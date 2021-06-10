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

class TrainState
{
public:
    TrainingParameters Parameters;
    std::ifstream Input;
    std::mutex InputMutex;
    std::ofstream Output;
    std::mutex OutputMutex;
    uint32_t PositionIndex;
    std::chrono::high_resolution_clock::time_point TrainStart;
    std::chrono::high_resolution_clock::time_point LastPrint;
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

void WriteResultsPlain(const Board& board, TrainState& state, SearchResults& results)
{
    constexpr size_t totalPositions = 9800000;
    const Fen fen = Fens::Serialize(board);
    const Fen fixedFen = fen + " 0 0";
    const MoveString moveStr = results.BestMove.ToPositionString();
    const auto depth = static_cast<uint16_t>(results.SearchedDepth);
    const auto now = std::chrono::high_resolution_clock::now();
    const auto elapsed = now - state.TrainStart;
    const auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(elapsed);
    const auto humanReadableDuration = HumanReadableDuration(elapsedSeconds);
    auto elapsedSecondCount = elapsedSeconds.count();
    if(elapsedSecondCount == 0)
    {
        elapsedSecondCount = 1;
    }

    std::lock_guard<std::mutex> guard(state.OutputMutex);
    state.PositionIndex++;
    auto completed = (static_cast<double>(state.PositionIndex) / totalPositions) * 100;
    const auto pps = static_cast<double>(state.PositionIndex) / elapsedSecondCount;
    const auto ppsInt = static_cast<size_t>(pps);
    const auto remaining = totalPositions - state.PositionIndex;
    auto estimatedSecondCount = static_cast<size_t>(remaining / pps);
    auto estimatedSeconds = std::chrono::seconds(estimatedSecondCount);
    auto humanReadableEstimate = HumanReadableDuration(estimatedSeconds);
    auto secondsSinceLastPrint = std::chrono::duration_cast<std::chrono::seconds>(now - state.LastPrint);
    auto doOut = secondsSinceLastPrint.count() >= 1;
    if(doOut)
    {
        state.LastPrint = now;
        
        std::stringstream ss = std::stringstream();
        ss << "[" << humanReadableDuration << "]";
        ss << " " << std::right << std::setw(7) << state.PositionIndex;
        ss << " (" << std::right << std::setw(3) << ppsInt << " PPS, " << std::fixed << std::setprecision(3) << completed << "%, " << humanReadableEstimate << " est.)";
        ss << " " << std::left << std::setw(70) << fen;
        ss << " depth " << std::left << std::setw(2) << depth;
        ss << " move " << std::left << std::setw(5) << moveStr;
        ss << " score " << results.SScore;
        ss << std::endl;
        const auto log = ss.str();
        std::cout << log;
    }
    
    state.Output << "fen " << fixedFen << "\n";
    state.Output << "move " << moveStr << "\n";
    state.Output << "score " << results.SScore << "\n";
    state.Output << "ply " << depth <<"\n";
    state.Output << "result 1\n";
    state.Output << "e\n";
    if(doOut)
    {
        state.Output.flush();
    }
}

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

void SearchPosition(Search& search, Board& board, TrainState& state)
{
    search.State.NewGame();
    SearchResults results;
    search.Run(board, state.Parameters.SearchParams, results);
    WriteResultsPlain(board, state, results);
    auto a = 123;
}

void GetFen(Fen& fen, TrainState& state)
{
    std::lock_guard<std::mutex> guard(state.InputMutex);
    std::getline(state.Input, fen);
    size_t offset = state.Input.tellg();
}

void RunThread(TrainState& state)
{
    auto callback = [&](SearchCallbackData& data)
    {

    };

    Search search = Search(callback);

    while (true)
    {
        Fen fen;
        GetFen(fen, state);
        //Fen fen = "rnb1k1nr/4pp1p/3p2p1/1p1P4/2p1PN2/2P5/P4PPP/1RB1KB1R b Kkq -";
        Board board{};
        Fens::Parse(board, fen);
        SearchPosition(search, board, state);
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
    TrainState state;
    state.Parameters = parameters;
    const size_t offset = ReadOffset(parameters.OffsetPath);
    state.Input.open(parameters.InputPath, std::ifstream::in);
    state.Input.seekg(offset);

    state.Output.open(parameters.OutputPath, std::ofstream::out | std::ofstream::app);
    state.PositionIndex = 0;
    state.TrainStart = std::chrono::high_resolution_clock::now();
  
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
