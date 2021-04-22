#pragma once
#include <functional>
#include <memory>

#include "board.h"

#include <vector>

class PlyData
{
};
using PlyDataArray = std::array<PlyData, Constants::MaxDepth>;

class ThreadData
{
public:
    PlyDataArray Plies;
};
using ThreadVector = std::vector<ThreadData>;

class SearchStats
{
public:
    //static constexpr bool Enable = true;
    
    Stat Nodes = 0;
};

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

    [[nodiscard]] bool ShouldStop()
    {
        return false;
    }

    [[nodiscard]] bool ShouldStopDepthIncrease()
    {
        return false;
    }

    explicit SearchStopper(const SearchParameters& parameters)
        : Parameters(parameters)
    {
    }
};

class TranspositionTableFlags
{
public:
    static constexpr TtFlag None = 0;
    static constexpr TtFlag Alpha = 1;
    static constexpr TtFlag Beta = 2;
    static constexpr TtFlag Exact = 3;

    TranspositionTableFlags() = delete;
};

class TranspositionTableEntry
{
    uint8_t DepthCheckAndFlag{};
    uint64_t PartialKeyAndScore{};

public:
    Move MMove;

    [[nodiscard]] Ply GetDepth() const
    {
        return static_cast<Ply>(DepthCheckAndFlag >> 2);
    }

    [[nodiscard]] TtFlag GetFlag() const
    {
        return  static_cast<TtFlag>(DepthCheckAndFlag & 3);
    }

    [[nodiscard]] ZobristKey GetPartialKey() const
    {
        constexpr ZobristKey mask = ~0xFFFFULL;
        return PartialKeyAndScore & mask;
    }

    [[nodiscard]] Score GetScore() const
    {
        return static_cast<short>(PartialKeyAndScore & 0xFFFFULL);
    }
    
    TranspositionTableEntry() = default;

    TranspositionTableEntry(const ZobristKey key, const Move move, const Ply depth, const Score score, const TtFlag flag)
    {
        PartialKeyAndScore = (key & ~0xFFFFULL) | static_cast<uint16_t>(score);
        DepthCheckAndFlag = static_cast<uint8_t>((depth << 2) | flag);
        MMove = move;
    }
};

class TranspositionTable
{
private:
    using TableEntries = std::unique_ptr<TranspositionTableEntry[]>;
    
    size_t _mask = 0;
    size_t _size = 0;
    TableEntries _entries = nullptr;
    std::vector<TranspositionTableEntry> _principalVariation;
    
    static size_t GetClampedSize(size_t bytes)
    {
        const size_t entrySize = sizeof(TranspositionTableEntry);
        const size_t size = bytes / entrySize;
        if ((size & (size - 1)) == 0)
        {
            return size;
        }

        size_t clampedSize = static_cast<size_t>(1);
        while (clampedSize < size)
        {
            clampedSize <<= 1;
        }
        clampedSize >>= 1;

        return clampedSize;
    }

    [[nodiscard]] constexpr size_t GetTableIndex(ZobristKey key) const
    {
        const size_t index = key & _mask;
        return index;
    }

    static constexpr ZobristKey RestoreKey(const ZobristKey partialKey, const size_t index)
    {
        return partialKey | (index & 0xFFFFULL);
    }

public:
 
    void SetSize(const size_t bytes)
    {
        const size_t newSize = GetClampedSize(bytes);

        if (_size == newSize)
        {
            return;
        }

        _size = newSize;
        _mask = _size - 1;
        _entries = TableEntries(new TranspositionTableEntry[newSize]);
    }

    void Store(const ZobristKey key, const Move move, const Ply depth, const Score score, const TtFlag flag) const
    {
        const size_t index = GetTableIndex(key);
        TranspositionTableEntry& existingEntry = _entries[index];
        const ZobristKey entryKey = RestoreKey(existingEntry.GetPartialKey(), index);

        if (entryKey == key && existingEntry.GetDepth() > depth)
        {
            return;
        }

        if (existingEntry.GetFlag() == TranspositionTableFlags::Exact)
        {
            if (flag != TranspositionTableFlags::Exact)
            {
                return;
            }
        }

        const TranspositionTableEntry entry = TranspositionTableEntry(key, move, depth, score, flag);
        _entries[index] = entry;

        TranspositionTableEntry e;
        ZobristKey k;
        if(key == 17035895950239398082ULL)
        {
            auto a = 123;
            auto e2 = TranspositionTableEntry(key, move, depth, score, flag);
        }
        assert(TryProbe(key, &e, &k));
        assert(key == k);
    }

    bool TryProbe(const ZobristKey key, TranspositionTableEntry* entry, ZobristKey* entryKey) const
    {
        //entry = default; return false;
        const size_t index = GetTableIndex(key);
        *entry = _entries[index];
        const bool exists = entry->GetFlag() != TranspositionTableFlags::None;
        *entryKey = RestoreKey(entry->GetPartialKey(), index);
        return exists;
    }

    void GetPrincipalVariation(const Board& board, std::vector<TranspositionTableEntry>& principalVariation) const
    {
        Board clone = board;
        for (Ply i = 0; i < Constants::MaxDepth; i++)
        {
            TranspositionTableEntry entry;
            ZobristKey entryKey;
            const bool success = TryProbe(clone.Key, &entry, &entryKey);
            
            if (!success)
            {
                break;
            }

            if (clone.Key != entryKey)
            {
                break;
            }

            const TtFlag ttFlag = entry.GetFlag();
            if (ttFlag != TranspositionTableFlags::Exact)
            {
                break;
            }

            Move move = entry.MMove;
            principalVariation.push_back(entry);
            clone.DoMove(move);
        }
    }
};

class GlobalData
{
public:
    TranspositionTable Table{};
};

class SearchData
{
public:
    ThreadVector Thread;
    GlobalData Global;
    SearchStats Stats;
    SearchStopper Stopper;

    explicit SearchData(const SearchStopper& stopper)
        : Stopper(stopper)
    {
        Thread = ThreadVector(1);
        Global = GlobalData();
        Stats = SearchStats();
    }
};

class SearchCallbackData
{
public:
    Board& Board;
    SearchData& Data;
    Ply Depth;
    Score _Score;

    SearchCallbackData(::Board& board, SearchData& data, Ply depth, Score score)
        : Board(board),
          Data(data),
          Depth(depth),
          _Score(score)
    {
    }
};

using SearchCallback = std::function<void(SearchCallbackData& data)>;

class Search
{
public:
    static void Run(Board& board, const SearchParameters& parameters, const SearchCallback& callback);
    
    Search() = delete;
};