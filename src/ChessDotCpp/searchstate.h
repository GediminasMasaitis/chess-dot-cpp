#pragma once
#include "board.h"
#include "options.h"
#include "searchhash.h"

class SearchParameters
{
public:
    bool Infinite = false;
    Ply MaxDepth = Constants::MaxDepth;

    size_t WhiteTime = 1000000;
    size_t BlackTime = 1000000;

    size_t WhiteTimeIncrement = 10000;
    size_t BlackTimeIncrement = 10000;

    size_t MinNodes = 0;
    size_t MaxNodes = 0;

    bool SkipNewSearch = false;
};

class SearchStats
{
public:
    //static constexpr bool Enable = true;

    Stat Nodes;
    size_t Elapsed;

    Stat HashMiss;
    Stat HashCollision;
    Stat HashInsufficientDepth;

    void NewSearch()
    {
        Nodes = 0;
        Elapsed = 0;
        HashMiss = 0;
        HashCollision = 0;
        HashInsufficientDepth = 0;
    }

    SearchStats()
    {
        NewSearch();
    }
};

class ContinuationEntry
{
public:
    EachPiece<EachPosition<MoveScore>> Scores{};

    void NewSearch()
    {
        for (Piece piece = 0; piece < Pieces::Count; piece++)
        {
            for (Position to = 0; to < Positions::Count; to++)
            {
                Scores[piece][to] >>= 3;
            }
        }
    }

    void NewGame()
    {
        for (Piece piece = 0; piece < Pieces::Count; piece++)
        {
            for (Position to = 0; to < Positions::Count; to++)
            {
                Scores[piece][to] = 0;
            }
        }
    }
};

class PlyData
{
public:
    constexpr static Ply MaxContinuationCount = 6;
    
    using KillerArray = std::array<Move, 2>;
    KillerArray Killers;
    

    void NewSearch()
    {
    }

    void NewGame()
    {
        Killers[0].Value = 0;
        Killers[1].Value = 0;
    }
};

using PlyDataArray = std::array<PlyData, Constants::MaxPly>;

class ThreadState
{
public:
    SearchStats Stats{};
    PlyDataArray Plies;
    
    EachColor<EachPosition<EachPosition<MoveScore>>> History;
    EachPiece<EachPosition<EachPiece<MoveScore>>> CaptureHistory;
    EachPiece<EachPosition<ContinuationEntry>> AllContinuations;
    EachPiece<EachPosition<Move>> Countermoves;

    EachPosition<EachPosition<Stat>> NodesPerMove;

    bool StopIteration;
    std::vector<Move> SavedPrincipalVariation{};
    
    Move SingularMove;
    Ply IterationsSincePvChange;
    Ply IterationInitialDepth;
    Ply SelectiveDepth;
    

    void NewSearch()
    {
        Stats.NewSearch();

        for(Ply i = 0; i < Constants::MaxPly; i++)
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

        for (Piece piece = 0; piece < Pieces::Count; piece++)
        {
            for (Position to = 0; to < Positions::Count; to++)
            {
                AllContinuations[piece][to].NewSearch();
            }
        }

        for (Position from = 0; from < Positions::Count; from++)
        {
            for (Position to = 0; to < Positions::Count; to++)
            {
                NodesPerMove[from][to] = 0;
            }
        }
        
        SingularMove = Move(0);
        IterationsSincePvChange = 0;
    }

    void NewGame()
    {
        for (Ply i = 0; i < Constants::MaxPly; i++)
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
                AllContinuations[piece][to].NewGame();
            }
        }
    }
};
using ThreadVector = std::vector<ThreadState>;

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
    Color ColorToMove;
    BreadcrumbArray Breadcrumbs{};
    SearchParameters Parameters{};

    GlobalData()
    {
        ColorToMove = Colors::White;
    }
    
    void NewGame()
    {
        Table.SetSize(16 * 1024 * 1024);
        Table.Clear();
#if EVALTABLE
        Eval.EvalTable.SetSize(16 * 1024 * 1024);
        Eval.EvalTable.Clear();
#endif
#if PAWNTABLE
        Eval.PawnTable.SetSize(16 * 1024 * 1024);
        Eval.PawnTable.Clear();
#endif
    }

    void NewSearch(const Board& board)
    {
        ColorToMove = board.ColorToMove;
    	if(!Parameters.SkipNewSearch)
        {
            for (auto& breadcrumb : Breadcrumbs)
            {
                breadcrumb.Key = 0;
                breadcrumb.TThreadId = -1;
            }
    	}
    }
};

class SearchState
{
public:
    bool Initialized;
    ThreadVector Thread;
    GlobalData Global{};
    //std::unique_ptr<ThreadPool> Pool;

    SearchState()
    {
        Initialized = false;
    }

    void NewGame()
    {
        Thread = ThreadVector(Options::Threads);
        //auto pool_size = static_cast<uint32_t>(Options::Threads - 1);
        //if(Options::Threads > 1 && (Pool == nullptr || Pool->get_thread_count() != pool_size))
        //{
        //    Pool = std::make_unique<thread_pool>(pool_size);
        //    Pool->sleep_duration = 0;
        //    //Pool = std::make_unique<ThreadPool>(Options::Threads - 1);
        //}
        //else
        //{
        //    Pool = nullptr;
        //}
        
        Global.NewGame();
        for(ThreadState& threadState : Thread)
        {
            threadState.NewGame();
        }
        Initialized = true;
    }

    void NewSearch(const Board& board, const SearchParameters& parameters)
    {
        Global.Parameters = parameters;
        Global.NewSearch(board);
    	if(!parameters.SkipNewSearch)
    	{
            for (ThreadState& threadState : Thread)
            {
                threadState.NewSearch();
            }
    	}
    }

    //SearchState& operator=(const SearchState&) = default;
};
