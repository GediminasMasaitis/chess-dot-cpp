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

    static constexpr int ParameterCount = 6 + 6 * 64 + 64 + 6 * 28 + 4 * 6 + 2 * 9 + 8;

    static constexpr std::array<PhaseScore, 6> material =
    {
        S(100, 142), S(407, 289), S(390, 290), S(549, 547), S(1209, 931), S(  0,   0)
    };

    static constexpr std::array<std::array<PhaseScore, 64>, 6> psts =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(101, 172), S(139, 200), S( 30,  75), S( 83,  31), S( 59,  92), S(152,  78), S(-21, 120), S(-115, 108),
            S(-21, -26), S(  0, -41), S(-17, -31), S(  8, -64), S(  3, -41), S( 76, -59), S( 42, -44), S(  3, -39),
            S(-31, -40), S(-10, -49), S(-15, -53), S(  8, -68), S(  6, -56), S( -1, -54), S(  0, -52), S(-28, -48),
            S(-40, -48), S(-24, -50), S(-11, -59), S( -0, -62), S(  7, -62), S( -0, -63), S( -5, -61), S(-33, -61),
            S(-38, -57), S(-27, -58), S(-23, -58), S(-17, -53), S( -7, -53), S(-12, -57), S( 14, -73), S(-25, -66),
            S(-32, -51), S(-17, -60), S(-22, -46), S( -4, -56), S( -7, -44), S( 26, -59), S( 23, -71), S(-13, -69),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-163,   9), S(-111,  -4), S(-77,  20), S(-61,  -1), S( 57, -14), S(-106,   6), S(-35, -32), S(-101, -33),
            S(-73,   8), S(-55,  19), S( 66, -20), S( -1,  18), S(  2,   9), S( 42, -16), S(  6,  -1), S(-16, -16),
            S(-56,  -4), S( 27, -11), S( -8,  23), S( 13,  21), S( 38,   9), S( 89,  -4), S( 36,  -9), S( 50, -27),
            S( -3,   0), S(  9,   4), S(-14,  28), S( 35,  25), S(  7,  31), S( 40,  16), S( -2,  16), S( 30,  -2),
            S( -2,  -2), S(  5,  -4), S( -1,  18), S(  4,  26), S( 17,  20), S( 11,  19), S( 22,   7), S( 12,   2),
            S(-15, -10), S(-19,   3), S( -7,  -0), S(-12,  20), S(  4,  15), S( -5,   0), S( 15, -14), S(-12,  -6),
            S( -3, -14), S(-36,   0), S(-18,   1), S( 13,  -3), S(  8,   0), S( 19, -12), S( -0,  -4), S( 10, -16),
            S(-91,  34), S(  8, -14), S(-40,  -1), S(-23,   7), S( 10,  -6), S(-11,   0), S( 13, -16), S( 11, -23)
        },
        {
            S(-15, -14), S(-10, -16), S(-132,   7), S(-94,   6), S(-48,   0), S(-64,  -1), S(-27,  -6), S( 11, -19),
            S(-23,   1), S( 13, -11), S(-25,   0), S(-31, -12), S( 15,  -8), S( 50, -17), S( -1,  -6), S(-45,  -4),
            S( -6,  -2), S( 27, -17), S( 30, -14), S(  9, -12), S(  6, -11), S( 36,  -8), S( 14,  -8), S(  3,   3),
            S( 11,  -9), S( 16, -11), S(  5,  -2), S( 36,  -6), S( 31,  -7), S( 27,  -8), S( 26, -19), S(  6,  -1),
            S( 16, -15), S( 19, -13), S( 24,  -8), S( 29,  -2), S( 44, -14), S( 27, -11), S( 25, -21), S( 37, -17),
            S( 25, -15), S( 36, -16), S( 32,  -7), S( 33,  -7), S( 36,  -5), S( 51, -20), S( 37, -19), S( 38, -17),
            S( 44, -16), S( 44, -24), S( 39, -17), S( 29, -11), S( 37,  -9), S( 46, -20), S( 64, -26), S( 42, -28),
            S(  7, -13), S( 38,  -7), S( 34, -12), S( 25,  -9), S( 34, -13), S( 29, -11), S( -7,   1), S( 21, -14)
        },
        {
            S( -7,  23), S( -4,  20), S(-50,  38), S(  5,  22), S( -1,  26), S(-46,  33), S(-17,  25), S(-15,  22),
            S(  3,  19), S(  9,  20), S( 40,  13), S( 38,  13), S( 53,  -1), S( 41,   8), S( -9,  23), S(  3,  17),
            S( -3,  15), S( 21,  12), S( 28,   8), S( 30,  10), S(  9,   9), S( 46,  -1), S( 68,  -6), S( 14,   2),
            S(-16,  15), S( -1,   9), S( 12,  17), S( 20,   6), S( 25,   7), S( 36,   4), S(  1,   4), S(-12,  12),
            S(-28,  14), S(-13,  13), S( -0,  13), S(  2,   8), S( 16,   0), S( -3,   2), S( 11,  -2), S(-19,   2),
            S(-29,   8), S( -9,   5), S(  0,  -2), S( -4,   3), S( 11,  -4), S(  8,  -8), S(  4,  -2), S(-22,  -5),
            S(-23,   3), S(  3,  -3), S( -1,   2), S( 11,   3), S( 24, -10), S( 27, -11), S( 15, -12), S(-45,   8),
            S(  5,  -5), S( 11,  -0), S( 24,  -1), S( 33,  -6), S( 37,  -9), S( 22,  -7), S( -8,   3), S(  6, -21)
        },
        {
            S(-17, -12), S(-54,  56), S(-39,  51), S(-50,  55), S( 74,  -7), S( 73, -12), S( 42,  -2), S( 57,  15),
            S(-13,  -8), S(-49,  27), S(-18,  31), S(-10,  44), S(-70,  84), S( 33,  12), S(  1,  40), S( 58,   6),
            S(  8,  -1), S( -1,   7), S( 15,  -3), S(-28,  71), S(  4,  49), S( 53,  15), S( 28,  23), S( 48,  19),
            S(-21,  43), S(-18,  37), S(-23,  31), S(-28,  45), S( -8,  50), S(  3,  33), S( -0,  75), S(  1,  64),
            S(  8,   4), S(-24,  42), S(  7,  10), S(  2,  30), S(  3,  26), S( 13,  21), S( 13,  40), S( 12,  38),
            S( -0,  12), S( 31, -42), S( 13,  -0), S( 26, -14), S( 21,   5), S( 24,   8), S( 38,   7), S( 26,  27),
            S(  2,  -8), S( 18, -27), S( 34, -31), S( 35, -26), S( 42, -22), S( 44, -28), S( 27, -41), S( 40, -30),
            S( 33, -35), S( 31, -37), S( 35, -25), S( 44, -33), S( 30,  -7), S( 13, -17), S( 16, -14), S(-20, -19)
        },
        {
            S(-127, -63), S(162, -67), S(164, -48), S( 80, -35), S(-115,  13), S(-68,  28), S( 47,  -5), S( 36, -22),
            S(185, -50), S( 97,   1), S( 53,   7), S(122,  -1), S( 51,  14), S( 59,  30), S(  0,  26), S(-137,  36),
            S( 66,  -6), S( 99,   8), S(119,   7), S( 32,  16), S( 64,  13), S(134,  31), S(149,  24), S(-10,  12),
            S( 18, -16), S(  9,  20), S( 34,  24), S(-16,  36), S(-24,  35), S(-25,  42), S(  6,  30), S(-87,  17),
            S(-78,  -5), S( 42,  -7), S(-39,  32), S(-91,  44), S(-98,  49), S(-66,  39), S(-62,  24), S(-96,   5),
            S( -1, -19), S(  4,   1), S(-29,  22), S(-57,  34), S(-62,  38), S(-52,  31), S(-10,  13), S(-46,  -0),
            S( 12, -33), S( 26, -11), S(-17,  14), S(-70,  26), S(-50,  26), S(-27,  16), S( 18,  -3), S( 15, -22),
            S(-24, -59), S( 43, -43), S( 14, -21), S(-73,   2), S(  1, -22), S(-34,  -4), S( 36, -34), S( 17, -61)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-36,  18), S(-18, -32), S( 25,  83), S(  3,  95), S(  7,  50), S( -9,  40), S( 26,  54), S( 46, 101),
        S( 35, 151), S( -2, 161), S( 32, 123), S(  1, 124), S( 40,  84), S( -3, 115), S(-37, 138), S(-40, 151),
        S( 18,  86), S( -0,  80), S( 12,  66), S( -8,  63), S( -4,  49), S( 32,  49), S( -5,  79), S( -9,  78),
        S(  5,  49), S(-22,  48), S(-26,  43), S(-26,  38), S(-21,  39), S(-16,  41), S(-18,  53), S( 14,  47),
        S( -2,  21), S(-18,  29), S(-17,  24), S(-41,  31), S(-13,  21), S( 22,  14), S(  8,  30), S( 21,  18),
        S(-12,  18), S(  1,  22), S(  5,  14), S(-42,  38), S(-16,  25), S(  5,  19), S( 17,  23), S(-17,  27),
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
            S(-108, -152), S(-46, -85), S(-36, -43), S(-26, -16), S( -8, -12), S( -2,  -2), S(  7,   2), S( 18,   4),
            S( 31,  -2), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 19, -61), S(-47, -59), S(-35, -18), S(-20,   0), S( -9,   9), S(  1,  17), S(  7,  24), S( 12,  28),
            S( 15,  33), S( 20,  36), S( 27,  35), S( 50,  32), S( 29,  48), S( 55,  33), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(114,  41), S(-50, -46), S(-50, -71), S(-42, -49), S(-34, -25), S(-27, -17), S(-20,  -6), S(-16,  -2),
            S( -7,  -2), S(  3,  -0), S( 14,   1), S( 25,   4), S( 35,   8), S( 40,  10), S( 59,   3), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(-91, -110), S(-25, -270), S(-19, -136), S(-22, -46), S(-13, -42),
            S(-13, -43), S( -7, -33), S( -5, -17), S( -4,  -5), S( -1,  10), S(  3,  15), S(  5,  23), S(  5,  39),
            S(  9,  37), S(  7,  55), S(  8,  50), S( 16,  58), S( 16,  70), S( 35,  63), S( 21,  76), S( 39,  67),
            S( 32,  73), S(134,   8), S( 18,  76), S(202, -27)
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
        S(  0,   0), S( 16,  -9), S( 19,  -4), S( 30,  -8), S( 16,   7), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> pinnedBonus =
    {
        S(  0,   0), S(-28, -67), S( -2, -79), S(-37, -48), S(-77, -58), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> protectedByPawnBonus =
    {
        S(  0,   0), S(  5,   6), S( -3,  14), S(  2,  -1), S(-10,   8), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> outpostBonus =
    {
        S(  0,   0), S( 20,  10), S( 37,  -6), S( 16,  17), S( 18,   5), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOwnPawnBonus =
    {
        S( -1,  24), S(  6,  15), S( 10,   4), S(  9,   0), S(  8,  -7), S(  4, -14), S( -2, -19), S( -2, -40),
        S(-34, -69)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOpponentPawnBonus =
    {
        S( 11, -23), S( -8, -12), S(-10,  -7), S(-10,  -5), S( -7,  -1), S( -6,   1), S( -3,   3), S( -1,  37),
        S(-45, -34)
    };

    static constexpr PhaseScore doubledPawnBonus = S(-7, -12);
    static constexpr PhaseScore doubledPassedPawnBonus = S(-6, -28);
    static constexpr PhaseScore blockedPassedPawnBonus = S(16, -40);
    static constexpr PhaseScore protectedPawnBonus = S(14, 10);
    static constexpr PhaseScore weakPawnBonus = S(-10, -8);
    static constexpr PhaseScore bishopPairBonus = S(30, 52);
    static constexpr PhaseScore rookOpenFileBonus = S(17, -2);
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