#pragma once

#include "common.h"
#include "evaluation.h"
#include "search.h"
#include "movegen.h"

#include <random>
#include <thread>
#include <mutex>
#include <fstream>
#include <filesystem>
#include <algorithm>

class Display
{
public:
    using DisplayEvaluation = EvaluationNnue2;//EvaluationClassical2;

    static void DisplayBoard(const BoardBase& board, const bool evalPieces = true)
    {
        std::stringstream ss;

        EachColor<Bitboard> pins;
        PinDetector::GetPinnedToKings(board, pins);
        Score eval = DisplayEvaluation::Evaluate(board, pins);
        eval = board.WhiteToMove ? eval : -eval;

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
                        clone.UnsetPiece(pos, piece);

                        EachColor<Bitboard> noPiecePins;
                        PinDetector::GetPinnedToKings(clone, noPiecePins);
                        Score noPieceEval = DisplayEvaluation::Evaluate(clone, noPiecePins);
                        noPieceEval = board.WhiteToMove ? noPieceEval : -noPieceEval;
                        const Score difference = static_cast<Score>(eval - noPieceEval);
                        const std::string diffStr = std::to_string(difference);
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
                        clone.SetPiece(pos, piece);
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
        //const PhaseScore phasedEval = DisplayEvaluation::EvaluatePhased(board, pins);
        //const PhaseScore flippedPhasedEval = phasedEval;//board.WhiteToMove ? static_cast<Score>(phasedEval) : -phasedEval;
        //ss << "Midgame: " << MgScore(flippedPhasedEval) << "\n";
        //ss << "Endgame: " << EgScore(flippedPhasedEval) << "\n";
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
        None,
        Win,
        Draw,
        Loss
    };

    class DataEntry
    {
    public:
        Fen FFen;
        Score SScore;
        GameResult Result;
        ZobristKey Key;
        bool IncludeInDataset;
    };
    using DataEntries = std::vector<DataEntry>;

    class DataGeneratorThreadState
    {
            
    };

    static void OnCallback(SearchCallbackData& data)
    {
        //const ThreadState& mainThreadState = data.State.Thread[0];
        //std::stringstream builder = std::stringstream();

        //builder << "info";
        //builder << " depth " << std::to_string(data.Depth);
        //builder << " multipv 1";
        //builder << " score cp " << std::to_string(data._Score);
        //builder << " nodes " << std::to_string(mainThreadState.Stats.Nodes);
        //auto elapsed = mainThreadState.Stats.Elapsed;
        //if (elapsed == 0)
        //{
        //    elapsed = 1;
        //}

        //Stat nodes = 0;
        //for (auto i = 0; i < Options::Threads; i++)
        //{
        //    nodes += data.State.Thread[i].Stats.Nodes;
        //}

        //auto nps = (nodes * 1000) / elapsed;

        //builder << " nps " << nps;
        //builder << " time " << elapsed;

        //builder << " pv";
        //std::vector<Move>& principalVariation = data.State.Thread[data.Id].SavedPrincipalVariation;
        //for (size_t ply = 0; ply < principalVariation.size(); ply++)
        //{
        //    const auto& entry = principalVariation[ply];
        //    builder << " " << entry.ToPositionString();
        //}

        //std::cout << builder.str() << std::endl;
    }

    static GameResult AdjudicateMates(Board& board)
    {
        MoveCount moveCount = 0;
        MoveArray moves;
        Bitboard checkers = CheckDetector::GetCheckers(board);
        const bool inCheck = checkers != 0;
        EachColor<Bitboard> pins;
        PinDetector::GetPinnedToKings(board, pins);
        const Bitboard pinned = pins[board.ColorToMove];
        MoveGenerator::GetAllPotentialMoves(board, checkers, pinned, moves, moveCount);
        bool hasValidMove = false;
        for (MoveCount moveIndex = 0; moveIndex < moveCount; moveIndex++)
        {
            const bool isValid = MoveValidator::IsKingSafeAfterMove2(board, moves[moveIndex], checkers, pinned);
            if (isValid)
            {
                hasValidMove = true;
                break;
            }
        }

        if (!hasValidMove)
        {
            if (inCheck)
            {
                if (board.WhiteToMove)
                {
                    return GameResult::Loss;
                }
                return GameResult::Win;
            }
            return GameResult::Draw;
        }

        return GameResult::None;
    }

