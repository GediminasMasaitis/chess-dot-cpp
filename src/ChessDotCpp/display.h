#pragma once

#include "common.h"
#include "fen.h"
#include "evaluation.h"

class DisplayPositionData
{
public:
    Score EvalDiff;
    Score SearchDiff;
    bool GivesCheck;
    bool Pinned;

    DisplayPositionData()
    {
        EvalDiff = 0;
        SearchDiff = 0;

        GivesCheck = false;
        Pinned = false;
    }
};

using DisplayPositionDataArray = EachPosition<DisplayPositionData>;

class DisplayData
{
public:
    bool HasEvalData;
    bool HasSearchData;
    Score EvalScore;
    Score SearchScore;
    DisplayPositionDataArray Positions;

    DisplayData()
    {
        HasEvalData = false;
        HasSearchData = false;
        EvalScore = 0;
        SearchScore = 0;
        Positions = DisplayPositionDataArray{};
    }
};

class Display
{
public:
    using DisplayEvaluation = EvaluationNnue2;//EvaluationClassical2;

    static void DisplayBoard(const BoardBase& board, const std::optional<Move> optMove , const DisplayData& data)
    {
        std::stringstream ss;

        if (data.HasEvalData)
        {
            const std::string border = "+-------+-------+-------+-------+-------+-------+-------+-------+\n";
            for (auto rank = 7; rank >= 0; rank--)
            {
                ss << border;
                for (auto file = 0; file < 8; file++)
                {
                    const Position pos = static_cast<Position>(rank * 8 + file);
                    const Piece piece = board.ArrayBoard[pos];
                    const char pieceChar = Pieces::CharMap[piece];
                    if(optMove.has_value() && optMove.value().GetFrom() == pos)
                    {
                        ss << "|FR " << pieceChar << " FR";
                    }
                    else if(optMove.has_value() && optMove.value().GetTo() == pos)
                    {
                        ss << "|TO " << pieceChar << " TO";
                    }
                    else
                    {
                        ss << "|   " << pieceChar << "   ";
                    }
                    
                }
                ss << "|\n";

                for (auto file = 0; file < 8; file++)
                {
                    const Position pos = static_cast<Position>(rank * 8 + file);
                    const DisplayPositionData& posData = data.Positions[pos];
                    const Piece piece = board.ArrayBoard[pos];
                    if (piece > Pieces::Empty && piece < Pieces::Count)
                    {
                        const Score diff = data.HasSearchData ? posData.SearchDiff : posData.EvalDiff;
                        const std::string diffStr = std::to_string(diff);
                        const auto padLeft = static_cast<int32_t>((7 - diffStr.size()) / 2);
                        const auto padRight = static_cast<int32_t>(7 - diffStr.size() - padLeft);

                        ss << "|";
                        for (int32_t i = 0; i < padLeft; i++)
                        {
                            ss << " ";
                        }
                        ss << diffStr;
                        for (int32_t i = 0; i < padRight; i++)
                        {
                            ss << " ";
                        }
                    }
                    else
                    {
                        ss << "|       ";
                    }
                }
                ss << "| " << (rank + 1) << "\n";
                for (auto file = 0; file < 8; file++)
                {
                    const Position pos = static_cast<Position>(rank * 8 + file);
                    const DisplayPositionData& posData = data.Positions[pos];

                    ss << "|";
                    if (posData.Pinned)
                    {
                        ss << "PIN";
                    }
                    else
                    {
                        ss << "   ";
                    }
                    ss << " ";
                    if (posData.GivesCheck)
                    {
                        ss << "CHK";
                    }
                    else
                    {
                        ss << "   ";
                    }
                }

                ss << "|\n";
            }
            ss << border << "";
            for (auto file = 0; file < 8; file++)
            {
                ss << "    " << static_cast<char>('A' + file) << "   ";
            }
            ss << "\n";
        }
        else
        {
            const std::string border = "+---+---+---+---+---+---+---+---+\n";
            for (auto rank = 7; rank >= 0; rank--)
            {
                ss << border;
                for (auto file = 0; file < 8; file++)
                {
                    const Position pos = static_cast<Position>(rank * 8 + file);
                    const Piece piece = board.ArrayBoard[pos];
                    const char pieceChar = Pieces::CharMap[piece];
                    ss << "| " << pieceChar << " ";
                }
                ss << "|\n";
            }
            ss << border << "";
        }

        const Fen fen = Fens::Serialize(board);
        ss << "Side: " << (board.WhiteToMove ? "White" : "Black") << "\n";
        ss << "FEN: " << fen << "\n";
        ss << "Key: " << board.Key << "\n";
        if(data.HasEvalData)
        {
            ss << "Eval: " << data.EvalScore << "\n";
        }
        if(data.HasSearchData)
        {
            ss << "Search: " << data.SearchScore << "\n";
        }
        //const PhaseScore phasedEval = DisplayEvaluation::EvaluatePhased(board, pins);
        //const PhaseScore flippedPhasedEval = phasedEval;//board.WhiteToMove ? static_cast<Score>(phasedEval) : -phasedEval;
        //ss << "Midgame: " << MgScore(flippedPhasedEval) << "\n";
        //ss << "Endgame: " << EgScore(flippedPhasedEval) << "\n";
        const int32_t phase = static_cast<int32_t>(GetPhase(board));
        ss << "Phase: " << phase << "\n";
        ss << "\n";
        if(optMove.has_value())
        {
            const auto moveDebugStr = optMove.value().ToDebugString();
            ss << moveDebugStr << "\n";
        }
        ss << "\n";
        std::cout << ss.str();
    }
};