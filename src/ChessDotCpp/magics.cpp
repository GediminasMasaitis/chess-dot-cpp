#include "magics.h"

constexpr Bitboard MaskedSlide(const Bitboard allPieces, const Bitboard pieceBitboard, const Bitboard mask)
{
	const auto left = ((allPieces & mask) - 2 * pieceBitboard);
	const auto right = ReverseBits(ReverseBits(allPieces & mask) - 2 * ReverseBits(pieceBitboard));
	const auto both = left ^ right;
	const auto slide = both & mask;
	return slide;
}

Bitboard HyperbolaQuintessence::HorizontalVerticalSlide(const Bitboard allPieces, const Position position)
{
	const auto pieceBitboard = GetBitboard(position);
	const auto horizontal = MaskedSlide(allPieces, pieceBitboard, BitboardConstants::Ranks[position / 8]);
	const auto vertical = MaskedSlide(allPieces, pieceBitboard, BitboardConstants::Files[position % 8]);
	return horizontal | vertical;
}

Bitboard HyperbolaQuintessence::DiagonalAntidiagonalSlide(const Bitboard allPieces, const Position position)
{
	const auto pieceBitboard = GetBitboard(position);
	const auto horizontal = MaskedSlide(allPieces, pieceBitboard, BitboardConstants::Diagonals[position / 8 + position % 8]);
	const auto vertical = MaskedSlide(allPieces, pieceBitboard, BitboardConstants::Antidiagonals[position / 8 + 7 - position % 8]);
	return horizontal | vertical;
}

Bitboard HyperbolaQuintessence::AllSlide(const Bitboard allPieces, const Position position)
{
	const auto hv = HorizontalVerticalSlide(allPieces, position);
	const auto dad = DiagonalAntidiagonalSlide(allPieces, position);
	return hv | dad;
}