    static GameResult Adjudicate(Board& board, DataEntries& entries, DataEntry& currentEntry)
    {
        constexpr Score drawishScore = 8;
        constexpr Score winishScore = 1500;
        constexpr Score loseishScore = -1500;

        constexpr auto drawishLimit = 8;
        constexpr auto winishLimit = 4;
        constexpr auto loseishLimit = 4;

        if(entries.size() >= 300)
        {
            return GameResult::Draw;
        }

        auto drawish = std::abs(currentEntry.SScore) < drawishScore ? 1 : 0;
        auto winish = currentEntry.SScore > winishScore ? 1 : 0;
        auto loseish = currentEntry.SScore < loseishScore ? 1 : 0;
        for(auto i = static_cast<int32_t>(entries.size()) - 1; i >= 0; i--)
        {
            const auto& entry = entries[i];

            if(entry.Key == currentEntry.Key)
            {
                return GameResult::Draw;
            }

            if(std::abs(entry.SScore) < drawishScore)
            {
                drawish++;
            }
            else
            {
                drawish = 0;
            }

            if (entry.SScore > winishScore)
            {
                winish++;
            }
            else
            {
                winish = 0;
            }

            if (entry.SScore < loseishScore)
            {
                loseish++;
            }
            else
            {
                loseish = 0;
            }

            if(drawish > drawishLimit)
            {
                return GameResult::Draw;
            }
            if(winish > winishLimit)
            {
                return GameResult::Win;
            }
            if(loseish > loseishLimit)
            {
                return GameResult::Loss;
            }
        }

        // MATE AND STALEMATE
        auto mateAdjudication = AdjudicateMates(board);
        return mateAdjudication;
    }

    static bool ShouldIncludeInDataset(const Board& board, const DataEntries& entries, const DataEntry& currentEntry, const Move& move)
    {
        constexpr Score scoreLimit = 2000;
        //constexpr Score scoreLimit = Constants::MateThreshold;
        if(std::abs(currentEntry.SScore) > scoreLimit)
        {
            return false;
        }

        const Piece takesPiece = move.GetTakesPiece();
        if(takesPiece != Pieces::Empty)
        {
            return false;
        }

        EachColor<Bitboard> checkers;
        CheckDetector::GetCheckers(board, checkers);
        const Bitboard allCheckers = checkers[Colors::White] | checkers[Colors::Black];
        if(allCheckers != 0)
        {
            return false;
        }

        return true;
    }

    static GameResult RunIteration(Search& search, std::mt19937& rng, std::vector<DataEntry>& data)
    {
        search.State.NewGame();
        Board board = Board();
        Fens::Parse(board, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

        auto iterationData = DataEntries();

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

            auto initialResult = AdjudicateMates(board);
            if (initialResult != GameResult::None)
            {
                return GameResult::None;
            }
        }

        SearchParameters parameters = SearchParameters();
        parameters.Infinite = true;
        parameters.MinNodes = 5000;
        //parameters.MaxNodes = 10000;
        GameResult result;
        while (true)
        //for (auto i = 0; i < 30; i++)
        {
            SearchResults results = SearchResults();
            search.Run(board, parameters, results);

            const Score score = board.WhiteToMove ? results.SScore : static_cast<Score>(-results.SScore);

            //std::cout << "Score: " << score << std::endl;
            //Display::DisplayBoard(board);

            auto entry = DataEntry();
            entry.FFen = Fens::Serialize(board);
            entry.SScore = score;
            entry.Key = board.Key;
            entry.IncludeInDataset = ShouldIncludeInDataset(board, iterationData, entry, results.BestMove);

            if(totalPly < 16)
            {
                board.DoMove(results.BestMove);
                totalPly++;

                result = Adjudicate(board, iterationData, entry);
                if (result != GameResult::None)
                {
                    return GameResult::None;
                }

                continue;
            }
            
            board.DoMove(results.BestMove);
            totalPly++;
            result = Adjudicate(board, iterationData, entry);
            if(result != GameResult::None)
            {
                for (DataEntry& iterationEntry : iterationData)
                {
                    if(iterationEntry.IncludeInDataset)
                    {
                        iterationEntry.Result = result;
                        data.push_back(iterationEntry);
                    }
                }
                break;
            }

            iterationData.push_back(entry);
        }

        const auto a = 123;
        return result;
    }

    using IterationCallback = std::function<void(DataEntries& iterationData, GameResult result)>;

    static void RunThread(const ThreadId threadId, const IterationCallback& callback)
    {
        Search search = Search(OnCallback);
        auto rng = std::mt19937(threadId * 256);
        auto data = std::vector<DataEntry>();


        while (true)
        {
            auto result = RunIteration(search, rng, data);
            if(result == GameResult::None)
            {
                continue;
            }

            callback(data, result);
        }
    }

