#include "search.h"


#include "attacks.h"
#include "movegen.h"
#include "evaluation.h"
#include "stopper.h"

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

    Score bestScore = -Constants::Inf;
    Move bestMove;
    bool raisedAlpha = false;
    bool betaCutoff = false;
    uint8_t movesEvaluated = 0;
    for (MoveCount i = 0; i < moveCount; i++)
    {
        const Move move = moves[i];
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

Score Search::AlphaBeta(Board& board, Ply depth, const Ply ply, Score alpha, Score beta)
{
    if (depth > 2 && State.Stopper.ShouldStop())
    {
        const Score score = Contempt(board);
        return score;
    }
    
    if(depth <= 0)
    {
        
        EachColor<Bitboard> pins;
        PinDetector::GetPinnedToKings(board, pins);
        //const Score eval = Evaluation::Evaluate(board, pins);
        const Score eval = Quiescence(board, depth, ply, alpha, beta);
        return eval;
    }

    ++State.Stats.Nodes;

    const Bitboard checkers = AttacksGenerator::GetCheckers(board);
    const bool inCheck = checkers != BitboardConstants::Empty;
    const Score currentMateScore = Constants::Mate - ply;
    
    EachColor<Bitboard> pins;
    PinDetector::GetPinnedToKings(board, pins);
    const Bitboard pinned = pins[board.ColorToMove];

    
    MoveArray moves;
    MoveCount moveCount = 0;
    MoveGenerator::GetAllPotentialMoves(board, checkers, pinned, moves, moveCount);

    Score bestScore = -Constants::Inf;
    Move bestMove;
    bool raisedAlpha = false;
    bool betaCutoff = false;
    uint8_t movesEvaluated = 0;
    for (MoveCount i = 0; i < moveCount; i++)
    {
        const Move move = moves[i];
        const bool valid = MoveValidator::IsKingSafeAfterMove2(board, move, checkers, pinned);
        if(!valid)
        {
            continue;
        }

        board.DoMove(move);
        const Score childScore = -AlphaBeta(board, depth - 1, ply + 1, -beta, -alpha);
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
    }

    
    if (betaCutoff)
    {
        StoreTranspositionTable(board.Key, bestMove, depth, bestScore, TranspositionTableFlags::Beta);
        return beta;
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
    Score score = AlphaBeta(board, depth, 0, -Constants::Inf, Constants::Inf);
    return score;
}

Move Search::IterativeDeepen(Board& board)
{
    Score score = AlphaBeta(board, 1, 0, -Constants::Inf, Constants::Inf);
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
