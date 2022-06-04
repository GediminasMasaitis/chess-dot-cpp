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
        S(100, 145), S(409, 304), S(398, 285), S(554, 552), S(1222, 925), S(  0,   0)
    };

    static constexpr std::array<std::array<PhaseScore, 64>, 6> psts =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(108, 183), S(143, 217), S( 17,  55), S( 78,   9), S( 49,  91), S(155,  71), S(-32, 111), S(-146,  88),
            S(-23, -26), S( -2, -41), S(-19, -33), S(  8, -64), S(  4, -44), S( 76, -60), S( 42, -45), S(  5, -41),
            S(-34, -41), S(-10, -51), S(-15, -55), S(  4, -67), S(  4, -57), S( -1, -55), S( -1, -53), S(-31, -50),
            S(-41, -49), S(-25, -51), S(-12, -61), S( -3, -63), S(  5, -62), S( -0, -65), S( -6, -62), S(-35, -62),
            S(-39, -58), S(-27, -60), S(-23, -60), S(-19, -54), S( -8, -54), S(-12, -58), S( 14, -74), S(-26, -67),
            S(-33, -52), S(-17, -62), S(-23, -48), S( -6, -57), S( -7, -47), S( 26, -61), S( 23, -72), S(-14, -71),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-158,  17), S(-111,   2), S(-68,  23), S(-50,   0), S( 51,  -8), S(-89,   9), S(-45, -23), S(-100, -24),
            S(-84,  17), S(-66,  26), S( 32, -11), S(-14,  22), S(  5,  10), S( 17,  -9), S(  2,   3), S(-35,  -4),
            S(-61,   2), S( 13,  -7), S(-14,  21), S( 10,  17), S( 24,  10), S( 89,  -7), S( 18,  -2), S( 51, -24),
            S( -6,   6), S( 13,   4), S(-10,  23), S( 35,  24), S( 13,  26), S( 42,  11), S(  4,  12), S( 28,   2),
            S( -3,   2), S(  8,  -5), S(  1,  15), S(  6,  24), S( 18,  19), S( 16,  13), S( 25,   7), S( 10,   7),
            S(-11,  -5), S(-19,   5), S( -4,  -2), S( -9,  19), S(  6,  14), S( -3,  -2), S( 16, -13), S( -7,  -2),
            S( -6,  -7), S(-38,   6), S(-18,   3), S( 12,  -0), S(  8,   4), S( 18,  -9), S( -3,   2), S(  7,  -8),
            S(-96,  45), S(  4,  -7), S(-44,   6), S(-28,  14), S(  8,   0), S(-14,   8), S(  9, -10), S(  4, -14)
        },
        {
            S( -7, -12), S( 15, -18), S(-114,   4), S(-80,   2), S(-36,  -4), S(-51,  -4), S( -4,  -8), S( 13, -16),
            S( -9,  -0), S( -8,  -7), S(-30,  -2), S(-28, -16), S(  4,  -9), S( 48, -20), S(-30,  -1), S(-36,  -6),
            S(  9,  -5), S( 26, -20), S( 21, -18), S(  4, -16), S(  2, -16), S( 30, -14), S( 13, -12), S( 15,  -0),
            S( 16,  -9), S(  8, -12), S(  4,  -8), S( 31, -16), S( 22, -16), S( 25, -15), S( 12, -19), S( 14,  -5),
            S( 17, -14), S( 19, -17), S( 25, -16), S( 25, -11), S( 42, -24), S( 26, -18), S( 26, -23), S( 31, -15),
            S( 24, -13), S( 38, -20), S( 33, -13), S( 35, -13), S( 39, -12), S( 51, -26), S( 38, -22), S( 39, -16),
            S( 42, -13), S( 43, -24), S( 41, -20), S( 33, -13), S( 40, -11), S( 47, -21), S( 64, -27), S( 41, -26),
            S(  6, -10), S( 39,  -6), S( 37,  -9), S( 28,  -7), S( 35, -11), S( 31,  -8), S( -2,   2), S( 23, -12)
        },
        {
            S(-19,  26), S(-13,  23), S(-59,  41), S( -0,  24), S( -8,  29), S(-49,  34), S(-17,  25), S(-19,  23),
            S( -0,  18), S(  6,  18), S( 32,  12), S( 35,  11), S( 51,  -4), S( 33,   7), S( -8,  21), S(  0,  17),
            S( -2,  12), S( 18,  10), S( 24,   6), S( 26,   7), S(  1,   7), S( 42,  -4), S( 67,  -8), S( 13,   0),
            S(-12,  13), S( -0,   7), S( 10,  15), S( 16,   5), S( 24,   4), S( 35,   2), S(  1,   2), S( -5,   9),
            S(-24,  14), S(-13,  13), S( -3,  14), S(  1,   8), S( 18,  -0), S( -4,   2), S( 17,  -4), S(-17,   2),
            S(-26,   9), S( -8,   7), S(  1,  -0), S( -3,   4), S( 12,  -2), S( 11,  -8), S(  7,  -1), S(-21,  -2),
            S(-21,   5), S(  6,  -1), S( -0,   5), S( 13,   4), S( 25,  -7), S( 30, -10), S( 17, -10), S(-43,  10),
            S(  6,  -2), S( 13,   1), S( 25,   0), S( 34,  -5), S( 38,  -8), S( 23,  -5), S( -7,   6), S(  8, -18)
        },
        {
            S( -8, -15), S(-38,  48), S(-17,  39), S(-34,  46), S( 92, -17), S( 75, -12), S( 58,  -9), S( 65,  13),
            S(-10, -11), S(-38,  19), S(-14,  28), S( -4,  41), S(-60,  78), S( 38,   9), S( 10,  35), S( 59,   6),
            S( 12,  -4), S(  4,   2), S( 26, -11), S(-18,  63), S( 17,  40), S( 63,   8), S( 32,  20), S( 53,  17),
            S(-20,  43), S(-12,  33), S(-16,  26), S(-21,  41), S( -2,  47), S( 10,  28), S(  3,  75), S(  3,  64),
            S( 10,   4), S(-23,  41), S(  6,  13), S(  3,  31), S(  6,  26), S( 11,  24), S( 15,  38), S(  9,  44),
            S( -3,  14), S( 26, -36), S(  9,   5), S( 20,  -7), S( 16,  10), S( 20,  14), S( 32,  12), S( 23,  31),
            S( -6,   1), S(  9, -17), S( 26, -21), S( 26, -15), S( 34, -11), S( 36, -19), S( 19, -33), S( 32, -23),
            S( 22, -23), S( 23, -28), S( 26, -14), S( 34, -19), S( 21,   1), S(  2,  -7), S(  7,  -6), S(-29,  -9)
        },
        {
            S(-160, -57), S(160, -67), S(163, -49), S( 74, -34), S(-121,  14), S(-67,  28), S( 47,  -5), S( 31, -21),
            S(183, -51), S( 96,   1), S( 53,   7), S(121,  -1), S( 51,  14), S( 56,  31), S( -1,  26), S(-140,  36),
            S( 68,  -7), S( 99,   7), S(122,   6), S( 29,  17), S( 63,  13), S(133,  32), S(153,  23), S( -7,  11),
            S( 22, -16), S(  9,  21), S( 33,  25), S(-15,  36), S(-22,  34), S(-25,  43), S(  9,  30), S(-88,  18),
            S(-76,  -5), S( 42,  -7), S(-36,  32), S(-91,  45), S(-97,  49), S(-65,  39), S(-61,  24), S(-96,   5),
            S( -3, -19), S(  4,   1), S(-27,  22), S(-56,  35), S(-62,  38), S(-51,  31), S(-10,  14), S(-45,  -0),
            S( 13, -33), S( 27, -11), S(-16,  14), S(-71,  26), S(-50,  26), S(-27,  17), S( 17,  -2), S( 15, -22),
            S(-25, -58), S( 45, -44), S( 15, -21), S(-73,   2), S(  1, -22), S(-34,  -4), S( 36, -34), S( 18, -62)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-48,   9), S(-24, -47), S( 36, 103), S(  6, 118), S( 13,  52), S(-15,  48), S( 39,  63), S( 73, 121),
        S( 34, 153), S( -2, 163), S( 33, 124), S(  0, 125), S( 39,  86), S( -4, 116), S(-40, 140), S(-46, 154),
        S( 18,  87), S( -2,  81), S( 12,  67), S( -6,  62), S( -3,  48), S( 29,  50), S( -6,  79), S( -9,  78),
        S(  4,  50), S(-22,  48), S(-26,  43), S(-26,  37), S(-21,  38), S(-20,  42), S(-18,  53), S( 12,  47),
        S( -3,  22), S(-21,  30), S(-19,  25), S(-41,  31), S(-13,  20), S( 21,  14), S(  5,  30), S( 20,  18),
        S(-13,  19), S(  1,  23), S(  6,  14), S(-41,  38), S(-18,  26), S(  3,  19), S( 16,  23), S(-18,  28),
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
            S(-98, -190), S(-40, -110), S(-31, -66), S(-21, -37), S( -5, -29), S(  2, -19), S(  9, -12), S( 19,  -9),
            S( 30, -11), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 18, -70), S(-51, -62), S(-38, -18), S(-24,   1), S(-12,  12), S( -4,  22), S(  1,  31), S(  8,  37),
            S( 10,  43), S( 16,  48), S( 21,  51), S( 47,  48), S( 27,  68), S( 56,  53), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(149,  51), S(-50, -66), S(-53, -82), S(-45, -57), S(-36, -34), S(-30, -26), S(-23, -15), S(-18, -10),
            S( -9,  -9), S( -0,  -6), S( 10,  -4), S( 21,  -0), S( 34,   4), S( 38,   8), S( 59,   1), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(-69, -134), S(-25, -282), S(-20, -123), S(-23, -41), S(-14, -34),
            S(-14, -37), S( -7, -29), S( -5, -12), S( -4,  -1), S( -1,  14), S(  3,  19), S(  6,  26), S(  6,  43),
            S(  9,  42), S(  6,  59), S(  9,  54), S( 18,  62), S( 16,  75), S( 34,  68), S( 21,  81), S( 36,  74),
            S( 28,  81), S(135,  14), S(  5,  89), S(268, -54)
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
            S( -4,  13), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( -6,  10), S(  0,   0), S(  0,   0), S(  0,   0), S( 19,   9), S(  0,   0)
        },
        {
            S(-11,  17), S(  0,   0), S(  0,   0), S(  0,   0), S( 38, -14), S(  0,   0)
        },
        {
            S( -6,   6), S(  0,   0), S(-20,  -9), S(-38,  14), S(  0,   0), S(  0,   0)
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
            S( -6,  11), S(  0,   0), S( 23,  18), S( 56, -13), S( 25, -33), S(  0,   0)
        },
        {
            S( -0,   9), S( 24,  30), S(  0,   0), S( 33,   2), S(  0,   0), S(  0,   0)
        },
        {
            S( -8,   8), S( 19,   6), S( 27,  10), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( -5,   3), S( -3,   5), S( -3,  19), S( -9,   4), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
    }};

    static constexpr std::array<PhaseScore, 6> kingAreaAttackBonus =
    {
        S(  0,   0), S( 16, -10), S( 21,  -5), S( 31,  -9), S( 18,   6), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> pinnedBonus =
    {
        S(  0,   0), S(-22, -58), S( -7, -63), S(-55, -43), S(-63, -63), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> protectedByPawnBonus =
    {
        S(  0,   0), S(  6,   4), S( -2,  16), S(  3,  -2), S(-10,   7), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> outpostBonus =
    {
        S(  0,   0), S( 18,  15), S( 38,  -6), S( 19,  14), S( 19,   4), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOwnPawnBonus =
    {
        S( -2,  22), S(  5,  14), S( 10,   3), S(  9,  -0), S(  7,  -6), S(  4, -12), S( -3, -14), S( -2, -32),
        S(-25, -92)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOpponentPawnBonus =
    {
        S( 13, -22), S( -7, -11), S( -9,  -6), S( -9,  -4), S( -7,  -1), S( -6,   1), S( -3,   0), S( -0,  33),
        S(-44, -48)
    };

    static constexpr PhaseScore doubledPawnBonus = S(-6, -13);
    static constexpr PhaseScore doubledPassedPawnBonus = S(-5, -28);
    static constexpr PhaseScore blockedPassedPawnBonus = S(16, -39);
    static constexpr PhaseScore protectedPawnBonus = S(15, 10);
    static constexpr PhaseScore weakPawnBonus = S(-10, -8);
    static constexpr PhaseScore bishopPairBonus = S(27, 48);
    static constexpr PhaseScore rookOpenFileBonus = S(14, -1);
    static constexpr PhaseScore rookSemiOpenFileBonus = S(7, -2);

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
            if constexpr (piece == Pieces::Bishop)
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