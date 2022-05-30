#pragma once

#include "board.h"

class AttacksGenerator
{
public:
	static Bitboard GetAttackedByPawns(Bitboard myPawns, bool whiteToMove);
	static Bitboard GetAllAttacked(const Board& board, bool whiteToMove, Bitboard allPieces, Bitboard canAttackFrom = ~0ULL);
	static Bitboard GetAttackersOf(const Board& board, Position position, Bitboard allPieces);
	static Bitboard GetAttackersOfSide(const Board& board, Position position, bool byWhite, Bitboard allPieces);
	static bool IsPositionAttacked(const Board& board, const Position position, const bool byWhite);
};

class CheckDetector
{
public:
	static Bitboard GetCheckers(const Board& board);
	static bool DoesGiveCheck(const Board& board, const Move move);
};