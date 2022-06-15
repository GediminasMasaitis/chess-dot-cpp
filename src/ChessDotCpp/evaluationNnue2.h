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
            for (auto hiddenIndex = 0; hiddenIndex < (HiddenCount / SimdNV::stride); hiddenIndex++)
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

    static Score Evaluate(const BoardBase& board, const EachColor<Bitboard>& pins)
    {
        return Evaluate(board);
    }

    static Score Evaluate(const BoardBase& board, const EachColor<Bitboard>& pins, EvalState& state)
    {
        return Evaluate(board);
    }
};