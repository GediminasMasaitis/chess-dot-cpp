#pragma once

#include "board.h"
#include "evalstate.h"

class EvaluationData
{
public:
    using Scoreboard = EachPosition<Score>;
    
private:

    static constexpr Scoreboard EmptyScoreboard
    {
        0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0
    };
    
    static constexpr Scoreboard PawnPcsqMidgame
    {
         0,   0,   0,   0,   0,   0,   0,   0,
        -6,  -4,   1,  -24,  -24, 1,  -4,  -6,
        -4,  -4,   1,   5,   5,   1,  -4,  -4,
        -6,  -4,   5,   10,  10,  5,  -4,  -6,
        -6,  -4,   2,   8,   8,   2,  -4,  -6,
        -6,  -4,   1,   2,   2,   1,  -4,  -6,
        -6,  -4,   1,   1,   1,   1,  -4,  -6,
         0,   0,   0,   0,   0,   0,   0,   0
    };

    static constexpr Scoreboard PawnPcsqEndgame
    {
         0,   0,   0,   0,   0,   0,   0,   0,
        -6,  -4,   1,  -24, -24,  1,  -4,  -6,
        -4,  -4,   1,   5,   5,   1,  -4,  -4,
        -6,  -4,   5,   10,  10,  5,  -4,  -6,
        -6,  -4,   2,   8,   8,   2,  -4,  -6,
        -6,  -4,   1,   2,   2,   1,  -4,  -6,
        -6,  -4,   1,   1,   1,   1,  -4,  -6,
         0,   0,   0,   0,   0,   0,   0,   0
    };

    static constexpr Scoreboard KnightPcsqMidgame
    {
        -16, -12, -8,  -8,  -8,  -8, -12,  -16,
        -8,   0,   1,   2,   2,   1,   0,  -8,
        -8,   0,   4,   6,   6,   4,   0,  -8,
        -8,   0,   6,   8,   8,   6,   0,  -8,
        -8,   0,   6,   8,   8,   6,   0,  -8,
        -8,   0,   4,   6,   6,   4,   0,  -8,
        -8,   0,   0,   0,   0,   0,   0,  -8,
        -8,  -8,  -8,  -8,  -8,  -8,  -8,  -8
    };

    static constexpr Scoreboard KnightPcsqEndgame
    {
        -16, -12, -8,  -8,  -8,  -8, -12,  -16,
        -8,   0,   1,   2,   2,   1,   0,  -8,
        -8,   0,   4,   6,   6,   4,   0,  -8,
        -8,   0,   6,   8,   8,   6,   0,  -8,
        -8,   0,   6,   8,   8,   6,   0,  -8,
        -8,   0,   4,   6,   6,   4,   0,  -8,
        -8,   0,   0,   0,   0,   0,   0,  -8,
        -8,  -8,  -8,  -8,  -8,  -8,  -8,  -8
    };

    static constexpr Scoreboard BishopPcsqMidgame
    {
        -4,  -4,  -12, -4,  -4,  -12, -4,  -4,
        -4,   2,   1,   1,   1,   1,   2,  -4,
        -4,   1,   2,   4,   4,   2,   1,  -4,
        -4,   0,   4,   6,   6,   4,   0,  -4,
        -4,   0,   4,   6,   6,   4,   0,  -4,
        -4,   0,   2,   4,   4,   2,   0,  -4,
        -4,   0,   0,   0,   0,   0,   0,  -4,
        -4,  -4,  -4,  -4,  -4,  -4,  -4,  -4
    };

    static constexpr Scoreboard BishopPcsqEndgame
    {
        -4,  -4,  -12, -4,  -4,  -12, -4,  -4,
        -4,   2,   1,   1,   1,   1,   2,  -4,
        -4,   1,   2,   4,   4,   2,   1,  -4,
        -4,   0,   4,   6,   6,   4,   0,  -4,
        -4,   0,   4,   6,   6,   4,   0,  -4,
        -4,   0,   2,   4,   4,   2,   0,  -4,
        -4,   0,   0,   0,   0,   0,   0,  -4,
        -4,  -4,  -4,  -4,  -4,  -4,  -4,  -4
    };

    static constexpr Scoreboard RookPcsqMidgame
    {
        0,   0,   0,   2,   2,   0,   0,   0,
       -5,   0,   0,   0,   0,   0,   0,  -5,
       -5,   0,   0,   0,   0,   0,   0,  -5,
       -5,   0,   0,   0,   0,   0,   0,  -5,
       -5,   0,   0,   0,   0,   0,   0,  -5,
       -5,   0,   0,   0,   0,   0,   0,  -5,
       -5,   0,   0,   0,   0,   0,   0,  -5,
        5,   5,   5,   5,   5,   5,   5,   5
    };

