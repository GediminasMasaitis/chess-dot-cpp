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
	ZobristKey PawnKey;
};

class Board
{
public:
	Color ColorToMove;
	bool WhiteToMove;
	CastlingPermission CastlingPermissions;
	
	std::array<UndoMove, Constants::MaxHistory> History;
	HistoryPly HistoryDepth;
	HistoryPly FiftyMoveRuleIndex;

	//Bitboard WhitePieces;
	//Bitboard BlackPieces;
	Bitboard EmptySquares;
	Bitboard AllPieces;

	EachPiece<Bitboard> BitBoard;
	EachPosition<Piece> ArrayBoard;

	File EnPassantFileIndex;
	Rank EnPassantRankIndex;
	Bitboard EnPassantFile;
	ZobristKey Key;
	ZobristKey PawnKey;

	EachPiece<Piece> PieceCounts;
	EachColor<Position> KingPositions;
	EachColor<Score> PawnMaterial;
	EachColor<Score> PieceMaterial;

	void SyncExtraBitBoards();
	void DoMove(const Move move);
	void UndoMove();

	[[nodiscard]] Move FromPositionString(const MoveString& moveString) const;
	void DoMove(const MoveString& moveString);

	void FlipColors();
};

class CastleRevocationClass
{
public:
	std::array<CastlingPermission, 64> Table{};

	constexpr CastleRevocationClass()
	{
		for (Position i = 0; i < 64; i++)
		{
			CastlingPermission permission = CastlingPermissions::All;
			switch (i)
			{
			case 0:
				permission &= ~CastlingPermissions::WhiteQueen;
				break;
			case 4:
				permission &= ~CastlingPermissions::WhiteQueen;
				permission &= ~CastlingPermissions::WhiteKing;
				break;
			case 7:
				permission &= ~CastlingPermissions::WhiteKing;
				break;
			case 56:
				permission &= ~CastlingPermissions::BlackQueen;
				break;
			case 60:
				permission &= ~CastlingPermissions::BlackQueen;
				permission &= ~CastlingPermissions::BlackKing;
				break;
			case 63:
				permission &= ~CastlingPermissions::BlackKing;
				break;
			default:
				break;
			}

			Table[i] = permission;
		}
	}
};

constexpr CastleRevocationClass CastleRevocation = CastleRevocationClass();
