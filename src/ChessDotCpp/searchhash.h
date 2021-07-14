#pragma once

#include "board.h"

#include <iostream>

class TranspositionTableFlags
{
public:
    static constexpr TtFlag None = 0;
    static constexpr TtFlag Alpha = 1;
    static constexpr TtFlag Beta = 2;
    static constexpr TtFlag Exact = 3;

    TranspositionTableFlags() = delete;
};

//class TranspositionTableEntryCompact
//{
//    uint8_t DepthCheckAndFlag{};
//    uint64_t PartialKeyAndScore{};
//
//public:
//    Move MMove;
//
//    [[nodiscard]] Ply GetDepth() const
//    {
//        return static_cast<Ply>(DepthCheckAndFlag >> 2);
//    }
//
//    [[nodiscard]] TtFlag GetFlag() const
//    {
//        return  static_cast<TtFlag>(DepthCheckAndFlag & 3);
//    }
//
//    [[nodiscard]] ZobristKey GetPartialKey() const
//    {
//        constexpr ZobristKey mask = ~0xFFFFULL;
//        return PartialKeyAndScore & mask;
//    }
//
//    [[nodiscard]] Score GetScore() const
//    {
//        return static_cast<short>(PartialKeyAndScore & 0xFFFFULL);
//    }
//
//    TranspositionTableEntryCompact() = default;
//
//    TranspositionTableEntryCompact(const ZobristKey key, const Move move, const Ply depth, const Score score, const TtFlag flag)
//    {
//        PartialKeyAndScore = (key & ~0xFFFFULL) | static_cast<uint16_t>(score);
//        DepthCheckAndFlag = static_cast<uint8_t>((depth << 2) | flag);
//        MMove = move;
//    }
//};
//
//class TranspositionTableCompact
//{
//public:
//    using TableEntries = std::unique_ptr<TranspositionTableEntryCompact[]>;
//
//    size_t _mask = 0;
//    size_t _size = 0;
//    TableEntries _entries = nullptr;
//
//    static size_t GetClampedSize(size_t bytes)
//    {
//        const size_t entrySize = sizeof(TranspositionTableEntryCompact);
//        const size_t size = bytes / entrySize;
//        if ((size & (size - 1)) == 0)
//        {
//            return size;
//        }
//
//        size_t clampedSize = static_cast<size_t>(1);
//        while (clampedSize < size)
//        {
//            clampedSize <<= 1;
//        }
//        clampedSize >>= 1;
//
//        return clampedSize;
//    }
//
//    [[nodiscard]] constexpr size_t GetTableIndex(ZobristKey key) const
//    {
//        const size_t index = key & _mask;
//        return index;
//    }
//
//    static constexpr ZobristKey RestoreKey(const ZobristKey partialKey, const size_t index)
//    {
//        return partialKey | (index & 0xFFFFULL);
//    }
//
//    std::vector<Move> SavedPrincipalVariation{};
//
//    void SetSize(const size_t bytes)
//    {
//        const size_t newSize = GetClampedSize(bytes);
//
//        if (_size == newSize)
//        {
//            return;
//        }
//
//        _size = newSize;
//        _mask = _size - 1;
//        _entries = TableEntries(new TranspositionTableEntryCompact[newSize]);
//    }
//
//    void Clear()
//    {
//        const size_t bytesToClear = sizeof(TranspositionTableEntryCompact) * _size;
//        std::memset(_entries.get(), 0, bytesToClear);
//    }
//
//    void Store(const ZobristKey key, const Move move, const Ply depth, const Score score, const TtFlag flag) const
//    {
//        const size_t index = GetTableIndex(key);
//        TranspositionTableEntryCompact& existingEntry = _entries[index];
//        const ZobristKey entryKey = RestoreKey(existingEntry.GetPartialKey(), index);
//
//        if (entryKey == key && existingEntry.GetDepth() > depth)
//        {
//            return;
//        }
//
//        if (existingEntry.GetFlag() == TranspositionTableFlags::Exact)
//        {
//            if (flag != TranspositionTableFlags::Exact)
//            {
//                return;
//            }
//        }
//
//        const TranspositionTableEntryCompact entry = TranspositionTableEntryCompact(key, move, depth, score, flag);
//        _entries[index] = entry;
//    }
//
//    bool TryProbe(const ZobristKey key, TranspositionTableEntryCompact* entry, ZobristKey* entryKey) const
//    {
//        //entry = default; return false;
//        const size_t index = GetTableIndex(key);
//        *entry = _entries[index];
//        const bool exists = entry->GetFlag() != TranspositionTableFlags::None;
//        *entryKey = RestoreKey(entry->GetPartialKey(), index);
//        return exists;
//    }
//
//    void GetPrincipalVariation(const Board& board, std::vector<Move>& principalVariation) const
//    {
//        Board clone = board;
//        for (Ply i = 0; i < Constants::MaxDepth; i++)
//        {
//            TranspositionTableEntryCompact entry;
//            ZobristKey entryKey;
//            const bool success = TryProbe(clone.Key, &entry, &entryKey);
//
//            if (!success)
//            {
//                break;
//            }
//
//            if (clone.Key != entryKey)
//            {
//                break;
//            }
//
//            const TtFlag ttFlag = entry.GetFlag();
//            if (ttFlag != TranspositionTableFlags::Exact)
//            {
//                break;
//            }
//
//            Move move = entry.MMove;
//            principalVariation.push_back(move);
//            clone.DoMove(move);
//        }
//    }
//
//    void SavePrincipalVariation(const Board& board)
//    {
//        SavedPrincipalVariation.clear();
//        GetPrincipalVariation(board, SavedPrincipalVariation);
//    }
//};


