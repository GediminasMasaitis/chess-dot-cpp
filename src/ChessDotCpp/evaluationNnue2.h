#pragma once

#include "common.h"
#include "board.h"
#include "evaluationNnueBase.h"

#include <immintrin.h>

class EvaluationNnue2 : public EvaluationNnueBase
{
public:
    alignas(SimdFV::alignment) static inline SimdNV::simd_t zero = { 0 };

    static constexpr FinalValue scale = 16 * 256;

    static Score Evaluate(const BoardBase& board)
    {
        assert(!board.accumulatorStack.empty());
        auto& accumulators = board.accumulatorStack[board.accumulatorStack.size() - 1].accumulators;
        alignas(SimdFV::alignment) auto outputSimd = SimdFV::simd_t { 0 };
        for(auto relativeSide = 0; relativeSide < 2; relativeSide++)
        {
            const Color accumulatorColor = relativeSide == 0 ? board.ColorToMove : board.ColorToMove ^ 1;
            auto& accumulator = accumulators[accumulatorColor];
            auto accumulatorPtr = SimdNV::reinterpret_const(accumulator.data());
            auto& hiddenWeights = HiddenWeightses[relativeSide];
            auto hiddenWeightsPtr = SimdNV::reinterpret_const(hiddenWeights.data());
            for (size_t hiddenIndex = 0; hiddenIndex < HiddenCount / SimdNV::stride; hiddenIndex++)
            {
                const auto hiddenValue = SimdNV::max(zero, accumulatorPtr[hiddenIndex]);
                const auto hiddenWeight = hiddenWeightsPtr[hiddenIndex];
                const auto outputAdditionSimd = SimdNV::madd16(hiddenValue, hiddenWeight);
                outputSimd = SimdFV::add(outputSimd, outputAdditionSimd);
            }
        }

        const FinalValue outputValue = SimdFV::sumRegisterEpi32(outputSimd) + OutputBias;
        const Score score = static_cast<Score>(outputValue / scale);
        return score;
    }
};