#pragma once

#include <array>
#include <vector>
#include <cmath>

#include "types.h"
#include "bits.h"

class Constants
{
public:
    static constexpr Ply MaxDepth = 64;
    static constexpr HistoryPly MaxHistory = 500;
    static constexpr size_t MaxMoves = 218;

    static constexpr Score Inf = 32000;
    static constexpr Score Mate = 31000;
    static constexpr Score MateThreshold = 30000;
    static constexpr Score EndgameMaterial = 1300;

private:
    Constants() = default;
};

template<class T>
using EachDepth = std::array<T, Constants::MaxDepth>;

template<class T>
using EachMove = std::array<T, Constants::MaxMoves>;

class CastlingPermissions
{
public:
    static constexpr CastlingPermission None = 0;

    static constexpr CastlingPermission WhiteQueen = 1 << 0;
    static constexpr CastlingPermission WhiteKing = 1 << 1;
    static constexpr CastlingPermission BlackQueen = 1 << 2;
    static constexpr CastlingPermission BlackKing = 1 << 3;

    static constexpr CastlingPermission All = WhiteKing | WhiteQueen | BlackKing | BlackQueen;

private:
    CastlingPermissions() = default;
};

class Colors
{
public:
    static constexpr Color White = 0;
    static constexpr Color Black = 1;
    
    static constexpr Color Count = 2;
};

template<class T>
using EachColor = std::array<T, Colors::Count>;

class Pieces
{
public:


    static constexpr Piece Empty = 0;
    
    static constexpr Piece Pawn = 2 << 1;
    static constexpr Piece Knight = 3 << 1;
    static constexpr Piece Bishop = 4 << 1;
    static constexpr Piece Rook = 5 << 1;
    static constexpr Piece Queen = 6 << 1;
    static constexpr Piece King = 7 << 1;

    static constexpr Piece WhitePawn = Colors::White | Pawn;
    static constexpr Piece WhiteKnight = Colors::White | Knight;
    static constexpr Piece WhiteBishop = Colors::White | Bishop;
    static constexpr Piece WhiteRook = Colors::White | Rook;
    static constexpr Piece WhiteQueen = Colors::White | Queen;
    static constexpr Piece WhiteKing = Colors::White | King;

    static constexpr Piece BlackPawn = Colors::Black | Pawn;
    static constexpr Piece BlackKnight = Colors::Black | Knight;
    static constexpr Piece BlackBishop = Colors::Black | Bishop;
    static constexpr Piece BlackRook = Colors::Black | Rook;
    static constexpr Piece BlackQueen = Colors::Black | Queen;
    static constexpr Piece BlackKing = Colors::Black | King;

    static constexpr Piece Color = 1;
    
    static constexpr Piece NextColor = 1;
    static constexpr Piece NextPiece = 1 << 1;
    
    static constexpr Piece Count = 16;
    

private:
    Pieces() = default;
};

template<class T>
using EachPiece = std::array<T, Pieces::Count>;

class Positions
{
public:
    static constexpr Position A1 = 0;
    static constexpr Position B1 = 1;
    static constexpr Position C1 = 2;
    static constexpr Position D1 = 3;
    static constexpr Position E1 = 4;
    static constexpr Position F1 = 5;
    static constexpr Position G1 = 6;
    static constexpr Position H1 = 7;

    static constexpr Position A2 = 8;
    static constexpr Position B2 = 9;
    static constexpr Position C2 = 10;
    static constexpr Position D2 = 11;
    static constexpr Position E2 = 12;
    static constexpr Position F2 = 13;
    static constexpr Position G2 = 14;
    static constexpr Position H2 = 15;

    static constexpr Position A3 = 16;
    static constexpr Position B3 = 17;
    static constexpr Position C3 = 18;
    static constexpr Position D3 = 19;
    static constexpr Position E3 = 20;
    static constexpr Position F3 = 21;
    static constexpr Position G3 = 22;
    static constexpr Position H3 = 23;

    static constexpr Position A4 = 24;
    static constexpr Position B4 = 25;
    static constexpr Position C4 = 26;
    static constexpr Position D4 = 27;
    static constexpr Position E4 = 28;
    static constexpr Position F4 = 29;
    static constexpr Position G4 = 30;
    static constexpr Position H4 = 31;

    static constexpr Position A5 = 32;
    static constexpr Position B5 = 33;
    static constexpr Position C5 = 34;
    static constexpr Position D5 = 35;
    static constexpr Position E5 = 36;
    static constexpr Position F5 = 37;
    static constexpr Position G5 = 38;
    static constexpr Position H5 = 39;

    static constexpr Position A6 = 40;
    static constexpr Position B6 = 41;
    static constexpr Position C6 = 42;
    static constexpr Position D6 = 43;
    static constexpr Position E6 = 44;
    static constexpr Position F6 = 45;
    static constexpr Position G6 = 46;
    static constexpr Position H6 = 47;

