#pragma once
#include "board.h"
#include "options.h"
#include "searchhash.h"
#include "searchparameters.h"
#include "stopper.h"
#include "movepick.h"

class SearchStats
{
public:
    //static constexpr bool Enable = true;

    Stat Nodes;
    Stat TbHits;
    size_t Elapsed;

    Stat HashMiss;
    Stat HashCollision;
    Stat HashInsufficientDepth;

    void NewSearch()
    {
        Nodes = 0;
        TbHits = 0;
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

class PrincipalVariationData
{
public:
    Ply Length;
    EachSearchPly<Move> Moves;
};

class PlyData
{
public:
    Move Killer;
    Move SingularMove;
    MovePicker MMovePicker;
    PrincipalVariationData PrincipalVariation;

    void NewSearch()
    {
        Killer.Value = 0;

        //PrincipalVariation.NewIteration();
        //SingularMove = Move(0);
    }

    void NewGame()
    {
        Killer.Value = 0;
    }
};

using PlyDataArray = std::array<PlyData, Constants::MaxPly>;

class ThreadState
{
public:
    ThreadId Id;
    SearchParameters Parameters;
    SearchStats Stats{};
    PlyDataArray Plies;
    SearchStopper Stopper;
    
    EachColor<EachPosition<EachPosition<MoveScore>>> History;
    EachPiece<EachPosition<EachPiece<MoveScore>>> CaptureHistory;
    EachPiece<EachPosition<ContinuationEntry>> AllContinuations;
    EachPiece<EachPosition<Move>> Countermoves;

    EachPosition<EachPosition<Stat>> NodesPerMove;

    EachMove<PrincipalVariationData> SavedPrincipalVariations;
    EachMove<Score> SavedScores;

    MoveArray SearchMoves;
    MoveCount SearchMoveCount;
    MoveCount SearchedMultiPv;
    //std::vector<Move> SavedPrincipalVariation{};

    Ply SelectiveDepth;

    Color ColorToMove;

    void NewSearch(const Board& board, const SearchParameters& parameters)
    {
        Parameters = parameters;
        Stats.NewSearch();
        Stopper.Init(parameters, board);

        for(Ply i = 0; i < Constants::MaxPly; i++)
        {
            Plies[i].NewSearch();
        }

        for (Position from = 0; from < Positions::Count; from++)
        {
            for (Position to = 0; to < Positions::Count; to++)
            {
                NodesPerMove[from][to] = 0;
            }
        }

        ColorToMove = board.ColorToMove;
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

class GlobalData
{
public:
    TranspositionTable Table{};
    SearchParameters Parameters{};

    GlobalData()
    {
    }
    
    void NewGame()
    {
        Table.SetSizeFromOptions();
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

    void NewSearch()
    {
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
        //for(ThreadState& threadState : Thread)
        for(ThreadId id = 0; id < Options::Threads; id++)
        {
            ThreadState& threadState = Thread[id];
            threadState.Id = id;
            threadState.NewGame();
        }
        Initialized = true;
    }

    void NewSearch(const Board& board, const SearchParameters& parameters)
    {
        Global.Parameters = parameters;
        Global.NewSearch();
    	if(!parameters.SkipNewSearch)
    	{
            for (ThreadState& threadState : Thread)
            {
                threadState.NewSearch(board, parameters);
            }
    	}
    }

    //SearchState& operator=(const SearchState&) = default;
};
