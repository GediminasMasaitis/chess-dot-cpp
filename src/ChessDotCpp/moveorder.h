#pragma once
#include "board.h"
#include "searchstate.h"

class MoveOrdering
{
public:
	static void CalculateStaticScores(const SearchState& state, const MoveArray& moves, const MoveCount moveCount, const Ply ply, const Move pvMove, MoveScoreArray& staticScores);
	static void OrderNextMove(const SearchState& state, const MoveCount currentIndex, MoveArray& moves, MoveScoreArray& staticScores, const MoveCount moveCount);
};
