#pragma once

#include "common.h"
#include "movegen.h"
#include "moveorder.h"
#include "see.h"
#include "display.h"

#define TESTMOVEPICK 0

class MovePickerEntry
{
public:
    Move move;
    Score see;
};

enum class MovePickerStage
{
    TranspositionTableMove,
    //OtherGen,
    //Other,
    CaptureGen,
    Captures,
    Killers,
    NonCaptureGen,
    NonCaptures,
    FirstBadCapture,
    BadCaptures
    //OtherGen,
    //Other
};

class MovePicker2
{
private:
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
public:
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

    //MoveArray _otherMoves;
    //MoveCount _otherMoveCount;
    //int16_t _otherIndex;
    //MoveScoreArray _otherScores;
    //ScoreArray _otherSeeScores;

    int16_t _killerIndex;

    ThreadState* _state;
    Ply _ply;
    Board* _board;
    Bitboard _checkers;
    Bitboard _pinned;
    Move _ttMove;

public:
#if TESTMOVEPICK
    MoveArray _debugPossibleMoves;
    MoveArray _debugPossibleMovesCopy;
    MoveCount _debugPossibleCount;
    ScoreArray _debugSee;
    ScoreArray _debugSeeCopy;
    MoveScoreArray _debugScores;
    MoveScoreArray _debugScoresCopy;

    MoveArray _debugMoves;
    MoveCount _debugCount;
    int16_t _debugIndex;
#endif

    void Reset(ThreadState& state, Ply ply, Board& board, Bitboard checkers, Bitboard pinned, Move ttMove)
    {
        _state = &state;
        _ply = ply;
        _board = &board;
        _checkers = checkers;
        _pinned = pinned;
        _ttMove = ttMove;

        _stage = MovePickerStage::TranspositionTableMove;
        _captureCount = 0;
        _captureIndex = -1;
        _nonCaptureCount = 0;
        _nonCaptureIndex = -1;
        _hasBadCaptures = false;
        _killerIndex = -1;

        //_otherMoveCount = 0;
        //_otherIndex = -1;

#if TESTMOVEPICK
        _debugPossibleCount = 0;
        _debugCount = 0;
        _debugIndex = -1;
        MoveGenerator::GetAllPotentialMoves(board, checkers, pinned, _debugPossibleMoves, _debugPossibleCount);
        _debugPossibleMovesCopy = _debugPossibleMoves;
        See::CalculateSeeScores(board, _debugPossibleMoves, _debugPossibleCount, _debugSee);
        _debugSeeCopy = _debugSee;
        Move previousMove1 = ply > 0 ? board.History[board.HistoryDepth - 1].Move : Move(0);
        Move previousMove2 = board.HistoryDepth > 1 ? board.History[board.HistoryDepth - 2].Move : Move(0);
        const auto& threadState = state.Thread[0];
        const Move countermove = threadState.Countermoves[previousMove1.GetPiece()][previousMove1.GetTo()];
        MoveOrdering::CalculateStaticScores(0, state, _debugPossibleMoves, _debugSee, _debugPossibleCount, ply, ttMove, countermove, _debugScores, board);
        _debugScoresCopy = _debugScores;
        for(MoveCount index = 0; index < _debugPossibleCount; index++)
        {
            const auto& move = _debugPossibleMoves[index];

            MoveOrdering::OrderNextMove(index, _debugPossibleMoves, _debugSee, _debugScores, _debugPossibleCount);

            if (!MoveValidator::IsKingSafeAfterMove2(board, move, checkers, pinned))
            {
                continue;
            }

            _debugMoves[_debugCount] = move;
            _debugCount++;
        }
#endif
    }

    void InitCaptures()
    {
        MoveGenerator::GetAllPotentialCaptures(*_board, _checkers, _pinned, _captures, _captureCount);
        See::CalculateSeeScores(*_board, _captures, _captureCount, _seeScores);

        MoveOrdering2::CalculateStaticCaptureScores(*_state, _captures, _seeScores, _captureCount, _captureScores);
    }

