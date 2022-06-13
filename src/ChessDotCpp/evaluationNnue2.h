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
        FinalValue outputValue = OutputBias;

        for(auto relativeSide = 0; relativeSide < 2; relativeSide++)
        {
            const Color accumulatorColor = relativeSide == 0 ? board.ColorToMove : board.ColorToMove ^ 1;
            const auto& accumulator = board.accumulators[accumulatorColor];

            for (auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
            {
                NnueValue hiddenValue = accumulator[hiddenIndex];
                hiddenValue = std::max(static_cast<NnueValue>(0), hiddenValue);

                const NnueValue hiddenWeight = HiddenWeightses[relativeSide][hiddenIndex];
                const FinalValue outputAddition = hiddenValue * hiddenWeight;
                outputValue += outputAddition;
            }
        }

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