#pragma once

#include "common.h"

#include <fstream>

class EvaluationNnueBase
{
public:
    static constexpr size_t InputCount = 12 * 64;
    static constexpr size_t HiddenCount = 128;

    using NnueValue = int16_t;
    using FinalValue = int32_t;

    using input_weights_t = std::array<std::array<NnueValue, HiddenCount>, InputCount>;
    using hidden_weights_t = std::array<NnueValue, HiddenCount>;
    using hidden_biases_t = std::array<NnueValue, HiddenCount>;
    using output_bias_t = FinalValue;

    using input_layer_t = std::array<NnueValue, InputCount>;
    using hidden_layer_t = std::array<FinalValue, HiddenCount>;

    inline static input_weights_t InputWeights;
    inline static hidden_biases_t HiddenBiases;
    inline static hidden_weights_t HiddenWeights;
    inline static output_bias_t OutputBias;

    static constexpr EachPiece<int32_t> pieceIndices = { -1, -1, -1, -1, 0, 6, 1, 7, 2, 8, 3, 9, 4, 10, 5, 11 };

    template<bool TSet>
    static void ApplyPiece(hidden_layer_t& hiddenLayer, const Position pos, const Piece piece)
    {
        const auto pieceIndex = pieceIndices[piece] * 64;
        assert(pieceIndex >= 0);

        const auto inputIndex = pieceIndex + pos;
        for (auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
        {
            const NnueValue weight = InputWeights[inputIndex][hiddenIndex];
            if constexpr (TSet)
            {
                hiddenLayer[hiddenIndex] += weight;
            }
            else
            {
                hiddenLayer[hiddenIndex] -= weight;
            }
        }
    }

    static void SetPiece(hidden_layer_t& hiddenLayer, const Position pos, const Piece piece)
    {
        ApplyPiece<true>(hiddenLayer, pos, piece);
    }

    static void UnsetPiece(hidden_layer_t& hiddenLayer, const Position pos, const Piece piece)
    {
        ApplyPiece<false>(hiddenLayer, pos, piece);
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
        //auto file = std::ifstream("C:/shared/cdcpp/nn/current.nnue", std::ios::binary | std::ios::ate);
        auto file = std::ifstream("C:/Chess/Networks/7/nn-epoch320.nnue", std::ios::binary | std::ios::ate);
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

        for (auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
        {
            assert(!file.eof());
            const NnueValue weight = Read<int16_t>(file);
            HiddenWeights[hiddenIndex] = weight;
        }

        assert(!file.eof());
        OutputBias = Read<int32_t>(file);
        //assert(file.eof());

        constexpr size_t valueCount = InputCount * HiddenCount + HiddenCount + HiddenCount;
        constexpr size_t expectedPos = sizeof(NnueValue) * valueCount + sizeof(FinalValue);
        auto pos = static_cast<size_t>(file.tellg());
        assert(pos == expectedPos);
        assert(pos == fileSize);

        auto a = 123;
    }
};
