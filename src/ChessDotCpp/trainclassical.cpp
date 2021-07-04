#include "trainclassical.h"

#include "movegen.h"
#include "evaluation.h"

#include <filesystem>
#include <fstream>
#include <thread>


//bool RunIterationClassical(TrainState& state, TrainThreadState& threadState)
//{
//    EachColor<Bitboard> pins;
//    PinDetector::GetPinnedToKings(board, pins);
//    const Score staticScore = Evaluation::Evaluate(board, pins, threadState.SSearch.State.Global.Eval);
//
//    if (std::abs(inputResult.SScore) > 1000)
//    {
//        return true;
//    }
//
//    const Score error = GetError(inputResult.SScore, staticScore);
//
//    std::lock_guard<std::mutex> guard(state.OutputMutex);
//
//    threadState.SearchedPositions++;
//    state.SearchedPositions++;
//
//    const auto now = std::chrono::high_resolution_clock::now();
//
//    auto secondsSinceLastPrint = std::chrono::duration_cast<std::chrono::seconds>(now - state.LastPrint);
//    auto doOut = secondsSinceLastPrint.count() >= 1;
//    if (doOut)
//    {
//        const auto elapsed = now - state.TrainStart;
//        const auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(elapsed);
//        const auto humanReadableDuration = HumanReadableDuration(elapsedSeconds);
//        auto elapsedSecondCount = elapsedSeconds.count();
//        if (elapsedSecondCount == 0)
//        {
//            elapsedSecondCount = 1;
//        }
//
//        auto completed = (static_cast<double>(state.CurrentOffset) / state.InputLength) * 100;
//        const auto pps = static_cast<double>(state.SearchedPositions) / elapsedSecondCount;
//        const auto ppsInt = static_cast<size_t>(pps);
//        const auto remaining = state.InputLength - state.CurrentOffset;
//        auto estimatedSecondCount = static_cast<size_t>(remaining / pps);
//        auto estimatedSeconds = std::chrono::seconds(estimatedSecondCount);
//        auto humanReadableEstimate = HumanReadableDuration(estimatedSeconds);
//
//        state.LastPrint = now;
//
//        std::stringstream ss = std::stringstream();
//        ss << "[" << humanReadableDuration << "]";
//        ss << " " << std::right << std::setw(7) << state.SearchedPositions;
//        ss << " (" << std::right << std::setw(3) << ppsInt << " PPS, " << std::fixed << std::setprecision(3) << completed << "%, " << humanReadableEstimate << " est.)";
//        ss << " " << std::left << std::setw(70) << inputResult.FFen;
//        //const auto depth = static_cast<uint16_t>(searchResults.SearchedDepth);
//        //ss << " depth " << std::left << std::setw(2) << depth;
//        //ss << " move " << std::left << std::setw(5) << outputResult.Move;
//        ss << " score " << staticScore;
//        ss << std::endl;
//        const auto log = ss.str();
//        std::cout << log;
//    }
//    return true;
//}

class ClassicalTrainerState
{
public:
    const ClassicalTrainingParameters& Parameters;
    BoardCache<BoardBase>& Cache;
    EvalState& Eval;
    std::chrono::high_resolution_clock::time_point TrainStart;
    
    ClassicalTrainerState(const ClassicalTrainingParameters& parameters, BoardCache<BoardBase>& cache, EvalState& eval)
        : Parameters(parameters),
          Cache(cache),
          Eval(eval)
    {
    }
};

Score GetError(Score expected, Score calculated)
{
    const Score error = static_cast<Score>(std::abs(expected - calculated));
    return error;
}

