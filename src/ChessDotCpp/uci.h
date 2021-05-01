#pragma once

#include "search.h"
#include "fen.h"

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
        std::stringstream fenBuilder;
        bool hasMoves = false;
    	while(!reader.eof())
    	{
            std::string fenPart;
            reader >> fenPart;
    		if(fenPart == "moves")
    		{
                hasMoves = true;
                break;
    		}
            fenBuilder << fenPart << " ";
    	}
        
        std::string fen = fenBuilder.str();
        Fens::Parse(board, fen);

        if(hasMoves)
        {
            HandleMoves(reader);
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
        
        search.Run(board, parameters);
        const Move move = search.State.Global.Table.SavedPrincipalVariation[0];
        Out("bestmove " + move.ToPositionString());
    }

    void HandleUci()
    {
        Out("id name ChessDotCpp");
        Out("id author Gediminas Masaitis");
        Out("");
        Out("uciok");
    }

    void HandleIsReady()
    {
        Out("readyok");
    }

    void HandleUciNewGame()
    {
        search.State.NewGame();
    }

    bool HandleInput(const std::string& line)
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
                HandleUci();
            }
            else if(word == "ucinewgame")
            {
                HandleUciNewGame();
            }
            else if(word == "isready")
            {
                HandleIsReady();
            }
            else if(word == "quit")
            {
                return false;
            }
        }
    	
        return true;
    }
    
    void Run()
    {
        while (true)
        {
            std::string line = In();
            const bool shouldContinue = HandleInput(line);
        	if(!shouldContinue)
        	{
                break;
        	}
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