#pragma once

#include "common.h"
#include "searchstate.h"

#include <mutex>
#include <iostream>

enum class OutputFormats : uint8_t
{
    Plain
};


enum class InputFormats : uint8_t
{
    Epd,
    Plain
};

class TrainingParameters
{
public:
    InputFormats InputFormat;
    std::string InputPath;

    OutputFormats OutputFormat;
    std::string OutputPath;

    std::string OffsetPath;

    SearchParameters SearchParams;
};

class TrainResult
{
public:
    Fen FFen;
    MoveString Move;
    Score SScore;
    HistoryPly Ply;
    int8_t Result;
    char Type;
};

class TrainingReader
{
    std::istream& Stream;
    InputFormats Format;
    std::mutex Mutex;

    size_t Position;

    bool ReadLine(std::string& str, size_t skip);
    bool ReadPlain(TrainResult& data);

public:
    
    
    explicit TrainingReader(std::istream& input, InputFormats format)
        : Stream(input), Format(format), Position(0)
    {
    }

    bool ReadData(TrainResult& data);

    [[nodiscard]] size_t GetCurrentOffset() const;
};

class TrainingWriter
{
    std::ostream& Stream;
    OutputFormats Format;
    std::mutex Mutex;

    void WriteResultsPlain(const TrainResult& result);

public:
    TrainingWriter(std::ostream& stream, OutputFormats format)
        : Stream(stream), Format(format)
    {
    }

    void WriteResults(const TrainResult& result, const bool flush);
};

template<class TBoard>
class BoardCacheEntry
{
public:
    size_t Index;
    TrainResult Result;
    TBoard Board;
};

template<class TBoard>
class BoardCache
{
    TrainingReader& Reader;
    std::mutex Mutex;
    std::vector<size_t> CurrentPositions;
public:
    std::vector<BoardCacheEntry<TBoard>> Entries;
    
    BoardCache(TrainingReader& reader): Reader(reader)
    {
        CurrentPositions = {};
    }

    void LoadAll(size_t limit = 0);

    bool NextEntry(BoardCacheEntry<TBoard>& entry, ThreadId threadId)
    {
        auto threadCount = static_cast<ThreadId>(CurrentPositions.size());
        auto threadSize = Entries.size() / threadCount;
        auto threadStart = threadSize * threadId;
        //auto threadEnd = threadStart + threadSize;
    	
        auto& currentPosition = CurrentPositions[threadId];
    	
        if(currentPosition == threadSize)
        {
            return false;
        }
        entry = Entries[threadStart + currentPosition];
        currentPosition++;
        return true;
    }

    void Reset(ThreadId threadCount)
    {
        CurrentPositions.clear();
    	for (auto i = 0; i < threadCount; i++)
    	{
            CurrentPositions.push_back(0);
    	}
    }
};
