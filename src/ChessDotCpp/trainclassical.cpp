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

int32_t GetError(Score expected, Score calculated)
{
    const Score mean = static_cast<Score>(std::abs(expected - calculated));
    const int32_t square = mean * mean;
    return mean;
    return square;
}

double RunIteration(ClassicalTrainerState& state, const std::vector<size_t>& parameterIndices, size_t iteration)
{

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

                const auto error = GetError(entry.Result.SScore, staticScore);
                //std::lock_guard<std::mutex> guard(mutex);
                totalError += error;
            }
        });
    }

    for (ThreadId thread_id = 0; thread_id < threadCount; thread_id++)
    {
        threads[thread_id].join();
    }

    const double averageError = static_cast<double>(totalError) / state.Cache.Entries.size();
    
    const auto iterationEnd = std::chrono::high_resolution_clock::now();
    const auto elapsed = iterationEnd - state.TrainStart;
    const auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(elapsed);
    const auto humanReadableDuration = HumanReadableDuration(elapsedSeconds);

    std::stringstream ss = std::stringstream();
    ss << "[" << humanReadableDuration << "]";
    ss << " " << std::right << std::setw(5) << iteration;
    for (auto parameterIndex : parameterIndices)
    {
        ss << ", P" << parameterIndex << ": " << std::right << std::setw(2) << EvaluationDataTune::TuneScores[parameterIndex];
    }
    ss << " Total error: " << std::right << std::setw(10) << totalError;
    ss << ", Avg error: " << std::right << std::setw(2) << averageError;
    ss << std::endl;
    const auto log = ss.str();
    std::cout << log;
    
    return averageError;
}

class TrainIterationResult2D
{
public:
    std::vector<Score> Parameters;
    double Error;
};

void Descend2D(ClassicalTrainerState& state)
{
    constexpr Score learningRate = 1;
    constexpr auto offsetses = std::array<std::array<Score, 2>, 8>
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

    std::vector<TrainIterationResult2D> results;
    size_t iteration = 0;
    TrainIterationResult2D minResult;
    const auto parameterIndices = std::vector<size_t>{ 0,1 };
    minResult.Error = RunIteration(state, parameterIndices, iteration++);
    minResult.Parameters = { EvaluationDataTune::TuneScores[0], EvaluationDataTune::TuneScores[1] };

    while (true)
    {
        std::vector<TrainIterationResult2D> iterationResults;
        for (auto offsets : offsetses)
        {
            EvaluationDataTune::TuneScores[0] = minResult.Parameters[0] + offsets[0];
            EvaluationDataTune::TuneScores[1] = minResult.Parameters[1] + offsets[1];

            auto skip = false;
            for (auto& otherResult : results)
            {
                skip = true;
                for (size_t i = 0; i < otherResult.Parameters.size(); i++)
                {
                    if (EvaluationDataTune::TuneScores[i] != otherResult.Parameters[i])
                    {
                        skip = false;
                        break;
                    }
                }
                if (skip)
                {
                    break;
                }
            }
            if (skip)
            {
                continue;
            }

            EvaluationDataTune::Sync();
            TrainIterationResult2D newResult;
            newResult.Error = RunIteration(state, parameterIndices, iteration++);
            newResult.Parameters = std::vector<Score>{ EvaluationDataTune::TuneScores[0], EvaluationDataTune::TuneScores[1] };
            iterationResults.push_back(newResult);
            results.push_back(newResult);
        }

        TrainIterationResult2D minIterationResult = minResult;
        for (auto result : iterationResults)
        {
            if (result.Error < minIterationResult.Error)
            {
                minIterationResult = result;
            }
        }

        if (minIterationResult.Error == minResult.Error)
        {
            break;
        }
        minResult = minIterationResult;
    }

    std::cout << std::endl << "Min: " << minResult.Parameters[0] << ";" << minResult.Parameters[1] << ";" << minResult.Error << std::endl;
}

