#include "nnuetrain.h"

#include "board.h"
#include "search.h"
#include "fen.h"

#include <thread>
#include <fstream>
#include <filesystem>
#include <mutex>

class BitWriter
{
public:
    uint8_t* Data;
    size_t Offset;

    BitWriter(uint8_t* data) : Data(data)
    {
        Offset = 0;
    }

    void WriteBit(const bool value)
    {
        const size_t byteOffset = Offset >> 3;
        const uint8_t bitOffset = Offset & 7;
        uint8_t& byte = Data[byteOffset];
        const uint8_t mask = static_cast<uint8_t>(1 << bitOffset);
        if (value)
        {
            byte |= mask;
        }
        else
        {
            const uint8_t reflectedMask = ~mask;
            byte &= reflectedMask;
        }
        Offset++;
    }

    void WriteBits(const size_t value, const uint8_t length)
    {
        for (uint8_t i = 0; i < length; i++)
        {
            const size_t mask = static_cast<size_t>(static_cast<size_t>(1) << i);
            const bool bitValue = (mask & value) > 0;
            WriteBit(bitValue);
        }
    }
};

class HuffmanPiece
{
public:
    HuffmanPieceValue Value;
    uint8_t Length;
};

class Huffman
{
public:
    constexpr static HuffmanPieceValue Invalid = ~0;
    constexpr static EachPiece<HuffmanPiece> Pieces =
    {
        HuffmanPiece { 0b00000, 1 },
        HuffmanPiece { Invalid, 5 },
        HuffmanPiece { Invalid, 5 },
        HuffmanPiece { Invalid, 5 },

        HuffmanPiece { 0b00010, 5 },
        HuffmanPiece { 0b00011, 5 },

        HuffmanPiece { 0b00110, 5 },
        HuffmanPiece { 0b00111, 5 },

        HuffmanPiece { 0b01010, 5 },
        HuffmanPiece { 0b01011, 5 },

        HuffmanPiece { 0b01110, 5 },
        HuffmanPiece { 0b01111, 5 },

        HuffmanPiece { 0b10010, 5 },
        HuffmanPiece { 0b10011, 5 },

        HuffmanPiece { Invalid, 5 },
        HuffmanPiece { Invalid, 5 }
    };
};

class Sfens
{
public:
    static void Serialize(const Board& board, BitWriter& writer)
    {
        writer.WriteBit(board.ColorToMove == Colors::White);
        writer.WriteBits(board.KingPositions[Colors::White], 6);
        writer.WriteBits(board.KingPositions[Colors::Black], 6);
        for (Position position = 0; position < Positions::Count; position++)
        {
            const Piece piece = board.ArrayBoard[position];
            if (piece == Pieces::WhiteKing || piece == Pieces::BlackKing)
            {
                continue;
            }

            const HuffmanPiece huffmanPiece = Huffman::Pieces[piece];
            assert(huffmanPiece.Value != Huffman::Invalid);
            writer.WriteBits(huffmanPiece.Value, huffmanPiece.Length);
        }
        writer.WriteBit(board.CanCastle(CastlingPermissions::WhiteKing));
        writer.WriteBit(board.CanCastle(CastlingPermissions::WhiteQueen));
        writer.WriteBit(board.CanCastle(CastlingPermissions::BlackKing));
        writer.WriteBit(board.CanCastle(CastlingPermissions::BlackQueen));


        if (board.EnPassantFile == BitboardConstants::Empty)
        {
            writer.WriteBit(false);
        }
        else
        {
            writer.WriteBit(true);
            const Position enPassantPosition = GetPosition(board.EnPassantFileIndex, board.EnPassantRankIndex);
            writer.WriteBits(enPassantPosition, 6);
        }
        writer.WriteBits(0, 6); // 50 move rule
        const HistoryPly fullMoves = static_cast<HistoryPly>(1 + (board.HistoryDepth - (board.WhiteToMove ? 1 : 0)) / 2);
        writer.WriteBits(fullMoves, 8);
        writer.WriteBits(fullMoves >> 8, 8);
        writer.WriteBits(0 >> 6, 1); // 50 move rule
    }

    static void Serialize(const Board& board, uint8_t* data)
    {
        auto writer = BitWriter(data);
        Serialize(board, writer);
    }
};

std::string HumanReadableDuration(std::chrono::seconds input_seconds)
{
    using namespace std::chrono;
    typedef duration<int, std::ratio<86400>> days;
    const auto d = duration_cast<days>(input_seconds);
    input_seconds -= d;
    const auto h = duration_cast<hours>(input_seconds);
    input_seconds -= h;
    const auto m = duration_cast<minutes>(input_seconds);
    input_seconds -= m;
    const auto s = duration_cast<seconds>(input_seconds);

    std::stringstream ss;
    ss.fill('0');
    ss << d.count() << ".";
    ss << std::setw(2);
    ss << h.count() << ":";
    ss << std::setw(2);
    ss << m.count() << ":";
    ss << std::setw(2);
    ss << s.count();
    return ss.str();
}

