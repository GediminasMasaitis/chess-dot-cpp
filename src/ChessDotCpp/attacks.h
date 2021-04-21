#pragma once

#include "board.h"

class AttacksGenerator
{
public:
	static Bitboard GetAttackedByPawns(const Bitboard myPawns, const bool whiteToMove);
	static Bitboard GetAllAttacked(const Board& board, bool whiteToMove, Bitboard allPieces, Bitboard canAttackFrom = ~0ULL);
};