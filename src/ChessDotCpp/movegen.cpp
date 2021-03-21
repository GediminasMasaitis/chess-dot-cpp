#include "movegen.h"

#include "common.h"
#include "magics.h"

#include <exception>

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

constexpr Bitboard GetAttackedByJumpingPieces(Bitboard jumpingPieces, const Bitboard jumpMask, const Position jumpMaskCenter)
{
	Bitboard allJumps = 0;
	while (jumpingPieces != 0)
	{
		const Position i = BitScanForward(jumpingPieces);
		Bitboard jumps;
		if (i > jumpMaskCenter)
		{
			jumps = jumpMask << (i - jumpMaskCenter);
		}
		else
		{
			jumps = jumpMask >> (jumpMaskCenter - i);
		}

		jumps &= ~(i % 8 < 4 ? BitboardConstants::Files[6] | BitboardConstants::Files[7] : BitboardConstants::Files[0] | BitboardConstants::Files[1]);
		allJumps |= jumps;
		jumpingPieces &= ~GetBitboard(i);
	}
	return allJumps;
}

constexpr Bitboard GetAttackedByKings(Bitboard kings)
{
	return GetAttackedByJumpingPieces(kings, BitboardConstants::KingSpan, BitboardConstants::KingSpanPosition);
}

constexpr Bitboard GetAttackedByKnights(Bitboard knights)
{
	return GetAttackedByJumpingPieces(knights, BitboardConstants::KnightSpan, BitboardConstants::KnightSpanPosition);
}

Bitboard AttacksGenerator::GetAllAttacked(Board board, const bool whiteToMove, const Bitboard allPieces, const Bitboard canAttackFrom)
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

void GeneratePromotionMoves
(
	const Position from,
	const Position to,
	const Piece takesPiece,
	const bool forWhite,
	MoveArray& moves,
	size_t& moveCount
)
{
	const Piece piece = forWhite ? ChessPiece::WhitePawn : ChessPiece::BlackPawn;
	
	moves[moveCount++] = Move(from, to, piece, takesPiece, false, false, forWhite ? ChessPiece::WhiteKnight : ChessPiece::BlackKnight);
	moves[moveCount++] = Move(from, to, piece, takesPiece, false, false, forWhite ? ChessPiece::WhiteBishop : ChessPiece::BlackBishop);
	moves[moveCount++] = Move(from, to, piece, takesPiece, false, false, forWhite ? ChessPiece::WhiteRook : ChessPiece::BlackRook);
	moves[moveCount++] = Move(from, to, piece, takesPiece, false, false, forWhite ? ChessPiece::WhiteQueen : ChessPiece::BlackQueen);
}

void GetPotentialWhitePawnCaptures(const Board& board, MoveArray& moves, size_t& moveCount)
{
	Bitboard takeLeft = (board.BitBoard[ChessPiece::WhitePawn] << 7) & ~BitboardConstants::Files[7] & board.BlackPieces;
	while (takeLeft != 0)
	{
		const Position i = BitScanForward(takeLeft);
		if (i > 55)
		{
			GeneratePromotionMoves(i - 7, i, board.ArrayBoard[i], true, moves, moveCount);
		}
		else
		{
			const auto move = Move(i - 7, i, ChessPiece::WhitePawn, board.ArrayBoard[i]);
			moves[moveCount++] = move;
		}
		takeLeft &= ~GetBitboard(i);
	}

	Bitboard takeRight = (board.BitBoard[ChessPiece::WhitePawn] << 9) & ~BitboardConstants::Files[0] & board.BlackPieces;
	while (takeRight != 0)
	{
		const Position i = BitScanForward(takeRight);
		if (i > 55)
		{
			GeneratePromotionMoves(i - 9, i, board.ArrayBoard[i], true, moves, moveCount);
		}
		else
		{
			const auto move = Move(i - 9, i, ChessPiece::WhitePawn, board.ArrayBoard[i]);
			moves[moveCount++] = move;
		}
		takeRight &= ~GetBitboard(i);
	}

	Bitboard enPassantLeft = (board.BitBoard[ChessPiece::WhitePawn] << 7) & ~BitboardConstants::Files[7] & board.EnPassantFile & BitboardConstants::Ranks[5] & board.BitBoard[ChessPiece::BlackPawn] << 8;
	while (enPassantLeft != 0)
	{
		const Position i = BitScanForward(enPassantLeft);
		const auto move = Move(i - 7, i, ChessPiece::WhitePawn, board.ArrayBoard[i - 8], true);
		moves[moveCount++] = move;
		enPassantLeft &= ~GetBitboard(i);
	}


	Bitboard enPassantRight = (board.BitBoard[ChessPiece::WhitePawn] << 9) & ~BitboardConstants::Files[0] & board.EnPassantFile & BitboardConstants::Ranks[5] & board.BitBoard[ChessPiece::BlackPawn] << 8;
	while (enPassantRight != 0)
	{
		const Position i = BitScanForward(enPassantRight);
		const auto move = Move(i - 9, i, ChessPiece::WhitePawn, board.ArrayBoard[i - 8], true);
		moves[moveCount++] = move;
		enPassantRight &= ~GetBitboard(i);
	}
}

