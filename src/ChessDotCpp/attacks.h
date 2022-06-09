#pragma once

#include "board.h"

class AttacksGenerator
{
public:
	static Bitboard GetAttackedByPawns(Bitboard myPawns, bool whiteToMove);
	static Bitboard GetAllAttacked(const BoardBase& board, bool whiteToMove, Bitboard allPieces, Bitboard canAttackFrom = ~0ULL);
	static Bitboard GetAttackersOf(const Board& board, Position position, Bitboard allPieces);
	static Bitboard GetAttackersOfSide(const BoardBase& board, Position position, bool byWhite, Bitboard allPieces);
	static bool IsPositionAttacked(const Board& board, const Position position, const bool byWhite);
};

class CheckDetector
{
public:
	static Bitboard GetCheckers(const BoardBase& board);
	static void GetCheckers(const BoardBase& board, EachColor<Bitboard>& checkers);
	static bool DoesGiveCheck(const BoardBase& board, const Move move);
};