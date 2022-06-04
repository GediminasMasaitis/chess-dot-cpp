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
    };

    using Trace = EvaluationClassical2Trace;
    using Data = EvaluationClassical2Data;

    static constexpr int ParameterCount = 6 + 6 * 64 + 64 + 6 * 28 + 2 * 6 * 6 + 5 * 6 + 2 * 9 + 8;

    static constexpr std::array<PhaseScore, 6> material =
    {
        S(100, 121), S(378, 321), S(420, 226), S(542, 570), S(1207, 902), S(  3,   4)
    };

    static constexpr std::array<std::array<PhaseScore, 64>, 6> psts =
    {{
        {
            S( -1,  24), S( -1,  24), S( -1,  24), S( -1,  24), S( -1,  24), S( -1,  24), S( -1,  24), S( -1,  24),
            S(117, 213), S(136, 262), S(  4,  49), S( 65, -19), S( 32,  92), S(163,  97), S(-59, 128), S(-186,  65),
            S(-17,  -4), S( -3, -17), S(-18,  -7), S(  6, -36), S(  9, -17), S( 77, -33), S( 42, -19), S( 10, -17),
            S(-24, -21), S(-10, -26), S(-14, -30), S(  4, -41), S(  5, -32), S(  2, -29), S( -0, -27), S(-25, -27),
            S(-33, -28), S(-25, -27), S(-14, -36), S( -4, -38), S(  4, -38), S(  1, -41), S( -5, -38), S(-30, -41),
            S(-31, -38), S(-28, -37), S(-24, -37), S(-22, -31), S(-11, -32), S(-10, -36), S( 12, -51), S(-21, -46),
            S(-29, -30), S(-20, -39), S(-27, -25), S( -9, -34), S(-10, -24), S( 25, -39), S( 20, -49), S(-12, -49),
            S( -1,  24), S( -1,  24), S( -1,  24), S( -1,  24), S( -1,  24), S( -1,  24), S( -1,  24), S( -1,  24)
        },
        {
            S(-143,  13), S(-102,  -1), S(-59,  21), S(-40,  -5), S( 62, -14), S(-100,  10), S(-36, -27), S(-89, -27),
            S(-76,  13), S(-53,  20), S( 17,  -8), S( -1,  17), S(-14,  12), S( 10,  -9), S(-18,   7), S(-37,  -7),
            S(-50,  -3), S( 25, -12), S(  1,  14), S( 18,  12), S( 34,   4), S( 79,  -8), S( 28,  -8), S( 43, -26),
            S(  8,   1), S( 26,  -2), S(  4,  17), S( 47,  17), S( 26,  19), S( 51,   6), S( 17,   7), S( 43,  -3),
            S( 10,  -2), S( 22, -11), S( 15,   9), S( 19,  17), S( 32,  12), S( 28,   8), S( 38,   1), S( 23,   1),
            S(  3, -10), S( -6,   0), S(  8,  -8), S(  3,  11), S( 19,   7), S( 10,  -7), S( 29, -18), S(  6,  -7),
            S(  4, -12), S(-23,   1), S( -6,  -3), S( 23,  -4), S( 19,  -2), S( 27, -14), S( 10,  -3), S( 17, -14),
            S(-74,  40), S( 15, -12), S(-28,  -0), S(-16,  10), S( 21,  -4), S( -2,   1), S( 19, -17), S( 18, -21)
        },
        {
            S(-19,  -0), S( -7,  -4), S(-124,  14), S(-84,  14), S(-65,  12), S(-75,  13), S(-22,   5), S(  1,  -5),
            S(-26,  12), S(-20,   5), S(-41,  13), S(-49,  -1), S(-10,   5), S( -9,   6), S(-42,  13), S(-72,  11),
            S( -2,   4), S( 10,  -5), S(  0,  -2), S( -7,  -3), S(-21,   1), S( 17,   0), S( -1,   1), S(  3,  11),
            S(  3,   2), S( -5,  -1), S( -8,   5), S( 19,  -2), S(  9,  -1), S( 14,  -2), S(  2,  -7), S(  1,   5),
            S(  5,  -4), S( 10,  -6), S( 15,  -3), S( 14,   3), S( 29, -11), S( 16,  -4), S( 14, -12), S( 18,  -5),
            S(  9,  -2), S( 25,  -9), S( 19,   1), S( 21,  -0), S( 25,   1), S( 39, -14), S( 26, -11), S( 27,  -9),
            S( 24,  -3), S( 29, -12), S( 28,  -7), S( 20,   2), S( 27,   1), S( 32,  -8), S( 50, -18), S( 27, -16),
            S( -6,   2), S( 24,   5), S( 22,   4), S( 14,   5), S( 21,   3), S( 16,   0), S(-17,  12), S(  9,  -1)
        },
        {
            S(-26,  21), S(-25,  18), S(-72,  36), S( -9,  16), S(-12,  20), S(-61,  30), S(-11,  16), S(-24,  17),
            S( -4,  10), S(  2,  10), S( 25,   4), S( 34,   0), S( 43, -11), S( 18,   3), S(-34,  20), S( -9,  11),
            S( -4,   4), S( 11,   2), S( 15,  -1), S( 17,  -1), S( -7,   0), S( 42, -12), S( 58, -14), S( 11,  -9),
            S(-15,   4), S( -2,  -2), S(  5,   7), S(  9,  -3), S( 14,  -2), S( 37,  -7), S(  1,  -7), S( -6,   0),
            S(-26,   6), S(-16,   6), S(-11,   7), S( -6,   1), S( 10,  -7), S( -2,  -6), S( 18, -12), S(-14,  -6),
            S(-26,   1), S(-12,   0), S( -8,  -6), S(-12,  -2), S(  3,  -9), S( 13, -16), S(  9, -10), S(-16, -11),
            S(-21,  -1), S( -3,  -5), S(-12,   1), S(  3,  -2), S( 14, -13), S( 25, -16), S( 10, -16), S(-41,   3),
            S(  7,  -6), S(  8,  -3), S( 11,  -1), S( 23,  -9), S( 27, -12), S( 24, -10), S( -8,  -1), S( 11, -23)
        },
        {
            S(-26, -24), S(-57,  36), S(-40,  32), S(-45,  27), S( 55, -18), S( 60, -30), S( 45, -22), S( 35,  10),
            S(-21, -24), S(-47,   4), S(-25,  16), S(-17,  31), S(-74,  67), S( -1,  -1), S(-22,  12), S( 28,   4),
            S(  4, -20), S( -6,  -9), S(  2, -16), S(-27,  45), S( -9,  26), S( 56, -11), S( 19,   0), S( 45, -11),
            S(-29,  30), S(-23,  21), S(-23,   9), S(-30,  22), S(-18,  36), S(  2,   8), S( -6,  54), S( -6,  42),
            S(  0,  -7), S(-30,  25), S( -2,  -0), S( -3,  16), S( -4,  12), S(  5,   7), S(  7,  22), S(  2,  25),
            S(-10,   2), S( 18, -49), S(  3,  -9), S( 13, -18), S(  9,  -3), S( 13,   2), S( 24,   0), S( 18,  14),
            S(-16,  -8), S(  1, -27), S( 17, -30), S( 18, -25), S( 24, -20), S( 26, -27), S(  8, -38), S( 23, -34),
            S( 12, -32), S( 12, -36), S( 15, -23), S( 25, -30), S( 12,  -8), S( -5, -11), S( -3, -15), S(-32, -22)
        },
        {
            S(-187, -55), S(149, -68), S(162, -50), S( 64, -36), S(-120,   9), S(-77,  25), S( 45,  -9), S( 30, -22),
            S(162, -50), S( 88,  -4), S( 44,   4), S(118,  -3), S( 24,  10), S( 60,  20), S(  2,  13), S(-132,  27),
            S( 64, -13), S(100,  -4), S(122,  -2), S( 17,  12), S( 54,   6), S(108,  19), S(140,   9), S(-16,   3),
            S( 15, -19), S(  8,   8), S( 25,  16), S(-20,  29), S(-24,  23), S(-26,  29), S(  3,  12), S(-99,  10),
            S(-86,  -5), S( 41, -14), S(-41,  27), S(-98,  40), S(-98,  43), S(-60,  30), S(-56,  14), S(-91,  -1),
            S(-10, -19), S(  1,   0), S(-30,  21), S(-59,  34), S(-62,  36), S(-48,  29), S(-11,  13), S(-46,  -1),
            S( 12, -32), S( 26, -10), S(-17,  15), S(-73,  28), S(-52,  28), S(-29,  18), S( 16,  -1), S( 12, -20),
            S(-27, -56), S( 41, -42), S( 14, -20), S(-76,   5), S( -3, -19), S(-38,  -1), S( 32, -31), S( 15, -58)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-49,  -4), S(-19, -72), S( 50, 134), S( 29, 170), S( 32,  78), S(-20,  50), S( 69,  72), S(129, 164),
        S( 37, 149), S(  3, 158), S( 35, 122), S(  7, 123), S( 35,  87), S( -4, 116), S(-37, 138), S(-43, 151),
        S( 18,  86), S(  0,  79), S( 14,  66), S( -3,  61), S(  1,  48), S( 27,  51), S( -6,  79), S( -6,  78),
        S(  3,  49), S(-18,  46), S(-21,  40), S(-23,  35), S(-20,  37), S(-21,  42), S(-20,  53), S( 10,  49),
        S( -5,  22), S(-19,  30), S(-13,  22), S(-35,  28), S(-11,  19), S( 24,  13), S(  6,  29), S( 18,  19),
        S(-12,  18), S(  3,  22), S(  9,  13), S(-40,  36), S(-16,  23), S(  3,  18), S( 14,  22), S(-17,  27),
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
            S(-87, -217), S(-34, -125), S(-24, -83), S(-16, -54), S( -0, -47), S(  6, -36), S( 13, -30), S( 23, -26),
            S( 34, -28), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 11, -73), S(-51, -57), S(-41, -14), S(-27,   6), S(-16,  16), S( -8,  25), S( -4,  33), S(  2,  38),
            S(  4,  43), S(  8,  48), S( 11,  51), S( 31,  49), S(  7,  68), S( 31,  56), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(191,  61), S(-57, -87), S(-59, -104), S(-51, -76), S(-43, -54), S(-37, -47), S(-31, -37), S(-28, -33),
            S(-21, -32), S(-12, -30), S( -5, -28), S(  2, -24), S( 11, -21), S( 12, -17), S( 36, -26), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  1,   1), S(-53, -146), S(-16, -252), S(-16, -107), S(-18, -25), S(-10, -25),
            S(-10, -22), S( -3, -17), S( -1,  -2), S( -0,  10), S(  3,  23), S(  6,  28), S(  9,  34), S(  7,  52),
            S( 10,  50), S(  9,  67), S(  9,  64), S( 16,  74), S( 16,  85), S( 36,  77), S( 27,  87), S( 48,  76),
            S( 21,  93), S(127,  28), S(-13, 111), S(347, -83)
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
            S( -5,   6), S(  0,   0), S(  0,   0), S(  0,   0), S( 21,   5), S( 82,   7)
        },
        {
            S(-19,  20), S(  0,   0), S(  0,   0), S(  0,   0), S( 34, -10), S(251, -56)
        },
        {
            S( -6,   8), S(  0,   0), S(-16,  -3), S(-28,  14), S(  0,   0), S(167, 182)
        },
        {
            S(-16,  42), S(  0,   0), S(-82,  -8), S(-247,  61), S(-165, -181), S(  0,   0)
        },
    }};

    static constexpr std::array<std::array<PhaseScore, 6>, 6> attackUnattackedBonus =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( -5,  10), S(  0,   0), S( 22,  17), S( 53, -11), S( 24, -31), S(110,  -4)
        },
        {
            S(  1,   6), S( 24,  27), S(  0,   0), S( 32,   1), S(  0,   0), S( 66,  56)
        },
        {
            S(-17,  12), S(  8,   8), S( 15,  12), S(  0,   0), S(  0,   0), S(140,  -1)
        },
        {
            S( -4,   4), S( -2,   2), S( -4,  23), S( -8,   5), S(  0,   0), S( 69,  95)
        },
        {
            S(-25,  41), S(-31,  14), S(-26,  25), S(-38,  21), S(  0,   0), S(  0,   0)
        },
    }};

    static constexpr std::array<PhaseScore, 6> kingAreaAttackBonus =
    {
        S(  0,   0), S( 16,  -9), S( 19,  -3), S( 26,  -7), S( 16,   7), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> pinnedBonus =
    {
        S(  0,   0), S(-23, -55), S(-10, -60), S(-58, -40), S(-63, -63), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> protectedByPawnBonus =
    {
        S(  0,   0), S(  7,   4), S( -2,  20), S(  2,  -2), S(-10,  10), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> behindPawnBonus =
    {
        S(  0,   0), S(  4,  11), S(  4,   6), S(  4,  -3), S(  2, -17), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> outpostBonus =
    {
        S(  0,   0), S( 18,  14), S( 36,  -6), S( 18,  13), S( 18,   3), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOwnPawnBonus =
    {
        S( 15,  33), S(  3,  30), S(  4,  21), S( -6,  18), S(-13,  11), S(-20,   0), S(-34,   0), S(-47, -26),
        S(-13, -171)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOpponentPawnBonus =
    {
        S( 28,  -4), S( -3,  11), S( -6,  14), S(-16,  17), S(-22,  18), S(-28,  17), S(-38,  24), S(-51,  20),
        S(-20, -104)
    };

    static constexpr PhaseScore doubledPawnBonus = S(-9, -13);
    static constexpr PhaseScore doubledPassedPawnBonus = S(-7, -29);
    static constexpr PhaseScore blockedPassedPawnBonus = S(13, -34);
    static constexpr PhaseScore protectedPawnBonus = S(14, 10);
    static constexpr PhaseScore weakPawnBonus = S(-10, -8);
    static constexpr PhaseScore bishopPairBonus = S(34, 42);
    static constexpr PhaseScore rookOpenFileBonus = S(47, -3);
    static constexpr PhaseScore rookSemiOpenFileBonus = S(28, -2);

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
    static PhaseScore EvaluateColor(const BoardBase& board, const Data& data)
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