void GetPotentialWhitePawnMoves(const Board& board, MoveArray& moves, size_t& moveCount)
{
	Bitboard moveOne = (board.BitBoard[ChessPiece::WhitePawn] << 8) & board.EmptySquares;
	while (moveOne != 0)
	{
		const Position i = BitScanForward(moveOne);
		if (i > 55)
		{
			GeneratePromotionMoves(i - 8, i, ChessPiece::Empty, true, moves, moveCount);
		}
		else
		{
			const auto move = Move(i - 8, i, ChessPiece::WhitePawn);
			moves[moveCount++] = move;
		}
		moveOne &= ~GetBitboard(i);
	}

	Bitboard moveTwo = (board.BitBoard[ChessPiece::WhitePawn] << 16) & board.EmptySquares & board.EmptySquares << 8 & BitboardConstants::Ranks[3];
	while (moveTwo != 0)
	{
		const Position i = BitScanForward(moveTwo);
		const auto move = Move(i - 16, i, ChessPiece::WhitePawn);
		moves[moveCount++] = move;
		moveTwo &= ~GetBitboard(i);
	}
}

void GetPotentialBlackPawnCaptures(const Board& board, MoveArray& moves, size_t& moveCount)
{
	Bitboard takeLeft = (board.BitBoard[ChessPiece::BlackPawn] >> 7) & ~BitboardConstants::Files[0] & board.WhitePieces;
	while (takeLeft != 0)
	{
		const Position i = BitScanForward(takeLeft);
		if (i < 8)
		{
			GeneratePromotionMoves(i + 7, i, board.ArrayBoard[i], false, moves, moveCount);
		}
		else
		{
			const auto move = Move(i + 7, i, ChessPiece::BlackPawn, board.ArrayBoard[i]);
			moves[moveCount++] = move;
		}
		takeLeft &= ~GetBitboard(i);
	}

	Bitboard takeRight = (board.BitBoard[ChessPiece::BlackPawn] >> 9) & ~BitboardConstants::Files[7] & board.WhitePieces;
	while (takeRight != 0)
	{
		const Position i = BitScanForward(takeRight);
		if (i < 8)
		{
			GeneratePromotionMoves(i + 9, i, board.ArrayBoard[i], false, moves, moveCount);
		}
		else
		{
			const auto move = Move(i + 9, i, ChessPiece::BlackPawn, board.ArrayBoard[i]);
			moves[moveCount++] = move;
		}
		takeRight &= ~GetBitboard(i);
	}

	Bitboard enPassantLeft = (board.BitBoard[ChessPiece::BlackPawn] >> 7) & ~BitboardConstants::Files[0] & board.EnPassantFile & BitboardConstants::Ranks[2] & board.BitBoard[ChessPiece::WhitePawn] >> 8;
	while (enPassantLeft != 0)
	{
		const Position i = BitScanForward(enPassantLeft);
		const auto move = Move(i + 7, i, ChessPiece::BlackPawn, board.ArrayBoard[i + 8], true);
		moves[moveCount++] = move;
		enPassantLeft &= ~GetBitboard(i);
	}


	Bitboard enPassantRight = (board.BitBoard[ChessPiece::BlackPawn] >> 9) & ~BitboardConstants::Files[7] & board.EnPassantFile & BitboardConstants::Ranks[2] & board.BitBoard[ChessPiece::WhitePawn] >> 8;
	while (enPassantRight != 0)
	{
		const Position i = BitScanForward(enPassantRight);
		const auto move = Move(i + 9, i, ChessPiece::BlackPawn, board.ArrayBoard[i + 8], true);
		moves[moveCount++] = move;
		enPassantRight &= ~GetBitboard(i);
	}
}

