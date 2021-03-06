#pragma once
#include "board.h"
#include "searchstate.h"

class MoveOrdering
{
public:
	static void CalculateStaticScores(const ThreadId threadId, const SearchState& state, const MoveArray& moves, const ScoreArray& seeScores, const MoveCount moveCount, const Ply ply, const Move pvMove, const Move countermove, MoveScoreArray& staticScores, const Board& board);
	static void OrderNextMove(const MoveCount currentIndex, MoveArray& moves, ScoreArray& seeScores, MoveScoreArray& staticScores, const MoveCount moveCount);
};
