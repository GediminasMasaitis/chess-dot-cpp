#pragma once
#include "board.h"
#include "evalstate.h"
#include "stopper.h"
#include "searchhash.h"

using KillerArray = std::array<Move, 2>;
class PlyData
{
public:
    KillerArray Killers;

    void NewSearch()
    {
        Killers[0].Value = 0;
        Killers[1].Value = 0;
    }
};

using PlyDataArray = std::array<PlyData, Constants::MaxDepth>;

class ThreadData
{
public:
    PlyDataArray Plies;
    
    EachColor<EachPosition<EachPosition<MoveScore>>> History;
    EachPiece<EachPosition<EachPiece<MoveScore>>> CaptureHistory;
    EachPiece<EachPosition<Move>> Countermoves;
    

    void NewSearch()
    {
        for(Ply i = 0; i < Constants::MaxDepth; i++)
        {
            Plies[i].NewSearch();
        }

        for(Color color = 0; color < Colors::Count; color++)
        {
            for(Position from = 0; from < Positions::Count; from++)
            {
                for (Position to = 0; to < Positions::Count; to++)
                {
                    History[color][from][to] = 0;
                }
            }
        }

        for (Piece piece = 0; piece < Pieces::Count; piece++)
        {
            for (Position to = 0; to < Positions::Count; to++)
            {
                for (Piece takesPiece = 0; takesPiece < Pieces::Count; takesPiece++)
                {
                    CaptureHistory[piece][to][takesPiece] = 0;
                }
            }
        }

    	for(Piece piece = 0; piece < Pieces::Count; piece++)
    	{
            for (Position to = 0; to < Positions::Count; to++)
            {
                Countermoves[piece][to].Value = 0;
            }
    	}
    }
};
using ThreadVector = std::vector<ThreadData>;

class SearchStats
{
public:
    //static constexpr bool Enable = true;

    Stat Nodes = 0;
    
    Stat HashMiss = 0;
    Stat HashCollision = 0;
    Stat HashInsufficientDepth = 0;
};


class GlobalData
{
public:
    TranspositionTable Table{};
    EvalState Eval{};
};

class SearchState
{
public:
    ThreadVector Thread;
    GlobalData Global;
    SearchStats Stats;
    SearchStopper Stopper;

    SearchState()
    {
        Thread = ThreadVector(1);
        Global = GlobalData();
        Stats = SearchStats();
        Stopper = SearchStopper();
    }

    void NewGame()
    {
        Global.Table.SetSize(16 * 1024 * 1024);
        Global.Table.Clear();

        Global.Eval.EvalTable.SetSize(16 * 1024 * 1024);
        Global.Eval.EvalTable.Clear();
    }

    void NewSearch()
    {

    }

    //SearchState& operator=(const SearchState&) = default;
};
