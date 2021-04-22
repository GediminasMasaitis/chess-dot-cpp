#include "movegen.h"

#include "attacks.h"
#include "common.h"
#include "magics.h"

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

Bitboard PinDetector::GetPinned(const Board& board, Color color, Position pos)
{
	const Color opponentColor = static_cast<Color>(color ^ 1);
	Bitboard pinned = 0ULL;
	const Bitboard ownPieces = board.BitBoard[color];

	Bitboard xrays = DiagonalAntidiagonalXray(board.AllPieces, ownPieces, pos);
	Bitboard pinners = xrays & (board.BitBoard[Pieces::Bishop | opponentColor] | board.BitBoard[Pieces::Queen | opponentColor]);

	while (pinners != 0)
	{
		const Position pinner = BitScanForward(pinners);
		pinned |= BetweenBitboards.Between[pinner][pos] & ownPieces;
		pinners &= pinners - 1;
	}

	xrays = HorizontalVerticalXray(board.AllPieces, ownPieces, pos);
	pinners = xrays & (board.BitBoard[Pieces::Rook | opponentColor] | board.BitBoard[Pieces::Queen | opponentColor]);

	while (pinners != 0)
	{
		const Position pinner = BitScanForward(pinners);
		pinned |= BetweenBitboards.Between[pinner][pos] & ownPieces;
		pinners &= pinners - 1;
	}
	return pinned;
}

void PinDetector::GetPinnedToKings(const Board& board, EachColor<Bitboard>& pins)
{
	pins[Colors::White] = GetPinned(board, Colors::White, board.KingPositions[Colors::White]);
	pins[Colors::Black] = GetPinned(board, Colors::Black, board.KingPositions[Colors::Black]);
}

template<Piece TColor>
Bitboard GetPinnedForColor(const Board& board, Position pos)
{
	constexpr Piece color = TColor;
	constexpr Piece opponentColor = color ^ 1;
	constexpr Piece opponentBishop = Pieces::Bishop | opponentColor;
	constexpr Piece opponentRook = Pieces::Rook | opponentColor;
	constexpr Piece opponentQueen = Pieces::Queen | opponentColor;
	
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
	Bitboard pinners = xrays & (board.BitBoard[Pieces::Bishop | opponentColor] | board.BitBoard[Pieces::Queen | opponentColor]);

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
	pinners = xrays & (board.BitBoard[Pieces::Rook | opponentColor] | board.BitBoard[Pieces::Queen | opponentColor]);

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
	MoveCount& moveCount
)
{
	constexpr Piece color = TColor;
	constexpr Piece piece = Pieces::Pawn | color;
	constexpr Piece queen = Pieces::Queen | color;
	constexpr Piece knight = Pieces::Knight | color;
	constexpr Piece rook = Pieces::Rook | color;
	constexpr Piece bishop = Pieces::Bishop | color;
	
	moves[moveCount++] = Move(from, to, piece, takesPiece, false, false, queen);
	moves[moveCount++] = Move(from, to, piece, takesPiece, false, false, knight);
	moves[moveCount++] = Move(from, to, piece, takesPiece, false, false, rook);
	moves[moveCount++] = Move(from, to, piece, takesPiece, false, false, bishop);
}

