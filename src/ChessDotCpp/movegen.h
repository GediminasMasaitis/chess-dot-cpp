#pragma once

#include "board.h"

class PinDetector
{
public:
	static Bitboard GetPinned(const BoardBase& board, Piece color, Position pos);
	static void GetPinnedToKings(const BoardBase& board, EachColor<Bitboard>& pins);
};

using PinPaths = std::array<Bitboard, 64>;

class MoveGenerator
{
public:
	static void GetAllPotentialMoves(const Board& board, Bitboard checkers, Bitboard pinned, MoveArray& moves, MoveCount& moveCount);
	static void GetAllPotentialCaptures(const Board& board, Bitboard checkers, Bitboard pinned, MoveArray& moves, MoveCount& moveCount);

	static void GetAllPossibleMoves(const Board& board, MoveArray& moves, MoveCount& moveCount);
};

class MoveValidator
{
public:
	static bool IsKingSafeAfterMove(const Board& board, const Move move);
	static bool IsKingSafeAfterMove2(const Board& board, const Move move, Bitboard checkers, Bitboard pinnedPieces);
	static void FilterMovesByKingSafety(const Board& board, Bitboard checkers, Bitboard pinnedPieces, MoveArray& moves, MoveCount& moveCount);
};
