#include "search.h"


#include "attacks.h"
#include "movegen.h"
#include "evaluation.h"
#include "moveorder.h"
#include "stopper.h"

//bool Search::TryProbeTranspositionTable(const ZobristKey key, const Ply depth, const Score alpha, const Score beta, Move& bestMove, Score& score, bool& entryExists)
//{
//    score = 0;
//    entryExists = false;
//    TranspositionTableEntry entry;
//    ZobristKey entryKey;
//    
//    const bool found = State.Global.Table.TryProbe(key, &entry, &entryKey);
//    if (!found)
//    {
//        State.Stats.HashMiss++;
//        return false;
//    }
//
//    if (entryKey != key)
//    {
//        State.Stats.HashCollision++;
//        return false;
//    }
//
//    entryExists = true;
//    bestMove = entry.MMove;
//
//    if (entry.GetDepth() < depth)
//    {
//        State.Stats.HashInsufficientDepth++;
//        return false;
//    }
//
//    switch (entry.GetFlag())
//    {
//    case TranspositionTableFlags::Exact:
//        score = entry.GetScore();
//        return true;
//        
//    case TranspositionTableFlags::Alpha:
//        if (entry.GetScore() <= alpha)
//        {
//            score = alpha;
//            return true;
//        }
//        return false;
//        
//    case TranspositionTableFlags::Beta:
//        if (entry.GetScore() >= beta)
//        {
//            score = beta;
//            return true;
//        }
//        return false;
//        
//    default:
//        assert(false);
//        break;
//    }
//
//    return false;
//}

bool Search::TryProbeTranspositionTable(const ZobristKey key, const Ply depth, const Score alpha, const Score beta, Move& bestMove, Score& score, bool& entryExists)
{
    score = 0;
    entryExists = false;
    TranspositionTableEntry entry;
    ZobristKey entryKey;

    const bool found = State.Global.Table.TryProbe(key, &entry, &entryKey);
    if (!found)
    {
        State.Stats.HashMiss++;
        return false;
    }

    if (entryKey != key)
    {
        State.Stats.HashCollision++;
        return false;
    }

    entryExists = true;
    bestMove = entry.MMove;

    if (entry.Depth < depth)
    {
        State.Stats.HashInsufficientDepth++;
        return false;
    }

    switch (entry.Flag)
    {
    case TranspositionTableFlags::Exact:
        score = entry.SScore;
        return true;

    case TranspositionTableFlags::Alpha:
        if (entry.SScore <= alpha)
        {
            score = alpha;
            return true;
        }
        return false;

    case TranspositionTableFlags::Beta:
        if (entry.SScore >= beta)
        {
            score = beta;
            return true;
        }
        return false;

    default:
        assert(false);
        break;
    }

    return false;
}

void Search::StoreTranspositionTable(const ZobristKey key, const Move move, const Ply depth, const Score score, const TtFlag flag)
{
    if (State.Stopper.Stopped)
    {
        return;
    }
    
    State.Global.Table.Store(key, move, depth, score, flag);
}

Score Search::Contempt(const Board& board)
{
    return 0;
}

