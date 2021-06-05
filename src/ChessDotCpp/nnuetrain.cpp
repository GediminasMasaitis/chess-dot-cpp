#include "nnuetrain.h"

#include "fen.h"

#include <thread>
#include <fstream>

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

void WriteResults(const Board& board, Score score)
{
    std::array<uint8_t, 40> data{};
    auto writer = BitWriter(data.data());
    Sfens::Serialize(board, writer);
    writer.WriteBits(score, 16);
    writer.WriteBits(0, 16);
    writer.WriteBits(0, 16);
    writer.WriteBits(0, 8);
    writer.WriteBits(0, 8);

    std::ofstream output = std::ofstream("C:/Chess/Training/result.bin", std::ios::out | std::ios::binary);
    const auto dataPointer = reinterpret_cast<char*>(data.data());
    output.write(dataPointer, 40);
    output.close();
}

void WriteResultsPlain(const Board& board, Move move, Score score)
{
    auto fen = Fens::Serialize(board);
    auto fixedFen = fen + " 0 0";
    const MoveString moveStr = move.ToPositionString();

    std::ofstream output = std::ofstream("C:/Chess/Training/result.plain");
    output << "fen " << fixedFen << "\n";
    output << "move " << moveStr << "\n";
    output << "score " << score << "\n";
    output << "ply 0\n";
    output << "result 1\n";
    output << "e\n";
    output.close();
}

void SearchPosition(Search& search, Board& board)
{
    auto parameters = SearchParameters();
    parameters.WhiteTime = 10000;
    parameters.WhiteTimeIncrement = 1000;
    parameters.BlackTime = 10000;
    parameters.BlackTimeIncrement = 1000;

    search.State.NewGame();
    const Score score = search.Run(board, parameters);
    const Move move = search.State.Thread[0].SavedPrincipalVariation[0];
    
    WriteResultsPlain(board, move, score);
    auto a = 123;
}

void RunThread()
{
    auto callback = [&](SearchCallbackData& data)
    {

    };

    Search search = Search(callback);
    search.State.NewGame();    
    
    Fen fen = "rnb1k1nr/4pp1p/3p2p1/1p1P4/2p1PN2/2P5/P4PPP/1RB1KB1R b Kkq -";
    Board board{};
    Fens::Parse(board, fen);

    SearchPosition(search, board);
}

void NnueTrainer::Run()
{
    RunThread();
    //constexpr ThreadId threadCount = 1;
    //auto threads = std::vector<std::thread>(threadCount);
    //for(ThreadId threadId = 0; threadId < threadCount; threadId++)
    //{
    //    threads.emplace_back([&]()
    //    {
    //        RunThread();
    //    });
    //}
    //
    //for (ThreadId thread_id = 1; thread_id < Options::Threads; thread_id++)
    //{
    //    threads[thread_id].join();
    //}
}
