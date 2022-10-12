#pragma once

#include "evalbase.h"
#include "attacks.h"
#include "common.h"
#include "search.h"
#include "movegen.h"
#include "tablebases.h"

#include <random>
#include <thread>
#include <mutex>
#include <fstream>
#include <filesystem>

class DataGenerator
{
public:
    static constexpr ThreadId ThreadCount = 1;

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

    static void OnCallback(const SearchCallbackData& data)
    {
        (void)data;
    }

    static GameResult AdjudicateMates(Board& board)
    {
        MoveCount moveCount = 0;
        MoveArray moves;
        const Bitboard checkers = CheckDetector::GetCheckers(board);
        const bool inCheck = checkers != 0;
        EachColor<Bitboard> pins;
        PinDetector::GetPinnedToKings(board, pins);
        const Bitboard pinned = pins[board.ColorToMove];
        MoveGenerator::GetAllPotentialMoves(board, checkers, pinned, moves, moveCount);
        bool hasValidMove = false;
        for (MoveCount moveIndex = 0; moveIndex < moveCount; moveIndex++)
        {
            const bool isValid = MoveValidator::IsKingSafeAfterMove2(board, moves[moveIndex], pinned);
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

    static bool ShouldIncludeInDataset(const Board& board, const DataEntry& currentEntry, const Move& move)
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
        auto threadStateBackup = search.State.Thread;
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
        parameters.UciThread = true;
        //parameters.MaxNodes = 10000;
        GameResult result;
        while (true)
        //for (auto i = 0; i < 30; i++)
        {
            SearchResults results = SearchResults();
            search.Run(board, parameters, results);
            std::swap(search.State.Thread, threadStateBackup);

            const Score score = board.WhiteToMove ? results.SScore : static_cast<Score>(-results.SScore);

            //std::cout << "Score: " << score << std::endl;
            //Display::DisplayBoard(board);

            auto entry = DataEntry();
            entry.FFen = Fens::Serialize(board);
            entry.SScore = score;
            entry.Key = board.Key;
            entry.IncludeInDataset = ShouldIncludeInDataset(board, entry, results.BestMove);

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

        return result;
    }

    using IterationCallback = std::function<void(DataEntries& iterationData, GameResult result)>;

    static void RunThread(const ThreadId threadId, const IterationCallback& callback)
    {
        Search search = Search(OnCallback);
        auto rng = std::mt19937(threadId * 10000073);
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

        for (auto entryId = 0; entryId < size; entryId++)
        {
            const auto& entry = entries[entryId];
            ss << entry.FFen << " 0 0 [";
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

#if DATAGEN
    static void Run()
    {
        Tablebases::Init("C:\\Chess\\Tablebases\\3-4-5piecesSyzygy\\3-4-5");

        auto threads = std::vector<std::thread>(ThreadCount);
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

        for (ThreadId threadId = 0; threadId < ThreadCount; threadId++)
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
            //const auto humanReadableDuration = HumanReadableDuration(elapsedSeconds);
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
            //ss << "[" << humanReadableDuration << "]";
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
#else
    static void Run()
    {
        std::cout << "DATAGEN DISABLED" << std::endl;
    }
#endif
};