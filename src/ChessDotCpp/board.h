#pragma once

#include "move.h"
#include "constants.h"

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
	bool WhiteToMove;
	CastlingPermission CastlingPermissions;
	
	std::array<UndoMove, Constants::MaxHistory> History;
	Ply HistoryDepth;
	Ply LastTookPieceHistoryIndex;

	Bitboard WhitePieces;
	Bitboard BlackPieces;
	Bitboard EmptySquares;
	Bitboard AllPieces;

	std::array<Bitboard, 13> BitBoard;
	std::array<Piece, 64> ArrayBoard;

	File EnPassantFileIndex;
	Rank EnPassantRankIndex;
	Bitboard EnPassantFile;
	ZobristKey Key;

	std::array<uint8_t, 13> PieceCounts;
	Material WhiteMaterial;
	Material BlackMaterial;

	void SyncExtraBitBoards();
	void DoMove(const Move move);
	void UndoMove();

private:
	static constexpr std::array<CastlingPermission, 64> GenerateRevocationTable();
	
	inline static const std::array<CastlingPermission, 64> CastleRevocationTable = GenerateRevocationTable();
};
