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
        std::array<std::array<TraceScores, 28>, 6> mobilityBonus;
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
    static constexpr int ParameterCount = 6 + 6 * 64 + 64 + 6 * 28 + 6;


    static constexpr std::array<PhaseScore, 6> material =
    {
        S(100, 143), S(413, 275), S(391, 304), S(556, 540), S(1229, 970), S(  0,   0)
    };

    static constexpr std::array<std::array<PhaseScore, 64>, 6> psts =
    {{
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S( 84, 158), S(134, 162), S( 50, 106), S( 94,  67), S( 68,  94), S(143,  80), S(  1, 129), S(-78, 150),
            S(-23, -27), S( -6, -39), S(-27, -25), S(  2, -58), S(  1, -44), S( 68, -57), S( 35, -44), S( -1, -38),
            S(-35, -40), S(-14, -48), S(-20, -52), S(  2, -65), S(  2, -55), S( -6, -53), S( -4, -51), S(-31, -49),
            S(-40, -49), S(-26, -50), S(-12, -59), S( -3, -62), S(  5, -61), S( -0, -64), S( -4, -61), S(-36, -62),
            S(-39, -58), S(-26, -58), S(-23, -58), S(-18, -50), S( -6, -52), S( -9, -57), S( 16, -73), S(-26, -67),
            S(-31, -53), S(-16, -60), S(-21, -45), S( -4, -53), S( -4, -46), S( 27, -58), S( 26, -71), S(-14, -70),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(-165,  -3), S(-112, -17), S(-74,   8), S(-56, -17), S( 66, -26), S(-99,  -7), S(-31, -45), S(-93, -51),
            S(-78,  -2), S(-57,  10), S( 67, -28), S(  8,   5), S( 10,  -4), S( 53, -29), S(  4, -11), S( -7, -31),
            S(-62,  -9), S( 40, -17), S(  1,  20), S( 29,  15), S( 59,  -1), S(109, -10), S( 63, -21), S( 60, -39),
            S( -5,  -5), S(  9,   6), S( -6,  31), S( 46,  22), S( 30,  23), S( 52,  14), S( 15,   9), S( 32,  -9),
            S( -4,  -5), S(  5,  -4), S( -1,  23), S(  4,  31), S( 13,  22), S( 11,  22), S( 22,   6), S( 11,  -2),
            S(-15, -10), S(-21,   4), S( -8,   4), S(-14,  22), S(  6,  17), S( -3,   3), S( 16, -16), S(-12,  -8),
            S( -8, -16), S(-40,  -4), S(-23,   0), S(  7,  -6), S(  5,  -3), S( 11, -14), S(-10,  -8), S(  6, -24),
            S(-109,  32), S(  4, -22), S(-46,  -7), S(-29,   3), S(  3, -11), S(-21,  -6), S(  9, -24), S( -0, -31)
        },
        {
            S(-13, -14), S(-15, -16), S(-140,   6), S(-90,   3), S(-42,  -1), S(-55,  -5), S(-19,  -6), S( 11, -23),
            S(-26,  -1), S(  7,  -8), S(-29,   2), S(-37, -10), S( 25, -11), S( 56, -17), S( 14,  -8), S(-42,  -6),
            S(-11,   1), S( 31, -16), S( 38, -11), S( 20,  -9), S( 27, -10), S( 58,  -9), S( 32,  -7), S( 12,   1),
            S(  6,  -7), S( 27,  -6), S( 15,   3), S( 49,   1), S( 35,   2), S( 35,  -1), S( 27, -14), S( 14,  -1),
            S( 20, -10), S( 24,  -8), S( 26,   1), S( 30,   8), S( 44,  -6), S( 18,  -1), S( 22, -13), S( 35, -12),
            S( 26, -10), S( 34,  -9), S( 26,   1), S( 31,   0), S( 29,   4), S( 46, -12), S( 30, -11), S( 37, -10),
            S( 44, -11), S( 38, -22), S( 37, -14), S( 23, -10), S( 32,  -8), S( 37, -16), S( 59, -23), S( 35, -24),
            S( -1,  -8), S( 38,  -4), S( 30, -14), S( 19,  -8), S( 27, -14), S( 25, -13), S(-13,   0), S( 16,  -7)
        },
        {
            S( 23,  16), S( 31,  12), S(-10,  28), S( 45,  12), S( 42,  15), S(-16,  25), S(  1,  19), S( 16,  12),
            S( 19,  16), S( 20,  18), S( 60,   8), S( 62,   7), S( 85,  -9), S( 78,  -2), S( 21,  15), S( 35,   9),
            S( -8,  17), S( 20,  14), S( 26,  10), S( 33,  10), S(  6,  11), S( 67,  -6), S( 82, -10), S( 29,  -2),
            S(-23,  17), S( -6,  11), S(  8,  20), S( 19,   7), S( 24,   8), S( 46,   3), S( 11,   3), S(-11,  13),
            S(-39,  20), S(-23,  17), S(-10,  16), S( -5,  11), S( 10,   2), S(  2,   1), S( 22,  -5), S(-24,   5),
            S(-40,  12), S(-20,   9), S(-12,   1), S(-14,   4), S(  4,  -3), S(  9,  -9), S(  4,  -3), S(-24,  -3),
            S(-36,   7), S( -9,   0), S(-12,   4), S( -0,   5), S( 12,  -9), S( 18,  -9), S( 12, -12), S(-52,  10),
            S( -7,  -2), S(  0,   3), S( 14,   2), S( 23,  -3), S( 27,  -7), S( 13,  -5), S(-14,   4), S( -0, -21)
        },
        {
            S( -2, -11), S(-27,  48), S( -4,  44), S(-11,  47), S(116, -12), S(120, -23), S( 84, -13), S( 77,  17),
            S(-20,  -1), S(-53,  34), S(-16,  35), S(-12,  55), S(-51,  89), S( 61,  15), S( 21,  40), S( 66,  16),
            S( -1,  -7), S(-14,   9), S( 12,  -8), S(-18,  65), S( 25,  47), S( 78,  19), S( 51,  26), S( 76,  18),
            S(-31,  34), S(-18,  22), S(-25,  24), S(-21,  39), S( -9,  59), S(  8,  43), S( -2,  87), S(  9,  72),
            S(  8, -14), S(-32,  38), S( -3,  10), S(-12,  35), S( -5,  25), S( -0,  29), S(  5,  50), S(  6,  53),
            S( -9,   9), S( 15, -38), S( -6,   4), S( 10, -12), S(  2,   1), S(  8,  15), S( 20,  17), S( 16,  35),
            S( -7, -10), S(  4, -29), S( 24, -38), S( 23, -38), S( 31, -36), S( 30, -34), S( 15, -46), S( 27, -27),
            S( 24, -41), S( 23, -44), S( 27, -36), S( 36, -46), S( 20, -19), S(  3, -28), S(  5, -19), S(-32, -24)
        },
        {
            S(-65, -77), S(180, -69), S(171, -50), S(101, -38), S(-127,  15), S(-71,  30), S( 70,  -9), S( 56, -24),
            S(202, -53), S( 88,   1), S( 48,   7), S(124,  -2), S( 53,  13), S( 48,  33), S(-14,  28), S(-130,  35),
            S( 94, -11), S( 89,   8), S(114,   6), S( 28,  15), S( 51,  14), S(127,  32), S(137,  24), S(  3,  10),
            S( 26, -18), S(  9,  21), S( 33,  23), S(-28,  37), S(-38,  37), S(-29,  43), S(  0,  31), S(-78,  17),
            S(-62,  -9), S( 34,  -7), S(-51,  34), S(-109,  48), S(-113,  52), S(-75,  41), S(-65,  25), S(-85,   4),
            S( 13, -22), S( -2,   1), S(-42,  24), S(-70,  37), S(-79,  42), S(-64,  34), S(-18,  15), S(-34,  -1),
            S( 18, -33), S( 19,  -9), S(-24,  15), S(-75,  26), S(-56,  27), S(-35,  18), S( 14,  -2), S( 23, -23),
            S(-17, -60), S( 49, -45), S( 19, -22), S(-74,   2), S(  4, -23), S(-32,  -5), S( 43, -36), S( 29, -60)
        },
    }};

    static constexpr std::array<PhaseScore, 64> passedPawnPst =
    {
        S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
        S(-28,  31), S(-15,   5), S( -1,  45), S(-15,  55), S( -8,  42), S( -5,  35), S(  2,  43), S(  3,  58),
        S( 37, 151), S(  1, 159), S( 39, 111), S(  4, 112), S( 46,  76), S(  2, 105), S(-33, 134), S(-39, 147),
        S( 21,  82), S(  4,  74), S( 18,  58), S(  2,  49), S(  1,  35), S( 39,  37), S( -8,  72), S( -0,  71),
        S(  9,  45), S(-22,  43), S(-22,  34), S(-18,  26), S(-13,  25), S( -9,  29), S(-22,  47), S( 21,  39),
        S(  4,  16), S(-17,  21), S(-16,  15), S(-37,  15), S( -8,   8), S( 29,  -1), S(  7,  23), S( 30,  11),
        S( -5,  14), S(  6,  14), S( 12,  -1), S(-29,  19), S(-11,  19), S( 18,   3), S( 17,  14), S(  1,  14),
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
            S(-83, -59), S(-46, -57), S(-36, -17), S(-26,   8), S( -7,   9), S( -1,  17), S(  8,  20), S( 18,  18),
            S( 32,  10), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  9, -33), S(-45, -66), S(-32, -27), S(-15,  -9), S( -4,  -1), S(  7,   7), S( 13,  12), S( 20,  16),
            S( 23,  19), S( 30,  21), S( 40,  17), S( 65,  11), S( 50,  22), S( 80,   9), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S( 27,  10), S(-53, -25), S(-50, -58), S(-40, -37), S(-33, -10), S(-26,  -2), S(-18,   9), S(-13,  13),
            S( -2,  10), S(  9,  11), S( 23,  12), S( 36,  14), S( 50,  16), S( 57,  17), S( 75,   9), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(-85, -51), S(-72, -98), S(-27, -133), S(-28, -68), S(-19, -63),
            S(-18, -63), S(-11, -52), S( -8, -34), S( -6, -23), S( -2,  -7), S(  3,  -2), S(  7,   4), S(  8,  21),
            S( 13,  18), S( 11,  37), S( 17,  31), S( 22,  42), S( 22,  54), S( 45,  46), S( 37,  59), S( 48,  58),
            S( 43,  65), S( 77,  38), S( 42,  61), S( 71,  50)
        },
        {
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0),
            S(  0,   0), S(  0,   0), S(  0,   0), S(  0,   0)
        },
    }};

    static constexpr PhaseScore bishopPairBonus = S(30, 54);
    static constexpr PhaseScore doubledPawnBonus = S(-5, -13);
    static constexpr PhaseScore protectedPawnBonus = S(14, 10);
    static constexpr PhaseScore weakPawnBonus = S(-11, -9);
    static constexpr PhaseScore rookOpenFileBonus = S(16, -4);
    static constexpr PhaseScore rookSemiOpenFileBonus = S(1, 8);

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