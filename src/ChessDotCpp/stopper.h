#pragma once

#include "searchparameters.h"

#include <chrono>

class SearchStopper
{
public:
    constexpr static size_t InfTime = std::numeric_limits<size_t>::max();
    
    SearchParameters Parameters;
    
    std::chrono::high_resolution_clock::time_point start;
    size_t _minTime;
    size_t _maxTime;
    bool Stopped;

    void Init(const SearchParameters& parameters, const Board& board)
    {
        start = std::chrono::high_resolution_clock::now();
        Parameters = parameters;

        if(parameters.Infinite)
        {
            _minTime = InfTime;
            _maxTime = InfTime;
        }
        else
        {
            const bool whiteToMove = board.WhiteToMove;
            const size_t time = whiteToMove ? parameters.WhiteTime : parameters.BlackTime;
            const size_t increment = whiteToMove ? parameters.WhiteTimeIncrement : parameters.BlackTimeIncrement;
            if (parameters.MoveTime == 0)
            {
                constexpr HistoryPly movesRemaining = 12;
                const size_t estimatedTime = time + increment * movesRemaining;
                _minTime = std::min(time / 2, estimatedTime / movesRemaining);
                _maxTime = std::min(time * 4 / 5, _minTime * 4);
            }
            else
            {
                _minTime = parameters.MoveTime;
                _maxTime = parameters.MoveTime;
            }
            
        }
        
        Stopped = false;
    }

    [[nodiscard]] size_t GetElapsed() const
    {
        const auto end = std::chrono::high_resolution_clock::now();
        const auto elapsed = end - start;
        const size_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
        return ms;
    }
    
    [[nodiscard]] bool ShouldStop(Stat nodes)
    {
        if(Stopped)
        {
            return true;
        }
        
        const auto elapsed = GetElapsed();
        Stopped = (elapsed > _maxTime) || (Parameters.MaxNodes != 0 && nodes >= Parameters.MaxNodes);
        return Stopped;
    }

    [[nodiscard]] bool ShouldStopDepthIncrease(const Stat nodes, const Stat bestMoveTotalNodes)
    {
        if(nodes == 0 && bestMoveTotalNodes == 0)
        {
            return true;
        }

        if(Parameters.MinNodes != 0 && nodes >= Parameters.MinNodes)
        {
            Stopped = true;
        }

        if (Stopped)
        {
            return true;
        }

    	if(Parameters.Infinite)
    	{
            return false;
    	}

        const auto bestMoveNodePercent = (bestMoveTotalNodes * 100) / nodes;
        //std::cout << "best " << bestMove.ToPositionString() << " " << bestMoveNodePercent << "% " << bestMoveTotalNodes << " nodes\n";

        // REDUCE BY BESTMOVE CHANGES
        //const Ply iterationsSincePvChange = threadState.IterationsSincePvChange;
        //size_t reduction = 0;
        //if(iterationsSincePvChange > 0)
        //{
        //    const auto reductionFactor = std::min(static_cast<size_t>(iterationsSincePvChange), 7ULL);
        //    reduction = _minTime * reductionFactor / 10;
        //}

        // REDUCE BY NODE DISTRIBUTION
        const auto reductionPercent = std::min(static_cast<size_t>(90), bestMoveNodePercent);
        const auto reduction = (_minTime * reductionPercent) / 100;
        const auto minTime = _minTime - reduction;
        
        const auto elapsed = GetElapsed();
        Stopped = elapsed > minTime;
        return Stopped;
    }
};