    static constexpr Position A7 = 48;
    static constexpr Position B7 = 49;
    static constexpr Position C7 = 50;
    static constexpr Position D7 = 51;
    static constexpr Position E7 = 52;
    static constexpr Position F7 = 53;
    static constexpr Position G7 = 54;
    static constexpr Position H7 = 55;

    static constexpr Position A8 = 56;
    static constexpr Position B8 = 57;
    static constexpr Position C8 = 58;
    static constexpr Position D8 = 59;
    static constexpr Position E8 = 60;
    static constexpr Position F8 = 61;
    static constexpr Position G8 = 62;
    static constexpr Position H8 = 63;

    static constexpr Position Count = 64;

    static constexpr std::array<Position, Count> All =
    {
        A1, B1, C1, D1, E1, F1, G1, H1,
        A2, B2, C2, D2, E2, F2, G2, H2,
        A3, B3, C3, D3, E3, F3, G3, H3,
        A4, B4, C4, D4, E4, F4, G4, H4,
        A5, B5, C5, D5, E5, F5, G5, H5,
        A6, B6, C6, D6, E6, F6, G6, H6,
        A7, B7, C7, D7, E7, F7, G7, H7,
        A8, B8, C8, D8, E8, F8, G8, H8
    };

    static constexpr std::array<Position, Count> Reflected =
    {
        A8, B8, C8, D8, E8, F8, G8, H8,
        A7, B7, C7, D7, E7, F7, G7, H7,
        A6, B6, C6, D6, E6, F6, G6, H6,
        A5, B5, C5, D5, E5, F5, G5, H5,
        A4, B4, C4, D4, E4, F4, G4, H4,
        A3, B3, C3, D3, E3, F3, G3, H3,
        A2, B2, C2, D2, E2, F2, G2, H2,
        A1, B1, C1, D1, E1, F1, G1, H1
    };

    template<class T>
    static constexpr std::array<T, Count> MakeReflected(const std::array<T, Count>& arr)
    {
        auto reflected = std::array<T, Count>{};
        for(auto i = 0; i < Count; i++)
        {
            reflected[i] = arr[Reflected[i]];
        }
        return reflected;
    }

    template<class T>
    static constexpr EachColor<std::array<T, Count>> MakeRelative(const std::array<T, Count>& arr)
    {
        return EachColor<std::array<T, Count>>
        {
            arr,
            MakeReflected<T>(arr),
        };
    }
    
    static constexpr EachColor<std::array<Position, Count>> Relative =
    {
        All,
        Reflected,
    };

    template<Color TColor>
    static constexpr Position Rel(Position position)
    {
        return Relative[TColor][position];
    }

    template<Color TColor, Position TPosition>
    static constexpr Position Rel()
    {
        return Relative[TColor][TPosition];
    }

    Positions() = delete;
};

class Files
{
public:
    static constexpr File A = 0;
    static constexpr File B = 1;
    static constexpr File C = 2;
    static constexpr File D = 3;
    static constexpr File E = 4;
    static constexpr File F = 5;
    static constexpr File G = 6;
    static constexpr File H = 7;

    static constexpr File Count = 8;

    static constexpr File Get(const Position position)
    {
        return position & 7;
    }
    
    Files() = delete;
};

class Ranks
{
public:
    static constexpr Rank Get(const Position position)
    {
        return position >> 3;
    }
};

template<class T>
using EachPosition = std::array<T, Positions::Count>;

class BitboardConstants
{
public:
    static constexpr Bitboard Empty = 0ULL;
    static constexpr Bitboard AllBoard = ~Empty;
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

    BitboardConstants() = delete;
};

class InFrontClass
{
public:
    EachColor<EachPosition<Bitboard>> ColumnInFront{};
    EachColor<EachPosition<Bitboard>> ColumnSortOfBehind{};
    
    constexpr InFrontClass()
    {
        for (Position i = 0; i < Positions::Count; i++)
        {
            const File col = Files::Get(i);
            const Rank row = i >> 3;
            Bitboard bitboard = 0UL;
            for (int j = row + 1; j < 8; j++)
            {
                bitboard |= GetBitboard(col + j * 8);
            }
            ColumnInFront[Colors::White][i] = bitboard;

            bitboard = 0;
            for (int j = row - 1; j >= 0; j--)
            {
                bitboard |= GetBitboard(col + j * 8);
            }
            ColumnInFront[Colors::Black][i] = bitboard;

            bitboard = 0;
            for (int j = row + 1; j >= 0; j--)
            {
                if (j > 7)
                {
                    continue;
                }
                bitboard |= GetBitboard(col + j * 8);
            }
            ColumnSortOfBehind[Colors::White][i] = bitboard;

            bitboard = 0;
            for (int j = row - 1; j < 8; j++)
            {
                if (j < 0)
                {
                    continue;
                }
                bitboard |= GetBitboard(col + j * 8);
            }
            ColumnSortOfBehind[Colors::Black][i] = bitboard;
        }
    };
};

