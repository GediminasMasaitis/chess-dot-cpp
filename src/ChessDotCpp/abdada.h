#pragma once

#include "common.h"

//#define ABDADA 1

#if ABDADA
constexpr bool UseAbdada = true;
#else
constexpr bool UseAbdada = false;
#endif


class AbdadaTable
{
public:
    using Way = size_t;
    using TableIndex = size_t;

    static constexpr TableIndex TableSize = 32768;
    static constexpr Way TableWays = 4;
    static constexpr Ply DeferDepth = 3;


    using TableType = std::array<std::array<AbdadaMoveKey, TableWays>, TableSize>;

    std::unique_ptr<TableType> Table;

    AbdadaTable()
    {
        Table = std::make_unique<TableType>();
    }

    constexpr static AbdadaMoveKey GetMoveHash(const ZobristKey key, const MoveValue move)
    {
        return key ^ ((move * 1664525) + 1013904223);
    }

    constexpr static TableIndex GetIndex(const AbdadaMoveKey moveKey)
    {
        return moveKey & (TableSize - 1);
    }

    bool DeferMove(const AbdadaMoveKey moveKey, const Ply depth)
    {
        if (depth < DeferDepth)
        {
            return false;
        }

        const TableIndex index = GetIndex(moveKey);

        for (Way way = 0; way < TableWays; way++)
        {
            if ((*Table)[index][way] == moveKey)
            {
                return true;
            }
        }
        return false;
    }

    void StartingSearch(const AbdadaMoveKey moveKey, const Ply depth)
    {
        if (depth < DeferDepth)
        {
            return;
        }

        const TableIndex index = GetIndex(moveKey);

        for (Way way = 0; way < TableWays; way++)
        {
            if ((*Table)[index][way] == 0)
            {
                (*Table)[index][way] = moveKey;
                return;
            }

            if ((*Table)[index][way] == moveKey)
            {
                return;
            }
        }
        (*Table)[index][0] = moveKey;
    }

    void FinishedSearch(const AbdadaMoveKey moveKey, int depth)
    {
        if (depth < DeferDepth)
        {
            return;
        }

        const TableIndex index = GetIndex(moveKey);

        for (Way way = 0; way < TableWays; way++)
        {
            if ((*Table)[index][way] == moveKey)
            {
                (*Table)[index][way] = 0;
            }
        }
    }

    void NewSearch()
    {
        for (TableIndex i = 0; i < TableSize; i++)
        {
            for (Way j = 0; j < TableWays; j++)
            {
                (*Table)[i][j] = 0;
            }
        }
    }
};