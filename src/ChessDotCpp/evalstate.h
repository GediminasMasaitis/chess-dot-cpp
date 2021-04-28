#pragma once

#include "common.h"

struct EvalHashTableEntry
{
public:
    ZobristKey Key;
    Score SScore;


    EvalHashTableEntry() = default;

    EvalHashTableEntry(const ZobristKey key, const Score score)
    {
        Key = key;
        SScore = score;
    }
};

class EvalHashTable
{
public:
    using TableEntries = std::unique_ptr<EvalHashTableEntry[]>;

    size_t _size = 0;
    TableEntries _entries = nullptr;

    [[nodiscard]] constexpr size_t GetTableIndex(ZobristKey key) const
    {
        const size_t index = key % _size;
        return index;
    }

    void SetSize(size_t bytes)
    {
        const size_t entrySize = sizeof(EvalHashTableEntry);
        const size_t newSize = bytes / entrySize;
        if (_size == newSize)
        {
            return;
        }

        _size = newSize;
        _entries = TableEntries(new EvalHashTableEntry[newSize]);
    }

    void Clear()
    {
        const size_t bytesToClear = sizeof(EvalHashTableEntry) * _size;
        std::memset(_entries.get(), 0, bytesToClear);
    }

    void Store(ZobristKey key, Score score)
    {
        const size_t index = GetTableIndex(key);
        const EvalHashTableEntry entry = EvalHashTableEntry(key, score);
        _entries[index] = entry;
    }

    bool TryProbe(ZobristKey key, Score& score)
    {
        const size_t index = GetTableIndex(key);
        const EvalHashTableEntry& entry = _entries[index];
        const bool success = entry.Key == key;
        score = entry.SScore;
        return success;
    }
};

class EvalState
{
public:
    EvalHashTable EvalTable;

    EvalState()
    {
        EvalTable = EvalHashTable();
    }
};