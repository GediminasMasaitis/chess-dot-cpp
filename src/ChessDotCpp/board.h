#pragma once

#include "common.h"
#include "move.h"

#include <array>

class UndoMove
{
public:
	Move Move;
	CastlingPermission CastlingPermission;
	File EnPassantFileIndex;
	Rank EnPassantRankIndex;
	Ply FiftyMoveRule;
	ZobristKey Key;
};

class Board
{
public:
	Piece ColorToMove;
	bool WhiteToMove;
	CastlingPermission CastlingPermissions;
	
	std::array<UndoMove, Constants::MaxHistory> History;
	Ply HistoryDepth;
	Ply LastTookPieceHistoryIndex;

	//Bitboard WhitePieces;
	//Bitboard BlackPieces;
	Bitboard EmptySquares;
	Bitboard AllPieces;

	std::array<Bitboard, ChessPiece::Count> BitBoard;
	std::array<Piece, 64> ArrayBoard;

	File EnPassantFileIndex;
	Rank EnPassantRankIndex;
	Bitboard EnPassantFile;
	ZobristKey Key;

	std::array<Piece, ChessPiece::Count> PieceCounts;
	std::array<Position, 2> KingPositions;
	Material WhiteMaterial;
	Material BlackMaterial;

	void SyncExtraBitBoards();
	void DoMove(const Move move);
	void UndoMove();

	[[nodiscard]] Move FromPositionString(const MoveString& moveString) const;
	void DoMove(const MoveString& moveString);
};

class CastleRevocationClass
{
public:
	std::array<CastlingPermission, 64> Table{};

	constexpr CastleRevocationClass()
	{
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

			Table[i] = permission;
		}
	}
};

constexpr CastleRevocationClass CastleRevocation = CastleRevocationClass();
