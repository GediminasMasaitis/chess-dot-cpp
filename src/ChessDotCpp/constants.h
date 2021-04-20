#pragma once

#include <array>
#include <vector>

#include "types.h"
#include "bits.h"

class Constants
{
public:
	static constexpr Ply MaxDepth = 64;
	static constexpr Ply MaxHistory = 20;
	static constexpr size_t MaxMoves = 218;

	static constexpr Score Inf = 32000;
	static constexpr Score Mate = 30000;

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
	static constexpr Piece White = 0;
	static constexpr Piece Black = 1;

	static constexpr Piece Empty = 0;
	
	static constexpr Piece Pawn = 2 << 1;
	static constexpr Piece Knight = 3 << 1;
	static constexpr Piece Bishop = 4 << 1;
	static constexpr Piece Rook = 5 << 1;
	static constexpr Piece Queen = 6 << 1;
	static constexpr Piece King = 7 << 1;

	static constexpr Piece WhitePawn = White | Pawn;
	static constexpr Piece WhiteKnight = White | Knight;
	static constexpr Piece WhiteBishop = White | Bishop;
	static constexpr Piece WhiteRook = White | Rook;
	static constexpr Piece WhiteQueen = White | Queen;
	static constexpr Piece WhiteKing = White | King;

	static constexpr Piece BlackPawn = Black | Pawn;
	static constexpr Piece BlackKnight = Black | Knight;
	static constexpr Piece BlackBishop = Black | Bishop;
	static constexpr Piece BlackRook = Black | Rook;
	static constexpr Piece BlackQueen = Black | Queen;
	static constexpr Piece BlackKing = Black | King;

	static constexpr Piece Color = 1;
	
	static constexpr Piece NextColor = 1;
	static constexpr Piece NextPiece = 1 << 1;
	
	static constexpr size_t Count = 16;
	

private:
	ChessPiece() = default;
};


class BitboardConstants
{
public:
	static constexpr Bitboard AllBoard = ~0ULL;	
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

	static constexpr std::array<Bitboard, Files.size() + Ranks.size() + Diagonals.size() + Antidiagonals.size()> AllSlides =
	{
		0x101010101010101ULL,
		0x202020202020202ULL,
		0x404040404040404ULL,
		0x808080808080808ULL,
		0x1010101010101010ULL,
		0x2020202020202020ULL,
		0x4040404040404040ULL,
		0x8080808080808080ULL,

		0xFFULL,
		0xFF00ULL,
		0xFF0000ULL,
		0xFF000000ULL,
		0xFF00000000ULL,
		0xFF0000000000ULL,
		0xFF000000000000ULL,
		0xFF00000000000000ULL,

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
		0x8000000000000000ULL,

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
	static constexpr Bitboard BlackQueenSideCastleAttackMask = (Files[2] | Files[3] | Files[4]) & Ranks[7];
	static constexpr Bitboard BlackKingSideCastleAttackMask = (Files[4] | Files[5] | Files[6]) & Ranks[7];

private:
	BitboardConstants() = default;
};

class EvaluationConstants
{
public:
	static constexpr std::array<Score, ChessPiece::Count> Weights = { /*0, 100, 325, 325, 550, 1000, 50000, 100, 325, 325, 550, 1000, 50000*/ }; // TODO
};

using JumpArray = std::array<Bitboard, 64>;
using ColoredJumpArray = std::array<JumpArray, 2>;
class BitboardJumpsClass
{
private:
	static constexpr Bitboard GetAttackedByJumpingPiece(const Position position, const Bitboard jumpMask, const Position jumpMaskCenter)
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
		jumps &= ~((position >> 3) < 4 ? BitboardConstants::Ranks[6] | BitboardConstants::Ranks[7] : BitboardConstants::Ranks[0] | BitboardConstants::Ranks[1]);
		return jumps;
	}

public:
	JumpArray KnightJumps;
	JumpArray KingJumps;
	ColoredJumpArray PawnJumps;
	
	constexpr BitboardJumpsClass()
	{
		KnightJumps = JumpArray{};
		KingJumps = JumpArray{};
		PawnJumps = ColoredJumpArray{};
		
		constexpr Bitboard KnightSpan = 43234889994ULL;
		constexpr Position KnightPosition = 18ULL;

		constexpr Bitboard KingSpan = 460039ULL;
		constexpr Position KingPosition = 9ULL;
		
		constexpr std::array<Bitboard, 2> pawnSpans{ 1280, 5 };
		constexpr std::array<Position, 2> pawnPositions{ 1, 9 };

		/*pawnSpans[ChessPiece::White] = 1280;
		pawnPositions[ChessPiece::White] = 1;
		pawnSpans[ChessPiece::Black] = 5;
		pawnPositions[ChessPiece::Black] = 9;*/

		for (Position i = 0; i < 64; i++)
		{
			KnightJumps[i] = GetAttackedByJumpingPiece(i, KnightSpan, KnightPosition);
			KingJumps[i] = GetAttackedByJumpingPiece(i, KingSpan, KingPosition);
			for (int j = 0; j < 2; j++)
			{
				const auto pawnSpan = pawnSpans[j];
				const auto pawnPosition = pawnPositions[j];
				PawnJumps[j][i] = GetAttackedByJumpingPiece(i, pawnSpan, pawnPosition);
			}	
		}
	}
};

static constexpr BitboardJumpsClass BitboardJumps = BitboardJumpsClass();

class BetweenBitboardsClass
{
public:
	using BetweenArray = std::array<std::array<Bitboard, 64>, 64>;

	BetweenArray Between{};
	
	constexpr BetweenBitboardsClass()
	{	
		for (Position i = 0; i < 64; i++)
		{
			const File fromFile = i & 7;
			const Rank fromRank = i >> 3;
			const Diagonal fromDiagonal = fromFile + fromRank;
			const Antidialgonal fromAntidiagonal = fromRank - fromFile + 7;
			
			for (Position j = 0; j < 64; j++)
			{
				if (i == j)
				{
					continue;
				}

				const File toFile = j & 7;
				const Rank toRank = j >> 3;
				const Diagonal toDiagonal = toFile + toRank;
				const Antidialgonal toAntidiagonal = toRank - toFile + 7;
				
				const Position min = std::min(i, j);
				const Position max = std::max(i, j);

				Bitboard slide = 0ULL;
				if(fromFile == toFile)
				{
					slide = BitboardConstants::Files[fromFile];
				}
				else if (fromRank == toRank)
				{
					slide = BitboardConstants::Ranks[fromRank];
				}
				else if(fromDiagonal == toDiagonal)
				{
					slide = BitboardConstants::Diagonals[fromDiagonal];
				}
				else if(fromAntidiagonal == toAntidiagonal)
				{
					slide = BitboardConstants::Antidiagonals[fromAntidiagonal];
				}		
				
				Bitboard result = 0ULL;
				while (slide != 0)
				{
					Position pos = BitScanForward(slide);
					if (pos > min && pos < max)
					{
						result |= GetBitboard(pos);
					}
					slide &= slide - 1;
				}
				Between[i][j] = result;
			}
		}
	}
};

static constexpr BetweenBitboardsClass BetweenBitboards = BetweenBitboardsClass();