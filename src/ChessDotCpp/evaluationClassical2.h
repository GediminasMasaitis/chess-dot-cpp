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
        TraceScores bishopPairBonus;
        TraceScores doubledPawnBonus;
        TraceScores protectedPawnBonus;
        TraceScores weakPawnBonus;
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

    static constexpr int ParameterCount = 6 + 6 * 64 + 64 + 6 * 28 + 6 + 6;

    static constexpr std::array<PhaseScore, 6> material =
    {
        S(100, 142), S(408, 280), S(387, 301), S(548, 545), S(1222, 952), S(  0,   0)
    };

    static constexpr std::array<std::array<PhaseScore, 64>, 6> psts =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S( 88, 160), S(136, 168), S( 48,  99), S( 94,  61), S( 69,  93), S(145,  78), S( -1, 127), S(-82, 145),
            S(-21, -26), S( -2, -41), S(-23, -26), S(  6, -58), S(  5, -44), S( 76, -59), S( 41, -44), S(  1, -38),
            S(-35, -40), S(-11, -48), S(-17, -52), S(  5, -65), S(  4, -54), S( -2, -53), S( -2, -51), S(-30, -49),
            S(-40, -48), S(-24, -49), S(-12, -59), S( -1, -62), S(  6, -61), S( -1, -63), S( -5, -61), S(-36, -61),
            S(-40, -57), S(-26, -57), S(-23, -57), S(-18, -50), S( -8, -51), S(-11, -56), S( 14, -73), S(-26, -67),
            S(-33, -52), S(-17, -60), S(-23, -44), S( -3, -53), S( -6, -45), S( 26, -58), S( 24, -71), S(-15, -70),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-165,  -3), S(-109, -17), S(-76,  11), S(-59, -12), S( 60, -21), S(-104,  -2), S(-32, -42), S(-98, -48),
            S(-76,  -1), S(-55,  11), S( 67, -26), S(  1,  11), S(  9,   1), S( 42, -22), S(  4,  -8), S(-16, -25),
            S(-60,  -9), S( 42, -17), S( -4,  23), S( 21,  21), S( 44,   9), S( 99,  -2), S( 44, -12), S( 53, -35),
            S( -2,  -6), S( 13,   6), S( -4,  32), S( 43,  26), S( 12,  34), S( 43,  21), S( -0,  18), S( 28,  -6),
            S( -0,  -7), S( 10,  -5), S(  2,  22), S(  9,  30), S( 17,  22), S( 14,  23), S( 23,   8), S( 14,  -2),
            S(-11, -12), S(-17,   2), S( -4,   1), S(-11,  20), S(  8,  16), S( -1,   0), S( 18, -17), S( -8, -10),
            S( -6, -19), S(-37,  -5), S(-19,  -3), S( 11,  -8), S(  7,  -5), S( 15, -16), S( -5, -11), S(  7, -24),
            S(-104,  29), S(  6, -24), S(-43, -10), S(-26,   1), S(  7, -14), S(-16,  -8), S( 12, -27), S(  5, -33)
        },
        {
            S(-12, -14), S(-12, -16), S(-132,   5), S(-91,   2), S(-46,  -1), S(-65,  -4), S(-26,  -5), S( 15, -25),
            S(-22,  -1), S( 16, -10), S(-27,   1), S(-31, -12), S( 14,  -9), S( 50, -17), S(  1,  -6), S(-46,  -5),
            S( -7,  -0), S( 33, -15), S( 38, -10), S( 13,  -8), S( 12,  -7), S( 41,  -7), S( 15,  -4), S(  1,   1),
            S(  9,  -7), S( 26,  -6), S( 10,   4), S( 39,   3), S( 33,   1), S( 28,  -1), S( 24, -13), S(  4,   1),
            S( 23, -11), S( 21,  -8), S( 24,   1), S( 30,   7), S( 44,  -6), S( 24,  -3), S( 25, -14), S( 34, -12),
            S( 21,  -9), S( 35, -10), S( 29,   0), S( 32,  -0), S( 33,   3), S( 50, -12), S( 34, -12), S( 36, -11),
            S( 41, -10), S( 41, -23), S( 37, -14), S( 28, -11), S( 36,  -8), S( 42, -18), S( 62, -24), S( 40, -26),
            S(  1,  -9), S( 35,  -4), S( 32, -14), S( 23,  -9), S( 30, -14), S( 28, -12), S( -9,   0), S( 18,  -8)
        },
        {
            S( 11,  18), S( 19,  15), S(-28,  32), S( 25,  17), S( 17,  21), S(-39,  30), S(-14,  23), S( -1,  16),
            S(  7,  18), S( 10,  20), S( 43,  12), S( 43,  12), S( 59,  -2), S( 43,   7), S( -8,  23), S(  6,  16),
            S( -1,  14), S( 24,  12), S( 29,   9), S( 34,  10), S(  8,  10), S( 46,  -0), S( 68,  -6), S( 14,   2),
            S(-15,  15), S(  1,   9), S( 16,  17), S( 23,   6), S( 26,   7), S( 36,   6), S(  3,   5), S(-13,  13),
            S(-29,  16), S(-14,  13), S( -1,  13), S(  3,   9), S( 15,   0), S( -4,   2), S( 11,  -2), S(-20,   3),
            S(-31,   9), S(-11,   6), S( -1,  -2), S( -6,   2), S(  9,  -4), S(  6,  -8), S(  2,  -3), S(-21,  -5),
            S(-27,   4), S(  0,  -4), S( -3,   1), S(  7,   2), S( 19, -10), S( 20, -11), S( 10, -12), S(-49,   8),
            S(  1,  -4), S(  8,   0), S( 21,  -1), S( 30,  -5), S( 34,  -9), S( 19,  -8), S(-11,   3), S(  4, -21)
        },
        {
            S( -2, -18), S(-32,  43), S(-15,  39), S(-25,  42), S( 96, -19), S( 98, -30), S( 63, -13), S( 74,   5),
            S(-15,  -9), S(-49,  26), S(-21,  34), S(-14,  49), S(-73,  86), S( 36,  12), S( -1,  43), S( 56,   6),
            S(  6,  -4), S( -2,   6), S( 17,  -5), S(-30,  73), S( 11,  49), S( 50,  19), S( 26,  25), S( 45,  17),
            S(-24,  41), S(-13,  32), S(-23,  32), S(-30,  50), S( -8,  53), S(  0,  37), S( -2,  75), S(  2,  61),
            S( 14,  -6), S(-28,  45), S(  3,  13), S( -4,  35), S(  1,  27), S(  6,  24), S(  9,  41), S(  9,  39),
            S( -8,  16), S( 23, -35), S(  4,   6), S( 17,  -9), S( 12,   8), S( 13,  14), S( 27,  11), S( 18,  33),
            S( -1,  -7), S( 14, -29), S( 32, -34), S( 33, -31), S( 40, -28), S( 40, -35), S( 23, -44), S( 35, -32),
            S( 30, -36), S( 29, -40), S( 34, -29), S( 43, -37), S( 28, -11), S( 11, -25), S( 12, -20), S(-24, -22)
        },
        {
            S(-73, -74), S(175, -69), S(169, -49), S( 97, -37), S(-121,  15), S(-69,  30), S( 63,  -8), S( 49, -23),
            S(192, -51), S( 94,   1), S( 53,   7), S(127,  -3), S( 52,  13), S( 52,  32), S( -8,  28), S(-134,  36),
            S( 81,  -9), S( 92,   7), S(122,   5), S( 32,  14), S( 59,  13), S(131,  32), S(146,  24), S( -7,  13),
            S( 18, -16), S( 13,  20), S( 39,  22), S(-16,  35), S(-25,  34), S(-22,  42), S(  8,  30), S(-88,  19),
            S(-67,  -7), S( 41,  -8), S(-38,  31), S(-93,  44), S(-99,  48), S(-66,  40), S(-58,  23), S(-94,   7),
            S(  1, -19), S(  2,   1), S(-33,  23), S(-58,  34), S(-66,  39), S(-53,  32), S(-10,  14), S(-43,   2),
            S( 12, -31), S( 24, -10), S(-19,  15), S(-72,  26), S(-52,  27), S(-29,  18), S( 17,  -2), S( 15, -20),
            S(-25, -58), S( 43, -43), S( 13, -20), S(-76,   4), S( -2, -20), S(-35,  -3), S( 35, -33), S( 17, -58)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-28,  28), S(-14,  -2), S(  7,  51), S( -8,  60), S( -2,  42), S( -4,  36), S(  5,  44), S( 10,  62),
        S( 37, 149), S(  2, 159), S( 41, 111), S(  6, 110), S( 45,  76), S(  4, 105), S(-33, 132), S(-37, 145),
        S( 22,  81), S(  4,  74), S( 18,  57), S(  1,  49), S(  4,  35), S( 36,  38), S( -4,  71), S( -0,  71),
        S( 11,  44), S(-20,  43), S(-20,  34), S(-18,  26), S(-13,  25), S(-11,  29), S(-22,  46), S( 20,  40),
        S(  5,  15), S(-15,  21), S(-15,  15), S(-34,  15), S( -6,   8), S( 27,  -0), S(  6,  23), S( 27,  12),
        S( -5,  13), S(  6,  14), S( 11,  -2), S(-32,  19), S( -9,  18), S( 16,   3), S( 14,  15), S(  1,  13),
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
            S(-105, -81), S(-46, -58), S(-36, -19), S(-25,   6), S( -7,   8), S( -2,  16), S(  7,  18), S( 18,  18),
            S( 32,  10), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 16, -44), S(-43, -64), S(-32, -23), S(-15,  -6), S( -4,   2), S(  5,   9), S( 11,  15), S( 16,  19),
            S( 19,  22), S( 25,  24), S( 33,  21), S( 56,  15), S( 33,  27), S( 64,  13), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 42,  15), S(-54, -26), S(-47, -60), S(-39, -38), S(-31, -12), S(-25,  -5), S(-18,   6), S(-13,  10),
            S( -4,   8), S(  7,   9), S( 19,  11), S( 29,  13), S( 40,  16), S( 44,  18), S( 60,  11), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(-99, -65), S(-52, -137), S(-19, -149), S(-22, -61), S(-13, -56),
            S(-13, -56), S( -7, -44), S( -5, -26), S( -4, -14), S( -2,   1), S(  3,   6), S(  6,  12), S(  5,  28),
            S(  9,  25), S(  7,  42), S(  9,  37), S( 17,  45), S( 18,  55), S( 36,  49), S( 27,  57), S( 43,  50),
            S( 38,  55), S( 89,  16), S( 31,  51), S( 79,  22)
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
        S(  0,   0), S( 15,  -9), S( 20,  -4), S( 29,  -9), S( 17,   5), S(  0,   0)
    };

    static constexpr PhaseScore bishopPairBonus = S(29, 54);
    static constexpr PhaseScore doubledPawnBonus = S(-6, -14);
    static constexpr PhaseScore protectedPawnBonus = S(14, 10);
    static constexpr PhaseScore weakPawnBonus = S(-11, -9);
    static constexpr PhaseScore rookOpenFileBonus = S(16, -4);
    static constexpr PhaseScore rookSemiOpenFileBonus = S(1, 8);

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

            // PASSED PAWNS
            const Bitboard opponentPawnsInFront = inFront & board.BitBoard[opponentPawn];
            const Bitboard passBitboard = inFront & (opponentPawnControl | ownPawnsInFront | opponentPawnsInFront);
            const auto isPassed = passBitboard == 0;
            if (isPassed)
            {
                score += passedPawnPst[GetRelativeInverse(color, pos)];
                TraceIncr(passedPawnPst[GetRelativeInverse(color, pos)]);
            }

            // WEAK PAWNS
            const Bitboard behind = InFront.ColumnSortOfBehind[color][pos];
            const Bitboard ownControlledBehind = behind & ownPawnControl;
            const auto isWeak = ownControlledBehind == 0;
            if (isWeak)
            {
                score += weakPawnBonus;
                TraceIncr(weakPawnBonus);
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