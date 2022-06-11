#pragma once

#include "common.h"
#include "evalbase.h"
#include "board.h"
#include "evalstate.h"
#include "evaluationNnueBase.h"

#include <immintrin.h>

class EvaluationNnue2 : EvaluationNnueBase
{
public:
    //static void SetInputs(const BoardBase& board, input_layer_t& input)
    //{
    //    for(Position pos = 0; pos < Positions::Count; pos++)
    //    {
    //        const Piece piece = board.ArrayBoard[pos];
    //        if(piece == Pieces::Empty)
    //        {
    //            continue;
    //        }

    //        const auto pieceIndex = pieceIndices[piece] * 64;
    //        assert(pieceIndex >= 0);

    //        const auto index = pieceIndex + pos;
    //        input[index] = 1;
    //    }
    //}

    static Score Evaluate(const BoardBase& board)
    {
        //input_layer_t inputLayer = input_layer_t{ 0 };
        //SetInputs(board, inputLayer);

        //hidden_layer_t hiddenLayer = { 0 };

        //for (auto inputIndex = 0; inputIndex < InputCount; inputIndex++)
        //{
        //    const NnueValue input = inputLayer[inputIndex];
        //    if(input == 0)
        //    {
        //        continue;
        //    }

        //    for (auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
        //    {
        //        const NnueValue weight = InputWeights[inputIndex][hiddenIndex];
        //        hiddenLayer[hiddenIndex] += weight;
        //    }
        //}

        const auto& hiddenLayer = board.accumulator;

        FinalValue outputValue = 0;
        for (auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
        {
            const NnueValue bias = HiddenBiases[hiddenIndex];
            auto hiddenValue = hiddenLayer[hiddenIndex] + bias;
            hiddenValue = std::max(0, hiddenValue);

            const NnueValue hiddenWeight = HiddenWeights[hiddenIndex];
            const FinalValue outputAddition = hiddenValue * hiddenWeight;
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