class TrainResult
{
public:
    Fen FFen;
    MoveString Move;
    Score SScore;
    HistoryPly Ply;
    int8_t Result;
    char Type;
};

class TrainingReader
{
    std::ifstream& Stream;
    InputFormats Format;
    std::mutex Mutex;

public:
    explicit TrainingReader(std::ifstream& input, InputFormats format)
    : Stream(input), Format(format)
    {
    }
    
    void ReadData(TrainResult& data)
    {
        std::lock_guard<std::mutex> guard(Mutex);
        switch (Format)
        {
        case InputFormats::Epd:
            std::getline(Stream, data.FFen);
            break;
        case InputFormats::Plain:
            break;
        }
        
    }

    size_t GetCurrentOffset() const
    {
        const size_t offset = Stream.tellg();
        return offset;
    }
};

class TrainingWriter
{
    std::ofstream& Stream;
    OutputFormats Format;
    std::mutex Mutex;

    void WriteResultsPlain(const TrainResult& result)
    {
        Stream << "fen " << result.FFen << "\n";
        Stream << "move " << result.Move << "\n";
        Stream << "score " << result.SScore << "\n";
        Stream << "ply " << result.Ply << "\n";
        Stream << "result 1\n";
        Stream << "e\n";

    }

public:
    TrainingWriter(std::ofstream& stream, OutputFormats format)
        : Stream(stream), Format(format)
    {
    }

    void WriteResults(const TrainResult& result, const bool flush)
    {
        switch (Format)
        {
        case OutputFormats::Plain:
            WriteResultsPlain(result);
            break;
        }

        if (flush)
        {
            Stream.flush();
        }
    }
};

class TrainingReporter
{
    std::mutex Mutex;

public:
    void PrintProgress()
    {
        
    }
};

class TrainState
{
public:
    TrainingParameters Parameters;
    TrainingReader& Reader;
    TrainingWriter& Writer;
    std::mutex OutputMutex;
    bool IsRunning;
    size_t InputLength;
    size_t CurrentOffset;
    uint32_t SearchedPositions;
    std::chrono::high_resolution_clock::time_point TrainStart;
    std::chrono::high_resolution_clock::time_point LastPrint;


    explicit TrainState(TrainingReader& reader, TrainingWriter& writer)
        : Reader(reader), Writer(writer)
    {
    }
};

//void WriteResults(const Board& board, Score score)
//{
//    std::array<uint8_t, 40> data{};
//    auto writer = BitWriter(data.data());
//    Sfens::Serialize(board, writer);
//    writer.WriteBits(score, 16);
//    writer.WriteBits(0, 16);
//    writer.WriteBits(0, 16);
//    writer.WriteBits(0, 8);
//    writer.WriteBits(0, 8);
//
//    std::ofstream output = std::ofstream("C:/Chess/Training/result.bin", std::ios::out | std::ios::binary);
//    const auto dataPointer = reinterpret_cast<char*>(data.data());
//    output.write(dataPointer, 40);
//    output.close();
//}

size_t ReadOffset(const std::string& path)
{
    if(!std::filesystem::exists(path))
    {
        return 0;
    }
    
    auto file = std::ifstream();
    file.open(path, std::ifstream::in);
    size_t offset;
    file >> offset;
    return offset;
}

size_t WriteOffset(const std::string& path, const size_t offset)
{
    auto file = std::ofstream();
    file.open(path, std::ofstream::out | std::ofstream::trunc);
    file << offset;
    return offset;
}

class TrainThreadState
{
public:
    size_t SearchedPositions = 0;
    Search& SSearch;

    explicit TrainThreadState(Search& search)
    : SSearch(search)
    {
    }
};

void GetOutputResults(TrainResult& inputResult, SearchResults& searchResults, TrainResult& outputResult, Board& board)
{
    outputResult = inputResult;
    if (inputResult.FFen.empty())
    {
        const Fen fen = Fens::Serialize(board);
        const Fen fixedFen = fen + " 0 0";
        outputResult.FFen = fixedFen;
    }
    if(outputResult.Result == -2)
    {
        outputResult.Result = 1;
    }
    if(outputResult.Type == '\0')
    {
        outputResult.Type = 'e';
    }
    outputResult.Move = searchResults.BestMove.ToPositionString();
    outputResult.SScore = searchResults.SScore;
}

void HandleSearchedPosition(TrainState& state, TrainThreadState& threadState, TrainResult& inputResult, Board& board, SearchResults& searchResults)
{

    
}

