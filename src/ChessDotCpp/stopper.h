#pragma once

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
    SearchParameters Parameters;
    
    std::chrono::high_resolution_clock::time_point start;
    size_t _minTime;
    size_t _maxTime;
    bool Stopped;

    explicit SearchStopper(const SearchParameters& parameters, bool whiteToMove)
        : Parameters(parameters)
    {
        start = std::chrono::high_resolution_clock::now();
        size_t time = whiteToMove ? parameters.WhiteTime : parameters.BlackTime;
        size_t increment = whiteToMove ? parameters.WhiteTimeIncrement : parameters.BlackTimeIncrement;
        _minTime = parameters.Infinite ? std::numeric_limits<size_t>::max() : time / 60 + increment / 3;
        _maxTime = parameters.Infinite ? std::numeric_limits<size_t>::max() : time / 20 + increment;
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

    [[nodiscard]] bool ShouldStopDepthIncrease()
    {
        if (Stopped)
        {
            return true;
        }
    	
        const auto elapsed = GetElapsed();
        Stopped = elapsed > _minTime;
        return Stopped;
    }
};
