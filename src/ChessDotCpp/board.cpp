#include "board.h"

#include "zobrist.h"

void Board::SyncExtraBitBoards()
{
	BitBoard[ChessPiece::White] = BitBoard[ChessPiece::WhitePawn]
		| BitBoard[ChessPiece::WhiteKnight]
		| BitBoard[ChessPiece::WhiteBishop]
		| BitBoard[ChessPiece::WhiteRook]
		| BitBoard[ChessPiece::WhiteQueen]
		| BitBoard[ChessPiece::WhiteKing];

	BitBoard[ChessPiece::Black] = BitBoard[ChessPiece::BlackPawn]
		| BitBoard[ChessPiece::BlackKnight]
		| BitBoard[ChessPiece::BlackBishop]
		| BitBoard[ChessPiece::BlackRook]
		| BitBoard[ChessPiece::BlackQueen]
		| BitBoard[ChessPiece::BlackKing];

	AllPieces = BitBoard[ChessPiece::White] | BitBoard[ChessPiece::Black];
	EmptySquares = ~AllPieces;
}

void Board::DoMove(const Move move)
{
	History[HistoryDepth].Move = move;
	History[HistoryDepth].Key = Key;
	History[HistoryDepth].CastlingPermission = CastlingPermissions;
	History[HistoryDepth].EnPassantFileIndex = EnPassantFileIndex;
	History[HistoryDepth].EnPassantRankIndex = EnPassantRankIndex;
	History[HistoryDepth].FiftyMoveRule = LastTookPieceHistoryIndex;
	HistoryDepth++;

	const auto originalWhiteToMove = WhiteToMove;
	const auto originalColorToMove = ColorToMove;

	WhiteToMove = !originalWhiteToMove;
	ColorToMove = ColorToMove ^ 1;
	Key ^= ZobristKeys.ZWhiteToMove;

	if (EnPassantFile != 0)
	{
		Key ^= ZobristKeys.ZEnPassant[EnPassantFileIndex];

		EnPassantFile = 0;
		EnPassantFileIndex = -1;
		EnPassantRankIndex = -1;
	}

	if (move.GetNullMove())
	{
		SyncExtraBitBoards();
		// TODO check
		return;
	}


	const Position from = move.GetFrom();
	const Position to = move.GetTo();
	const Position piece = move.GetPiece();
	
	// FROM
	const Bitboard fromPosBitBoard = GetBitboard(from);
	ArrayBoard[from] = ChessPiece::Empty;
	BitBoard[piece] &= ~fromPosBitBoard;
	Key ^= ZobristKeys.ZPieces[from][piece];

	Piece promotedPiece;
	if (move.GetPawnPromoteTo() != ChessPiece::Empty)
	{
		promotedPiece = move.GetPawnPromoteTo();
		PieceCounts[piece]--;
		PieceCounts[promotedPiece]++;
		if (originalWhiteToMove)
		{
			WhiteMaterial -= EvaluationConstants::Weights[ChessPiece::WhitePawn];
			WhiteMaterial += EvaluationConstants::Weights[promotedPiece];
		}
		else
		{
			BlackMaterial -= EvaluationConstants::Weights[ChessPiece::BlackPawn];
			BlackMaterial += EvaluationConstants::Weights[promotedPiece];
		}
	}
	else
	{
		promotedPiece = piece;
	}
		
	// TO
	Bitboard toPosBitBoard = GetBitboard(to);
	ArrayBoard[to] = promotedPiece;
	BitBoard[promotedPiece] |= toPosBitBoard;
	Key ^= ZobristKeys.ZPieces[to][promotedPiece];

	// TAKES
	if (move.GetTakesPiece() > 0)
	{
		if (!move.GetEnPassant())
		{
			auto takesPiece = move.GetTakesPiece();
			BitBoard[takesPiece] &= ~toPosBitBoard;
			Key ^= ZobristKeys.ZPieces[to][move.GetTakesPiece()];
		}
		LastTookPieceHistoryIndex = HistoryDepth - 1;
		PieceCounts[move.GetTakesPiece()]--;
		if (originalWhiteToMove)
		{
			BlackMaterial -= EvaluationConstants::Weights[move.GetTakesPiece()];
		}
		else
		{
			WhiteMaterial -= EvaluationConstants::Weights[move.GetTakesPiece()];
		}
	}
	
	// KING POS
	if (piece == (ChessPiece::King | originalColorToMove))
	{
		KingPositions[originalColorToMove] = to;
	}

	// EN PASSANT
	if (move.GetEnPassant())
	{
		int killedPawnPos;
		if (originalWhiteToMove) // TODO: whitetomove
		{
			killedPawnPos = to - 8;
		}
		else
		{
			killedPawnPos = to + 8;
		}

		Bitboard killedPawnBitBoard = GetBitboard(killedPawnPos);

		BitBoard[move.GetTakesPiece()] &= ~killedPawnBitBoard;
		ArrayBoard[killedPawnPos] = ChessPiece::Empty;
		Key ^= ZobristKeys.ZPieces[killedPawnPos][move.GetTakesPiece()];
	}

	// PAWN DOUBLE MOVES
	if ((piece == ChessPiece::WhitePawn && from + 16 == to) || (piece == ChessPiece::BlackPawn && from - 16 == to))
	{
		File fileIndex = from % 8;
		Rank rankIndex = (to >> 3) + (originalWhiteToMove ? -1 : 1);
		EnPassantFile = BitboardConstants::Files[fileIndex];
		EnPassantFileIndex = fileIndex;
		EnPassantRankIndex = rankIndex;
		Key ^= ZobristKeys.ZEnPassant[fileIndex];
	}
	else
	{
		EnPassantFile = 0;
		EnPassantFileIndex = -1;
		EnPassantRankIndex = -1;
	}

	// CASTLING
	if (move.GetCastle())
	{
		auto kingSide = to % 8 > 3;
		Position castlingRookPos = (kingSide ? 7 : 0) + (originalWhiteToMove ? 0 : 56);
		Position castlingRookNewPos = (from + to) / 2;
		Piece rookPiece = originalWhiteToMove ? ChessPiece::WhiteRook : ChessPiece::BlackRook;

		ArrayBoard[castlingRookPos] = ChessPiece::Empty;
		ArrayBoard[castlingRookNewPos] = rookPiece;
		BitBoard[rookPiece] &= ~GetBitboard(castlingRookPos);
		BitBoard[rookPiece] |= GetBitboard(castlingRookNewPos);
		Key ^= ZobristKeys.ZPieces[castlingRookPos][rookPiece];
		Key ^= ZobristKeys.ZPieces[castlingRookNewPos][rookPiece];
	}

	const CastlingPermission originalPermissions = CastlingPermissions;
	CastlingPermissions &= CastleRevocation.Table[from];
	CastlingPermissions &= CastleRevocation.Table[to];
	const CastlingPermission revoked = CastlingPermissions ^ originalPermissions;
	Key ^= ZobristKeys.ZCastle[revoked];
	
	//SyncCastleTo1();
	SyncExtraBitBoards();
}

