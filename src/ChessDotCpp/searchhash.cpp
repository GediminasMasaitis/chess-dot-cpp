#include "searchhash.h"
#include "options.h"

#include <iostream>
#include <sstream>

size_t TranspositionTable::GetClampedSize(const size_t bytes)
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

void TranspositionTable::SetSize(const size_t bytes)
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

void TranspositionTable::SetSizeFromOptions()
{
    SetSize(Options::Hash * 1024 * 1024);
}

void TranspositionTable::Prefetch(const ZobristKey key) const
{
#if ENABLE_PREFETCH
    const size_t index = GetTableIndex(key);
    const auto ptr = reinterpret_cast<char*>(&_entries[index]);

#if defined(__INTEL_COMPILER) || defined(_MSC_VER)
    _mm_prefetch(ptr, _MM_HINT_T0);
#else 
    __builtin_prefetch(ptr);
#endif
#endif
}

void TranspositionTable::PrefetchForMove(const Board& board, const Move move) const
{
    KeyAnd50Move keyAnd50MoveAfterMove;
    board.GetKeyAfterMove(move, keyAnd50MoveAfterMove);
    Prefetch(keyAnd50MoveAfterMove.Key);
}

void TranspositionTable::Clear()
{
    const size_t bytesToClear = sizeof(TranspositionTableEntry) * _size;
    std::memset(_entries.get(), 0, bytesToClear);
}

void TranspositionTable::Store(const ZobristKey key, const Move move, const Ply depth, const Score score,
                               const TtFlag flag)
{
    const size_t index = GetTableIndex(key);
    const TranspositionTableEntry& existingEntry = _entries[index];

    if(existingEntry.Key != key || flag == TranspositionTableFlags::Exact || depth > existingEntry.Depth - 5)
    {
        const TranspositionTableEntry entry = TranspositionTableEntry(key, move, depth, score, flag);
        _entries[index] = entry;
    }
}

bool TranspositionTable::TryProbe(const ZobristKey key, TranspositionTableEntry* entry, ZobristKey* entryKey)
{
    const size_t index = GetTableIndex(key);

    *entry = _entries[index];
    const bool exists = entry->Flag != TranspositionTableFlags::None;
    *entryKey = entry->Key;
    return exists;
}

bool TranspositionTable::TryGetPvMove(const Board& board, Move& move)
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

    if(entry.MMove.Value == 0)
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

void TranspositionTable::GetPrincipalVariation(const Board& board, std::vector<Move>& principalVariation)
{
    Board clone = board;
    for (Ply i = 0; i <= Constants::MaxDepth; i++)
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

bool TranspositionTable::IsRootMoveChanged(const Board& board, const std::vector<Move>& savedPrincipalVariation)
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

void TranspositionTable::PrintOccupancy()
{
    const auto samples = 65536;
    const auto gapSize = _size / samples;
    std::array<int64_t, 4> counts{};
    for (size_t i = 0; i < _size; i += gapSize)
    {
        counts[_entries[i].Flag]++;
    }

    std::array<double, 4> percentages{};
    for(TtFlag flag = 0; flag < 4; flag++)
    {
        percentages[flag] = static_cast<double>(counts[flag] * 100) / static_cast<double>(samples);
    }

    auto ss = std::stringstream();
    ss << "None: " << std::fixed << std::setprecision(3) << percentages[TranspositionTableFlags::None] << "%";
    ss << ", Alpha: " << std::fixed << std::setprecision(3) << percentages[TranspositionTableFlags::Alpha] << "%";
    ss << ", Beta: " << std::fixed << std::setprecision(3) << percentages[TranspositionTableFlags::Beta] << "%";
    ss << ", Exact: " << std::fixed << std::setprecision(3) << percentages[TranspositionTableFlags::Exact] << "%";
    ss << std::endl;
    std::cout << ss.str();
}

void TranspositionTable::Print()
{
    auto entries = _entries.get();
    for (auto i = 0; i < 10000; i++)
    {
        auto& entry = entries[i];
        std::cout << entry.Key << std::endl;
    }
}