double RunIteration(ClassicalTrainerState& state, size_t iteration)
{
    //BoardCacheEntry<BoardBase> entry;
    //while(state.Cache.NextEntry(entry))

    std::atomic_int64_t totalError = 0;
    const auto iterationStart = std::chrono::high_resolution_clock::now();

    //std::mutex mutex;
    constexpr ThreadId threadCount = 12;
    state.Cache.Reset(threadCount);
    auto threads = std::vector<std::thread>();
    for (ThreadId threadId = 0; threadId < threadCount; threadId++)
    {
        threads.emplace_back([&, threadId]()
        {
            BoardCacheEntry<BoardBase> entry;
            EachColor<Bitboard> pins;
            while(true)
            {
                const bool success = state.Cache.NextEntry(entry, threadId);
                if (!success)
                {
                    break;
                }

                if (std::abs(entry.Result.SScore) > 1000)
                {
                    continue;
                }
                
                PinDetector::GetPinnedToKings(entry.Board, pins);
                const Score staticScore = Evaluation::Evaluate(entry.Board, pins, state.Eval);

                const Score error = GetError(entry.Result.SScore, staticScore);
                //std::lock_guard<std::mutex> guard(mutex);
                totalError += error;
            }
        });
    }

    for (ThreadId thread_id = 0; thread_id < threadCount; thread_id++)
    {
        threads[thread_id].join();
    }

    //BoardCacheEntry<BoardBase> entry;
    //EachColor<Bitboard> pins;
    //while (true)
    //{
    //    const bool success = state.Cache.NextEntry(entry);
    //    if (!success)
    //    {
    //        break;
    //    }

    //    if (std::abs(entry.Result.SScore) > 1000)
    //    {
    //        continue;
    //    }

    //    PinDetector::GetPinnedToKings(entry.Board, pins);
    //    const Score staticScore = Evaluation::Evaluate(entry.Board, pins, state.Eval);

    //    const Score error = GetError(entry.Result.SScore, staticScore);
    //    std::lock_guard<std::mutex> guard(mutex);
    //    totalError += error;
    //}

    const double averageError = static_cast<double>(totalError) / state.Cache.Entries.size();
    
    const auto iterationEnd = std::chrono::high_resolution_clock::now();
    const auto elapsed = iterationEnd - state.TrainStart;
    const auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(elapsed);
    const auto humanReadableDuration = HumanReadableDuration(elapsedSeconds);

    std::stringstream ss = std::stringstream();
    ss << "[" << humanReadableDuration << "]";
    ss << " " << std::right << std::setw(5) << iteration;
    ss << ", S1: " << std::right << std::setw(2) << EvaluationData::TuneScores[0];
    ss << ", S2: " << std::right << std::setw(2) << EvaluationData::TuneScores[1];
    ss << " Total error: " << std::right << std::setw(10) << totalError;
    ss << ", Avg error: " << std::right << std::setw(2) << averageError;
    ss << std::endl;
    const auto log = ss.str();
    std::cout << log;
    
    return averageError;
}

class TrainIterationResult
{
public:
    std::vector<Score> Parameters;
    double Error;
};

