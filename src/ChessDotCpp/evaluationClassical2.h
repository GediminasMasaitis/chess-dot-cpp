#pragma once

#include "common.h"
#include "evalbase.h"
#include "board.h"
#include "evalstate.h"

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
        TraceScores bishopPairBonus;
        TraceScores doubledPawnBonus;
    };

    using Trace = EvaluationClassical2Trace;
    static constexpr int ParameterCount = 6 + 6 * 64 + 2;


    static constexpr std::array<PhaseScore, 6> material =
    {
        S(100, 163), S(375, 268), S(367, 295), S(512, 523), S(1100, 950), S(0, 0)
    };

    static constexpr std::array<EachPosition<PhaseScore>, 6> psts =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S( 87, 129), S(141, 115), S( 67, 102), S(115,  69), S( 92,  84), S(145,  69), S( 29, 120), S(-39, 148),
            S(-26,  43), S( -6,  49), S( 19,  29), S( 24,   7), S( 69, -10), S( 70, -12), S( 16,  27), S(-34,  31),
            S(-36, -23), S(  1, -35), S(  0, -49), S( 15, -60), S( 19, -66), S(  8, -58), S( 11, -45), S(-37, -42),
            S(-50, -43), S(-16, -51), S(-15, -66), S(  3, -74), S(  9, -74), S(  1, -72), S(  2, -62), S(-40, -63),
            S(-47, -54), S(-18, -54), S(-14, -69), S(-20, -59), S( -5, -64), S( -1, -69), S( 26, -70), S(-26, -72),
            S(-58, -41), S(-15, -52), S(-32, -49), S(-36, -51), S(-26, -50), S( 19, -65), S( 29, -65), S(-37, -68),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-205, -31), S(-110, -23), S(-55,   6), S(-48, -19), S( 71, -28), S(-107, -11), S(-22, -54), S(-124, -80),
            S(-86, -11), S(-54,   7), S( 73, -19), S( 27,   8), S( 24,  -0), S( 68, -23), S( -2, -13), S(-14, -43),
            S(-52, -11), S( 65, -15), S( 38,  20), S( 67,  16), S( 95,  -1), S(137,  -8), S( 81, -16), S( 50, -39),
            S(-15,  -5), S( 18,  14), S( 19,  35), S( 56,  30), S( 40,  31), S( 76,  17), S( 20,  16), S( 23, -10),
            S(-14,  -8), S(  7,   4), S( 15,  28), S( 12,  39), S( 29,  27), S( 21,  28), S( 19,  15), S( -8, -10),
            S(-23, -14), S(-10,   8), S( 14,   7), S( 11,  25), S( 20,  21), S( 20,   5), S( 27, -12), S(-16, -14),
            S(-32, -32), S(-61,  -5), S(-13,   2), S( -3,   5), S( -1,   8), S( 20, -11), S(-18, -12), S(-19, -38),
            S(-130,  -7), S(-21, -47), S(-67,  -9), S(-39,  -2), S(-16, -14), S(-30,  -8), S(-17, -45), S(-25, -57)
        },
        {
            S(-24, -15), S(  9, -21), S(-105,  -1), S(-52,  -4), S(-33,  -1), S(-34,  -7), S(  1, -11), S(  3, -25),
            S(-15,  -8), S( 25,  -6), S(-10,   7), S(-18,  -6), S( 46,  -7), S( 73, -16), S( 32,  -5), S(-37, -12),
            S( -4,   1), S( 51, -11), S( 57,  -3), S( 53,  -4), S( 47,  -5), S( 76,  -2), S( 47,  -1), S( 13,   2),
            S( 10,  -5), S( 21,   7), S( 33,  11), S( 64,   8), S( 54,  12), S( 53,   5), S( 21,  -1), S( 10,  -1),
            S(  7,  -8), S( 28,   0), S( 27,  12), S( 40,  18), S( 49,   6), S( 27,   8), S( 23,  -4), S( 15, -11),
            S( 14, -13), S( 30,  -5), S( 29,   8), S( 31,   9), S( 27,  13), S( 43,  -1), S( 32,  -6), S( 22, -17),
            S( 18, -16), S( 31, -21), S( 31,  -9), S( 14,  -2), S( 23,   1), S( 33, -11), S( 49, -21), S( 20, -33),
            S(-27, -23), S(  9, -10), S( -0, -30), S(-12,  -6), S( -2, -10), S(  2, -21), S(-30,  -3), S(-15, -15)
        },
        {
            S( 49,  12), S( 69,   5), S( 40,  20), S( 95,   4), S( 89,   6), S(  8,  19), S( 27,  12), S( 46,   7),
            S( 43,  10), S( 42,  13), S( 86,   4), S( 89,   3), S(111, -15), S(102,  -9), S( 34,  10), S( 55,   2),
            S( -5,  14), S( 26,  11), S( 35,   8), S( 39,   9), S( 15,   9), S( 67,  -8), S( 83, -11), S( 24,  -2),
            S(-25,  13), S( -9,  10), S(  8,  19), S( 30,   4), S( 24,   7), S( 42,   1), S(  2,   2), S(-18,  11),
            S(-40,  14), S(-27,  14), S( -9,  14), S(  1,  10), S(  7,   2), S( -5,   0), S( 15,  -7), S(-23,  -3),
            S(-50,   8), S(-23,   9), S(-13,   1), S(-20,   8), S(  2,  -2), S( -0,  -6), S( -0,  -4), S(-33,  -8),
            S(-49,   6), S(-13,   1), S(-19,   8), S(-10,  10), S( -0,  -3), S( 10,  -4), S( -2,  -6), S(-73,  11),
            S(-21,   2), S(-14,  12), S(  1,  12), S( 11,   8), S( 14,   3), S( -2,   2), S(-31,  12), S(-21, -16)
        },
        {
            S(-26,  -4), S( -8,  36), S( 21,  31), S( 16,  34), S(120, -14), S(111, -22), S( 68, -11), S( 54,  17),
            S(-17, -18), S(-36,  28), S(  0,  37), S(  3,  53), S(-26,  80), S( 78,   9), S( 36,  30), S( 67, -11),
            S( -3, -22), S(-10,   7), S( 16,   6), S(  3,  62), S( 32,  55), S( 80,  17), S( 58,  16), S( 71,  -4),
            S(-28,  15), S(-21,  30), S(-10,  29), S(-11,  53), S(  0,  70), S( 18,  48), S(  2,  72), S(  5,  44),
            S(  0, -24), S(-26,  41), S( -2,  23), S( -5,  55), S(  1,  40), S(  5,  36), S(  8,  44), S(  6,  22),
            S(-12,  -7), S( 13, -39), S( -4,  19), S(  6,   6), S(  2,  14), S(  9,  20), S( 22,  11), S( 10,  11),
            S(-29, -19), S( -1, -23), S( 22, -38), S( 11, -18), S( 18, -18), S( 25, -29), S(  8, -43), S( 11, -37),
            S(  4, -34), S( -8, -34), S( -0, -24), S( 21, -59), S( -9,  -4), S(-23, -28), S(-28, -18), S(-45, -42)
        },
        {
            S(-33, -71), S(121, -51), S(117, -35), S( 72, -32), S(-84,   5), S(-48,  26), S( 47,   1), S( 31, -14),
            S(144, -34), S( 63,   9), S( 45,   7), S(111,  -1), S( 49,  10), S( 35,  35), S(-26,  31), S(-108,  35),
            S( 67,   0), S( 73,  12), S( 93,  11), S( 29,  13), S( 49,  12), S(119,  29), S(121,  29), S( -0,  15),
            S(  7, -10), S( -6,  25), S( 21,  25), S(-33,  36), S(-28,  33), S(-33,  42), S(  2,  30), S(-71,  17),
            S(-64, -11), S( 20,  -4), S(-52,  33), S(-101,  45), S(-104,  48), S(-66,  38), S(-59,  23), S(-76,   3),
            S( 19, -23), S( -2,   0), S(-32,  20), S(-70,  35), S(-66,  38), S(-58,  32), S(-10,  13), S(-29,  -1),
            S( 21, -32), S( 22, -13), S(-11,  12), S(-75,  26), S(-54,  26), S(-26,  15), S( 22,  -5), S( 30, -23),
            S( -3, -59), S( 55, -46), S( 22, -24), S(-70,  -0), S(  9, -29), S(-34,  -5), S( 42, -33), S( 40, -59)
        },
    }};


    static constexpr PhaseScore bishopPairBonus = S(29, 49);
    static constexpr PhaseScore doubledPawnBonus = S(-13, -30);

    static inline Trace T;
    static inline EachPiece<EachPosition<PhaseScore>> MaterialAndPst;

    using PieceIndex = uint8_t;
    static constexpr PieceIndex GetPieceIndex(Piece piece)
    {
        return (piece / 2) - 2;
    }

    template<Color TColor>
    static PhaseScore EvaluatePawns(const BoardBase& board)
    {
        constexpr Color color = TColor;
        constexpr Piece pieceNoColor = Pieces::Pawn;
        constexpr Piece piece = pieceNoColor | color;
        constexpr PieceIndex pieceIndex = GetPieceIndex(piece);
        PhaseScore score = 0;

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
    static PhaseScore EvaluateColor(const BoardBase& board)
    {
        constexpr Color color = TColor;
        PhaseScore score = 0;

        score += EvaluatePawns<TColor>(board);
        score += EvaluatePiece<TColor, Pieces::Knight>(board);
        score += EvaluatePiece<TColor, Pieces::Bishop>(board);
        score += EvaluatePiece<TColor, Pieces::Rook>(board);
        score += EvaluatePiece<TColor, Pieces::Queen>(board);
        score += EvaluateKings<TColor>(board);

        // BISHOP PAIR
        if(board.PieceCounts[Pieces::Bishop | color] == 2)
        {
            score += bishopPairBonus;
            TraceIncr(bishopPairBonus);
        }

        return score;
    }

    static PhaseScore EvaluatePhased(const BoardBase& board)
    {
        PhaseScore score = 0;

        score += EvaluateColor<Colors::White>(board);
        score -= EvaluateColor<Colors::Black>(board);

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