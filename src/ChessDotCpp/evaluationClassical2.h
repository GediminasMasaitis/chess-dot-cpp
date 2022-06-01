#pragma once

#include "common.h"
#include "evalbase.h"
#include "board.h"
#include "evalstate.h"
#include "attacks.h"
#include "magics.h"

class EvaluationClassical2
{
public:
#if TUNE
    static constexpr bool tune = true;
#else
    static constexpr bool tune = false;
#endif

    class EvaluationClassical2Trace
    {
    public:
        using TraceScores = EachColor<PhaseScore>;

        PhaseScore eval;
        Phase phase;

        std::array<TraceScores, 6> material;
        std::array<EachPosition<TraceScores>, 6> psts;
        EachPosition<TraceScores> passedPawnPst;
        std::array<std::array<TraceScores, 28>, 6> mobilityBonus;
        std::array<TraceScores, 6> kingAttackBonus;
        std::array<TraceScores, 8> bishopSameColorSquareOwnPawnBonus;
        std::array<TraceScores, 8> bishopSameColorSquareOpponentPawnBonus;
        TraceScores bishopPairBonus;
        TraceScores doubledPawnBonus;
        TraceScores doubledPassedPawnBonus;
        TraceScores protectedPawnBonus;
        TraceScores weakPawnBonus;
        TraceScores rookOpenFileBonus;
        TraceScores rookSemiOpenFileBonus;
    };

    class EvaluationClassical2Data
    {
    public:
        EachPiece<Bitboard> PieceAttacks;
        EachPosition<Bitboard> AttacksFrom;
    };

    using Trace = EvaluationClassical2Trace;
    using Data = EvaluationClassical2Data;

    static constexpr int ParameterCount = 6 + 6 * 64 + 64 + 6 * 28 + 6 + 2 * 8 + 7;

    static constexpr std::array<PhaseScore, 6> material =
    {
        S(100, 143), S(408, 283), S(388, 296), S(548, 547), S(1216, 946), S(  0,   0)
    };

