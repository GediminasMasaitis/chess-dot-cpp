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
    static constexpr int ParameterCount = 6 + 6 * 64 + 64 + 4;


    static constexpr std::array<PhaseScore, 6> material =
    {
        S(100, 138), S(362, 260), S(350, 288), S(484, 510), S(1068, 916), S(  0,   0)
    };

    static constexpr std::array<EachPosition<PhaseScore>, 6> psts =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S( 89, 140), S(133, 134), S( 55,  89), S(104,  58), S( 76,  83), S(139,  71), S( 13, 114), S(-58, 133),
            S(-30, -26), S( 11, -37), S( -9, -28), S( 12, -58), S( 20, -45), S( 77, -54), S( 41, -36), S( -9, -37),
            S(-33, -39), S(  3, -42), S( -1, -50), S( 15, -63), S( 17, -54), S(  5, -47), S( 11, -45), S(-34, -45),
            S(-46, -44), S(-13, -41), S(-14, -52), S(  4, -58), S(  9, -55), S( -1, -53), S(  1, -49), S(-39, -56),
            S(-43, -52), S(-16, -46), S(-12, -55), S(-18, -46), S( -5, -44), S( -2, -49), S( 24, -57), S(-26, -62),
            S(-53, -44), S(-13, -48), S(-30, -38), S(-33, -43), S(-25, -35), S( 17, -48), S( 27, -54), S(-35, -62),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-196, -31), S(-117, -20), S(-54,   5), S(-48, -18), S( 69, -27), S(-111,  -6), S(-22, -49), S(-125, -71),
            S(-83,  -8), S(-52,   8), S( 65, -17), S( 24,  10), S( 22,   0), S( 66, -22), S( -6, -11), S(-17, -40),
            S(-57,  -8), S( 58, -12), S( 32,  20), S( 60,  17), S( 85,   1), S(129,  -7), S( 75, -14), S( 46, -37),
            S(-16,  -5), S( 15,  15), S( 15,  34), S( 52,  30), S( 35,  32), S( 72,  17), S( 16,  17), S( 18,  -8),
            S(-15,  -4), S(  3,   6), S( 13,  29), S( 10,  38), S( 25,  28), S( 17,  29), S( 17,  16), S(-11,  -6),
            S(-25, -10), S(-11,   9), S( 12,   9), S(  8,  25), S( 17,  23), S( 17,   7), S( 23, -10), S(-18, -12),
            S(-34, -25), S(-58,  -3), S(-15,   5), S( -5,   6), S( -3,   9), S( 15,  -7), S(-19, -12), S(-19, -33),
            S(-129,  -1), S(-22, -44), S(-63,  -7), S(-39,  -0), S(-18, -10), S(-30,  -6), S(-19, -42), S(-23, -54)
        },
        {
            S(-26, -13), S(  8, -20), S(-108,   0), S(-59,  -1), S(-28,  -3), S(-35,  -6), S(  6, -12), S(  4, -24),
            S(-13,  -7), S( 22,  -4), S( -9,   6), S(-20,  -5), S( 44,  -6), S( 71, -15), S( 31,  -4), S(-34, -11),
            S( -4,  -0), S( 50, -11), S( 56,  -4), S( 51,  -5), S( 48,  -5), S( 76,  -3), S( 44,  -1), S( 14,   0),
            S( 12,  -6), S( 21,   5), S( 33,   9), S( 61,   8), S( 52,  11), S( 51,   5), S( 23,  -2), S( 10,  -1),
            S(  8,  -6), S( 29,   1), S( 27,  11), S( 40,  17), S( 49,   5), S( 27,   7), S( 23,  -5), S( 14, -10),
            S( 14, -11), S( 30,  -3), S( 29,   7), S( 31,   8), S( 28,  11), S( 43,  -2), S( 31,  -6), S( 23, -14),
            S( 16, -12), S( 32, -21), S( 31,  -9), S( 15,  -3), S( 24,  -1), S( 33, -11), S( 49, -21), S( 20, -32),
            S(-24, -20), S( 10,  -8), S(  1, -28), S( -9,  -6), S( -1, -10), S(  3, -21), S(-33,  -1), S(-15, -13)
        },
        {
            S( 45,  12), S( 62,   6), S( 33,  21), S( 83,   5), S( 78,   8), S(  6,  19), S( 24,  13), S( 37,   8),
            S( 37,  11), S( 36,  14), S( 78,   5), S( 85,   3), S(100, -13), S( 94,  -7), S( 27,  12), S( 47,   3),
            S( -8,  14), S( 20,  12), S( 31,   8), S( 32,   9), S( 11,   9), S( 61,  -7), S( 75, -10), S( 22,  -3),
            S(-25,  14), S( -7,   9), S(  5,  18), S( 24,   4), S( 18,   7), S( 42,   0), S(  3,   1), S(-18,  10),
            S(-38,  15), S(-27,  14), S(-15,  16), S( -2,  10), S(  6,   1), S( -3,   0), S( 17,  -6), S(-20,  -1),
            S(-46,  10), S(-23,   9), S(-15,   3), S(-21,   8), S( -0,  -1), S(  2,  -6), S(  1,  -4), S(-30,  -6),
            S(-44,   7), S(-12,   1), S(-19,   7), S(-11,   9), S( -1,  -3), S( 13,  -6), S(  1,  -8), S(-67,  11),
            S(-17,   1), S(-11,   9), S( -0,  11), S( 10,   7), S( 12,   2), S(  1,   1), S(-28,  11), S(-18, -16)
        },
        {
            S(-24,  -2), S(-12,  40), S( 17,  34), S( 12,  38), S(116, -14), S(120, -30), S( 67, -13), S( 54,  18),
            S(-16, -14), S(-37,  31), S(  2,  35), S(  1,  53), S(-28,  81), S( 74,  11), S( 33,  31), S( 65, -12),
            S( -2, -21), S( -6,   6), S( 15,   8), S(  3,  61), S( 30,  55), S( 77,  18), S( 54,  17), S( 68,  -5),
            S(-26,  17), S(-20,  31), S(-11,  32), S( -9,  52), S(  2,  67), S( 19,  47), S(  1,  71), S(  6,  43),
            S(  1, -19), S(-23,  40), S( -1,  22), S( -3,  52), S(  2,  38), S(  6,  34), S(  9,  39), S(  6,  22),
            S(-11,  -1), S( 14, -35), S( -4,  19), S(  7,   4), S(  2,  15), S( 10,  20), S( 21,  11), S( 11,  11),
            S(-26, -14), S(  1, -22), S( 22, -36), S( 12, -18), S( 18, -17), S( 26, -29), S( 12, -44), S( 14, -34),
            S(  6, -35), S( -6, -31), S(  1, -22), S( 21, -55), S( -7,  -4), S(-19, -29), S(-28, -14), S(-45, -38)
        },
        {
            S(-51, -70), S(166, -64), S(143, -45), S( 86, -35), S(-122,  12), S(-73,  28), S( 60,  -9), S( 50, -22),
            S(180, -48), S( 71,   3), S( 34,   7), S(114,  -3), S( 42,  12), S( 38,  30), S(-29,  26), S(-119,  31),
            S( 80,  -9), S( 71,   8), S(100,   6), S( 22,  14), S( 38,  13), S(110,  29), S(124,  22), S( -3,   9),
            S( 18, -15), S( -4,  21), S( 26,  21), S(-35,  34), S(-39,  33), S(-26,  39), S( -1,  28), S(-70,  15),
            S(-61,  -9), S( 22,  -6), S(-53,  32), S(-104,  45), S(-107,  48), S(-67,  38), S(-60,  23), S(-75,   3),
            S( 19, -21), S( -1,   1), S(-32,  22), S(-66,  35), S(-67,  38), S(-56,  31), S(-10,  13), S(-27,  -1),
            S( 24, -29), S( 22,  -9), S(-10,  13), S(-73,  26), S(-54,  27), S(-27,  16), S( 19,  -3), S( 26, -21),
            S( -2, -56), S( 51, -41), S( 20, -21), S(-68,   1), S(  7, -27), S(-34,  -4), S( 39, -31), S( 37, -56)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-15,  12), S(  0,   1), S(  9,  33), S(  1,  33), S( -1,  25), S(  5,  18), S(  9,  27), S( 12,  39),
        S( 48, 122), S( -6, 130), S( 41,  90), S( 12,  91), S( 45,  58), S(  6,  84), S(-26, 106), S(-29, 122),
        S( 11,  64), S( -1,  53), S(  8,  43), S( -1,  35), S( -0,  25), S( 28,  22), S(-14,  55), S( -8,  55),
        S(  3,  29), S(-28,  25), S(-22,  18), S(-22,  15), S(-20,  13), S(-15,  12), S(-22,  27), S( 15,  24),
        S( -9,   5), S(-25,   4), S(-31,   7), S(-44,   5), S(-13,  -5), S( 15, -13), S(  8,   3), S( 20,   0),
        S(-11,   3), S( -2,  -1), S(  9, -14), S(-28,   9), S(-13,   6), S( 13, -12), S( 18,  -5), S( -3,   2),
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
    };

    static constexpr PhaseScore bishopPairBonus = S(29, 46);
    static constexpr PhaseScore doubledPawnBonus = S(-14, -28);
    static constexpr PhaseScore rookOpenFileBonus = S(22, -2);
    static constexpr PhaseScore rookSemiOpenFileBonus = S(6, 3);

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

            pawns &= pawns - 1;
        }

        return score;
    }

    template<Color TColor, Piece TPiece>
    static PhaseScore EvaluatePiece(const BoardBase& board)
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