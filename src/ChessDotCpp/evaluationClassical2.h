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
        S(100, 119), S(378, 369), S(484, 161), S(589, 621), S(1241, 912), S(  2,   4)
    };

    static constexpr std::array<std::array<PhaseScore, 64>, 6> psts =
    {{
        {
            S(  4,  26), S(  4,  26), S(  4,  26), S(  4,  26), S(  4,  26), S(  4,  26), S(  4,  26), S(  4,  26),
            S(143, 244), S(131, 326), S(-27, -10), S( 39, -114), S( 13,  56), S(136,  79), S(-136,  97), S(-275, -34),
            S(-14,   3), S(  0, -10), S(-19,   0), S(  7, -31), S( 15, -14), S( 78, -26), S( 51, -15), S( 14, -10),
            S(-20, -15), S( -6, -21), S(-11, -24), S(  8, -36), S(  9, -27), S(  4, -23), S(  5, -22), S(-21, -21),
            S(-28, -23), S(-21, -22), S( -9, -31), S(  1, -34), S(  8, -33), S(  6, -37), S( -1, -33), S(-26, -36),
            S(-27, -33), S(-24, -32), S(-20, -31), S(-16, -26), S( -5, -27), S( -5, -32), S( 18, -47), S(-18, -41),
            S(-25, -25), S(-15, -33), S(-21, -19), S( -4, -29), S( -3, -18), S( 31, -34), S( 27, -45), S( -9, -43),
            S(  4,  26), S(  4,  26), S(  4,  26), S(  4,  26), S(  4,  26), S(  4,  26), S(  4,  26), S(  4,  26)
        },
        {
            S(-148,  12), S(-106,  -3), S(-66,  20), S(-36,  -9), S( 59, -17), S(-100,   7), S(-50, -28), S(-88, -30),
            S(-79,  13), S(-56,  20), S( 18,  -9), S(  6,  15), S( -9,   9), S( 14, -10), S(-15,   6), S(-36, -10),
            S(-51,  -3), S( 24, -10), S( 10,  12), S( 27,   9), S( 47,  -1), S( 90, -11), S( 44, -13), S( 48, -29),
            S(  9,   0), S( 23,   0), S(  5,  18), S( 50,  17), S( 41,  13), S( 55,   5), S( 29,   3), S( 46,  -5),
            S(  8,  -1), S( 20,  -9), S( 11,  12), S( 16,  21), S( 25,  16), S( 23,  11), S( 30,   4), S( 20,   2),
            S( -1,  -9), S( -8,   3), S(  6,  -6), S(  1,  13), S( 19,   9), S(  8,  -4), S( 28, -16), S(  2,  -6),
            S(  3, -12), S(-23,   1), S( -8,  -1), S( 22,  -2), S( 18,   0), S( 25, -11), S(  8,  -3), S( 15, -13),
            S(-80,  43), S( 12, -11), S(-29,   1), S(-20,  13), S( 19,  -2), S( -6,   3), S( 16, -16), S( 16, -20)
        },
        {
            S(-29,   2), S(-17,  -3), S(-126,  15), S(-96,  16), S(-58,  11), S(-69,  12), S(-28,   8), S(-10,  -2),
            S(-32,  14), S(-24,   4), S(-49,  13), S(-58,  -0), S( -8,   5), S(-11,   7), S(-38,  11), S(-81,  14),
            S( 11,   0), S( 15,  -8), S(  6,  -5), S(  4,  -6), S(  3,  -5), S( 52,  -6), S( 31,  -4), S( 32,   7),
            S(  2,   1), S(  1,  -4), S( -6,   4), S( 27,  -4), S(  7,   2), S( 22,  -2), S(  4,  -5), S( 10,   6),
            S(  3,  -3), S( 13,  -7), S( 16,  -4), S( 14,   3), S( 32, -12), S(  7,  -1), S( 11, -10), S( 15,  -2),
            S(  9,  -1), S( 22,  -9), S( 14,   1), S( 17,  -1), S( 19,   1), S( 35, -15), S( 20,  -9), S( 22,  -7),
            S( 23,  -1), S( 24, -11), S( 24,  -7), S( 14,   2), S( 20,   1), S( 27,  -9), S( 45, -18), S( 21, -15),
            S( -9,   3), S( 20,   6), S( 17,   5), S( 10,   5), S( 20,   2), S( 10,   1), S(-26,  14), S(  3,   0)
        },
        {
            S(-16,  20), S(-10,  16), S(-63,  36), S(  2,  15), S( 11,  15), S(-47,  27), S(  3,  13), S(-28,  19),
            S(  5,  10), S( 12,  10), S( 37,   3), S( 50,  -1), S( 60, -12), S( 35,   1), S(-16,  16), S(  3,   8),
            S(-13,   6), S(  3,   5), S(  5,   2), S(  1,   4), S(-23,   5), S( 44, -12), S( 60, -15), S(  2,  -6),
            S(-23,   5), S(-10,  -0), S( -3,   9), S(  4,  -2), S(  6,  -1), S( 33,  -6), S( -3,  -7), S(-11,   1),
            S(-33,   8), S(-22,   7), S(-17,   8), S(-10,   1), S(  7,  -8), S( -1,  -8), S( 18, -13), S(-19,  -5),
            S(-30,   2), S(-16,   0), S(-11,  -6), S(-14,  -2), S(  1,  -9), S( 17, -18), S(  7, -11), S(-20, -11),
            S(-25,  -1), S( -8,  -5), S(-14,   0), S(  2,  -3), S( 12, -13), S( 25, -17), S(  5, -16), S(-45,   4),
            S(  4,  -6), S(  5,  -3), S(  9,  -1), S( 21, -10), S( 26, -13), S( 22,  -9), S(-12,  -1), S(  7, -23)
        },
        {
            S(-21, -19), S(-50,  44), S(-51,  48), S(-58,  39), S( 61, -12), S( 51, -12), S( 49, -16), S( 33,  22),
            S(-17, -14), S(-43,  12), S(-16,  19), S( -1,  29), S(-79,  78), S(-18,  19), S(-19,  17), S( 35,  11),
            S(  4, -22), S( -9, -12), S(-10, -13), S(-43,  52), S(-32,  38), S( 31,   1), S( -1,   9), S( 23,   3),
            S(-26,  25), S(-16,   9), S(-18,   2), S(-33,  25), S(-37,  49), S(-13,   9), S(-19,  47), S( -7,  25),
            S(  5, -12), S(-21,  19), S(  7,  -5), S( -6,  19), S(  2,   4), S(  1,  -0), S( 10,  15), S( -4,  23),
            S( -2,  -0), S( 23, -52), S(  6, -11), S( 19, -23), S( 13, -12), S( 18,  -6), S( 27,  -3), S( 21,  11),
            S( -9,  -9), S(  6, -30), S( 23, -33), S( 22, -32), S( 29, -28), S( 32, -35), S( 14, -45), S( 28, -36),
            S( 18, -35), S( 19, -41), S( 21, -30), S( 30, -35), S( 20, -18), S( -0, -17), S(  6, -24), S(-26, -29)
        },
        {
            S(-223, -54), S(131, -67), S(162, -51), S( 61, -37), S(-155,  13), S(-78,  24), S( 55, -13), S( 43, -25),
            S(162, -51), S( 75,  -2), S( 28,   7), S(114,  -2), S(  0,  15), S( 54,  22), S(-14,  16), S(-147,  29),
            S( 66, -14), S( 96,  -3), S(131,  -3), S( 19,  13), S( 70,   5), S(114,  20), S(147,   9), S(-15,   2),
            S( 22, -22), S(  9,  10), S( 29,  17), S(-18,  30), S(-11,  23), S(-20,  30), S(  2,  13), S(-102,   9),
            S(-91,  -6), S( 48, -15), S(-35,  27), S(-87,  40), S(-94,  44), S(-56,  30), S(-51,  14), S(-94,  -2),
            S(-18, -19), S(  9,  -1), S(-26,  21), S(-48,  33), S(-53,  36), S(-35,  27), S( -3,  12), S(-47,  -2),
            S( 14, -35), S( 27,  -9), S(-12,  14), S(-71,  28), S(-47,  28), S(-22,  18), S( 21,  -2), S( 13, -22),
            S(-34, -57), S( 43, -43), S( 14, -20), S(-77,   5), S( -3, -18), S(-39,   0), S( 33, -30), S( 14, -59)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-69, -20), S( -4, -123), S( 88, 205), S( 55, 277), S( 55, 129), S(-83, 101), S(155, 115), S(228, 276),
        S( 40, 154), S(  3, 164), S( 40, 126), S(  9, 128), S( 34,  94), S( -1, 120), S(-42, 145), S(-43, 156),
        S( 17,  89), S( -2,  82), S( 14,  68), S( -4,  63), S( -1,  50), S( 28,  53), S(-10,  82), S( -5,  80),
        S(  2,  51), S(-20,  48), S(-23,  42), S(-25,  37), S(-22,  39), S(-25,  45), S(-21,  56), S(  7,  51),
        S( -6,  23), S(-21,  31), S(-14,  23), S(-35,  28), S(-14,  20), S( 23,  14), S(  0,  32), S( 15,  21),
        S(-13,  19), S(  2,  23), S(  8,  14), S(-40,  37), S(-26,  27), S(  4,  19), S( 10,  24), S(-21,  28),
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
            S(-77, -253), S(-12, -167), S( -3, -124), S(  6, -94), S( 23, -88), S( 30, -78), S( 37, -71), S( 48, -67),
            S( 59, -70), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( -1, -56), S(-65, -51), S(-51,  -4), S(-37,  16), S(-26,  27), S(-16,  36), S(-11,  45), S( -5,  51),
            S( -2,  57), S(  1,  62), S(  5,  66), S( 26,  64), S(  4,  84), S( 30,  71), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(217,  54), S(-65, -121), S(-74, -140), S(-66, -113), S(-58, -90), S(-52, -83), S(-45, -72), S(-42, -67),
            S(-35, -67), S(-26, -65), S(-18, -63), S(-11, -59), S(  1, -56), S(  5, -54), S( 32, -64), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  3,   3), S(-47, -114), S( -9, -223), S( -9, -92), S(-10,   7), S( -1,   5),
            S( -0,   6), S(  7,  12), S(  9,  30), S( 11,  42), S( 14,  54), S( 18,  62), S( 21,  68), S( 19,  89),
            S( 23,  87), S( 19, 106), S( 20, 103), S( 26, 115), S( 25, 128), S( 45, 122), S( 35, 133), S( 63, 121),
            S( 42, 136), S(141,  78), S(-23, 169), S(426, -65)
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
            S(-44, -24), S(  0,   0), S(  0,   0), S(  0,   0), S( 19,   7), S( 74,  10)
        },
        {
            S(-19,  22), S(  0,   0), S(  0,   0), S(  0,   0), S( 37,  -5), S(238, -55)
        },
        {
            S(-45,   3), S(  0,   0), S(-15,  -7), S(-25,  16), S(  0,   0), S(126, 135)
        },
        {
            S(-308,  24), S(  0,   0), S(-75,  -8), S(-236,  57), S(-122, -133), S(  0,   0)
        },
    }};

    static constexpr std::array<std::array<PhaseScore, 6>, 6> attackUnattackedBonus =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( -5,  10), S(  0,   0), S( 22,  16), S( 54, -12), S( 23, -34), S(102,   1)
        },
        {
            S(  2,   9), S( 22,  29), S(  0,   0), S( 30,  -0), S(  0,   0), S( 62,  60)
        },
        {
            S(-17,  16), S(  9,   8), S( 15,  14), S(  0,   0), S(  0,   0), S(130,   7)
        },
        {
            S( -2,   5), S( -1,   1), S( -3,  23), S(-10,   8), S(  0,   0), S( 55,  98)
        },
        {
            S( -8,  40), S(-29,  15), S(-23,  22), S(-42,  30), S(  0,   0), S(  0,   0)
        },
    }};

    static constexpr std::array<PhaseScore, 64> kingSafetyTable =
    {
        S(-118,   6), S(  0,   0), S(-117,   4), S(-129, -11), S(-116,   1), S(-119,   2), S(-110,  -8), S(-115,   3),
        S(-101,  -7), S(-103,   2), S(-117,   1), S(-86, -13), S(-110,   5), S(-71, -12), S(-101,  12), S(-102,  10),
        S(-63, -15), S(-74,  -0), S(-58,  -6), S(-20, -15), S(-84,  11), S( -9, -31), S(-65,  43), S( 26, -59),
        S(-16,  12), S(-54,  12), S( 58, -30), S( -8,  14), S(  8, -11), S( 94, -44), S( 71, -49), S(173, -108),
        S(292, -202), S(141,  48), S(249, -97), S(134, -93), S(291, -176), S(244, -85), S(400, -126), S(282, -99),
        S(134,  52), S(-16, 210), S(146, 288), S(279, 222), S(462, 206), S(365, -133), S(427, 305), S(188, -73),
        S( 93,  45), S(198,  34), S(-144,  62), S(  0,   0), S(-100, -44), S(  0,   0), S( 83,  17), S(  1,   1),
        S(  0,   0), S(  0,   0), S(  0,   0), S( -0,  -0), S( -0,  -0), S(  0,   0), S(  0,   0), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> pinnedBonus =
    {
        S(  0,   0), S(-23, -60), S(-14, -63), S(-66, -46), S(-75, -53), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> protectedByPawnBonus =
    {
        S(  0,   0), S(  6,   4), S( -3,  21), S(  2,  -3), S(-12,  12), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> behindPawnBonus =
    {
        S(  0,   0), S(  5,  11), S(  5,   6), S(  4,  -3), S(  2, -15), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> outpostBonus =
    {
        S(  0,   0), S( 19,  15), S( 41,  -7), S( 20,  14), S( 22,   1), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOwnPawnBonus =
    {
        S( -2,  66), S(-12,  62), S(-11,  52), S(-21,  49), S(-28,  41), S(-36,  30), S(-49,  30), S(-66,   2),
        S(-25, -160)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOpponentPawnBonus =
    {
        S( 11,  29), S(-19,  44), S(-22,  47), S(-31,  50), S(-37,  51), S(-43,  49), S(-53,  57), S(-68,  52),
        S(-30, -90)
    };

    static constexpr PhaseScore doubledPawnBonus = S(-10, -13);
    static constexpr PhaseScore doubledPassedPawnBonus = S(-6, -30);
    static constexpr PhaseScore blockedPassedPawnBonus = S(14, -36);
    static constexpr PhaseScore protectedPawnBonus = S(14, 11);
    static constexpr PhaseScore weakPawnBonus = S(-10, -8);
    static constexpr PhaseScore bishopPairBonus = S(38, 43);
    static constexpr PhaseScore rookOpenFileBonus = S(49, -3);
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
            if constexpr (TPiece == Pieces::Pawn)
            {
                attack = BitboardJumps.PawnJumps[TColor][position];
            }
            else if constexpr (TPiece == Pieces::Knight)
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
        GetDataForPieces<TColor, Pieces::Pawn>(board, data);
        GetDataForPieces<TColor, Pieces::Knight>(board, data);
        GetDataForPieces<TColor, Pieces::Bishop>(board, data);
        GetDataForPieces<TColor, Pieces::Rook>(board, data);
        GetDataForPieces<TColor, Pieces::Queen>(board, data);
        GetDataForPieces<TColor, Pieces::King>(board, data);

        //constexpr Piece coloredPawn = Pieces::Pawn | TColor;
        //constexpr bool forWhite = TColor == Colors::White;
        //const Bitboard pawnAttacks = AttacksGenerator::GetAttackedByPawns(board.BitBoard[coloredPawn], forWhite);
        //data.PieceAttacks[coloredPawn] = pawnAttacks;
        //data.PieceAttacks[TColor] |= pawnAttacks;

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

    static Score GetScaledEndgame(const BoardBase& board, PhaseScore score)
    {
        const Score unscaledEndgame = EgScore(score);

        if constexpr (tune)
        {
            return unscaledEndgame;
        }

        // ENDGAME SCALING - PAWN COUNT
        const Color strongerColor = score > 0 ? Colors::White : Colors::Black;
        const uint8_t strongerColorPawnCount = PopCount(board.BitBoard[Pieces::Pawn | strongerColor]);
        const int8_t stringerColorPawnsMissing = static_cast<int8_t>(8 - strongerColorPawnCount);
        constexpr int32_t maxScale = 128;
        const int32_t scale = maxScale - stringerColorPawnsMissing * stringerColorPawnsMissing;
        const Score scaledEndgame = static_cast<Score>((unscaledEndgame * scale) / maxScale);
        return scaledEndgame;
    }

    static Score EvaluateInner(const BoardBase& board, const EachColor<Bitboard>& pins)
    {
        const PhaseScore score = EvaluatePhased(board, pins);

        TraceEval(score);
        const Phase phase = GetPhase(board);
        TracePhase(phase);
        const Score midgame = MgScore(score);
        const Score endgame = GetScaledEndgame(board, score);

        const Score interpolated = static_cast<Score>((midgame * phase + (24 - phase) * endgame) / MaxPhase);
        const Score flipped = board.WhiteToMove ? interpolated : static_cast<Score>(-interpolated);

        // TEMPO
        const Score final = tune ? flipped : static_cast<Score>(flipped + 15);

        return final;
    }

    static Score Evaluate(const BoardBase& board, const EachColor<Bitboard>& pins)
    {
        return EvaluateInner(board, pins);
    }

    static Score Evaluate(const BoardBase& board, const EachColor<Bitboard>& pins, EvalState& state)
    {
        return EvaluateInner(board, pins);
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