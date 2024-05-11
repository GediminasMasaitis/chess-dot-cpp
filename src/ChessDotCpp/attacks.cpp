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

Bitboard AttacksGenerator::GetAllAttacked(const BoardBase& board, const bool whiteToMove, const Bitboard allPieces, const Bitboard canAttackFrom)
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

Bitboard AttacksGenerator::GetAttackersOf(const Board& board, Position position, Bitboard allPieces)
{
	Bitboard result = 0UL;

	const Bitboard whitePawns = board.BitBoard[Pieces::WhitePawn];
	const Bitboard blackPawns = board.BitBoard[Pieces::BlackPawn];
	const Bitboard knights = board.BitBoard[Pieces::WhiteKnight] | board.BitBoard[Pieces::BlackKnight];
	const Bitboard bishops = board.BitBoard[Pieces::WhiteBishop] | board.BitBoard[Pieces::BlackBishop];
	const Bitboard rooks = board.BitBoard[Pieces::WhiteRook] | board.BitBoard[Pieces::BlackRook];
	const Bitboard queens = board.BitBoard[Pieces::WhiteQueen] | board.BitBoard[Pieces::BlackQueen];
	const Bitboard kings = board.BitBoard[Pieces::WhiteKing] | board.BitBoard[Pieces::BlackKing];

	const Bitboard knightAttack = BitboardJumps.KnightJumps[position];
	result |= knightAttack & knights;

	const Bitboard kingAttack = BitboardJumps.KingJumps[position];
	result |= kingAttack & kings;

	const Bitboard whitePawnAttack = BitboardJumps.PawnJumps[Colors::Black][position];
	result |= whitePawnAttack & whitePawns;

	const Bitboard blackPawnAttack = BitboardJumps.PawnJumps[Colors::White][position];
	result |= blackPawnAttack & blackPawns;

	const Bitboard diagonalAttack = SlideMoveGenerator::DiagonalAntidiagonalSlide(allPieces, position);
	result |= diagonalAttack & bishops;
	result |= diagonalAttack & queens;

	const Bitboard verticalAttack = SlideMoveGenerator::HorizontalVerticalSlide(allPieces, position);
	result |= verticalAttack & rooks;
	result |= verticalAttack & queens;

	return result;
}

Bitboard AttacksGenerator::GetAttackersOfSide(const BoardBase& board, Position position, bool byWhite, Bitboard allPieces)
{
	Bitboard result = 0UL;

	Bitboard pawns;
	Bitboard knights;
	Bitboard bishops;
	Bitboard rooks;
	Bitboard queens;
	Bitboard kings;
	if (byWhite)
	{
		pawns = board.BitBoard[Pieces::WhitePawn];
		knights = board.BitBoard[Pieces::WhiteKnight];
		bishops = board.BitBoard[Pieces::WhiteBishop];
		rooks = board.BitBoard[Pieces::WhiteRook];
		queens = board.BitBoard[Pieces::WhiteQueen];
		kings = board.BitBoard[Pieces::WhiteKing];
	}
	else
	{
		pawns = board.BitBoard[Pieces::BlackPawn];
		knights = board.BitBoard[Pieces::BlackKnight];
		bishops = board.BitBoard[Pieces::BlackBishop];
		rooks = board.BitBoard[Pieces::BlackRook];
		queens = board.BitBoard[Pieces::BlackQueen];
		kings = board.BitBoard[Pieces::BlackKing];
	}

	const Bitboard knightAttack = BitboardJumps.KnightJumps[position];
	result |= knightAttack & knights;

	const Bitboard kingAttack = BitboardJumps.KingJumps[position];
	result |= kingAttack & kings;

	const Piece pawnIndex = byWhite ? Colors::Black : Colors::White;
	const Bitboard pawnAttack = BitboardJumps.PawnJumps[pawnIndex][position];
	result |= pawnAttack & pawns;

	const Bitboard diagonalAttack = SlideMoveGenerator::DiagonalAntidiagonalSlide(allPieces, position);
	result |= diagonalAttack & bishops;
	result |= diagonalAttack & queens;

	const Bitboard verticalAttack = SlideMoveGenerator::HorizontalVerticalSlide(allPieces, position);
	result |= verticalAttack & rooks;
	result |= verticalAttack & queens;

	return result;
}