void RunInner(ClassicalTrainerState& state)
{
    std::vector<TrainIterationResult> results;
    size_t iteration = 0;

    EvaluationData::SetInitial();
    EvaluationData::Sync();

    TrainIterationResult minResult;
    minResult.Error = RunIteration(state, iteration++);
    minResult.Parameters = { EvaluationData::TuneScores[0], EvaluationData::TuneScores[1] };

    constexpr Score learningRate = 1;
    const auto offsetses = std::array<std::array<Score, 2>, 8>
    {
        std::array<Score, 2>{ -learningRate, -learningRate },
        std::array<Score, 2>{ -learningRate, 0 },
        std::array<Score, 2>{ -learningRate, learningRate },
        std::array<Score, 2>{ 0, -learningRate },
        std::array<Score, 2>{ 0, learningRate },
        std::array<Score, 2>{ learningRate, -learningRate },
        std::array<Score, 2>{ learningRate, 0 },
        std::array<Score, 2>{ learningRate, learningRate },
    };
    
    while (true)
    {
        std::vector<TrainIterationResult> iterationResults;
        for (auto offsets : offsetses)
        {
            EvaluationData::TuneScores[0] = minResult.Parameters[0] + offsets[0];
            EvaluationData::TuneScores[1] = minResult.Parameters[1] + offsets[1];

            auto skip = false;
            for (auto& otherResult : results)
            {
                skip = true;
                for (size_t i = 0; i < otherResult.Parameters.size(); i++)
                {
                    if(EvaluationData::TuneScores[i] != otherResult.Parameters[i])
                    {
                        skip = false;
                        break;
                    }
                }
                if(skip)
                {
                    break;
                }
            }
            if(skip)
            {
                continue;
            }
            
            EvaluationData::Sync();
            TrainIterationResult newResult;
            newResult.Error = RunIteration(state, iteration++);
            newResult.Parameters = std::vector<Score>{ EvaluationData::TuneScores[0], EvaluationData::TuneScores[1] };
            iterationResults.push_back(newResult);
            results.push_back(newResult);
        }
        
        TrainIterationResult minIterationResult = minResult;
        for (auto result : iterationResults)
        {
            if (result.Error < minIterationResult.Error)
            {
                minIterationResult = result;
            }
        }
        
        if(minIterationResult.Error == minResult.Error)
        {
            break;
        }
        minResult = minIterationResult;
    }
    
    std::cout << std::endl << "Min: " << minResult.Parameters[0] << ";" << minResult.Parameters[1] << ";" << minResult.Error << std::endl;

    return;
    
    results.clear();
    
    constexpr Score window = 50;
    constexpr Score increment = 5;
    for(Score score1 = minResult.Parameters[0] - window; score1 <= minResult.Parameters[0] + window; score1 += increment)
    {
        for (Score score2 = minResult.Parameters[1] - window; score2 <= minResult.Parameters[1] + window; score2 += increment)
        {
            EvaluationData::TuneScores[0] = score1;
            EvaluationData::TuneScores[1] = score2;
            EvaluationData::Sync();
            TrainIterationResult result;
            result.Error = RunIteration(state, iteration++);
            result.Parameters = std::vector<Score>{ score1, score2 };
            results.push_back(result);
        }
    }

    std::stringstream ss;
    
    minResult.Error = 9999999999;
    for(auto result : results)
    {
        ss << result.Parameters[0] << ";" << result.Parameters[1] << ";" << result.Error << std::endl;
        if(result.Error < minResult.Error)
        {
            minResult = result;
        }
    }
    std::cout << std::endl << "Min: " << minResult.Parameters[0] << ";" << minResult.Parameters[1] << ";" << minResult.Error << std::endl;
    std::ofstream out;
    out.open("C:/Temp/tune/result.csv");
    out << ss.str() << std::endl;
    out.flush();
    out.close();
}

void ClassicalTrainer::Run(const ClassicalTrainingParameters& parameters)
{
    const auto loadStart = std::chrono::high_resolution_clock::now();
    size_t inputLength = std::filesystem::file_size(parameters.InputPath);
    std::ifstream inputStream;
    inputStream.open(parameters.InputPath, std::ifstream::in);
    TrainingReader reader = TrainingReader(inputStream, parameters.InputFormat);

    BoardCache<BoardBase> cache = BoardCache<BoardBase>(reader);
    cache.LoadAll();
    const auto loadEnd = std::chrono::high_resolution_clock::now();

    const auto elapsed = loadEnd - loadStart;
    const auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(elapsed);
    const auto humanReadableDuration = HumanReadableDuration(elapsedSeconds);

    EvalState evalState = EvalState();
    evalState.EvalTable.Enable = false;
    evalState.PawnTable.Enable = false;

    std::cout << "Loaded " << cache.Entries.size() << " boards in " << humanReadableDuration << std::endl;
    
    ClassicalTrainerState state = ClassicalTrainerState(parameters, cache, evalState);

    state.TrainStart = std::chrono::high_resolution_clock::now();
    RunInner(state);
}
