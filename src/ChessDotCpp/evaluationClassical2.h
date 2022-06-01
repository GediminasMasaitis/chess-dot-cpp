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
    static constexpr int ParameterCount = 6 + 6 * 64 + 64 + 6;


    static constexpr std::array<PhaseScore, 6> material =
    {
        S(100, 146), S(406, 291), S(392, 324), S(544, 571), S(1198, 1025), S(  0,   0)
    };

    static constexpr std::array<EachPosition<PhaseScore>, 6> psts =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(106, 161), S(150, 158), S( 65, 103), S(120,  65), S( 85,  96), S(157,  86), S( 15, 131), S(-61, 151),
            S(-24, -27), S(  7, -43), S( -7, -29), S( 19, -61), S( 24, -48), S( 88, -61), S( 44, -43), S(  1, -37),
            S(-30, -42), S(  4, -51), S( -4, -55), S( 18, -66), S( 22, -57), S(  6, -54), S( 17, -55), S(-27, -50),
            S(-44, -49), S(-17, -52), S(-10, -60), S(  6, -62), S( 12, -61), S( -1, -63), S(  2, -63), S(-36, -63),
            S(-46, -58), S(-29, -57), S(-20, -60), S(-26, -46), S(-15, -49), S(-12, -56), S( 14, -73), S(-27, -69),
            S(-51, -49), S(-26, -58), S(-31, -41), S(-30, -46), S(-27, -40), S( 18, -56), S( 17, -69), S(-27, -67),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-219, -36), S(-131, -22), S(-59,   5), S(-54, -17), S( 76, -30), S(-124,  -6), S(-29, -53), S(-140, -83),
            S(-95, -10), S(-58,   8), S( 69, -19), S( 27,  12), S( 22,   2), S( 70, -24), S( -7, -13), S(-21, -45),
            S(-63, -10), S( 65, -13), S( 37,  23), S( 66,  19), S( 96,   1), S(143,  -7), S( 80, -14), S( 53, -41),
            S(-17,  -5), S( 17,  17), S( 17,  39), S( 60,  34), S( 42,  36), S( 81,  20), S( 19,  19), S( 20,  -9),
            S(-18,  -4), S(  7,   7), S( 15,  32), S( 12,  42), S( 28,  32), S( 20,  33), S( 20,  18), S(-11,  -6),
            S(-28, -12), S(-11,  11), S( 13,  11), S(  9,  29), S( 19,  25), S( 19,   9), S( 26, -11), S(-20, -13),
            S(-39, -25), S(-64,  -3), S(-16,   7), S( -6,   8), S( -2,  11), S( 15,  -7), S(-22, -13), S(-22, -38),
            S(-143,   1), S(-26, -48), S(-69,  -7), S(-45,   1), S(-19, -11), S(-33,  -7), S(-21, -47), S(-26, -65)
        },
        {
            S(-24, -16), S( 10, -23), S(-121,  -0), S(-67,  -1), S(-32,  -2), S(-43,  -6), S( 12, -14), S(  9, -27),
            S(-17,  -8), S( 25,  -6), S(-11,   6), S(-20,  -6), S( 49,  -7), S( 79, -16), S( 32,  -5), S(-38, -14),
            S( -3,  -2), S( 52, -12), S( 62,  -4), S( 56,  -5), S( 56,  -6), S( 87,  -4), S( 47,  -1), S( 16,  -0),
            S( 13,  -8), S( 25,   6), S( 38,  10), S( 69,  10), S( 59,  12), S( 57,   5), S( 27,  -2), S( 12,  -2),
            S(  8,  -8), S( 32,   0), S( 31,  13), S( 45,  19), S( 55,   5), S( 31,   8), S( 27,  -6), S( 18, -11),
            S( 15, -12), S( 33,  -4), S( 31,   9), S( 34,   9), S( 31,  13), S( 47,  -2), S( 35,  -8), S( 24, -17),
            S( 18, -14), S( 34, -23), S( 35, -11), S( 18,  -4), S( 27,  -1), S( 37, -12), S( 54, -23), S( 23, -35),
            S(-32, -22), S( 11,  -9), S(  2, -31), S( -9,  -7), S(  1, -13), S(  4, -23), S(-35,  -1), S(-17, -16)
        },
        {
            S( 49,  14), S( 67,   8), S( 35,  24), S( 91,   7), S( 88,   9), S(  7,  21), S( 27,  15), S( 41,  11),
            S( 42,  12), S( 42,  15), S( 84,   6), S( 90,   5), S(110, -12), S(101,  -5), S( 31,  14), S( 54,   5),
            S( -5,  15), S( 23,  13), S( 36,   8), S( 35,  10), S( 14,  10), S( 69,  -7), S( 80,  -9), S( 27,  -3),
            S(-27,  16), S( -6,  10), S(  7,  20), S( 30,   5), S( 25,   7), S( 46,   2), S(  4,   2), S(-16,  10),
            S(-41,  17), S(-30,  17), S(-16,  18), S( -2,  11), S(  7,   3), S( -3,   1), S( 20,  -7), S(-22,  -0),
            S(-51,  12), S(-23,  10), S(-16,   4), S(-21,   8), S( -0,  -0), S(  3,  -7), S(  4,  -5), S(-30,  -6),
            S(-50,   8), S(-13,   1), S(-22,   9), S(-12,  11), S( -1,  -4), S( 12,  -6), S(  0, -10), S(-75,  11),
            S(-19,   2), S(-12,  10), S( -0,  13), S( 11,   9), S( 14,   3), S(  1,   1), S(-31,  12), S(-20, -18)
        },
        {
            S(-30,  -1), S(-13,  45), S( 17,  38), S( 15,  42), S(133, -16), S(135, -34), S( 76, -13), S( 61,  22),
            S(-18, -16), S(-42,  36), S( -2,  42), S(  1,  61), S(-30,  91), S( 82,  12), S( 38,  34), S( 71,  -9),
            S( -3, -22), S( -4,   6), S( 19,   7), S(  2,  71), S( 37,  61), S( 86,  23), S( 58,  21), S( 77,  -5),
            S(-29,  18), S(-20,  33), S(-10,  35), S( -8,  58), S(  3,  76), S( 20,  55), S(  3,  80), S(  7,  49),
            S(  1, -22), S(-26,  44), S( -1,  26), S( -3,  59), S(  3,  42), S(  8,  40), S( 11,  43), S(  7,  26),
            S(-13,   1), S( 16, -38), S( -3,  22), S( 10,   4), S(  3,  17), S( 11,  22), S( 26,  10), S( 12,  16),
            S(-30, -15), S( -0, -25), S( 26, -38), S( 13, -19), S( 20, -18), S( 30, -34), S( 12, -49), S( 16, -40),
            S(  6, -38), S( -8, -35), S(  2, -25), S( 23, -61), S( -7,  -5), S(-19, -35), S(-29, -16), S(-54, -43)
        },
        {
            S(-59, -78), S(186, -72), S(161, -50), S( 95, -39), S(-137,  15), S(-81,  32), S( 65,  -9), S( 58, -24),
            S(201, -54), S( 77,   3), S( 34,   8), S(125,  -3), S( 47,  14), S( 43,  34), S(-30,  30), S(-133,  35),
            S( 90, -10), S( 79,   9), S(110,   7), S( 27,  15), S( 41,  15), S(120,  34), S(137,  25), S( -5,  11),
            S( 22, -18), S( -4,  23), S( 29,  23), S(-39,  39), S(-42,  37), S(-31,  45), S( -1,  32), S(-80,  18),
            S(-68, -10), S( 25,  -6), S(-56,  35), S(-116,  50), S(-122,  54), S(-75,  42), S(-69,  26), S(-88,   4),
            S( 17, -23), S( -3,   2), S(-34,  23), S(-72,  38), S(-74,  42), S(-61,  35), S(-12,  14), S(-33,  -1),
            S( 27, -34), S( 27, -11), S(-12,  14), S(-82,  28), S(-59,  29), S(-29,  18), S( 22,  -3), S( 30, -24),
            S( -0, -63), S( 58, -47), S( 22, -24), S(-76,   0), S(  8, -30), S(-38,  -5), S( 44, -35), S( 40, -62)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S( -6,  24), S(  4,   8), S( 19,  47), S( 12,  51), S(  5,  39), S(  6,  28), S( 15,  41), S( 27,  55),
        S( 59, 150), S(  7, 161), S( 50, 111), S( 19, 111), S( 55,  74), S(  9, 106), S(-25, 132), S(-30, 146),
        S( 26,  83), S(  8,  75), S( 20,  58), S(  4,  47), S(  2,  35), S( 43,  36), S(-10,  75), S(  0,  72),
        S( 16,  45), S(-19,  44), S(-16,  33), S(-15,  24), S(-13,  24), S( -1,  26), S(-14,  46), S( 26,  39),
        S(  7,  17), S( -8,  20), S(-17,  18), S(-32,  13), S(  1,   5), S( 39,  -2), S( 24,  21), S( 36,  11),
        S( -0,  15), S( 17,  14), S( 22,  -5), S(-22,  19), S( -1,  16), S( 30,   1), S( 35,  12), S(  7,  13),
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
    };

    static constexpr PhaseScore bishopPairBonus = S(33, 51);
    static constexpr PhaseScore doubledPawnBonus = S(-1, -15);
    static constexpr PhaseScore protectedPawnBonus = S(15, 11);
    static constexpr PhaseScore weakPawnBonus = S(-12, -9);
    static constexpr PhaseScore rookOpenFileBonus = S(23, -2);
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

        // PROTECTED PAWNS
        const Bitboard protectedPawns = ownPawnControl & board.BitBoard[piece];
        const Bitboard protectedPawnCount = PopCount(protectedPawns);
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