void GetPotentialWhitePawnCaptures(const Board& board, Bitboard allowedFrom, Bitboard allowedTo, MoveArray& moves, MoveCount& moveCount)
{
	const Bitboard pawns = board.BitBoard[Pieces::WhitePawn] & allowedFrom;
	Bitboard takeLeft = (pawns << 7) & ~BitboardConstants::Files[7] & board.BitBoard[Colors::Black] & allowedTo;
	while (takeLeft != 0)
	{
		const Position i = BitScanForward(takeLeft);
		if (i > 55)
		{
			GeneratePromotionMoves<Colors::White>(i - 7, i, board.ArrayBoard[i], moves, moveCount);
		}
		else
		{
			const auto move = Move(i - 7, i, Pieces::WhitePawn, board.ArrayBoard[i]);
			moves[moveCount++] = move;
		}
		takeLeft &= takeLeft - 1;
	}

	Bitboard takeRight = (pawns << 9) & ~BitboardConstants::Files[0] & board.BitBoard[Colors::Black] & allowedTo;
	while (takeRight != 0)
	{
		const Position i = BitScanForward(takeRight);
		if (i > 55)
		{
			GeneratePromotionMoves<Colors::White>(i - 9, i, board.ArrayBoard[i], moves, moveCount);
		}
		else
		{
			const auto move = Move(i - 9, i, Pieces::WhitePawn, board.ArrayBoard[i]);
			moves[moveCount++] = move;
		}
		takeRight &= takeRight - 1;
	}

	Bitboard enPassantLeft = (pawns << 7) & ~BitboardConstants::Files[7] & board.EnPassantFile & BitboardConstants::Ranks[5] & board.BitBoard[Pieces::BlackPawn] << 8;
	while (enPassantLeft != 0)
	{
		const Position i = BitScanForward(enPassantLeft);
		const auto move = Move(i - 7, i, Pieces::WhitePawn, board.ArrayBoard[i - 8], true);
		moves[moveCount++] = move;
		enPassantLeft &= enPassantLeft - 1;
	}


	Bitboard enPassantRight = (pawns << 9) & ~BitboardConstants::Files[0] & board.EnPassantFile & BitboardConstants::Ranks[5] & board.BitBoard[Pieces::BlackPawn] << 8;
	while (enPassantRight != 0)
	{
		const Position i = BitScanForward(enPassantRight);
		const auto move = Move(i - 9, i, Pieces::WhitePawn, board.ArrayBoard[i - 8], true);
		moves[moveCount++] = move;
		enPassantRight &= enPassantRight - 1;
	}
}

