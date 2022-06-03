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

    static constexpr int ParameterCount = 6 + 6 * 64 + 64 + 6 * 28 + 6 + 6 + 6 + 2 * 9 + 8;

    static constexpr std::array<PhaseScore, 6> material =
    {
        S(100, 141), S(403, 287), S(390, 290), S(547, 547), S(1204, 930), S(  0,   0)
    };

    static constexpr std::array<std::array<PhaseScore, 64>, 6> psts =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(100, 173), S(137, 200), S( 31,  78), S( 83,  32), S( 58,  90), S(150,  76), S(-20, 121), S(-111, 110),
            S(-21, -25), S(  1, -41), S(-21, -29), S(  7, -57), S(  3, -46), S( 77, -59), S( 43, -44), S(  5, -40),
            S(-32, -40), S( -9, -49), S(-15, -53), S(  7, -67), S(  6, -55), S( -1, -53), S(  1, -51), S(-28, -48),
            S(-40, -47), S(-23, -50), S(-11, -59), S(  0, -62), S(  7, -61), S( -1, -63), S( -4, -60), S(-33, -60),
            S(-38, -56), S(-26, -58), S(-22, -57), S(-17, -52), S( -7, -52), S(-12, -56), S( 14, -72), S(-25, -65),
            S(-32, -50), S(-17, -60), S(-22, -46), S( -4, -54), S( -7, -44), S( 26, -59), S( 23, -70), S(-13, -69),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-159,   7), S(-113,  -6), S(-79,  20), S(-62,   0), S( 53, -13), S(-104,   6), S(-34, -33), S(-97, -35),
            S(-72,   6), S(-55,  19), S( 68, -20), S(  0,  19), S(  5,   9), S( 41, -16), S(  6,  -2), S(-13, -17),
            S(-57,  -3), S( 37, -13), S( -4,  23), S( 18,  21), S( 40,  11), S( 94,  -3), S( 40,  -9), S( 51, -28),
            S( -0,  -1), S( 12,   5), S( -9,  29), S( 40,  26), S(  8,  32), S( 41,  17), S( -1,  17), S( 31,  -1),
            S(  0,  -2), S(  8,  -4), S(  1,  19), S(  6,  27), S( 17,  21), S( 10,  19), S( 21,   7), S( 14,   1),
            S(-14, -10), S(-20,   3), S( -8,  -1), S(-13,  21), S(  3,  15), S( -6,  -2), S( 13, -16), S(-12,  -8),
            S( -2, -17), S(-35,  -0), S(-18,   2), S( 13,  -3), S(  9,   1), S( 19, -11), S( -0,  -5), S( 11, -17),
            S(-91,  34), S(  9, -16), S(-40,  -2), S(-23,   8), S( 10,  -6), S(-11,   1), S( 13, -17), S( 11, -25)
        },
        {
            S(-12, -14), S(-12, -14), S(-132,   7), S(-95,   6), S(-48,   1), S(-65,  -0), S(-29,  -5), S( 11, -19),
            S(-23,   1), S( 14, -11), S(-25,   1), S(-32, -11), S( 15,  -9), S( 51, -17), S( -1,  -5), S(-46,  -4),
            S( -7,  -1), S( 32, -18), S( 33, -14), S( 12, -11), S(  9, -10), S( 39,  -8), S( 14,  -7), S(  3,   2),
            S( 11,  -9), S( 18, -11), S( 12,  -3), S( 39,  -7), S( 33,  -8), S( 27,  -7), S( 25, -18), S(  5,  -1),
            S( 18, -15), S( 21, -14), S( 24,  -7), S( 31,  -2), S( 44, -13), S( 25, -10), S( 24, -20), S( 35, -16),
            S( 25, -14), S( 34, -16), S( 30,  -6), S( 32,  -6), S( 32,  -4), S( 48, -19), S( 33, -18), S( 38, -17),
            S( 43, -15), S( 44, -24), S( 38, -16), S( 29, -10), S( 36,  -9), S( 45, -19), S( 63, -25), S( 42, -28),
            S(  5, -13), S( 36,  -7), S( 34, -12), S( 24,  -8), S( 33, -13), S( 29, -10), S( -8,   1), S( 20, -13)
        },
        {
            S( -8,  23), S( -1,  19), S(-50,  38), S(  6,  21), S( -1,  26), S(-47,  33), S(-17,  25), S(-13,  20),
            S(  4,  18), S(  8,  20), S( 40,  12), S( 39,  13), S( 56,  -1), S( 39,   8), S(-10,  23), S(  3,  17),
            S( -1,  14), S( 24,  12), S( 30,   8), S( 34,   9), S(  9,   9), S( 47,  -1), S( 66,  -5), S( 13,   2),
            S(-14,  14), S( -0,   9), S( 13,  17), S( 22,   6), S( 25,   7), S( 37,   4), S(  0,   4), S(-11,  12),
            S(-27,  14), S(-14,  12), S( -1,  13), S(  1,   8), S( 16,  -1), S( -5,   1), S(  8,  -3), S(-19,   2),
            S(-30,   8), S(-13,   5), S( -2,  -2), S( -6,   2), S(  7,  -5), S(  4,  -9), S( -2,  -4), S(-23,  -6),
            S(-23,   2), S(  3,  -3), S( -1,   2), S( 11,   2), S( 23, -10), S( 27, -12), S( 14, -13), S(-45,   7),
            S(  5,  -5), S( 11,  -0), S( 24,  -1), S( 33,  -6), S( 37, -10), S( 22,  -7), S( -8,   3), S(  6, -21)
        },
        {
            S(-16, -12), S(-54,  56), S(-36,  49), S(-50,  55), S( 78,  -9), S( 74, -14), S( 45,  -4), S( 59,  13),
            S(-13,  -8), S(-48,  27), S(-18,  31), S(-12,  46), S(-71,  85), S( 32,  13), S(  1,  41), S( 59,   5),
            S(  8,  -1), S(  1,   7), S( 16,  -2), S(-26,  71), S(  5,  50), S( 53,  18), S( 27,  23), S( 48,  18),
            S(-21,  44), S(-17,  37), S(-21,  31), S(-27,  46), S( -7,  51), S(  4,  33), S( -0,  75), S(  2,  64),
            S(  9,   4), S(-24,  42), S(  6,   9), S(  3,  30), S(  3,  26), S( 12,  21), S( 13,  37), S( 12,  39),
            S( -1,  12), S( 29, -42), S( 11,   1), S( 24, -13), S( 19,   4), S( 21,   8), S( 36,   5), S( 25,  29),
            S(  1,  -7), S( 17, -27), S( 34, -30), S( 35, -25), S( 42, -22), S( 44, -28), S( 26, -39), S( 39, -29),
            S( 33, -34), S( 31, -37), S( 36, -24), S( 44, -32), S( 30,  -7), S( 13, -17), S( 15, -14), S(-19, -21)
        },
        {
            S(-117, -65), S(163, -67), S(165, -47), S( 82, -35), S(-115,  13), S(-66,  27), S( 48,  -6), S( 38, -22),
            S(183, -50), S( 96,   1), S( 54,   7), S(123,  -2), S( 50,  14), S( 57,  31), S( -2,  26), S(-137,  36),
            S( 65,  -5), S( 98,   8), S(119,   7), S( 32,  16), S( 64,  13), S(134,  31), S(149,  23), S( -8,  11),
            S( 18, -16), S(  9,  20), S( 34,  24), S(-16,  36), S(-24,  35), S(-25,  43), S(  5,  30), S(-89,  18),
            S(-76,  -5), S( 41,  -7), S(-40,  32), S(-91,  44), S(-99,  49), S(-66,  39), S(-61,  23), S(-95,   5),
            S( -0, -20), S(  3,   1), S(-29,  22), S(-57,  34), S(-62,  38), S(-52,  31), S(-10,  13), S(-46,  -0),
            S( 11, -33), S( 25, -10), S(-17,  14), S(-71,  26), S(-51,  26), S(-27,  16), S( 17,  -3), S( 14, -22),
            S(-24, -59), S( 43, -43), S( 14, -21), S(-73,   2), S(  0, -22), S(-34,  -4), S( 35, -34), S( 17, -61)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-36,  18), S(-18, -31), S( 23,  80), S(  3,  95), S(  8,  53), S( -7,  43), S( 25,  53), S( 42,  99),
        S( 35, 151), S( -1, 161), S( 37, 121), S(  3, 117), S( 41,  89), S( -3, 115), S(-37, 139), S(-39, 151),
        S( 19,  86), S( -0,  80), S( 13,  66), S( -7,  63), S( -4,  49), S( 32,  49), S( -3,  78), S( -7,  78),
        S(  6,  49), S(-22,  48), S(-25,  43), S(-26,  38), S(-21,  39), S(-15,  41), S(-18,  53), S( 15,  46),
        S( -2,  21), S(-17,  29), S(-17,  24), S(-41,  30), S(-12,  21), S( 22,  13), S(  8,  29), S( 21,  18),
        S(-11,  18), S(  3,  22), S(  7,  13), S(-40,  37), S(-14,  25), S(  6,  19), S( 18,  23), S(-16,  27),
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
            S(-111, -144), S(-44, -81), S(-35, -40), S(-24, -13), S( -6, -10), S(  0,  -1), S(  9,   4), S( 20,   5),
            S( 33,  -0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 18, -59), S(-47, -59), S(-35, -18), S(-20,  -0), S( -9,   9), S(  1,  17), S(  7,  24), S( 12,  28),
            S( 15,  33), S( 21,  35), S( 28,  35), S( 50,  31), S( 27,  48), S( 54,  33), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(105,  38), S(-49, -48), S(-50, -70), S(-42, -48), S(-34, -24), S(-27, -17), S(-20,  -6), S(-16,  -2),
            S( -7,  -2), S(  3,   0), S( 14,   2), S( 24,   5), S( 35,   9), S( 40,  11), S( 59,   4), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(-89, -104), S(-26, -261), S(-18, -136), S(-22, -46), S(-13, -41),
            S(-13, -43), S( -7, -32), S( -5, -16), S( -4,  -4), S( -1,  11), S(  3,  16), S(  5,  22), S(  5,  39),
            S(  8,  37), S(  6,  55), S(  8,  50), S( 16,  58), S( 15,  71), S( 35,  62), S( 25,  73), S( 40,  65),
            S( 34,  70), S(132,   7), S( 20,  72), S(187, -22)
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
        S(  0,   0), S(-27, -67), S( -1, -79), S(-36, -49), S(-77, -59), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 6> protectedByPawnBonus =
    {
        S(  0,   0), S(  7,  15), S(  2,  16), S(  7,  12), S( -8,  17), S(  0,   0)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOwnPawnBonus =
    {
        S( -2,  24), S(  6,  15), S( 10,   4), S(  8,   0), S(  7,  -7), S(  3, -14), S( -2, -18), S( -2, -39),
        S(-36, -58)
    };

    static constexpr std::array<PhaseScore, 9> bishopSameColorSquareOpponentPawnBonus =
    {
        S( 12, -23), S( -8, -12), S( -9,  -7), S(-10,  -5), S( -7,  -1), S( -5,   1), S( -2,   3), S( -0,  37),
        S(-45, -29)
    };

    static constexpr PhaseScore doubledPawnBonus = S(-7, -12);
    static constexpr PhaseScore doubledPassedPawnBonus = S(-6, -27);
    static constexpr PhaseScore blockedPassedPawnBonus = S(16, -40);
    static constexpr PhaseScore protectedPawnBonus = S(15, 10);
    static constexpr PhaseScore weakPawnBonus = S(-11, -8);
    static constexpr PhaseScore bishopPairBonus = S(29, 52);
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
            const Bitboard attackedByOwnPawns = data.PieceAttacks[Pieces::Pawn | color];
            const bool isProtected = (posBitboard & attackedByOwnPawns) != 0;
            if(isProtected)
            {
                score += protectedByPawnBonus[pieceIndex];
                TraceIncr(protectedByPawnBonus[pieceIndex]);
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