Score Search::Quiescence(Board& board, Ply depth, Ply ply, Score alpha, Score beta)
{
    ++State.Stats.Nodes;
    
    EachColor<Bitboard> pins;
    PinDetector::GetPinnedToKings(board, pins);
    const Score standPat = Evaluation::Evaluate(board, pins);

    if (standPat >= beta)
    {
        return beta;
    }

    if (alpha < standPat)
    {
        alpha = standPat;
    }

    const Bitboard checkers = AttacksGenerator::GetCheckers(board);
    const bool inCheck = checkers != BitboardConstants::Empty;
    const Score currentMateScore = Constants::Mate - ply;

    const Bitboard pinned = pins[board.ColorToMove];

    MoveArray moves;
    MoveCount moveCount = 0;
    MoveGenerator::GetAllPotentialCaptures(board, checkers, pinned, moves, moveCount);

    MoveScoreArray staticMoveScores{};
    MoveOrdering::CalculateStaticScores(State, moves, moveCount, ply, Move(0), staticMoveScores);

    Score bestScore = -Constants::Inf;
    Move bestMove;
    bool raisedAlpha = false;
    bool betaCutoff = false;
    uint8_t movesEvaluated = 0;
    for (MoveCount moveIndex = 0; moveIndex < moveCount; moveIndex++)
    {
        MoveOrdering::OrderNextMove(State, moveIndex, moves, staticMoveScores, moveCount);
        const Move move = moves[moveIndex];
    	
        const bool valid = MoveValidator::IsKingSafeAfterMove2(board, move, checkers, pinned);
        if (!valid)
        {
            continue;
        }

        board.DoMove(move);
        const Score childScore = -Quiescence(board, depth - 1, ply + 1, -beta, -alpha);
        board.UndoMove();
        movesEvaluated++;

        if (childScore > bestScore)
        {
            bestScore = childScore;
            bestMove = move;

            if (childScore > alpha)
            {
                alpha = childScore;
                raisedAlpha = true;

                if (childScore >= beta)
                {
                    betaCutoff = true;
                    break;
                }
            }
        }
    }

    if (betaCutoff)
    {
        return beta;
    }

    return alpha;
}

Score Search::AlphaBeta(Board& board, Ply depth, const Ply ply, Score alpha, Score beta, bool nullMoveAllowed)
{
    constexpr int threadId = 0;
    
    if (depth > 2 && State.Stopper.ShouldStop())
    {
        const Score score = Contempt(board);
        return score;
    }

    // IN CHECK EXTENSION
    const Bitboard checkers = AttacksGenerator::GetCheckers(board);
    const bool inCheck = checkers != BitboardConstants::Empty;
    if (inCheck)
    {
        depth++;
    }
    
    if(depth <= 0)
    {
        //EachColor<Bitboard> pins;
        //PinDetector::GetPinnedToKings(board, pins);
        //const Score eval = Evaluation::Evaluate(board, pins);
        const Score eval = Quiescence(board, depth, ply, alpha, beta);
        return eval;
    }

    ++State.Stats.Nodes;
    MoveScore bonus = depth * depth + depth - 1;

    // PROBE TRANSPOSITION TABLE
    Move principalVariationMove = Move(0);
    bool hashEntryExists = true;
    Score probedScore;
    constexpr bool isPrincipalVariation = true;
    const bool probeSuccess = TryProbeTranspositionTable(board.Key, depth, alpha, beta, principalVariationMove, probedScore, hashEntryExists);
    if (probeSuccess)
    {
        if (!isPrincipalVariation || (probedScore > alpha && probedScore < beta))
        {
            if (probedScore > Constants::MateThreshold)
            {
                probedScore -= ply;
            }
            else if (probedScore < -Constants::MateThreshold)
            {
                probedScore += ply;
            }

            return probedScore;
        }
    }
    
    const Score currentMateScore = Constants::Mate - ply;

    // NULL MOVE PRUNING
    if
    (
        nullMoveAllowed
        && !inCheck
        && depth > 2
        && ply > 0
    )
    {
        const Score material = board.PieceMaterial[board.ColorToMove];
        if (material > Constants::EndgameMaterial)
        {
            const Ply nullDepthReduction = depth > 6 ? 3 : 2;
            const Move nullMove = Move(0, 0, Pieces::Empty);
            board.DoMove(nullMove);
            const Score nullMoveScore = -AlphaBeta(board, depth - nullDepthReduction - 1, ply + 1, -beta, -beta + 1, false);
            board.UndoMove();
            if (nullMoveScore >= beta)
            {
                return beta;
            }
        }
    }
    
    EachColor<Bitboard> pins;
    PinDetector::GetPinnedToKings(board, pins);
    const Bitboard pinned = pins[board.ColorToMove];
    
    MoveArray moves;
    MoveCount moveCount = 0;
    MoveGenerator::GetAllPotentialMoves(board, checkers, pinned, moves, moveCount);

    MoveScoreArray staticMoveScores{};
    MoveOrdering::CalculateStaticScores(State, moves, moveCount, ply, principalVariationMove, staticMoveScores);

    Score bestScore = -Constants::Inf;
    Move bestMove;
    bool raisedAlpha = false;
    bool betaCutoff = false;
    uint8_t movesEvaluated = 0;

    MoveArray failedMoves;
    MoveCount failedMoveCount = 0;
    for (MoveCount moveIndex = 0; moveIndex < moveCount; moveIndex++)
    {
        MoveOrdering::OrderNextMove(State, moveIndex, moves, staticMoveScores, moveCount);
        const Move move = moves[moveIndex];
        
        const bool valid = MoveValidator::IsKingSafeAfterMove2(board, move, checkers, pinned);
        if(!valid)
        {
            continue;
        }

        board.DoMove(move);
        const Score childScore = -AlphaBeta(board, depth - 1, ply + 1, -beta, -alpha, true);
        board.UndoMove();
        movesEvaluated++;
        
        if(childScore > bestScore)
        {
            bestScore = childScore;
            bestMove = move;

            if(childScore > alpha)
            {
                alpha = childScore;
                raisedAlpha = true;

                if(childScore >= beta)
                {
                    betaCutoff = true;
                    break;
                }
            }
        }
        else
        {
            failedMoves[failedMoveCount++] = move;
        }
    }

    if (raisedAlpha)
    {
    	if(bestMove.GetTakesPiece() == Pieces::Empty)
    	{
            State.Thread[threadId].History[bestMove.GetColorToMove()][bestMove.GetFrom()][bestMove.GetTo()] += bonus;
    	}
        if (betaCutoff)
        {
            if (bestMove.GetTakesPiece() == Pieces::Empty)
            {
                PlyData& plyState = State.Thread[threadId].Plies[ply];
                plyState.Killers[1] = plyState.Killers[0];
                plyState.Killers[0] = bestMove;
            }

            StoreTranspositionTable(board.Key, bestMove, depth, bestScore, TranspositionTableFlags::Beta);
            return beta;
        }
    }

    // MATE / STALEMATE
    if(movesEvaluated == 0)
    {
        if(inCheck)
        {
            return -currentMateScore;
        }
        return Contempt(board);
    }

    if(raisedAlpha)
    {
        StoreTranspositionTable(board.Key, bestMove, depth, bestScore, TranspositionTableFlags::Exact);
    }
    else
    {
        StoreTranspositionTable(board.Key, bestMove, depth, bestScore, TranspositionTableFlags::Alpha);
    }
    
    return alpha;
}

