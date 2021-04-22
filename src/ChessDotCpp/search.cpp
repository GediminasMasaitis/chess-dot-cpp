#include "search.h"


#include "attacks.h"
#include "movegen.h"
#include "evaluation.h"
#include "stopper.h"

static void StoreTranspositionTable(SearchData& data, const ZobristKey key, const Move move, const Ply depth, const Score score, const TtFlag flag)
{
    if (data.Stopper.Stopped)
    {
        return;
    }
    
    data.Global.Table.Store(key, move, depth, score, flag);
}

static Score Contempt(const Board& board)
{
    return 0;
}

static Score AlphaBeta(Board& board, SearchData& data, Ply depth, const Ply ply, Score alpha, Score beta)
{
    //if (depth > 2 && data.Stopper.ShouldStop())
    //{
    //    const Score score = Contempt(board);
    //    return score;
    //}
    
    if(depth <= 0)
    {
        ++data.Stats.Nodes;
        
        EachColor<Bitboard> pins;
        PinDetector::GetPinnedToKings(board, pins);
        const Score eval = Evaluation::Evaluate(board, pins);
        return eval;
    }

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
        const Score childScore = -AlphaBeta(board, data, depth - 1, ply + 1, -beta, -alpha);
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
        StoreTranspositionTable(data, board.Key, bestMove, depth, bestScore, TranspositionTableFlags::Beta);
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
        StoreTranspositionTable(data, board.Key, bestMove, depth, bestScore, TranspositionTableFlags::Exact);
    }
    else
    {
        StoreTranspositionTable(data, board.Key, bestMove, depth, bestScore, TranspositionTableFlags::Alpha);
    }
    
    return alpha;
}

static Score Aspiration(Board& board, SearchData& data, const Ply depth, const Score previous)
{
    Score score = AlphaBeta(board, data, depth, 0, -Constants::Inf, Constants::Inf);
    return score;
}

static Move IterativeDeepen(Board& board, SearchData& data, const SearchCallback& callback)
{
    Score score = AlphaBeta(board, data, 1, 0, -Constants::Inf, Constants::Inf);
    data.Global.Table.SavePrincipalVariation(board);
    SearchCallbackData callbackData(board, data, 1, score);
    
    callback(callbackData);

    if (data.Stopper.ShouldStopDepthIncrease())
    {
        return data.Global.Table.SavedPrincipalVariation[0];
    }
    
    for (Ply depth = 2; depth < Constants::MaxDepth; depth++)
    {
        score = Aspiration(board, data, depth, score);
        callbackData.Depth = depth;
        callbackData._Score = score;

        if(data.Stopper.ShouldStopDepthIncrease())
        {
            break;
        }

        data.Global.Table.SavePrincipalVariation(board);
        callback(callbackData);
    }

    return data.Global.Table.SavedPrincipalVariation[0];
}

Move Search::Run(Board& board, const SearchParameters& parameters, const SearchCallback& callback)
{
    const SearchStopper stopper = SearchStopper(parameters, board.WhiteToMove);
    SearchData data = SearchData(stopper);
    data.Global.Table.SetSize(1024 * 1024 * 1024);
    const auto move = IterativeDeepen(board, data, callback);
    return move;
}