void RunIteration(TrainState& state, TrainThreadState& threadState)
{
    TrainResult inputResult;
    state.Reader.ReadData(inputResult);
    state.CurrentOffset = state.Reader.GetCurrentOffset();
    Board board{};
    Fens::Parse(board, inputResult.FFen);

    if ((threadState.SearchedPositions & 0xFF) == 0)
    {
        threadState.SSearch.State.NewGame();
    }
    SearchResults searchResults;
    threadState.SSearch.Run(board, state.Parameters.SearchParams, searchResults);
    
    //HandleSearchedPosition(state, threadState, inputResult, board, searchResults);

    TrainResult outputResult;
    GetOutputResults(inputResult, searchResults, outputResult, board);
    threadState.SearchedPositions++;

    const auto now = std::chrono::high_resolution_clock::now();
    const auto elapsed = now - state.TrainStart;
    const auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(elapsed);
    const auto humanReadableDuration = HumanReadableDuration(elapsedSeconds);
    auto elapsedSecondCount = elapsedSeconds.count();
    if (elapsedSecondCount == 0)
    {
        elapsedSecondCount = 1;
    }

    std::lock_guard<std::mutex> guard(state.OutputMutex);
    state.SearchedPositions++;
    auto completed = (static_cast<double>(state.CurrentOffset) / state.InputLength) * 100;
    const auto pps = static_cast<double>(state.SearchedPositions) / elapsedSecondCount;
    const auto ppsInt = static_cast<size_t>(pps);
    const auto remaining = state.InputLength - state.CurrentOffset;
    auto estimatedSecondCount = static_cast<size_t>(remaining / pps);
    auto estimatedSeconds = std::chrono::seconds(estimatedSecondCount);
    auto humanReadableEstimate = HumanReadableDuration(estimatedSeconds);
    auto secondsSinceLastPrint = std::chrono::duration_cast<std::chrono::seconds>(now - state.LastPrint);
    auto doOut = secondsSinceLastPrint.count() >= 1;
    if (doOut)
    {
        state.LastPrint = now;

        std::stringstream ss = std::stringstream();
        ss << "[" << humanReadableDuration << "]";
        ss << " " << std::right << std::setw(7) << state.SearchedPositions;
        ss << " (" << std::right << std::setw(3) << ppsInt << " PPS, " << std::fixed << std::setprecision(3) << completed << "%, " << humanReadableEstimate << " est.)";
        ss << " " << std::left << std::setw(70) << outputResult.FFen;
        const auto depth = static_cast<uint16_t>(searchResults.SearchedDepth);
        ss << " depth " << std::left << std::setw(2) << depth;
        ss << " move " << std::left << std::setw(5) << outputResult.Move;
        ss << " score " << outputResult.SScore;
        ss << std::endl;
        const auto log = ss.str();
        std::cout << log;
    }

    const bool doFlush = (state.SearchedPositions % 0xFF) == 0;
    state.Writer.WriteResults(outputResult, doFlush);
}

void RunThread(TrainState& state)
{
    auto callback = [&](SearchCallbackData& data)
    {

    };

    Search search = Search(callback);
    TrainThreadState threadState(search);
    while (state.IsRunning)
    {
        RunIteration(state, threadState);
    }
}

void FillConsoleBuffer()
{
    std::stringstream ss;
    for(auto i = 0; i < 1000; i++)
    {
        ss << "\n";
    }
    std::cout << ss.str();
}

void NnueTrainer::Run(const TrainingParameters& parameters)
{
    size_t inputLength = std::filesystem::file_size(parameters.InputPath);
    const size_t offset = ReadOffset(parameters.OffsetPath);
    std::ifstream inputStream;
    inputStream.open(parameters.InputPath, std::ifstream::in);
    inputStream.seekg(offset);
    TrainingReader reader = TrainingReader(inputStream, parameters.InputFormat);

    std::ofstream outputStream;
    outputStream.open(parameters.OutputPath, std::ofstream::out | std::ofstream::app);
    TrainingWriter writer = TrainingWriter(outputStream, parameters.OutputFormat);

    TrainState state = TrainState(reader, writer);
    state.Parameters = parameters;
    state.SearchedPositions = 0;
    state.TrainStart = std::chrono::high_resolution_clock::now();
    state.IsRunning = true;
    state.InputLength = inputLength;
  
    //RunThread(state, parameters);
    
    constexpr ThreadId threadCount = 24;
    auto threads = std::vector<std::thread>();
    for(ThreadId threadId = 0; threadId < threadCount; threadId++)
    {
        threads.emplace_back([&]()
        {
            RunThread(state);
        });
    }
    
    for (ThreadId thread_id = 0; thread_id < threadCount; thread_id++)
    {
        threads[thread_id].join();
    }
}
