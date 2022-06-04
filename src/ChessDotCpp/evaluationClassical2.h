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
        std::array<std::array<TraceScores, 6>, 6> attackBonus;
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

    static constexpr int ParameterCount = 6 + 6 * 64 + 64 + 6 * 28 + 6 * 6 + 4 * 6 + 2 * 9 + 8;

    static constexpr std::array<PhaseScore, 6> material =
    {
        S(100, 145), S(413, 299), S(396, 291), S(554, 551), S(1227, 932), S(  0,   0)
    };

    static constexpr std::array<std::array<PhaseScore, 64>, 6> psts =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(105, 180), S(142, 213), S( 22,  64), S( 80,  18), S( 54,  92), S(154,  75), S(-28, 114), S(-136,  94),
            S(-22, -27), S( -2, -42), S(-20, -33), S(  8, -66), S(  1, -42), S( 74, -60), S( 41, -45), S(  4, -41),
            S(-34, -42), S(-10, -51), S(-15, -55), S(  5, -67), S(  5, -57), S( -0, -55), S( -0, -53), S(-30, -50),
            S(-41, -49), S(-25, -51), S(-11, -61), S( -2, -63), S(  6, -63), S(  0, -65), S( -5, -62), S(-35, -63),
            S(-39, -59), S(-26, -61), S(-23, -60), S(-19, -54), S( -7, -55), S(-11, -59), S( 14, -74), S(-26, -68),
            S(-33, -53), S(-17, -63), S(-22, -48), S( -5, -58), S( -7, -47), S( 27, -61), S( 24, -73), S(-13, -71),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-160,  18), S(-110,   2), S(-65,  22), S(-51,  -1), S( 53,  -9), S(-93,   8), S(-44, -24), S(-103, -24),
            S(-85,  18), S(-66,  25), S( 32, -11), S(-14,  23), S(  2,  10), S( 16,  -9), S(  1,   4), S(-38,  -2),
            S(-60,   2), S( 11,  -6), S(-15,  21), S( 11,  17), S( 25,   9), S( 90,  -8), S( 18,  -2), S( 51, -25),
            S( -5,   5), S( 12,   4), S(-11,  23), S( 35,  24), S( 14,  25), S( 41,  10), S(  4,  12), S( 28,   2),
            S( -3,   3), S(  7,  -5), S(  1,  14), S(  6,  24), S( 18,  18), S( 16,  12), S( 25,   6), S( 10,   7),
            S(-11,  -5), S(-19,   4), S( -5,  -2), S( -9,  18), S(  6,  14), S( -3,  -2), S( 16, -13), S( -7,  -2),
            S( -7,  -6), S(-38,   6), S(-18,   3), S( 12,  -0), S(  8,   3), S( 18,  -9), S( -3,   2), S(  7,  -9),
            S(-96,  45), S(  4,  -6), S(-44,   5), S(-28,  15), S(  8,   0), S(-13,   6), S(  9, -10), S(  4, -13)
        },
        {
            S( -8, -11), S( 17, -19), S(-114,   4), S(-79,   2), S(-38,  -3), S(-53,  -3), S( -5,  -7), S( 14, -16),
            S( -9,  -0), S( -8,  -7), S(-31,  -1), S(-27, -16), S(  5,  -9), S( 47, -20), S(-30,  -1), S(-36,  -6),
            S( 10,  -5), S( 25, -19), S( 21, -17), S(  5, -16), S(  1, -16), S( 29, -13), S( 13, -12), S( 13,   1),
            S( 16,  -9), S(  8, -12), S(  4,  -8), S( 31, -15), S( 22, -16), S( 25, -15), S( 13, -20), S( 14,  -5),
            S( 17, -14), S( 20, -17), S( 26, -16), S( 26, -11), S( 43, -24), S( 26, -18), S( 26, -23), S( 32, -15),
            S( 24, -13), S( 39, -20), S( 33, -13), S( 35, -13), S( 39, -12), S( 52, -26), S( 39, -22), S( 39, -16),
            S( 44, -14), S( 45, -24), S( 42, -20), S( 34, -13), S( 41, -11), S( 48, -21), S( 66, -27), S( 42, -26),
            S(  7, -10), S( 40,  -6), S( 38,  -9), S( 29,  -7), S( 36, -11), S( 32,  -9), S( -2,   3), S( 24, -11)
        },
        {
            S(-19,  27), S(-13,  24), S(-59,  42), S( -0,  24), S( -8,  29), S(-49,  35), S(-16,  25), S(-20,  24),
            S(  0,  18), S(  6,  19), S( 33,  12), S( 35,  11), S( 52,  -3), S( 34,   8), S( -8,  23), S(  1,  17),
            S( -1,  12), S( 19,  10), S( 25,   6), S( 27,   7), S(  1,   8), S( 43,  -3), S( 69,  -8), S( 13,   1),
            S(-12,  13), S( -0,   8), S( 11,  16), S( 17,   5), S( 24,   4), S( 36,   2), S(  1,   3), S( -5,   9),
            S(-24,  14), S(-13,  14), S( -2,  14), S(  1,   9), S( 18,   0), S( -4,   2), S( 18,  -4), S(-16,   3),
            S(-25,  10), S( -8,   7), S(  1,   1), S( -2,   4), S( 13,  -2), S( 11,  -8), S(  8,  -1), S(-20,  -2),
            S(-21,   5), S(  7,  -1), S(  0,   5), S( 13,   5), S( 26,  -7), S( 30, -10), S( 17, -10), S(-43,  10),
            S(  6,  -2), S( 14,   2), S( 26,   1), S( 35,  -5), S( 39,  -8), S( 24,  -5), S( -6,   6), S(  8, -18)
        },
        {
            S( -9, -15), S(-39,  48), S(-20,  41), S(-36,  47), S( 88, -14), S( 73, -11), S( 54,  -7), S( 64,  13),
            S(-10, -11), S(-39,  19), S(-14,  28), S( -4,  41), S(-61,  78), S( 38,   9), S(  8,  36), S( 59,   6),
            S( 12,  -5), S(  5,   2), S( 26, -12), S(-18,  62), S( 16,  40), S( 64,   8), S( 32,  21), S( 52,  17),
            S(-20,  42), S(-12,  33), S(-16,  25), S(-22,  40), S( -2,  47), S( 10,  28), S(  2,  75), S(  3,  63),
            S( 10,   3), S(-24,  41), S(  6,  12), S(  3,  31), S(  6,  24), S( 11,  23), S( 15,  37), S(  9,  43),
            S( -3,  14), S( 26, -37), S(  9,   4), S( 21,  -8), S( 16,   9), S( 20,  13), S( 33,  11), S( 24,  30),
            S( -7,   1), S(  9, -19), S( 26, -22), S( 26, -16), S( 34, -12), S( 36, -20), S( 20, -34), S( 33, -24),
            S( 22, -24), S( 23, -29), S( 26, -16), S( 34, -20), S( 22,   0), S(  3,  -8), S(  8,  -8), S(-28, -11)
        },
        {
            S(-155, -58), S(161, -67), S(164, -48), S( 75, -34), S(-120,  14), S(-69,  29), S( 47,  -5), S( 31, -21),
            S(182, -51), S( 97,   1), S( 53,   7), S(122,  -1), S( 52,  14), S( 58,  31), S( -1,  26), S(-140,  36),
            S( 68,  -6), S(100,   8), S(122,   7), S( 30,  17), S( 62,  13), S(134,  32), S(152,  24), S( -8,  12),
            S( 22, -16), S( 10,  21), S( 34,  25), S(-15,  36), S(-22,  35), S(-26,  43), S(  9,  30), S(-89,  18),
            S(-76,  -5), S( 43,  -7), S(-36,  32), S(-91,  45), S(-97,  49), S(-65,  39), S(-61,  24), S(-96,   5),
            S( -3, -19), S(  4,   1), S(-27,  22), S(-57,  35), S(-62,  38), S(-51,  31), S(-10,  14), S(-45,  -0),
            S( 13, -33), S( 27, -11), S(-16,  14), S(-71,  26), S(-50,  26), S(-27,  17), S( 17,  -2), S( 15, -22),
            S(-26, -58), S( 45, -44), S( 15, -21), S(-73,   2), S(  1, -22), S(-34,  -4), S( 36, -34), S( 19, -62)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-46,  12), S(-21, -42), S( 32,  96), S(  4, 110), S( 10,  52), S(-14,  45), S( 35,  60), S( 64, 116),
        S( 35, 153), S( -1, 163), S( 33, 125), S(  1, 128), S( 42,  85), S( -3, 116), S(-39, 139), S(-45, 153),
        S( 17,  87), S( -2,  82), S( 11,  67), S( -6,  63), S( -3,  48), S( 29,  50), S( -6,  80), S( -9,  78),
        S(  4,  50), S(-22,  48), S(-27,  43), S(-26,  37), S(-20,  38), S(-20,  42), S(-19,  53), S( 12,  48),
        S( -3,  22), S(-21,  30), S(-19,  25), S(-42,  31), S(-13,  21), S( 21,  14), S(  6,  30), S( 20,  18),
        S(-13,  19), S(  0,  23), S(  6,  14), S(-42,  38), S(-18,  26), S(  3,  20), S( 16,  23), S(-19,  28),
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
            S(-102, -182), S(-42, -105), S(-32, -60), S(-23, -31), S( -7, -23), S( -0, -13), S(  7,  -6), S( 17,  -2),
            S( 29,  -4), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 18, -69), S(-49, -67), S(-36, -23), S(-21,  -4), S(-10,   7), S( -1,  17), S(  4,  26), S( 10,  32),
            S( 13,  39), S( 18,  43), S( 23,  46), S( 49,  44), S( 29,  64), S( 57,  49), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(143,  49), S(-51, -58), S(-52, -78), S(-44, -53), S(-36, -30), S(-29, -23), S(-22, -11), S(-17,  -6),
            S( -9,  -5), S(  1,  -3), S( 11,  -1), S( 22,   3), S( 35,   7), S( 40,  11), S( 61,   3), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(-73, -129), S(-25, -283), S(-21, -127), S(-24, -44), S(-15, -37),
            S(-14, -40), S( -7, -32), S( -5, -15), S( -4,  -4), S( -1,  11), S(  3,  16), S(  6,  23), S(  5,  40),
            S(  8,  39), S(  6,  56), S(  9,  51), S( 17,  59), S( 16,  72), S( 34,  66), S( 20,  79), S( 36,  71),
            S( 26,  79), S(133,  12), S(  8,  84), S(251, -49)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
    }};

    static constexpr std::array<std::array<PhaseScore, 6>, 6> attackBonus =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( -5,  11), S(  0,   0), S( 24,  18), S( 57, -14), S( 25, -33), S(  0,   0)
        },
        {
            S( -1,   9), S( 24,  30), S(  0,   0), S( 33,   2), S( 36,  37), S(  0,   0)
        },
        {
            S( -9,  11), S( 19,   6), S( 28,  10), S(  0,   0), S( 66, -23), S(  0,   0)
        },
        {
            S( -5,   4), S( -3,   5), S( -3,  19), S(-10,   5), S(  0,   0), S(  0,   0)
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
        S(  0,   0), S(-22, -58), S( -7, -62), S(-55, -44), S(-64, -63), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> protectedByPawnBonus =
    {
        S(  0,   0), S(  6,   4), S( -2,  17), S(  3,  -2), S(-10,   7), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> outpostBonus =
    {
        S(  0,   0), S( 19,  15), S( 39,  -6), S( 19,  15), S( 19,   4), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOwnPawnBonus =
    {
        S( -2,  23), S(  5,  14), S( 10,   3), S(  9,   0), S(  7,  -5), S(  4, -12), S( -3, -15), S( -2, -32),
        S(-27, -90)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOpponentPawnBonus =
    {
        S( 14, -22), S( -7, -11), S( -9,  -6), S(-10,  -4), S( -7,  -1), S( -6,   1), S( -3,   0), S( -1,  34),
        S(-45, -47)
    };

    static constexpr PhaseScore doubledPawnBonus = S(-6, -13);
    static constexpr PhaseScore doubledPassedPawnBonus = S(-5, -28);
    static constexpr PhaseScore blockedPassedPawnBonus = S(17, -39);
    static constexpr PhaseScore protectedPawnBonus = S(15, 10);
    static constexpr PhaseScore weakPawnBonus = S(-10, -8);
    static constexpr PhaseScore bishopPairBonus = S(28, 49);
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

            //// CHECKS
            //const bool isCheck = (attacks & board.BitBoard[Pieces::King | opponent]) != 0;
            //if(isCheck)
            //{
            //    score += checkBonus[pieceIndex];
            //    TraceIncr(checkBonus[pieceIndex]);
            //}

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

                    score += attackBonus[pieceIndex][attackedPieceIndex];
                    TraceIncr(attackBonus[pieceIndex][attackedPieceIndex]);
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