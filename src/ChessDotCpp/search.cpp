#include "search.h"

#include "attacks.h"
#include "movegen.h"
#include "evaluation.h"
#include "moveorder.h"
#include "see.h"
#include "stopper.h"
#include "options.h"
#include "tablebases.h"

#include <thread>
#include <algorithm>

#include "zobrist.h"

bool Search::TryProbeTranspositionTable(const ZobristKey key, const Ply depth, const Score alpha, const Score beta, TranspositionTableEntry& entry, Score& score, bool& entryExists)
{
    score = 0;
    entryExists = false;
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

void Search::StoreTranspositionTable(const ThreadState& threadState, const ZobristKey key, const Move move, const Ply depth, const Score score, const TtFlag flag)
{
    if (threadState.StopIteration || Stopper.Stopped)
    {
        return;
    }
    
    State.Global.Table.Store(key, move, depth, score, flag);
}

Score Search::Contempt(const Board& board) const
{
    //constexpr Score midgame = -(Constants::Mate + 200);
    //constexpr Score midgame = -15;
    //
    //if (board.PieceMaterial[State.Global.ColorToMove] < Constants::EndgameMaterial)
    //{
    //    return 0;
    //}
    //
    //Score score;
    //if (board.ColorToMove == State.Global.ColorToMove)
    //{
    //    score = midgame;
    //}
    //else
    //{
    //    score = -midgame;
    //}   
    //return score;

    (void)board;
    return 0;
}

bool Search::IsRepetitionOr50Move(const Board& board) const
{
    if (board.HistoryDepth - board.FiftyMoveRuleIndex > 100)
    {
        return true;
    }

    for (HistoryPly ply = board.FiftyMoveRuleIndex; ply < board.HistoryDepth; ply++)
    {
        const auto& previousEntry = board.History[ply];
        const ZobristKey previousKey = previousEntry.Key;
        if (board.Key == previousKey)
        {
            return true;
        }
    }
    return false;
}

Score Search::Quiescence(const ThreadId threadId, Board& board, Ply depth, Ply ply, Score alpha, Score beta)
{
    ThreadState& threadState = State.Thread[threadId];
    const bool rootNode = ply == 0;
    
    ++State.Stats.Nodes;
    
    EachColor<Bitboard> pins;
    PinDetector::GetPinnedToKings(board, pins);
    const Score standPat = Evaluation::Evaluate(board, pins, State.Global.Eval);

    if (standPat >= beta)
    {
        return beta;
    }

    if (alpha < standPat)
    {
        alpha = standPat;
    }

    const Bitboard checkers = CheckDetector::GetCheckers(board);
    const bool inCheck = checkers != BitboardConstants::Empty;

    const Bitboard pinned = pins[board.ColorToMove];

    MoveArray moves;
    MoveCount moveCount = 0;
    MoveGenerator::GetAllPotentialCaptures(board, checkers, pinned, moves, moveCount);

    const Move previousMove = rootNode ? Move(0) : board.History[board.HistoryDepth - 1].Move;
    const Move countermove = threadState.Countermoves[previousMove.GetPiece()][previousMove.GetTo()];

    ScoreArray seeScores;
    See::CalculateSeeScores(board, moves, moveCount, seeScores);
    
    MoveScoreArray staticMoveScores{};
    MoveOrdering::CalculateStaticScores(threadId, State, moves, seeScores, moveCount, ply, Move(0), countermove, staticMoveScores, board);

    Score bestScore = -Constants::Inf;
    Move bestMove;
    bool raisedAlpha = false;
    bool betaCutoff = false;
    uint8_t movesEvaluated = 0;
    for (MoveCount moveIndex = 0; moveIndex < moveCount; moveIndex++)
    {
        MoveOrdering::OrderNextMove(moveIndex, moves, seeScores, staticMoveScores, moveCount);
        const Move move = moves[moveIndex];
        
        const bool valid = MoveValidator::IsKingSafeAfterMove2(board, move, checkers, pinned);
        if (!valid)
        {
            continue;
        }

        const Score takesMaterial = EvaluationConstants::PieceValues[move.GetTakesPiece()];
        const Score opponentMaterial = board.PieceMaterial[board.ColorToMove ^ 1];
        const Score resultMaterial = opponentMaterial - takesMaterial;
        
        // DELTA PRUNING
        if
        (
            !inCheck
            && standPat + takesMaterial + 200 < alpha
            && resultMaterial > Constants::EndgameMaterial
            && move.GetPawnPromoteTo() == Pieces::Empty
        )
        {
            continue;
        }

        // SEE PRUNING
        if
        (
            !inCheck
            && move.GetPawnPromoteTo() == Pieces::Empty
            &&
            (
                resultMaterial > Constants::EndgameMaterial
                || move.GetTakesPiece() == Pieces::WhitePawn
                || move.GetTakesPiece() == Pieces::BlackPawn
            )
        )
        {
            const Score seeScore = seeScores[moveIndex];
            if (seeScore < 0) // TODO: -10?
            {
                continue;
            }
        }

        board.DoMove(move);
        const Score childScore = -Quiescence(threadId, board, depth - 1, ply + 1, -beta, -alpha);
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

class SearchedPosition
{
private:
    Breadcrumb* _breadcrumb;
    bool _owned;

public:
    bool OtherThread;
    
    SearchedPosition(SearchState& state, const ThreadId threadId, const ZobristKey key, const Ply ply)
    {
        _owned = false;
        OtherThread = false;
        
        if(ply >= 6)
        {
            _breadcrumb = nullptr;
            return;
        }
        
        const size_t index = key & GlobalData::BreadcrumbMask;
        _breadcrumb = &state.Global.Breadcrumbs[index];
        const ThreadId ownedId = _breadcrumb->TThreadId.load(std::memory_order::relaxed);
        if(ownedId == -1)
        {
            _breadcrumb->TThreadId.store(threadId, std::memory_order::relaxed);
            _breadcrumb->Key.store(key, std::memory_order::relaxed);
            _owned = true;
        }
        else if(ownedId != threadId)
        {
            const ZobristKey ownedKey = _breadcrumb->Key.load(std::memory_order::relaxed);
            if(ownedKey == key)
            {
                OtherThread = true;
            }
        }
    }

    ~SearchedPosition()
    {
        if(_owned)
        {
            _breadcrumb->TThreadId.store(-1, std::memory_order::relaxed);
        }
    }
};

void UpdateHistoryEntry(MoveScore& score, const MoveScore value)
{
    const MoveScore absValue = std::abs(value);
    if (absValue > 324)
    {
        return;
    }

    score -= (score * absValue) / 324;
    score += value * 32;
}

void Search::UpdateHistory(const ThreadId threadId, Board& board, Ply depth, Ply ply, MoveArray& attemptedMoves, MoveCount attemptedMoveCount, Move bestMove, bool betaCutoff)
{
    auto& threadState = State.Thread[threadId];
    auto& plyState = threadState.Plies[ply];

    const bool isCapture = bestMove.GetTakesPiece() != Pieces::Empty;
    const Move previousMove1 = board.HistoryDepth > 0 ? board.History[board.HistoryDepth - 1].Move : Move(0);
    const Move previousMove2 = board.HistoryDepth > 1 ? board.History[board.HistoryDepth - 2].Move : Move(0);
    //const Score bonus = static_cast<Score>(depth * depth);
    const MoveScore bonus = depth * depth + depth - 1;

    if(isCapture)
    {
        UpdateHistoryEntry(threadState.CaptureHistory[bestMove.GetPiece()][bestMove.GetTo()][bestMove.GetTakesPiece()], bonus);
    }
    else
    {
        UpdateHistoryEntry(threadState.History[bestMove.GetColorToMove()][bestMove.GetFrom()][bestMove.GetTo()], bonus);
        if (previousMove1.Value != 0)
        {
            UpdateHistoryEntry(threadState.AllContinuations[previousMove1.GetPiece()][previousMove1.GetTo()].Scores[bestMove.GetPiece()][bestMove.GetTo()], bonus);
        }
        if (previousMove2.Value != 0)
        {
            UpdateHistoryEntry(threadState.AllContinuations[previousMove2.GetPiece()][previousMove2.GetTo()].Scores[bestMove.GetPiece()][bestMove.GetTo()], bonus);
        }
        UpdateHistoryEntry(threadState.History[bestMove.GetColorToMove()][bestMove.GetFrom()][bestMove.GetTo()], bonus);
        if(betaCutoff)
        {
            if (bestMove.Value != plyState.Killers[0].Value)
            {
                plyState.Killers[1] = plyState.Killers[0];
                plyState.Killers[0] = bestMove;
            }
            threadState.Countermoves[previousMove1.GetPiece()][previousMove1.GetTo()] = bestMove;
        }
    }
    

    for (MoveCount moveIndex = 0; moveIndex < attemptedMoveCount; moveIndex++)
    {
        const Move& attemptedMove = attemptedMoves[moveIndex];
        const bool attemptedCapture = attemptedMove.GetTakesPiece() != Pieces::Empty;
        if (attemptedCapture)
        {
            UpdateHistoryEntry(threadState.CaptureHistory[attemptedMove.GetPiece()][attemptedMove.GetTo()][attemptedMove.GetTakesPiece()], -bonus);
        }
        else
        {
            UpdateHistoryEntry(threadState.History[attemptedMove.GetColorToMove()][attemptedMove.GetFrom()][attemptedMove.GetTo()], -bonus);
        }
    }
}

Score Search::AlphaBeta(const ThreadId threadId, Board& board, Ply depth, const Ply ply, Score alpha, Score beta, bool isPrincipalVariation, bool isCutNode, bool nullMoveAllowed)
{
    ThreadState& threadState = State.Thread[threadId];
    PlyData& plyState = threadState.Plies[ply];
    const bool rootNode = ply == 0;
    const bool zeroWindow = alpha == beta - 1;
    
    // TIME CONTROL
    if (depth > 2 && (threadState.StopIteration || Stopper.ShouldStop()))
    {
        const Score score = Contempt(board);
        return score;
    }
    
    // REPETITION DETECTION
    if (nullMoveAllowed && !rootNode)
    {
        const bool isDraw = IsRepetitionOr50Move(board);
        if (isDraw)
        {
            const auto score = Contempt(board);
            return score;
        }
    }

    // TABLEBASES PROBE
    //if(Tablebases::CanProbe(board))
    //{
    //    if (rootNode)
    //    {
    //        Move tbMove;
    //        const auto tbWin = Tablebases::ProbeRoot(board, tbMove);
    //        if (tbWin)
    //        {
    //            StoreTranspositionTable(threadState, board.Key, tbMove, 42, Constants::TablebaseMate, TranspositionTableFlags::Exact);
    //            return Constants::TablebaseMate;
    //        }
    //    }
    //    else
    //    {
    //        auto result = Tablebases::Probe(board);
    //        switch (result)
    //        {
    //        case GameOutcome::Win:
    //            return Constants::TablebaseMate;
    //        case GameOutcome::Draw:
    //            return Contempt(board);
    //        case GameOutcome::Loss:
    //            return -Constants::TablebaseMate;
    //        case GameOutcome::Unknown:
    //            Throw();
    //            break;
    //        }
    //    }
    //}

    // MATE DISTANCE PRUNE
    const Score currentMateScore = Constants::Mate - ply;
    if (!rootNode)
    {
        if (alpha < -currentMateScore)
        {
            alpha = -currentMateScore;
        }

        if (beta > currentMateScore - 1)
        {
            beta = currentMateScore - 1;
        }

        if (alpha >= beta)
        {
            return alpha;
        }
    }
    
    // IN CHECK EXTENSION
    const Bitboard checkers = CheckDetector::GetCheckers(board);
    const bool inCheck = checkers != BitboardConstants::Empty;
    if (inCheck)
    {
        depth++;
    }

    // QUIESCENCE
    if(depth <= 0)
    {
        const Score eval = Quiescence(threadId, board, depth, ply, alpha, beta);
        return eval;
    }

    ++State.Stats.Nodes;
    const MoveScore bonus = depth * depth + depth - 1;

    // PROBE TRANSPOSITION TABLE
    TranspositionTableEntry entry;
    bool hashEntryExists = true;
    Score probedScore;
    const ZobristKey key = ZobristKeys.GetSingularKey(board.Key, threadState.SingularMove.Value);
    const bool probeSuccess = TryProbeTranspositionTable(key, depth, alpha, beta, entry, probedScore, hashEntryExists);
    bool probedMoveLegal = false;

    if(probeSuccess)
    {
        if(Options::Threads != 1)
        {
            // Doublecheck TT move legality
            auto ttMoves = MoveArray();
            EachColor<Bitboard> ttPins;
            PinDetector::GetPinnedToKings(board, ttPins);
            const Bitboard ttPinned = ttPins[board.ColorToMove];
            MoveCount ttMoveCount = 0;
            MoveGenerator::GetAllPotentialMoves(board, checkers, ttPinned, ttMoves, ttMoveCount);
            for (int ttMoveIndex = 0; ttMoveIndex < ttMoveCount; ttMoveIndex++)
            {
                auto ttMove = ttMoves[ttMoveIndex];
                if (ttMove.Value == entry.MMove.Value)
                {
                    probedMoveLegal = MoveValidator::IsKingSafeAfterMove2(board, ttMove, checkers, ttPinned);
                    break;
                }
            }
        }
        else
        {
            probedMoveLegal = true;
        }
    }

    const Move principalVariationMove = hashEntryExists ? entry.MMove : Move(0);
    if (probedMoveLegal)
    {
        bool returnTtValue = !isPrincipalVariation || (probedScore > alpha && probedScore < beta);
        if(returnTtValue /*&& isPrincipalVariation*/)
        {
            board.DoMove(principalVariationMove);
            if (IsRepetitionOr50Move(board))
            {
                returnTtValue = false;
            }
            board.UndoMove();
        }
        if (returnTtValue)
        {
            if (probedScore > Constants::MateThreshold)
            {
                probedScore -= ply;
            }
            else if (probedScore < -Constants::MateThreshold)
            {
                probedScore += ply;
            }

            if (principalVariationMove.GetTakesPiece() == Pieces::Empty)
            {
                UpdateHistoryEntry(threadState.History[principalVariationMove.GetColorToMove()][principalVariationMove.GetFrom()][principalVariationMove.GetTo()], bonus);
            }
            else
            {
                UpdateHistoryEntry(threadState.CaptureHistory[principalVariationMove.GetPiece()][principalVariationMove.GetTo()][principalVariationMove.GetTakesPiece()], bonus);
            }
            
            return probedScore;
        }
    }
    
    // STATIC EVALUATION
    EachColor<Bitboard> pins;
    PinDetector::GetPinnedToKings(board, pins);
    Score staticScore = Evaluation::Evaluate(board, pins, State.Global.Eval);
    //if (hashEntryExists && entry.Flag & (probedScore > staticScore ? TranspositionTableFlags::Beta : TranspositionTableFlags::Alpha))
    //{
    //    staticScore = probedScore;
    //}
    board.StaticEvaluation = staticScore;
    const bool improving = board.HistoryDepth < 2 || staticScore >= board.History[board.HistoryDepth - 2].StaticEvaluation;

    // STATIC EVALUATION PRUNING
    if
    (
        depth < 4
        && !isPrincipalVariation
        && !inCheck
    )
    {
        constexpr Score marginPerDepth = 64;
        //const Score marginPerDepth = Options::TuneScore1;
        Score margin = static_cast<Score>(marginPerDepth * depth);

        if(improving)
        {
            margin += marginPerDepth / 2;
        }
        
        if (staticScore - margin >= beta)
        {
            return staticScore - margin;
        }
    }

    // RAZORING
    constexpr Score razorMargin = 200;
    //const Score razorMargin = Options::Tune1;
    if
    (
        depth == 1
        && staticScore + razorMargin < beta
    )
    {
        const auto razorScore = Quiescence(threadId, board, 0, ply, alpha, beta);
        if (razorScore < beta)
        {
            return razorScore;
        }

        return beta;
    }

    // NULL MOVE PRUNING
    if
    (
        nullMoveAllowed
        && !rootNode
        && !inCheck
        && depth > 2
        && staticScore >= beta
        //&& board.PieceMaterial[board.ColorToMove] > Constants::EndgameMaterial
    )
    {
        const Ply nullDepthReduction = 3 + depth / 5 + static_cast<Ply>(std::min(3, (staticScore - beta) / 256));
        const Move nullMove = Move(0, 0, Pieces::Empty);
        board.DoMove(nullMove);
        const Score nullMoveScore = -AlphaBeta(threadId, board, depth - nullDepthReduction - 1, ply + 1, -beta, -beta + 1, false, !isCutNode, false);
        board.UndoMove();
        if (nullMoveScore >= beta)
        {
            return beta;
        }
    }

    const Bitboard pinned = pins[board.ColorToMove];
    MoveArray moves;
    MoveCount moveCount = 0;
    ScoreArray seeScores;
    MoveScoreArray staticMoveScores;
    Move previousMove1 = !rootNode ? board.History[board.HistoryDepth - 1].Move : Move(0);
    Move previousMove2 = board.HistoryDepth > 1 ? board.History[board.HistoryDepth - 2].Move : Move(0);
    const Move countermove = threadState.Countermoves[previousMove1.GetPiece()][previousMove1.GetTo()];

    // PROBCUT
    //if (
    //    !inCheck
    //    && !isPrincipalVariation
    //    && depth >= 5
    //    && abs(beta) < Constants::MateThreshold
    //    && !(
    //        hashEntryExists
    //        && entry.Flag == TranspositionTableFlags::Alpha
    //        && entry.SScore < beta)
    //    )
    //{
    //    MoveGenerator::GetAllPotentialCaptures(board, checkers, pinned, moves, moveCount);
    //    See::CalculateSeeScores(board, moves, moveCount, seeScores);
    //    MoveOrdering::CalculateStaticScores(threadId, State, moves, seeScores, moveCount, ply, principalVariationMove, countermove, staticMoveScores);
    //    Score threshold = beta + 200;

    //    for (MoveCount moveIndex = 0; moveIndex < moveCount; moveIndex++)
    //    {
    //        MoveOrdering::OrderNextMove(threadId, State, ply, moveIndex, moves, seeScores, staticMoveScores, moveCount);
    //        const Move move = moves[moveIndex];

    //        const bool valid = MoveValidator::IsKingSafeAfterMove2(board, move, checkers, pinned);
    //        if (!valid)
    //        {
    //            continue;
    //        }

    //        const Score seeScore = seeScores[moveIndex];
    //        if(seeScore < 0)
    //        {
    //            break;
    //        }

    //        board.DoMove(move);

    //        // See if a quiescence search beats pbBeta
    //        Score pbScore = -Quiescence(threadId, board, depth-1, ply+1, -threshold, -threshold + 1);

    //        // If it did, do a proper search with reduced depth
    //        if (pbScore >= threshold)
    //        {
    //            pbScore = -AlphaBeta(threadId, board, depth - 4, ply + 1, -threshold, -threshold + 1, false, false, true);
    //        }

    //        board.UndoMove();

    //        // Cut if the reduced depth search beats pbBeta
    //        if (pbScore >= threshold)
    //        {
    //            return pbScore;
    //        }
    //    }
    //}

    // FUTILITY PRUNING - DETECTION
    bool futilityPruning = false;
    //const Score futilityPerDepth = Options::TuneScore1;
    //std::array<Score, 4> futilityMargins{ 0, futilityPerDepth, futilityPerDepth * 2, futilityPerDepth };
    std::array<Score, 4> futilityMargins { 0, 200, 300, 500 };
    if
    (
        depth <= 3
        && !isPrincipalVariation
        && !inCheck
        && std::abs(alpha) < 9000
        && staticScore + futilityMargins[depth] <= alpha
        //&& board.PieceMaterial[board.ColorToMove] > 0
    )
    {
        futilityPruning = true;
    }

    //TablebaseResult parentResult = TablebaseResult::Unknown;
    //if(Tablebases::CanProbe(board))
    //{
    //    parentResult = Tablebases::Probe(board);
    //}

    // INTERNAL ITERATIVE DEEPENING
    if (depth > 3 && !hashEntryExists)
    {
        depth -= 1;
    }

    // MOVE LOOP
    assert(depth > 0);
    SearchedPosition searchedPosition = SearchedPosition(State, threadId, board.Key, ply);
    moveCount = 0;
    MoveGenerator::GetAllPotentialMoves(board, checkers, pinned, moves, moveCount);
    See::CalculateSeeScores(board, moves, moveCount, seeScores);
    MoveOrdering::CalculateStaticScores(threadId, State, moves, seeScores, moveCount, ply, principalVariationMove, countermove, staticMoveScores, board);

    Score bestScore = -Constants::Inf;
    Move bestMove;
    bool raisedAlpha = false;
    bool betaCutoff = false;
    uint8_t movesEvaluated = 0;
    uint8_t quietMovesEvaluated = 0;

    MoveArray failedMoves;
    MoveCount failedMoveCount = 0;
    
    for (MoveCount moveIndex = 0; moveIndex < moveCount; moveIndex++)
    {
        MoveOrdering::OrderNextMove(moveIndex, moves, seeScores, staticMoveScores, moveCount);
        const Move move = moves[moveIndex];
        
        //if(move.Value == threadState.SingularMove.Value)
        //{
        //    continue;
        //}

        const bool valid = MoveValidator::IsKingSafeAfterMove2(board, move, checkers, pinned);
        if (!valid)
        {
            continue;
        }

        const Piece takesPiece = move.GetTakesPiece();
        const bool capture = takesPiece != Pieces::Empty;
        const Piece pawnPromoteTo = move.GetPawnPromoteTo();
        const bool promotion = pawnPromoteTo != Pieces::Empty;
        const bool quiet = !capture && !promotion;
        const Score seeScore = seeScores[moveIndex];

        if
        (
            !rootNode
            && quiet
            && !CheckDetector::DoesGiveCheck(board, move)
        )
        {
            // LATE MOVE PRUNING
            //constexpr auto lateMovePruning = std::array<Score, 6> { 0, 5, 10, 15, 20, 25 };
            constexpr auto lateMovePruning = std::array<Score, 6> { 0, 3, 6, 10, 15, 20 };
            if
            (
                depth < 6
                && quietMovesEvaluated > lateMovePruning[depth]
            )
            {
                continue;
            }

            // FUTILITY PRUNING
            if
            (
                futilityPruning
                && movesEvaluated > 0
            )
            {
                continue;
            }
        }

        // SINGULAR EXTENSION
        Ply extension = 0;
        //if
        //(
        //    !rootNode
        //    && depth >= 6
        //    //&& nullMoveAllowed
        //    && threadState.SingularMove.Value == 0
        //    && move.Value == principalVariationMove.Value
        //    && entry.Flag == TranspositionTableFlags::Beta
        //    && entry.Depth >= depth - 3
        //    && std::abs(entry.SScore) < Constants::MateThreshold
        //)
        //{
        //    const Score singularBeta = entry.SScore - 10 * depth;
        //    const Score singularAlpha = singularBeta - 1;
        //    const Ply singularDepth = depth / 2;
        //    
        //    threadState.SingularMove = move;
        //    const Score singularScore = AlphaBeta(threadId, board, singularDepth, ply, singularAlpha, singularBeta, false, isCutNode, true);
        //    threadState.SingularMove = Move(0);

        //    if(singularScore < singularBeta)
        //    {
        //        extension++;
        //    }
        //    else if(singularBeta >= beta)
        //    {
        //        return singularBeta;
        //    }
        //    else if(entry.SScore >= beta)
        //    {
        //        threadState.SingularMove = move;
        //        const Score zeroWindowScore = AlphaBeta(threadId, board, singularDepth, ply, beta - 1, beta, false, isCutNode, true);
        //        threadState.SingularMove = Move(0);
        //    	if(zeroWindowScore >= beta)
        //    	{
        //            return beta;
        //    	}
        //    }
        //}


        // SHALLOW PRUNING
        //if (!rootNode && movesEvaluated > 0)
        //{
        //    if (movesEvaluated > (3 + 2 * depth * depth) / (2 - improving))
        //    {
        //        continue;
        //    }

        //    // Quiet late move pruning
        //    if ((move.GetTakesPiece() == Pieces::Empty) && movesEvaluated > (1 + depth * depth) / (2 - improving)) {
        //        continue;
        //    }

        //    const Ply lmrDepth = depth - SearchData.Reductions[isPrincipalVariation ? 1 : 0][depth][movesEvaluated];
        //    //if (lmrDepth < 7 && seeScore < -50 * depth)
        //    if (lmrDepth < 3 && threadState.History[move.GetColorToMove()][move.GetFrom()][move.GetTo()] < -1024 * depth)
        //    {
        //        continue;
        //    }

        //    if (lmrDepth < 7 && !See::SeeTest(board, move, -50 * depth))
        //    {
        //        continue;
        //    }
        //}

        board.DoMove(move);

        // LATE MOVE REDUCTION
        Ply reduction = 0;
        if
        (
            movesEvaluated > 1
            && (!rootNode || movesEvaluated > 3)
            //&& (!isPrincipalVariation || movesEvaluated > 3)
            && depth >= 3
            //&& !inCheck
            && move.Value != plyState.Killers[0].Value
            && move.Value != plyState.Killers[1].Value
            //&& move.Value != countermove.Value
            && seeScore <= 0
            && pawnPromoteTo == Pieces::Empty
        )
        {
            const auto pvReductionIndex = isPrincipalVariation ? 1 : 0;
            const auto captureReductionIndex = takesPiece == Pieces::Empty ? 0 : 1;
            reduction = SearchData.Reductions[pvReductionIndex][captureReductionIndex][depth][movesEvaluated];

            if (!isPrincipalVariation && !improving && reduction > 1)
            {
                reduction++;
            }

            //if
            //(
            //    reduction > 0
            //    &&
            //    (
            //        move.Value == plyState.Killers[0].Value
            //        || move.Value == plyState.Killers[1].Value
            //    )
            //)
            //{
            //    reduction--;
            //}

            //if
            //(
            //    !isPrincipalVariation
            //    && threadState.IterationInitialDepth > 6
            //    && threadState.BestMoveChanges <= 2
            //)
            //{
            //    reduction++;
            //}

            MoveScore moveScore = capture
                ? threadState.CaptureHistory[move.GetPiece()][move.GetTo()][takesPiece]
                : threadState.History[move.GetColorToMove()][move.GetFrom()][move.GetTo()]
                  + threadState.AllContinuations[previousMove1.GetPiece()][previousMove1.GetTo()].Scores[move.GetPiece()][move.GetTo()]
                  + threadState.AllContinuations[previousMove2.GetPiece()][previousMove2.GetTo()].Scores[move.GetPiece()][move.GetTo()];
            if
            (
                reduction > 0
                && moveScore > 0
            )
            {
                reduction--;
            }

            if (moveScore < 0)
            {
                //reduction -= moveScore / 4000;
                reduction++;
                //if(moveScore < 5000)
                //{
                //    reduction++;
                //}
            }

            //if
            //(
            //    isCutNode
            //    && move.GetTakesPiece() == Pieces::Empty
            //)
            //{
            //    reduction += 2;
            //}

            if
            (
                !isPrincipalVariation
                && threadState.History[move.GetColorToMove()][move.GetFrom()][move.GetTo()] < 0
            )
            {
                reduction++;
            }

            if (searchedPosition.OtherThread)
            {
                reduction++;
            }
        }

        const bool isReduced = reduction > 0;
        const bool childCut = isReduced || !isCutNode;
        Score childScore;

        if (movesEvaluated > 0)
        {
            childScore = -AlphaBeta(threadId, board, depth + extension - reduction - 1, ply + 1, -alpha - 1, -alpha, false, childCut, true);
            if (!zeroWindow && childScore > alpha)
            {
                childScore = -AlphaBeta(threadId, board, depth + extension - reduction - 1, ply + 1, -beta, -alpha, isPrincipalVariation, childCut, true);
            }
            if (reduction > 0 && childScore > alpha)
            {
                childScore = -AlphaBeta(threadId, board, depth + extension - 1, ply + 1, -beta, -alpha, isPrincipalVariation, childCut, true);
            }
        }
        else
        {
            childScore = -AlphaBeta(threadId, board, depth + extension - reduction - 1, ply + 1, -beta, -alpha, isPrincipalVariation, childCut, true);
            if (reduction > 0 && childScore > alpha)
            {
                childScore = -AlphaBeta(threadId, board, depth + extension - 1, ply + 1, -beta, -alpha, isPrincipalVariation, false, true);
            }
        }
        
        board.UndoMove();
        movesEvaluated++;
        if(quiet)
        {
            quietMovesEvaluated++;
        }
        
        if (childScore > bestScore)
        {
            bestScore = childScore;
            bestMove = move;

            if (childScore > alpha)
            {
                alpha = childScore;
                raisedAlpha = true;

                if (rootNode)
                {
                    threadState.BestMoveChanges++;
                }

                if (childScore >= beta)
                {
                    betaCutoff = true;
                    break;
                }
            }
        }
        //else
        {
            failedMoves[failedMoveCount++] = move;
        }
    }

    if (raisedAlpha)
    {
        UpdateHistory(threadId, board, depth, ply, failedMoves, failedMoveCount, bestMove, betaCutoff);
        if(betaCutoff)
        {
            StoreTranspositionTable(threadState, key, bestMove, depth, bestScore, TranspositionTableFlags::Beta);
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

    //if (threadState.SingularMove.Value == 0)
    {
        if (raisedAlpha)
        {
            StoreTranspositionTable(threadState, key, bestMove, depth, bestScore, TranspositionTableFlags::Exact);
        }
        else
        {
            StoreTranspositionTable(threadState, key, bestMove, depth, bestScore, TranspositionTableFlags::Alpha);
        }
    }
    
    return alpha;
}

Score Search::Aspiration(const ThreadId threadId, Board& board, const Ply depth, const Score previous)
{
    if(depth < 5)
    {
        State.Thread[threadId].BestMoveChanges = 0;
        const Score fullSearchScore = AlphaBeta(threadId, board, depth, 0, -Constants::Inf, Constants::Inf, true, false, true);
        return fullSearchScore;
    }

    constexpr Score window = 20;
    constexpr Score termination = 5000;
    Score widen = 20;
    Score alpha = previous - window;
    Score beta = previous + window;
    while (true)
    {
        if (alpha < -termination)
        {
            alpha = -Constants::Inf;
        }
        if (beta > termination)
        {
            beta = Constants::Inf;
        }

        State.Thread[threadId].BestMoveChanges = 0;
        const Score score = AlphaBeta(threadId, board, depth, 0, alpha, beta, true, false, true);
        widen *= 2;

        if (score <= alpha)
        {
            alpha = static_cast<Score>(std::max(alpha - widen, -Constants::Inf));
            beta = (alpha + 3 * beta) / 4; // Trick to circumvent search instability issues
        }
        else if (score >= beta)
        {
            beta = std::min(static_cast<Score>(beta + widen), Constants::Inf);
        }
        else
        {
            return score;
        }
    }
}

void Search::GetSearchResults(SearchResults& results, Ply depth, Score score)
{
    results.BestMove = State.Thread[0].SavedPrincipalVariation[0];
    results.SearchedDepth = depth;
    results.SScore = score;
}

void Search::IterativeDeepen(const ThreadId threadId, Board& board, SearchResults& results)
{
    ThreadState& threadState = State.Thread[threadId];
    Ply depth = 1;
    threadState.IterationInitialDepth = depth;
    Score score = AlphaBeta(threadId, board, depth, 0, -Constants::Inf, Constants::Inf, true, false, true);

    threadState.SavedPrincipalVariation.clear();
    State.Global.Table.GetPrincipalVariation(board, threadState.SavedPrincipalVariation);
    State.Stats.Elapsed = Stopper.GetElapsed();
    SearchCallbackData callbackData(threadId, board, State, 1, score);

    if (threadId == 0)
    {
        Callback(callbackData);
    }

    if (Stopper.ShouldStopDepthIncrease(threadId, State))
    {
        GetSearchResults(results, depth, score);
        return;
    }
    
    for (depth = depth + 1; depth < State.Global.Parameters.MaxDepth; depth++)
    {
        threadState.IterationInitialDepth = depth;
        score = Aspiration(threadId, board, depth, score);
        callbackData.Depth = depth;
        callbackData._Score = score;
        const bool pvMoveChanged = State.Global.Table.IsRootMoveChanged(board, threadState.SavedPrincipalVariation);
        if(pvMoveChanged)
        {
            threadState.IterationsSincePvChange = 0;
        }
        else
        {
            threadState.IterationsSincePvChange++;
        }
        State.Stats.Elapsed = Stopper.GetElapsed();
        if(Stopper.ShouldStopDepthIncrease(threadId, State))
        {
            break;
        }

        threadState.SavedPrincipalVariation.clear();
        State.Global.Table.GetPrincipalVariation(board, threadState.SavedPrincipalVariation);
        if (threadId == 0)
        {
            Callback(callbackData);
        }
    }
    
    GetSearchResults(results, depth, score);
}

void Search::IterativeDeepenLazySmp(Board& board, SearchResults& results)
{
    auto threads = std::vector<std::thread>();
    for (ThreadId helperId = 1; helperId < Options::Threads; helperId++)
    {
        State.Thread[helperId] = State.Thread[0];
        threads.emplace_back([this, helperId, board]()
        //State.Pool->push_task([this, helperId, board, &results]()
        {
            Board clone = board;
            SearchResults fakeResults;
            IterativeDeepen(helperId, clone, fakeResults);
        });
    }

    IterativeDeepen(0, board, results);

    for (ThreadId helperId = 1; helperId < Options::Threads; helperId++)
    {
        State.Thread[helperId].StopIteration = true;
    }

    //if(Options::Threads > 1)
    //{
    //    State.Pool->wait_for_tasks();
    //}

    for (ThreadId helperId = 1; helperId < Options::Threads; helperId++)
    {
        threads[helperId - 1].join();
    }
}

void Search::IterativeDeepenLazySmpOld(Board& board, SearchResults& results)
{
    ThreadState& mainThreadState = State.Thread[0];
    Ply depth = 1;
    mainThreadState.IterationInitialDepth = depth;
    Score score = AlphaBeta(0, board, 1, 0, -Constants::Inf, Constants::Inf, true, false, true);

    mainThreadState.SavedPrincipalVariation.clear();
    State.Global.Table.GetPrincipalVariation(board, mainThreadState.SavedPrincipalVariation);
    
    State.Stats.Elapsed = Stopper.GetElapsed();
    SearchCallbackData callbackData(0, board, State, 1, score);
    Callback(callbackData);
    //State.Global.Table.PrintOccupancy();

    if (Stopper.ShouldStopDepthIncrease(0, State))
    {
        GetSearchResults(results, depth, score);
        return;
    }

    for (depth = depth + 1; depth < State.Global.Parameters.MaxDepth; depth++)
    {
        State.Thread[0].IterationInitialDepth = depth;
        auto threads = std::vector<std::thread>();
        for(ThreadId helperId = 1; helperId < Options::Threads; helperId++)
        {
            State.Thread[helperId] = State.Thread[0];
            threads.emplace_back([this, helperId, board, depth, score]()
            {
                Board clone = board;
                const Ply helperDepth = depth + helperId / 2;
                State.Thread[helperId].IterationInitialDepth = helperDepth;
                Aspiration(helperId, clone, helperDepth, score);
            });
        }
        
        score = Aspiration(0, board, depth, score);

        for (ThreadId helperId = 1; helperId < Options::Threads; helperId++)
        {
            State.Thread[helperId].StopIteration = true;
        }

        for (ThreadId helperId = 1; helperId < Options::Threads; helperId++)
        {
            threads[helperId-1].join();
        }
        
        callbackData.Depth = depth;
        callbackData._Score = score;
        const bool pvMoveChanged = State.Global.Table.IsRootMoveChanged(board, mainThreadState.SavedPrincipalVariation);
        if (pvMoveChanged)
        {
            mainThreadState.IterationsSincePvChange = 0;
        }
        else
        {
            mainThreadState.IterationsSincePvChange++;
        }
        State.Stats.Elapsed = Stopper.GetElapsed();
        if (Stopper.ShouldStopDepthIncrease(0, State))
        {
            break;
        }

        mainThreadState.SavedPrincipalVariation.clear();
        State.Global.Table.GetPrincipalVariation(board, mainThreadState.SavedPrincipalVariation);
        Callback(callbackData);
        //State.Global.Table.PrintOccupancy();
    }
    GetSearchResults(results, depth, score);
}

void Search::Run(Board& board, const SearchParameters& parameters, SearchResults& results)
{
    if(!State.Initialized)
    {
        State.NewGame();
    }
    //std::cout << board.Key << std::endl;
    Stopper.Init(parameters, board.WhiteToMove);
    State.NewSearch(board, parameters);
    IterativeDeepenLazySmp(board, results);
    //IterativeDeepen(0, board, results);
}