static constexpr InFrontClass InFront = InFrontClass();

class EvaluationConstants
{
public:
    static constexpr EachPiece<Score> PieceValues = { 0, 0, 0, 0, 100, 100, 325, 325, 335, 335, 500, 500, 975, 975, 0, 0 };
};

using JumpArray = EachPosition<Bitboard>;
using ColoredJumpArray = EachColor<JumpArray>;

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
    JumpArray KnightJumps{};
    JumpArray KingJumps{};
    ColoredJumpArray PawnJumps{};

    // For eval
    ColoredJumpArray KingExtendedJumps{};
    ColoredJumpArray PawnSupportJumps{};
    
    constexpr BitboardJumpsClass()
    {
        //KnightJumps = JumpArray{};
        //KingJumps = JumpArray{};
        //PawnJumps = ColoredJumpArray{};
        //KingExtendedJumps = ColoredJumpArray{};
        //PawnSupportJumps = ColoredJumpArray{};
        
        constexpr Bitboard knightSpan = 43234889994ULL;
        constexpr Position knightPosition = 18ULL;

        constexpr Bitboard kingSpan = 460039ULL;
        constexpr Position kingPosition = 9ULL;
        
        constexpr std::array<Bitboard, 2> pawnSpans{ 1280, 5 };
        constexpr std::array<Position, 2> pawnPositions{ 1, 9 };

        constexpr std::array<Bitboard, 2> kingExtendedSpans
        {
            kingSpan | GetBitboard(24) | GetBitboard(25) | GetBitboard(26),
            (kingSpan << 8) | GetBitboard(0) | GetBitboard(1) | GetBitboard(2)
        };
        constexpr std::array<Position, 2> kingExtendedPositions = { 9, 17 };

        constexpr std::array<Bitboard, 2> pawnSupportSpans
        {
            GetBitboard(0) | GetBitboard(2) | GetBitboard(8) | GetBitboard(10),
            GetBitboard(0) | GetBitboard(2) | GetBitboard(8) | GetBitboard(10)
        };
        constexpr std::array<Position, 2> pawnSupportPositions = { 9, 1 };

        for (Position i = 0; i < Positions::Count; i++)
        {
            KnightJumps[i] = GetAttackedByJumpingPiece(i, knightSpan, knightPosition);
            KingJumps[i] = GetAttackedByJumpingPiece(i, kingSpan, kingPosition);
            for (int j = 0; j < 2; j++)
            {
                const auto pawnSpan = pawnSpans[j];
                const auto pawnPosition = pawnPositions[j];
                PawnJumps[j][i] = GetAttackedByJumpingPiece(i, pawnSpan, pawnPosition);

                const auto kingExtendedSpan = kingExtendedSpans[j];
                const auto kingExtendedPosition = kingExtendedPositions[j];
                KingExtendedJumps[j][i] = GetAttackedByJumpingPiece(i, kingExtendedSpan, kingExtendedPosition);

                const auto pawnSupporSpan = pawnSupportSpans[j];
                const auto pawnSupporPosition = pawnSupportPositions[j];
                PawnSupportJumps[j][i] = GetAttackedByJumpingPiece(i, pawnSupporSpan, pawnSupporPosition);
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
        for (Position i = 0; i < Positions::Count; i++)
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

class SearchDataClass
{
public:
    using ReductionsTableType = std::array<EachDepth<EachMove<Ply>>, 2>;

    ReductionsTableType Reductions{};

    SearchDataClass()
    {
        for(Ply depth = 0; depth < Constants::MaxDepth; depth++)
        {
            for(MoveCount movesEvaluated = 1; movesEvaluated < Constants::MaxMoves; movesEvaluated++)
            {
                constexpr double offset = 0.8;
                constexpr double ratio = 0.45;
                const double reduction = std::log(depth) * std::log(movesEvaluated) * ratio + offset;
                if (reduction >= 1.5)
                {
                    Reductions[0][depth][movesEvaluated] = static_cast<Ply>(reduction);
                }

                constexpr double offsetPv = 0.5;
                constexpr double ratioPv = 0.33;
                const double reductionPv = std::log(depth) * std::log(movesEvaluated) * ratioPv + offsetPv;
                if(reductionPv >= 1.5)
                {
                    Reductions[1][depth][movesEvaluated] = static_cast<Ply>(reductionPv);
                }
            }
        }
    }
};

static inline SearchDataClass SearchData = SearchDataClass();