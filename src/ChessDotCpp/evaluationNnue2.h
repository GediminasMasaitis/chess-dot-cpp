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
    static Score Evaluate(const BoardBase& board)
    {
        FinalValue outputValue = 0;

        for(auto relativeSide = 0; relativeSide < 2; relativeSide++)
        {
            //auto& accumulator = relativeAccumulators[relativeSide];
            const auto& accumulator = relativeSide == 0 ? board.accumulators[board.ColorToMove] : board.accumulators[board.ColorToMove ^ 1];

            for (auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
            {
                const NnueValue bias = HiddenBiases[hiddenIndex];
                auto hiddenValue = accumulator[hiddenIndex] + bias;
                hiddenValue = std::max(0, hiddenValue);

                const NnueValue hiddenWeight = HiddenWeightses[relativeSide][hiddenIndex];
                const FinalValue outputAddition = hiddenValue * hiddenWeight;
                outputValue += outputAddition;
            }
        }

        outputValue += OutputBias;

        constexpr auto scale = 64 * 256;
        const Score score = static_cast<Score>(outputValue / scale);

        return score;
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