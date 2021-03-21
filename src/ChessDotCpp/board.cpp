#include "board.h"

#include "common.h"
#include "zobrist.h"

constexpr std::array<CastlingPermission, 64> Board::GenerateRevocationTable()
{
	std::array<CastlingPermission, 64> table {};
	for (Position i = 0; i < 64; i++)
	{
		CastlingPermission permission = ChessCastlingPermissions::All;
		switch (i)
		{
		case 0:
			permission &= ~ChessCastlingPermissions::WhiteQueen;
			break;
		case 4:
			permission &= ~ChessCastlingPermissions::WhiteQueen;
			permission &= ~ChessCastlingPermissions::WhiteKing;
			break;
		case 7:
			permission &= ~ChessCastlingPermissions::WhiteKing;
			break;
		case 56:
			permission &= ~ChessCastlingPermissions::BlackQueen;
			break;
		case 60:
			permission &= ~ChessCastlingPermissions::BlackQueen;
			permission &= ~ChessCastlingPermissions::BlackKing;
			break;
		case 63:
			permission &= ~ChessCastlingPermissions::BlackKing;
			break;
		default:
			break;
		}

		table[i] = permission;
	}

	return table;
}

void Board::SyncExtraBitBoards()
{
	WhitePieces = BitBoard[ChessPiece::WhitePawn]
		| BitBoard[ChessPiece::WhiteKnight]
		| BitBoard[ChessPiece::WhiteBishop]
		| BitBoard[ChessPiece::WhiteRook]
		| BitBoard[ChessPiece::WhiteQueen]
		| BitBoard[ChessPiece::WhiteKing];

	BlackPieces = BitBoard[ChessPiece::BlackPawn]
		| BitBoard[ChessPiece::BlackKnight]
		| BitBoard[ChessPiece::BlackBishop]
		| BitBoard[ChessPiece::BlackRook]
		| BitBoard[ChessPiece::BlackQueen]
		| BitBoard[ChessPiece::BlackKing];

	AllPieces = WhitePieces | BlackPieces;
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

	const auto whiteToMove = WhiteToMove;

	WhiteToMove = !whiteToMove;
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


	// FROM
	const Bitboard fromPosBitBoard = GetBitboard(move.GetFrom());
	ArrayBoard[move.GetFrom()] = ChessPiece::Empty;
	BitBoard[move.GetPiece()] &= ~fromPosBitBoard;
	Key ^= ZobristKeys.ZPieces[move.GetFrom()][move.GetPiece()];

	Piece promotedPiece;
	if (move.GetPawnPromoteTo() != ChessPiece::Empty)
	{
		promotedPiece = move.GetPawnPromoteTo();
		PieceCounts[move.GetPiece()]--;
		PieceCounts[promotedPiece]++;
		if (whiteToMove)
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
		promotedPiece = move.GetPiece();
	}


	// TO
	Bitboard toPosBitBoard = GetBitboard(move.GetTo());
	ArrayBoard[move.GetTo()] = promotedPiece;
	BitBoard[promotedPiece] |= toPosBitBoard;
	Key ^= ZobristKeys.ZPieces[move.GetTo()][promotedPiece];

	// TAKES
	if (move.GetTakesPiece() > 0)
	{
		if (!move.GetEnPassant())
		{
			auto takesPiece = move.GetTakesPiece();
			BitBoard[takesPiece] &= ~toPosBitBoard;
			Key ^= ZobristKeys.ZPieces[move.GetTo()][move.GetTakesPiece()];
		}
		LastTookPieceHistoryIndex = HistoryDepth - 1;
		PieceCounts[move.GetTakesPiece()]--;
		if (whiteToMove)
		{
			BlackMaterial -= EvaluationConstants::Weights[move.GetTakesPiece()];
		}
		else
		{
			WhiteMaterial -= EvaluationConstants::Weights[move.GetTakesPiece()];
		}
	}

	// EN PASSANT
	if (move.GetEnPassant())
	{
		int killedPawnPos;
		if (whiteToMove) // TODO: whitetomove
		{
			killedPawnPos = move.GetTo() - 8;
		}
		else
		{
			killedPawnPos = move.GetTo() + 8;
		}

		Bitboard killedPawnBitBoard = GetBitboard(killedPawnPos);

		BitBoard[move.GetTakesPiece()] &= ~killedPawnBitBoard;
		ArrayBoard[killedPawnPos] = ChessPiece::Empty;
		Key ^= ZobristKeys.ZPieces[killedPawnPos][move.GetTakesPiece()];
	}

	// PAWN DOUBLE MOVES
	if ((move.GetPiece() == ChessPiece::WhitePawn && move.GetFrom() + 16 == move.GetTo()) || (move.GetPiece() == ChessPiece::BlackPawn && move.GetFrom() - 16 == move.GetTo()))
	{
		File fileIndex = move.GetFrom() % 8;
		Rank rankIndex = (move.GetTo() >> 3) + (whiteToMove ? -1 : 1);
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
		auto kingSide = move.GetTo() % 8 > 3;
		Position castlingRookPos = (kingSide ? 7 : 0) + (whiteToMove ? 0 : 56);
		Position castlingRookNewPos = (move.GetFrom() + move.GetTo()) / 2;
		Piece rookPiece = whiteToMove ? ChessPiece::WhiteRook : ChessPiece::BlackRook;

		ArrayBoard[castlingRookPos] = ChessPiece::Empty;
		ArrayBoard[castlingRookNewPos] = rookPiece;
		BitBoard[rookPiece] &= ~GetBitboard(castlingRookPos);
		BitBoard[rookPiece] |= GetBitboard(castlingRookNewPos);
		Key ^= ZobristKeys.ZPieces[castlingRookPos][rookPiece];
		Key ^= ZobristKeys.ZPieces[castlingRookNewPos][rookPiece];
	}

	if (move.GetPiece() == ChessPiece::WhiteKing)
	{
		if ((CastlingPermissions & ChessCastlingPermissions::WhiteQueen) != ChessCastlingPermissions::None)
		{
			Key ^= ZobristKeys.ZCastle[ChessCastlingPermissions::WhiteQueen];
		}

		if ((CastlingPermissions & ChessCastlingPermissions::WhiteKing) != ChessCastlingPermissions::None)
		{
			Key ^= ZobristKeys.ZCastle[ChessCastlingPermissions::WhiteKing];
		}
	}
	else if (move.GetPiece() == ChessPiece::WhiteRook)
	{
		if ((CastlingPermissions & ChessCastlingPermissions::WhiteQueen) != ChessCastlingPermissions::None && move.GetFrom() == 0)
		{
			Key ^= ZobristKeys.ZCastle[ChessCastlingPermissions::WhiteQueen];
		}

		if ((CastlingPermissions & ChessCastlingPermissions::WhiteKing) != ChessCastlingPermissions::None && move.GetFrom() == 7)
		{
			Key ^= ZobristKeys.ZCastle[ChessCastlingPermissions::WhiteKing];
		}
	}
	else if (move.GetPiece() == ChessPiece::BlackKing)
	{
		if ((CastlingPermissions & ChessCastlingPermissions::BlackQueen) != ChessCastlingPermissions::None)
		{
			Key ^= ZobristKeys.ZCastle[ChessCastlingPermissions::BlackQueen];
		}

		if ((CastlingPermissions & ChessCastlingPermissions::BlackKing) != ChessCastlingPermissions::None)
		{
			Key ^= ZobristKeys.ZCastle[ChessCastlingPermissions::BlackKing];
		}
	}
	else if (move.GetPiece() == ChessPiece::BlackRook)
	{
		if ((CastlingPermissions & ChessCastlingPermissions::BlackQueen) != ChessCastlingPermissions::None && move.GetFrom() == 56)
		{
			Key ^= ZobristKeys.ZCastle[ChessCastlingPermissions::BlackQueen];
		}

		if ((CastlingPermissions & ChessCastlingPermissions::BlackKing) != ChessCastlingPermissions::None && move.GetFrom() == 63)
		{
			Key ^= ZobristKeys.ZCastle[ChessCastlingPermissions::BlackKing];
		}
	}

	switch (move.GetTo())
	{
	case 0:
		if ((CastlingPermissions & ChessCastlingPermissions::WhiteQueen) != ChessCastlingPermissions::None)
		{
			Key ^= ZobristKeys.ZCastle[ChessCastlingPermissions::WhiteQueen];
		}
		break;
	case 7:
		if ((CastlingPermissions & ChessCastlingPermissions::WhiteKing) != ChessCastlingPermissions::None)
		{
			Key ^= ZobristKeys.ZCastle[ChessCastlingPermissions::WhiteKing];
		}
		break;
	case 56:
		if ((CastlingPermissions & ChessCastlingPermissions::BlackQueen) != ChessCastlingPermissions::None)
		{
			Key ^= ZobristKeys.ZCastle[ChessCastlingPermissions::BlackQueen];
		}
		break;
	case 63:
		if ((CastlingPermissions & ChessCastlingPermissions::BlackKing) != ChessCastlingPermissions::None)
		{
			Key ^= ZobristKeys.ZCastle[ChessCastlingPermissions::BlackKing];
		}
		break;
	}

	CastlingPermissions &= CastleRevocationTable[move.GetFrom()];
	CastlingPermissions &= CastleRevocationTable[move.GetTo()];

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


	if (move.GetNullMove())
	{
		SyncExtraBitBoards();
		// TODO check
		return;
	}

	// FROM
	Bitboard fromPosBitBoard = GetBitboard(move.GetFrom());
	//Piece promotedPiece = move.PawnPromoteTo.HasValue ? move.PawnPromoteTo.Value : move.Piece;
	ArrayBoard[move.GetFrom()] = move.GetPiece();
	BitBoard[move.GetPiece()] |= fromPosBitBoard;

	Piece promotedPiece;
	if (move.GetPawnPromoteTo() != ChessPiece::Empty)
	{
		promotedPiece = move.GetPawnPromoteTo();
		PieceCounts[move.GetPiece()]++;
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
		promotedPiece = move.GetPiece();
	}

	// TO
	Bitboard toPosBitBoard = GetBitboard(move.GetTo());
	BitBoard[promotedPiece] &= ~toPosBitBoard;
	if (move.GetEnPassant())
	{
		ArrayBoard[move.GetTo()] = ChessPiece::Empty;
	}
	else
	{
		ArrayBoard[move.GetTo()] = move.GetTakesPiece();
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
		if (WhiteMaterial)
		{
			killedPawnPos = move.GetTo() - 8;
		}
		else
		{
			killedPawnPos = move.GetTo() + 8;
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
		auto kingSide = move.GetTo() % 8 > 3;
		auto castlingRookPos = (kingSide ? 7 : 0) + (WhiteToMove ? 0 : 56);
		auto castlingRookNewPos = (move.GetFrom() + move.GetTo()) / 2;
		auto rookPiece = WhiteToMove ? ChessPiece::WhiteRook : ChessPiece::BlackRook;

		ArrayBoard[castlingRookPos] = rookPiece;
		ArrayBoard[castlingRookNewPos] = ChessPiece::Empty;
		BitBoard[rookPiece] |= GetBitboard(castlingRookPos);
		BitBoard[rookPiece] &= ~GetBitboard(castlingRookNewPos);
	}

	//SyncCastleTo1();
	SyncExtraBitBoards();
}