//PACK(
class /*alignas(64)*/ TranspositionTableEntry
{
public:
    ZobristKey Key{};
    Move MMove{};
    Score SScore{};
    Ply Depth {};
    TtFlag Flag {};
    

    TranspositionTableEntry() = default;

    TranspositionTableEntry(const ZobristKey key, const Move move, const Ply depth, const Score score, const TtFlag flag)
    {
        Key = key;
        MMove = move;
        Depth = depth;
        SScore = score;
        Flag = flag;
    }
};
//)

class TranspositionTable
{
public:
    using TableEntries = std::unique_ptr<TranspositionTableEntry[]>;

    size_t _size = 0;
    size_t _mask = 0;
    TableEntries _entries = nullptr;

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
        //const size_t index = key % _size;
        const size_t index = key & _mask;
        return index;
    }

    static constexpr ZobristKey RestoreKey(const ZobristKey partialKey, const size_t index)
    {
        return partialKey | (index & 0xFFFFULL);
    }

    void SetSize(const size_t bytes)
    {
        //const size_t newSize = bytes / sizeof(TranspositionTableEntry);
        const size_t newSize = GetClampedSize(bytes);

        if (_size == newSize)
        {
            return;
        }

        _size = newSize;
        _mask = _size - 1;
        _entries = TableEntries(new TranspositionTableEntry[newSize]);
    }

    void Clear()
    {
        const size_t bytesToClear = sizeof(TranspositionTableEntry) * _size;
        std::memset(_entries.get(), 0, bytesToClear);
    }

    void Store(const ZobristKey key, const Move move, const Ply depth, const Score score, const TtFlag flag) const
    {
        const size_t index = GetTableIndex(key);
        TranspositionTableEntry& existingEntry = _entries[index];

        const bool existingExact = existingEntry.Flag == TranspositionTableFlags::Exact;
        const bool newExact = flag == TranspositionTableFlags::Exact;
        
        if (existingExact && !newExact)
        {
            return;
        }

        if(!existingExact && newExact)
        {
            const TranspositionTableEntry entry = TranspositionTableEntry(key, move, depth, score, flag);
            _entries[index] = entry;
            return;
        }

        if (existingEntry.Key == key && existingEntry.Depth > depth * 2)
        {
            return;
        }

        const TranspositionTableEntry entry = TranspositionTableEntry(key, move, depth, score, flag);
        _entries[index] = entry;
    }

    bool TryProbe(const ZobristKey key, TranspositionTableEntry* entry, ZobristKey* entryKey) const
    {
        //entry = default; return false;
        const size_t index = GetTableIndex(key);
        *entry = _entries[index];
        const bool exists = entry->Flag != TranspositionTableFlags::None;
        *entryKey = entry->Key;
        return exists;
    }

    bool TryGetPvMove(const Board& board, Move& move) const
    {
        TranspositionTableEntry entry;
        ZobristKey entryKey;
        const bool success = TryProbe(board.Key, &entry, &entryKey);

        if (!success)
        {
            return false;
        }

        if (board.Key != entryKey)
        {
            return false;
        }

        const TtFlag ttFlag = entry.Flag;
        if (ttFlag != TranspositionTableFlags::Exact)
        {
            return false;
        }

        move = entry.MMove;
        return true;
    }
    
    void GetPrincipalVariation(const Board& board, std::vector<Move>& principalVariation) const
    {
        Board clone = board;
        for (Ply i = 0; i < Constants::MaxDepth; i++)
        {
            Move move = Move(0);
            const bool success = TryGetPvMove(clone, move);

            if (!success)
            {
                break;
            }
            
            principalVariation.push_back(move);
            clone.DoMove(move);
        }
    }

    bool IsRootMoveChanged(const Board& board, const std::vector<Move>& savedPrincipalVariation)
    {
        if(savedPrincipalVariation.empty())
        {
            return true;
        }
    	
        Move move = Move(0);
        const bool success = TryGetPvMove(board, move);

        if (!success)
        {
            return true;
        }
            	
        const bool isChanged = savedPrincipalVariation[0].Value != move.Value;
        return isChanged;
    }

    void PrintOccupancy()
    {
        const auto samples = 65536;
        const auto gapSize = _size / samples;
        std::array<int64_t, 4> counts{};
        for (auto i = 0; i < _size; i += gapSize)
        {
            counts[_entries[i].Flag]++;
        }

        std::array<double, 4> percentages{};
        for(TtFlag flag = 0; flag < 4; flag++)
        {
            percentages[flag] = static_cast<double>(counts[flag] * 100) / static_cast<double>(samples);
        }

        std::stringstream ss;
        ss << "None: " << std::fixed << std::setprecision(3) << percentages[TranspositionTableFlags::None] << "%";
        ss << ", Alpha: " << std::fixed << std::setprecision(3) << percentages[TranspositionTableFlags::Alpha] << "%";
        ss << ", Beta: " << std::fixed << std::setprecision(3) << percentages[TranspositionTableFlags::Beta] << "%";
        ss << ", Exact: " << std::fixed << std::setprecision(3) << percentages[TranspositionTableFlags::Exact] << "%";
        ss << std::endl;
        std::cout << ss.str();
    }

    void Print()
    {
        auto entries = _entries.get();
        for (auto i = 0; i < 10000; i++)
        {
            auto& entry = entries[i];
            std::cout << entry.Key << std::endl;
        }
    }
};