void GetPotentialBlackPawnMoves(const Board& board, MoveArray& moves, size_t& moveCount)
{
	Bitboard moveOne = (board.BitBoard[ChessPiece::BlackPawn] >> 8) & board.EmptySquares;
	while (moveOne != 0)
	{
		const Position i = BitScanForward(moveOne);
		if (i < 8)
		{
			GeneratePromotionMoves(i + 8, i, board.ArrayBoard[i], false, moves, moveCount);
		}
		else
		{
			const auto move = Move(i + 8, i, ChessPiece::BlackPawn);
			moves[moveCount++] = move;
		}
		moveOne &= ~GetBitboard(i);
	}

	Bitboard moveTwo = (board.BitBoard[ChessPiece::BlackPawn] >> 16) & board.EmptySquares & board.EmptySquares >> 8 & BitboardConstants::Ranks[4];
	while (moveTwo != 0)
	{
		const Position i = BitScanForward(moveTwo);
		const auto move = Move(i + 16, i, ChessPiece::BlackPawn);
		moves[moveCount++] = move;
		moveTwo &= ~GetBitboard(i);
	}
}

void BitmaskToMoves
(
	const Board& board,
	Bitboard bitmask,
	const Position positionFrom,
	const Piece piece,
	MoveArray& moves,
	size_t& moveCount
)
{
	while (bitmask != 0)
	{
		const auto i = BitScanForward(bitmask);
		const auto move = Move(positionFrom, i, piece, board.ArrayBoard[i]);
		moves[moveCount++] = move;
		bitmask &= ~GetBitboard(i);
	}
}

void GetPotentialJumpingMoves
(
	const Board& board,
	const Bitboard allowedSquareMask,
	Bitboard jumpingPieces,
	const Bitboard jumpMask,
	const Position jumpMaskCenter,
	const Piece piece,
	MoveArray& moves,
	size_t& moveCount
)
{
	const Bitboard ownPieces = board.WhiteToMove ? board.WhitePieces : board.BlackPieces;
	while (jumpingPieces != 0)
	{
		const Position i = BitScanForward(jumpingPieces);
		Bitboard jumps;
		if (i > jumpMaskCenter)
		{
			jumps = jumpMask << (i - jumpMaskCenter);
		}
		else
		{
			jumps = jumpMask >> (jumpMaskCenter - i);
		}

		jumps &= ~(i % 8 < 4 ? BitboardConstants::Files[6] | BitboardConstants::Files[7] : BitboardConstants::Files[0] | BitboardConstants::Files[1]);
		jumps &= ~ownPieces;
		jumps &= allowedSquareMask;

		BitmaskToMoves(board, jumps, i, piece, moves, moveCount);

		jumpingPieces &= ~GetBitboard(i);
	}
}

void GetPotentialKnightMoves(const Board& board, Bitboard allowedSquareMask, MoveArray& moves, size_t& moveCount)
{
	const Bitboard knights = board.WhiteToMove ? board.BitBoard[ChessPiece::WhiteKnight] : board.BitBoard[ChessPiece::BlackKnight];
	const Piece chessPiece = board.WhiteToMove ? ChessPiece::WhiteKnight : ChessPiece::BlackKnight;
	GetPotentialJumpingMoves(board, allowedSquareMask, knights, BitboardConstants::KnightSpan, BitboardConstants::KnightSpanPosition, chessPiece, moves, moveCount);
}