template<Piece TColor>
void GetPotentialPawnMoves(const Board& board, Bitboard allowedFrom, Bitboard allowedTo, MoveArray& moves, MoveCount& moveCount)
{
	constexpr Piece color = TColor;
	constexpr bool isWhite = color == Colors::White;
	constexpr Piece piece = Pieces::Pawn | color;
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
		GeneratePromotionMoves<TColor>(from, position, Pieces::Empty, moves, moveCount);
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

void GetPotentialBlackPawnCaptures(const Board& board, Bitboard allowedFrom, Bitboard allowedTo, MoveArray& moves, MoveCount& moveCount)
{
	const Bitboard pawns = board.BitBoard[Pieces::BlackPawn] & allowedFrom;
	Bitboard takeLeft = (pawns >> 7) & ~BitboardConstants::Files[0] & board.BitBoard[Colors::White] & allowedTo;
	while (takeLeft != 0)
	{
		const Position i = BitScanForward(takeLeft);
		if (i < 8)
		{
			GeneratePromotionMoves<Colors::Black>(i + 7, i, board.ArrayBoard[i], moves, moveCount);
		}
		else
		{
			const auto move = Move(i + 7, i, Pieces::BlackPawn, board.ArrayBoard[i]);
			moves[moveCount++] = move;
		}
		takeLeft &= takeLeft - 1;
	}

	Bitboard takeRight = (pawns >> 9) & ~BitboardConstants::Files[7] & board.BitBoard[Colors::White] & allowedTo;
	while (takeRight != 0)
	{
		const Position i = BitScanForward(takeRight);
		if (i < 8)
		{
			GeneratePromotionMoves<Colors::Black>(i + 9, i, board.ArrayBoard[i], moves, moveCount);
		}
		else
		{
			const auto move = Move(i + 9, i, Pieces::BlackPawn, board.ArrayBoard[i]);
			moves[moveCount++] = move;
		}
		takeRight &= takeRight - 1;
	}

	Bitboard enPassantLeft = (pawns >> 7) & ~BitboardConstants::Files[0] & board.EnPassantFile & BitboardConstants::Ranks[2] & board.BitBoard[Pieces::WhitePawn] >> 8;
	while (enPassantLeft != 0)
	{
		const Position i = BitScanForward(enPassantLeft);
		const auto move = Move(i + 7, i, Pieces::BlackPawn, board.ArrayBoard[i + 8], true);
		moves[moveCount++] = move;
		enPassantLeft &= enPassantLeft - 1;
	}


	Bitboard enPassantRight = (pawns >> 9) & ~BitboardConstants::Files[7] & board.EnPassantFile & BitboardConstants::Ranks[2] & board.BitBoard[Pieces::WhitePawn] >> 8;
	while (enPassantRight != 0)
	{
		const Position i = BitScanForward(enPassantRight);
		const auto move = Move(i + 9, i, Pieces::BlackPawn, board.ArrayBoard[i + 8], true);
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
	MoveCount& moveCount
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
	MoveCount& moveCount
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
void GetPotentialKnightMoves(const Board& board, Bitboard allowedFrom, Bitboard allowedTo, MoveArray& moves, MoveCount& moveCount)
{
	constexpr Piece color = TColor;
	constexpr Piece piece = Pieces::Knight | color;
	const Bitboard knights = board.BitBoard[piece] & allowedFrom;
	GetPotentialJumpingMoves<piece>(board, allowedTo, knights, BitboardJumps.KnightJumps, moves, moveCount);
}

template<Piece TColor>
void GetPotentialKingMoves(const Board& board, const Bitboard allowedTo, MoveArray& moves, MoveCount& moveCount)
{
	constexpr Piece color = TColor;
	constexpr Piece piece = Pieces::King | color;
	const Bitboard kings = board.BitBoard[piece];
	GetPotentialJumpingMoves<piece>(board, allowedTo, kings, BitboardJumps.KingJumps, moves, moveCount);
}

void GetPotentialCastlingMoves(const Board& board, MoveArray& moves, MoveCount& moveCount)
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
		castlingPermissionQueenSide = (board.CastlingPermissions & CastlingPermissions::WhiteQueen) != CastlingPermissions::None;
		castlingPermissionKingSide = (board.CastlingPermissions & CastlingPermissions::WhiteKing) != CastlingPermissions::None;
		kingPos = BitScanForward(board.BitBoard[Pieces::WhiteKing]);
		queenSideCastleMask = BitboardConstants::WhiteQueenSideCastleMask;
		kingSideCastleMask = BitboardConstants::WhiteKingSideCastleMask;
		queenSideCastleAttackMask = BitboardConstants::WhiteQueenSideCastleAttackMask;
		kingSideCastleAttackMask = BitboardConstants::WhiteKingSideCastleAttackMask;
		piece = Pieces::WhiteKing;
	}
	else
	{
		castlingPermissionQueenSide = (board.CastlingPermissions & CastlingPermissions::BlackQueen) != CastlingPermissions::None;
		castlingPermissionKingSide = (board.CastlingPermissions & CastlingPermissions::BlackKing) != CastlingPermissions::None;
		kingPos = BitScanForward(board.BitBoard[Pieces::BlackKing]);
		queenSideCastleMask = BitboardConstants::BlackQueenSideCastleMask;
		kingSideCastleMask = BitboardConstants::BlackKingSideCastleMask;
		queenSideCastleAttackMask = BitboardConstants::BlackQueenSideCastleAttackMask;
		kingSideCastleAttackMask = BitboardConstants::BlackKingSideCastleAttackMask;
		piece = Pieces::BlackKing;
	}

	const bool canMaybeCastleQueenSide = castlingPermissionQueenSide && ((board.AllPieces & queenSideCastleMask) == 0);
	const bool canMaybeCastleKingSide = castlingPermissionKingSide && (board.AllPieces & kingSideCastleMask) == 0;

	if (canMaybeCastleQueenSide | canMaybeCastleKingSide)
	{
		const Bitboard attackedByEnemy = AttacksGenerator::GetAllAttacked(board, !board.WhiteToMove, board.AllPieces);
		if (canMaybeCastleQueenSide && ((attackedByEnemy & queenSideCastleAttackMask) == 0))
		{
			moves[moveCount++] = Move(kingPos, kingPos - 2, piece, Pieces::Empty, false, true);
		}
		if (canMaybeCastleKingSide && ((attackedByEnemy & kingSideCastleAttackMask) == 0))
		{
			moves[moveCount++] = Move(kingPos, kingPos + 2, piece, Pieces::Empty, false, true);
		}
	}
}

template<Piece TColor>
void GetPotentialRookMoves(const Board& board, const Bitboard allowedFrom, const Bitboard allowedTo, MoveArray& moves, MoveCount& moveCount)
{
	constexpr Piece color = TColor;
	constexpr Piece piece = Pieces::Rook | color;
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
void GetPotentialBishopMoves(const Board& board, const Bitboard allowedFrom, const Bitboard allowedTo, MoveArray& moves, MoveCount& moveCount)
{
	constexpr Piece color = TColor;
	constexpr Piece piece = Pieces::Bishop | color;
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
void GetPotentialQueenMoves(const Board& board, const Bitboard allowedFrom, const Bitboard allowedTo, MoveArray& moves, MoveCount& moveCount)
{
	constexpr Piece color = TColor;
	constexpr Piece piece = Pieces::Queen | color;
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
void GetAllPotentialMovesForColor(const Board& board, const Bitboard checkers, const Bitboard pinned, MoveArray& moves, MoveCount& moveCount)
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

	if constexpr (TColor == Colors::White)
	{
		GetPotentialWhitePawnCaptures(board, allowedFrom, allowedTo, moves, moveCount);
	}
	else
	{
		GetPotentialBlackPawnCaptures(board, allowedFrom, allowedTo, moves, moveCount);
	}
	
	GetPotentialPawnMoves<TColor>(board, allowedFrom, allowedTo, moves, moveCount);
}

void MoveGenerator::GetAllPotentialMoves(const Board& board, const Bitboard checkers, const Bitboard pinned, MoveArray& moves, MoveCount& moveCount)
{
	if (board.WhiteToMove)
	{
		GetAllPotentialMovesForColor<Colors::White>(board, checkers, pinned, moves, moveCount);
	}
	else
	{
		GetAllPotentialMovesForColor<Colors::Black>(board, checkers, pinned, moves, moveCount);
	}
}

template<Piece TColor>
void GetAllPotentialCapturesForColor(const Board& board, const Bitboard checkers, const Bitboard pinned, MoveArray& moves, MoveCount& moveCount)
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

	if constexpr (TColor == Colors::White)
	{
		GetPotentialWhitePawnCaptures(board, allowedFrom, allowedTo, moves, moveCount);
	}
	else
	{
		GetPotentialBlackPawnCaptures(board, allowedFrom, allowedTo, moves, moveCount);
	}
}

void MoveGenerator::GetAllPotentialCaptures(const Board& board, const Bitboard checkers, const Bitboard pinned, MoveArray& moves, MoveCount& moveCount)
{
	if (board.WhiteToMove)
	{
		GetAllPotentialCapturesForColor<Colors::White>(board, checkers, pinned, moves, moveCount);
	}
	else
	{
		GetAllPotentialCapturesForColor<Colors::Black>(board, checkers, pinned, moves, moveCount);
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
		
	const bool kingMove = piece == Pieces::WhiteKing || piece == Pieces::BlackKing;
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
		pawns = board.BitBoard[Pieces::BlackPawn] & invTakes;
		knights = board.BitBoard[Pieces::BlackKnight] & invTakes;
		bishops = board.BitBoard[Pieces::BlackBishop] & invTakes;
		rooks = board.BitBoard[Pieces::BlackRook] & invTakes;
		queens = board.BitBoard[Pieces::BlackQueen] & invTakes;
		kings = board.BitBoard[Pieces::BlackKing] & invTakes;
	}
	else
	{
		pawns = board.BitBoard[Pieces::WhitePawn] & invTakes;
		knights = board.BitBoard[Pieces::WhiteKnight] & invTakes;
		bishops = board.BitBoard[Pieces::WhiteBishop] & invTakes;
		rooks = board.BitBoard[Pieces::WhiteRook] & invTakes;
		queens = board.BitBoard[Pieces::WhiteQueen] & invTakes;
		kings = board.BitBoard[Pieces::WhiteKing] & invTakes;
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
	const bool kingMove = move.GetPiece() == Pieces::King + board.ColorToMove;
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

void MoveValidator::FilterMovesByKingSafety(const Board& board, Bitboard checkers, Bitboard pinnedPieces, MoveArray& moves, MoveCount& moveCount)
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

template<Piece TColor>
void GetAllPossibleMovesForColor(const Board& board, MoveArray& moves, MoveCount& moveCount)
{
	const Bitboard checkers = AttacksGenerator::GetCheckers(board);
	const Bitboard pinned = GetPinnedForColor<TColor>(board, board.KingPositions[board.ColorToMove]);
	GetAllPotentialMovesForColor<TColor>(board, checkers, pinned, moves, moveCount);
	MoveValidator::FilterMovesByKingSafety(board, checkers, pinned, moves, moveCount);
}

void MoveGenerator::GetAllPossibleMoves(const Board& board, MoveArray& moves, MoveCount& moveCount)
{
	if (board.WhiteToMove)
	{
		GetAllPossibleMovesForColor<Colors::White>(board, moves, moveCount);
	}
	else
	{
		GetAllPossibleMovesForColor<Colors::Black>(board, moves, moveCount);
	}
}