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
        TraceScores bishopPairBonus;
    };

    using Trace = EvaluationClassical2Trace;
    static constexpr int ParameterCount = 6 + 6 * 64 + 1;


    static constexpr std::array<PhaseScore, 6> material = {S(100, 168), S(388, 280), S(376, 307), S(527, 546), S(1132, 992), S(0, 0)};
    static constexpr std::array<EachPosition<PhaseScore>, 6> psts =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S( 90, 135), S(141, 121), S( 70, 106), S(120,  73), S( 95,  87), S(144,  70), S( 26, 122), S(-35, 152),
            S(-28,  46), S( -9,  49), S( 17,  30), S( 24,   9), S( 70, -11), S( 65, -15), S( 13,  27), S(-37,  32),
            S(-37, -23), S(  2, -38), S( -4, -51), S( 14, -62), S( 16, -70), S(  5, -63), S( 11, -50), S(-39, -44),
            S(-51, -43), S(-15, -53), S(-16, -68), S(  4, -75), S( 10, -76), S( -1, -77), S(  4, -65), S(-42, -65),
            S(-48, -54), S(-17, -56), S(-15, -72), S(-21, -62), S( -6, -66), S( -4, -73), S( 29, -72), S(-27, -74),
            S(-59, -42), S(-13, -55), S(-33, -53), S(-36, -53), S(-27, -53), S( 18, -68), S( 33, -68), S(-38, -72),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-209, -34), S(-111, -25), S(-56,   6), S(-50, -19), S( 72, -30), S(-108, -12), S(-23, -57), S(-127, -85),
            S(-89, -11), S(-56,   8), S( 77, -21), S( 29,   8), S( 26,  -1), S( 72, -24), S( -2, -14), S(-13, -45),
            S(-54, -13), S( 68, -16), S( 40,  20), S( 70,  17), S(100,  -2), S(142,  -8), S( 83, -17), S( 52, -41),
            S(-16,  -6), S( 19,  14), S( 19,  36), S( 59,  31), S( 41,  32), S( 79,  18), S( 21,  16), S( 23, -10),
            S(-14, -10), S(  6,   3), S( 15,  29), S( 13,  39), S( 30,  28), S( 21,  29), S( 20,  15), S( -9, -10),
            S(-25, -16), S(-11,   9), S( 14,   7), S( 10,  25), S( 20,  21), S( 20,   5), S( 27, -12), S(-16, -15),
            S(-35, -33), S(-64,  -7), S(-15,   1), S( -4,   4), S( -2,   8), S( 20, -13), S(-20, -13), S(-21, -39),
            S(-135,  -9), S(-22, -50), S(-70,  -8), S(-42,  -3), S(-18, -14), S(-34,  -8), S(-18, -48), S(-26, -60)
        },
        {
            S(-22, -15), S( 11, -22), S(-108,  -1), S(-53,  -3), S(-35,  -1), S(-34,  -7), S(  1, -12), S(  4, -26),
            S(-14,  -9), S( 27,  -5), S( -9,   7), S(-18,  -8), S( 49,  -7), S( 77, -16), S( 33,  -5), S(-37, -12),
            S( -4,   1), S( 53, -11), S( 60,  -2), S( 56,  -4), S( 51,  -5), S( 79,  -1), S( 49,  -0), S( 14,   3),
            S( 10,  -5), S( 21,   9), S( 34,  12), S( 68,   9), S( 56,  13), S( 56,   7), S( 22,   0), S( 10,   1),
            S(  6,  -8), S( 30,   0), S( 27,  13), S( 40,  18), S( 51,   7), S( 26,   9), S( 25,  -4), S( 16, -11),
            S( 14, -15), S( 30,  -5), S( 29,   8), S( 31,  10), S( 27,  14), S( 44,   0), S( 31,  -7), S( 23, -18),
            S( 18, -16), S( 32, -23), S( 31,  -9), S( 12,  -2), S( 22,   1), S( 35, -12), S( 50, -21), S( 19, -34),
            S(-28, -23), S(  9,  -9), S( -1, -31), S(-13,  -6), S( -3, -10), S(  1, -22), S(-32,  -3), S(-17, -16)
        },
        {
            S( 52,  12), S( 71,   5), S( 43,  20), S( 96,   5), S( 92,   6), S(  8,  20), S( 28,  12), S( 48,   6),
            S( 44,  10), S( 44,  13), S( 90,   4), S( 93,   4), S(116, -16), S(104,  -8), S( 32,  11), S( 55,   3),
            S( -8,  15), S( 25,  12), S( 37,   8), S( 41,   9), S( 16,  10), S( 68,  -8), S( 85, -11), S( 21,  -1),
            S(-27,  14), S( -9,  11), S(  7,  20), S( 32,   4), S( 25,   7), S( 42,   2), S(  2,   3), S(-22,  12),
            S(-43,  14), S(-29,  14), S(-11,  15), S(  1,  10), S(  8,   2), S( -7,   1), S( 15,  -6), S(-25,  -3),
            S(-52,   8), S(-24,   9), S(-14,   1), S(-20,   8), S(  2,  -2), S( -1,  -7), S( -2,  -4), S(-34,  -8),
            S(-51,   6), S(-15,   0), S(-20,   8), S(-10,  10), S( -0,  -3), S( 10,  -4), S( -4,  -7), S(-75,  11),
            S(-21,   2), S(-14,  11), S(  1,  12), S( 12,   9), S( 14,   3), S( -1,   1), S(-33,  11), S(-22, -17)
        },
        {
            S(-26,  -5), S( -8,  38), S( 22,  32), S( 17,  35), S(122, -13), S(110, -19), S( 71, -10), S( 56,  16),
            S(-15, -19), S(-38,  28), S(  2,  38), S(  2,  54), S(-26,  83), S( 81,  11), S( 38,  29), S( 69, -12),
            S( -2, -24), S( -9,   7), S( 16,   7), S(  4,  65), S( 34,  56), S( 83,  19), S( 62,  15), S( 74,  -4),
            S(-28,  16), S(-22,  31), S(-10,  29), S(-11,  55), S(  1,  71), S( 20,  50), S(  1,  76), S(  5,  46),
            S( -0, -23), S(-27,  43), S( -3,  25), S( -5,  58), S(  1,  42), S(  4,  39), S(  8,  47), S(  5,  25),
            S(-12,  -6), S( 13, -39), S( -5,  19), S(  6,   6), S(  1,  15), S(  9,  22), S( 22,  11), S( 10,  12),
            S(-30, -20), S( -1, -23), S( 23, -39), S( 10, -19), S( 18, -17), S( 25, -29), S(  8, -44), S( 11, -39),
            S(  5, -36), S( -9, -34), S( -1, -25), S( 22, -61), S(-10,  -4), S(-25, -28), S(-28, -19), S(-50, -43)
        },
        {
            S(-33, -73), S(118, -51), S(115, -35), S( 71, -32), S(-82,   5), S(-47,  27), S( 47,   2), S( 30, -13),
            S(140, -34), S( 63,  10), S( 47,   7), S(111,  -0), S( 51,  11), S( 36,  37), S(-27,  32), S(-107,  36),
            S( 68,  -0), S( 76,  12), S( 96,  12), S( 31,  13), S( 50,  13), S(120,  31), S(123,  31), S( -2,  16),
            S(  7, -11), S( -6,  26), S( 21,  25), S(-33,  37), S(-28,  33), S(-34,  44), S( -0,  32), S(-74,  18),
            S(-67, -11), S( 22,  -6), S(-54,  34), S(-105,  46), S(-108,  50), S(-70,  39), S(-61,  24), S(-80,   3),
            S( 19, -23), S( -3,  -0), S(-33,  21), S(-74,  37), S(-69,  39), S(-61,  32), S(-11,  13), S(-31,  -1),
            S( 21, -33), S( 23, -14), S(-11,  12), S(-78,  27), S(-57,  27), S(-26,  15), S( 24,  -6), S( 32, -24),
            S( -2, -62), S( 58, -47), S( 24, -26), S(-72,  -1), S( 11, -31), S(-35,  -6), S( 45, -35), S( 42, -61)
        },
    }};

    static constexpr PhaseScore bishopPairBonus = S(30, 50);

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