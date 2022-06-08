#pragma once

#include "common.h"
#include "evaluation.h"
#include "search.h"
#include "movegen.h"

#include <random>

class Display
{
public:
    static void DisplayBoard(const BoardBase& board, const bool evalPieces = true)
    {
        std::stringstream ss;

        EachColor<Bitboard> pins;
        PinDetector::GetPinnedToKings(board, pins);
        const Score eval = Evaluation::Evaluate(board, pins);

        if(evalPieces)
        {
            BoardBase clone = board;

            auto checkers = CheckDetector::GetCheckers(clone);
            clone.WhiteToMove = !clone.WhiteToMove;
            clone.ColorToMove ^= 1;
            checkers |= CheckDetector::GetCheckers(clone);
            clone.WhiteToMove = !clone.WhiteToMove;
            clone.ColorToMove ^= 1;

            const std::string border = "+-------+-------+-------+-------+-------+-------+-------+-------+\n";
            for (auto rank = 7; rank >= 0; rank--)
            {
                ss << border;
                for (auto file = 0; file < 8; file++)
                {
                    const Position pos = static_cast<Position>(rank * 8 + file);
                    const Piece piece = board.ArrayBoard[pos];
                    const char pieceChar = Pieces::CharMap[piece];
                    ss << "|   " << pieceChar << "   ";
                }
                ss << "|\n";

                for (auto file = 0; file < 8; file++)
                {
                    const Position pos = static_cast<Position>(rank * 8 + file);
                    const Piece piece = board.ArrayBoard[pos];
                    if(piece > Pieces::Empty && piece < Pieces::King)
                    {
                        const Bitboard posBitboard = GetBitboard(pos);
                        const Color color = piece & Colors::Mask;
                        clone.ArrayBoard[pos] = Pieces::Empty;
                        clone.BitBoard[piece] &= ~posBitboard;
                        clone.BitBoard[color] &= ~posBitboard;
                        clone.AllPieces &= ~posBitboard;
                        clone.PieceCounts[piece]--;

                        EachColor<Bitboard> noPiecePins;
                        PinDetector::GetPinnedToKings(clone, noPiecePins);
                        const Score noPieceEval = Evaluation::Evaluate(clone, noPiecePins);
                        const Score difference = static_cast<Score>(noPieceEval - eval);
                        const Score flipped = board.WhiteToMove ? static_cast<Score>(-difference) : difference;
                        const std::string diffStr = std::to_string(flipped);
                        const auto padLeft = (7 - diffStr.size()) / 2;
                        const auto padRight = 7 - diffStr.size() - padLeft;

                        ss << "|";
                        for (auto i = 0; i < padLeft; i++)
                        {
                            ss << " ";
                        }
                        ss << diffStr;
                        for (auto i = 0; i < padRight; i++)
                        {
                            ss << " ";
                        }

                        clone.ArrayBoard[pos] = piece;
                        clone.BitBoard[piece] |= posBitboard;
                        clone.BitBoard[color] |= posBitboard;
                        clone.AllPieces |= posBitboard;
                        clone.PieceCounts[piece]++;
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
                    const Bitboard posBitboard = GetBitboard(pos);
                    const Piece piece = board.ArrayBoard[pos];
                    const Color color = piece & Colors::Mask;

                    ss << "|";
                    if(pins[color] & posBitboard)
                    {
                        ss << "PIN";
                    }
                    else
                    {
                        ss << "   ";
                    }
                    ss << " ";
                    if (checkers & posBitboard)
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
        ss << "Eval: " << eval << "\n";
        const PhaseScore phasedEval = Evaluation::EvaluatePhased(board, pins);
        const PhaseScore flippedPhasedEval = board.WhiteToMove ? static_cast<Score>(phasedEval) : -phasedEval;
        ss << "Midgame: " << MgScore(flippedPhasedEval) << "\n";
        ss << "Endgame: " << EgScore(flippedPhasedEval) << "\n";
        const int32_t phase = static_cast<int32_t>(GetPhase(board));
        ss << "Phase: " << phase << "\n";
        
        ss << "\n\n";
        std::cout << ss.str();
    }
};

class DataGenerator
{
public:
    enum class GameResult
    {
        Win,
        Draw,
        Loss
    };

    class GeneratedPosition
    {
    public:
        Fen FFen;
        Score SScore;
        GameResult Result;
    };

    class DataGeneratorThreadState
    {
            
    };

    static void OnCallback(SearchCallbackData& data)
    {
        const ThreadState& mainThreadState = data.State.Thread[0];
        std::stringstream builder = std::stringstream();

        builder << "info";
        builder << " depth " << std::to_string(data.Depth);
        builder << " multipv 1";
        builder << " score cp " << std::to_string(data._Score);
        builder << " nodes " << std::to_string(mainThreadState.Stats.Nodes);
        auto elapsed = mainThreadState.Stats.Elapsed;
        if (elapsed == 0)
        {
            elapsed = 1;
        }

        Stat nodes = 0;
        for (auto i = 0; i < Options::Threads; i++)
        {
            nodes += data.State.Thread[i].Stats.Nodes;
        }

        auto nps = (nodes * 1000) / elapsed;

        builder << " nps " << nps;
        builder << " time " << elapsed;

        builder << " pv";
        std::vector<Move>& principalVariation = data.State.Thread[data.Id].SavedPrincipalVariation;
        for (size_t ply = 0; ply < principalVariation.size(); ply++)
        {
            const auto& entry = principalVariation[ply];
            builder << " " << entry.ToPositionString();
        }

        std::cout << builder.str() << std::endl;
    }

    static void RunIteration(Search& search, std::mt19937& rng)
    {
        Board board = Board();
        Fens::Parse(board, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

        HistoryPly totalPly = 0;
        MoveArray moves;
        MoveCount moveCount;

        while (totalPly < 8)
        {
            moveCount = 0;
            MoveGenerator::GetAllPossibleMoves(board, moves, moveCount);
            auto dist = std::uniform_int_distribution<int32_t>(0, moveCount - 1);
            auto moveIndex = dist(rng);
            const Move move = moves[moveIndex];
            board.DoMove(move);
            totalPly++;
        }

        Display::DisplayBoard(board);

        SearchParameters parameters = SearchParameters();
        parameters.Infinite = true;
        //parameters.MaxDepth = 10;
        parameters.MaxNodesOnDepthIncrease = 5000;

        SearchResults results = SearchResults();
        search.Run(board, parameters, results);
    }

    static void Run()
    {
        Search search = Search(OnCallback);
        auto rng = std::mt19937(0);

        RunIteration(search, rng);
        //RunIteration(search, rng);
        //RunIteration(search, rng);
        //RunIteration(search, rng);
        //RunIteration(search, rng);
        //RunIteration(search, rng);
    }
};