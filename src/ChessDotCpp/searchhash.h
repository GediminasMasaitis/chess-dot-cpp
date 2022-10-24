#pragma once

#include "board.h"

#define ENABLE_PREFETCH 1
#if ENABLE_PREFETCH
#include <xmmintrin.h>
#endif

class TranspositionTableFlags
{
public:
    static constexpr TtFlag None = 0;
    static constexpr TtFlag Alpha = 1;
    static constexpr TtFlag Beta = 2;
    static constexpr TtFlag Exact = 3;

    TranspositionTableFlags() = delete;
};

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

class TranspositionTable
{
public:
    using TableEntries = std::unique_ptr<TranspositionTableEntry[]>;

    size_t _size = 0;
    size_t _mask = 0;
    TableEntries _entries = nullptr;

    static size_t GetClampedSize(const size_t bytes);

    [[nodiscard]] constexpr size_t GetTableIndex(ZobristKey key) const
    {
        const size_t index = key & _mask;
        return index;
    }

    static constexpr ZobristKey RestoreKey(const ZobristKey partialKey, const size_t index)
    {
        return partialKey | (index & 0xFFFFULL);
    }

    void SetSize(const size_t bytes);
    void SetSizeFromOptions();
    void Prefetch(const ZobristKey key) const;
    void PrefetchForMove(const Board& board, const Move move) const;
    void Clear();
    void Store(const ZobristKey key, const Move move, const Ply depth, const Score score, const TtFlag flag);
    bool TryProbe(const ZobristKey key, TranspositionTableEntry* entry, ZobristKey* entryKey);
    bool TryGetPvMove(const Board& board, Move& move);
    void GetPrincipalVariation(const Board& board, std::vector<Move>& principalVariation);
    bool IsRootMoveChanged(const Board& board, const std::vector<Move>& savedPrincipalVariation);
    void PrintOccupancy();
    void Print();
};