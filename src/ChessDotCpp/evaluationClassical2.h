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
        S(100, 117), S(376, 294), S(388, 249), S(520, 531), S(1173, 887), S(  4,   4)
    };

    static constexpr std::array<std::array<PhaseScore, 64>, 6> psts =
    {{
        {
            S( -2,  22), S( -2,  22), S( -2,  22), S( -2,  22), S( -2,  22), S( -2,  22), S( -2,  22), S( -2,  22),
            S(105, 195), S(137, 233), S( 14,  69), S( 73,  19), S( 45, 104), S(150,  88), S(-36, 123), S(-143,  99),
            S(-16,  -5), S( -3, -19), S(-19, -11), S(  5, -38), S(  3, -22), S( 76, -38), S( 39, -23), S(  9, -19),
            S(-25, -20), S(-11, -27), S(-15, -31), S(  1, -42), S(  3, -33), S(  1, -32), S( -1, -30), S(-25, -28),
            S(-33, -27), S(-26, -27), S(-16, -36), S( -6, -38), S(  1, -37), S( -0, -41), S( -6, -38), S(-30, -40),
            S(-32, -36), S(-29, -36), S(-25, -35), S(-24, -30), S(-13, -31), S(-11, -35), S( 10, -49), S(-21, -45),
            S(-30, -29), S(-21, -37), S(-28, -23), S(-11, -31), S(-12, -22), S( 23, -37), S( 18, -47), S(-13, -47),
            S( -2,  22), S( -2,  22), S( -2,  22), S( -2,  22), S( -2,  22), S( -2,  22), S( -2,  22), S( -2,  22)
        },
        {
            S(-144,  16), S(-99,  -0), S(-60,  19), S(-43,  -4), S( 58, -11), S(-78,   5), S(-34, -26), S(-87, -25),
            S(-70,  13), S(-54,  20), S( 38, -14), S( -2,  17), S( 16,   4), S( 23, -12), S( 12,  -0), S(-27,  -6),
            S(-51,  -1), S( 20, -10), S( -3,  14), S( 20,  11), S( 32,   5), S( 97, -12), S( 26,  -6), S( 57, -27),
            S(  4,   1), S( 22,  -1), S(  1,  16), S( 42,  17), S( 23,  19), S( 50,   6), S( 14,   7), S( 38,  -2),
            S(  6,  -1), S( 18, -10), S( 11,   9), S( 15,  17), S( 27,  12), S( 25,   7), S( 33,   2), S( 19,   3),
            S( -1,  -9), S( -9,  -0), S(  4,  -8), S( -0,  11), S( 15,   7), S(  6,  -6), S( 25, -17), S(  2,  -7),
            S(  1, -11), S(-27,   1), S( -9,  -2), S( 19,  -4), S( 15,  -2), S( 24, -13), S(  8,  -4), S( 13, -12),
            S(-80,  40), S( 11, -12), S(-32,   1), S(-18,  11), S( 17,  -3), S( -5,   1), S( 16, -16), S( 13, -17)
        },
        {
            S(-24,  -0), S( -7,  -3), S(-132,  17), S(-92,  15), S(-58,  11), S(-63,   9), S(-22,   5), S( -4,  -3),
            S(-25,  12), S(-22,   5), S(-43,  12), S(-42,  -2), S(-11,   5), S( 28,  -6), S(-43,  13), S(-47,   6),
            S( -4,   5), S(  8,  -5), S(  7,  -5), S( -8,  -2), S(-10,  -2), S( 17,  -1), S( -1,   1), S(  0,  11),
            S(  1,   3), S( -4,  -1), S( -9,   6), S( 19,  -2), S(  8,  -1), S( 12,  -2), S(  0,  -6), S(  2,   5),
            S(  2,  -3), S(  6,  -4), S( 13,  -3), S( 12,   3), S( 26, -10), S( 14,  -4), S( 13, -12), S( 15,  -3),
            S(  7,  -1), S( 23,  -9), S( 18,   1), S( 19,  -0), S( 23,   1), S( 37, -14), S( 25, -11), S( 24,  -8),
            S( 23,  -2), S( 27, -11), S( 26,  -7), S( 19,   1), S( 25,   1), S( 30,  -9), S( 47, -17), S( 24, -15),
            S( -9,   3), S( 22,   5), S( 20,   5), S( 14,   5), S( 19,   3), S( 14,   0), S(-18,  12), S(  8,  -2)
        },
        {
            S(-27,  21), S(-22,  17), S(-62,  33), S( -6,  16), S( -8,  20), S(-43,  25), S(-15,  17), S(-20,  16),
            S( -6,  11), S(  1,  11), S( 22,   5), S( 27,   3), S( 43, -10), S( 34,  -1), S(-14,  15), S( -2,  10),
            S( -8,   5), S(  8,   4), S( 13,  -0), S( 15,  -1), S( -8,   1), S( 40, -11), S( 62, -15), S( 12,  -7),
            S(-16,   5), S( -6,  -0), S(  3,   7), S(  7,  -3), S( 14,  -3), S( 35,  -6), S(  4,  -7), S( -5,   1),
            S(-26,   6), S(-17,   5), S(-12,   7), S( -8,   1), S(  9,  -7), S( -4,  -6), S( 18, -11), S(-16,  -5),
            S(-27,   1), S(-13,  -0), S(-10,  -6), S(-13,  -2), S(  1,  -8), S( 10, -15), S(  7,  -9), S(-17, -11),
            S(-22,  -2), S( -4,  -6), S(-14,   1), S(  1,  -2), S( 12, -12), S( 23, -15), S(  8, -16), S(-41,   2),
            S(  5,  -7), S(  6,  -3), S(  9,  -2), S( 20, -10), S( 25, -12), S( 21, -10), S(-10,  -1), S(  8, -23)
        },
        {
            S(-24, -24), S(-48,  34), S(-24,  23), S(-39,  29), S( 76, -28), S( 63, -26), S( 43, -21), S( 44,   4),
            S(-23, -23), S(-49,   7), S(-27,  17), S(-18,  30), S(-70,  63), S( 25,  -5), S( -5,  23), S( 42,  -5),
            S(  2, -20), S( -8, -10), S( 16, -24), S(-31,  49), S(  6,  26), S( 52,  -8), S( 21,   6), S( 40,  -0),
            S(-31,  27), S(-23,  19), S(-27,  12), S(-31,  27), S(-13,  33), S( -2,  15), S( -9,  57), S( -9,  47),
            S( -2, -10), S(-33,  26), S( -5,   1), S( -7,  18), S( -5,  13), S(  1,  10), S(  3,  23), S( -2,  28),
            S(-13,   1), S( 14, -48), S( -1,  -8), S(  9, -16), S(  5,  -2), S(  9,   2), S( 20,  -1), S( 12,  16),
            S(-19, -10), S( -3, -27), S( 13, -30), S( 14, -27), S( 20, -21), S( 22, -28), S(  6, -39), S( 18, -31),
            S(  8, -33), S(  9, -37), S( 11, -25), S( 20, -32), S(  8, -11), S( -8, -14), S( -7, -16), S(-34, -24)
        },
        {
            S(-160, -57), S(148, -67), S(151, -50), S( 66, -36), S(-118,  10), S(-68,  24), S( 41,  -8), S( 26, -23),
            S(169, -52), S( 86,  -2), S( 45,   3), S(111,  -4), S( 42,  10), S( 49,  25), S( -8,  21), S(-134,  30),
            S( 61, -10), S( 86,   4), S(113,   2), S( 23,  12), S( 56,   9), S(118,  27), S(141,  18), S(-12,   7),
            S( 15, -18), S(  1,  16), S( 25,  20), S(-20,  30), S(-28,  29), S(-26,  36), S(  3,  25), S(-85,  13),
            S(-74,  -8), S( 37, -10), S(-38,  26), S(-92,  39), S(-95,  42), S(-66,  33), S(-64,  19), S(-93,   1),
            S( -6, -22), S(  0,  -3), S(-29,  17), S(-58,  29), S(-63,  32), S(-53,  26), S(-14,  10), S(-47,  -4),
            S( 10, -35), S( 23, -14), S(-18,   9), S(-73,  21), S(-52,  21), S(-30,  13), S( 12,  -5), S( 10, -24),
            S(-25, -59), S( 40, -46), S( 12, -24), S(-73,  -1), S( -5, -23), S(-38,  -7), S( 29, -36), S( 14, -62)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-40,   6), S(-19, -53), S( 40, 101), S( 15, 120), S( 21,  51), S(-10,  43), S( 44,  61), S( 84, 118),
        S( 33, 144), S(  1, 153), S( 35, 116), S(  7, 116), S( 39,  82), S( -4, 110), S(-38, 133), S(-44, 145),
        S( 16,  83), S(  0,  76), S( 13,  63), S( -2,  57), S(  1,  45), S( 27,  47), S( -6,  75), S( -9,  74),
        S(  1,  48), S(-18,  45), S(-21,  40), S(-22,  34), S(-17,  35), S(-18,  40), S(-16,  50), S(  9,  46),
        S( -6,  22), S(-18,  28), S(-15,  23), S(-35,  29), S(-10,  19), S( 23,  13), S(  7,  28), S( 16,  19),
        S(-13,  18), S(  3,  21), S(  8,  13), S(-39,  35), S(-14,  24), S(  3,  19), S( 15,  22), S(-19,  27),
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
            S(-90, -187), S(-37, -109), S(-28, -67), S(-20, -38), S( -5, -31), S(  1, -21), S(  9, -14), S( 18, -10),
            S( 29, -12), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 19, -67), S(-45, -60), S(-36, -17), S(-23,   2), S(-13,  12), S( -5,  21), S( -0,  28), S(  5,  34),
            S(  7,  39), S( 11,  44), S( 15,  46), S( 33,  45), S( 12,  63), S( 35,  50), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(151,  51), S(-41, -66), S(-48, -82), S(-40, -55), S(-32, -34), S(-27, -28), S(-21, -17), S(-18, -12),
            S(-11, -12), S( -3, -10), S(  4,  -7), S( 10,  -3), S( 18,   1), S( 20,   4), S( 38,  -3), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(-64, -132), S(-18, -266), S(-18, -117), S(-20, -34), S(-12, -32),
            S(-12, -32), S( -5, -25), S( -4,  -9), S( -3,   2), S( -1,  15), S(  3,  20), S(  5,  26), S(  5,  41),
            S(  8,  40), S(  5,  57), S(  7,  52), S( 14,  60), S( 15,  71), S( 32,  65), S( 22,  75), S( 35,  69),
            S( 27,  75), S(127,  12), S( -1,  86), S(268, -61)
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
            S( -5,   6), S(  0,   0), S(  0,   0), S(  0,   0), S( 17,   5), S(  0,   0)
        },
        {
            S(-18,  18), S(  0,   0), S(  0,   0), S(  0,   0), S( 31, -11), S(  0,   0)
        },
        {
            S( -6,   6), S(  0,   0), S(-19,  -5), S(-30,  12), S(  0,   0), S(  0,   0)
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
            S( -5,  10), S(  0,   0), S( 21,  16), S( 53, -12), S( 23, -28), S(  0,   0)
        },
        {
            S(  1,   6), S( 23,  26), S(  0,   0), S( 32,   1), S(  0,   0), S(  0,   0)
        },
        {
            S(-16,  10), S(  7,   7), S( 15,  11), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( -4,   2), S( -3,   2), S( -3,  20), S( -9,   5), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
    }};

    static constexpr std::array<PhaseScore, 6> kingAreaAttackBonus =
    {
        S(  0,   0), S( 15, -10), S( 20,  -4), S( 27,  -7), S( 17,   6), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> pinnedBonus =
    {
        S(  0,   0), S(-20, -53), S( -6, -59), S(-50, -40), S(-59, -59), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> protectedByPawnBonus =
    {
        S(  0,   0), S(  6,   4), S( -2,  20), S(  3,  -3), S( -9,   7), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> behindPawnBonus =
    {
        S(  0,   0), S(  4,  11), S(  4,   7), S(  4,  -3), S(  2, -17), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> outpostBonus =
    {
        S(  0,   0), S( 18,  14), S( 36,  -7), S( 17,  14), S( 17,   2), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOwnPawnBonus =
    {
        S( 23,  20), S( 12,  17), S( 13,   8), S(  4,   4), S( -3,  -4), S( -9, -15), S(-22, -14), S(-35, -41),
        S(-28, -114)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOpponentPawnBonus =
    {
        S( 36, -19), S(  6,  -4), S(  3,  -1), S( -7,   2), S(-12,   2), S(-18,   0), S(-27,   9), S(-39,   5),
        S(-33, -52)
    };

    static constexpr PhaseScore doubledPawnBonus = S(-9, -11);
    static constexpr PhaseScore doubledPassedPawnBonus = S(-7, -26);
    static constexpr PhaseScore blockedPassedPawnBonus = S(15, -37);
    static constexpr PhaseScore protectedPawnBonus = S(13, 9);
    static constexpr PhaseScore weakPawnBonus = S(-9, -8);
    static constexpr PhaseScore bishopPairBonus = S(32, 42);
    static constexpr PhaseScore rookOpenFileBonus = S(45, -3);
    static constexpr PhaseScore rookSemiOpenFileBonus = S(29, -4);

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