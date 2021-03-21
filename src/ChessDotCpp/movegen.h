#pragma once

#include "board.h"

class AttacksGenerator
{
public:
	static Bitboard GetAllAttacked(Board board, bool whiteToMove, Bitboard allPieces, Bitboard canAttackFrom = ~0ULL);
};

class MoveGenerator
{
public:
	static void GetAllPotentialMoves(const Board& board, MoveArray& moves, size_t& moveCount);
	static void GetAllPotentialCaptures(const Board& board, MoveArray& moves, size_t& moveCount);

	static bool IsKingSafeAfterMove(const Board board, const Move move);
	static void FilterMovesByKingSafety(const Board& board, MoveArray& moves, size_t& moveCount);
	static void GetAllPossibleMoves(const Board& board, MoveArray& moves, size_t& moveCount);
};
