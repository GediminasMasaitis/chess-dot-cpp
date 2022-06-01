#pragma once

#include "common.h"
#include "board.h"

#define TUNE 0
#define TAPERED 1

#if TUNE
#define TraceParam Trace& T,
#define TraceIncr(term) ++T.term[color]
#define TraceAdd(term, count) T.term[color] += count
#define TraceEval(e) T.eval = e
#define TracePhase(e) T.phase = e
#else
#define TraceParam
#define TraceIncr(term)
#define TraceAdd(term, count)
#define TraceEval(e)
#define TracePhase(e)
#endif

class PhaseStages
{
public:
    static constexpr PhaseStage Midgame = 0;
    static constexpr PhaseStage Endgame = 1;

    static constexpr PhaseStage Count = 2;
};

template<class T>
using EachPhase = std::array<T, PhaseStages::Count>;

static constexpr EachPiece<Phase> PiecePhases = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 4, 4, 0, 0 };
static constexpr Phase MaxPhase = 4 * PiecePhases[Pieces::Knight] + 4 * PiecePhases[Pieces::Bishop] + 4 * PiecePhases[Pieces::Rook] + 2 * PiecePhases[Pieces::Queen];

static Phase GetPhase(const BoardBase& board)
{
    const Phase phase = PiecePhases[Pieces::WhiteKnight] * board.PieceCounts[Pieces::WhiteKnight]
        + PiecePhases[Pieces::WhiteBishop] * board.PieceCounts[Pieces::WhiteBishop]
        + PiecePhases[Pieces::WhiteRook] * board.PieceCounts[Pieces::WhiteRook]
        + PiecePhases[Pieces::WhiteQueen] * board.PieceCounts[Pieces::WhiteQueen]
        + PiecePhases[Pieces::BlackKnight] * board.PieceCounts[Pieces::BlackKnight]
        + PiecePhases[Pieces::BlackBishop] * board.PieceCounts[Pieces::BlackBishop]
        + PiecePhases[Pieces::BlackRook] * board.PieceCounts[Pieces::BlackRook]
        + PiecePhases[Pieces::BlackQueen] * board.PieceCounts[Pieces::BlackQueen];

    return phase;
}

static constexpr Score MgScore(int s)
{
    return static_cast<int16_t>(static_cast<uint16_t>(static_cast<unsigned>(s)));
}

static constexpr Score EgScore(int s)
{
    return static_cast<int16_t>(static_cast<uint16_t>(static_cast<unsigned>(s + 0x8000) >> 16));
}

static constexpr int S(const int mg, const int eg)
{
    return static_cast<int>(static_cast<unsigned int>(eg) << 16) + mg;
}

static constexpr Position GetRelative(Color c, Position p)
{
    return c == Colors::White ? p : p ^ 56;
}

static constexpr Position GetRelativeInverse(Color c, Position p)
{
    return c == Colors::White ? p ^ 56: p;
}