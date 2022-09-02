#pragma once
#include "board.h"
#include "searchstate.h"

class MoveOrdering
{
public:
	static void CalculateStaticCaptureScores
    (
        const ThreadState& threadState,
        const MoveArray& moves,
        const ScoreArray& seeScores,
        const MoveCount moveCount,
        MoveScoreArray& staticScores
    );

	static void OrderNextCaptureMove
    (
        const MoveCount currentIndex,
        MoveArray& moves,
        ScoreArray& seeScores,
        MoveScoreArray& staticScores,
        const MoveCount moveCount
    );

	static void CalculateStaticNonCaptureScores
    (
        const ThreadState& threadState,
        const MoveArray& moves,
        const MoveCount moveCount,
        const Move countermove,
        MoveScoreArray& staticScores,
        const Board& board
    );

	static void OrderNextNonCaptureMove
    (
        const MoveCount currentIndex,
        MoveArray& moves,
        MoveScoreArray& staticScores,
        const MoveCount moveCount
    );
};