void FullErrorPlane(ClassicalTrainerState& state)
{
    std::vector<TrainIterationResult2D> results;
    size_t iteration = 0;
    const auto parameterIndices = std::vector<size_t>{ 0, 1 };
    TrainIterationResult2D minResult;
    minResult.Error = RunIteration(state, parameterIndices, iteration++);
    minResult.Parameters = { EvaluationDataTune::TuneScores[0], EvaluationDataTune::TuneScores[1] };

    constexpr Score window = 50;
    constexpr Score increment = 5;
    for (Score score1 = minResult.Parameters[0] - window; score1 <= minResult.Parameters[0] + window; score1 += increment)
    {
        for (Score score2 = minResult.Parameters[1] - window; score2 <= minResult.Parameters[1] + window; score2 += increment)
        {
            EvaluationDataTune::TuneScores[0] = score1;
            EvaluationDataTune::TuneScores[1] = score2;
            EvaluationDataTune::Sync();
            TrainIterationResult2D result;
            result.Error = RunIteration(state, parameterIndices, iteration++);
            result.Parameters = std::vector<Score>{ score1, score2 };
            results.push_back(result);
        }
    }

    std::stringstream ss;

    for (auto result : results)
    {
        ss << result.Parameters[0] << ";" << result.Parameters[1] << ";" << result.Error << std::endl;
        if (result.Error < minResult.Error)
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

double DescendParameterStep(ClassicalTrainerState& state, size_t& iteration, size_t parameterIndex, int& direction, double previousError)
{
    const auto parameterIndices = std::vector<size_t>{ parameterIndex };
    const Score initialParameter = EvaluationDataTune::TuneScores[parameterIndex];
    const auto initialError = direction == 0 ? RunIteration(state, parameterIndices, iteration++) : previousError;

    EvaluationDataTune::TuneScores[parameterIndex] = initialParameter + 1;
    EvaluationDataTune::Sync();
    const auto increaseError = (direction == 0 || direction == 1) ? RunIteration(state, parameterIndices, iteration++) : 999999999;

    EvaluationDataTune::TuneScores[parameterIndex] = initialParameter - 1;
    EvaluationDataTune::Sync();
    const auto decreaseError = (direction == 0 || direction == -1) ? RunIteration(state, parameterIndices, iteration++) : 999999999;

    if (decreaseError < initialError && decreaseError <= increaseError)
    {
        direction = -1;
        return decreaseError;
    }
    else if (increaseError < initialError)
    {
        EvaluationDataTune::TuneScores[parameterIndex] = initialParameter + 1;
        EvaluationDataTune::Sync();
        direction = 1;
        return increaseError;
    }
    else
    {
        EvaluationDataTune::TuneScores[parameterIndex] = initialParameter;
        EvaluationDataTune::Sync();
        direction = 0;
        return initialError;
    }
}

void MultipleDescendAllParameters(ClassicalTrainerState& state, size_t& iteration)
{
    bool anyChanged = true;
    while(anyChanged)
    {
        anyChanged = false;
        for(size_t parameterIndex = 0; parameterIndex < EvaluationDataTune::TuneScores.size(); parameterIndex++)
        {
            auto direction = 0;
            DescendParameterStep(state, iteration, parameterIndex, direction, 0);
            anyChanged |= direction != 0;
        }
    }

    for (size_t parameterIndex = 0; parameterIndex < EvaluationDataTune::TuneScores.size(); parameterIndex++)
    {
        std::cout << "P" << parameterIndex << ": " << EvaluationDataTune::TuneScores[parameterIndex] << std::endl;
    }
}

bool SingularDescendAllParameters(ClassicalTrainerState& state, size_t& iteration)
{
    bool anyChanged = false;
    for (size_t parameterIndex = 0; parameterIndex < EvaluationDataTune::TuneScores.size(); parameterIndex++)
    {
        auto direction = 0;
        auto error = DescendParameterStep(state, iteration, parameterIndex, direction, 0);
        while (direction != 0)
        {
            error = DescendParameterStep(state, iteration, parameterIndex, direction, error);
            if(direction)
            {
                anyChanged = true;
            }
            else
            {
                break;
            }
        }
    }

    for (size_t parameterIndex = 0; parameterIndex < EvaluationDataTune::TuneScores.size(); parameterIndex++)
    {
        std::cout << "P" << parameterIndex << ": " << EvaluationDataTune::TuneScores[parameterIndex] << std::endl;
    }
    return anyChanged;
}

void RunInner(ClassicalTrainerState& state)
{
    EvaluationDataTune::SetInitial();
    EvaluationDataTune::Sync();

    size_t iteration = 0;
    for(auto i = 0; i < 10; i++)
    {
        const auto changed = SingularDescendAllParameters(state, iteration);
        if(!changed)
        {
            break;
        }
    }
    MultipleDescendAllParameters(state, iteration);
    //Descend2D(state);
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
