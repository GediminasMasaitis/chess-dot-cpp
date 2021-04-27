#pragma once

#include "search.h"
#include "debug.h"

#include <iostream>
#include <sstream>


class Uci
{
public:
    static inline std::string startPos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    using InType = std::function<std::string()>;
    using OutType = std::function<void(std::string)>;
    
    InType& In;
    OutType& Out;

    Board board;
    Search search;
    
    Uci(InType& in, OutType& out) : In(in), Out(out), search([&](SearchCallbackData& data) { OnCallback(data); })
    {
    }

    void OnCallback(SearchCallbackData& data) const
    {
        std::stringstream builder = std::stringstream();

        builder << "info";
        builder << " depth " << std::to_string(data.Depth);
        builder << " multipv 1";
        builder << " score cp " << std::to_string(data._Score);
        builder << " nodes " << std::to_string(data.State.Stats.Nodes);
        auto elapsed = data.State.Stopper.GetElapsed();
        if(elapsed == 0)
        {
            elapsed = 1;
        }
        auto nps = (data.State.Stats.Nodes * 1000) / elapsed;
        
        builder << " nps " << nps;
        builder << " time " << elapsed;

        builder << " pv";
        std::vector<Move>& principalVariation = data.State.Global.Table.SavedPrincipalVariation;
        for (size_t ply = 0; ply < principalVariation.size(); ply++)
        {
            const auto& entry = principalVariation[ply];
            builder << " " << entry.ToPositionString();
        }
        
        Out(builder.str());

        auto pv2 = std::vector<Move>();
        search.State.Global.Table.GetPrincipalVariation(board, pv2);
    	
        //if (principalVariation.empty())
        //{
        //    auto a = 123;
        //    //Debug::SaveTt(data.State);
        //    //Throw();
        //}
    }

    void HandleMoves(std::stringstream& reader)
    {
        while (!reader.eof())
        {
            MoveString moveStr;
            reader >> moveStr;

            board.DoMove(moveStr);
        }
    }

    void HandleStartpos(std::stringstream& reader)
    {
        Fens::Parse(board, startPos);
        if (!reader.eof())
        {
            std::string type;
            reader >> type;

            if (type == "moves")
            {
                HandleMoves(reader);
            }
        }
    }

    void HandleFen(std::stringstream& reader)
    {
        std::string fen;
        reader >> fen;

        Fens::Parse(board, fen);

        if(!reader.eof())
        {
            std::string type;
            reader >> type;

            if(type == "moves")
            {
                HandleMoves(reader);
            }
        }
    }
    
    void HandlePosition(std::stringstream& reader)
    {
        std::string type;
        reader >> type;

        if(type == "startpos")
        {
            HandleStartpos(reader);
        }
        else if(type == "moves")
        {
            Fens::Parse(board, startPos);
            HandleMoves(reader);
        }
        else if(type == "fen")
        {
            HandleFen(reader);
        }
    }

    void HandleGo(std::stringstream& reader)
    {
        //search.State.Global.Table.Print();
        
        //Debug::StoreTt(search.State);
        
        SearchParameters parameters = SearchParameters();
        while(!reader.eof())
        {
            std::string word;
            reader >> word;

            if(word == "wtime")
            {
                reader >> parameters.WhiteTime;
            }
            else if(word == "btime")
            {
                reader >> parameters.BlackTime;
            }
            else if (word == "winc")
            {
                reader >> parameters.WhiteTimeIncrement;
            }
            else if (word == "binc")
            {
                reader >> parameters.BlackTimeIncrement;
            }
            else if (word == "infinite")
            {
                parameters.Infinite = true;
            }
        }
        
        const Move move = search.Run(board, parameters);
        const Move move2 = search.State.Global.Table.SavedPrincipalVariation[0];
        Out("bestmove " + move2.ToPositionString());
    }

    void HandleUci(std::stringstream& reader)
    {
        Out("id name ChessDotCpp");
        Out("id author Gediminas Masaitis");
        Out("");
        Out("uciok");
    }

    void HandleIsReady(std::stringstream& reader)
    {
        Out("readyok");
    }

    void HandleUciNewGame(std::stringstream& reader)
    {
        search.State.NewGame();
        //Debug::LoadTt("C:/Temp/tt/tt1619555771084.dat", search.State);
    }

    void HandleInput(const std::string& line)
    {
        std::stringstream reader(line);

        while (!reader.eof())
        {
            std::string word;
            reader >> word;

            if(word == "position")
            {
                HandlePosition(reader);
            }
            else if(word == "go")
            {
                HandleGo(reader);
            }
            else if(word == "uci")
            {
                HandleUci(reader);
            }
            else if(word == "ucinewgame")
            {
                HandleUciNewGame(reader);
            }
            else if(word == "isready")
            {
                HandleIsReady(reader);
            }
        }
    }
    
    void Run()
    {
        while (true)
        {
            std::string line = In();
            HandleInput(line);
        }
    }
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