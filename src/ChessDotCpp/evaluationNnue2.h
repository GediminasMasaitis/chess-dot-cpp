#pragma once

#include "common.h"
#include "board.h"
#include "evaluationNnueBase.h"

class EvaluationNnue2 : public EvaluationNnueBase
{
public:
    static constexpr FinalValue scale = 112;

    static Score Evaluate(const BoardBase& board)
    {
        assert(!board.accumulatorStack.empty());
        auto& accumulators = board.accumulatorStack[board.accumulatorStack.size() - 1].accumulators;
        FinalValue outputValue = 0;
        for(auto relativeSide = 0; relativeSide < 2; relativeSide++)
        {
            const Color accumulatorColor = relativeSide == 0 ? board.ColorToMove : board.ColorToMove ^ 1;
            const auto& accumulator = accumulators[accumulatorColor];
            for (auto hiddenIndex = 0; hiddenIndex < HiddenCount; hiddenIndex++)
            {
                NnueValue hiddenValue = accumulator[hiddenIndex];
                hiddenValue = std::min(static_cast<NnueValue>(128), hiddenValue);
                hiddenValue = std::max(static_cast<NnueValue>(0), hiddenValue);

                const NnueValue hiddenWeight = HiddenWeightses[relativeSide][hiddenIndex];
                const FinalValue outputAddition = (hiddenValue * hiddenValue) * hiddenWeight;
                outputValue += outputAddition;
            }
        }

        outputValue /= 48;
        outputValue += OutputBias;

        const Score score = static_cast<Score>(outputValue / scale);
        return score;
    }
};