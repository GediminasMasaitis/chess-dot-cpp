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
        TraceScores doubledPassedPawnBonus;
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

    static constexpr int ParameterCount = 6 + 6 * 64 + 64 + 6 * 28 + 6 + 7;

    static constexpr std::array<PhaseScore, 6> material =
    {
        S(100, 144), S(414, 286), S(394, 302), S(557, 557), S(1239, 964), S(  0,   0)
    };

    static constexpr std::array<std::array<PhaseScore, 64>, 6> psts =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S( 92, 164), S(140, 179), S( 45,  93), S( 92,  53), S( 68,  94), S(148,  77), S( -6, 124), S(-90, 136),
            S(-21, -25), S(  0, -42), S(-22, -28), S(  7, -57), S(  7, -44), S( 81, -60), S( 45, -45), S(  4, -39),
            S(-34, -39), S(-10, -48), S(-16, -53), S(  7, -67), S(  5, -54), S( -0, -53), S( -1, -52), S(-28, -49),
            S(-40, -47), S(-24, -49), S(-11, -59), S(  0, -62), S(  7, -61), S(  0, -63), S( -2, -62), S(-34, -62),
            S(-39, -57), S(-25, -58), S(-22, -57), S(-17, -51), S( -6, -51), S(-10, -56), S( 16, -73), S(-24, -67),
            S(-32, -51), S(-16, -59), S(-22, -45), S( -2, -54), S( -5, -43), S( 28, -58), S( 27, -72), S(-13, -70),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-168,  -2), S(-110, -16), S(-78,  13), S(-61, -10), S( 56, -19), S(-106,  -1), S(-32, -40), S(-99, -47),
            S(-76,  -0), S(-56,  13), S( 67, -25), S(  1,  13), S(  8,   2), S( 42, -21), S(  5,  -7), S(-17, -24),
            S(-61,  -8), S( 43, -16), S( -4,  25), S( 21,  23), S( 44,  10), S(100,  -1), S( 44, -12), S( 54, -33),
            S( -2,  -4), S( 13,   7), S( -5,  33), S( 43,  28), S( 12,  35), S( 44,  23), S( -1,  19), S( 29,  -5),
            S( -0,  -5), S( 10,  -4), S(  2,  23), S(  9,  32), S( 18,  24), S( 13,  24), S( 23,   9), S( 14,  -1),
            S(-11, -11), S(-17,   4), S( -4,   3), S(-11,  22), S(  7,  18), S( -1,   2), S( 19, -16), S( -8,  -8),
            S( -5, -18), S(-37,  -4), S(-19,  -2), S( 12,  -7), S(  7,  -4), S( 15, -15), S( -5,  -9), S(  8, -23),
            S(-104,  30), S(  7, -23), S(-43,  -9), S(-26,   2), S(  7, -13), S(-16,  -7), S( 12, -25), S(  6, -32)
        },
        {
            S(-13, -15), S(-12, -17), S(-133,   4), S(-94,   3), S(-49,  -1), S(-67,  -4), S(-30,  -6), S( 16, -25),
            S(-22,  -2), S( 16, -10), S(-27,   1), S(-32, -12), S( 15, -10), S( 51, -17), S(  1,  -6), S(-48,  -5),
            S( -7,  -1), S( 34, -16), S( 38, -10), S( 14,  -8), S( 12,  -8), S( 41,  -7), S( 15,  -5), S(  1,   1),
            S( 10,  -8), S( 26,  -6), S( 10,   4), S( 40,   2), S( 33,   0), S( 28,  -1), S( 25, -14), S(  4,   1),
            S( 23, -11), S( 21,  -8), S( 24,   1), S( 31,   7), S( 44,  -6), S( 24,  -4), S( 26, -14), S( 34, -13),
            S( 22, -10), S( 35, -10), S( 30,  -0), S( 32,  -1), S( 33,   3), S( 50, -13), S( 34, -12), S( 37, -12),
            S( 42, -11), S( 42, -24), S( 37, -14), S( 28, -12), S( 37,  -9), S( 43, -18), S( 63, -25), S( 40, -26),
            S(  1, -10), S( 36,  -5), S( 33, -14), S( 23,  -9), S( 30, -15), S( 28, -13), S(-11,  -0), S( 18,  -9)
        },
        {
            S( 11,  18), S( 17,  15), S(-29,  33), S( 25,  17), S( 16,  21), S(-44,  32), S(-16,  24), S( -1,  17),
            S(  7,  19), S( 10,  20), S( 43,  13), S( 43,  12), S( 59,  -2), S( 43,   7), S( -8,  23), S(  6,  16),
            S( -1,  15), S( 25,  13), S( 29,   9), S( 35,  10), S(  8,  10), S( 45,   0), S( 68,  -6), S( 14,   2),
            S(-15,  14), S(  1,   9), S( 17,  17), S( 23,   6), S( 27,   7), S( 37,   5), S(  3,   5), S(-13,  13),
            S(-29,  16), S(-13,  13), S( -1,  13), S(  3,   8), S( 15,  -0), S( -4,   2), S( 11,  -2), S(-20,   3),
            S(-31,   9), S(-11,   6), S( -1,  -3), S( -6,   2), S(  9,  -4), S(  6,  -8), S(  2,  -3), S(-21,  -5),
            S(-27,   4), S(  0,  -3), S( -3,   1), S(  8,   2), S( 20, -11), S( 20, -11), S( 11, -13), S(-49,   8),
            S(  1,  -4), S(  8,   0), S( 22,  -1), S( 31,  -5), S( 34,  -9), S( 19,  -8), S(-11,   2), S(  4, -22)
        },
        {
            S( -1, -19), S(-32,  44), S(-17,  41), S(-29,  45), S( 93, -17), S( 89, -23), S( 57,  -9), S( 76,   5),
            S(-15,  -9), S(-49,  27), S(-22,  35), S(-14,  50), S(-75,  89), S( 34,  15), S( -2,  45), S( 58,   6),
            S(  7,  -4), S( -2,   6), S( 18,  -5), S(-30,  75), S( 11,  51), S( 49,  21), S( 26,  26), S( 46,  18),
            S(-24,  42), S(-13,  32), S(-24,  33), S(-30,  51), S( -8,  54), S(  1,  37), S( -1,  75), S(  2,  62),
            S( 14,  -6), S(-28,  45), S(  4,  13), S( -3,  36), S(  1,  27), S(  6,  25), S( 10,  42), S(  9,  39),
            S( -7,  16), S( 24, -35), S(  5,   6), S( 18,  -9), S( 12,   8), S( 14,  14), S( 28,  11), S( 19,  34),
            S( -1,  -7), S( 15, -30), S( 33, -34), S( 34, -31), S( 41, -28), S( 41, -35), S( 24, -45), S( 37, -33),
            S( 31, -37), S( 29, -41), S( 34, -29), S( 44, -37), S( 28, -12), S( 12, -25), S( 13, -21), S(-23, -22)
        },
        {
            S(-87, -74), S(172, -69), S(168, -49), S( 93, -37), S(-116,  14), S(-68,  29), S( 58,  -7), S( 42, -22),
            S(185, -50), S( 97,   0), S( 56,   6), S(130,  -3), S( 52,  13), S( 54,  32), S( -4,  27), S(-138,  37),
            S( 75,  -7), S( 94,   7), S(125,   5), S( 35,  14), S( 63,  12), S(135,  32), S(151,  24), S(-10,  13),
            S( 18, -16), S( 15,  20), S( 39,  22), S(-16,  35), S(-24,  34), S(-22,  43), S(  8,  31), S(-88,  19),
            S(-70,  -6), S( 43,  -9), S(-38,  31), S(-93,  44), S(-100,  49), S(-66,  40), S(-58,  24), S(-96,   7),
            S( -0, -19), S(  2,   1), S(-33,  23), S(-59,  35), S(-66,  39), S(-54,  33), S(-10,  14), S(-44,   2),
            S( 12, -32), S( 24, -10), S(-20,  15), S(-73,  26), S(-52,  27), S(-30,  18), S( 17,  -2), S( 15, -21),
            S(-25, -59), S( 44, -43), S( 13, -20), S(-77,   3), S( -2, -21), S(-35,  -3), S( 36, -34), S( 17, -59)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-29,  26), S(-14, -11), S( 13,  59), S( -3,  70), S(  1,  42), S( -6,  39), S( 13,  48), S( 20,  71),
        S( 40, 149), S(  2, 162), S( 43, 115), S(  7, 111), S( 46,  77), S(  1, 108), S(-35, 134), S(-39, 147),
        S( 23,  81), S(  6,  75), S( 19,  59), S(  2,  51), S(  4,  35), S( 37,  39), S( -2,  73), S( -3,  72),
        S( 12,  44), S(-18,  43), S(-20,  34), S(-18,  26), S(-14,  26), S( -9,  29), S(-19,  46), S( 18,  41),
        S(  5,  14), S(-15,  22), S(-12,  15), S(-34,  18), S( -3,   7), S( 29,   1), S( 11,  22), S( 26,  12),
        S( -4,  10), S(  7,  14), S( 15,   0), S(-31,  22), S( -4,   9), S( 14,   5), S( 20,  14), S( -9,  16),
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
            S(-117, -107), S(-46, -63), S(-37, -24), S(-26,   2), S( -7,   5), S( -1,  12), S(  7,  15), S( 18,  15),
            S( 33,   7), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 18, -52), S(-44, -60), S(-33, -19), S(-17,  -1), S( -6,   6), S(  4,  14), S( 10,  20), S( 15,  24),
            S( 18,  27), S( 24,  29), S( 32,  26), S( 55,  20), S( 31,  33), S( 63,  19), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 64,  23), S(-55, -30), S(-49, -64), S(-40, -41), S(-32, -15), S(-26,  -8), S(-19,   3), S(-14,   7),
            S( -5,   5), S(  6,   7), S( 18,   8), S( 28,  11), S( 40,  14), S( 44,  15), S( 60,   9), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(-101, -81), S(-42, -192), S(-19, -148), S(-22, -56), S(-13, -51),
            S(-13, -52), S( -7, -40), S( -5, -22), S( -4, -10), S( -1,   6), S(  3,  11), S(  6,  17), S(  6,  34),
            S( 10,  30), S(  8,  47), S( 10,  43), S( 18,  50), S( 18,  61), S( 37,  54), S( 27,  64), S( 43,  56),
            S( 39,  60), S(112,  10), S( 27,  59), S(115,   9)
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
        S(  0,   0), S( 16,  -9), S( 21,  -4), S( 30,  -9), S( 17,   5), S(  0,   0)
    };

    static constexpr PhaseScore bishopPairBonus = S(29, 55);
    static constexpr PhaseScore doubledPawnBonus = S(-6, -12);
    static constexpr PhaseScore doubledPassedPawnBonus = S(-9, -27);
    static constexpr PhaseScore protectedPawnBonus = S(14, 10);
    static constexpr PhaseScore weakPawnBonus = S(-11, -9);
    static constexpr PhaseScore rookOpenFileBonus = S(16, -4);
    static constexpr PhaseScore rookSemiOpenFileBonus = S(0, 8);

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