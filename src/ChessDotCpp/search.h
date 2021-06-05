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

    SearchCallbackData(ThreadId threadId, ::Board& board, SearchState& state, Ply depth, Score score)
        : Id(threadId), Board(board),
          State(state),
          Depth(depth),
          _Score(score)
    {
    }
};

using SearchCallback = std::function<void(SearchCallbackData& data)>;


class Search
{
private:
    SearchCallback Callback;
    Score IterativeDeepen(const ThreadId threadId, Board& board);
    void IterativeDeepenLazySmp(Board& board);

public:
    SearchState State{};
    SearchStopper Stopper{};

    bool TryProbeTranspositionTable(const ZobristKey key, const Ply depth, const Score alpha, const Score beta, TranspositionTableEntry& entry, Score& score, bool& entryExists);
    void StoreTranspositionTable(const ThreadState& threadState, const ZobristKey key, const Move move, const Ply depth, const Score score, const TtFlag flag);
    Score Contempt(const Board& board) const;
    bool IsRepetitionOr50Move(const Board& board) const;
    Score Quiescence(const ThreadId threadId, Board& board, Ply depth, Ply ply, Score alpha, Score beta);
    Score AlphaBeta(const ThreadId threadId, Board& board, Ply depth, const Ply ply, Score alpha, Score beta, bool isPrincipalVariation, bool isCutNode, bool nullMoveAllowed);
    Score Aspiration(const ThreadId threadId, Board& board, const Ply depth, const Score previous);
    //void RunSingleThread(Board& board);
    //void RunMultiThread(Board& board);
    Score Run(Board& board, const SearchParameters& parameters);


    explicit Search(const SearchCallback& callback)
        : Callback(callback)
    {
    }
};
