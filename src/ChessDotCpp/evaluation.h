#pragma once

#define EVALPINS 0

#include "evaluationClassical2.h"
#include "evaluationNnue2.h"

//using Evaluation = EvaluationClassical2;
using Evaluation = EvaluationNnue2;

#if EVALPINS
#define CallEval(board, pins) Evaluation::Evaluate(board, pins)
#else
#define CallEval(board, pins) Evaluation::Evaluate(board)
#endif