#pragma once

#include "board.h"

class AttacksGenerator
{
public:
	static Bitboard GetAllAttacked(const Board& board, bool whiteToMove, Bitboard allPieces, Bitboard canAttackFrom = ~0ULL);
};

class PinDetector
{
public:
	static Bitboard GetPinned(const Board& board, Piece color, Position pos);
};

using PinPaths = std::array<Bitboard, 64>;

class MoveGenerator
{
public:
	static void GetAllPotentialMoves(const Board& board, Bitboard checkers, Bitboard pinned, MoveArray& moves, size_t& moveCount);
	static void GetAllPotentialCaptures(const Board& board, Bitboard checkers, Bitboard pinned, MoveArray& moves, size_t& moveCount);

	static void GetAllPossibleMoves(const Board& board, MoveArray& moves, size_t& moveCount);
};

class MoveValidator
{
public:
	static bool IsKingSafeAfterMove(const Board& board, const Move move);
	static bool IsKingSafeAfterMove2(const Board& board, const Move move, Bitboard checkers, Bitboard pinnedPieces);
	static void FilterMovesByKingSafety(const Board& board, Bitboard checkers, Bitboard pinnedPieces, MoveArray& moves, size_t& moveCount);
};
