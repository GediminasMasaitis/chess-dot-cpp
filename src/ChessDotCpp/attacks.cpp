#include "attacks.h"

#include "magics.h"

Bitboard AttacksGenerator::GetAttackedByPawns(const Bitboard myPawns, const bool whiteToMove)
{
	Bitboard pawnsLeft;
	Bitboard pawnsRight;
	if (whiteToMove)
	{
		pawnsLeft = (myPawns << 7) & ~BitboardConstants::Files[7];
		pawnsRight = (myPawns << 9) & ~BitboardConstants::Files[0];
	}
	else
	{
		pawnsLeft = (myPawns >> 7) & ~BitboardConstants::Files[0];
		pawnsRight = (myPawns >> 9) & ~BitboardConstants::Files[7];
	}
	return pawnsLeft | pawnsRight;
}

constexpr Bitboard GetAttackedBySlidingPieces(const Bitboard allPieces, Bitboard slidingPieces, const bool diagonal)
{
	Bitboard allSlide = 0;
	while (slidingPieces != 0)
	{
		const Position i = BitScanForward(slidingPieces);
		const Bitboard slide = diagonal ? SlideMoveGenerator::DiagonalAntidiagonalSlide(allPieces, i) : SlideMoveGenerator::HorizontalVerticalSlide(allPieces, i);
		allSlide |= slide;
		slidingPieces &= ~GetBitboard(i);
	}
	return allSlide;
}

constexpr Bitboard GetAttackedByJumpingPiece(Position position, const Bitboard jumpMask, const Position jumpMaskCenter)
{
	Bitboard jumps;
	if (position > jumpMaskCenter)
	{
		jumps = jumpMask << (position - jumpMaskCenter);
	}
	else
	{
		jumps = jumpMask >> (jumpMaskCenter - position);
	}

	jumps &= ~(position % 8 < 4 ? BitboardConstants::Files[6] | BitboardConstants::Files[7] : BitboardConstants::Files[0] | BitboardConstants::Files[1]);
	return jumps;
}

constexpr Bitboard GetAttackedByKings(Bitboard kings)
{
	Bitboard allJumps = 0;
	while (kings != 0)
	{
		const Position i = BitScanForward(kings);
		const Bitboard jumps = BitboardJumps.KingJumps[i];
		allJumps |= jumps;
		kings &= kings - 1;
	}
	return allJumps;
}

constexpr Bitboard GetAttackedByKnights(Bitboard knights)
{
	Bitboard allJumps = 0;
	while (knights != 0)
	{
		const Position i = BitScanForward(knights);
		const Bitboard jumps = BitboardJumps.KnightJumps[i];
		allJumps |= jumps;
		knights &= knights - 1;
	}
	return allJumps;
}

Bitboard AttacksGenerator::GetAllAttacked(const Board& board, const bool whiteToMove, const Bitboard allPieces, const Bitboard canAttackFrom)
{
	Bitboard pawns;
	Bitboard knights;
	Bitboard kings;
	Bitboard bq;
	Bitboard rq;
	if (whiteToMove)
	{
		pawns = board.BitBoard[Pieces::WhitePawn] & allPieces;
		bq = board.BitBoard[Pieces::WhiteBishop] | board.BitBoard[Pieces::WhiteQueen];
		rq = board.BitBoard[Pieces::WhiteRook] | board.BitBoard[Pieces::WhiteQueen];
		knights = board.BitBoard[Pieces::WhiteKnight];
		kings = board.BitBoard[Pieces::WhiteKing];
	}
	else
	{
		pawns = board.BitBoard[Pieces::BlackPawn] & allPieces;
		bq = board.BitBoard[Pieces::BlackBishop] | board.BitBoard[Pieces::BlackQueen];
		rq = board.BitBoard[Pieces::BlackRook] | board.BitBoard[Pieces::BlackQueen];
		knights = board.BitBoard[Pieces::BlackKnight];
		kings = board.BitBoard[Pieces::BlackKing];
	}

	pawns &= canAttackFrom;
	bq &= canAttackFrom;
	rq &= canAttackFrom;
	knights &= canAttackFrom;
	kings &= canAttackFrom;

	const Bitboard pawnsAttack = GetAttackedByPawns(pawns, whiteToMove);
	const Bitboard knightsAttack = GetAttackedByKnights(knights);

	const Bitboard bqAttack = GetAttackedBySlidingPieces(allPieces, bq, true);
	const Bitboard rqAttack = GetAttackedBySlidingPieces(allPieces, rq, false);

	const Bitboard kingsAttack = GetAttackedByKings(kings);

	const Bitboard allAttacked = pawnsAttack | knightsAttack | bqAttack | rqAttack | kingsAttack;
	return allAttacked;
}