    static constexpr Scoreboard RookPcsqEndgame
    {
        0,   0,   0,   2,   2,   0,   0,   0,
       -5,   0,   0,   0,   0,   0,   0,  -5,
       -5,   0,   0,   0,   0,   0,   0,  -5,
       -5,   0,   0,   0,   0,   0,   0,  -5,
       -5,   0,   0,   0,   0,   0,   0,  -5,
       -5,   0,   0,   0,   0,   0,   0,  -5,
       -5,   0,   0,   0,   0,   0,   0,  -5,
        5,   5,   5,   5,   5,   5,   5,   5
    };

    static constexpr Scoreboard QueenPcsqMidgame
    {
       -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5,
        0,   0,   1,   1,   1,   1,   0,   0,
        0,   0,   1,   2,   2,   1,   0,   0,
        0,   0,   2,   3,   3,   2,   0,   0,
        0,   0,   2,   3,   3,   2,   0,   0,
        0,   0,   1,   2,   2,   1,   0,   0,
        0,   0,   1,   1,   1,   1,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0
    };

    static constexpr Scoreboard QueenPcsqEndgame
    {
       -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5,
        0,   0,   1,   1,   1,   1,   0,   0,
        0,   0,   1,   2,   2,   1,   0,   0,
        0,   0,   2,   3,   3,   2,   0,   0,
        0,   0,   2,   3,   3,   2,   0,   0,
        0,   0,   1,   2,   2,   1,   0,   0,
        0,   0,   1,   1,   1,   1,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0
    };

    static constexpr Scoreboard KingPcsqMidgame
    {
       40,  50,  30,  10,  10,  30,  50,  40,
       30,  40,  20,   0,   0,  20,  40,  30,
       10,  20,   0, -20, -20,   0,  20,  10,
        0,  10, -10, -30, -30, -10,  10,   0,
      -10,   0, -20, -40, -40, -20,   0, -10,
      -20, -10, -30, -50, -50, -30, -10, -20,
      -30, -20, -40, -60, -60, -40, -20, -30,
      -40, -30, -50, -70, -70, -50, -30, -40
    };

    static constexpr Scoreboard KingPcsqEndgame
    {
      -72, -48, -36, -24, -24, -36, -48, -72,
      -48, -24, -12,   0,   0, -12, -24, -48,
      -36, -12,   0,  12,  12,   0, -12, -36,
      -24,   0,  12,  24,  24,  12,   0, -24,
      -24,   0,  12,  24,  24,  12,   0, -24,
      -36, -12,   0,  12,  12,   0, -12, -36,
      -48, -24, -12,   0,   0, -12, -24, -48,
      -72, -48, -36, -24, -24, -36, -48, -72
    };

    static constexpr Scoreboard WeakPawnPcsq
    {
        0,   0,   0,   0,   0,   0,   0,   0,
       -10, -12, -14, -16, -16, -14, -12, -10,
       -10, -12, -14, -16, -16, -14, -12, -10,
       -10, -12, -14, -16, -16, -14, -12, -10,
       -10, -12, -14, -16, -16, -14, -12, -10,
       -10, -12, -14, -16, -16, -14, -12, -10,
       -10, -12, -14, -16, -16, -14, -12, -10,
        0,   0,   0,   0,   0,   0,   0,   0
    };

    static constexpr Scoreboard PassedPawnPcsq
    {
        0,   0,   0,   0,   0,   0,   0,   0,
        20,  20,  20,  20,  20,  20,  20,  20,
        20,  20,  20,  20,  20,  20,  20,  20,
        32,  32,  32,  32,  32,  32,  32,  32,
        56,  56,  56,  56,  56,  56,  56,  56,
        92,  92,  92,  92,  92,  92,  92,  92,
        140, 140, 140, 140, 140, 140, 140, 140,
        0,   0,   0,   0,   0,   0,   0,   0
    };

    static constexpr Scoreboard ProtectedPasserPcsq
    {
        0,   0,   0,   0,   0,   0,   0,   0,
        25,  25,  25,  25,  25,  25,  25,  25,
        25,  25,  25,  25,  25,  25,  25,  25,
        40,  40,  40,  40,  40,  40,  40,  40,
        70,  70,  70,  70,  70,  70,  70,  70,
        115, 115, 115, 115, 115, 115, 115, 115,
        175, 175, 175, 175, 175, 175, 175, 175,
        0,   0,   0,   0,   0,   0,   0,   0
    };

public:
    
    static constexpr EachColor<Rank> Seventh = { 6, 1 };
    static constexpr EachColor<Rank> Eighth = { 7, 0 };

