#pragma once

#include "common.h"
#include "simd.h"

#include <fstream>

class EvaluationNnueBase
{
public:
    using NnueCount = int16_t;

    static constexpr uint8_t BucketCount = 8;
    static constexpr NnueCount InputCount = BucketCount * 2 * 6 * 64;
    static constexpr NnueCount HiddenCount = 512;

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

    using bucket_t = uint8_t;
    static constexpr EachPosition<bucket_t> BucketMap = {
        0,  1,  2,  3,  3,  2,  1,  0,
        4,  4,  5,  5,  5,  5,  4,  4,
        6,  6,  6,  6,  6,  6,  6,  6,
        6,  6,  6,  6,  6,  6,  6,  6,
        7,  7,  7,  7,  7,  7,  7,  7,
        7,  7,  7,  7,  7,  7,  7,  7,
        7,  7,  7,  7,  7,  7,  7,  7,
        7,  7,  7,  7,  7,  7,  7,  7,
    };

    static constexpr bucket_t GetBucket(Position position, const Color color)
    {
        if (color == Colors::Black)
        {
            position ^= 56;
        }

        return BucketMap[position];
    }

    static constexpr EachPiece<int32_t> pieceIndices =
    {
        -1,
        -1,
        -1,
        -1,
        Positions::Count * 0,
        Positions::Count * 6,
        Positions::Count * 1,
        Positions::Count * 7,
        Positions::Count * 2,
        Positions::Count * 8,
        Positions::Count * 3,
        Positions::Count * 9,
        Positions::Count * 4,
        Positions::Count * 10,
        Positions::Count * 5,
        Positions::Count * 11
    };

    template<bool TSet>
    static void ApplyPieceSingle(hidden_layer_t& hiddenLayer, const Position pos, const Piece piece, const bool kingQueenSide, const bucket_t bucket)
    {
        const auto pieceIndex = pieceIndices[piece];
        assert(pieceIndex >= 0);

        const auto posIndex = kingQueenSide ? pos ^ 7 : pos;
        //const auto posIndex = pos;
        const auto bucketIndex = bucket * 2 * 6 * 64;
        const auto inputIndex = bucketIndex + pieceIndex + posIndex;
        const auto hiddenLayerPtr = SimdNV::reinterpret(hiddenLayer.data());
        const auto inputWeightsPtr = SimdNV::reinterpret(InputWeights[inputIndex].data());
        for (NnueCount hiddenIndex = 0; hiddenIndex < static_cast<NnueCount>(HiddenCount / SimdNV::stride); hiddenIndex++)
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
    static void ApplyPiece(hidden_layers_t& hiddenLayers, const Position pos, const Piece piece, const EachColor<bool>& kingsQueenSide, const EachColor<bucket_t>& buckets)
    {
        const Position flippedPos = pos ^ 56;
        const Piece flippedPiece = piece ^ 1;
        ApplyPieceSingle<TSet>(hiddenLayers[Colors::White], pos, piece, kingsQueenSide[Colors::White], buckets[Colors::White]);
        ApplyPieceSingle<TSet>(hiddenLayers[Colors::Black], flippedPos, flippedPiece, kingsQueenSide[Colors::Black], buckets[Colors::Black]);
    }

    static void SetPiece(hidden_layers_t& hiddenLayers, const Position pos, const Piece piece, const EachColor<bool>& kingsQueenSide, const EachColor<bucket_t>& buckets)
    {
        ApplyPiece<true>(hiddenLayers, pos, piece, kingsQueenSide, buckets);
    }

    static void UnsetPiece(hidden_layers_t& hiddenLayers, const Position pos, const Piece piece, const EachColor<bool>& kingsQueenSide, const EachColor<bucket_t>& buckets)
    {
        ApplyPiece<false>(hiddenLayers, pos, piece, kingsQueenSide, buckets);
    }

    static void ResetSingle(hidden_layer_t& hiddenLayer)
    {
        std::copy(std::begin(HiddenBiases), std::end(HiddenBiases), std::begin(hiddenLayer));
    }

    static void Reset(hidden_layers_t& hiddenLayers)
    {
        for (Color color = 0; color < Colors::Count; color++)
        {
            auto& hiddenLayer = hiddenLayers[color];
            ResetSingle(hiddenLayer);
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
        auto file = std::ifstream("C:/Chess/Networks/42/nn-epoch500.nnue", std::ios::binary);

        for (size_t inputIndex = 0; inputIndex < InputCount; inputIndex++)
        {
            for (auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
            {
                assert(!file.eof());
                const NnueValue weight = Read<int16_t>(file);
                InputWeights[inputIndex][hiddenIndex] = weight;
            }
        }

        for (size_t hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
        {
            assert(!file.eof());
            const NnueValue bias = Read<int16_t>(file);
            HiddenBiases[hiddenIndex] = bias;
        }

        for (auto hiddenNum = 0; hiddenNum < 2; hiddenNum++)
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

        assert(static_cast<size_t>(file.tellg()) == sizeof(NnueValue) * (InputCount * HiddenCount + HiddenCount + HiddenCount * 2) + sizeof(FinalValue));
    }
};
