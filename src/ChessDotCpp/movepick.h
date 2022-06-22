#pragma once

#include "common.h"
#include "movegen.h"
#include "moveorder.h"
#include "see.h"

class MovePickerEntry
{
public:
    Move move;
    Score see;
};

enum class MovePickerStage
{
    TranspositionTableMove,
    Other
};

class MovePicker2
{
public:
    //using EntryArray = std::array<MovePicker, Constants::MaxMoves>;

    MovePickerStage _stage;

    MoveArray _moves;
    MoveCount _moveCount;
    int16_t _moveIndex;
    ScoreArray _seeScores;
    MoveScoreArray _moveScores;
    bool _init;

    SearchState* _state;
    Ply _ply;
    Board* _board;
    Bitboard _checkers;
    Bitboard _pinned;
    Move _ttMove;
    
    void Reset(SearchState& state, Ply ply, Board& board, Bitboard checkers, Bitboard pinned, Move ttMove)
    {
        _state = &state;
        _ply = ply;
        _board = &board;
        _checkers = checkers;
        _pinned = pinned;
        _ttMove = ttMove;
        _init = false;

        _stage = MovePickerStage::TranspositionTableMove;
        _moveCount = 0;
        _moveIndex = -1;
    }

    void Init()
    {
        MoveGenerator::GetAllPotentialMoves(*_board, _checkers, _pinned, _moves, _moveCount);
        See::CalculateSeeScores(*_board, _moves, _moveCount, _seeScores);

        const ThreadId threadId = 0;
        const ThreadState& threadState = _state->Thread[threadId];
        const Move previousMove = _ply != 0 ? _board->History[_board->HistoryDepth - 1].Move : Move(0);
        const Move countermove = threadState.Countermoves[previousMove.GetPiece()][previousMove.GetTo()];
        MoveOrdering::CalculateStaticScores(threadId, *_state, _moves, _seeScores, _moveCount, _ply, _ttMove, countermove, _moveScores, *_board);
        auto b = 123;
    }

    bool GetNextMove(MovePickerEntry& entry)
    {
        //if(_stage == MovePickerStage::TranspositionTableMove && _ttMove.Value != 0)
        //{
        //    //_moveIndex++;
        //    entry.move = _ttMove;
        //    const bool valid = MoveValidator::IsKingSafeAfterMove2(*_board, _ttMove, _checkers, _pinned);
        //    if (!valid)
        //    {
        //        std::cout << "TT INVALID\n";
        //    }
        //    assert(valid);
        //    if(_ttMove.GetTakesPiece() != 0)
        //    {
        //        entry.see = See::GetSee(*_board, _ttMove);
        //    }
        //    else
        //    {
        //        entry.see = 0;
        //    }
        //    _stage = MovePickerStage::Other;
        //    return true;
        //}

        if(!_init)
        {
            Init();
            _init = true;
        }

        while(true)
        {
            _moveIndex++;
            if (_moveIndex >= _moveCount)
            {
                return false;
            }

            const auto index = static_cast<MoveCount>(_moveIndex);
            MoveOrdering::OrderNextMove(index, _moves, _seeScores, _moveScores, _moveCount);
            const auto& move = _moves[index];

            //if(move.Value == _ttMove.Value)
            //{
            //    continue;
            //}

            const bool valid = MoveValidator::IsKingSafeAfterMove2(*_board, move, _checkers, _pinned);
            if(!valid)
            {
                continue;
            }

            entry.move = move;
            entry.see = _seeScores[index];

            return true;
        }
    }
};

class MovePicker
{
public:
    //using EntryArray = std::array<MovePicker, Constants::MaxMoves>;

    MovePickerStage _stage;

    MoveArray _moves;
    MoveCount _moveCount;
    int16_t _moveIndex;
    ScoreArray _seeScores;
    MoveScoreArray _moveScores;
    bool _init;

    SearchState* _state;
    Ply _ply;
    Board* _board;
    Bitboard _checkers;
    Bitboard _pinned;
    Move _ttMove;

    void Reset(SearchState& state, Ply ply, Board& board, Bitboard checkers, Bitboard pinned, Move ttMove)
    {
        _state = &state;
        _ply = ply;
        _board = &board;
        _checkers = checkers;
        _pinned = pinned;
        _ttMove = ttMove;
        _init = false;

        _stage = MovePickerStage::TranspositionTableMove;
        _moveCount = 0;
        _moveIndex = -1;
    }

    void Init()
    {
        MoveGenerator::GetAllPotentialMoves(*_board, _checkers, _pinned, _moves, _moveCount);
        See::CalculateSeeScores(*_board, _moves, _moveCount, _seeScores);

        const ThreadId threadId = 0;
        const ThreadState& threadState = _state->Thread[threadId];
        const Move previousMove = _ply != 0 ? _board->History[_board->HistoryDepth - 1].Move : Move(0);
        const Move countermove = threadState.Countermoves[previousMove.GetPiece()][previousMove.GetTo()];
        MoveOrdering::CalculateStaticScores(threadId, *_state, _moves, _seeScores, _moveCount, _ply, _ttMove, countermove, _moveScores, *_board);
        auto b = 123;
    }

    bool GetNextMove(MovePickerEntry& entry)
    {
        //if (!_init)
        //{
        //    Init();
        //    _init = true;
        //}

        if (_stage == MovePickerStage::TranspositionTableMove && _ttMove.Value != 0)
        {
            //_moveIndex++;
            entry.move = _ttMove;
            const bool valid = MoveValidator::IsKingSafeAfterMove2(*_board, _ttMove, _checkers, _pinned);
            if (!valid)
            {
                std::cout << "TT INVALID\n";
            }
            assert(valid);
            if (_ttMove.GetTakesPiece() != 0)
            {
                entry.see = See::GetSee(*_board, _ttMove);
            }
            else
            {
                entry.see = 0;
            }
            _stage = MovePickerStage::Other;
            return true;
        }

        if (!_init)
        {
            Init();
            _init = true;
        }

        while (true)
        {
            _moveIndex++;
            if (_moveIndex >= _moveCount)
            {
                return false;
            }

            const auto index = static_cast<MoveCount>(_moveIndex);
            MoveOrdering::OrderNextMove(index, _moves, _seeScores, _moveScores, _moveCount);
            const auto& move = _moves[index];

            if (move.Value == _ttMove.Value)
            {
                continue;
            }

            const bool valid = MoveValidator::IsKingSafeAfterMove2(*_board, move, _checkers, _pinned);
            if (!valid)
            {
                continue;
            }

            entry.move = move;
            entry.see = _seeScores[index];

            return true;
        }
    }
};