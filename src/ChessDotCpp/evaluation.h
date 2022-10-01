#pragma once

#if NNUE
#include "evaluationNnue2.h"
#define EVALPINS 0
using Evaluation = EvaluationNnue2;
#else
#include "evaluationClassical2.h"
#define EVALPINS 1
using Evaluation = EvaluationClassical2;
#endif

#if EVALPINS
#define CallEval(board, pins) Evaluation::Evaluate(board, pins)
#else
#define CallEval(board, pins) Evaluation::Evaluate(board)
#endif