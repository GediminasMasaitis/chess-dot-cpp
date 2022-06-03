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
    };

    using Trace = EvaluationClassical2Trace;
    using Data = EvaluationClassical2Data;

    static constexpr int ParameterCount = 6 + 6 * 64 + 64 + 6 * 28 + 6 + 2 * 9 + 8;

    static constexpr std::array<PhaseScore, 6> material =
    {
        S(100, 142), S(406, 283), S(388, 292), S(547, 545), S(1208, 941), S(  0,   0)
    };

    static constexpr std::array<std::array<PhaseScore, 64>, 6> psts =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S( 97, 170), S(138, 190), S( 35,  84), S( 88,  45), S( 62,  94), S(149,  74), S(-12, 122), S(-100, 123),
            S(-21, -25), S( -1, -41), S(-22, -29), S(  7, -56), S(  4, -42), S( 80, -59), S( 44, -44), S(  4, -40),
            S(-31, -40), S(-11, -48), S(-15, -53), S(  7, -66), S(  6, -55), S( -0, -53), S( -0, -51), S(-28, -48),
            S(-39, -47), S(-23, -49), S(-11, -59), S(  0, -62), S(  7, -61), S(  0, -63), S( -4, -60), S(-33, -61),
            S(-37, -57), S(-26, -57), S(-22, -57), S(-17, -51), S( -7, -52), S(-10, -56), S( 15, -72), S(-25, -66),
            S(-32, -50), S(-15, -59), S(-22, -44), S( -2, -54), S( -5, -43), S( 27, -58), S( 25, -70), S(-13, -69),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-163,   3), S(-112, -10), S(-77,  16), S(-61,  -5), S( 56, -16), S(-104,   2), S(-34, -37), S(-99, -38),
            S(-76,   4), S(-56,  16), S( 66, -22), S( -2,  16), S(  7,   6), S( 40, -18), S(  4,  -4), S(-17, -21),
            S(-60,  -6), S( 41, -14), S( -6,  25), S( 19,  24), S( 42,  11), S( 95,  -1), S( 43,  -9), S( 50, -30),
            S( -3,  -3), S( 12,   8), S( -6,  33), S( 41,  28), S( 12,  35), S( 42,  22), S( -1,  20), S( 27,  -2),
            S( -0,  -4), S(  9,  -4), S(  2,  22), S(  8,  30), S( 16,  23), S( 13,  23), S( 22,   9), S( 13,   1),
            S(-12, -12), S(-17,   2), S( -4,   2), S(-11,  19), S(  8,  16), S( -1,   1), S( 17, -16), S( -9,  -8),
            S( -5, -20), S(-36,  -5), S(-20,  -1), S( 10,  -7), S(  6,  -4), S( 14, -16), S( -5,  -9), S(  8, -21),
            S(-97,  30), S(  6, -21), S(-43,  -7), S(-27,   4), S(  7, -12), S(-15,  -6), S( 11, -23), S(  6, -28)
        },
        {
            S(-14, -15), S(-11, -16), S(-132,   6), S(-91,   4), S(-48,  -1), S(-67,  -1), S(-30,  -7), S( 12, -21),
            S(-23,   1), S( 13, -10), S(-26,   1), S(-33, -11), S( 15,  -9), S( 47, -17), S(  0,  -4), S(-46,  -5),
            S( -7,  -1), S( 32, -15), S( 37, -10), S( 13,  -8), S( 10,  -7), S( 39,  -5), S( 13,  -4), S(  2,   1),
            S( 10,  -9), S( 25,  -7), S( 10,   3), S( 39,   1), S( 33,   1), S( 27,  -2), S( 25, -13), S(  4,  -1),
            S( 22, -16), S( 21,  -9), S( 23,  -2), S( 31,   5), S( 42,  -8), S( 25,  -6), S( 24, -15), S( 35, -17),
            S( 23, -15), S( 34, -13), S( 30,  -3), S( 31,  -4), S( 33,   1), S( 50, -16), S( 34, -13), S( 37, -17),
            S( 42, -17), S( 42, -25), S( 37, -18), S( 29, -13), S( 35, -11), S( 44, -22), S( 61, -27), S( 41, -30),
            S(  4, -14), S( 35,  -9), S( 33, -15), S( 22, -11), S( 30, -15), S( 27, -15), S( -9,  -1), S( 19, -14)
        },
        {
            S(  9,  19), S( 15,  16), S(-31,  34), S( 21,  18), S( 14,  23), S(-42,  32), S(-16,  25), S( -2,  17),
            S(  6,  19), S(  9,  21), S( 42,  13), S( 41,  13), S( 57,  -1), S( 40,   8), S( -9,  23), S(  5,  17),
            S( -2,  15), S( 23,  13), S( 28,   9), S( 33,  10), S(  7,  10), S( 44,   1), S( 66,  -5), S( 13,   2),
            S(-15,  15), S(  1,  10), S( 16,  18), S( 22,   6), S( 25,   8), S( 36,   5), S(  3,   6), S(-12,  12),
            S(-27,  13), S(-13,  12), S( -1,  13), S(  2,   8), S( 14,   0), S( -4,   3), S( 11,  -1), S(-20,   2),
            S(-29,   6), S(-11,   4), S( -1,  -3), S( -6,   1), S(  9,  -5), S(  6,  -9), S(  2,  -2), S(-20,  -6),
            S(-25,   1), S(  0,  -4), S( -3,   0), S(  7,   1), S( 20, -11), S( 20, -11), S( 11, -13), S(-48,   6),
            S(  2,  -7), S(  9,  -2), S( 21,  -3), S( 30,  -7), S( 34, -10), S( 19,  -8), S(-11,   2), S(  4, -23)
        },
        {
            S( -1, -16), S(-34,  47), S(-17,  41), S(-29,  46), S( 92, -15), S( 82, -18), S( 56,  -8), S( 73,   7),
            S(-15,  -7), S(-48,  27), S(-21,  36), S(-14,  50), S(-75,  89), S( 33,  15), S( -2,  45), S( 57,   6),
            S(  6,  -4), S( -2,   7), S( 17,  -4), S(-30,  74), S( 11,  49), S( 49,  20), S( 25,  26), S( 45,  19),
            S(-23,  42), S(-13,  31), S(-23,  32), S(-29,  50), S( -7,  53), S(  1,  36), S( -2,  76), S(  2,  61),
            S( 14,  -6), S(-28,  45), S(  4,  11), S( -2,  34), S(  2,  26), S(  7,  25), S( 11,  41), S( 10,  38),
            S( -6,  15), S( 23, -35), S(  5,   5), S( 18,  -9), S( 13,   8), S( 14,  13), S( 28,  11), S( 19,  32),
            S(  1,  -9), S( 16, -29), S( 33, -33), S( 33, -31), S( 41, -27), S( 41, -35), S( 23, -43), S( 35, -31),
            S( 31, -37), S( 30, -40), S( 34, -29), S( 43, -36), S( 28, -11), S( 11, -24), S( 13, -17), S(-21, -24)
        },
        {
            S(-96, -69), S(169, -67), S(167, -48), S( 88, -35), S(-113,  13), S(-66,  28), S( 54,  -6), S( 40, -21),
            S(184, -49), S( 97,   1), S( 56,   7), S(125,  -2), S( 49,  14), S( 56,  31), S( -3,  26), S(-136,  36),
            S( 70,  -6), S( 93,   9), S(122,   7), S( 29,  17), S( 61,  13), S(133,  31), S(147,  24), S( -6,  12),
            S( 22, -15), S( 14,  20), S( 37,  24), S(-16,  36), S(-25,  35), S(-27,  43), S(  6,  31), S(-87,  19),
            S(-72,  -5), S( 43,  -7), S(-39,  32), S(-93,  44), S(-101,  49), S(-65,  39), S(-60,  24), S(-93,   5),
            S(  3, -20), S(  2,   1), S(-31,  22), S(-59,  34), S(-65,  38), S(-53,  31), S(-11,  14), S(-41,  -0),
            S( 14, -33), S( 24, -10), S(-18,  15), S(-72,  26), S(-51,  26), S(-28,  17), S( 17,  -2), S( 16, -22),
            S(-23, -58), S( 43, -43), S( 13, -20), S(-75,   2), S( -2, -21), S(-34,  -4), S( 35, -33), S( 18, -59)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-35,  21), S(-16, -21), S( 17,  73), S( -1,  82), S(  3,  49), S( -4,  44), S( 17,  53), S( 28,  85),
        S( 35, 152), S(  2, 162), S( 38, 121), S(  2, 118), S( 41,  85), S( -3, 115), S(-36, 139), S(-40, 151),
        S( 18,  86), S(  1,  80), S( 13,  66), S( -7,  63), S( -3,  48), S( 32,  49), S( -3,  79), S( -7,  78),
        S(  7,  49), S(-20,  48), S(-24,  42), S(-24,  37), S(-21,  39), S(-14,  40), S(-16,  53), S( 15,  47),
        S( -2,  21), S(-15,  28), S(-17,  25), S(-39,  29), S(-10,  19), S( 25,  13), S( 10,  29), S( 22,  18),
        S(-11,  18), S(  3,  21), S(  9,  12), S(-39,  36), S(-11,  24), S(  8,  18), S( 19,  23), S(-16,  27),
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
            S(-117, -125), S(-45, -73), S(-35, -33), S(-24,  -6), S( -6,  -3), S( -1,   6), S(  8,   9), S( 19,   9),
            S( 32,   2), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 18, -58), S(-44, -60), S(-34, -17), S(-18,   0), S( -7,   9), S(  3,  17), S(  9,  23), S( 14,  27),
            S( 17,  30), S( 22,  32), S( 29,  30), S( 51,  24), S( 26,  38), S( 57,  22), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 83,  30), S(-49, -44), S(-49, -67), S(-41, -44), S(-33, -20), S(-27, -12), S(-19,  -1), S(-15,   3),
            S( -6,   3), S(  4,   4), S( 15,   5), S( 26,   8), S( 37,  12), S( 40,  14), S( 56,   7), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(-93, -91), S(-35, -229), S(-19, -142), S(-22, -51), S(-13, -47),
            S(-14, -48), S( -7, -36), S( -5, -20), S( -4,  -8), S( -2,   7), S(  2,  13), S(  5,  19), S(  5,  35),
            S(  9,  33), S(  6,  50), S(  8,  45), S( 16,  53), S( 16,  64), S( 34,  57), S( 25,  67), S( 39,  60),
            S( 37,  62), S(122,   7), S( 24,  64), S(149,  -6)
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
        S(  0,   0), S( 15,  -9), S( 20,  -3), S( 29,  -8), S( 17,   5), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOwnPawnBonus =
    {
        S( -3,  22), S(  7,  13), S( 12,   3), S( 10,  -0), S(  8,  -7), S(  4, -14), S( -2, -19), S( -2, -41),
        S( -1,  -1)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOpponentPawnBonus =
    {
        S(  8, -19), S( -9, -11), S(-11,  -6), S(-11,  -4), S( -8,  -1), S( -6,   2), S( -3,   2), S(  0,  37),
        S(  0,   0)
    };

    static constexpr PhaseScore doubledPawnBonus = S(-7, -12);
    static constexpr PhaseScore doubledPassedPawnBonus = S(-7, -27);
    static constexpr PhaseScore blockedPassedPawnBonus = S(16, -39);
    static constexpr PhaseScore protectedPawnBonus = S(14, 10);
    static constexpr PhaseScore weakPawnBonus = S(-11, -8);
    static constexpr PhaseScore bishopPairBonus = S(30, 52);
    static constexpr PhaseScore rookOpenFileBonus = S(17, -2);
    static constexpr PhaseScore rookSemiOpenFileBonus = S(4, 2);

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