    void InitNonCaptures()
    {
        MoveGenerator::GetAllPotentialNonCaptures(*_board, _checkers, _pinned, _nonCaptures, _nonCaptureCount);
        const Move previousMove = _ply != 0 ? _board->History[_board->HistoryDepth - 1].Move : Move(0);
        const Move countermove = _state->Countermoves[previousMove.GetPiece()][previousMove.GetTo()];
        MoveOrdering2::CalculateStaticNonCaptureScores(*_state, _nonCaptures, _nonCaptureCount, countermove, _nonCaptureScores, *_board);
    }

#if TESTMOVEPICK
    bool IsPseudoLegalDebug(Move move)
    {
        for (auto i = 0; i < _debugPossibleCount; i++)
        {
            if(move.Value == _debugPossibleMoves[i].Value)
            {
                return true;
            }
        }
        return false;
    }

    bool IsLegalDebug(Move move)
    {
        for (auto i = 0; i < _debugCount; i++)
        {
            if (move.Value == _debugMoves[i].Value)
            {
                return true;
            }
        }
        return false;
    }
#endif

    //void InitOther()
    //{
    //    MoveGenerator::GetAllPotentialMoves(*_board, _checkers, _pinned, _otherMoves, _otherMoveCount);
    //    See::CalculateSeeScores(*_board, _otherMoves, _otherMoveCount, _otherSeeScores);

    //    const ThreadId threadId = 0;
    //    const ThreadState& threadState = _state->Thread[threadId];
    //    const Move previousMove = _ply != 0 ? _board->History[_board->HistoryDepth - 1].Move : Move(0);
    //    const Move countermove = threadState.Countermoves[previousMove.GetPiece()][previousMove.GetTo()];
    //    MoveOrdering::CalculateStaticScores(threadId, *_state, _otherMoves, _otherSeeScores, _otherMoveCount, _ply, _ttMove, countermove, _otherScores, *_board);
    //    auto b = 123;
    //}

