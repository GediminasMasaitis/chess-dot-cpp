#pragma once

#include "searchstate.h"
#include "stopper.h"

#include <functional>

class SearchCallbackData
{
public:
    ThreadId Id;
    Board& Board;
    SearchState& State;
    Ply Depth;
    Score _Score;
    bool Aborted;

    SearchCallbackData(ThreadId threadId, ::Board& board, SearchState& state, Ply depth, Score score, bool aborted)
        : Id(threadId), Board(board),
          State(state),
          Depth(depth),
          _Score(score),
          Aborted(aborted)
    {
    }
};

using SearchCallback = std::function<void(SearchCallbackData& data)>;

class SearchResults
{
public:
    Ply SearchedDepth;
    Score SScore;
    Move BestMove;
};

class Search
{
private:
    SearchCallback Callback;
    void GetSearchResults(SearchResults& results, Ply depth, Score score);
    void IterativeDeepen(const ThreadId threadId, Board& board, SearchResults& results);
    void IterativeDeepenLazySmp(Board& board, SearchResults& results);
    void IterativeDeepenLazySmpOld(Board& board, SearchResults& results);

public:
    SearchState State{};
    SearchStopper Stopper{};

    bool TryProbeTranspositionTable(const ZobristKey key, const Ply depth, const Score alpha, const Score beta, TranspositionTableEntry& entry, Score& score, bool& entryExists);
    void StoreTranspositionTable(const ThreadState& threadState, const ZobristKey key, const Move move, const Ply depth, const Score score, const TtFlag flag);
    Score Contempt(const Board& board) const;
    bool IsRepetitionOr50Move(const Board& board) const;
    bool IsRepetitionOr50MoveAfterMove(const Board& board, const Move move) const;
    Score Quiescence(const ThreadId threadId, Board& board, Ply depth, Ply ply, Score alpha, Score beta);
    bool TablebaseRootSearch(Board& board);
    void UpdateHistory(const ThreadId threadId, Board& board, Ply depth, Ply ply, MoveArray& attemptedMoves, MoveCount attemptedMoveCount, Move bestMove, bool betaCutoff);
    Score AlphaBeta(const ThreadId threadId, Board& board, Ply depth, const Ply ply, Score alpha, Score beta, bool isPrincipalVariation, bool isCutNode, bool nullMoveAllowed);
    Score Aspiration(const ThreadId threadId, Board& board, const Ply depth, const Score previous);
    //void RunSingleThread(Board& board);
    //void RunMultiThread(Board& board);
    
    void Run(Board& board, const SearchParameters& parameters, SearchResults& results);


    explicit Search(const SearchCallback& callback)
        : Callback(callback)
    {
    }
};
