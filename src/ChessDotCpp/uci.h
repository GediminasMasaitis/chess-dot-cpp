#pragma once

#include "search.h"

#include <iostream>
#include <sstream>

class Uci
{
public:
    static inline std::string startPos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    
    std::istream* In;
    std::ostream* Out;

    Board board;
    
    Uci(std::istream* in, std::ostream* out) : In(in), Out(out)
    {
        
    }

    void OnCallback(SearchCallbackData& data) const
    {	
        std::vector<Move>& principalVariation = data.Data.Global.Table.SavedPrincipalVariation;
        
        std::stringstream builder = std::stringstream();

        builder << "info";
        builder << " depth " << std::to_string(data.Depth);
        builder << " multipv 1";
        builder << " score cp " << std::to_string(data._Score);
        builder << " nodes " << std::to_string(data.Data.Stats.Nodes);
        builder << " nps 0";
        builder << " time 0";

        builder << " pv";
        for (size_t ply = 0; ply < principalVariation.size(); ply++)
        {
            const auto& entry = principalVariation[ply];
            builder << " " << entry.ToPositionString();
        }
            
        *Out << builder.str() << std::endl;
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
        
        const Move move = Search::Run(board, parameters, [&](SearchCallbackData& data) { OnCallback(data); });
        *Out << "bestmove " << move.ToPositionString() << std::endl;
    }

    void HandleUci(std::stringstream& reader)
    {
        *Out << "id name ChessDotCpp" << std::endl;
        *Out << "id author Gediminas Masaitis" << std::endl;
        *Out << std::endl;
        *Out << "uciok" << std::endl;
    }

    void HandleIsReady(std::stringstream& reader)
    {
        *Out << "readyok" << std::endl;
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
            std::string line;
            std::getline(*In, line);
            HandleInput(line);
        }
    }
};