Score Search::Aspiration(Board& board, const Ply depth, const Score previous)
{
    Score score = AlphaBeta(board, depth, 0, -Constants::Inf, Constants::Inf, true);
    return score;
}

Move Search::IterativeDeepen(Board& board)
{
    Score score = AlphaBeta(board, 1, 0, -Constants::Inf, Constants::Inf, true);
    State.Global.Table.SavePrincipalVariation(board);
    SearchCallbackData callbackData(board, State, 1, score);
    
    Callback(callbackData);

    if (State.Stopper.ShouldStopDepthIncrease())
    {
        return State.Global.Table.SavedPrincipalVariation[0];
    }
    
    for (Ply depth = 2; depth < Constants::MaxDepth; depth++)
    {
        score = Aspiration(board, depth, score);
        callbackData.Depth = depth;
        callbackData._Score = score;

        if(State.Stopper.ShouldStopDepthIncrease())
        {
            break;
        }

        State.Global.Table.SavePrincipalVariation(board);
        Callback(callbackData);
    }

    return State.Global.Table.SavedPrincipalVariation[0];
}

Move Search::Run(Board& board, const SearchParameters& parameters)
{
    State.Stopper.Init(parameters, board.WhiteToMove);
    const auto move = IterativeDeepen(board);
    return move;
}
