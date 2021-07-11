#pragma once

#include "board.h"
#include "evalstate.h"

class EvaluationNnue
{
public:
    static Score Evaluate(const BoardBase& board, const EachColor<Bitboard>& pins, EvalState& state);
    static void Init();
};