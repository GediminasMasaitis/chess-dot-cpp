#include "movepick.h"

#include "movegen.h"
#include "see.h"
#include "searchstate.h"

void MovePicker::Reset(ThreadState& state, Ply ply, Board& board, Bitboard checkers, Bitboard pinned, Move ttMove)
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
}

void MovePicker::InitCaptures()
{
    MoveGenerator::GetAllPotentialCaptures(*_board, _checkers, _pinned, _captures, _captureCount);
    See::CalculateSeeScores(*_board, _captures, _captureCount, _seeScores);

    MoveOrdering::CalculateStaticCaptureScores(*_state, _captures, _seeScores, _captureCount, _captureScores);
}

void MovePicker::InitNonCaptures()
{
    MoveGenerator::GetAllPotentialNonCaptures(*_board, _checkers, _pinned, _nonCaptures, _nonCaptureCount);
    const Move previousMove = _ply != 0 ? _board->History[_board->History.size() - 1].MMove : Move(0);
    const Move countermove = _state->Countermoves[previousMove.GetPiece()][previousMove.GetTo()];
    MoveOrdering::CalculateStaticNonCaptureScores(*_state, _nonCaptures, _nonCaptureCount, countermove, _nonCaptureScores, *_board);
}

template <bool VAllowNonCaptures>
bool MovePicker::GetNextMove(MovePickerEntry& entry)
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
                assert(MoveValidator::IsPseudoLegal(*_board, _ttMove));
                assert(MoveValidator::IsKingSafeAfterMove(*_board, _ttMove));
                assert(MoveValidator::IsKingSafeAfterMove2(*_board, _ttMove, _pinned));
                entry.move = _ttMove;
                if (_ttMove.GetTakesPiece() != Pieces::Empty)
                {
                    entry.see = See::GetSee(*_board, _ttMove);
                }
                else
                {
                    entry.see = 0;
                }

                return true;
            }
        }
        else
        {
            if (_ttMove.Value != 0 && _ttMove.GetTakesPiece() != Pieces::Empty)
            {
                assert(MoveValidator::IsPseudoLegal(*_board, _ttMove));
                assert(MoveValidator::IsKingSafeAfterMove(*_board, _ttMove));
                assert(MoveValidator::IsKingSafeAfterMove2(*_board, _ttMove, _pinned));
                entry.move = _ttMove;
                entry.see = See::GetSee(*_board, _ttMove);
                return true;
            }
        }

        [[fallthrough]];
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
                    _stage = MovePickerStage::Killer;
                    break;
                }
                else
                {
                    return false;
                }
            }

            const auto index = static_cast<MoveCount>(_captureIndex);
            MoveOrdering::OrderNextCaptureMove(index, _captures, _seeScores, _captureScores, _captureCount);

            if constexpr (allowNonCaptures)
            {
                const MoveScore score = _captureScores[index];
                if (score < badCapture)
                {
                    _hasBadCaptures = true;
                    _stage = MovePickerStage::Killer;
                    break;
                }
            }

            const auto& move = _captures[index];

            if (move.Value == _ttMove.Value)
            {
                continue;
            }

            const bool valid = MoveValidator::IsKingSafeAfterMove2(*_board, move, _pinned);
            if (!valid)
            {
                continue;
            }

            entry.move = move;
            entry.see = _seeScores[index];

            return true;
        }
        [[fallthrough]];
    case MovePickerStage::Killer:
    {
        const auto& killer = _state->Plies[_ply].Killer;
        _stage = MovePickerStage::NonCaptureGen;

        if
        (
            killer.Value != _ttMove.Value
            && MoveValidator::IsPseudoLegal(*_board, killer)
            && MoveValidator::IsKingSafeAfterMove(*_board, killer)
        )
        {
            assert(_board->ColorToMove == killer.GetColorToMove());

            entry.move = killer;
            entry.see = 0;
            return true;
        }
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
            MoveOrdering::OrderNextNonCaptureMove(index, _nonCaptures, _nonCaptureScores, _nonCaptureCount);
            const auto& move = _nonCaptures[index];

            if (move.Value == _ttMove.Value)
            {
                continue;
            }

            
            const bool is_killer = move.Value == _state->Plies[_ply].Killer.Value;
            if (is_killer)
            {
                continue;
            }

            const bool valid = MoveValidator::IsKingSafeAfterMove2(*_board, move, _pinned);
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
        const bool valid = MoveValidator::IsKingSafeAfterMove2(*_board, move, _pinned);
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
            MoveOrdering::OrderNextCaptureMove(index, _captures, _seeScores, _captureScores, _captureCount);
            //MoveOrdering2::OrderNextCaptureMove(index, _captures, _debugSeeCopy, _debugScoresCopy, _captureCount);
            assert(_captureScores[index] < badCapture);

            const auto& move = _captures[index];
            if (move.Value == _ttMove.Value)
            {
                continue;
            }

            const bool valid = MoveValidator::IsKingSafeAfterMove2(*_board, move, _pinned);
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

template bool MovePicker::GetNextMove<true>(MovePickerEntry& entry);
template bool MovePicker::GetNextMove<false>(MovePickerEntry& entry);