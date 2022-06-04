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
        std::array<TraceScores, 64> kingSafetyTable;
        //std::array<TraceScores, 6> kingAreaAttackBonus;
        std::array<TraceScores, 6> pinnedBonus;
        std::array<TraceScores, 6> protectedByPawnBonus;
        std::array<TraceScores, 6> behindPawnBonus;
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
        EachColor<uint8_t> KingAttackWeight;
        //EachColor<uint8_t> KingAttackCount;
    };

    using Trace = EvaluationClassical2Trace;
    using Data = EvaluationClassical2Data;

    static constexpr int ParameterCount = 6 + 6 * 64 + 64 + 6 * 28 + 2 * 6 * 6 + 64 + 4 * 6 + 2 * 9 + 8;

    static constexpr std::array<PhaseScore, 6> material =
    {
        S(100, 119), S(375, 356), S(468, 167), S(578, 610), S(1224, 906), S(  3,   4)
    };

    static constexpr std::array<std::array<PhaseScore, 64>, 6> psts =
    {{
        {
            S(  3,  25), S(  3,  25), S(  3,  25), S(  3,  25), S(  3,  25), S(  3,  25), S(  3,  25), S(  3,  25),
            S(138, 238), S(132, 308), S(-22,  -2), S( 47, -94), S( 18,  64), S(172,  75), S(-124, 101), S(-254, -14),
            S(-14,   2), S( -1, -10), S(-17,  -1), S(  2, -30), S(  9, -25), S( 78, -26), S( 48, -15), S( 13, -12),
            S(-22, -15), S( -7, -21), S(-12, -25), S(  6, -36), S(  8, -27), S(  2, -23), S(  3, -23), S(-23, -22),
            S(-30, -23), S(-22, -22), S(-11, -31), S( -1, -34), S(  7, -33), S(  5, -37), S( -2, -33), S(-28, -36),
            S(-28, -33), S(-25, -32), S(-21, -32), S(-18, -27), S( -6, -27), S( -5, -32), S( 17, -47), S(-19, -41),
            S(-26, -25), S(-17, -34), S(-23, -19), S( -6, -29), S( -5, -19), S( 29, -34), S( 25, -45), S(-10, -44),
            S(  3,  25), S(  3,  25), S(  3,  25), S(  3,  25), S(  3,  25), S(  3,  25), S(  3,  25), S(  3,  25)
        },
        {
            S(-147,  13), S(-102,  -3), S(-62,  20), S(-39,  -8), S( 59, -16), S(-105,   7), S(-46, -29), S(-89, -29),
            S(-79,  14), S(-57,  21), S( 18,  -9), S(  2,  15), S(-13,  10), S( 14, -11), S(-16,   6), S(-35, -10),
            S(-52,  -2), S( 22, -10), S(  9,  12), S( 26,  10), S( 44,   0), S( 88, -11), S( 43, -13), S( 47, -29),
            S(  9,   0), S( 23,  -0), S(  6,  17), S( 49,  17), S( 40,  13), S( 54,   4), S( 28,   2), S( 45,  -5),
            S(  9,  -1), S( 21,  -9), S( 11,  11), S( 16,  20), S( 25,  16), S( 23,  10), S( 29,   3), S( 20,   1),
            S(  1,  -8), S( -7,   2), S(  7,  -6), S(  2,  14), S( 19,   9), S(  8,  -4), S( 28, -16), S(  3,  -5),
            S(  4, -11), S(-24,   1), S( -7,  -0), S( 22,  -2), S( 19,   0), S( 26, -12), S( 10,  -3), S( 15, -14),
            S(-79,  43), S( 14, -11), S(-28,   0), S(-18,  13), S( 20,  -2), S( -5,   3), S( 18, -15), S( 18, -22)
        },
        {
            S(-24,   0), S(-14,  -2), S(-128,  16), S(-91,  16), S(-54,  11), S(-63,  12), S(-20,   7), S( -7,  -2),
            S(-28,  12), S(-24,   5), S(-45,  12), S(-54,  -0), S( -7,   5), S( -7,   7), S(-38,  11), S(-78,  14),
            S( -5,   5), S( 12,  -7), S( -1,  -2), S(  2,  -5), S(-10,  -1), S( 33,  -2), S( 10,  -0), S( 11,  11),
            S(  2,   1), S( -4,  -3), S( -5,   4), S( 26,  -4), S(  8,   1), S( 14,  -1), S(  1,  -6), S(  6,   5),
            S(  4,  -4), S( 12,  -7), S( 15,  -4), S( 13,   3), S( 28, -12), S( 10,  -3), S( 11, -12), S( 14,  -2),
            S( 12,  -2), S( 25,  -9), S( 17,   1), S( 20,  -1), S( 22,   0), S( 37, -16), S( 23, -11), S( 25,  -9),
            S( 25,  -1), S( 27, -11), S( 27,  -7), S( 17,   1), S( 24,   1), S( 29, -10), S( 48, -19), S( 24, -16),
            S( -7,   3), S( 23,   7), S( 21,   4), S( 13,   4), S( 22,   1), S( 14,  -0), S(-21,  13), S(  5,  -0)
        },
        {
            S(-17,  19), S(-11,  15), S(-62,  35), S(  2,  15), S(  9,  15), S(-48,  27), S(  3,  13), S(-27,  19),
            S(  5,  10), S( 12,  10), S( 37,   3), S( 48,  -0), S( 59, -13), S( 32,   1), S(-15,  16), S(  2,   9),
            S(-12,   6), S(  3,   5), S(  4,   2), S(  2,   4), S(-22,   5), S( 41, -12), S( 59, -15), S(  4,  -6),
            S(-22,   5), S( -8,  -0), S( -2,   9), S(  3,  -3), S(  7,  -2), S( 33,  -6), S( -2,  -7), S(-11,   1),
            S(-32,   7), S(-20,   5), S(-16,   8), S(-10,   1), S(  7,  -8), S( -1,  -7), S( 18, -12), S(-18,  -6),
            S(-30,   1), S(-15,   0), S(-11,  -6), S(-14,  -2), S(  2,  -9), S( 15, -17), S(  7, -10), S(-20, -10),
            S(-25,  -1), S( -7,  -5), S(-14,   1), S(  1,  -2), S( 12, -13), S( 23, -16), S(  4, -15), S(-45,   4),
            S(  4,  -6), S(  5,  -3), S(  9,  -1), S( 21,  -9), S( 26, -12), S( 22,  -9), S(-12,  -0), S(  8, -23)
        },
        {
            S(-18, -20), S(-48,  44), S(-49,  46), S(-56,  38), S( 60, -12), S( 51, -11), S( 45, -14), S( 34,  21),
            S(-16, -14), S(-41,  10), S(-13,  17), S( -3,  30), S(-78,  76), S(-17,  19), S(-16,  13), S( 34,  12),
            S(  1, -18), S(-13,  -9), S(-12, -10), S(-41,  51), S(-36,  40), S( 28,   2), S(-14,  16), S( 20,   1),
            S(-25,  24), S(-19,  11), S(-18,   1), S(-34,  25), S(-36,  47), S(-19,  11), S(-21,  47), S(-11,  31),
            S(  6, -13), S(-21,  19), S(  5,  -5), S( -4,  17), S(  0,   5), S(  1,  -1), S(  9,  15), S( -3,  22),
            S( -0,  -1), S( 24, -52), S(  8, -11), S( 20, -23), S( 13, -11), S( 19,  -7), S( 28,  -4), S( 22,  10),
            S( -7, -10), S(  6, -30), S( 24, -33), S( 24, -33), S( 30, -28), S( 32, -34), S( 14, -45), S( 28, -36),
            S( 21, -37), S( 21, -41), S( 23, -31), S( 32, -36), S( 21, -18), S(  2, -17), S(  6, -25), S(-20, -32)
        },
        {
            S(-223, -53), S(126, -66), S(159, -51), S( 58, -37), S(-154,  13), S(-78,  25), S( 52, -12), S( 40, -25),
            S(160, -51), S( 75,  -2), S( 27,   7), S(113,  -2), S( -0,  15), S( 54,  22), S(-14,  16), S(-148,  29),
            S( 67, -14), S( 98,  -3), S(131,  -3), S( 21,  12), S( 69,   5), S(114,  20), S(150,   9), S(-14,   2),
            S( 22, -21), S( 11,   9), S( 31,  16), S(-18,  30), S(-10,  23), S(-16,  29), S(  5,  13), S(-99,   9),
            S(-88,  -7), S( 47, -15), S(-36,  27), S(-86,  40), S(-92,  44), S(-53,  29), S(-50,  14), S(-92,  -3),
            S(-16, -19), S(  8,  -1), S(-26,  21), S(-48,  33), S(-53,  35), S(-36,  27), S( -3,  11), S(-48,  -2),
            S( 13, -35), S( 25,  -9), S(-12,  14), S(-71,  28), S(-48,  28), S(-23,  17), S( 20,  -2), S( 12, -21),
            S(-34, -56), S( 42, -42), S( 13, -20), S(-77,   6), S( -3, -18), S(-40,   0), S( 31, -30), S( 11, -58)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-63, -17), S( -2, -108), S( 84, 193), S( 54, 253), S( 46, 118), S(-20,  81), S(140, 109), S(207, 254),
        S( 40, 153), S(  3, 161), S( 39, 125), S( 14, 126), S( 38, 103), S( -1, 119), S(-38, 143), S(-44, 156),
        S( 19,  88), S(  0,  81), S( 15,  67), S( -2,  61), S( -0,  50), S( 31,  52), S( -9,  82), S( -4,  79),
        S(  3,  51), S(-18,  47), S(-22,  42), S(-23,  36), S(-20,  38), S(-23,  44), S(-21,  55), S(  9,  50),
        S( -5,  23), S(-19,  30), S(-14,  23), S(-35,  28), S(-12,  20), S( 24,  14), S( -0,  32), S( 15,  20),
        S(-12,  19), S(  4,  23), S(  9,  13), S(-36,  36), S(-21,  25), S(  6,  18), S( 12,  24), S(-20,  28),
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
            S(-77, -242), S(-16, -157), S( -6, -115), S(  2, -85), S( 19, -79), S( 26, -69), S( 33, -62), S( 44, -58),
            S( 55, -61), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  3, -64), S(-61, -50), S(-49,  -5), S(-35,  15), S(-24,  26), S(-15,  35), S(-10,  44), S( -3,  49),
            S( -1,  55), S(  3,  61), S(  6,  64), S( 28,  63), S(  7,  82), S( 32,  70), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(214,  56), S(-71, -117), S(-72, -135), S(-63, -108), S(-56, -85), S(-50, -78), S(-43, -67), S(-39, -62),
            S(-32, -61), S(-23, -60), S(-16, -57), S( -8, -54), S(  2, -51), S(  6, -49), S( 33, -59), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  3,   3), S(-46, -118), S(-12, -222), S(-10, -93), S(-11,   3), S( -2,  -0),
            S( -1,   4), S(  6,   7), S(  8,  25), S( 10,  37), S( 13,  49), S( 17,  56), S( 20,  63), S( 18,  83),
            S( 22,  81), S( 18, 100), S( 20,  98), S( 26, 109), S( 24, 122), S( 45, 116), S( 32, 128), S( 64, 115),
            S( 37, 134), S(138,  74), S(-20, 162), S(411, -63)
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
            S( -4,  12), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( -5,   7), S(  0,   0), S(  0,   0), S(  0,   0), S( 20,   6), S( 72,  11)
        },
        {
            S(-19,  22), S(  0,   0), S(  0,   0), S(  0,   0), S( 39,  -7), S(235, -54)
        },
        {
            S( -5,   8), S(  0,   0), S(-16,  -7), S(-25,  16), S(  0,   0), S(121, 142)
        },
        {
            S(-19,  42), S(  0,   0), S(-74, -10), S(-233,  56), S(-118, -140), S(  0,   0)
        },
    }};

    static constexpr std::array<std::array<PhaseScore, 6>, 6> attackUnattackedBonus =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( -5,  10), S(  0,   0), S( 23,  17), S( 54, -12), S( 24, -33), S(101,   1)
        },
        {
            S(  1,   7), S( 23,  29), S(  0,   0), S( 33,  -0), S(  0,   0), S( 69,  58)
        },
        {
            S(-17,  14), S(  9,   8), S( 16,  14), S(  0,   0), S(  0,   0), S(129,   7)
        },
        {
            S( -3,   5), S( -1,   1), S( -3,  24), S( -9,   5), S(  0,   0), S( 57,  95)
        },
        {
            S(-25,  41), S(-29,  15), S(-23,  23), S(-41,  30), S(  0,   0), S(  0,   0)
        },
    }};

    static constexpr std::array<PhaseScore, 64> kingSafetyTable =
    {
        S(-114,   4), S(  0,   0), S(-112,   2), S(-124, -13), S(-110,  -1), S(-114,   1), S(-104,  -9), S(-109,   2),
        S(-94,  -8), S(-97,   0), S(-112,  -1), S(-80, -15), S(-104,   3), S(-64, -14), S(-95,  10), S(-97,   8),
        S(-56, -17), S(-68,  -3), S(-52,  -8), S(-14, -16), S(-78,   9), S( -3, -33), S(-59,  39), S( 28, -59),
        S(-10,   9), S(-50,  12), S( 61, -28), S( -7,  14), S( 14, -15), S( 95, -41), S( 73, -50), S(168, -101),
        S(290, -196), S(143,  45), S(252, -97), S(135, -93), S(269, -149), S(230, -65), S(346, -31), S(237, -48),
        S(134,  58), S( 16, 168), S(164, 253), S(267, 200), S(417, 239), S(280, -47), S(352, 256), S(148, -34),
        S( 73,  35), S(162,  28), S(-105,  36), S(  0,   0), S(-80, -35), S(  0,   0), S( 67,  14), S(  1,   1),
        S(  0,   0), S(  0,   0), S(  0,   0), S( -0,  -0), S( -0,  -0), S(  0,   0), S(  0,   0), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> pinnedBonus =
    {
        S(  0,   0), S(-26, -58), S(-15, -63), S(-65, -45), S(-74, -55), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> protectedByPawnBonus =
    {
        S(  0,   0), S(  7,   4), S( -2,  21), S(  2,  -3), S(-11,  11), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> behindPawnBonus =
    {
        S(  0,   0), S(  4,  11), S(  5,   6), S(  4,  -3), S(  2, -14), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> outpostBonus =
    {
        S(  0,   0), S( 19,  15), S( 39,  -6), S( 20,  13), S( 20,   3), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOwnPawnBonus =
    {
        S(  1,  62), S( -9,  59), S( -8,  49), S(-19,  46), S(-26,  38), S(-34,  27), S(-47,  27), S(-62,  -3),
        S(-23, -165)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOpponentPawnBonus =
    {
        S( 15,  25), S(-15,  40), S(-17,  43), S(-27,  46), S(-34,  47), S(-39,  45), S(-49,  53), S(-63,  46),
        S(-27, -94)
    };

    static constexpr PhaseScore doubledPawnBonus = S(-9, -13);
    static constexpr PhaseScore doubledPassedPawnBonus = S(-7, -30);
    static constexpr PhaseScore blockedPassedPawnBonus = S(13, -35);
    static constexpr PhaseScore protectedPawnBonus = S(14, 11);
    static constexpr PhaseScore weakPawnBonus = S(-10, -8);
    static constexpr PhaseScore bishopPairBonus = S(36, 42);
    static constexpr PhaseScore rookOpenFileBonus = S(48, -3);
    static constexpr PhaseScore rookSemiOpenFileBonus = S(29, -3);

    static constexpr std::array<uint8_t, 6> kingAttackWeights =
    {
        0, 2, 2, 3, 5, 0
    };

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

        data.KingAttackWeight[TColor] = 0;
        //data.KingAttackCount[TColor] = 0;
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
    static PhaseScore EvaluatePiece(const BoardBase& board, Data& data)
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

            // KING SAFETY - COUNTING
            const Position opponentKingPos = board.KingPositions[opponent];
            const Bitboard opponentKingPosBitboard = GetBitboard(opponentKingPos);
            const Bitboard opponentKingJumps = BitboardJumps.KingExtendedJumps[opponent][opponentKingPos];
            const Bitboard opponentKingZone = opponentKingPosBitboard | opponentKingJumps;
            const Bitboard kingAttacks = attacks & opponentKingZone;
            const uint8_t kingAttackCount = PopCount(kingAttacks);
            data.KingAttackWeight[color] += kingAttackCount * kingAttackWeights[pieceIndex];

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

            // BEHIND PAWN
            const Bitboard oneInFront = color == Colors::White ? posBitboard << 8 : posBitboard >> 8;
            const Bitboard ownPawns = board.BitBoard[Pieces::Pawn | color];
            const bool isPawnInFront = (oneInFront & ownPawns) != 0;
            if (isPawnInFront)
            {
                score += behindPawnBonus[pieceIndex];
                TraceIncr(behindPawnBonus[pieceIndex]);
            }

            // OUTPOST
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
                const Bitboard sameColorOwnPawns = ownPawns & sameColor;
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

                attackedOpponent &= attackedOpponent - 1;
            }

            pieces &= pieces - 1;
        }

        return score;
    }

    template<Color TColor>
    static PhaseScore EvaluateKings(const BoardBase& board, const Data& data)
    {
        constexpr Color color = TColor;
        constexpr Color opponent = color ^ 1;
        constexpr Piece pieceNoColor = Pieces::King;
        constexpr Piece piece = pieceNoColor | color;
        constexpr PieceIndex pieceIndex = GetPieceIndex(piece);
        PhaseScore score = 0;

        const Position pos = board.KingPositions[color];

        // PST
        score += MaterialAndPst[piece][pos];
        TraceIncr(psts[pieceIndex][GetRelativeInverse(color, pos)]);

        // KING SAFETY - APPLYING
        uint8_t tableIndex = data.KingAttackWeight[color];
        if (tableIndex >= kingSafetyTable.size())
        {
            tableIndex = kingSafetyTable.size() - 1;
        }
        score += kingSafetyTable[tableIndex];
        TraceIncr(kingSafetyTable[tableIndex]);

        // ATTACKS
        const Bitboard attacks = data.AttacksFrom[pos];
        const Bitboard posBitboard = GetBitboard(pos);
        Bitboard attackedOpponent = attacks & board.BitBoard[opponent];
        while (attackedOpponent)
        {
            const Position attackedPos = BitScanForward(attackedOpponent);
            if (attackedPos != board.KingPositions[opponent]) // For some reason checks don't gain
            {
                const Piece attackedPiece = board.ArrayBoard[attackedPos];
                const uint8_t attackedPieceIndex = GetPieceIndex(attackedPiece);
                const Bitboard attackedAttacks = data.AttacksFrom[attackedPos];
                const bool isAttackedBack = (attackedAttacks & posBitboard) != 0;

                if (isAttackedBack)
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

        return score;
    }

    template<Color TColor>
    static PhaseScore EvaluateColor(const BoardBase& board, Data& data)
    {
        constexpr Color color = TColor;
        PhaseScore score = 0;

        score += EvaluatePawns<TColor>(board, data);
        score += EvaluatePiece<TColor, Pieces::Knight>(board, data);
        score += EvaluatePiece<TColor, Pieces::Bishop>(board, data);
        score += EvaluatePiece<TColor, Pieces::Rook>(board, data);
        score += EvaluatePiece<TColor, Pieces::Queen>(board, data);
        score += EvaluateKings<TColor>(board, data);

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