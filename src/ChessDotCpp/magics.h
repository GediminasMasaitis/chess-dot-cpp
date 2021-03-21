#pragma once

#include "common.h"
#include "constants.h"


class HyperbolaQuintessence
{
public:
	static Bitboard HorizontalVerticalSlide(const Bitboard allPieces, const Position position);
	static Bitboard DiagonalAntidiagonalSlide(const Bitboard allPieces, const Position position);
	static Bitboard AllSlide(const Bitboard allPieces, const Position position);
};

using SlideMoveGenerator = HyperbolaQuintessence;