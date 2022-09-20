#pragma once

#include "common.h"
#include "moveorder.h"

class ThreadState;

class MovePickerEntry
{
public:
    Move move;
    Score see;
};

enum class MovePickerStage
{
    TranspositionTableMove,
    CaptureGen,
    Captures,
    Killers,
    NonCaptureGen,
    NonCaptures,
    FirstBadCapture,
    BadCaptures
};

class MovePicker
{
private:
    MovePickerStage _stage;

    MoveArray _captures;
    MoveCount _captureCount;
    int16_t _captureIndex;
    MoveScoreArray _captureScores;
    ScoreArray _seeScores;
    bool _hasBadCaptures;

    MoveArray _nonCaptures;
    MoveCount _nonCaptureCount;
    int16_t _nonCaptureIndex;
    MoveScoreArray _nonCaptureScores;

    int16_t _killerIndex;

    ThreadState* _state;
    Ply _ply;
    Board* _board;
    Bitboard _checkers;
    Bitboard _pinned;
    Move _ttMove;

public:
    void Reset(ThreadState& state, Ply ply, Board& board, Bitboard checkers, Bitboard pinned, Move ttMove);
    void InitCaptures();
    void InitNonCaptures();

    template<bool VAllowNonCaptures>
    bool GetNextMove(MovePickerEntry& entry);
};
