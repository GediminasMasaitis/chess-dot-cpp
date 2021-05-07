#pragma once
#include "board.h"
#include "evalstate.h"
#include "options.h"
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

    bool StopIteration;
    std::vector<Move> SavedPrincipalVariation{};
    
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

class Breadcrumb
{
public:
    std::atomic<ThreadId> TThreadId;
    std::atomic<ZobristKey> Key;
};

class GlobalData
{
public:
    constexpr static size_t BreadcrumbCount = 4096;
    constexpr static size_t BreadcrumbMask = BreadcrumbCount - 1;
    using BreadcrumbArray = std::array<Breadcrumb, BreadcrumbCount>;
    
    TranspositionTable Table{};
    EvalState Eval{};
    Color ColorToMove;
    BreadcrumbArray Breadcrumbs{};

    GlobalData()
    {
        ColorToMove = Colors::White;
    }
	
    void NewGame()
    {
        Table.SetSize(16 * 1024 * 1024);
        Table.Clear();

        Eval.EvalTable.SetSize(16 * 1024 * 1024);
        Eval.EvalTable.Clear();

        Eval.PawnTable.SetSize(16 * 1024 * 1024);
        Eval.PawnTable.Clear();
    }

    void NewSearch(const Board& board)
    {
        ColorToMove = board.ColorToMove;
        for (auto& breadcrumb : Breadcrumbs)
        {
            breadcrumb.Key = 0;
            breadcrumb.TThreadId = -1;
        }
    }
};

class SearchState
{
public:
    ThreadVector Thread;
    GlobalData Global{};
    SearchStats Stats{};

    SearchState()
    {
        Thread = ThreadVector(Options::Threads);
    }

    void NewGame()
    {
        Global.NewGame();
        for(ThreadState& threadState : Thread)
        {
            threadState.NewGame();
        }
    }

    void NewSearch(const Board& board)
    {
        Global.NewSearch(board);
        for (ThreadState& threadState : Thread)
        {
            threadState.NewSearch();
        }
    }

    //SearchState& operator=(const SearchState&) = default;
};
