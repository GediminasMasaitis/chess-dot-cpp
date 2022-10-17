#pragma once

#include "search.h"
#include "fen.h"

#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>

class Uci
{
public:
    static inline Fen StartingFen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    using InType = std::function<std::string()>;
    using OutType = std::function<void(std::string)>;
    
    InType& In;
    OutType& Out;

    Board board;
    Search search;
    std::thread SearchThread;
    bool IsSearching;
    std::mutex SearchMutex;
    
    Uci(InType& in, OutType& out) : In(in), Out(out), search([&](SearchCallbackData& data) { OnCallback(data); })
    {
    }

    void OnCallback(SearchCallbackData& data) const;
    void HandleMoves(std::stringstream& reader);
    void HandleStartpos(std::stringstream& reader);
    void HandleFen(std::stringstream& reader);
    void HandlePosition(std::stringstream& reader);
    void ReadMoves(std::stringstream& reader, MoveArray& moves, MoveCount& moveCount, bool doMoves, bool undoMoves);
    void ReadSearchParameters(std::stringstream& reader, SearchParameters& parameters);
    void HandleGo(std::stringstream& reader);
    void HandleStop();
    void HandlePerft(std::stringstream& reader);
    void PrintOptions();
    void HandleUci();
    void HandleIsReady();
    void HandleUciNewGame();
    void HandleDisplaySearch(std::stringstream& reader);
    void HandleDisplayMoves(std::stringstream& reader);
    void HandleSetoption(std::stringstream& reader);
    bool HandleInput(const std::string& line);
    void Init();
    void Run();
};

class UciStd : public Uci
{
public:
    InType StdIn = []()
    {
        std::string command;
        std::getline(std::cin, command);
        return command;
    };

    OutType StdOut = [](std::string str)
    {
        std::cout << str << std::endl;
    };
    
    UciStd() : Uci(StdIn, StdOut)
    {
        
    }
};