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
    class EvaluationClassical2Trace
    {
    public:
        using TraceScores = EachColor<PhaseScore>;

        PhaseScore eval;
        Phase phase;

        std::array<TraceScores, 6> material;
        std::array<EachPosition<TraceScores>, 6> psts;
        EachPosition<TraceScores> passedPawnPst;
        TraceScores bishopPairBonus;
        TraceScores doubledPawnBonus;
    };

    class EvaluationClassical2Data
    {
    public:
        EachPiece<Bitboard> PieceAttacks;
        EachPosition<Bitboard> AttacksFrom;
    };

    using Trace = EvaluationClassical2Trace;
    using Data = EvaluationClassical2Data;
    static constexpr int ParameterCount = 6 + 6 * 64 + 64 + 2;


    static constexpr std::array<PhaseScore, 6> material =
    {
        S(100, 138), S(362, 262), S(351, 289), S(491, 512), S(1074, 919), S(  0,   0)
    };

    static constexpr std::array<EachPosition<PhaseScore>, 6> psts =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S( 89, 143), S(133, 132), S( 55,  91), S(107,  64), S( 79,  85), S(139,  70), S( 19, 121), S(-53, 134),
            S(-34, -25), S( 13, -37), S(-10, -27), S( 12, -58), S( 23, -43), S( 78, -54), S( 41, -35), S(-11, -37),
            S(-34, -38), S(  4, -41), S( -1, -50), S( 16, -63), S( 17, -53), S(  4, -47), S( 12, -45), S(-35, -45),
            S(-47, -43), S(-13, -41), S(-13, -52), S(  5, -58), S(  9, -55), S( -1, -53), S(  1, -49), S(-40, -55),
            S(-44, -51), S(-16, -45), S(-12, -54), S(-18, -46), S( -5, -44), S( -3, -49), S( 24, -57), S(-27, -62),
            S(-54, -43), S(-12, -48), S(-30, -37), S(-33, -42), S(-25, -35), S( 16, -47), S( 27, -54), S(-37, -61),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-199, -31), S(-115, -21), S(-52,   4), S(-48, -17), S( 72, -27), S(-112,  -6), S(-21, -50), S(-124, -73),
            S(-84,  -9), S(-51,   7), S( 67, -18), S( 25,  10), S( 23,  -0), S( 66, -22), S( -4, -12), S(-15, -41),
            S(-54,  -9), S( 60, -13), S( 34,  20), S( 63,  16), S( 89,   0), S(129,  -7), S( 77, -14), S( 48, -37),
            S(-16,  -5), S( 16,  15), S( 15,  34), S( 53,  30), S( 37,  31), S( 72,  17), S( 17,  17), S( 20,  -9),
            S(-15,  -4), S(  4,   6), S( 13,  28), S( 11,  37), S( 26,  27), S( 18,  29), S( 16,  16), S(-10,  -7),
            S(-24, -11), S(-11,   9), S( 12,   8), S(  9,  25), S( 18,  21), S( 18,   6), S( 24, -11), S(-17, -13),
            S(-33, -25), S(-60,  -3), S(-14,   4), S( -4,   6), S( -3,   8), S( 17,  -8), S(-18, -13), S(-20, -34),
            S(-130,  -2), S(-22, -45), S(-65,  -7), S(-39,  -1), S(-17, -11), S(-30,  -7), S(-18, -44), S(-23, -56)
        },
        {
            S(-28, -12), S(  8, -19), S(-106,   1), S(-56,  -1), S(-33,  -1), S(-36,  -5), S(  6, -11), S(  3, -23),
            S(-14,  -7), S( 23,  -3), S( -9,   7), S(-17,  -5), S( 44,  -5), S( 72, -13), S( 33,  -4), S(-34, -10),
            S( -3,   1), S( 49, -11), S( 56,  -4), S( 51,  -4), S( 48,  -4), S( 75,  -2), S( 46,  -0), S( 14,   1),
            S( 11,  -5), S( 20,   6), S( 34,  10), S( 62,   9), S( 52,  12), S( 51,   6), S( 22,  -1), S(  9,   0),
            S(  7,  -5), S( 28,   2), S( 27,  12), S( 40,  18), S( 49,   6), S( 27,   8), S( 23,  -5), S( 15,  -9),
            S( 14,  -9), S( 30,  -2), S( 29,   8), S( 30,   9), S( 27,  12), S( 42,  -1), S( 31,  -6), S( 22, -14),
            S( 16, -11), S( 31, -20), S( 31,  -8), S( 14,  -3), S( 23,   0), S( 33, -10), S( 48, -19), S( 20, -31),
            S(-26, -19), S(  9,  -7), S(  0, -28), S(-10,  -5), S( -2,  -9), S(  2, -21), S(-30,  -0), S(-15, -12)
        },
        {
            S( 48,  12), S( 66,   5), S( 38,  20), S( 92,   4), S( 83,   7), S(  6,  19), S( 26,  13), S( 43,   7),
            S( 42,  10), S( 39,  13), S( 82,   4), S( 89,   3), S(105, -13), S( 95,  -6), S( 32,  11), S( 54,   2),
            S( -6,  14), S( 23,  11), S( 34,   7), S( 37,   8), S( 16,   8), S( 60,  -7), S( 77, -10), S( 23,  -4),
            S(-26,  14), S( -8,   9), S(  9,  17), S( 28,   4), S( 23,   6), S( 39,   2), S(  3,   2), S(-19,  10),
            S(-40,  15), S(-27,  15), S(-12,  16), S( -1,  10), S(  8,   1), S( -4,   1), S( 15,  -6), S(-22,  -1),
            S(-48,  11), S(-23,   9), S(-14,   3), S(-21,   8), S(  2,  -1), S( -0,  -5), S( -1,  -3), S(-33,  -5),
            S(-46,   8), S(-13,   1), S(-18,   7), S(-10,   9), S( -0,  -2), S( 10,  -5), S( -1,  -7), S(-70,  12),
            S(-20,   2), S(-13,  10), S(  1,  11), S( 11,   7), S( 13,   3), S( -2,   2), S(-31,  12), S(-21, -16)
        },
        {
            S(-25,  -1), S(-10,  39), S( 17,  35), S( 10,  39), S(117, -14), S(121, -30), S( 69, -13), S( 53,  19),
            S(-13, -15), S(-38,  31), S(  2,  36), S(  3,  52), S(-25,  80), S( 74,  12), S( 34,  31), S( 65, -11),
            S( -1, -22), S( -6,   6), S( 15,   8), S(  4,  60), S( 31,  55), S( 78,  18), S( 55,  17), S( 67,  -4),
            S(-25,  17), S(-20,  31), S(-10,  31), S( -9,  52), S(  1,  68), S( 18,  48), S(  1,  72), S(  5,  43),
            S(  1, -19), S(-23,  40), S( -1,  22), S( -4,  52), S(  2,  38), S(  6,  35), S(  8,  40), S(  6,  22),
            S(-11,  -2), S( 14, -35), S( -4,  19), S(  7,   4), S(  2,  15), S( 10,  20), S( 21,  10), S(  9,  11),
            S(-26, -14), S(  1, -23), S( 22, -36), S( 11, -18), S( 18, -17), S( 25, -29), S( 10, -44), S( 11, -32),
            S(  5, -35), S( -7, -31), S(  1, -23), S( 21, -56), S( -8,  -4), S(-20, -29), S(-29, -14), S(-44, -39)
        },
        {
            S(-47, -72), S(157, -62), S(141, -45), S( 85, -35), S(-116,  11), S(-71,  28), S( 59,  -9), S( 45, -21),
            S(174, -47), S( 72,   3), S( 34,   7), S(113,  -3), S( 43,  12), S( 37,  30), S(-30,  26), S(-118,  31),
            S( 82,  -9), S( 72,   8), S(101,   6), S( 24,  13), S( 39,  13), S(111,  29), S(123,  22), S( -5,  10),
            S( 20, -16), S( -5,  21), S( 28,  21), S(-36,  35), S(-38,  33), S(-27,  39), S(  1,  28), S(-68,  15),
            S(-60,  -9), S( 23,  -6), S(-53,  32), S(-104,  45), S(-107,  48), S(-67,  38), S(-59,  23), S(-76,   3),
            S( 19, -21), S( -1,   1), S(-33,  22), S(-66,  35), S(-66,  38), S(-56,  31), S(-10,  13), S(-28,  -1),
            S( 23, -29), S( 22, -10), S(-11,  13), S(-74,  26), S(-54,  27), S(-27,  16), S( 19,  -3), S( 26, -21),
            S( -3, -56), S( 52, -41), S( 19, -21), S(-69,   1), S(  7, -27), S(-35,  -4), S( 39, -31), S( 37, -56)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-15,  10), S(  2,   5), S(  9,  31), S( -2,  27), S( -3,  23), S(  7,  20), S(  4,  21), S(  5,  39),
        S( 50, 122), S( -8, 131), S( 41,  89), S( 12,  91), S( 42,  57), S(  7,  84), S(-26, 106), S(-29, 122),
        S( 11,  63), S( -2,  53), S(  6,  43), S( -0,  36), S( -0,  25), S( 28,  21), S(-14,  55), S( -8,  55),
        S(  3,  29), S(-28,  25), S(-23,  19), S(-22,  15), S(-20,  13), S(-15,  11), S(-21,  27), S( 15,  23),
        S( -9,   4), S(-26,   4), S(-32,   7), S(-43,   5), S(-14,  -5), S( 14, -13), S( 10,   3), S( 21,   0),
        S(-12,   3), S( -3,  -1), S(  9, -14), S(-28,   9), S(-13,   6), S( 13, -12), S( 20,  -5), S( -3,   2),
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
    };

    static constexpr PhaseScore bishopPairBonus = S(29, 46);
    static constexpr PhaseScore doubledPawnBonus = S(-14, -28);

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

        Bitboard pawns = board.BitBoard[piece];
        while (pawns != 0)
        {
            const Position pos = BitScanForward(pawns);

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

            pawns &= pawns - 1;
        }

        return score;
    }

    template<Color TColor, Piece TPiece>
    static PhaseScore EvaluatePiece(const BoardBase& board)
    {
        constexpr Color color = TColor;
        constexpr Piece pieceNoColor = TPiece;
        constexpr Piece piece = pieceNoColor | color;
        constexpr PieceIndex pieceIndex = GetPieceIndex(piece);
        PhaseScore score = 0;

        Bitboard pieces = board.BitBoard[piece];
        while (pieces != 0)
        {
            const Position pos = BitScanForward(pieces);

            score += MaterialAndPst[piece][pos];
            TraceIncr(material[pieceIndex]);
            TraceIncr(psts[pieceIndex][GetRelativeInverse(color, pos)]);

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
        score += EvaluatePiece<TColor, Pieces::Knight>(board);
        score += EvaluatePiece<TColor, Pieces::Bishop>(board);
        score += EvaluatePiece<TColor, Pieces::Rook>(board);
        score += EvaluatePiece<TColor, Pieces::Queen>(board);
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
        const Score interpolated = (mg * phase + (24 - phase) * eg) / MaxPhase;
        const Score flipped = board.WhiteToMove ? interpolated : -interpolated;
        return flipped;
    }

    static void Init()
    {
        for (Piece piece = Pieces::Pawn; piece < Pieces::Count; piece++)
        {
            const auto pieceIndex = (piece / 2) - 2;
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