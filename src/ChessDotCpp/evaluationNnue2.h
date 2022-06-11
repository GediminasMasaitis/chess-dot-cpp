#pragma once

#include "common.h"
#include "evalbase.h"
#include "board.h"
#include "evalstate.h"
//#include "attacks.h"
//#include "magics.h"

#include <immintrin.h>
#include <fstream>

class EvaluationNnue2
{
public:
    static constexpr size_t InputCount = 12 * 64;
    static constexpr size_t HiddenCount = 64;

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
        auto file = std::ifstream("C:/Chess/Networks/5/nn-epoch320.nnue", std::ios::binary | std::ios::ate);
        auto fileSize = static_cast<size_t>(file.tellg());
        file.seekg(0);

        for(auto inputIndex = 0; inputIndex < InputCount; inputIndex++)
        {
            for(auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
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

    static void SetInputs(const BoardBase& board, input_layer_t& input)
    {
        constexpr EachPiece<int32_t> pieceIndices = {-1, -1, -1, -1, 0, 6, 1, 7, 2, 8, 3, 9, 4, 10, 5, 11};
        
        for(Position pos = 0; pos < Positions::Count; pos++)
        {
            const Piece piece = board.ArrayBoard[pos];
            if(piece == Pieces::Empty)
            {
                continue;
            }

            const auto pieceIndex = pieceIndices[piece] * 64;
            assert(pieceIndex >= 0);

            const auto index = pieceIndex + pos;
            input[index] = 1;
        }
    }

    static Score Evaluate(const BoardBase& board)
    {
        input_layer_t inputLayer = input_layer_t{ 0 };
        SetInputs(board, inputLayer);

        hidden_layer_t hiddenLayer = { 0 };

        for (auto inputIndex = 0; inputIndex < InputCount; inputIndex++)
        {
            const NnueValue input = inputLayer[inputIndex];
            if(input == 0)
            {
                continue;
            }

            for (auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
            {
                const NnueValue weight = InputWeights[inputIndex][hiddenIndex];
                hiddenLayer[hiddenIndex] += weight;
            }
        }

        FinalValue outputValue = 0;
        for (auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
        {
            const NnueValue bias = HiddenBiases[hiddenIndex];
            hiddenLayer[hiddenIndex] += bias;
            hiddenLayer[hiddenIndex] = std::max(0, hiddenLayer[hiddenIndex]);

            const NnueValue hiddenWeight = HiddenWeights[hiddenIndex];
            const FinalValue outputAddition = hiddenLayer[hiddenIndex] * hiddenWeight;
            outputValue += outputAddition;
        }
        outputValue += OutputBias;

        constexpr auto scale = 128 * 256;
        const Score score = static_cast<Score>(outputValue / scale);
        const Score flipped = board.WhiteToMove ? score : static_cast<Score>(-score);

        return flipped;
    }

    static Score Evaluate(const BoardBase& board, const EachColor<Bitboard>& pins)
    {
        return Evaluate(board);
    }

    static Score Evaluate(const BoardBase& board, const EachColor<Bitboard>& pins, EvalState& state)
    {
        return Evaluate(board);
    }
};