#pragma once

#include "searchstate.h"

#include <chrono>

class SearchParameters
{
public:
    bool Infinite = false;
    Ply MaxDepth = Constants::MaxDepth;

    size_t WhiteTime = 10000;
    size_t BlackTime = 10000;

    size_t WhiteTimeIncrement = 100;
    size_t BlackTimeIncrement = 100;
};

class SearchStopper
{
public:
    constexpr static size_t InfTime = std::numeric_limits<size_t>::max();
    
    SearchParameters Parameters;
    
    std::chrono::high_resolution_clock::time_point start;
    size_t _minTime;
    size_t _maxTime;
    bool Stopped;

    void Init(const SearchParameters& parameters, bool whiteToMove)
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
            const size_t time = whiteToMove ? parameters.WhiteTime : parameters.BlackTime;
            const size_t increment = whiteToMove ? parameters.WhiteTimeIncrement : parameters.BlackTimeIncrement;
            constexpr HistoryPly movesRemaining = 30;
            const size_t estimatedTime = time + increment * movesRemaining;
            _minTime = std::min(time / 2, estimatedTime / movesRemaining);
            _maxTime = std::min(time * 4 / 5, _minTime * 4);
            
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
    
    [[nodiscard]] bool ShouldStop()
    {
        if(Stopped)
        {
            return true;
        }
        
        const auto elapsed = GetElapsed();
        Stopped = elapsed > _maxTime;
        return Stopped;
    }

    [[nodiscard]] bool ShouldStopDepthIncrease(SearchState& state)
    {
        if (Stopped)
        {
            return true;
        }

    	if(Parameters.Infinite)
    	{
            return false;
    	}

        const MoveCount bestMoveChanges = state.Thread[0].BestMoveChanges;
        const Ply iterationsSincePvChange = state.Thread[0].IterationsSincePvChange;
        size_t reduction = 0;
        if(iterationsSincePvChange > 0)
        {
            const auto reductionFactor = std::min(static_cast<size_t>(iterationsSincePvChange), 7ULL);
            reduction = _minTime * reductionFactor / 10;
        }
        const auto minTime = _minTime - reduction;
        
        //std::min(time / 2, estimatedTime / movesRemaining)
        
        const auto elapsed = GetElapsed();
        Stopped = elapsed > minTime;
        return Stopped;
    }
};
