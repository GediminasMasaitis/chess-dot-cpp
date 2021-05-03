#pragma once
#include "board.h"
#include "evalstate.h"
#include "searchhash.h"

//class ContinuationEntry
//{
//public:
//    EachPiece<EachPosition<MoveScore>> Scores{};
//
//    void NewSearch()
//    {
//        for (Piece piece = 0; piece < Pieces::Count; piece++)
//        {
//            for (Position to = 0; to < Positions::Count; to++)
//            {
//                Scores[piece][to] >>= 3;
//            }
//        }
//    }
//
//    void NewGame()
//    {
//        for (Piece piece = 0; piece < Pieces::Count; piece++)
//        {
//            for (Position to = 0; to < Positions::Count; to++)
//            {
//                Scores[piece][to] = 0;
//            }
//        }
//    }
//};
//
//static inline ContinuationEntry EmptyContinuation{};

class PlyData
{
public:
    constexpr static Ply MaxContinuationCount = 6;
    
    using KillerArray = std::array<Move, 2>;
    //using CurrentContinuationsType = std::array<ContinuationEntry*, MaxContinuationCount>;
    
    KillerArray Killers;
    //CurrentContinuationsType CurrentContinuations;
    

    void NewSearch()
    {
        //for(Ply i = 0; i < MaxContinuationCount; i++)
        //{
        //    CurrentContinuations[i] = &EmptyContinuation;
        //}
    }

    void NewGame()
    {
        Killers[0].Value = 0;
        Killers[1].Value = 0;
    }
};
using PlyDataArray = std::array<PlyData, Constants::MaxDepth>;

class ThreadState
{
public:
    PlyDataArray Plies;
    
    EachColor<EachPosition<EachPosition<MoveScore>>> History;
    EachPiece<EachPosition<EachPiece<MoveScore>>> CaptureHistory;
    //EachPiece<EachPosition<ContinuationEntry>> AllContinuations;
    EachPiece<EachPosition<Move>> Countermoves;
    
    Move SingularMove;
    MoveCount BestMoveChanges;
    Ply IterationsSincePvChange;
    

    void NewSearch()
    {
        for(Ply i = 0; i < Constants::MaxDepth; i++)
        {
            Plies[i].NewSearch();
        }

        for (Color color = 0; color < Colors::Count; color++)
        {
            for (Position from = 0; from < Positions::Count; from++)
            {
                for (Position to = 0; to < Positions::Count; to++)
                {
                    History[color][from][to] /= 8;
                }
            }
        }

        for (Piece piece = 0; piece < Pieces::Count; piece++)
        {
            for (Position to = 0; to < Positions::Count; to++)
            {
                for (Piece takesPiece = 0; takesPiece < Pieces::Count; takesPiece++)
                {
                    CaptureHistory[piece][to][takesPiece] /= 8;
                }
            }
        }

        //for (Piece piece = 0; piece < Pieces::Count; piece++)
        //{
        //    for (Position to = 0; to < Positions::Count; to++)
        //    {
        //        AllContinuations[piece][to].NewSearch();
        //    }
        //}

        SingularMove = Move(0);
        BestMoveChanges = 0;
        IterationsSincePvChange = 0;
    }

    void NewGame()
    {
        for (Ply i = 0; i < Constants::MaxDepth; i++)
        {
            Plies[i].NewGame();
        }
        
        for (Color color = 0; color < Colors::Count; color++)
        {
            for (Position from = 0; from < Positions::Count; from++)
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

        for (Piece piece = 0; piece < Pieces::Count; piece++)
        {
            for (Position to = 0; to < Positions::Count; to++)
            {
                Countermoves[piece][to].Value = 0;
                //AllContinuations[piece][to].NewGame();
            }
        }
    }
};
using ThreadVector = std::vector<ThreadState>;

class SearchStats
{
public:
    //static constexpr bool Enable = true;

    Stat Nodes = 0;
    size_t Elapsed = 0;
    
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

    SearchState()
    {
        Thread = ThreadVector(1);
        Global = GlobalData();
        Stats = SearchStats();
    }

    void NewGame()
    {
        for(ThreadState& threadState : Thread)
        {
            threadState.NewGame();
        }
        
        Global.Table.SetSize(16 * 1024 * 1024);
        Global.Table.Clear();

        Global.Eval.EvalTable.SetSize(16 * 1024 * 1024);
        Global.Eval.EvalTable.Clear();

        Global.Eval.PawnTable.SetSize(16 * 1024 * 1024);
        Global.Eval.PawnTable.Clear();
    }

    void NewSearch()
    {
        for (ThreadState& threadState : Thread)
        {
            threadState.NewSearch();
        }
    }

    //SearchState& operator=(const SearchState&) = default;
};