    static constexpr std::array<std::array<PhaseScore, 64>, 6> psts =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S( 93, 163), S(139, 180), S( 42,  89), S( 90,  49), S( 65,  93), S(147,  75), S( -9, 120), S(-92, 130),
            S(-21, -24), S(  0, -41), S(-22, -28), S(  7, -58), S(  6, -43), S( 77, -58), S( 43, -44), S(  4, -39),
            S(-32, -39), S(-11, -47), S(-16, -51), S(  6, -65), S(  5, -54), S( -1, -53), S( -0, -51), S(-28, -48),
            S(-40, -46), S(-23, -49), S(-11, -58), S( -0, -60), S(  7, -60), S(  0, -62), S( -3, -61), S(-33, -61),
            S(-38, -56), S(-26, -56), S(-22, -56), S(-17, -50), S( -7, -51), S(-11, -56), S( 15, -72), S(-25, -66),
            S(-32, -49), S(-15, -59), S(-22, -44), S( -2, -53), S( -6, -43), S( 27, -58), S( 26, -71), S(-13, -69),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-163,  -0), S(-107, -14), S(-75,  12), S(-61,  -8), S( 55, -18), S(-104,   0), S(-32, -38), S(-97, -45),
            S(-75,   1), S(-54,  13), S( 68, -24), S(  1,  13), S(  9,   3), S( 42, -21), S(  4,  -6), S(-15, -23),
            S(-60,  -7), S( 42, -15), S( -4,  24), S( 20,  22), S( 43,  10), S( 97,  -1), S( 43, -11), S( 53, -31),
            S( -2,  -4), S( 13,   7), S( -5,  32), S( 42,  28), S( 12,  35), S( 43,  22), S( -1,  19), S( 28,  -4),
            S( -0,  -4), S(  9,  -3), S(  2,  22), S(  8,  32), S( 17,  23), S( 13,  24), S( 22,   9), S( 14,   0),
            S(-11, -10), S(-17,   4), S( -4,   3), S(-11,  21), S(  7,  17), S( -1,   1), S( 18, -15), S( -8,  -8),
            S( -5, -15), S(-36,  -3), S(-20,  -1), S( 11,  -6), S(  7,  -3), S( 15, -15), S( -4,  -9), S(  8, -22),
            S(-100,  31), S(  6, -22), S(-42,  -8), S(-26,   3), S(  6, -12), S(-15,  -7), S( 12, -24), S(  6, -30)
        },
        {
            S(-14, -16), S(-10, -17), S(-130,   3), S(-92,   2), S(-47,  -3), S(-65,  -4), S(-30,  -7), S( 15, -24),
            S(-22,  -2), S( 14, -11), S(-26,   0), S(-32, -13), S( 17, -11), S( 49, -18), S(  1,  -5), S(-47,  -6),
            S( -7,  -2), S( 33, -16), S( 38, -12), S( 14,  -9), S( 11,  -9), S( 40,  -7), S( 13,  -6), S(  2,   0),
            S( 10,  -8), S( 25,  -7), S( 11,   3), S( 39,   1), S( 34,  -0), S( 27,  -2), S( 25, -14), S(  4,  -1),
            S( 22, -14), S( 21,  -8), S( 23,  -0), S( 31,   7), S( 42,  -7), S( 24,  -4), S( 25, -15), S( 34, -14),
            S( 22, -10), S( 34, -11), S( 30,  -0), S( 31,  -2), S( 33,   2), S( 49, -14), S( 34, -13), S( 36, -13),
            S( 41, -12), S( 42, -23), S( 36, -15), S( 28, -11), S( 35,  -9), S( 43, -19), S( 61, -26), S( 40, -26),
            S(  2, -10), S( 34,  -5), S( 32, -13), S( 22, -10), S( 30, -14), S( 27, -14), S(-10,  -1), S( 19, -11)
        },
        {
            S( 12,  18), S( 17,  15), S(-29,  33), S( 25,  17), S( 17,  21), S(-43,  32), S(-16,  24), S( -1,  16),
            S(  7,  18), S( 10,  20), S( 43,  12), S( 42,  12), S( 58,  -2), S( 42,   7), S( -8,  23), S(  6,  16),
            S( -1,  14), S( 24,  12), S( 29,   9), S( 34,  10), S(  8,  10), S( 45,  -0), S( 67,  -6), S( 14,   2),
            S(-14,  14), S(  1,   9), S( 16,  17), S( 23,   6), S( 26,   7), S( 36,   5), S(  3,   5), S(-13,  13),
            S(-29,  16), S(-13,  13), S( -1,  13), S(  3,   8), S( 15,   0), S( -4,   2), S( 12,  -3), S(-20,   3),
            S(-30,   9), S(-11,   5), S( -1,  -3), S( -6,   2), S(  9,  -4), S(  6,  -8), S(  1,  -3), S(-20,  -4),
            S(-26,   4), S(  1,  -3), S( -3,   1), S(  7,   2), S( 20, -11), S( 20, -11), S( 11, -12), S(-48,   8),
            S(  2,  -4), S(  8,   0), S( 21,  -0), S( 30,  -5), S( 34,  -9), S( 19,  -8), S(-10,   2), S(  4, -21)
        },
        {
            S( -1, -18), S(-31,  44), S(-16,  41), S(-28,  45), S( 92, -16), S( 85, -21), S( 57,  -9), S( 74,   5),
            S(-15,  -9), S(-48,  26), S(-21,  35), S(-13,  49), S(-74,  89), S( 34,  14), S( -1,  44), S( 57,   6),
            S(  6,  -5), S( -2,   7), S( 18,  -4), S(-30,  74), S( 11,  50), S( 49,  21), S( 26,  25), S( 46,  17),
            S(-23,  41), S(-13,  31), S(-23,  32), S(-29,  50), S( -7,  54), S(  1,  37), S( -2,  74), S(  2,  61),
            S( 14,  -6), S(-28,  44), S(  4,  13), S( -3,  36), S(  1,  27), S(  6,  25), S( 10,  40), S( 10,  38),
            S( -7,  16), S( 23, -35), S(  5,   6), S( 18,  -8), S( 13,   8), S( 14,  14), S( 28,  11), S( 19,  34),
            S( -1,  -7), S( 15, -28), S( 33, -33), S( 33, -30), S( 41, -27), S( 41, -35), S( 23, -44), S( 36, -32),
            S( 31, -36), S( 29, -39), S( 34, -28), S( 43, -36), S( 28, -11), S( 12, -25), S( 14, -20), S(-21, -24)
        },
        {
            S(-91, -71), S(169, -68), S(166, -48), S( 90, -36), S(-113,  13), S(-66,  28), S( 56,  -6), S( 40, -21),
            S(181, -48), S( 96,   1), S( 56,   6), S(128,  -3), S( 52,  13), S( 54,  32), S( -2,  27), S(-136,  37),
            S( 74,  -7), S( 93,   7), S(123,   5), S( 33,  14), S( 62,  12), S(134,  31), S(148,  24), S(-10,  13),
            S( 19, -16), S( 15,  19), S( 39,  21), S(-15,  34), S(-23,  34), S(-21,  42), S(  7,  30), S(-86,  19),
            S(-70,  -6), S( 43,  -8), S(-38,  31), S(-90,  44), S(-99,  48), S(-64,  39), S(-59,  23), S(-93,   6),
            S( -0, -19), S(  2,   1), S(-31,  22), S(-58,  34), S(-65,  39), S(-53,  32), S(-10,  14), S(-43,   2),
            S( 13, -31), S( 24, -10), S(-20,  15), S(-72,  26), S(-51,  27), S(-29,  18), S( 17,  -2), S( 16, -20),
            S(-23, -58), S( 43, -43), S( 13, -20), S(-76,   3), S( -2, -20), S(-35,  -3), S( 35, -33), S( 17, -58)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-30,  23), S(-15, -16), S( 15,  60), S( -2,  72), S(  2,  42), S( -5,  39), S( 15,  49), S( 24,  74),
        S( 38, 146), S(  2, 158), S( 42, 113), S(  8, 110), S( 45,  76), S(  3, 105), S(-35, 132), S(-39, 145),
        S( 22,  80), S(  5,  73), S( 19,  57), S(  1,  50), S(  4,  35), S( 36,  39), S( -3,  71), S( -3,  71),
        S( 12,  43), S(-19,  42), S(-20,  33), S(-18,  25), S(-14,  26), S(-10,  29), S(-18,  45), S( 17,  40),
        S(  4,  14), S(-15,  22), S(-13,  15), S(-34,  17), S( -4,   7), S( 28,   1), S( 10,  21), S( 25,  11),
        S( -4,  10), S(  6,  13), S( 14,  -0), S(-32,  22), S( -5,   9), S( 13,   5), S( 19,  14), S(-10,  16),
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
    };

    static constexpr std::array<std::array<PhaseScore, 28>, 6> mobilityBonus =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-117, -115), S(-47, -65), S(-37, -27), S(-26,  -1), S( -8,   2), S( -2,  10), S(  7,  13), S( 18,  12),
            S( 31,   6), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 17, -54), S(-43, -62), S(-32, -19), S(-16,  -1), S( -5,   7), S(  5,  15), S( 11,  21), S( 16,  25),
            S( 19,  28), S( 24,  30), S( 32,  27), S( 53,  22), S( 29,  34), S( 59,  20), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 72,  26), S(-55, -32), S(-48, -63), S(-40, -41), S(-32, -16), S(-26,  -8), S(-19,   3), S(-14,   6),
            S( -5,   5), S(  5,   6), S( 17,   7), S( 27,  10), S( 39,  13), S( 43,  15), S( 58,   8), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(-97, -85), S(-38, -207), S(-18, -144), S(-22, -53), S(-13, -48),
            S(-13, -49), S( -7, -37), S( -4, -20), S( -3,  -8), S( -1,   7), S(  3,  12), S(  6,  18), S(  6,  35),
            S(  9,  31), S(  8,  48), S( 10,  43), S( 17,  51), S( 17,  62), S( 36,  55), S( 26,  64), S( 42,  57),
            S( 38,  60), S(116,   7), S( 25,  60), S(128,   2)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
    }};

    static constexpr std::array<PhaseScore, 6> kingAttackBonus =
    {
        S(  0,   0), S( 15,  -9), S( 20,  -3), S( 29,  -9), S( 17,   5), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 8> bishopSameColorSquareOwnPawnBonus =
    {
        S( -7,  21), S(  3,  12), S(  8,   1), S(  7,  -3), S(  6, -10), S(  2, -19), S( -4, -24), S( -4, -43)
    };

    static constexpr std::array<PhaseScore, 8> bishopSameColorSquareOpponentPawnBonus =
    {
        S( 11, -19), S( -6,  -9), S( -7,  -5), S( -8,  -3), S( -5,   2), S( -4,   5), S( -1,   6), S(  2,  37)
    };

    static constexpr PhaseScore bishopPairBonus = S(29, 53);
    static constexpr PhaseScore doubledPawnBonus = S(-6, -12);
    static constexpr PhaseScore doubledPassedPawnBonus = S(-8, -27);
    static constexpr PhaseScore protectedPawnBonus = S(14, 10);
    static constexpr PhaseScore weakPawnBonus = S(-11, -9);
    static constexpr PhaseScore rookOpenFileBonus = S(17, -3);
    static constexpr PhaseScore rookSemiOpenFileBonus = S(2, 9);

    static constexpr Score Tempo = 15;

    static inline Trace T;
    static inline EachPiece<EachPosition<PhaseScore>> MaterialAndPst;

    using PieceIndex = uint8_t;
    static constexpr PieceIndex GetPieceIndex(Piece piece)
    {
        return (piece / 2) - 2;
    }

    template<Color TColor, Piece TPiece>
    static void GetDataForPieces(const BoardBase& board, Data& data)
    {
        constexpr Piece coloredPiece = TPiece | TColor;
        const Bitboard allPieces = board.AllPieces;
        //const Bitboard notOwnPieces = ~board.BitBoard[TColor];
        Bitboard piecesBitboard = board.BitBoard[coloredPiece];
        Bitboard allAttacks = BitboardConstants::Empty;
        while (piecesBitboard != 0)
        {
            const Position position = BitScanForward(piecesBitboard);
            Bitboard attack;
            if constexpr (TPiece == Pieces::Knight)
            {
                attack = BitboardJumps.KnightJumps[position];
            }
            else if constexpr (TPiece == Pieces::Bishop)
            {
                attack = SlideMoveGenerator::DiagonalAntidiagonalSlide(allPieces, position);
            }
            else if constexpr (TPiece == Pieces::Rook)
            {
                attack = SlideMoveGenerator::HorizontalVerticalSlide(allPieces, position);
            }
            else if constexpr (TPiece == Pieces::Queen)
            {
                attack = SlideMoveGenerator::AllSlide(allPieces, position);
            }
            else if constexpr (TPiece == Pieces::King)
            {
                attack = BitboardJumps.KingJumps[position];
            }
            else
            {
                Throw();
            }

            //attack &= notOwnPieces;
            data.AttacksFrom[position] = attack;
            allAttacks |= attack;
            piecesBitboard &= piecesBitboard - 1;
        }
        data.PieceAttacks[coloredPiece] = allAttacks;
        data.PieceAttacks[TColor] |= allAttacks;
    }

    template<Color TColor>
    static void GetDataForColor(const BoardBase& board, Data& data)
    {
        data.PieceAttacks[TColor] = BitboardConstants::Empty;
        GetDataForPieces<TColor, Pieces::Knight>(board, data);
        GetDataForPieces<TColor, Pieces::Bishop>(board, data);
        GetDataForPieces<TColor, Pieces::Rook>(board, data);
        GetDataForPieces<TColor, Pieces::Queen>(board, data);
        GetDataForPieces<TColor, Pieces::King>(board, data);

        constexpr Piece coloredPawn = Pieces::Pawn | TColor;
        constexpr bool forWhite = TColor == Colors::White;
        const Bitboard pawnAttacks = AttacksGenerator::GetAttackedByPawns(board.BitBoard[coloredPawn], forWhite);
        data.PieceAttacks[coloredPawn] = pawnAttacks;
        data.PieceAttacks[TColor] |= pawnAttacks;
    }

    static void GetData(const BoardBase& board, Data& data)
    {
        GetDataForColor<Colors::White>(board, data);
        GetDataForColor<Colors::Black>(board, data);
    }

    template<Color TColor>
    static PhaseScore EvaluatePawns(const BoardBase& board, const Data& data)
    {
        constexpr Color color = TColor;
        constexpr Color opponent = color ^ 1;
        constexpr Piece pieceNoColor = Pieces::Pawn;
        constexpr Piece piece = pieceNoColor | color;
        constexpr PieceIndex pieceIndex = GetPieceIndex(piece);
        PhaseScore score = 0;

        constexpr Piece opponentPawn = Pieces::Pawn | opponent;
        const Bitboard ownPawnControl = data.PieceAttacks[piece];
        const Bitboard opponentPawnControl = data.PieceAttacks[opponentPawn];

        // PROTECTED PAWNS
        const Bitboard protectedPawns = ownPawnControl & board.BitBoard[piece];
        const uint8_t protectedPawnCount = PopCount(protectedPawns);
        score += protectedPawnCount * protectedPawnBonus;
        TraceAdd(protectedPawnBonus, protectedPawnCount);

        Bitboard pawns = board.BitBoard[piece];
        while (pawns != 0)
        {
            const Position pos = BitScanForward(pawns);

            // MATERIAL AND PST
            score += MaterialAndPst[piece][pos];
            TraceIncr(material[pieceIndex]);
            TraceIncr(psts[pieceIndex][GetRelativeInverse(color, pos)]);

            // DOUBLED PAWNS
            const Bitboard inFront = InFront.ColumnInFront[color][pos];
            const Bitboard ownPawnsInFront = inFront & board.BitBoard[piece];
            const uint8_t ownPawnInFrontCount = PopCount(ownPawnsInFront);
            score += ownPawnInFrontCount * doubledPawnBonus;
            TraceAdd(doubledPawnBonus, ownPawnInFrontCount);
            
            // WEAK PAWNS
            const Bitboard behind = InFront.ColumnSortOfBehind[color][pos];
            const Bitboard ownControlledBehind = behind & ownPawnControl;
            const auto isWeak = ownControlledBehind == 0;
            if (isWeak)
            {
                score += weakPawnBonus;
                TraceIncr(weakPawnBonus);
            }

            // PASSED PAWNS
            const Bitboard opponentPawnsInFront = inFront & board.BitBoard[opponentPawn];
            const Bitboard passBitboard = inFront & (opponentPawnControl | opponentPawnsInFront);
            const auto isPassed = passBitboard == 0;
            if (isPassed)
            {
                score += passedPawnPst[GetRelativeInverse(color, pos)];
                TraceIncr(passedPawnPst[GetRelativeInverse(color, pos)]);

                // DOUBLED PASSED PAWNS
                score += ownPawnInFrontCount * doubledPassedPawnBonus;
                TraceAdd(doubledPassedPawnBonus, ownPawnInFrontCount);
            }

            pawns &= pawns - 1;
        }

        return score;
    }

    template<Color TColor, Piece TPiece>
    static PhaseScore EvaluatePiece(const BoardBase& board, const Data& data)
    {
        constexpr Color color = TColor;
        constexpr Color opponent = color ^ 1;
        constexpr Piece pieceNoColor = TPiece;
        constexpr Piece piece = pieceNoColor | color;
        constexpr PieceIndex pieceIndex = GetPieceIndex(piece);
        PhaseScore score = 0;

        Bitboard pieces = board.BitBoard[piece];
        while (pieces != 0)
        {
            const Position pos = BitScanForward(pieces);

            // MATERIAL AND PST
            score += MaterialAndPst[piece][pos];
            TraceIncr(material[pieceIndex]);
            TraceIncr(psts[pieceIndex][GetRelativeInverse(color, pos)]);

            // MOBILITY
            const Bitboard mobility = data.AttacksFrom[pos] & ~data.PieceAttacks[Pieces::Pawn | opponent];
            const uint8_t mobilityCount = PopCount(mobility);
            score += mobilityBonus[pieceIndex][mobilityCount];
            TraceIncr(mobilityBonus[pieceIndex][mobilityCount]);

            // KING ATTACKS
            const Bitboard opponentKingJumps = BitboardJumps.KingJumps[board.KingPositions[opponent]];
            const Bitboard kingAttacks = mobility & opponentKingJumps;
            const uint8_t kingAttackCount = PopCount(kingAttacks);
            score += kingAttackCount * kingAttackBonus[pieceIndex];
            TraceAdd(kingAttackBonus[pieceIndex], kingAttackCount);

            if constexpr (piece == Pieces::Bishop)
            {
                const Bitboard posBitboard = GetBitboard(pos);
                const Color squareColor = (posBitboard & BitboardConstants::ColoredSquares[Colors::White]) != 0 ? Colors::White : Colors::Black;
                const Bitboard sameColor = BitboardConstants::ColoredSquares[squareColor];

                // BISHOP SAME COLOR SQUARE OWN PAWNS
                const Bitboard sameColorOwnPawns = board.BitBoard[Pieces::Pawn | color] & sameColor;
                const uint8_t sameColorOwnPawnCount = PopCount(sameColorOwnPawns);
                score += bishopSameColorSquareOwnPawnBonus[sameColorOwnPawnCount];
                TraceIncr(bishopSameColorSquareOwnPawnBonus[sameColorOwnPawnCount]);

                // BISHOP SAME COLOR SQUARE OPPONENT PAWNS
                const Bitboard sameColorOpponentPawns = board.BitBoard[Pieces::Pawn | opponent] & sameColor;
                const uint8_t sameColorOpponentPawnCount = PopCount(sameColorOpponentPawns);
                score += bishopSameColorSquareOpponentPawnBonus[sameColorOpponentPawnCount];
                TraceIncr(bishopSameColorSquareOpponentPawnBonus[sameColorOpponentPawnCount]);
            }

            if constexpr (piece == Pieces::Rook)
            {
                const File sqCol = Files::Get(pos);
                const Bitboard file = BitboardConstants::Files[sqCol];
                const Bitboard ownPawnsOnFile = board.BitBoard[Pieces::Pawn | color] & file;
                if (ownPawnsOnFile == 0)
                {
                    const Bitboard opponentPawnsOnFile = board.BitBoard[Pieces::Pawn | opponent] & file;
                    if (opponentPawnsOnFile == 0)
                    {
                        // ROOK ON OPEN FILE
                        score += rookOpenFileBonus;
                        TraceIncr(rookOpenFileBonus);
                    }
                    else
                    {
                        // ROOK ON SEMI OPEN FILE
                        score += rookSemiOpenFileBonus;
                        TraceIncr(rookSemiOpenFileBonus);
                    }
                }
            }

            pieces &= pieces - 1;
        }

        return score;
    }

    template<Color TColor>
    static PhaseScore EvaluateKings(const BoardBase& board)
    {
        constexpr Color color = TColor;
        constexpr Piece pieceNoColor = Pieces::King;
        constexpr Piece piece = pieceNoColor | color;
        constexpr PieceIndex pieceIndex = GetPieceIndex(piece);
        PhaseScore score = 0;

        const Position pos = board.KingPositions[color];

        // PST
        score += MaterialAndPst[piece][pos];
        TraceIncr(psts[pieceIndex][GetRelativeInverse(color, pos)]);

        return score;
    }

    template<Color TColor>
    static PhaseScore EvaluateColor(const BoardBase& board, const Data& data)
    {
        constexpr Color color = TColor;
        PhaseScore score = 0;

        score += EvaluatePawns<TColor>(board, data);
        score += EvaluatePiece<TColor, Pieces::Knight>(board, data);
        score += EvaluatePiece<TColor, Pieces::Bishop>(board, data);
        score += EvaluatePiece<TColor, Pieces::Rook>(board, data);
        score += EvaluatePiece<TColor, Pieces::Queen>(board, data);
        score += EvaluateKings<TColor>(board);

        // BISHOP PAIR
        if (board.PieceCounts[Pieces::Bishop | color] == 2)
        {
            score += bishopPairBonus;
            TraceIncr(bishopPairBonus);
        }

        return score;
    }

    static PhaseScore EvaluatePhased(const BoardBase& board)
    {
        PhaseScore score = 0;

        Data data;
        GetData(board, data);

        score += EvaluateColor<Colors::White>(board, data);
        score -= EvaluateColor<Colors::Black>(board, data);

        return score;
    }

    static Score Evaluate(const BoardBase& board, const EachColor<Bitboard>& pins, EvalState& state)
    {
        const PhaseScore score = EvaluatePhased(board);

        TraceEval(score);
        const Phase phase = GetPhase(board);
        TracePhase(phase);
        const Score mg = MgScore(score);
        const Score eg = EgScore(score);
        const Score interpolated = static_cast<Score>((mg * phase + (24 - phase) * eg) / MaxPhase);
        const Score flipped = board.WhiteToMove ? interpolated : static_cast<Score>(-interpolated);

        // TEMPO
        const Score final = tune ? flipped : static_cast<Score>(flipped + 15);

        return final;
    }

    static void Init()
    {
        for (Piece piece = Pieces::Pawn; piece < Pieces::Count; piece++)
        {
            const auto pieceIndex = GetPieceIndex(piece);
            const Color color = piece & Colors::Mask;
            for (Position pos = 0; pos < Positions::Count; pos++)
            {
                const auto relativePos = GetRelativeInverse(color, pos);
                MaterialAndPst[piece][relativePos] = material[pieceIndex];
                MaterialAndPst[piece][relativePos] += psts[pieceIndex][pos];
            }
        }
    }
};