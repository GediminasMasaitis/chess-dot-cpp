#pragma once

#include <array>

#include "types.h"

class Constants
{
public:
	static constexpr Ply MaxDepth = 256;
	static constexpr Ply MaxHistory = 20;
	static constexpr size_t MaxMoves = 218;

	static constexpr size_t PieceCount = 13;
private:
	Constants() = default;
};

class ChessCastlingPermissions
{
public:
	static constexpr CastlingPermission None = 0;

	static constexpr CastlingPermission WhiteQueen = 1 << 0;
	static constexpr CastlingPermission WhiteKing = 1 << 1;
	static constexpr CastlingPermission BlackQueen = 1 << 2;
	static constexpr CastlingPermission BlackKing = 1 << 3;

	static constexpr CastlingPermission All = WhiteKing | WhiteQueen | BlackKing | BlackQueen;

private:
	ChessCastlingPermissions() = default;
};

class ChessPiece
{
public:
	static constexpr Piece Empty = 0;

	static constexpr Piece WhitePawn = 1;
	static constexpr Piece WhiteKnight = 2;
	static constexpr Piece WhiteBishop = 3;
	static constexpr Piece WhiteRook = 4;
	static constexpr Piece WhiteQueen = 5;
	static constexpr Piece WhiteKing = 6;

	static constexpr Piece BlackPawn = 7;
	static constexpr Piece BlackKnight = 8;
	static constexpr Piece BlackBishop = 9;
	static constexpr Piece BlackRook = 10;
	static constexpr Piece BlackQueen = 11;
	static constexpr Piece BlackKing = 12;

private:
	ChessPiece() = default;
};


class BitboardConstants
{
public:
	static constexpr Bitboard AllBoard = ~0ULL;
	static constexpr Bitboard KnightSpan = 43234889994ULL;
	static constexpr Position KnightSpanPosition = 18ULL;
	static constexpr Bitboard KingSpan = 460039ULL;
	static constexpr Position KingSpanPosition = 9ULL;
	
	static constexpr std::array<Bitboard, 8> Files =
	{
		0x101010101010101ULL,
		0x202020202020202ULL,
		0x404040404040404ULL,
		0x808080808080808ULL,
		0x1010101010101010ULL,
		0x2020202020202020ULL,
		0x4040404040404040ULL,
		0x8080808080808080ULL
	};
	
	static constexpr std::array<Bitboard, 8> Ranks =
	{
		0xFFULL,
		0xFF00ULL,
		0xFF0000ULL,
		0xFF000000ULL,
		0xFF00000000ULL,
		0xFF0000000000ULL,
		0xFF000000000000ULL,
		0xFF00000000000000ULL
	};
	
	static constexpr std::array<Bitboard, 15> Diagonals =
	{
		0x1ULL,
		0x102ULL,
		0x10204ULL,
		0x1020408ULL,
		0x102040810ULL,
		0x10204081020ULL,
		0x1020408102040ULL,
		0x102040810204080ULL,
		0x204081020408000ULL,
		0x408102040800000ULL,
		0x810204080000000ULL,
		0x1020408000000000ULL,
		0x2040800000000000ULL,
		0x4080000000000000ULL,
		0x8000000000000000ULL
	};
	
	static constexpr std::array<Bitboard, 15> Antidiagonals =
	{
		0x80ULL,
		0x8040ULL,
		0x804020ULL,
		0x80402010ULL,
		0x8040201008ULL,
		0x804020100804ULL,
		0x80402010080402ULL,
		0x8040201008040201ULL,
		0x4020100804020100ULL,
		0x2010080402010000ULL,
		0x1008040201000000ULL,
		0x804020100000000ULL,
		0x402010000000000ULL,
		0x201000000000000ULL,
		0x100000000000000ULL
	};
	
	static constexpr Bitboard KingSide = Files[0] | Files[1] | Files[2] | Files[3];
	static constexpr Bitboard QueenSide = ~KingSide;

	static constexpr Bitboard WhiteQueenSideCastleMask = (Files[1] | Files[2] | Files[3]) & Ranks[0];
	static constexpr Bitboard WhiteKingSideCastleMask = (Files[5] | Files[6]) & Ranks[0];
	static constexpr Bitboard BlackQueenSideCastleMask = (Files[1] | Files[2] | Files[3]) & Ranks[7];
	static constexpr Bitboard BlackKingSideCastleMask = (Files[5] | Files[6]) & Ranks[7];

	static constexpr Bitboard WhiteQueenSideCastleAttackMask = (Files[2] | Files[3] | Files[4]) & Ranks[0];
	static constexpr Bitboard WhiteKingSideCastleAttackMask = (Files[4] | Files[5] | Files[6]) & Ranks[0];
	static constexpr Bitboard BlackKingSideCastleAttackMask = (Files[2] | Files[3] | Files[4]) & Ranks[7];
	static constexpr Bitboard BlackQueenSideCastleAttackMask = (Files[4] | Files[5] | Files[6]) & Ranks[7];

private:
	BitboardConstants() = default;
};

class EvaluationConstants
{
public:
	static constexpr std::array<Score, Constants::PieceCount> Weights = { 0, 100, 325, 325, 550, 1000, 50000, 100, 325, 325, 550, 1000, 50000 };
};
