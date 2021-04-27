#pragma once
#include "searchstate.h"

#include <chrono>

class Debug
{
public:

    static inline TranspositionTableEntry StoredTt[699050];

    static void StoreTt(const SearchState& state)
    {
        std::memcpy(StoredTt, state.Global.Table._entries.get(), 699050 * sizeof(TranspositionTableEntry));
    }
    
    static void SaveTt(const SearchState& state)
    {
        const auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        const auto filename = std::string("C:/Temp/tt/tt") + std::to_string(timestamp) + ".dat";
        auto file = std::fopen(filename.c_str(), "w");
        //auto data = state.Global.Table._entries.get();
        auto length = state.Global.Table._size;
        std::fwrite(StoredTt, sizeof(TranspositionTableEntry), length, file);
        std::fclose(file);
    }

    static void LoadTt(const std::string& path, SearchState& state)
    {
        auto file = std::fopen(path.c_str(), "r");
        auto data = state.Global.Table._entries.get();
        auto length = state.Global.Table._size;
        std::fread(data, sizeof(TranspositionTableEntry), length, file);
        std::fclose(file);
    }
};
