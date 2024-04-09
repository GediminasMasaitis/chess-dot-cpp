#pragma once

#include "searchstate.h"
#include "stopper.h"

#include <functional>

class SearchCallbackData
{
public:
    ThreadState& _ThreadState;
    Board& _Board;
    SearchState& State;
    Ply Depth;
    Score _Score;
    MoveCount MultiPv;
    bool Aborted;

    SearchCallbackData(ThreadState& threadState, ::Board& board, SearchState& state, Ply depth, Score score, MoveCount multiPv, bool aborted)
        : _ThreadState(threadState), _Board(board),
          State(state),
          Depth(depth),
          _Score(score),
          MultiPv(multiPv),
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
    void GetSearchResults(const ThreadState& threadState, const Board& board, Ply depth, Score score, SearchResults& results);
    void IterativeDeepen(const ThreadId threadId, Board& board, SearchResults& results);
    void IterativeDeepenLazySmp(Board& board, SearchResults& results);
    void IterativeDeepenLazySmpOld(Board& board, SearchResults& results);

public:
    SearchState State{};

    bool TryProbeTranspositionTable(const ZobristKey key, const Ply depth, const Ply ply, const Score alpha, const Score beta, const Move singularMove, TranspositionTableEntry& entry, Score& score, bool& entryExists);
    void StoreTranspositionTable(const ThreadState& threadState, const ZobristKey key, const Move move, const Ply depth, const Ply ply, const Score score, const TtFlag flag);
    Score Contempt(const Board& board) const;
    bool IsRepetitionOr50Move(const Board& board) const;
    bool IsRepetitionOr50MoveAfterMove(const Board& board, const Move move) const;
    Score Quiescence(ThreadState& threadState, Board& board, Ply depth, const Ply ply, Score alpha, Score beta, const bool isPrincipalVariation);
    bool TablebaseRootSearch(Board& board);
    void UpdateHistory(ThreadState& threadState, Board& board, Ply depth, Ply ply, MoveArray& attemptedMoves, MoveCount attemptedMoveCount, Move bestMove, bool betaCutoff);
    Score AlphaBeta(ThreadState& threadState, Board& board, Ply depth, const Ply ply, Score alpha, Score beta, bool isPrincipalVariation, bool nullMoveAllowed);
    Score Aspiration(ThreadState& threadState, Board& board, const Ply depth, const Score previous);
    Score MultiPv(ThreadState& threadState, Board& board, const Ply depth, const Score previous);
    //void RunSingleThread(Board& board);
    //void RunMultiThread(Board& board);
    
    void Run(Board& board, const SearchParameters& parameters, SearchResults& results);


    explicit Search(const SearchCallback& callback)
        : Callback(callback)
    {
    }
};
