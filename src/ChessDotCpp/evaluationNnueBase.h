#pragma once

#include "common.h"
#include "simd.h"

#include <fstream>

class EvaluationNnueBase
{
public:
    static constexpr size_t InputCount = 12 * 64;
    static constexpr size_t HiddenCount = 512;

    using NnueValue = int16_t;
    using FinalValue = int32_t;

    using input_weights_t = std::array<std::array<NnueValue, HiddenCount>, InputCount>;
    using hidden_biases_t = std::array<NnueValue, HiddenCount>;
    using hidden_weights_t = std::array<NnueValue, HiddenCount>;
    using hidden_weightses_t = EachColor<hidden_weights_t>;
    using output_bias_t = FinalValue;

    using input_layer_t = std::array<NnueValue, InputCount>;
    using hidden_layer_t = std::array<NnueValue, HiddenCount>;
    using hidden_layers_t = EachColor<hidden_layer_t>;

    using SimdNV = Simd<NnueValue>;
    using SimdFV = Simd<FinalValue>;

    alignas(SimdNV::alignment) inline static input_weights_t InputWeights;
    alignas(SimdNV::alignment) inline static hidden_biases_t HiddenBiases;
    alignas(SimdNV::alignment) inline static hidden_weightses_t HiddenWeightses;
    alignas(SimdNV::alignment) inline static output_bias_t OutputBias;

    static constexpr EachPiece<int32_t> pieceIndices = { -1, -1, -1, -1, 0, 6, 1, 7, 2, 8, 3, 9, 4, 10, 5, 11 };

    template<bool TSet>
    static void ApplyPieceSingle(hidden_layer_t& hiddenLayer, const Position pos, const Piece piece)
    {
        const auto pieceIndex = pieceIndices[piece] * Positions::Count;
        assert(pieceIndex >= 0);

        const auto inputIndex = pieceIndex + pos;
        const auto hiddenLayerPtr = SimdNV::reinterpret(hiddenLayer.data());
        const auto inputWeightsPtr = SimdNV::reinterpret(InputWeights[inputIndex].data());
        for (auto hiddenIndex = 0; hiddenIndex < (HiddenCount / SimdNV::stride); hiddenIndex++)
        {
            if constexpr (TSet)
            {
                hiddenLayerPtr[hiddenIndex] = SimdNV::add(hiddenLayerPtr[hiddenIndex], inputWeightsPtr[hiddenIndex]);
            }
            else
            {
                hiddenLayerPtr[hiddenIndex] = SimdNV::subtract(hiddenLayerPtr[hiddenIndex], inputWeightsPtr[hiddenIndex]);
            }
        }
    }

    template<bool TSet>
    static void ApplyPiece(hidden_layers_t& hiddenLayers, const Position pos, const Piece piece)
    {
        const Position flippedPos = pos ^ 56;
        const Piece flippedPiece = piece ^ 1;
        ApplyPieceSingle<TSet>(hiddenLayers[Colors::White], pos, piece);
        ApplyPieceSingle<TSet>(hiddenLayers[Colors::Black], flippedPos, flippedPiece);
    }

    static void SetPiece(hidden_layers_t& hiddenLayers, const Position pos, const Piece piece)
    {
        ApplyPiece<true>(hiddenLayers, pos, piece);
    }

    static void UnsetPiece(hidden_layers_t& hiddenLayers, const Position pos, const Piece piece)
    {
        ApplyPiece<false>(hiddenLayers, pos, piece);
    }

    static void Reset(hidden_layers_t& hiddenLayers)
    {
        for(Color color = 0; color < Colors::Count; color++)
        {
            std::copy(std::begin(HiddenBiases), std::end(HiddenBiases), std::begin(hiddenLayers[color]));
        }
    }

    template<class T>
    static T Read(std::istream& stream)
    {
        constexpr size_t size = sizeof(T);
        char buffer[size];
        stream.read(buffer, size);
        const T* resultPtr = reinterpret_cast<T*>(buffer);
        const auto result = *resultPtr;
        return result;
    }
    
    static void Init()
    {
        auto file = std::ifstream("C:/Chess/Networks/29/nn-epoch500.nnue", std::ios::binary | std::ios::ate);
        auto fileSize = static_cast<size_t>(file.tellg());
        file.seekg(0);

        for (auto inputIndex = 0; inputIndex < InputCount; inputIndex++)
        {
            for (auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
            {
                assert(!file.eof());
                const NnueValue weight = Read<int16_t>(file);
                InputWeights[inputIndex][hiddenIndex] = weight;
            }
        }

        for (auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
        {
            assert(!file.eof());
            const NnueValue bias = Read<int16_t>(file);
            HiddenBiases[hiddenIndex] = bias;
        }

        for(auto hiddenNum = 0; hiddenNum < 2; hiddenNum++)
        {
            for (auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
            {
                assert(!file.eof());
                const NnueValue weight = Read<int16_t>(file);
                HiddenWeightses[hiddenNum][hiddenIndex] = weight;
            }
        }

        assert(!file.eof());
        OutputBias = Read<int32_t>(file);

        constexpr size_t valueCount = InputCount * HiddenCount + HiddenCount + HiddenCount*2;
        constexpr size_t expectedPos = sizeof(NnueValue) * valueCount + sizeof(FinalValue);
        auto pos = static_cast<size_t>(file.tellg());
        assert(pos == expectedPos);
        assert(pos == fileSize);
    }
};
