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
        std::array<std::array<TraceScores, 6>, 6> attackAttackedBonus;
        std::array<std::array<TraceScores, 6>, 6> attackUnattackedBonus;
        std::array<TraceScores, 6> kingAreaAttackBonus;
        std::array<TraceScores, 6> pinnedBonus;
        std::array<TraceScores, 6> protectedByPawnBonus;
        std::array<TraceScores, 6> outpostBonus;
        std::array<TraceScores, 9> bishopSameColorSquareOwnPawnBonus;
        std::array<TraceScores, 9> bishopSameColorSquareOpponentPawnBonus;
        TraceScores doubledPawnBonus;
        TraceScores doubledPassedPawnBonus;
        TraceScores blockedPassedPawnBonus;
        TraceScores protectedPawnBonus;
        TraceScores weakPawnBonus;
        TraceScores bishopPairBonus;
        TraceScores rookOpenFileBonus;
        TraceScores rookSemiOpenFileBonus;
    };

    class EvaluationClassical2Data
    {
    public:
        EachPiece<Bitboard> PieceAttacks;
        EachPosition<Bitboard> AttacksFrom;
        EachColor<Bitboard> Pins;
    };

    using Trace = EvaluationClassical2Trace;
    using Data = EvaluationClassical2Data;

    static constexpr int ParameterCount = 6 + 6 * 64 + 64 + 6 * 28 + 2 * 6 * 6 + 4 * 6 + 2 * 9 + 8;

    static constexpr std::array<PhaseScore, 6> material =
    {
        S(100, 115), S(374, 290), S(381, 248), S(514, 522), S(1157, 877), S(  4,   4)
    };

    static constexpr std::array<std::array<PhaseScore, 64>, 6> psts =
    {{
        {
            S( -2,  21), S( -2,  21), S( -2,  21), S( -2,  21), S( -2,  21), S( -2,  21), S( -2,  21), S( -2,  21),
            S(105, 193), S(135, 227), S( 14,  69), S( 73,  22), S( 45, 104), S(148,  88), S(-35, 120), S(-139, 101),
            S(-17,  -5), S( -3, -18), S(-19,  -9), S(  5, -39), S(  3, -21), S( 74, -37), S( 38, -23), S(  9, -19),
            S(-26, -20), S(-12, -26), S(-15, -31), S(  1, -41), S(  2, -32), S( -0, -32), S( -2, -30), S(-26, -27),
            S(-34, -27), S(-27, -26), S(-15, -36), S( -6, -37), S(  1, -37), S(  0, -41), S( -8, -38), S(-30, -40),
            S(-33, -35), S(-29, -35), S(-25, -35), S(-23, -29), S(-12, -30), S(-12, -35), S( 11, -49), S(-22, -44),
            S(-29, -29), S(-20, -37), S(-27, -23), S(-11, -32), S(-12, -22), S( 24, -37), S( 18, -47), S(-12, -47),
            S( -2,  21), S( -2,  21), S( -2,  21), S( -2,  21), S( -2,  21), S( -2,  21), S( -2,  21), S( -2,  21)
        },
        {
            S(-142,  15), S(-97,  -1), S(-59,  18), S(-42,  -5), S( 57, -12), S(-76,   4), S(-33, -26), S(-85, -25),
            S(-70,  12), S(-55,  20), S( 37, -15), S( -2,  16), S( 15,   4), S( 22, -12), S( 11,  -1), S(-26,  -7),
            S(-51,  -2), S( 19, -10), S( -3,  14), S( 19,  11), S( 31,   4), S( 94, -12), S( 24,  -6), S( 56, -27),
            S(  4,   1), S( 21,  -1), S(  1,  16), S( 41,  17), S( 22,  19), S( 48,   5), S( 14,   7), S( 37,  -2),
            S(  5,  -2), S( 18, -10), S( 10,   9), S( 14,  17), S( 26,  12), S( 24,   7), S( 33,   2), S( 18,   3),
            S( -1,  -8), S( -9,  -0), S(  5,  -7), S(  1,  11), S( 15,   8), S(  6,  -6), S( 25, -16), S(  2,  -6),
            S(  2, -10), S(-26,   2), S( -8,  -2), S( 19,  -4), S( 15,  -1), S( 24, -12), S( 10,  -3), S( 14, -10),
            S(-79,  40), S( 11, -10), S(-31,   1), S(-19,  10), S( 16,  -3), S( -3,   2), S( 16, -12), S( 14, -17)
        },
        {
            S(-23,  -1), S( -5,  -4), S(-129,  16), S(-91,  15), S(-56,  10), S(-62,   9), S(-21,   4), S( -4,  -3),
            S(-25,  12), S(-23,   4), S(-43,  11), S(-43,  -3), S(-11,   5), S( 27,  -6), S(-43,  12), S(-47,   6),
            S( -5,   4), S(  7,  -5), S(  7,  -5), S( -8,  -2), S(-11,  -2), S( 15,  -0), S( -1,   0), S( -0,  11),
            S(  0,   3), S( -5,  -1), S(-10,   6), S( 18,  -2), S(  8,  -1), S( 12,  -2), S( -0,  -6), S(  1,   5),
            S(  2,  -3), S(  6,  -4), S( 12,  -3), S( 12,   3), S( 26, -10), S( 14,  -4), S( 12, -12), S( 14,  -3),
            S(  8,  -0), S( 22,  -8), S( 18,   1), S( 20,  -0), S( 24,   2), S( 36, -13), S( 24, -10), S( 23,  -6),
            S( 25,  -1), S( 28, -10), S( 27,  -6), S( 19,   1), S( 25,   2), S( 31,  -7), S( 48, -16), S( 26, -14),
            S( -9,   3), S( 23,   5), S( 20,   5), S( 12,   4), S( 18,   2), S( 15,   2), S(-16,  13), S(  8,  -1)
        },
        {
            S(-27,  20), S(-21,  17), S(-61,  33), S( -6,  16), S( -8,  19), S(-44,  25), S(-15,  17), S(-20,  16),
            S( -7,  11), S(  0,  11), S( 21,   5), S( 26,   3), S( 42, -10), S( 32,  -0), S(-14,  15), S( -3,  10),
            S( -8,   5), S(  7,   4), S( 13,  -0), S( 14,  -0), S(-10,   1), S( 39, -11), S( 60, -14), S( 11,  -7),
            S(-16,   5), S( -5,  -0), S(  3,   7), S(  6,  -3), S( 14,  -3), S( 34,  -6), S(  4,  -7), S( -5,   1),
            S(-25,   5), S(-17,   5), S(-12,   7), S( -8,   1), S(  9,  -7), S( -4,  -5), S( 18, -11), S(-15,  -5),
            S(-25,   0), S(-12,  -0), S( -9,  -5), S(-13,  -2), S(  2,  -8), S( 11, -15), S(  8,  -9), S(-16, -11),
            S(-20,  -3), S( -3,  -6), S(-13,   1), S(  1,  -2), S( 12, -12), S( 24, -16), S(  8, -16), S(-40,   3),
            S(  5,  -7), S(  6,  -4), S(  9,  -2), S( 19,  -9), S( 24, -12), S( 22, -11), S(-10,  -1), S(  8, -22)
        },
        {
            S(-22, -24), S(-46,  34), S(-25,  23), S(-40,  29), S( 75, -28), S( 62, -24), S( 43, -20), S( 45,   4),
            S(-23, -22), S(-49,   7), S(-27,  17), S(-18,  29), S(-70,  62), S( 24,  -5), S( -4,  23), S( 42,  -5),
            S(  2, -18), S( -8,  -9), S( 14, -23), S(-31,  48), S(  4,  25), S( 51,  -7), S( 21,   6), S( 40,   1),
            S(-31,  28), S(-23,  19), S(-27,  11), S(-31,  26), S(-13,  32), S( -3,  15), S( -9,  56), S( -8,  48),
            S( -2,  -9), S(-32,  26), S( -5,   0), S( -8,  17), S( -6,  11), S(  1,   9), S(  2,  24), S( -2,  29),
            S(-13,   1), S( 14, -47), S( -1,  -9), S(  9, -19), S(  5,  -3), S(  9,   1), S( 20,  -1), S( 12,  16),
            S(-18, -10), S( -2, -28), S( 14, -32), S( 14, -26), S( 20, -22), S( 23, -29), S(  8, -41), S( 19, -31),
            S(  9, -32), S(  9, -36), S( 11, -23), S( 20, -30), S(  8,  -9), S( -7, -17), S( -6, -17), S(-34, -22)
        },
        {
            S(-157, -57), S(146, -66), S(149, -49), S( 65, -36), S(-117,  10), S(-67,  23), S( 40,  -8), S( 25, -23),
            S(167, -51), S( 85,  -2), S( 45,   3), S(109,  -4), S( 42,   9), S( 48,  25), S( -7,  21), S(-133,  29),
            S( 60,  -9), S( 86,   4), S(112,   2), S( 23,  12), S( 56,   8), S(117,  26), S(140,  18), S(-11,   7),
            S( 15, -18), S(  2,  16), S( 25,  19), S(-20,  30), S(-26,  29), S(-25,  36), S(  3,  24), S(-85,  13),
            S(-74,  -8), S( 36, -10), S(-38,  26), S(-90,  38), S(-94,  42), S(-65,  33), S(-63,  19), S(-92,   1),
            S( -6, -21), S(  0,  -3), S(-29,  17), S(-58,  29), S(-62,  32), S(-52,  26), S(-14,  10), S(-46,  -4),
            S( 10, -35), S( 23, -13), S(-18,   9), S(-72,  21), S(-51,  21), S(-30,  12), S( 12,  -6), S( 10, -24),
            S(-25, -58), S( 38, -45), S( 10, -24), S(-73,  -2), S( -5, -23), S(-37,  -7), S( 29, -35), S( 14, -61)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-40,   6), S(-19, -50), S( 38,  98), S( 13, 115), S( 19,  49), S(-10,  42), S( 42,  62), S( 79, 114),
        S( 32, 142), S(  0, 152), S( 33, 115), S(  6, 116), S( 37,  80), S( -4, 109), S(-38, 132), S(-44, 144),
        S( 15,  82), S(  0,  75), S( 12,  62), S( -3,  57), S(  1,  44), S( 26,  47), S( -6,  74), S( -9,  74),
        S(  1,  47), S(-19,  44), S(-22,  39), S(-22,  34), S(-17,  35), S(-20,  39), S(-16,  50), S(  9,  46),
        S( -7,  21), S(-18,  28), S(-16,  23), S(-35,  28), S(-11,  19), S( 23,  13), S(  6,  28), S( 16,  19),
        S(-13,  18), S(  1,  22), S(  7,  13), S(-39,  35), S(-15,  24), S(  2,  19), S( 14,  22), S(-19,  27),
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
            S(-89, -183), S(-37, -105), S(-28, -65), S(-20, -36), S( -5, -29), S(  1, -19), S(  8, -12), S( 18,  -9),
            S( 28, -10), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 19, -66), S(-44, -58), S(-34, -16), S(-21,   2), S(-11,  12), S( -4,  21), S(  0,  28), S(  6,  33),
            S(  8,  39), S( 11,  43), S( 15,  46), S( 33,  45), S( 14,  62), S( 37,  49), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(146,  50), S(-42, -63), S(-44, -79), S(-38, -55), S(-31, -33), S(-26, -26), S(-20, -15), S(-17, -11),
            S(-11, -10), S( -3,  -7), S(  4,  -5), S( 10,  -1), S( 18,   2), S( 20,   6), S( 39,  -1), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(-65, -129), S(-19, -263), S(-17, -119), S(-20, -38), S(-12, -35),
            S(-13, -35), S( -6, -27), S( -5, -11), S( -4,   0), S( -1,  13), S(  3,  18), S(  5,  25), S(  4,  40),
            S(  7,  40), S(  5,  57), S(  7,  52), S( 15,  60), S( 14,  71), S( 32,  65), S( 22,  76), S( 35,  69),
            S( 28,  76), S(127,  13), S(  1,  85), S(261, -56)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
    }};

    static constexpr std::array<std::array<PhaseScore, 6>, 6> attackAttackedBonus =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( -4,  11), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( -5,   6), S(  0,   0), S(  0,   0), S(  0,   0), S( 17,   4), S(  0,   0)
        },
        {
            S(-18,  18), S(  0,   0), S(  0,   0), S(  0,   0), S( 31, -11), S(  0,   0)
        },
        {
            S( -6,   7), S(  0,   0), S(-19,  -5), S(-30,  12), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
    }};

    static constexpr std::array<std::array<PhaseScore, 6>, 6> attackUnattackedBonus =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( -5,   9), S(  0,   0), S( 22,  16), S( 52, -12), S( 23, -28), S(  0,   0)
        },
        {
            S(  1,   6), S( 22,  26), S(  0,   0), S( 31,   1), S(  0,   0), S(  0,   0)
        },
        {
            S(-16,  11), S(  8,   7), S( 16,  11), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( -4,   3), S( -2,   3), S( -3,  20), S( -9,   5), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
    }};

    static constexpr std::array<PhaseScore, 6> kingAreaAttackBonus =
    {
        S(  0,   0), S( 15, -10), S( 19,  -4), S( 26,  -7), S( 16,   6), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> pinnedBonus =
    {
        S(  0,   0), S(-20, -53), S( -6, -58), S(-49, -40), S(-58, -58), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> protectedByPawnBonus =
    {
        S(  0,   0), S(  5,   4), S( -2,  19), S(  3,  -3), S( -9,   7), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> outpostBonus =
    {
        S(  0,   0), S( 18,  14), S( 35,  -6), S( 16,  14), S( 17,   2), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOwnPawnBonus =
    {
        S( 25,  20), S( 14,  16), S( 15,   7), S(  6,   3), S( -2,  -5), S( -8, -16), S(-22, -16), S(-35, -44),
        S(-30, -105)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOpponentPawnBonus =
    {
        S( 36, -20), S(  7,  -5), S(  4,  -2), S( -5,   1), S(-11,   2), S(-16,  -0), S(-26,   8), S(-37,   3),
        S(-32, -47)
    };

    static constexpr PhaseScore doubledPawnBonus = S(-9, -11);
    static constexpr PhaseScore doubledPassedPawnBonus = S(-7, -26);
    static constexpr PhaseScore blockedPassedPawnBonus = S(15, -36);
    static constexpr PhaseScore protectedPawnBonus = S(13, 9);
    static constexpr PhaseScore weakPawnBonus = S(-9, -8);
    static constexpr PhaseScore bishopPairBonus = S(32, 41);
    static constexpr PhaseScore rookOpenFileBonus = S(44, -3);
    static constexpr PhaseScore rookSemiOpenFileBonus = S(27, -3);

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

    static void GetData(const BoardBase& board, const EachColor<Bitboard>& pins, Data& data)
    {
        GetDataForColor<Colors::White>(board, data);
        GetDataForColor<Colors::Black>(board, data);
        data.Pins = pins;
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

                // BLOCKED PASSED PAWNS
                const Bitboard opponentInFront = inFront & board.BitBoard[opponent];
                const bool isBlocked = opponentInFront != 0;
                if(isBlocked)
                {
                    score += blockedPassedPawnBonus;
                    TraceIncr(blockedPassedPawnBonus);
                }
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
            const Bitboard posBitboard = GetBitboard(pos);

            // MATERIAL AND PST
            score += MaterialAndPst[piece][pos];
            TraceIncr(material[pieceIndex]);
            TraceIncr(psts[pieceIndex][GetRelativeInverse(color, pos)]);

            // MOBILITY
            const Bitboard attacks = data.AttacksFrom[pos];
            const Bitboard mobility = attacks & ~data.PieceAttacks[Pieces::Pawn | opponent];
            const uint8_t mobilityCount = PopCount(mobility);
            score += mobilityBonus[pieceIndex][mobilityCount];
            TraceIncr(mobilityBonus[pieceIndex][mobilityCount]);

            // KING ATTACKS
            const Bitboard opponentKingJumps = BitboardJumps.KingJumps[board.KingPositions[opponent]];
            const Bitboard kingAttacks = mobility & opponentKingJumps;
            const uint8_t kingAttackCount = PopCount(kingAttacks);
            score += kingAttackCount * kingAreaAttackBonus[pieceIndex];
            TraceAdd(kingAreaAttackBonus[pieceIndex], kingAttackCount);

            // PINS
            const bool isPinned = data.Pins[color] & posBitboard;
            if(isPinned)
            {
                score += pinnedBonus[pieceIndex];
                TraceIncr(pinnedBonus[pieceIndex]);
            }

            // PROTECTED BY PAWN
            const Bitboard ownPawnControl = data.PieceAttacks[Pieces::Pawn | color];
            const bool isProtected = (posBitboard & ownPawnControl) != 0;
            if(isProtected)
            {
                score += protectedByPawnBonus[pieceIndex];
                TraceIncr(protectedByPawnBonus[pieceIndex]);
            }

            const Bitboard opponentPawnControl = data.PieceAttacks[Pieces::Pawn | opponent];
            const Bitboard inFront = InFront.ColumnInFront[color][pos];
            const bool isPotentialOutpost = (inFront & opponentPawnControl) == 0;
            const bool isOutpost = isPotentialOutpost && isProtected;
            if (isOutpost)
            {
                score += outpostBonus[pieceIndex];
                TraceIncr(outpostBonus[pieceIndex]);
            }

            // BISHOP EVAL
            if constexpr (pieceNoColor == Pieces::Bishop)
            {
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

            // ROOK EVAL
            if constexpr (pieceNoColor == Pieces::Rook)
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

            // ATTACKS
            Bitboard attackedOpponent = attacks & board.BitBoard[opponent];
            while (attackedOpponent)
            {
                const Position attackedPos = BitScanForward(attackedOpponent);
                if(attackedPos != board.KingPositions[opponent]) // For some reason checks don't gain
                {
                    const Piece attackedPiece = board.ArrayBoard[attackedPos];
                    const uint8_t attackedPieceIndex = GetPieceIndex(attackedPiece);
                    const Bitboard attackedAttacks = data.AttacksFrom[attackedPos];
                    const bool isAttackedBack = (attackedAttacks & posBitboard) != 0;

                    if(isAttackedBack)
                    {
                        // ATTACKING A PIECE WHICH IS ATTACKING BACK
                        score += attackAttackedBonus[pieceIndex][attackedPieceIndex];
                        TraceIncr(attackAttackedBonus[pieceIndex][attackedPieceIndex]);
                    }
                    else
                    {
                        // ATTACKING A PIECE WHICH IS NOT ATTACKING BACK
                        score += attackUnattackedBonus[pieceIndex][attackedPieceIndex];
                        TraceIncr(attackUnattackedBonus[pieceIndex][attackedPieceIndex]);
                    }
                }

                attackedOpponent &= attackedOpponent - 1;
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

    static PhaseScore EvaluatePhased(const BoardBase& board, const EachColor<Bitboard>& pins)
    {
        PhaseScore score = 0;

        Data data;
        GetData(board, pins, data);

        score += EvaluateColor<Colors::White>(board, data);
        score -= EvaluateColor<Colors::Black>(board, data);

        return score;
    }

    static Score Evaluate(const BoardBase& board, const EachColor<Bitboard>& pins, EvalState& state)
    {
        const PhaseScore score = EvaluatePhased(board, pins);

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