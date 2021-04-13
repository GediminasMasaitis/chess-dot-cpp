#include "movegen.h"

#include "common.h"
#include "magics.h"

#include <exception>
#include <iostream>

#include "fen.h"

constexpr Bitboard GetAttackedByPawns(const Bitboard myPawns, const bool whiteToMove)
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

//constexpr Bitboard GetAttackedByJumpingPieces(Bitboard jumpingPieces, const Bitboard jumpMask, const Position jumpMaskCenter)
//{
//	Bitboard allJumps = 0;
//	while (jumpingPieces != 0)
//	{
//		const Position i = BitScanForward(jumpingPieces);
//		const Bitboard jumps = GetAttackedByJumpingPiece(i, jumpMask, jumpMaskCenter);
//		allJumps |= jumps;
//		jumpingPieces &= ~GetBitboard(i);
//	}
//	return allJumps;
//}

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
		pawns = board.BitBoard[ChessPiece::WhitePawn] & allPieces;
		bq = board.BitBoard[ChessPiece::WhiteBishop] | board.BitBoard[ChessPiece::WhiteQueen];
		rq = board.BitBoard[ChessPiece::WhiteRook] | board.BitBoard[ChessPiece::WhiteQueen];
		knights = board.BitBoard[ChessPiece::WhiteKnight];
		kings = board.BitBoard[ChessPiece::WhiteKing];
	}
	else
	{
		pawns = board.BitBoard[ChessPiece::BlackPawn] & allPieces;
		bq = board.BitBoard[ChessPiece::BlackBishop] | board.BitBoard[ChessPiece::BlackQueen];
		rq = board.BitBoard[ChessPiece::BlackRook] | board.BitBoard[ChessPiece::BlackQueen];
		knights = board.BitBoard[ChessPiece::BlackKnight];
		kings = board.BitBoard[ChessPiece::BlackKing];
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

Bitboard DiagonalAntidiagonalXray(const Bitboard allPieces, Bitboard ownPieces, const Position position)
{
	const auto attacks = SlideMoveGenerator::DiagonalAntidiagonalSlide(allPieces, position);
	ownPieces &= attacks;
	const auto xrayAttacks = attacks ^ SlideMoveGenerator::DiagonalAntidiagonalSlide(allPieces ^ ownPieces, position);
	return xrayAttacks;
}

Bitboard HorizontalVerticalXray(const Bitboard allPieces, Bitboard ownPieces, const Position position)
{
	const auto attacks = SlideMoveGenerator::HorizontalVerticalSlide(allPieces, position);
	ownPieces &= attacks;
	const auto xrayAttacks = attacks ^ SlideMoveGenerator::HorizontalVerticalSlide(allPieces ^ ownPieces, position);
	return xrayAttacks;
}

Bitboard PinDetector::GetPinned(const Board& board, Piece color, Position pos)
{
	const Piece opponentColor = static_cast<Piece>(color ^ 1);
	Bitboard pinned = 0ULL;
	const Bitboard ownPieces = board.BitBoard[board.ColorToMove];

	Bitboard xrays = DiagonalAntidiagonalXray(board.AllPieces, ownPieces, pos);
	Bitboard pinners = xrays & (board.BitBoard[ChessPiece::Bishop | opponentColor] | board.BitBoard[ChessPiece::Queen | opponentColor]);

	while (pinners != 0)
	{
		const Position pinner = BitScanForward(pinners);
		pinned |= BetweenBitboards.Between[pinner][pos] & ownPieces;
		pinners &= pinners - 1;
	}

	xrays = HorizontalVerticalXray(board.AllPieces, ownPieces, pos);
	pinners = xrays & (board.BitBoard[ChessPiece::Rook | opponentColor] | board.BitBoard[ChessPiece::Queen | opponentColor]);

	while (pinners != 0)
	{
		const Position pinner = BitScanForward(pinners);
		pinned |= BetweenBitboards.Between[pinner][pos] & ownPieces;
		pinners &= pinners - 1;
	}
	return pinned;
}

template<Piece TColor>
Bitboard GetPinnedForColor(const Board& board, Position pos)
{
	constexpr Piece color = TColor;
	constexpr Piece opponentColor = color ^ 1;
	constexpr Piece opponentBishop = ChessPiece::Bishop | opponentColor;
	constexpr Piece opponentRook = ChessPiece::Rook | opponentColor;
	constexpr Piece opponentQueen = ChessPiece::Queen | opponentColor;
	
	Bitboard pinned = 0ULL;
	const Bitboard ownPieces = board.BitBoard[color];

	Bitboard xrays = DiagonalAntidiagonalXray(board.AllPieces, ownPieces, pos);
	Bitboard pinners = xrays & (board.BitBoard[opponentBishop] | board.BitBoard[opponentQueen]);

	while (pinners != 0)
	{
		const Position pinner = BitScanForward(pinners);
		pinned |= BetweenBitboards.Between[pinner][pos] & ownPieces;
		pinners &= pinners - 1;
	}

	xrays = HorizontalVerticalXray(board.AllPieces, ownPieces, pos);
	pinners = xrays & (board.BitBoard[opponentRook] | board.BitBoard[opponentQueen]);

	while (pinners != 0)
	{
		const Position pinner = BitScanForward(pinners);
		pinned |= BetweenBitboards.Between[pinner][pos] & ownPieces;
		pinners &= pinners - 1;
	}
	return pinned;
}

Bitboard GetPinnedData(const Board& board, Piece color, Position pos, PinPaths& paths)
{
	paths.fill(~0ULL);
	const Piece opponentColor = static_cast<Piece>(color ^ 1);
	Bitboard allPinned = 0ULL;
	const Bitboard ownPieces = board.BitBoard[board.ColorToMove];

	Bitboard xrays = DiagonalAntidiagonalXray(board.AllPieces, ownPieces, pos);
	Bitboard pinners = xrays & (board.BitBoard[ChessPiece::Bishop | opponentColor] | board.BitBoard[ChessPiece::Queen | opponentColor]);

	while (pinners != 0)
	{
		const Position pinnerPos = BitScanForward(pinners);
		const Bitboard pinnerBitboard = GetBitboard(pinnerPos);
		const Bitboard between = BetweenBitboards.Between[pinnerPos][pos];
		const Bitboard pinnedBitboard = between & ownPieces;
		const Position pinnedPos = BitScanForward(pinnedBitboard);
		paths[pinnedPos] = between | pinnerBitboard;
		allPinned |= pinnedBitboard;
		pinners &= pinners - 1;
	}

	xrays = HorizontalVerticalXray(board.AllPieces, ownPieces, pos);
	pinners = xrays & (board.BitBoard[ChessPiece::Rook | opponentColor] | board.BitBoard[ChessPiece::Queen | opponentColor]);

	while (pinners != 0)
	{
		const Position pinnerPos = BitScanForward(pinners);
		const Bitboard pinnerBitboard = GetBitboard(pinnerPos);
		const Bitboard between = BetweenBitboards.Between[pinnerPos][pos];
		const Bitboard pinnedBitboard = between & ownPieces;
		const Position pinnedPos = BitScanForward(pinnedBitboard);
		paths[pinnedPos] = between | pinnerBitboard;
		allPinned |= pinnedBitboard;
		pinners &= pinners - 1;
	}
	return allPinned;
}

template<Piece TColor>
void GeneratePromotionMoves
(
	const Position from,
	const Position to,
	const Piece takesPiece,
	MoveArray& moves,
	size_t& moveCount
)
{
	constexpr Piece color = TColor;
	constexpr Piece piece = ChessPiece::Pawn | color;
	constexpr Piece queen = ChessPiece::Queen | color;
	constexpr Piece knight = ChessPiece::Knight | color;
	constexpr Piece rook = ChessPiece::Rook | color;
	constexpr Piece bishop = ChessPiece::Bishop | color;
	
	moves[moveCount++] = Move(from, to, piece, takesPiece, false, false, queen);
	moves[moveCount++] = Move(from, to, piece, takesPiece, false, false, knight);
	moves[moveCount++] = Move(from, to, piece, takesPiece, false, false, rook);
	moves[moveCount++] = Move(from, to, piece, takesPiece, false, false, bishop);
}

void GetPotentialWhitePawnCaptures(const Board& board, Bitboard allowedFrom, Bitboard allowedTo, MoveArray& moves, size_t& moveCount)
{
	const Bitboard pawns = board.BitBoard[ChessPiece::WhitePawn] & allowedFrom;
	Bitboard takeLeft = (pawns << 7) & ~BitboardConstants::Files[7] & board.BitBoard[ChessPiece::Black] & allowedTo;
	while (takeLeft != 0)
	{
		const Position i = BitScanForward(takeLeft);
		if (i > 55)
		{
			GeneratePromotionMoves<ChessPiece::White>(i - 7, i, board.ArrayBoard[i], moves, moveCount);
		}
		else
		{
			const auto move = Move(i - 7, i, ChessPiece::WhitePawn, board.ArrayBoard[i]);
			moves[moveCount++] = move;
		}
		takeLeft &= takeLeft - 1;
	}

	Bitboard takeRight = (pawns << 9) & ~BitboardConstants::Files[0] & board.BitBoard[ChessPiece::Black] & allowedTo;
	while (takeRight != 0)
	{
		const Position i = BitScanForward(takeRight);
		if (i > 55)
		{
			GeneratePromotionMoves<ChessPiece::White>(i - 9, i, board.ArrayBoard[i], moves, moveCount);
		}
		else
		{
			const auto move = Move(i - 9, i, ChessPiece::WhitePawn, board.ArrayBoard[i]);
			moves[moveCount++] = move;
		}
		takeRight &= takeRight - 1;
	}

	Bitboard enPassantLeft = (pawns << 7) & ~BitboardConstants::Files[7] & board.EnPassantFile & BitboardConstants::Ranks[5] & board.BitBoard[ChessPiece::BlackPawn] << 8;
	while (enPassantLeft != 0)
	{
		const Position i = BitScanForward(enPassantLeft);
		const auto move = Move(i - 7, i, ChessPiece::WhitePawn, board.ArrayBoard[i - 8], true);
		moves[moveCount++] = move;
		enPassantLeft &= enPassantLeft - 1;
	}


	Bitboard enPassantRight = (pawns << 9) & ~BitboardConstants::Files[0] & board.EnPassantFile & BitboardConstants::Ranks[5] & board.BitBoard[ChessPiece::BlackPawn] << 8;
	while (enPassantRight != 0)
	{
		const Position i = BitScanForward(enPassantRight);
		const auto move = Move(i - 9, i, ChessPiece::WhitePawn, board.ArrayBoard[i - 8], true);
		moves[moveCount++] = move;
		enPassantRight &= enPassantRight - 1;
	}
}

template<Piece TColor>
void GetPotentialPawnMoves(const Board& board, Bitboard allowedFrom, Bitboard allowedTo, MoveArray& moves, size_t& moveCount)
{
	constexpr Piece color = TColor;
	constexpr bool isWhite = color == ChessPiece::White;
	constexpr Piece piece = ChessPiece::Pawn | color;
	constexpr Bitboard rank2 = isWhite ? BitboardConstants::Ranks[1] : BitboardConstants::Ranks[6];
	constexpr Bitboard rank7 = isWhite ? BitboardConstants::Ranks[6] : BitboardConstants::Ranks[1];
	constexpr int8_t push1From = isWhite ? -8 : 8;
	constexpr int8_t push2From = isWhite ? -16 : 16;
		
	const Bitboard pawns = board.BitBoard[piece] & allowedFrom;
	const Bitboard allowedPush = allowedTo & board.EmptySquares;

	Bitboard promote = allowedPush;
	Bitboard moveOne = allowedPush;
	Bitboard moveTwo;
	if constexpr (isWhite)
	{
		promote &= (pawns & rank7) << 8;
		moveOne &= (pawns & ~rank7) << 8;
		moveTwo = ((((pawns & rank2) << 8) & board.EmptySquares) << 8) & allowedPush;
	}
	else
	{
		promote &= (pawns & rank7) >> 8;
		moveOne &= (pawns & ~rank7) >> 8;
		moveTwo = ((((pawns & rank2) >> 8) & board.EmptySquares) >> 8) & allowedPush;
	}
	
	while (promote != 0)
	{
		const Position position = BitScanForward(promote);
		const Position from = position + push1From;
		GeneratePromotionMoves<TColor>(from, position, ChessPiece::Empty, moves, moveCount);
		promote &= promote - 1;
	}
		
	while (moveOne != 0)
	{
		const Position position = BitScanForward(moveOne);
		const Position from = position + push1From;
		const auto move = Move(from, position, piece);
		moves[moveCount++] = move;
		moveOne &= moveOne - 1;
	}
		
	while (moveTwo != 0)
	{
		const Position position = BitScanForward(moveTwo);
		const Position from = position + push2From;
		const auto move = Move(from, position, piece);
		moves[moveCount++] = move;
		moveTwo &= moveTwo - 1;
	}
}

void GetPotentialBlackPawnCaptures(const Board& board, Bitboard allowedFrom, Bitboard allowedTo, MoveArray& moves, size_t& moveCount)
{
	const Bitboard pawns = board.BitBoard[ChessPiece::BlackPawn] & allowedFrom;
	Bitboard takeLeft = (pawns >> 7) & ~BitboardConstants::Files[0] & board.BitBoard[ChessPiece::White] & allowedTo;
	while (takeLeft != 0)
	{
		const Position i = BitScanForward(takeLeft);
		if (i < 8)
		{
			GeneratePromotionMoves<ChessPiece::Black>(i + 7, i, board.ArrayBoard[i], moves, moveCount);
		}
		else
		{
			const auto move = Move(i + 7, i, ChessPiece::BlackPawn, board.ArrayBoard[i]);
			moves[moveCount++] = move;
		}
		takeLeft &= takeLeft - 1;
	}

	Bitboard takeRight = (pawns >> 9) & ~BitboardConstants::Files[7] & board.BitBoard[ChessPiece::White] & allowedTo;
	while (takeRight != 0)
	{
		const Position i = BitScanForward(takeRight);
		if (i < 8)
		{
			GeneratePromotionMoves<ChessPiece::Black>(i + 9, i, board.ArrayBoard[i], moves, moveCount);
		}
		else
		{
			const auto move = Move(i + 9, i, ChessPiece::BlackPawn, board.ArrayBoard[i]);
			moves[moveCount++] = move;
		}
		takeRight &= takeRight - 1;
	}

	Bitboard enPassantLeft = (pawns >> 7) & ~BitboardConstants::Files[0] & board.EnPassantFile & BitboardConstants::Ranks[2] & board.BitBoard[ChessPiece::WhitePawn] >> 8;
	while (enPassantLeft != 0)
	{
		const Position i = BitScanForward(enPassantLeft);
		const auto move = Move(i + 7, i, ChessPiece::BlackPawn, board.ArrayBoard[i + 8], true);
		moves[moveCount++] = move;
		enPassantLeft &= enPassantLeft - 1;
	}


	Bitboard enPassantRight = (pawns >> 9) & ~BitboardConstants::Files[7] & board.EnPassantFile & BitboardConstants::Ranks[2] & board.BitBoard[ChessPiece::WhitePawn] >> 8;
	while (enPassantRight != 0)
	{
		const Position i = BitScanForward(enPassantRight);
		const auto move = Move(i + 9, i, ChessPiece::BlackPawn, board.ArrayBoard[i + 8], true);
		moves[moveCount++] = move;
		enPassantRight &= enPassantRight - 1;
	}
}

template<Piece TPiece>
void BitmaskToMoves
(
	const Board& board,
	Bitboard bitmask,
	const Position positionFrom,
	MoveArray& moves,
	size_t& moveCount
)
{
	constexpr Piece piece = TPiece;
	while (bitmask != 0)
	{
		const auto i = BitScanForward(bitmask);
		const auto move = Move(positionFrom, i, piece, board.ArrayBoard[i]);
		moves[moveCount++] = move;
		bitmask &= bitmask - 1;
	}
}

template<Piece TPiece>
void GetPotentialJumpingMoves
(
	const Board& board,
	const Bitboard allowedTo,
	Bitboard jumpingPieces,
	const JumpArray& jumpTable,
	MoveArray& moves,
	size_t& moveCount
)
{
	while (jumpingPieces != 0)
	{
		const Position i = BitScanForward(jumpingPieces);
		Bitboard jumps = jumpTable[i];
		jumps &= allowedTo;
		BitmaskToMoves<TPiece>(board, jumps, i, moves, moveCount);
		jumpingPieces &= jumpingPieces - 1;
	}
}

template<Piece TColor>
void GetPotentialKnightMoves(const Board& board, Bitboard allowedFrom, Bitboard allowedTo, MoveArray& moves, size_t& moveCount)
{
	constexpr Piece color = TColor;
	constexpr Piece piece = ChessPiece::Knight | color;
	const Bitboard knights = board.BitBoard[piece] & allowedFrom;
	GetPotentialJumpingMoves<piece>(board, allowedTo, knights, BitboardJumps.KnightJumps, moves, moveCount);
}

template<Piece TColor>
void GetPotentialKingMoves(const Board& board, const Bitboard allowedTo, MoveArray& moves, size_t& moveCount)
{
	constexpr Piece color = TColor;
	constexpr Piece piece = ChessPiece::King | color;
	const Bitboard kings = board.BitBoard[piece];
	GetPotentialJumpingMoves<piece>(board, allowedTo, kings, BitboardJumps.KingJumps, moves, moveCount);
}

void GetPotentialCastlingMoves(const Board& board, MoveArray& moves, size_t& moveCount)
{
	const bool isWhite = board.WhiteToMove;
	Position kingPos;
	Bitboard queenSideCastleMask;
	Bitboard kingSideCastleMask;
	Bitboard queenSideCastleAttackMask;
	Bitboard kingSideCastleAttackMask;
	Piece piece;
	bool castlingPermissionQueenSide;
	bool castlingPermissionKingSide;

	if (isWhite)
	{
		castlingPermissionQueenSide = (board.CastlingPermissions & ChessCastlingPermissions::WhiteQueen) != ChessCastlingPermissions::None;
		castlingPermissionKingSide = (board.CastlingPermissions & ChessCastlingPermissions::WhiteKing) != ChessCastlingPermissions::None;
		kingPos = BitScanForward(board.BitBoard[ChessPiece::WhiteKing]);
		queenSideCastleMask = BitboardConstants::WhiteQueenSideCastleMask;
		kingSideCastleMask = BitboardConstants::WhiteKingSideCastleMask;
		queenSideCastleAttackMask = BitboardConstants::WhiteQueenSideCastleAttackMask;
		kingSideCastleAttackMask = BitboardConstants::WhiteKingSideCastleAttackMask;
		piece = ChessPiece::WhiteKing;
	}
	else
	{
		castlingPermissionQueenSide = (board.CastlingPermissions & ChessCastlingPermissions::BlackQueen) != ChessCastlingPermissions::None;
		castlingPermissionKingSide = (board.CastlingPermissions & ChessCastlingPermissions::BlackKing) != ChessCastlingPermissions::None;
		kingPos = BitScanForward(board.BitBoard[ChessPiece::BlackKing]);
		queenSideCastleMask = BitboardConstants::BlackQueenSideCastleMask;
		kingSideCastleMask = BitboardConstants::BlackKingSideCastleMask;
		queenSideCastleAttackMask = BitboardConstants::BlackQueenSideCastleAttackMask;
		kingSideCastleAttackMask = BitboardConstants::BlackKingSideCastleAttackMask;
		piece = ChessPiece::BlackKing;
	}

	const bool canMaybeCastleQueenSide = castlingPermissionQueenSide && ((board.AllPieces & queenSideCastleMask) == 0);
	const bool canMaybeCastleKingSide = castlingPermissionKingSide && (board.AllPieces & kingSideCastleMask) == 0;

	if (canMaybeCastleQueenSide | canMaybeCastleKingSide)
	{
		const Bitboard attackedByEnemy = AttacksGenerator::GetAllAttacked(board, !board.WhiteToMove, board.AllPieces);
		if (canMaybeCastleQueenSide && ((attackedByEnemy & queenSideCastleAttackMask) == 0))
		{
			moves[moveCount++] = Move(kingPos, kingPos - 2, piece, ChessPiece::Empty, false, true);
		}
		if (canMaybeCastleKingSide && ((attackedByEnemy & kingSideCastleAttackMask) == 0))
		{
			moves[moveCount++] = Move(kingPos, kingPos + 2, piece, ChessPiece::Empty, false, true);
		}
	}
}

template<Piece TColor>
void GetPotentialRookMoves(const Board& board, const Bitboard allowedFrom, const Bitboard allowedTo, MoveArray& moves, size_t& moveCount)
{
	constexpr Piece color = TColor;
	constexpr Piece piece = ChessPiece::Rook | color;
	Bitboard piecesBitmask = board.BitBoard[piece] & allowedFrom;
	while (piecesBitmask != 0)
	{
		const Position position = BitScanForward(piecesBitmask);
		Bitboard slide = SlideMoveGenerator::HorizontalVerticalSlide(board.AllPieces, position);
		slide &= allowedTo;
		BitmaskToMoves<piece>(board, slide, position, moves, moveCount);
		piecesBitmask &= piecesBitmask - 1;
	}
}

template<Piece TColor>
void GetPotentialBishopMoves(const Board& board, const Bitboard allowedFrom, const Bitboard allowedTo, MoveArray& moves, size_t& moveCount)
{
	constexpr Piece color = TColor;
	constexpr Piece piece = ChessPiece::Bishop | color;
	Bitboard piecesBitmask = board.BitBoard[piece] & allowedFrom;
	while (piecesBitmask != 0)
	{
		const Position position = BitScanForward(piecesBitmask);
		Bitboard slide = SlideMoveGenerator::DiagonalAntidiagonalSlide(board.AllPieces, position);
		slide &= allowedTo;
		BitmaskToMoves<piece>(board, slide, position, moves, moveCount);
		piecesBitmask &= piecesBitmask - 1;
	}
}

template<Piece TColor>
void GetPotentialQueenMoves(const Board& board, const Bitboard allowedFrom, const Bitboard allowedTo, MoveArray& moves, size_t& moveCount)
{
	constexpr Piece color = TColor;
	constexpr Piece piece = ChessPiece::Queen | color;
	Bitboard piecesBitmask = board.BitBoard[piece] & allowedFrom;
	while (piecesBitmask != 0)
	{
		const Position position = BitScanForward(piecesBitmask);
		Bitboard slide = SlideMoveGenerator::AllSlide(board.AllPieces, position);
		slide &= allowedTo;
		BitmaskToMoves<piece>(board, slide, position, moves, moveCount);
		piecesBitmask &= piecesBitmask - 1;
	}
}

template<Piece TColor>
void GetAllPotentialMovesForColor(const Board& board, const Bitboard checkers, const Bitboard pinned, MoveArray& moves, size_t& moveCount)
{
	Bitboard allowedFrom = ~0ULL;
	Bitboard allowedTo = board.EmptySquares | board.BitBoard[board.ColorToMove ^ 1];
	Bitboard allowedToKing = allowedTo;

	const auto checkCount = PopCount(checkers);
	if (checkCount > 1)
	{
		GetPotentialKingMoves<TColor>(board, allowedToKing, moves, moveCount);
		return;
	}

	//auto boardStr = Fens::Serialize(board);
	//if(boardStr == "rnbqkbnr/p1pppppp/8/1P6/1P6/8/2PPPPPP/RNBQKBNR b KQkq b3")
	//{
	//	auto a = 123;
	//}



	if (checkCount == 1)
	{
		allowedFrom = ~pinned;

		const Position checkerPos = BitScanForward(checkers);
		allowedTo = BetweenBitboards.Between[board.KingPositions[board.ColorToMove]][checkerPos] | checkers;
	}
	else
	{
		GetPotentialCastlingMoves(board, moves, moveCount);
	}

	GetPotentialKnightMoves<TColor>(board, allowedFrom, allowedTo, moves, moveCount);
	GetPotentialBishopMoves<TColor>(board, allowedFrom, allowedTo, moves, moveCount);
	GetPotentialRookMoves<TColor>(board, allowedFrom, allowedTo, moves, moveCount);
	GetPotentialQueenMoves<TColor>(board, allowedFrom, allowedTo, moves, moveCount);
	GetPotentialKingMoves<TColor>(board, allowedToKing, moves, moveCount);

	if constexpr (TColor == ChessPiece::White)
	{
		GetPotentialWhitePawnCaptures(board, allowedFrom, allowedTo, moves, moveCount);
	}
	else
	{
		GetPotentialBlackPawnCaptures(board, allowedFrom, allowedTo, moves, moveCount);
	}
	
	GetPotentialPawnMoves<TColor>(board, allowedFrom, allowedTo, moves, moveCount);
}

void MoveGenerator::GetAllPotentialMoves(const Board& board, const Bitboard checkers, const Bitboard pinned, MoveArray& moves, size_t& moveCount)
{
	if (board.WhiteToMove)
	{
		GetAllPotentialMovesForColor<ChessPiece::White>(board, checkers, pinned, moves, moveCount);
	}
	else
	{
		GetAllPotentialMovesForColor<ChessPiece::Black>(board, checkers, pinned, moves, moveCount);
	}
}

template<Piece TColor>
void GetAllPotentialCapturesForColor(const Board& board, const Bitboard checkers, const Bitboard pinned, MoveArray& moves, size_t& moveCount)
{
	Bitboard allowedFrom = ~0ULL;
	Bitboard allowedTo = board.BitBoard[board.ColorToMove ^ 1];
	Bitboard allowedToKing = allowedTo;

	const auto checkCount = PopCount(checkers);
	if (checkCount > 1)
	{
		GetPotentialKingMoves<TColor>(board, allowedToKing, moves, moveCount);
		return;
	}

	if (checkCount == 1)
	{
		allowedFrom = ~pinned;
		allowedTo = checkers;
	}

	GetPotentialKnightMoves<TColor>(board, allowedFrom, allowedTo, moves, moveCount);
	GetPotentialBishopMoves<TColor>(board, allowedFrom, allowedTo, moves, moveCount);
	GetPotentialRookMoves<TColor>(board, allowedFrom, allowedTo, moves, moveCount);
	GetPotentialQueenMoves<TColor>(board, allowedFrom, allowedTo, moves, moveCount);
	GetPotentialKingMoves<TColor>(board, allowedToKing, moves, moveCount);

	if constexpr (TColor == ChessPiece::White)
	{
		GetPotentialWhitePawnCaptures(board, allowedFrom, allowedTo, moves, moveCount);
	}
	else
	{
		GetPotentialBlackPawnCaptures(board, allowedFrom, allowedTo, moves, moveCount);
	}
}

void MoveGenerator::GetAllPotentialCaptures(const Board& board, const Bitboard checkers, const Bitboard pinned, MoveArray& moves, size_t& moveCount)
{
	if (board.WhiteToMove)
	{
		GetAllPotentialCapturesForColor<ChessPiece::White>(board, checkers, pinned, moves, moveCount);
	}
	else
	{
		GetAllPotentialCapturesForColor<ChessPiece::Black>(board, checkers, pinned, moves, moveCount);
	}
}

//bool IsKingSafeAfterMoveOld(const Board& board, const Move move)
//{
//	Bitboard allPieces = board.AllPieces;
//	const Bitboard inverseFromBitboard = ~GetBitboard(move.GetFrom());
//	const Bitboard toBitboard = GetBitboard(move.GetTo());
//	allPieces &= inverseFromBitboard;
//	allPieces |= toBitboard;
//	if (move.GetEnPassant())
//	{
//		const Bitboard enPassantedBitboard = board.WhiteToMove ? toBitboard >> 8 : toBitboard << 8;
//		allPieces &= ~enPassantedBitboard;
//	}
//	
//	const auto enemyAttackedAfterMove = AttacksGenerator::GetAllAttacked(board, !board.WhiteToMove, allPieces, ~toBitboard);
//
//	auto myKings = board.WhiteToMove ? board.BitBoard[ChessPiece::WhiteKing] : board.BitBoard[ChessPiece::BlackKing];
//	if ((board.WhiteToMove && move.GetPiece() == ChessPiece::WhiteKing) || (!board.WhiteToMove && move.GetPiece() == ChessPiece::BlackKing))
//	{
//		myKings &= inverseFromBitboard;
//		myKings |= toBitboard;
//	}
//
//	const bool isSafe = (enemyAttackedAfterMove & myKings) == 0;
//	return isSafe;
//}


bool MoveValidator::IsKingSafeAfterMove(const Board& board, const Move move)
{
	const Position from = move.GetFrom();
	const Position to = move.GetTo();
	const Piece piece = move.GetPiece();
	
	Bitboard allPieces = board.AllPieces;
	const Bitboard fromBitboard = GetBitboard(from);
	const Bitboard toBitboard = GetBitboard(to);

	allPieces &= ~fromBitboard;
	allPieces |= toBitboard;

	Bitboard takesBitboard = toBitboard;
	if (move.GetEnPassant())
	{
		const Bitboard enPassantedBitboard = board.WhiteToMove ? toBitboard >> 8 : toBitboard << 8;
		allPieces &= ~enPassantedBitboard;
		takesBitboard |= enPassantedBitboard;
	}
		
	const bool kingMove = piece == ChessPiece::WhiteKing || piece == ChessPiece::BlackKing;
	const Position myKingPos = kingMove ? to : board.KingPositions[board.ColorToMove];

	const Bitboard invTakes = ~takesBitboard;

	Bitboard pawns;
	Bitboard knights;
	Bitboard bishops;
	Bitboard rooks;
	Bitboard queens;
	Bitboard kings;
	if (board.WhiteToMove)
	{
		pawns = board.BitBoard[ChessPiece::BlackPawn] & invTakes;
		knights = board.BitBoard[ChessPiece::BlackKnight] & invTakes;
		bishops = board.BitBoard[ChessPiece::BlackBishop] & invTakes;
		rooks = board.BitBoard[ChessPiece::BlackRook] & invTakes;
		queens = board.BitBoard[ChessPiece::BlackQueen] & invTakes;
		kings = board.BitBoard[ChessPiece::BlackKing] & invTakes;
	}
	else
	{
		pawns = board.BitBoard[ChessPiece::WhitePawn] & invTakes;
		knights = board.BitBoard[ChessPiece::WhiteKnight] & invTakes;
		bishops = board.BitBoard[ChessPiece::WhiteBishop] & invTakes;
		rooks = board.BitBoard[ChessPiece::WhiteRook] & invTakes;
		queens = board.BitBoard[ChessPiece::WhiteQueen] & invTakes;
		kings = board.BitBoard[ChessPiece::WhiteKing] & invTakes;
	}

	const Bitboard knightAttack = BitboardJumps.KnightJumps[myKingPos];
	if ((knightAttack & knights) != 0)
	{
		return false;
	}

	const Bitboard kingAttack = BitboardJumps.KingJumps[myKingPos];
	if ((kingAttack & kings) != 0)
	{
		return false;
	}

	const Bitboard pawnAttack = BitboardJumps.PawnJumps[board.ColorToMove][myKingPos]; //AttacksService.GetAttackedByPawns(myKings, board.WhiteToMove);
	if ((pawnAttack & pawns) != 0)
	{
		return false;
	}
	
	const Bitboard diagonalAttack = SlideMoveGenerator::DiagonalAntidiagonalSlide(allPieces, myKingPos);
	if ((diagonalAttack & (bishops | queens)) != 0)
	{
		return false;
	}

	const Bitboard verticalAttack = SlideMoveGenerator::HorizontalVerticalSlide(allPieces, myKingPos);
	if ((verticalAttack & (rooks | queens)) != 0)
	{
		return false;
	}

	return true;
}

bool MoveValidator::IsKingSafeAfterMove2(const Board& board, Move move, Bitboard checkers, Bitboard pinnedPieces)
{
	//return IsKingSafeAfterMove(board, move);
	const bool kingMove = move.GetPiece() == ChessPiece::King + board.ColorToMove;
	const bool isPinned = (pinnedPieces & GetBitboard(move.GetFrom())) != 0;

	//auto checkCount = PopCount(checkers);
	//if (checkCount == 1 && !kingMove)
	//{
	//    if (isPinned)
	//    {
	//        return false;
	//    }

	//	auto toBitboard = GetBitboard(move.GetTo());
	//    auto checkerPos = BitScanForward(checkers);
	//    auto canMoveTo = BetweenBitboards.Between[board.KingPositions[board.ColorToMove]][checkerPos] | checkers;

	//    if ((canMoveTo & toBitboard) == 0)
	//    {
	//        return false;
	//    }

	//    return true;
	//}
	
	//if (isPinned)
	//{
	//	auto toBitboard = GetBitboard(move.GetTo());
	//    auto canMoveTo = BetweenBitboards.Between[board.KingPositions[board.ColorToMove]][move.GetFrom()];
	//    if ((canMoveTo & toBitboard) != 0)
	//    {
	//        return true;
	//    }
	//}
	
	if
	(
		move.GetEnPassant()
		|| kingMove
		|| isPinned
	)
	{
		return IsKingSafeAfterMove(board, move);
	}

	return true;
}

void MoveValidator::FilterMovesByKingSafety(const Board& board, Bitboard checkers, Bitboard pinnedPieces, MoveArray& moves, size_t& moveCount)
{
	size_t toRemove = 0;
	for (size_t i = 0; i < moveCount; i++)
	{
		auto move = moves[i];
		bool safe = IsKingSafeAfterMove2(board, move, checkers, pinnedPieces);
		if (safe)
		{
			if (toRemove > 0)
			{
				moves[i - toRemove] = move;
			}
		}
		else
		{
			toRemove++;
		}
	}
	moveCount -= toRemove;
}

Bitboard GetAttackersOfSide(const Board& board, Position position, bool byWhite, Bitboard allPieces)
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
		pawns = board.BitBoard[ChessPiece::WhitePawn];
		knights = board.BitBoard[ChessPiece::WhiteKnight];
		bishops = board.BitBoard[ChessPiece::WhiteBishop];
		rooks = board.BitBoard[ChessPiece::WhiteRook];
		queens = board.BitBoard[ChessPiece::WhiteQueen];
		kings = board.BitBoard[ChessPiece::WhiteKing];
	}
	else
	{
		pawns = board.BitBoard[ChessPiece::BlackPawn];
		knights = board.BitBoard[ChessPiece::BlackKnight];
		bishops = board.BitBoard[ChessPiece::BlackBishop];
		rooks = board.BitBoard[ChessPiece::BlackRook];
		queens = board.BitBoard[ChessPiece::BlackQueen];
		kings = board.BitBoard[ChessPiece::BlackKing];
	}

	const Bitboard knightAttack = BitboardJumps.KnightJumps[position];
	result |= knightAttack & knights;

	const Bitboard kingAttack = BitboardJumps.KingJumps[position];
	result |= kingAttack & kings;

	const Piece pawnIndex = byWhite ? ChessPiece::Black : ChessPiece::White;
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

Bitboard GetCheckers(const Board& board)
{
	const Bitboard checkers = GetAttackersOfSide(board, board.KingPositions[board.ColorToMove], !board.WhiteToMove, board.AllPieces);
	return checkers;
}

template<Piece TColor>
void GetAllPossibleMovesForColor(const Board& board, MoveArray& moves, size_t& moveCount)
{
	const Bitboard checkers = GetCheckers(board);
	const Bitboard pinned = GetPinnedForColor<TColor>(board, board.KingPositions[board.ColorToMove]);
	GetAllPotentialMovesForColor<TColor>(board, checkers, pinned, moves, moveCount);
	MoveValidator::FilterMovesByKingSafety(board, checkers, pinned, moves, moveCount);
}

void MoveGenerator::GetAllPossibleMoves(const Board& board, MoveArray& moves, size_t& moveCount)
{
	if (board.WhiteToMove)
	{
		GetAllPossibleMovesForColor<ChessPiece::White>(board, moves, moveCount);
	}
	else
	{
		GetAllPossibleMovesForColor<ChessPiece::Black>(board, moves, moveCount);
	}
}