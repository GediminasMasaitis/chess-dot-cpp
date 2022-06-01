#pragma once

#include "common.h"
#include "evalbase.h"
#include "board.h"
#include "evalstate.h"

class EvaluationClassical2
{
public:
    struct EvaluationClassical2Trace
    {
        using TraceScores = EachColor<PhaseScore>;

        PhaseScore eval;
        Phase phase;

        std::array<TraceScores, 6> material;
        std::array<EachPosition<TraceScores>, 6> psts;
    };

    using Trace = EvaluationClassical2Trace;
    static constexpr int ParameterCount = 6 + 6 * 64;


    static constexpr int material[] = {S(100, 168), S(385, 284), S(399, 312), S(522, 550), S(1092, 1022), S(0, 0)};
    static constexpr std::array<EachPosition<PhaseScore>, 6> psts =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(104, 133), S(135, 124), S( 74, 105), S(111,  77), S( 93,  90), S(127,  76), S( 33, 120), S( -1, 144),
            S(-28,  47), S( -9,  51), S( 16,  31), S( 24,  10), S( 71, -10), S( 64, -14), S( 12,  27), S(-37,  33),
            S(-37, -23), S(  1, -38), S( -4, -51), S( 13, -62), S( 16, -70), S(  5, -63), S( 11, -49), S(-40, -44),
            S(-52, -43), S(-16, -53), S(-16, -68), S(  3, -75), S(  9, -76), S( -1, -77), S(  3, -65), S(-42, -64),
            S(-49, -54), S(-17, -55), S(-16, -72), S(-22, -63), S( -6, -66), S( -4, -73), S( 29, -72), S(-27, -74),
            S(-59, -42), S(-14, -55), S(-34, -54), S(-37, -53), S(-27, -52), S( 18, -68), S( 33, -67), S(-38, -72),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-179, -51), S(-97, -28), S(-55,   5), S(-48, -21), S( 65, -28), S(-103, -17), S(-26, -55), S(-119, -92),
            S(-87, -12), S(-55,   8), S( 77, -20), S( 29,   9), S( 26,  -1), S( 72, -23), S( -4, -13), S(-14, -45),
            S(-54, -14), S( 68, -17), S( 39,  21), S( 70,  17), S(103,  -3), S(139,  -6), S( 82, -17), S( 50, -40),
            S(-15,  -6), S( 18,  14), S( 19,  35), S( 59,  31), S( 41,  31), S( 80,  18), S( 20,  16), S( 23, -10),
            S(-15,  -9), S(  5,   4), S( 14,  29), S( 12,  39), S( 29,  28), S( 21,  29), S( 20,  16), S( -9, -12),
            S(-26, -16), S(-11,   8), S( 13,   6), S( 10,  25), S( 21,  21), S( 20,   4), S( 26, -14), S(-18, -15),
            S(-35, -33), S(-63,  -8), S(-15,   1), S( -4,   4), S( -3,   7), S( 19, -14), S(-20, -14), S(-21, -39),
            S(-126, -15), S(-23, -51), S(-70,  -9), S(-42,  -4), S(-18, -14), S(-34,  -9), S(-19, -48), S(-26, -59)
        },
        {
            S(-19, -14), S( 12, -22), S(-103,  -1), S(-55,  -1), S(-36,  -1), S(-34,  -7), S(  0, -12), S(  7, -26),
            S(-13,  -9), S( 30,  -5), S( -7,   8), S(-16,  -7), S( 51,  -6), S( 78, -17), S( 35,  -6), S(-36, -11),
            S( -3,   2), S( 54, -11), S( 62,  -2), S( 59,  -4), S( 52,  -5), S( 78,   1), S( 51,  -0), S( 15,   4),
            S( 11,  -3), S( 23,   9), S( 35,  13), S( 69,   8), S( 59,  13), S( 59,   8), S( 24,   2), S( 12,   3),
            S(  8,  -6), S( 32,   1), S( 30,  14), S( 41,  20), S( 52,   7), S( 29,  10), S( 26,  -3), S( 18,  -9),
            S( 16, -13), S( 33,  -4), S( 31,   9), S( 33,  10), S( 30,  14), S( 46,  -0), S( 34,  -7), S( 24, -16),
            S( 21, -16), S( 34, -22), S( 32,  -7), S( 15,  -0), S( 25,   3), S( 37, -11), S( 53, -20), S( 20, -32),
            S(-26, -21), S( 12,  -9), S(  1, -28), S(-12,  -4), S( -3,  -8), S(  4, -20), S(-30,  -2), S(-13, -15)
        },
        {
            S( 48,  14), S( 72,   6), S( 42,  21), S( 96,   5), S( 92,   6), S(  8,  20), S( 28,  13), S( 47,   7),
            S( 44,  10), S( 43,  14), S( 89,   5), S( 92,   5), S(116, -15), S(106,  -8), S( 31,  11), S( 57,   3),
            S( -7,  15), S( 25,  12), S( 35,   9), S( 40,   9), S( 18,   9), S( 68,  -8), S( 83, -10), S( 21,   0),
            S(-27,  14), S( -9,  11), S(  8,  20), S( 33,   4), S( 24,   7), S( 44,   2), S(  1,   3), S(-23,  12),
            S(-43,  14), S(-30,  15), S(-10,  16), S( -0,  11), S(  7,   2), S( -8,   1), S( 15,  -6), S(-25,  -3),
            S(-52,   8), S(-24,   9), S(-14,   1), S(-20,   8), S(  1,  -2), S( -1,  -7), S( -2,  -4), S(-34,  -8),
            S(-51,   7), S(-14,   0), S(-21,   8), S(-11,  11), S( -1,  -2), S( 10,  -4), S( -4,  -7), S(-76,  12),
            S(-21,   1), S(-15,  11), S(  1,  12), S( 11,   8), S( 14,   3), S( -2,   0), S(-33,  11), S(-22, -18)
        },
        {
            S(-26,  -4), S( -5,  35), S( 20,  34), S( 18,  36), S(111,  -4), S( 93,  -7), S( 66,  -5), S( 57,  17),
            S(-15, -19), S(-38,  28), S(  1,  40), S(  3,  54), S(-24,  82), S( 80,  14), S( 38,  29), S( 67, -10),
            S( -3, -24), S(-10,   8), S( 16,   7), S(  5,  66), S( 34,  59), S( 81,  21), S( 61,  16), S( 73,  -1),
            S(-29,  17), S(-24,  32), S(-11,  31), S(-12,  57), S(  1,  73), S( 20,  52), S(  0,  77), S(  3,  49),
            S( -1, -23), S(-28,  44), S( -4,  27), S( -6,  61), S( -0,  44), S(  3,  41), S(  7,  48), S(  4,  28),
            S(-13,  -5), S( 12, -38), S( -6,  21), S(  4,   8), S( -0,  16), S(  8,  24), S( 21,  13), S(  9,  12),
            S(-32, -19), S( -3, -22), S( 22, -38), S(  9, -17), S( 16, -16), S( 24, -27), S(  6, -44), S( 10, -38),
            S(  4, -35), S(-10, -35), S( -2, -25), S( 21, -60), S(-12,  -3), S(-27, -27), S(-30, -18), S(-49, -44)
        },
        {
            S(-30, -74), S( 93, -47), S( 93, -30), S( 58, -29), S(-64,   2), S(-36,  25), S( 39,   4), S( 23, -11),
            S(109, -27), S( 57,  12), S( 45,   8), S( 96,   3), S( 48,  12), S( 34,  38), S(-23,  33), S(-87,  32),
            S( 62,   1), S( 75,  13), S( 89,  13), S( 32,  14), S( 47,  14), S(107,  34), S(109,  34), S( -2,  16),
            S(  6, -10), S( -4,  26), S( 22,  26), S(-31,  37), S(-25,  34), S(-31,  44), S(  0,  32), S(-71,  18),
            S(-64, -11), S( 26,  -6), S(-51,  34), S(-103,  47), S(-106,  50), S(-68,  40), S(-59,  24), S(-80,   3),
            S( 18, -24), S( -2,  -1), S(-32,  21), S(-72,  36), S(-69,  40), S(-59,  32), S(-10,  13), S(-30,  -1),
            S( 24, -34), S( 25, -14), S( -9,  12), S(-77,  26), S(-55,  27), S(-24,  15), S( 25,  -6), S( 33, -24),
            S( -3, -62), S( 60, -48), S( 26, -27), S(-70,  -1), S( 13, -32), S(-33,  -6), S( 47, -35), S( 44, -62)
        }
    }};

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