    // TODO: Make it go up to 64
    static constexpr std::array<Score, 17> KnightPawnAdjust = { -20, -16, -12, -8, -4, 0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44 };
    static constexpr std::array<Score, 17> RookPawnAdjust = { 15, 12, 9, 6, 3, 0, -3, -6, -9, -12, -15, -18, -21, -24, -27, -30, -33 };

    static constexpr EachPiece<Phase> PiecePhases = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 4, 4, 0, 0 };
    static constexpr Phase MaxPhase = 4 * PiecePhases[Pieces::Knight] + 4 * PiecePhases[Pieces::Bishop] + 4 * PiecePhases[Pieces::Rook] + 2 * PiecePhases[Pieces::Queen];
    
    static constexpr EachColor<Scoreboard> WeakPawn = Positions::MakeRelative(WeakPawnPcsq);
    static constexpr EachColor<Scoreboard> PassedPawn = Positions::MakeRelative(PassedPawnPcsq);
    static constexpr EachColor<Scoreboard> ProtectedPasser = Positions::MakeRelative(ProtectedPasserPcsq);
    
    static constexpr EachPiece<Scoreboard> Midgame =
    {
        EmptyScoreboard,
        EmptyScoreboard,
        EmptyScoreboard,
        EmptyScoreboard,
        PawnPcsqMidgame,
        Positions::MakeReflected(PawnPcsqMidgame),
        KnightPcsqMidgame,
        Positions::MakeReflected(KnightPcsqMidgame),
        BishopPcsqMidgame,
        Positions::MakeReflected(BishopPcsqMidgame),
        RookPcsqMidgame,
        Positions::MakeReflected(RookPcsqMidgame),
        QueenPcsqMidgame,
        Positions::MakeReflected(QueenPcsqMidgame),
        KingPcsqMidgame,
        Positions::MakeReflected(KingPcsqMidgame)
    };

    static constexpr EachPiece<Scoreboard> Endgame =
    {
        EmptyScoreboard,
        EmptyScoreboard,
        EmptyScoreboard,
        EmptyScoreboard,
        PawnPcsqEndgame,
        Positions::MakeReflected(PawnPcsqEndgame),
        KnightPcsqEndgame,
        Positions::MakeReflected(KnightPcsqEndgame),
        BishopPcsqEndgame,
        Positions::MakeReflected(BishopPcsqEndgame),
        RookPcsqEndgame,
        Positions::MakeReflected(RookPcsqEndgame),
        QueenPcsqEndgame,
        Positions::MakeReflected(QueenPcsqEndgame),
        KingPcsqEndgame,
        Positions::MakeReflected(KingPcsqEndgame)
    };

    static constexpr std::array<Score, 100> SafetyTable =
    {
        0,  0,   1,   2,   3,   5,   7,   9,  12,  15,
        18,  22,  26,  30,  35,  39,  44,  50,  56,  62,
        68,  75,  82,  85,  89,  97, 105, 113, 122, 131,
        140, 150, 169, 180, 191, 202, 213, 225, 237, 248,
        260, 272, 283, 295, 307, 319, 330, 342, 354, 366,
        377, 389, 401, 412, 424, 436, 448, 459, 471, 483,
        494, 500, 500, 500, 500, 500, 500, 500, 500, 500,
        500, 500, 500, 500, 500, 500, 500, 500, 500, 500,
        500, 500, 500, 500, 500, 500, 500, 500, 500, 500,
        500, 500, 500, 500, 500, 500, 500, 500, 500, 500
    };

    static constexpr Score BishopPair = 30;
    static constexpr Score KnightPair = -8;
    static constexpr Score RookPair = -16;

    static constexpr Score RookOpenFile = 10;
    static constexpr Score RookHalfOpenFile = 5;

    static constexpr Score BishopTrappedA7 = -150;
    static constexpr Score BishopTrappedA6 = -50;
    static constexpr Score KnightTrappedA8 = -150;
    static constexpr Score KnightTrappedA7 = -100;
    static constexpr Score BlockedCentralPawn = -24;
    static constexpr Score KingBlocksRook = -24;

    static constexpr Score KingShieldRank2 = 10;
    static constexpr Score KingShieldRank3 = 5;
    static constexpr Score KingNoShield = -10;

    static constexpr Score ReturningBishop = 20;
    static constexpr Score KnightC3 = -5;
    static constexpr Score NoFianchetto = -4;
    static constexpr Score Fianchetto = 4;
    static constexpr Score Tempo = 10;
};

class Evaluation
{
public:
    static Score Evaluate(const Board& board, const EachColor<Bitboard>& pins, EvalState& state);
};