bool AttacksGenerator::IsPositionAttacked(const Board& board, const Position position, const bool byWhite)
{
	Bitboard allPieces = board.AllPieces;

	Bitboard pawns;
	Bitboard knights;
	Bitboard bishops;
	Bitboard rooks;
	Bitboard queens;
	Bitboard kings;
	if (byWhite)
	{
		pawns = board.BitBoard[Pieces::WhitePawn];
		knights = board.BitBoard[Pieces::WhiteKnight];
		bishops = board.BitBoard[Pieces::WhiteBishop];
		rooks = board.BitBoard[Pieces::WhiteRook];
		queens = board.BitBoard[Pieces::WhiteQueen];
		kings = board.BitBoard[Pieces::WhiteKing];
	}
	else
	{
		pawns = board.BitBoard[Pieces::BlackPawn];
		knights = board.BitBoard[Pieces::BlackKnight];
		bishops = board.BitBoard[Pieces::BlackBishop];
		rooks = board.BitBoard[Pieces::BlackRook];
		queens = board.BitBoard[Pieces::BlackQueen];
		kings = board.BitBoard[Pieces::BlackKing];
	}

	const Bitboard knightAttack = BitboardJumps.KnightJumps[position];
	if ((knightAttack & knights) != 0)
	{
		return true;
	}

	const Bitboard kingAttack = BitboardJumps.KingJumps[position];
	if ((kingAttack & kings) != 0)
	{
		return true;
	}

	const Piece pawnIndex = byWhite ? Colors::Black : Colors::White;
	const Bitboard pawnAttack = BitboardJumps.PawnJumps[pawnIndex][position];
	if ((pawnAttack & pawns) != 0)
	{
		return true;
	}

	const Bitboard diagonalAttack = SlideMoveGenerator::DiagonalAntidiagonalSlide(allPieces, position);
	if ((diagonalAttack & bishops) != 0)
	{
		return true;
	}
	if ((diagonalAttack & queens) != 0)
	{
		return true;
	}

	const Bitboard verticalAttack = SlideMoveGenerator::HorizontalVerticalSlide(allPieces, position);
	if ((verticalAttack & rooks) != 0)
	{
		return true;
	}
	if ((verticalAttack & queens) != 0)
	{
		return true;
	}

	return false;
}

Bitboard CheckDetector::GetCheckers(const BoardBase& board)
{
	const Bitboard checkers = AttacksGenerator::GetAttackersOfSide(board, board.KingPositions[board.ColorToMove], !board.WhiteToMove, board.AllPieces);
	return checkers;
}

void CheckDetector::GetCheckers(const BoardBase& board, EachColor<Bitboard>& checkers)
{
	checkers[board.ColorToMove] = AttacksGenerator::GetAttackersOfSide(board, board.KingPositions[board.ColorToMove], !board.WhiteToMove, board.AllPieces);
	checkers[board.ColorToMove ^ 1] = AttacksGenerator::GetAttackersOfSide(board, board.KingPositions[board.ColorToMove ^ 1], board.WhiteToMove, board.AllPieces);
}

bool CheckDetector::DoesGiveCheck(const BoardBase& board, const Move move)
{
	const Color color = board.ColorToMove;
	const Color opponentColor = color ^ 1;
	const Position from = move.GetFrom();
	const Position to = move.GetTo();
	const Piece piece = move.GetPiece();
	const Piece takes = move.GetTakesPiece();
	const Piece promotion = move.GetPawnPromoteTo();

	Bitboard allPieces = board.AllPieces;
	const Bitboard fromBitboard = GetBitboard(from);
	const Bitboard toBitboard = GetBitboard(to);

	allPieces &= ~fromBitboard;
	allPieces |= toBitboard;


	EachPiece<Bitboard> bitboards = board.BitBoard;
	bitboards[piece] &= ~fromBitboard;

	if (move.GetPawnPromoteTo() == Pieces::Empty)
	{
		bitboards[piece] |= toBitboard;
	}
	else
	{
		bitboards[promotion] |= toBitboard;
	}

	Bitboard takesBitboard = toBitboard;
	if (move.get_en_passant())
	{
		const Bitboard enPassantedBitboard = color == Colors::White ? toBitboard >> 8 : toBitboard << 8;
		allPieces &= ~enPassantedBitboard;
		takesBitboard |= enPassantedBitboard;
	}
	bitboards[takes] &= ~takesBitboard;

	if (move.GetCastle())
	{
		const bool kingSide = to % 8 > 3;
		const Position castlingRookPos = (kingSide ? 7 : 0) + (color == Colors::White ? 0 : 56);
		const Position castlingRookNewPos = (from + to) / 2;
		const Piece rookPiece = Pieces::Rook | color;
		bitboards[rookPiece] &= ~GetBitboard(castlingRookPos);
		bitboards[rookPiece] |= GetBitboard(castlingRookNewPos);
	}

	const Position kingPos = board.KingPositions[opponentColor];

	const Bitboard knightAttack = BitboardJumps.KnightJumps[kingPos];
	if ((knightAttack & bitboards[Pieces::Knight | color]) != 0)
	{
		return true;
	}

	const Bitboard kingAttack = BitboardJumps.KingJumps[kingPos];
	if ((kingAttack & bitboards[Pieces::King | color]) != 0)
	{
		return true;
	}

	const Bitboard pawnAttack = BitboardJumps.PawnJumps[opponentColor][kingPos];
	if ((pawnAttack & bitboards[Pieces::Pawn | color]) != 0)
	{
		return true;
	}

	const Bitboard diagonalAttack = SlideMoveGenerator::DiagonalAntidiagonalSlide(allPieces, kingPos);
	if ((diagonalAttack & (bitboards[Pieces::Bishop | color] | bitboards[Pieces::Queen | color])) != 0)
	{
		return true;
	}

	const Bitboard verticalAttack = SlideMoveGenerator::HorizontalVerticalSlide(allPieces, kingPos);
	if ((verticalAttack & (bitboards[Pieces::Rook | color] | bitboards[Pieces::Queen | color])) != 0)
	{
		return true;
	}

	return false;
}