    static void WriteResults(DataEntries& entries)
    {
        std::stringstream ss;
        const auto size = static_cast<int32_t>(entries.size());
        //const auto size = 725000;
        // r2qkbnr/pppbppp1/2n5/3p3p/5P2/1P2P1P1/P1PP3P/RNBQKBNR w KQkq -
        // r1b1k1r1/p2npp1p/2pp1n1R/qp6/3PP3/5N2/PPPN1PP1/R2QKB2 b Qq - c9 "1/2-1/2";
        //for(auto& entry : entries)

        //for(auto entryId = 0; entryId < size; entryId++)
        //{
        //    const auto& entry = entries[entryId];
        //    ss << entry.FFen << " c9 \"";
        //    switch (entry.Result)
        //    {
        //    case GameResult::Win:
        //        ss << "1-0";
        //        break;
        //    case GameResult::Draw:
        //        ss << "1/2-1/2";
        //        break;
        //    case GameResult::Loss:
        //        ss << "0-1";
        //        break;
        //    case GameResult::None:
        //        Throw();
        //        break;
        //    }
        //    ss << "\";";
        //    //if(entryId != size - 1)
        //    //{
        //        ss << "\n";
        //    //}
        //}

        for (auto entryId = 0; entryId < size; entryId++)
        {
            const auto& entry = entries[entryId];
            ss << entry.FFen << " 0 0 \[";
            switch (entry.Result)
            {
            case GameResult::Win:
                ss << "1.0";
                break;
            case GameResult::Draw:
                ss << "0.5";
                break;
            case GameResult::Loss:
                ss << "0.0";
                break;
            case GameResult::None:
                Throw();
                break;
            }
            ss << "] ";
            ss << entry.SScore;
            //if(entryId != size - 1)
            //{
                ss << "\n";
            //}
        }

        auto file = std::ofstream("C:/Chess/Datasets/cdcpp/data.fen", std::ofstream::out | std::ofstream::app);
        file << ss.str();
        file.flush();
    }

    static void Run()
    {
        constexpr ThreadId threadCount = 16;
        auto threads = std::vector<std::thread>(threadCount);
        auto mutex = std::mutex();
        auto data = DataEntries();
        auto results = std::vector<GameResult>();
        const auto trainStart = std::chrono::high_resolution_clock::now();
        auto wins = 0;
        auto draws = 0;
        auto losses = 0;
        auto games = 0;
        auto positions = 0;
        const IterationCallback callback = [&wins, &losses, &draws, &games, &positions, &data, &results, &mutex](DataEntries& threadData, GameResult result)
        {
            auto lock = std::unique_lock<std::mutex>(mutex);
            if (result == GameResult::Win)
            {
                wins++;
            }
            else if (result == GameResult::Draw)
            {
                draws++;
            }
            else if (result == GameResult::Loss)
            {
                losses++;
            }
            else
            {
                Throw();
            }
            games++;
            positions += static_cast<int32_t>(threadData.size());

            for(auto& entry : threadData)
            {
                data.push_back(entry);
            }
            threadData.clear();
            results.push_back(result);
        };

        for (ThreadId threadId = 0; threadId < threadCount; threadId++)
        {
            threads.emplace_back([threadId, &callback]()
            {
                RunThread(threadId, callback);
            });
        }

        while(true)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

            auto lock = std::unique_lock<std::mutex>(mutex);

            const auto now = std::chrono::high_resolution_clock::now();
            const auto elapsed = now - trainStart;
            const auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(elapsed);
            const auto humanReadableDuration = HumanReadableDuration(elapsedSeconds);
            auto elapsedSecondCount = static_cast<int32_t>(elapsedSeconds.count());
            if (elapsedSecondCount == 0)
            {
                elapsedSecondCount = 1;
            }

            auto winPercent = (static_cast<double>(wins) / games) * 100;
            auto drawPercent = (static_cast<double>(draws) / games) * 100;
            auto lossPercent = (static_cast<double>(losses) / games) * 100;
            const auto pps = static_cast<double>(positions) / elapsedSecondCount;
            const auto ppsInt = static_cast<size_t>(pps);

            std::stringstream ss = std::stringstream();
            ss << "[" << humanReadableDuration << "]";
            ss << " Games: " << std::right << std::setw(4) << games;
            ss << " Positions: " << std::right << std::setw(9) << positions;
            ss << " (" << std::right << std::setw(3) << ppsInt << " PPS)";
            ss << " Wins: " << std::fixed << std::setprecision(3) << winPercent << "%,";
            ss << " Draws: " << std::fixed << std::setprecision(3) << drawPercent << "%,";
            ss << " Losses: " << std::fixed << std::setprecision(3) << lossPercent << "%";
            ss << std::endl;
            const auto log = ss.str();
            std::cout << log;

            //if(data.size() >= 10000)
            {
                //auto shuffeRng = std::default_random_engine(0);
                //std::shuffle(data.begin(), data.end(), shuffeRng);
                WriteResults(data);
                data.clear();
                //return;
            }
        }
    }
};