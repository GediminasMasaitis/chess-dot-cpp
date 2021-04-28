#pragma once

#include "searchstate.h"

#include <functional>

class SearchCallbackData
{
public:
    Board& Board;
    SearchState& State;
    Ply Depth;
    Score _Score;

    SearchCallbackData(::Board& board, SearchState& data, Ply depth, Score score)
        : Board(board),
          State(data),
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
    Move IterativeDeepen(Board& board);

public:
    SearchState State;

    bool TryProbeTranspositionTable(const ZobristKey key, const Ply depth, const Score alpha, const Score beta, Move& bestMove, Score& score, bool& entryExists);
    void StoreTranspositionTable(const ZobristKey key, const Move move, const Ply depth, const Score score, const TtFlag flag);
    Score Contempt(const Board& board);
    Score Quiescence(Board& board, Ply depth, Ply ply, Score alpha, Score beta);
    Score AlphaBeta(Board& board, Ply depth, const Ply ply, Score alpha, Score beta, bool nullMoveAllowed);
    Score Aspiration(Board& board, const Ply depth, const Score previous);
    Move Run(Board& board, const SearchParameters& parameters);


    explicit Search(const SearchCallback& callback)
        : Callback(callback)
    {
        State = SearchState();
    }
};