    template<bool VAllowNonCaptures>
    bool GetNextMove(MovePickerEntry& entry)
    {
        constexpr bool allowNonCaptures = VAllowNonCaptures;
        constexpr MoveScore badCapture = -500'000'000;
        switch (_stage)
        {
        case MovePickerStage::TranspositionTableMove:
            _stage = MovePickerStage::CaptureGen;

            if constexpr (allowNonCaptures)
            {
                if (_ttMove.Value != 0)
                {
                    if(!MoveValidator::IsPseudoLegal(*_board, _ttMove))
                    {
                        Display::DisplayBoard(*_board, _ttMove);
                        auto a = 123;
                    }
                    assert(MoveValidator::IsPseudoLegal(*_board, _ttMove));
                    assert(MoveValidator::IsKingSafeAfterMove(*_board, _ttMove));
                    assert(MoveValidator::IsKingSafeAfterMove2(*_board, _ttMove, _checkers, _pinned));
                    entry.move = _ttMove;
                    if (_ttMove.GetTakesPiece() != Pieces::Empty)
                    {
                        entry.see = See::GetSee(*_board, _ttMove);
                    }
                    else
                    {
                        entry.see = 0;
                    }
#if TESTMOVEPICK
                    _debugIndex++;
                    assert(entry.move.Value == _debugMoves[_debugIndex].Value);
#endif
                    return true;
                }
            }
            else
            {
                if (_ttMove.Value != 0 && _ttMove.GetTakesPiece() != Pieces::Empty)
                {
                    assert(MoveValidator::IsPseudoLegal(*_board, _ttMove));
                    assert(MoveValidator::IsKingSafeAfterMove(*_board, _ttMove));
                    assert(MoveValidator::IsKingSafeAfterMove2(*_board, _ttMove, _checkers, _pinned));
                    entry.move = _ttMove;
                    entry.see = See::GetSee(*_board, _ttMove);
                    return true;
                }
            }

            [[fallthrough]];
//        case MovePickerStage::OtherGen:
//            InitOther();
//            _stage = MovePickerStage::Other;
//            [[fallthrough]];
//        case MovePickerStage::Other:
//            while (true)
//            {
//                _otherIndex++;
//                if (_otherIndex >= _otherMoveCount)
//                {
//                    return false;
//                }
//
//                const auto index = static_cast<MoveCount>(_otherIndex);
//
//#if TESTMOVEPICK
//                assert(_otherMoveCount == _debugPossibleCount);
//#endif
//                MoveOrdering::OrderNextMove(index, _otherMoves, _otherSeeScores, _otherScores, _otherMoveCount);
//                //MoveOrdering::OrderNextMove(index, _otherMoves, _debugSeeCopy, _debugScoresCopy, _otherMoveCount);
//                const auto& move = _otherMoves[index];
//
//#if TESTMOVEPICK
//                if(_debugPossibleMoves[_otherIndex].Value != move.Value)
//                {
//                    Display::DisplayBoard(*_board);
//                    std::cout << _otherIndex << "\n";
//                    std::cout << move.ToDebugString() << "\n";
//                    std::cout << _debugPossibleMoves[_otherIndex].ToDebugString() << "\n";
//                    assert(false);
//                }
//#endif
//                if (move.Value == _ttMove.Value)
//                {
//#if TESTMOVEPICK
//                    const bool ttValid = MoveValidator::IsKingSafeAfterMove2(*_board, move, _checkers, _pinned);
//                    if (!ttValid)
//                    {
//                        assert(false);
//                    }
//                    _debugIndex++;
//                    if (_debugMoves[_debugIndex].Value != move.Value)
//                    {
//                        Display::DisplayBoard(*_board);
//                        std::cout << _debugIndex << "\n";
//                        std::cout << move.ToDebugString() << "\n";
//                        std::cout << _debugMoves[_debugIndex].ToDebugString() << "\n";
//                        assert(false);
//                    }
//#endif
//                    continue;
//                }
//
//                //bool isKiller = false;
//                //const auto& killers = _state->Thread[0].Plies[_ply].Killers;
//                //for(auto killerIndex = 0; killerIndex < killers.size(); killerIndex++)
//                //{
//                //    if(move.Value == killers[killerIndex].Value)
//                //    {
//                //        isKiller = true;
//                //        break;
//                //    }
//                //}
//                //if(isKiller)
//                //{
//                //    continue;
//                //}
//
//                const bool valid = MoveValidator::IsKingSafeAfterMove2(*_board, move, _checkers, _pinned);
//                if (!valid)
//                {
//                    continue;
//                }
//
//#if TESTMOVEPICK
//                _debugIndex++;
//                if (_debugMoves[_debugIndex].Value != move.Value)
//                {
//                    Display::DisplayBoard(*_board);
//                    std::cout << _debugIndex << "\n";
//                    std::cout << move.ToDebugString() << "\n";
//                    std::cout << _debugMoves[_debugIndex].ToDebugString() << "\n";
//                    assert(false);
//                }
//#endif
//
//                entry.move = move;
//                entry.see = 0;
//
//                return true;
//            }
//            assert(false);
//            [[fallthrough]];
        case MovePickerStage::CaptureGen:
            InitCaptures();
            _stage = MovePickerStage::Captures;
            [[fallthrough]];
        case MovePickerStage::Captures:
            while (true)
            {
                _captureIndex++;
                if (_captureIndex >= _captureCount)
                {
                    if constexpr (allowNonCaptures)
                    {
                        _stage = MovePickerStage::Killers;
                        break;
                    }
                    else
                    {
                        return false;
                    }
                }

                const auto index = static_cast<MoveCount>(_captureIndex);
                MoveOrdering2::OrderNextCaptureMove(index, _captures, _seeScores, _captureScores, _captureCount);
                //MoveOrdering2::OrderNextCaptureMove(index, _captures, _debugSeeCopy, _debugScoresCopy, _captureCount);
                
                if constexpr (allowNonCaptures)
                {
                    const MoveScore score = _captureScores[index];
                    if(score < badCapture)
                    {
                        _hasBadCaptures = true;
                        _stage = MovePickerStage::Killers;
                        break;
                    }
                }

                const auto& move = _captures[index];

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

//#if TESTMOVEPICK
//                _debugIndex++;
//                assert(entry.move.Value == _debugMoves[_debugIndex].Value);
//#endif

#if TESTMOVEPICK
                //_debugIndex++;
                //if (entry.move.Value != _debugMoves[_debugIndex].Value)
                //{
                //    Display::DisplayBoard(*_board);
                //    std::cout << _debugIndex << "\n";
                //    std::cout << move.ToDebugString() << "\n";
                //    std::cout << _debugMoves[_debugIndex].ToDebugString() << "\n";
                //    assert(false);
                //}
#endif

                return true;
            }
            //_captureIndex--;
            [[fallthrough]];
        case MovePickerStage::Killers:
            while (true)
            {
                _killerIndex++;
                const auto& killers = _state->Plies[_ply].Killers;
                if(_killerIndex >= killers.size())
                {
                    _stage = MovePickerStage::NonCaptureGen;
                    break;
                }

                const auto& move = killers[_killerIndex];
                if (move.Value == _ttMove.Value)
                {
                    continue;
                }

                const bool isPseudoLegal = MoveValidator::IsPseudoLegal(*_board, move);
#if TESTMOVEPICK
                const bool isLegal2 = isPseudoLegal && MoveValidator::IsKingSafeAfterMove(*_board, move);
                const bool isLegalDebug = IsLegalDebug(move);
                if(isLegal2 != isLegalDebug)
                {
                    Display::DisplayBoard(*_board);
                    std::cout << move.ToDebugString() << "\n";

                    std::cout << "Killer index: " << _killerIndex << "\n";
                    std::cout << "Legal: " << isLegal2 << "\n";
                    std::cout << "Debug legal: " << isLegalDebug << "\n";
                    assert(false);
                }
#endif
                if(!isPseudoLegal)
                {
                    continue;
                }

                if (!MoveValidator::IsKingSafeAfterMove(*_board, move))
                {
                    continue;
                }

                entry.move = move;
                entry.see = 0;

                return true;
            }
            [[fallthrough]];
        case MovePickerStage::NonCaptureGen:
            InitNonCaptures();
            _stage = MovePickerStage::NonCaptures;
            [[fallthrough]];
        case MovePickerStage::NonCaptures:
            while (true)
            {
                _nonCaptureIndex++;
                if (_nonCaptureIndex >= _nonCaptureCount)
                {
                    if constexpr (allowNonCaptures)
                    {
                        if (_hasBadCaptures)
                        {
                            _stage = MovePickerStage::FirstBadCapture;
                            break;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }

                const auto index = static_cast<MoveCount>(_nonCaptureIndex);
                MoveOrdering2::OrderNextNonCaptureMove(index, _nonCaptures, _nonCaptureScores, _nonCaptureCount);
                const auto& move = _nonCaptures[index];

                if (move.Value == _ttMove.Value)
                {
                    continue;
                }

                bool isKiller = false;
                const auto& killers = _state->Plies[_ply].Killers;
                for(auto killerIndex = 0; killerIndex < killers.size(); killerIndex++)
                {
                    if(move.Value == killers[killerIndex].Value)
                    {
                        isKiller = true;
                        break;
                    }
                }
                if(isKiller)
                {
                    continue;
                }

                const bool valid = MoveValidator::IsKingSafeAfterMove2(*_board, move, _checkers, _pinned);
                if (!valid)
                {
                    continue;
                }

                entry.move = move;
                entry.see = 0;

                return true;
            }
            [[fallthrough]];
        case MovePickerStage::FirstBadCapture:
            {
                _stage = MovePickerStage::BadCaptures;
                assert(_hasBadCaptures);
                assert(_captureIndex < _captureCount);
                const auto index = static_cast<MoveCount>(_captureIndex);
                const auto& move = _captures[index];
                const bool valid = MoveValidator::IsKingSafeAfterMove2(*_board, move, _checkers, _pinned);
                if (valid)
                {
                    entry.move = move;
                    entry.see = _seeScores[index];

                    return true;
                }
            }
            [[fallthrough]];
        case MovePickerStage::BadCaptures:
            assert(_hasBadCaptures);
            while (true)
            {
                _captureIndex++;
                if (_captureIndex >= _captureCount)
                {
                    return false;
                }

                const auto index = static_cast<MoveCount>(_captureIndex);
                MoveOrdering2::OrderNextCaptureMove(index, _captures, _seeScores, _captureScores, _captureCount);
                //MoveOrdering2::OrderNextCaptureMove(index, _captures, _debugSeeCopy, _debugScoresCopy, _captureCount);
                assert(_captureScores[index] < badCapture);

                const auto& move = _captures[index];
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
            [[fallthrough]];
        default:
            assert(false);
            break;
        }

        return false;
    }
};