void Board::UndoMove()
{
	auto& history = History[HistoryDepth - 1];
	auto move = history.Move;
	HistoryDepth--;

	EnPassantFileIndex = history.EnPassantFileIndex;
	EnPassantRankIndex = history.EnPassantRankIndex;
	EnPassantFile = EnPassantFileIndex >= 0 ? BitboardConstants::Files[history.EnPassantFileIndex] : 0;
	CastlingPermissions = history.CastlingPermission;
	Key = history.Key;
	LastTookPieceHistoryIndex = history.FiftyMoveRule;

	//var whiteToMove = WhiteToMove;
	WhiteToMove = !WhiteToMove;
	ColorToMove = ColorToMove ^ 1;


	if (move.GetNullMove())
	{
		SyncExtraBitBoards();
		// TODO check
		return;
	}

	const Position from = move.GetFrom();
	const Position to = move.GetTo();
	const Piece piece = move.GetPiece();
	
	// FROM
	Bitboard fromPosBitBoard = GetBitboard(from);
	
	//Piece promotedPiece = move.PawnPromoteTo.HasValue ? move.PawnPromoteTo.Value : move.Piece;
	ArrayBoard[from] = piece;
	BitBoard[piece] |= fromPosBitBoard;

	Piece promotedPiece;
	if (move.GetPawnPromoteTo() != ChessPiece::Empty)
	{
		promotedPiece = move.GetPawnPromoteTo();
		PieceCounts[piece]++;
		PieceCounts[promotedPiece]--;
		if (WhiteToMove)
		{
			WhiteMaterial += EvaluationConstants::Weights[ChessPiece::WhitePawn];
			WhiteMaterial -= EvaluationConstants::Weights[promotedPiece];
		}
		else
		{
			BlackMaterial += EvaluationConstants::Weights[ChessPiece::BlackPawn];
			BlackMaterial -= EvaluationConstants::Weights[promotedPiece];
		}
	}
	else
	{
		promotedPiece = piece;
	}

	
	// TO
	Bitboard toPosBitBoard = GetBitboard(to);
	BitBoard[promotedPiece] &= ~toPosBitBoard;
	if (move.GetEnPassant())
	{
		ArrayBoard[to] = ChessPiece::Empty;
	}
	else
	{
		ArrayBoard[to] = move.GetTakesPiece();
	}

	// KING POS
	if (piece == ChessPiece::King + ColorToMove)
	{
		KingPositions[ColorToMove] = from;
	}
	
	// TAKES
	if (move.GetTakesPiece() > 0)
	{
		if (!move.GetEnPassant())
		{
			BitBoard[move.GetTakesPiece()] |= toPosBitBoard;
		}
		PieceCounts[move.GetTakesPiece()]++;
		if (WhiteToMove)
		{
			BlackMaterial += EvaluationConstants::Weights[move.GetTakesPiece()];
		}
		else
		{
			WhiteMaterial += EvaluationConstants::Weights[move.GetTakesPiece()];
		}
	}

	// EN PASSANT
	if (move.GetEnPassant())
	{
		Position killedPawnPos;
		if (WhiteToMove)
		{
			killedPawnPos = to - 8;
		}
		else
		{
			killedPawnPos = to + 8;
		}

		Bitboard killedPawnBitBoard = GetBitboard(killedPawnPos);

		BitBoard[move.GetTakesPiece()] |= killedPawnBitBoard;
		ArrayBoard[killedPawnPos] = move.GetTakesPiece();

		//BitBoard[move.TakesPiece] &= ~killedPawnBitBoard;
		//ArrayBoard[killedPawnPos] = ChessPiece.Empty;
		//Key ^= ZobristKeys.ZPieces[killedPawnPos, move.TakesPiece];
	}

	if (move.GetCastle())
	{
		auto kingSide = to % 8 > 3;
		auto castlingRookPos = (kingSide ? 7 : 0) + (WhiteToMove ? 0 : 56);
		auto castlingRookNewPos = (from + to) / 2;
		auto rookPiece = WhiteToMove ? ChessPiece::WhiteRook : ChessPiece::BlackRook;

		ArrayBoard[castlingRookPos] = rookPiece;
		ArrayBoard[castlingRookNewPos] = ChessPiece::Empty;
		BitBoard[rookPiece] |= GetBitboard(castlingRookPos);
		BitBoard[rookPiece] &= ~GetBitboard(castlingRookNewPos);
	}

	//SyncCastleTo1();
	SyncExtraBitBoards();
}

