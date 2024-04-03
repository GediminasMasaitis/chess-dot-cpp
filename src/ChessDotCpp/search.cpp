#include "search.h"

#include "attacks.h"
#include "movegen.h"
#include "evalbase.h"
#include "evaluation.h"
#include "moveorder.h"
#include "movepick.h"
#include "see.h"
#include "stopper.h"
#include "options.h"
#include "tablebases.h"

#include <thread>
#include <algorithm>

#include "zobrist.h"

#if DATAGEN
static constexpr bool datagen = true;
#else
static constexpr bool datagen = false;
#endif

bool Search::TryProbeTranspositionTable(const ZobristKey key, const Ply depth, const Ply ply, const Score alpha, const Score beta/*, const Move singularMove*/, TranspositionTableEntry& entry, Score& score, bool& entryExists)
{
    score = 0;
    entryExists = false;
    ZobristKey entryKey;

    const bool found = State.Global.Table.TryProbe(key, &entry, &entryKey);
    if (!found)
    {
        //State.Stats.HashMiss++;
        return false;
    }

    if (entryKey != key)
    {
        //State.Stats.HashCollision++;
        return false;
    }

    //if(entry.MMove.Value == singularMove.Value)
    //{
    //    return false;
    //}

    entryExists = true;
    score = entry.SScore;
    if (entry.SScore > Constants::MateThreshold)
    {
        score -= ply;
    }
    else if (entry.SScore < -Constants::MateThreshold)
    {
        score += ply;
    }

    if (entry.Depth < depth)
    {
        //State.Stats.HashInsufficientDepth++;
        return false;
    }

    switch (entry.Flag)
    {
    case TranspositionTableFlags::Exact:
        return true;

    case TranspositionTableFlags::Alpha:
        if (score <= alpha)
        {
            score = alpha;
            return true;
        }
        return false;

    case TranspositionTableFlags::Beta:
        if (score >= beta)
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

void Search::StoreTranspositionTable(const ThreadState& threadState, const ZobristKey key, const Move move, const Ply depth, const Ply ply, const Score score, const TtFlag flag)
{
    //assert((std::abs(score) > Constants::MateThreshold) || move.Value != 0);

    if (threadState.Stopper.Stopped)
    {
        return;
    }

    //const PlyData& plyState = threadState.Plies[ply];
    //if(plyState.SingularMove.Value != 0)
    //    return;
    //}

    Score adjustedScore = score;
    if(score > Constants::MateThreshold)
    {
        adjustedScore = static_cast<Score>(score + ply);
    }
    else if(score < -Constants::MateThreshold)
    {
        adjustedScore = static_cast<Score>(score - ply);
    }

    State.Global.Table.Store(key, move, depth, adjustedScore, flag);
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
    if (board.History.size() - board.FiftyMoveRuleIndex > 100)
    {
        return true;
    }

    for (HistoryPly ply = board.FiftyMoveRuleIndex; ply < board.History.size(); ply++)
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

bool Search::IsRepetitionOr50MoveAfterMove(const Board& board, const Move move) const
{
    if(move.Value == 0)
    {
        return false;
    }

    KeyAnd50Move keyAnd50Move;
    board.GetKeyAfterMove(move, keyAnd50Move);
    if (board.History.size() + 1 - keyAnd50Move.FiftyMoveRuleIndex > 100)
    {
        return true;
    }

    // < or <= ??? <= gains for some reason but it should be wrong
    for (HistoryPly ply = keyAnd50Move.FiftyMoveRuleIndex; ply < board.History.size(); ply++)
    {
        const auto& previousEntry = board.History[ply];
        const ZobristKey previousKey = previousEntry.Key;
        if (keyAnd50Move.Key == previousKey)
        {
            return true;
        }
    }
    return false;
}

Score Search::Quiescence(ThreadState& threadState, Board& board, Ply depth, const Ply ply, Score alpha, Score beta, const bool isPrincipalVariation)
{
    ++threadState.Stats.Nodes;
    if(ply > threadState.SelectiveDepth)
    {
        threadState.SelectiveDepth = ply;
    }

    TranspositionTableEntry entry;
    bool hashEntryExists = true;
    Score probedScore;
    //const ZobristKey key = ZobristKeys.GetSingularKey(board.Key, plyState.SingularMove.Value);
    const ZobristKey key = board.Key;
    bool probeSuccess = TryProbeTranspositionTable(key, 0, ply, alpha, beta/*, plyState.SingularMove*/, entry, probedScore, hashEntryExists);
    //probeSuccess = false;
    //hashEntryExists = false;
    if (hashEntryExists && Options::Threads != 1)
    {
        const bool isPseudoLegal = MoveValidator::IsPseudoLegal(board, entry.MMove);
        if (!isPseudoLegal)
        {
            hashEntryExists = false;
            probeSuccess = false;
        }
        else
        {
            const bool isLegal = MoveValidator::IsKingSafeAfterMove(board, entry.MMove);
            if (!isLegal)
            {
                hashEntryExists = false;
                probeSuccess = false;
            }
        }
    }

    const Move principalVariationMove = hashEntryExists ? entry.MMove : Move(0);
    if (probeSuccess && !isPrincipalVariation)
    {
        return probedScore;
    }

#if EVALPINS
    EachColor<Bitboard> pins;
    PinDetector::GetPinnedToKings(board, pins);
    const Bitboard pinned = pins[board.ColorToMove];
#endif

    Score standPat = CallEval(board, pins);

    if
    (
        hashEntryExists
        //&& std::abs(probedScore) < Constants::MateThreshold
        && (
            (entry.Flag == TranspositionTableFlags::Exact)
            || (entry.Flag == TranspositionTableFlags::Beta && standPat < probedScore)
            || (entry.Flag == TranspositionTableFlags::Alpha && standPat > probedScore)
        )
    )
    {
        standPat = probedScore;
    }

    if (standPat >= beta || ply >= Constants::MaxPly)
    {
        return beta;
    }

    if (alpha < standPat)
    {
        alpha = standPat;
    }

    const Bitboard checkers = CheckDetector::GetCheckers(board);
    const bool inCheck = checkers != BitboardConstants::Empty;

#if !EVALPINS
    const Bitboard pinned = PinDetector::GetPinnedToKingForColorToMove(board);
#endif

    PlyData& plyState = threadState.Plies[ply];
    auto& movePicker = plyState.MMovePicker;
    movePicker.Reset(threadState, ply, board, checkers, pinned, principalVariationMove);

    Score bestScore = -Constants::Inf;
    Move bestMove;
    bool raisedAlpha = false;
    bool betaCutoff = false;
    uint8_t movesEvaluated = 0;
    MovePickerEntry moveEntry;
    while (true)
    {
        auto nextMoveExists = movePicker.GetNextMove<false>(moveEntry);
        if(!nextMoveExists)
        {
            break;
        }
        const Move move = moveEntry.move;
        State.Global.Table.PrefetchForMove(board, move);

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
        if(moveEntry.see < 0)
        {
            continue;
        }

        board.DoMove(move);
        const Score childScore = -Quiescence(threadState, board, depth - 1, ply + 1, -beta, -alpha, isPrincipalVariation);
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

    if (movesEvaluated > 0)
    {
        if (raisedAlpha)
        {
            if (betaCutoff)
            {
                StoreTranspositionTable(threadState, key, bestMove, 0, ply, bestScore, TranspositionTableFlags::Beta);
            }
            else
            {
                StoreTranspositionTable(threadState, key, bestMove, 0, ply, bestScore, TranspositionTableFlags::Exact);
            }
        }
        else
        {
            StoreTranspositionTable(threadState, key, bestMove, 0, ply, bestScore, TranspositionTableFlags::Alpha);
        }
    }

    if (betaCutoff)
    {
        return beta;
    }

    return alpha;
}

void UpdateHistoryEntry(MoveScore& score, const MoveScore value)
{
    const MoveScore absValue = std::abs(value);
    score -= (score * absValue) / 256;
    score += value * 32;
}

void Search::UpdateHistory(ThreadState& threadState, Board& board, Ply depth, Ply ply, MoveArray& attemptedMoves, MoveCount attemptedMoveCount, Move bestMove, bool betaCutoff)
{
    if(bestMove.Value == 0)
    {
        return;
    }

    assert(board.ColorToMove == bestMove.GetColorToMove());
    assert(threadState.ColorToMove == (board.ColorToMove ^ (ply % 2)));
    auto& plyState = threadState.Plies[ply];

    const bool isCapture = bestMove.GetTakesPiece() != Pieces::Empty;

    const bool hasPreviousMove1 = board.History.size() > 0;
    const bool hasPreviousMove2 = board.History.size() > 1;
    const Move previousMove1 = hasPreviousMove1 ? board.History[board.History.size() - 1].MMove : Move(0);
    const Move previousMove2 = hasPreviousMove2 ? board.History[board.History.size() - 2].MMove : Move(0);

    //const Score bonus = static_cast<Score>(depth * depth);
    const MoveScore bonus = depth * depth + depth - 1;

    if(isCapture)
    {
        UpdateHistoryEntry(threadState.CaptureHistory[bestMove.GetPiece()][bestMove.GetTo()][bestMove.GetTakesPiece()], bonus);
    }
    else
    {
        UpdateHistoryEntry(threadState.History[bestMove.GetColorToMove()][bestMove.GetFrom()][bestMove.GetTo()], bonus);
        if (hasPreviousMove1)
        {
            UpdateHistoryEntry(threadState.AllContinuations[previousMove1.GetPiece()][previousMove1.GetTo()].Scores[bestMove.GetPiece()][bestMove.GetTo()], bonus);
        }
        if (hasPreviousMove2)
        {
            UpdateHistoryEntry(threadState.AllContinuations[previousMove2.GetPiece()][previousMove2.GetTo()].Scores[bestMove.GetPiece()][bestMove.GetTo()], bonus);
        }
        if(betaCutoff)
        {
            if (bestMove.Value != plyState.Killers[0].Value)
            {
                plyState.Killers[1] = plyState.Killers[0];
                plyState.Killers[0] = bestMove;
            }
            assert(plyState.Killers[0].Value != plyState.Killers[1].Value);
            threadState.Countermoves[previousMove1.GetPiece()][previousMove1.GetTo()] = bestMove;
        }
    }
    

    for (MoveCount moveIndex = 0; moveIndex < attemptedMoveCount; moveIndex++)
    {
        const Move& attemptedMove = attemptedMoves[moveIndex];
        if(attemptedMove.Value == bestMove.Value)
        {
            continue;
        }

        const bool attemptedCapture = attemptedMove.GetTakesPiece() != Pieces::Empty;
        if (attemptedCapture)
        {
            UpdateHistoryEntry(threadState.CaptureHistory[attemptedMove.GetPiece()][attemptedMove.GetTo()][attemptedMove.GetTakesPiece()], -bonus);
        }
        else
        {
            UpdateHistoryEntry(threadState.History[attemptedMove.GetColorToMove()][attemptedMove.GetFrom()][attemptedMove.GetTo()], -bonus);
            if (hasPreviousMove1)
            {
                UpdateHistoryEntry(threadState.AllContinuations[previousMove1.GetPiece()][previousMove1.GetTo()].Scores[attemptedMove.GetPiece()][attemptedMove.GetTo()], -bonus);
            }
            if (hasPreviousMove2)
            {
                UpdateHistoryEntry(threadState.AllContinuations[previousMove2.GetPiece()][previousMove2.GetTo()].Scores[attemptedMove.GetPiece()][attemptedMove.GetTo()], -bonus);
            }
        }
    }
}

Score Search::AlphaBeta(ThreadState& threadState, Board& board, Ply depth, const Ply ply, Score alpha, Score beta, bool isPrincipalVariation, bool nullMoveAllowed)
{
    PlyData& plyState = threadState.Plies[ply];
    if (isPrincipalVariation)
    {
        plyState.PrincipalVariation.Length = 0;
    }

    const bool rootNode = ply == 0;
    const bool zeroWindow = alpha == beta - 1;

    assert(threadState.ColorToMove == (board.ColorToMove ^ (ply % 2)));
    
    // TIME CONTROL
    if (depth > 2 && threadState.Stopper.ShouldStop(threadState.Stats.Nodes))
    {
        //const Score score = Contempt(board);
        return beta;
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
    if(Tablebases::CanProbe(board))
    {
        threadState.Stats.TbHits++;
        if (rootNode)
        {
            Move tbMove;
            const auto tbWin = Tablebases::ProbeRoot(board, tbMove);
            if (tbWin)
            {
                StoreTranspositionTable(threadState, board.Key, tbMove, 42, ply, Constants::TablebaseMate, TranspositionTableFlags::Exact);
                return Constants::TablebaseMate;
            }
        }
        else
        {
            auto result = Tablebases::Probe(board);
            switch (result)
            {
            case GameOutcome::Win:
                return Constants::TablebaseMate;
            case GameOutcome::Draw:
                return Contempt(board);
            case GameOutcome::Loss:
                return -Constants::TablebaseMate;
            case GameOutcome::Unknown:
                Throw();
                break;
            }
        }
    }

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
    if(depth <= 0 || ply >= Constants::MaxSearchPly)
    {
        const Score eval = Quiescence(threadState, board, depth, ply, alpha, beta, isPrincipalVariation);
        return eval;
    }

    ++threadState.Stats.Nodes;
    const MoveScore bonus = depth * depth + depth - 1;

    // PROBE TRANSPOSITION TABLE
    TranspositionTableEntry entry;
    bool hashEntryExists = true;
    Score probedScore;
    //const ZobristKey key = ZobristKeys.GetSingularKey(board.Key, plyState.SingularMove.Value);
    const ZobristKey key = board.Key;
    bool probeSuccess = TryProbeTranspositionTable(key, depth, ply, alpha, beta/*, plyState.SingularMove*/, entry, probedScore, hashEntryExists);
    //probeSuccess = false;
    //hashEntryExists = false;

    if(hashEntryExists && (datagen || Options::Threads != 1))
    {
        const bool isPseudoLegal = MoveValidator::IsPseudoLegal(board, entry.MMove);
        if(!isPseudoLegal)
        {
            hashEntryExists = false;
            probeSuccess = false;
        }
        else
        {
            const bool isLegal = MoveValidator::IsKingSafeAfterMove(board, entry.MMove);
            if(!isLegal)
            {
                hashEntryExists = false;
                probeSuccess = false;
            }
        }
    }

    const Move principalVariationMove = hashEntryExists ? entry.MMove : Move(0);
    assert(!hashEntryExists || principalVariationMove.Value == 0 || principalVariationMove.GetColorToMove() == board.ColorToMove);
    //assert(!hashEntryExists || std::abs(entry.SScore) > Constants::MateThreshold || principalVariationMove.Value != 0);

    if (probeSuccess)
    {
        bool returnTtValue = !isPrincipalVariation /*|| (!datagen && probedScore >= alpha && probedScore <= beta)*/;
        if(returnTtValue)
        {
            const bool isDraw = IsRepetitionOr50MoveAfterMove(board, principalVariationMove);
            if(isDraw)
            {
                returnTtValue = false;
            }
        }
        if (returnTtValue)
        {
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
    Score staticScore;
    //if (hashEntryExists)
    //{
    //    staticScore = entry.SScore;
    //}
    //else
    //{
    //    staticScore = Evaluation::Evaluate(board, pins, State.Global.Eval);
    //}
#if EVALPINS
    EachColor<Bitboard> pins;
    PinDetector::GetPinnedToKings(board, pins);
    const Bitboard pinned = pins[board.ColorToMove];
#endif
    staticScore = CallEval(board, pins);
    board.StaticEvaluation = staticScore;
    const bool improving = !inCheck && (ply < 2 || staticScore >= board.History[board.History.size() - 2].StaticEvaluation);
    if
    (
        hashEntryExists
        //&& std::abs(probedScore) < Constants::MateThreshold
        && (
            (entry.Flag == TranspositionTableFlags::Exact)
            || (entry.Flag == TranspositionTableFlags::Beta && staticScore < probedScore)
            || (entry.Flag == TranspositionTableFlags::Alpha && staticScore > probedScore)
        )
    )
    {
        staticScore = probedScore;
    }

    if(ply > 1)
    {
        PlyData& oldPlyState = threadState.Plies[ply - 2];
        oldPlyState.Killers[0] = Move(0);
        oldPlyState.Killers[1] = Move(0);
    }

    assert(depth > 0);
    if
    (
        !rootNode
        && !inCheck
        //&& plyState.SingularMove.Value == 0
    )
    {
        // STATIC EVALUATION PRUNING
        if
        (
            depth < 6
            && !isPrincipalVariation
        )
        {
            constexpr std::array<Score, 6> margins = { 64, 64, 128, 256, 512, 768 };
            const Score margin = margins[depth - improving];

            if (staticScore - margin >= beta)
            {
                return beta;
            }
        }

        // RAZORING
        constexpr Score razorMargin = 200;
        if
        (
            depth < 4
            && !isPrincipalVariation
            && staticScore + (razorMargin * depth) < beta
        )
        {
            const auto razorScore = Quiescence(threadState, board, 0, ply, alpha, beta, false);
            if (razorScore < beta)
            {
                return razorScore;
            }

            if (depth == 1)
            {
                return beta;
            }
        }

        // NULL MOVE PRUNING
        if
        (
            nullMoveAllowed
            && depth > 1
            && staticScore >= beta
            && board.BitBoard[board.ColorToMove] != (board.BitBoard[Pieces::Pawn | board.ColorToMove] | board.BitBoard[Pieces::King | board.ColorToMove])
            //&& board.PieceMaterial[board.ColorToMove] > Constants::EndgameMaterial
        )
        {
            const Ply nullDepthReduction = 4 + depth / 4 + static_cast<Ply>(std::min(3, (staticScore - beta) / 256));
            const Move nullMove = Move(0, 0, Pieces::Empty);
            board.DoMove(nullMove);
            const Score nullMoveScore = -AlphaBeta(threadState, board, depth - nullDepthReduction, ply + 1, -beta, -beta + 1, false, false);
            board.UndoMove();
            if (nullMoveScore >= beta)
            {
                return beta;
            }
        }
    }

#if !EVALPINS
    const Bitboard pinned = PinDetector::GetPinnedToKingForColorToMove(board);
#endif

    auto& movePicker = plyState.MMovePicker;
    movePicker.Reset(threadState, ply, board, checkers, pinned, principalVariationMove);
        
    /*MoveArray moves;
    MoveCount moveCount = 0;
    ScoreArray seeScores;
    MoveScoreArray staticMoveScores;*/
    Move previousMove1 = !rootNode ? board.History[board.History.size() - 1].MMove : Move(0);
    Move previousMove2 = board.History.size() > 1 ? board.History[board.History.size() - 2].MMove : Move(0);
    //const Move countermove = threadState.Countermoves[previousMove1.GetPiece()][previousMove1.GetTo()];

    //TablebaseResult parentResult = TablebaseResult::Unknown;
    //if(Tablebases::CanProbe(board))
    //{
    //    parentResult = Tablebases::Probe(board);
    //}

    // INTERNAL ITERATIVE DEEPENING
    if (depth > 3 && !hashEntryExists)
    {
        depth -= 2;
    }

    // MOVE LOOP
    assert(depth > 0);
    //MoveGenerator::GetAllPotentialMoves(board, checkers, pinned, moves, moveCount);
    
    

    Score bestScore = -Constants::Inf;
    Move bestMove;
    bool raisedAlpha = false;
    bool betaCutoff = false;
    uint8_t movesEvaluated = 0;
    uint8_t quietMovesEvaluated = 0;

    MoveArray failedMoves;
    MoveCount failedMoveCount = 0;
    MovePickerEntry moveEntry;
    
    //for (MoveCount moveIndex = 0; moveIndex < moveCount; moveIndex++)
    while(true)
    {
        auto nextMoveExists = movePicker.GetNextMove<true>(moveEntry);

        if(!nextMoveExists)
        {
            break;
        }

        if(threadState.Stopper.Stopped)
        {
            return bestScore;
        }

        const Move move = moveEntry.move;
        State.Global.Table.PrefetchForMove(board, move);

        if(rootNode && threadState.SearchMoveCount != 0)
        {
            bool skipMove = true;
            for(MoveCount searchMoveIndex = 0; searchMoveIndex < threadState.SearchMoveCount; searchMoveIndex++)
            {
                const Move searchMove = threadState.SearchMoves[searchMoveIndex];
                if(move.Value == searchMove.Value)
                {
                    skipMove = false;
                    break;
                }
            }

            if(skipMove)
            {
                continue;
            }
        }
        
        //if(move.Value == plyState.SingularMove.Value)
        //{
        //    continue;
        //}

        const Piece takesPiece = move.GetTakesPiece();
        const bool capture = takesPiece != Pieces::Empty;
        const Piece pawnPromoteTo = move.GetPawnPromoteTo();
        const bool promotion = pawnPromoteTo != Pieces::Empty;
        const bool givesCheck = CheckDetector::DoesGiveCheck(board, move);
        const bool quiet = !capture && !promotion && !givesCheck;

        MoveScore moveScore = capture
            ? threadState.CaptureHistory[move.GetPiece()][move.GetTo()][takesPiece]
            : threadState.History[move.GetColorToMove()][move.GetFrom()][move.GetTo()]
            + threadState.AllContinuations[previousMove1.GetPiece()][previousMove1.GetTo()].Scores[move.GetPiece()][move.GetTo()]
            + threadState.AllContinuations[previousMove2.GetPiece()][previousMove2.GetTo()].Scores[move.GetPiece()][move.GetTo()];

        //{
        //    auto file = std::ofstream("C:/temp/history.txt", std::ios::app);
        //    file << std::to_string(moveScore) << "\n";
        //    file.flush();
        //    file.close();
        //}

        if
        (
            (!datagen || !isPrincipalVariation)
            && !rootNode
            && !promotion
            && !givesCheck
            && movesEvaluated > 0
        )
        {
            // LATE MOVE PRUNING
            constexpr auto lateMovePruning = std::array<Score, 5> { 0, 8, 15, 25, 40 };
            if
            (
                depth < 5
                && movesEvaluated > lateMovePruning[depth]
            )
            {
                break;
            }

            // HISTORY PRUNING
            if (moveScore < (depth + improving) * -8192)
            {
                continue;
            }

            // LATE QUIET MOVE PRUNING
            constexpr auto lateQuietMovePruning = std::array<Score, 8> { 0, 3, 6, 10, 15, 20, 25, 30 };
            if
            (
                !capture
                && depth < 8
                && quietMovesEvaluated > lateQuietMovePruning[depth]
            )
            {
                continue;
            }

            // SEE PRUNING
            if
            (
                depth < 6
            )
            {
                const Score marginPerDepth = capture ? 128 : 48;
                auto quietSee = capture ? moveEntry.see : See::GetSee(board, move);
                if (quietSee <= depth * -marginPerDepth)
                {
                    continue;
                }
            }
        }

        // SINGULAR EXTENSION
        Ply extension = 0;
        //if
        //(
        //    !rootNode
        //    //&& !inCheck 
        //    && depth > 7
        //    //&& nullMoveAllowed
        //    && plyState.SingularMove.Value == 0
        //    && move.Value == principalVariationMove.Value
        //    && entry.Flag != TranspositionTableFlags::Alpha
        //    && entry.Depth >= depth - 3
        //    && std::abs(probedScore) < Constants::MateThreshold
        //)
        //{
        //    const Score singularBeta = static_cast<Score>(probedScore - depth * 2);
        //    const Score singularAlpha = static_cast<Score>(singularBeta - 1);
        //    const Ply singularDepth = static_cast<Ply>(depth / 2);
        //    
        //    plyState.SingularMove = move;
        //    const MovePicker movePickerBackup = movePicker;
        //    const Score singularScore = AlphaBeta(threadId, board, singularDepth, ply, singularAlpha, singularBeta, false, nullMoveAllowed);
        //    plyState.SingularMove = Move(0);

        //    if(singularScore < singularBeta)
        //    {
        //        extension++;
        //    }
        //    else if(singularBeta >= beta)
        //    {
        //        return singularBeta;
        //    }
        //    //else if(probedScore >= beta)
        //    //{
        //    //    plyState.SingularMove = move;
        //    //    const Score zeroWindowScore = AlphaBeta(threadId, board, singularDepth, ply, beta - 1, beta, false, nullMoveAllowed);
        //    //    plyState.SingularMove = Move(0);
        //    //	if(zeroWindowScore >= beta)
        //    //	{
        //    //        return beta;
        //    //	}
        //    //}
        //    movePicker = movePickerBackup;
        //}
        board.DoMove(move);

        // LATE MOVE REDUCTION
        Ply reduction = 0;
        if
        (
            movesEvaluated > 1
            //&& (!rootNode || movesEvaluated > 3)
            //&& (!isPrincipalVariation || movesEvaluated > 3)
            && depth >= 3
            //&& !inCheck
            //&& move.Value != plyState.Killers[0].Value
            //&& move.Value != plyState.Killers[1].Value
            //&& move.Value != countermove.Value
            && moveEntry.see <= 0
            && pawnPromoteTo == Pieces::Empty
            && extension == 0
        )
        {
            reduction = SearchData.Reductions[depth][movesEvaluated];

            if(reduction > 0)
            {
                if (improving)
                {
                    reduction--;
                }

                if(!isPrincipalVariation)
                {
                    reduction++;
                }

                //if
                //(
                //    move.Value == plyState.Killers[0].Value
                //    || move.Value == plyState.Killers[1].Value
                //)
                //{
                //    reduction--;
                //}

                if (moveScore > 0)
                {
                    reduction--;
                    if (moveScore > 8912)
                    {
                        reduction--;
                    }
                }
                else if (moveScore < 0)
                {
                    reduction++;
                    if (moveScore < -16384)
                    {
                        reduction++;
                    }
                }

                reduction = std::max(static_cast<Ply>(0), reduction);
            }
        }

        Score childScore;

        auto nodesBefore = threadState.Stats.Nodes;
        if (movesEvaluated > 0)
        {
            childScore = -AlphaBeta(threadState, board, depth + extension - reduction - 1, ply + 1, -alpha - 1, -alpha, false, true);
            if (reduction > 0 && childScore > alpha)
            {
                childScore = -AlphaBeta(threadState, board, depth + extension - 1, ply + 1, -alpha - 1, -alpha, false, true);
            }
            if (!zeroWindow && childScore > alpha && childScore < beta)
            {
                childScore = -AlphaBeta(threadState, board, depth + extension - 1, ply + 1, -beta, -alpha, isPrincipalVariation, true);
            }
        }
        else
        {
            childScore = -AlphaBeta(threadState, board, depth + extension - 1, ply + 1, -beta, -alpha, isPrincipalVariation, true);
        }

        if(rootNode)
        {
            auto nodesForMove = threadState.Stats.Nodes - nodesBefore;
            threadState.NodesPerMove[move.GetFrom()][move.GetTo()] += nodesForMove;
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

                if (childScore >= beta)
                {
                    betaCutoff = true;
                    break;
                }

                if (isPrincipalVariation)
                {
                    if(rootNode)
                    {
                        StoreTranspositionTable(threadState, key, bestMove, depth, ply, bestScore, TranspositionTableFlags::Exact);
                    }

                    PrincipalVariationData& thisPlyPv = plyState.PrincipalVariation;
                    thisPlyPv.Moves[0] = bestMove;
                    if (ply < Constants::MaxSearchPly - 1)
                    {
                        PlyData& nextPlyState = threadState.Plies[ply + 1];
                        PrincipalVariationData& nextPlyPv = nextPlyState.PrincipalVariation;
                        thisPlyPv.Length = static_cast<Ply>(1 + nextPlyPv.Length);
                        for (Ply nextPlyIndex = 0; nextPlyIndex < nextPlyPv.Length; nextPlyIndex++)
                        {
                            thisPlyPv.Moves[nextPlyIndex + 1] = nextPlyPv.Moves[nextPlyIndex];
                        }
                        //nextPlyPv.Length = 0;
                    }
                    else
                    {
                        thisPlyPv.Length = 1;
                    }
                }
            }
        }
        failedMoves[failedMoveCount++] = move;
    }

    // MATE / STALEMATE
    if(movesEvaluated == 0)
    {
        //if(plyState.SingularMove.Value != 0)
        //{
        //    return alpha;
        //}
        if(inCheck)
        {
            bestScore = -currentMateScore;
        }
        else
        {
            bestScore = Contempt(board);
        }

        if(bestScore > alpha)
        {
            raisedAlpha = true;
            if(bestScore > beta)
            {
                betaCutoff = true;
            }
        }
    }

    if (raisedAlpha)
    {
        UpdateHistory(threadState, board, depth, ply, failedMoves, failedMoveCount, bestMove, betaCutoff);
        if (betaCutoff)
        {
            StoreTranspositionTable(threadState, key, bestMove, depth, ply, bestScore, TranspositionTableFlags::Beta);
            return beta;
        }
        StoreTranspositionTable(threadState, key, bestMove, depth, ply, bestScore, TranspositionTableFlags::Exact);
    }
    else
    {
        StoreTranspositionTable(threadState, key, bestMove, depth, ply, bestScore, TranspositionTableFlags::Alpha);
    }
    return bestScore;
}

Score Search::Aspiration(ThreadState& threadState, Board& board, const Ply depth, const Score previous)
{
    if(depth < 5)
    {
        const Score fullSearchScore = AlphaBeta(threadState, board, depth, 0, -Constants::Inf, Constants::Inf, true, true);
        return fullSearchScore;
    }

    constexpr Score window = 20;
    constexpr Score termination = 5000;
    Score widen = 20;
    Score alpha = previous - window;
    Score beta = previous + window;
    
    while (true)
    {
        if(threadState.Stopper.Stopped)
        {
            return previous;
        }

        if (alpha < -termination)
        {
            alpha = -Constants::Inf;
        }
        if (beta > termination)
        {
            beta = Constants::Inf;
        }

        const Score score = AlphaBeta(threadState, board, depth, 0, alpha, beta, true, true);
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

Score Search::MultiPv(ThreadState& threadState, Board& board, const Ply depth, const Score previous)
{
    assert((depth == 1 && previous == -Constants::Inf) || (depth > 1 && previous != -Constants::Inf));
    const SearchParameters& parameters = threadState.Parameters;
    threadState.SearchMoves = parameters.SearchMoves;
    threadState.SearchMoveCount = parameters.SearchMoveCount;
    threadState.SearchedMultiPv = 0;
    
    if(parameters.MultiPv > 1 && threadState.SearchMoveCount == 0)
    {
        const Bitboard checkers = CheckDetector::GetCheckers(board);
        const Bitboard pinned = PinDetector::GetPinnedToKingForColorToMove(board);
        MoveGenerator::GetAllPotentialMoves(board, checkers, pinned, threadState.SearchMoves, threadState.SearchMoveCount);
    }

    for(MoveCount moveIndex = 0; moveIndex < parameters.MultiPv; moveIndex++)
    {
        threadState.SelectiveDepth = 0;
        Score score;
        if(moveIndex == 0)
        {
            score = Aspiration(threadState, board, depth, previous);
        }
        else
        {
            score = AlphaBeta(threadState, board, depth, 0, -Constants::Inf, Constants::Inf, true, true);
        }

        if (depth > 0 && threadState.Stopper.Stopped)
        {
            break;
        }

        threadState.SavedPrincipalVariations[moveIndex] = threadState.Plies[0].PrincipalVariation;
        threadState.SavedScores[moveIndex] = score;
        threadState.SearchedMultiPv = moveIndex + 1;

        if (threadState.Id == 0 && Callback != nullptr)
        {
            SearchCallbackData callbackData(threadState, board, State, depth, score, moveIndex, threadState.Stopper.Stopped);
            threadState.Stats.Elapsed = threadState.Stopper.GetElapsed();
            Callback(callbackData);
        }

        if(threadState.SearchMoveCount > 0)
        {
            const Move bestMove = threadState.SavedPrincipalVariations[moveIndex].Moves[0];
            MoveCount bestMoveIndex = 255;
            for(MoveCount searchMoveIndex = 0; searchMoveIndex < threadState.SearchMoveCount; searchMoveIndex++)
            {
                const Move searchMove = threadState.SearchMoves[searchMoveIndex];
                if(searchMove.Value == bestMove.Value)
                {
                    bestMoveIndex = searchMoveIndex;
                    break;
                }
            }
            assert(bestMoveIndex != 255);
            threadState.SearchMoves[bestMoveIndex] = threadState.SearchMoves[threadState.SearchMoveCount - 1];
            threadState.SearchMoveCount--;
        }

        if(threadState.SearchMoveCount == 0)
        {
            break;
        }
    }

    return threadState.SavedScores[0];
}

void Search::GetSearchResults(const ThreadState& threadState, const Board& board, Ply depth, Score score, SearchResults& results)
{
    Move ttMove = Move(0);
    const bool success = State.Global.Table.TryGetPvMove(board, ttMove);
    if(threadState.Parameters.MultiPv <= 1 && success) // Should fix
    {
        results.BestMove = ttMove;
    }
    else
    {
        results.BestMove = threadState.SavedPrincipalVariations[0].Moves[0];
    }
    
    results.SearchedDepth = depth;
    results.SScore = score;
}

void Search::IterativeDeepen(const ThreadId threadId, Board& board, SearchResults& results)
{
    ThreadState& threadState = State.Thread[threadId];

    Score previousScore = -Constants::Inf;
    Ply depth;
    for (depth = 1; depth <= State.Global.Parameters.MaxDepth; depth++)
    {
        const Score score = MultiPv(threadState, board, depth, previousScore);
        
        const auto bestMove = threadState.SavedPrincipalVariations[0].Moves[0];
        const auto bestMoveNodes = threadState.NodesPerMove[bestMove.GetFrom()][bestMove.GetTo()];
        if (threadState.Stopper.ShouldStopDepthIncrease(threadState.Stats.Nodes, bestMoveNodes))
        {
            break;
        }

        previousScore = score;
    }
    GetSearchResults(threadState, board, depth, threadState.SavedScores[0], results);
}

void Search::IterativeDeepenLazySmp(Board& board, SearchResults& results)
{
    auto threads = std::vector<std::thread>();
    for (ThreadId helperId = 1; helperId < Options::Threads; helperId++)
    {
        State.Thread[helperId] = State.Thread[0];
        State.Thread[helperId].Id = helperId;
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
        State.Thread[helperId].Stopper.Stopped = true;
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

void Search::Run(Board& board, const SearchParameters& parameters, SearchResults& results)
{
    assert(!board.enableAccumulatorStack);
    board.enableAccumulatorStack = true;
    if(!State.Initialized)
    {
        State.NewGame();
    }
    State.NewSearch(board, parameters);
    IterativeDeepenLazySmp(board, results);
    board.enableAccumulatorStack = false;
}
