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
        std::array<TraceScores, 6> pinnedBonus;
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

    static constexpr int ParameterCount = 6 + 6 * 64 + 64 + 6 * 28 + 6 + 6 + 2 * 9 + 8;

    static constexpr std::array<PhaseScore, 6> material =
    {
        S(100, 141), S(404, 286), S(387, 290), S(546, 544), S(1199, 929), S(  0,   0)
    };

    static constexpr std::array<std::array<PhaseScore, 64>, 6> psts =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S( 97, 171), S(137, 198), S( 31,  78), S( 82,  33), S( 58,  90), S(149,  75), S(-19, 121), S(-109, 112),
            S(-20, -25), S( -0, -40), S(-22, -28), S(  5, -56), S(  3, -46), S( 76, -58), S( 43, -44), S(  4, -40),
            S(-31, -40), S(-11, -47), S(-16, -52), S(  7, -67), S(  6, -54), S( -1, -53), S( -1, -50), S(-28, -48),
            S(-39, -47), S(-23, -49), S(-11, -58), S( -0, -62), S(  7, -61), S( -0, -62), S( -4, -60), S(-33, -61),
            S(-37, -56), S(-26, -57), S(-22, -56), S(-17, -51), S( -7, -51), S(-11, -55), S( 14, -71), S(-25, -65),
            S(-32, -50), S(-15, -59), S(-22, -44), S( -3, -54), S( -6, -43), S( 26, -58), S( 24, -70), S(-13, -69),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-162,   3), S(-114,  -8), S(-79,  17), S(-64,  -4), S( 53, -16), S(-105,   3), S(-35, -35), S(-100, -38),
            S(-76,   4), S(-57,  17), S( 64, -22), S( -2,  17), S(  4,   7), S( 39, -18), S(  3,  -3), S(-16, -20),
            S(-60,  -5), S( 39, -13), S( -5,  25), S( 19,  24), S( 40,  11), S( 94,   0), S( 41,  -9), S( 47, -30),
            S( -2,  -2), S( 12,   8), S( -6,  34), S( 41,  29), S( 11,  36), S( 41,  22), S( -1,  21), S( 28,  -2),
            S( -1,  -3), S( 10,  -4), S(  2,  23), S(  8,  31), S( 16,  24), S( 13,  24), S( 23,  10), S( 13,   1),
            S(-11, -11), S(-17,   3), S( -4,   2), S(-11,  21), S(  8,  18), S( -1,   3), S( 18, -13), S( -9,  -8),
            S( -5, -19), S(-37,  -3), S(-20,   0), S( 11,  -6), S(  7,  -2), S( 17, -13), S( -2,  -7), S(  8, -20),
            S(-95,  30), S(  6, -20), S(-42,  -4), S(-26,   5), S(  7,  -9), S(-13,  -2), S( 11, -22), S(  7, -27)
        },
        {
            S(-13, -16), S(-12, -16), S(-131,   5), S(-94,   4), S(-50,  -1), S(-65,  -2), S(-31,  -8), S(  9, -21),
            S(-22,  -0), S( 14, -11), S(-26,   0), S(-33, -12), S( 15, -10), S( 49, -18), S(  1,  -6), S(-46,  -6),
            S( -6,  -3), S( 33, -16), S( 34, -11), S( 13,  -9), S(  9,  -8), S( 38,  -6), S( 13,  -5), S(  2,   1),
            S( 12, -11), S( 17,  -5), S( 11,   1), S( 39,  -0), S( 33,  -1), S( 28,  -3), S( 26, -15), S(  4,  -2),
            S( 19, -16), S( 22, -10), S( 24,  -4), S( 31,   4), S( 43,  -9), S( 26,  -6), S( 25, -16), S( 35, -18),
            S( 25, -16), S( 35, -14), S( 31,  -4), S( 32,  -5), S( 34,   1), S( 50, -16), S( 35, -14), S( 38, -19),
            S( 43, -18), S( 43, -26), S( 38, -18), S( 29, -12), S( 36, -11), S( 45, -20), S( 62, -27), S( 43, -31),
            S(  5, -15), S( 37,  -9), S( 34, -15), S( 23, -11), S( 32, -15), S( 28, -13), S( -7,  -1), S( 20, -16)
        },
        {
            S( -9,  22), S( -3,  19), S(-51,  37), S(  4,  21), S( -2,  25), S(-47,  32), S(-19,  25), S(-12,  19),
            S(  4,  18), S(  8,  20), S( 39,  12), S( 39,  12), S( 54,  -1), S( 38,   8), S(-10,  23), S(  2,  17),
            S( -2,  14), S( 25,  12), S( 29,   8), S( 34,  10), S(  8,   9), S( 47,  -0), S( 64,  -4), S( 14,   1),
            S(-14,  15), S(  2,  10), S( 17,  17), S( 23,   6), S( 27,   8), S( 37,   5), S(  1,   6), S(-12,  12),
            S(-27,  14), S(-12,  13), S(  1,  13), S(  5,   9), S( 16,   1), S( -2,   2), S( 10,  -1), S(-18,   3),
            S(-28,   7), S(-10,   5), S(  1,  -3), S( -5,   2), S( 12,  -5), S(  8,  -9), S(  4,  -3), S(-19,  -5),
            S(-24,   2), S(  1,  -3), S( -2,   1), S( 10,   1), S( 21, -11), S( 25, -12), S( 14, -13), S(-46,   6),
            S(  3,  -6), S( 10,  -1), S( 23,  -2), S( 31,  -7), S( 35, -10), S( 21,  -8), S(-10,   3), S(  5, -22)
        },
        {
            S(-15, -14), S(-53,  54), S(-35,  46), S(-48,  52), S( 79, -11), S( 73, -16), S( 45,  -5), S( 60,  11),
            S(-12, -10), S(-46,  24), S(-17,  30), S(-13,  46), S(-72,  84), S( 32,  12), S(  1,  41), S( 60,   4),
            S(  9,  -3), S(  1,   6), S( 16,  -3), S(-27,  71), S(  5,  49), S( 51,  17), S( 27,  23), S( 48,  17),
            S(-21,  43), S(-18,  38), S(-22,  33), S(-28,  47), S( -8,  53), S(  3,  34), S( -0,  75), S(  4,  62),
            S( 10,   2), S(-25,  44), S(  6,  11), S(  0,  34), S(  2,  27), S(  9,  25), S( 12,  40), S( 13,  38),
            S( -4,  15), S( 26, -37), S(  8,   5), S( 21, -10), S( 15,  10), S( 17,  14), S( 30,  12), S( 21,  33),
            S(  2,  -8), S( 18, -29), S( 35, -33), S( 36, -29), S( 43, -25), S( 44, -30), S( 27, -41), S( 39, -30),
            S( 34, -36), S( 32, -39), S( 37, -27), S( 46, -35), S( 31,  -9), S( 14, -19), S( 16, -15), S(-18, -23)
        },
        {
            S(-113, -66), S(163, -67), S(165, -48), S( 82, -35), S(-113,  13), S(-66,  27), S( 48,  -5), S( 38, -22),
            S(183, -49), S( 96,   1), S( 55,   7), S(123,  -2), S( 49,  14), S( 56,  31), S( -2,  26), S(-136,  36),
            S( 65,  -6), S( 97,   8), S(118,   7), S( 32,  16), S( 64,  13), S(134,  31), S(148,  24), S( -7,  12),
            S( 19, -16), S( 12,  20), S( 35,  24), S(-16,  36), S(-25,  34), S(-26,  42), S(  5,  30), S(-88,  18),
            S(-74,  -5), S( 41,  -7), S(-40,  32), S(-91,  44), S(-99,  48), S(-65,  38), S(-61,  23), S(-94,   5),
            S(  0, -20), S(  2,   1), S(-29,  22), S(-56,  34), S(-62,  38), S(-52,  31), S(-10,  13), S(-46,  -0),
            S( 12, -33), S( 25, -10), S(-18,  14), S(-70,  26), S(-50,  26), S(-27,  17), S( 17,  -3), S( 14, -22),
            S(-24, -59), S( 42, -43), S( 14, -21), S(-73,   2), S( -0, -21), S(-34,  -4), S( 35, -34), S( 17, -60)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-36,  19), S(-17, -30), S( 23,  80), S(  2,  94), S(  6,  52), S( -7,  43), S( 22,  53), S( 39,  97),
        S( 34, 151), S( -1, 162), S( 36, 120), S(  3, 118), S( 41,  89), S( -3, 114), S(-36, 138), S(-39, 151),
        S( 18,  86), S(  0,  80), S( 13,  66), S( -7,  63), S( -4,  48), S( 33,  49), S( -2,  78), S( -8,  77),
        S(  6,  48), S(-21,  48), S(-25,  42), S(-25,  38), S(-21,  39), S(-14,  41), S(-17,  52), S( 15,  47),
        S( -2,  21), S(-16,  28), S(-17,  24), S(-41,  30), S(-11,  20), S( 24,  13), S(  8,  29), S( 21,  18),
        S(-11,  17), S(  3,  22), S(  9,  13), S(-39,  37), S(-14,  25), S(  7,  18), S( 16,  23), S(-17,  27),
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
            S(-111, -141), S(-45, -76), S(-35, -36), S(-24,  -9), S( -6,  -7), S( -1,   2), S(  8,   5), S( 19,   5),
            S( 32,  -2), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 18, -58), S(-46, -56), S(-35, -16), S(-19,   2), S( -8,  11), S(  2,  19), S(  8,  25), S( 13,  28),
            S( 16,  33), S( 21,  34), S( 28,  33), S( 49,  27), S( 26,  41), S( 52,  26), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(102,  37), S(-49, -49), S(-50, -69), S(-41, -47), S(-33, -22), S(-27, -15), S(-20,  -5), S(-16,  -0),
            S( -7,  -1), S(  3,   1), S( 14,   3), S( 25,   6), S( 35,  10), S( 40,  12), S( 59,   5), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(-89, -102), S(-27, -257), S(-19, -137), S(-22, -47), S(-13, -42),
            S(-14, -44), S( -7, -32), S( -5, -16), S( -4,  -4), S( -2,  11), S(  2,  16), S(  5,  22), S(  5,  39),
            S(  9,  37), S(  6,  54), S(  9,  49), S( 17,  57), S( 16,  69), S( 36,  61), S( 26,  71), S( 40,  63),
            S( 34,  68), S(130,   6), S( 20,  69), S(181, -21)
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
        S(  0,   0), S( 15,  -9), S( 19,  -3), S( 29,  -8), S( 16,   7), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> pinnedBonus =
    {
        S(  0,   0), S(-27, -67), S( -1, -78), S(-37, -48), S(-75, -61), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOwnPawnBonus =
    {
        S( -2,  22), S(  6,  14), S( 10,   4), S(  8,   1), S(  7,  -6), S(  3, -14), S( -2, -18), S( -3, -39),
        S(-37, -53)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOpponentPawnBonus =
    {
        S( 11, -21), S( -8, -11), S( -9,  -7), S(-10,  -5), S( -7,  -2), S( -5,   1), S( -2,   2), S(  1,  37),
        S(-45, -27)
    };

    static constexpr PhaseScore doubledPawnBonus = S(-7, -12);
    static constexpr PhaseScore doubledPassedPawnBonus = S(-6, -27);
    static constexpr PhaseScore blockedPassedPawnBonus = S(17, -39);
    static constexpr PhaseScore protectedPawnBonus = S(14, 10);
    static constexpr PhaseScore weakPawnBonus = S(-11, -8);
    static constexpr PhaseScore bishopPairBonus = S(29, 51);
    static constexpr PhaseScore rookOpenFileBonus = S(16, -2);
    static constexpr PhaseScore rookSemiOpenFileBonus = S(4, 3);

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

            // PINS
            const bool isPinned = data.Pins[color] & posBitboard;
            if(isPinned)
            {
                score += pinnedBonus[pieceIndex];
                TraceIncr(pinnedBonus[pieceIndex]);
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