Move Board::FromPositionString(const MoveString& moveString) const
{
	const Position from = Move::TextToPosition(moveString.substr(0, 2));
	const Position to = Move::TextToPosition(moveString.substr(2, 2));
	const Piece piece = ArrayBoard[from];
	Piece takesPiece = ArrayBoard[to];
	bool enPassant = false;
	Piece pawnPromotesTo = ChessPiece::Empty;
	if (piece == ChessPiece::WhitePawn || piece == ChessPiece::BlackPawn)
	{
		if (from % 8 != to % 8) // Must be take
		{
			if (takesPiece == ChessPiece::Empty) // Must be en-passant
			{
				takesPiece = static_cast<Piece>(ChessPiece::Pawn + (ColorToMove ^ 1));
				enPassant = true;
			}
		}
	}

	if (moveString.length() == 5)
	{
		switch (moveString[4])
		{
		case 'q':
		case 'Q':
			pawnPromotesTo = static_cast<Piece>(ChessPiece::Queen + ColorToMove);
			break;
		case 'n':
		case 'N':
			pawnPromotesTo = static_cast<Piece>(ChessPiece::Knight + ColorToMove);
			break;
		case 'b':
		case 'B':
			pawnPromotesTo = static_cast<Piece>(ChessPiece::Bishop + ColorToMove);
			break;
		case 'r':
		case 'R':
			pawnPromotesTo = static_cast<Piece>(ChessPiece::Rook + ColorToMove);
			break;
		default: throw std::exception("Unknown promotion");
		}
	}

	const bool castle = (piece == ChessPiece::WhiteKing || piece == ChessPiece::BlackKing) && std::abs(from - to) == 2;
	
	const Move move = Move(from, to, piece, takesPiece, enPassant, castle, pawnPromotesTo);
	return move;
}

void Board::DoMove(const MoveString& moveString)
{
	const Move move = FromPositionString(moveString);
	DoMove(move);
}
