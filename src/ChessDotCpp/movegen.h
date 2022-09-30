#pragma once

#include "board.h"

class PinDetector
{
public:
	static Bitboard GetPinned(const BoardBase& board, Piece color, Position pos);
	static void GetPinnedToKings(const BoardBase& board, EachColor<Bitboard>& pins);
	static Bitboard GetPinnedToKingForColorToMove(const BoardBase& board);
};

using PinPaths = std::array<Bitboard, 64>;

class MoveGenerator
{
public:
	static void GetAllPotentialMoves(const Board& board, Bitboard checkers, Bitboard pinned, MoveArray& moves, MoveCount& moveCount);
	static void GetAllPotentialCaptures(const Board& board, Bitboard checkers, Bitboard pinned, MoveArray& moves, MoveCount& moveCount);
	static void GetAllPotentialNonCaptures(const Board& board, Bitboard checkers, Bitboard pinned, MoveArray& moves, MoveCount& moveCount);

	static void GetAllPossibleMoves(const Board& board, MoveArray& moves, MoveCount& moveCount);
};

class MoveValidator
{
public:
	static bool IsKingSafeAfterMove(const Board& board, const Move move);
	static bool IsKingSafeAfterMove2(const Board& board, const Move move, Bitboard pinnedPieces);
	static void FilterMovesByKingSafety(const Board& board, Bitboard pinnedPieces, MoveArray& moves, MoveCount& moveCount);

	static bool IsPseudoLegal(const Board& board, const Move move);
};
