#pragma once

#include "board.h"
#include "common.h"

class BoardWithOutcome
{
public:
    BoardBase Board;
    GameOutcome Outcome;
    Score SScore;
};

class Pgns
{
public:
    static void ParseSingle(std::istream& input, BoardBase& board)
    {

    }

    static void ParseMultiple(std::istream& input, std::vector<BoardBase>& boards)
    {
        std::string line = "[]";
        BoardWithOutcome result = BoardWithOutcome();
        result.Outcome = GameOutcome::Unknown;
        while (true)
        {
            //input >> word;
            if (!line.starts_with('['))
            {
                break;
            }
            if (line.starts_with("[Result"))
            {
                if(line == "[Result \"1 - 0\"]")
                {
                    result.Outcome = GameOutcome::Win;
                }
                else if(line == "[Result \"0 - 1\"]")
                {
                    result.Outcome = GameOutcome::Loss;
                }
                else
                {
                    result.Outcome = GameOutcome::Draw;
                }
            }

            std::getline(input, line);
        }
        auto ss = std::stringstream();
        while (true)
        {
            if (line.starts_with('['))
            {
                break;
            }

            if(line.empty())
            {
                continue;
            }
            
            ss << line;
            std::getline(input, line);
        }
        
    }
};