void GetPotentialKingCaptures(const Board& board, Bitboard allowedSquareMask, MoveArray& moves, size_t& moveCount)
{
	const Bitboard kings = board.WhiteToMove ? board.BitBoard[ChessPiece::WhiteKing] : board.BitBoard[ChessPiece::BlackKing];
	const Piece chessPiece = board.WhiteToMove ? ChessPiece::WhiteKing : ChessPiece::BlackKing;
	GetPotentialJumpingMoves(board, allowedSquareMask, kings, BitboardConstants::KingSpan, BitboardConstants::KingSpanPosition, chessPiece, moves, moveCount);
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

void GetPotentialKingMoves(const Board& board, Bitboard allowedSquareMask, MoveArray& moves, size_t& moveCount)
{
	const Bitboard kings = board.WhiteToMove ? board.BitBoard[ChessPiece::WhiteKing] : board.BitBoard[ChessPiece::BlackKing];
	const Piece chessPiece = board.WhiteToMove ? ChessPiece::WhiteKing : ChessPiece::BlackKing;
	GetPotentialJumpingMoves(board, allowedSquareMask, kings, BitboardConstants::KingSpan, BitboardConstants::KingSpanPosition, chessPiece, moves, moveCount);
	GetPotentialCastlingMoves(board, moves, moveCount);
}

void GetPotentialSlidingPieceMoves
(
	const Board& board,
	Bitboard slidingPieces,
	Piece piece,
	Bitboard allowedSquareMask,
	MoveArray& moves,
	size_t& moveCount
)
{
	const Bitboard ownPieces = board.WhiteToMove ? board.WhitePieces : board.BlackPieces;
	while (slidingPieces != 0)
	{
		const Position i = BitScanForward(slidingPieces);
		//var slide = slideResolutionFunc.Invoke(board.AllPieces, i);
		Bitboard slide;
		switch (piece)
		{
		case ChessPiece::WhiteRook:
		case ChessPiece::BlackRook:
			slide = SlideMoveGenerator::HorizontalVerticalSlide(board.AllPieces, i);
			break;
		case ChessPiece::WhiteBishop:
		case ChessPiece::BlackBishop:
			slide = SlideMoveGenerator::DiagonalAntidiagonalSlide(board.AllPieces, i);
			break;
		case ChessPiece::WhiteQueen:
		case ChessPiece::BlackQueen:
			slide = SlideMoveGenerator::AllSlide(board.AllPieces, i);
			break;
		default:
			throw std::exception("Attempted to generate slide attacks for a non-sliding piece");
		}
		slide &= ~ownPieces;
		slide &= allowedSquareMask;
		BitmaskToMoves(board, slide, i, piece, moves, moveCount);
		slidingPieces &= ~GetBitboard(i);
	}
}

void GetPotentialRookMoves(const Board& board, const Bitboard allowedSquareMask, MoveArray& moves, size_t& moveCount)
{
	const Bitboard rooks = board.WhiteToMove ? board.BitBoard[ChessPiece::WhiteRook] : board.BitBoard[ChessPiece::BlackRook];
	const Piece chessPiece = board.WhiteToMove ? ChessPiece::WhiteRook : ChessPiece::BlackRook;
	GetPotentialSlidingPieceMoves(board, rooks, chessPiece, allowedSquareMask, moves, moveCount);
}

void GetPotentialBishopMoves(const Board& board, const Bitboard allowedSquareMask, MoveArray& moves, size_t& moveCount)
{
	const Bitboard bishops = board.WhiteToMove ? board.BitBoard[ChessPiece::WhiteBishop] : board.BitBoard[ChessPiece::BlackBishop];
	const Piece chessPiece = board.WhiteToMove ? ChessPiece::WhiteBishop : ChessPiece::BlackBishop;
	GetPotentialSlidingPieceMoves(board, bishops, chessPiece, allowedSquareMask, moves, moveCount);
}

void GetPotentialQueenMoves(const Board& board, const Bitboard allowedSquareMask, MoveArray& moves, size_t& moveCount)
{
	const Bitboard bishops = board.WhiteToMove ? board.BitBoard[ChessPiece::WhiteQueen] : board.BitBoard[ChessPiece::BlackQueen];
	const Piece chessPiece = board.WhiteToMove ? ChessPiece::WhiteQueen : ChessPiece::BlackQueen;
	GetPotentialSlidingPieceMoves(board, bishops, chessPiece, allowedSquareMask, moves, moveCount);
}

void MoveGenerator::GetAllPotentialMoves(const Board& board, MoveArray& moves, size_t& moveCount)
{
	constexpr Bitboard allowedSquareMask = ~0ULL;
	moveCount = 0;
	
	if (board.WhiteToMove)
	{
		GetPotentialWhitePawnCaptures(board, moves, moveCount);
		GetPotentialWhitePawnMoves(board, moves, moveCount);
	}
	else
	{
		GetPotentialBlackPawnCaptures(board, moves, moveCount);
		GetPotentialBlackPawnMoves(board, moves, moveCount);
	}

	GetPotentialKnightMoves(board, allowedSquareMask, moves, moveCount);
	GetPotentialBishopMoves(board, allowedSquareMask, moves, moveCount);
	GetPotentialRookMoves(board, allowedSquareMask, moves, moveCount);
	GetPotentialQueenMoves(board, allowedSquareMask, moves, moveCount);
	GetPotentialKingMoves(board, allowedSquareMask, moves, moveCount);
}

void MoveGenerator::GetAllPotentialCaptures(const Board& board, MoveArray& moves, size_t& moveCount)
{
	const Bitboard allowedSquareMask = board.WhiteToMove ? board.BlackPieces : board.WhitePieces;

	if (board.WhiteToMove)
	{
		GetPotentialWhitePawnCaptures(board, moves, moveCount);
	}
	else
	{
		GetPotentialBlackPawnCaptures(board, moves, moveCount);
	}

	GetPotentialKnightMoves(board, allowedSquareMask, moves, moveCount);
	GetPotentialBishopMoves(board, allowedSquareMask, moves, moveCount);
	GetPotentialRookMoves(board, allowedSquareMask, moves, moveCount);
	GetPotentialQueenMoves(board, allowedSquareMask, moves, moveCount);
	GetPotentialKingCaptures(board, allowedSquareMask, moves, moveCount);
}

bool MoveGenerator::IsKingSafeAfterMove(const Board board, const Move move)
{
	Bitboard allPieces = board.AllPieces;
	const Bitboard inverseFromBitboard = ~GetBitboard(move.GetFrom());
	const Bitboard toBitboard = GetBitboard(move.GetTo());
	allPieces &= inverseFromBitboard;
	allPieces |= toBitboard;
	if (move.GetEnPassant())
	{
		const Bitboard enPassantedBitboard = board.WhiteToMove ? toBitboard >> 8 : toBitboard << 8;
		allPieces &= ~enPassantedBitboard;
	}
	
	const auto enemyAttackedAfterMove = AttacksGenerator::GetAllAttacked(board, !board.WhiteToMove, allPieces, ~toBitboard);

	auto myKings = board.WhiteToMove ? board.BitBoard[ChessPiece::WhiteKing] : board.BitBoard[ChessPiece::BlackKing];
	if ((board.WhiteToMove && move.GetPiece() == ChessPiece::WhiteKing) || (!board.WhiteToMove && move.GetPiece() == ChessPiece::BlackKing))
	{
		myKings &= inverseFromBitboard;
		myKings |= toBitboard;
	}

	const bool isSafe = (enemyAttackedAfterMove & myKings) == 0;
	return isSafe;
}

void MoveGenerator::FilterMovesByKingSafety(const Board& board, MoveArray& moves, size_t& moveCount)
{
	size_t toRemove = 0;
	for (size_t i = 0; i < moveCount; i++)
	{
		auto move = moves[i];
		bool safe = IsKingSafeAfterMove(board, move);
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

void MoveGenerator::GetAllPossibleMoves(const Board& board, MoveArray& moves, size_t& moveCount)
{
	GetAllPotentialMoves(board, moves, moveCount);
	FilterMovesByKingSafety(board, moves, moveCount);
}