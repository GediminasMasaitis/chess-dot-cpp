#pragma once
#include <iostream>

#include "board.h"
#include "common.h"
#include "fen.h"
#include "magics.h"
#include "see.h"
#include "likeliness.h"
#include "zobrist.h"

class Tests
{
public:
    static void TestUci()
    {
        std::vector<Fen> moveses =
        {
            "e2e4 c7c5 g1f3 d7d6 d2d4 c5d4 d1d4 b8c6 f1b5 c8d7 d4d3 g7g6 e1g1 g8f6 b1c3 f8g7 c1f4 e8g8 a2a3 a7a6 b5c4 e7e5 f4e3 b7b5 c4b3 c6a5 d3d6 a5b3 c2b3 d7e6 d6b4 d8b8 e3g5 a6a5 b4b5 b8b5 c3b5 a8b8 b5c7 e6b3 g5f6 g7f6 a1c1 a5a4 c7a6 b8b5 c1c7 g6g5 a6c5 g5g4 f3d2 f6d8 c7c6 d8g5 d2b3 a4b3 f1d1 g5e7 c5d7 f8d8 c6c3 g8g7 c3c7 b5b6 g1f1 b6d6 d1d6 e7d6 c7b7 h7h5 a3a4 d8a8 d7b6 a8a6 b6c4 d6c5 c4e5 a6a4 b7f7 g7g8 f7f5 c5e7 f5h5 a4e4 h5f5 e4a4 f1e2 e7f8 e5d3 a4a7 f5g5 a7g7 g5g7 g8g7 e2d2 f8d6 d2c3 d6h2 g2g3 g7f6 c3b3 f6e6 b3a4 e6d5 b2b4 d5e4 b4b5 e4d5 b5b6 d5c6 a4a5 c6b7 d3c5 b7c6 b6b7 c6c7 a5a6 h2g1 a6a7 g1f2 b7b8Q c7c6 b8e8 c6c5 e8f8 c5c4 f8f2 c4d3 f2f5 d3c4 f5g4 c4c3 g4f3 c3c4 f3e4 c4c3 e4f3", // 69
            "e2e4 c7c5 g1f3 d7d6 d2d4 c5d4 d1d4 b8c6 f1b5 c8d7 d4d3 g7g6 e1g1 g8f6 b1c3 f8g7 c1f4 e8g8 a2a3 a7a6 b5c4 e7e5 f4e3 b7b5 c4b3 c6a5 d3d6 a5b3 c2b3 d7e6 d6b4 d8b8 e3g5 a6a5 b4b5 b8b5 c3b5 a8b8 b5c7 e6b3 g5f6 g7f6 a1c1 a5a4 c7a6 b8b5 c1c7 g6g5 a6c5 g5g4 f3d2 f6d8 c7c6 d8g5 d2b3 a4b3 f1d1 g5e7 c5d7 f8d8 c6c3 g8g7 c3c7 b5b6 g1f1 b6d6 d1d6 e7d6 c7b7 h7h5 a3a4 d8a8 d7b6 a8a6 b6c4 d6c5 c4e5 a6a4 b7f7 g7g8 f7f5 c5e7 f5h5 a4e4 h5f5 e4a4 f1e2 e7f8 e5d3 a4a7 f5g5 a7g7 g5g7 g8g7 e2d2 f8d6 d2c3 d6h2 g2g3 g7f6 c3b3 f6e6 b3a4 e6d5 b2b4 d5e4 b4b5 e4d5 b5b6 d5c6 a4a5 c6b7 d3c5 b7c6 b6b7 c6c7 a5a6 h2g1 a6a7 g1f2 b7b8Q c7c6 b8e8 c6c5 e8f8 c5c4 f8f2 c4d3 f2f5 d3c4 f5g4 c4c3 g4f3 c3c4 f3e4 c4c3 e4f3 c3c4",
            "e2e4 c7c5 g1f3 d7d6 d2d4 c5d4 d1d4 b8c6 f1b5 c8d7 d4d3 g7g6 e1g1 g8f6 b1c3 f8g7 c1f4 e8g8 a2a3 a7a6 b5c4 e7e5 f4e3 b7b5 c4b3 c6a5 d3d6 a5b3 c2b3 d7e6 d6b4 d8b8 e3g5 a6a5 b4b5 b8b5 c3b5 a8b8 b5c7 e6b3 g5f6 g7f6 a1c1 a5a4 c7a6 b8b5 c1c7 g6g5 a6c5 g5g4 f3d2 f6d8 c7c6 d8g5 d2b3 a4b3 f1d1 g5e7 c5d7 f8d8 c6c3 g8g7 c3c7 b5b6 g1f1 b6d6 d1d6 e7d6 c7b7 h7h5 a3a4 d8a8 d7b6 a8a6 b6c4 d6c5 c4e5 a6a4 b7f7 g7g8 f7f5 c5e7 f5h5 a4e4 h5f5 e4a4 f1e2 e7f8 e5d3 a4a7 f5g5 a7g7 g5g7 g8g7 e2d2 f8d6 d2c3 d6h2 g2g3 g7f6 c3b3 f6e6 b3a4 e6d5 b2b4 d5e4 b4b5 e4d5 b5b6 d5c6 a4a5 c6b7 d3c5 b7c6 b6b7 c6c7 a5a6 h2g1 a6a7 g1f2 b7b8Q c7c6 b8e8 c6c5 e8f8 c5c4 f8f2 c4d3 f2f5 d3c4 f5g4 c4c3 g4f3 c3c4 f3e4 c4c3 e4f3 c3c4 f3e4", // 70
            "e2e4 c7c5 g1f3 d7d6 d2d4 c5d4 d1d4 b8c6 f1b5 c8d7 d4d3 g7g6 e1g1 g8f6 b1c3 f8g7 c1f4 e8g8 a2a3 a7a6 b5c4 e7e5 f4e3 b7b5 c4b3 c6a5 d3d6 a5b3 c2b3 d7e6 d6b4 d8b8 e3g5 a6a5 b4b5 b8b5 c3b5 a8b8 b5c7 e6b3 g5f6 g7f6 a1c1 a5a4 c7a6 b8b5 c1c7 g6g5 a6c5 g5g4 f3d2 f6d8 c7c6 d8g5 d2b3 a4b3 f1d1 g5e7 c5d7 f8d8 c6c3 g8g7 c3c7 b5b6 g1f1 b6d6 d1d6 e7d6 c7b7 h7h5 a3a4 d8a8 d7b6 a8a6 b6c4 d6c5 c4e5 a6a4 b7f7 g7g8 f7f5 c5e7 f5h5 a4e4 h5f5 e4a4 f1e2 e7f8 e5d3 a4a7 f5g5 a7g7 g5g7 g8g7 e2d2 f8d6 d2c3 d6h2 g2g3 g7f6 c3b3 f6e6 b3a4 e6d5 b2b4 d5e4 b4b5 e4d5 b5b6 d5c6 a4a5 c6b7 d3c5 b7c6 b6b7 c6c7 a5a6 h2g1 a6a7 g1f2 b7b8Q c7c6 b8e8 c6c5 e8f8 c5c4 f8f2 c4d3 f2f5 d3c4 f5g4 c4c3 g4f3 c3c4 f3e4 c4c3 e4f3 c3c4 f3e4 c4c3",
        };
        
        std::queue<std::string> commands = std::queue<std::string>();
        commands.push("uci");
        commands.push("ucinewgame");

        for (const auto& moves : moveses)
        {
            commands.push("position startpos moves " + moves);
            commands.push("isready");
            //commands.push("go wtime 60000 winc 600 btime 60000 binc 600");
            commands.push("go infinite depth 10");
        }
        commands.push("quit");
        Game::RunCommands(commands);
        Likeliness::PrintStats();
    }

    //static void TestSfen()
    //{
    //    Fen fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    //    Board board{};
    //    Fens::Parse(board, fen);

    //    auto bytes = std::array<uint8_t, 32>();
    //    Sfens::Serialize(board, bytes.data());

    //    auto a = 123;
    //}

    static void TestFenSerialize()
    {
        Fen fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
        Board board{};
        Fens::Parse(board, fen);

        auto fen2 = Fens::Serialize(board);
        std::cout << fen2 << std::endl;
    }
    
    static void TestSee()
    {
        Fen fen = "4k3/1b6/8/3p4/4p3/5P2/6B1/4K2B w - - 0 1";
        Board board{};
        Fens::Parse(board, fen);

        const Move move = board.FromPositionString("f3e4");
        const Score see = See::GetSee(board, move);
        std::cout << see << std::endl;
    }

    static void TestMagics()
    {
        Fen fen = "3k4/8/4p1p1/8/4Q3/5N2/8/3K4 w - - 0 1";
        Board board{};
        Fens::Parse(board, fen);

        const Bitboard attacks = SlideMoveGenerator::AllSlide(board.AllPieces, Positions::E4);
        std::cout << attacks << std::endl;
    }

    static void TestZobrist()
    {
        //Fen fen = "3k4/8/4p1p1/8/4Q3/5N2/8/3K4 w - - 0 1";
        Fen fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
        Board board{};
        Fens::Parse(board, fen);

        const ZobristKey key = ZobristKeys.CalculateKey(board);
        std::cout << std::hex << key << std::endl;
    }

    static size_t RunWithTiming(const std::function<void()>& function, const size_t times)
    {
        const auto start = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < times; i++)
        {
            function();
        }
        const auto end = std::chrono::high_resolution_clock::now();
        const auto elapsed = end - start;
        const auto elapsedNs = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
        return elapsedNs;
    }

    static void PrintWithTiming(const std::function<void()>& function, const size_t times)
    {
        const size_t elapsedNs = RunWithTiming(function, times);
        const auto perSecond = static_cast<uint64_t>((static_cast<double>(times) / static_cast<double>(elapsedNs)) * 1000000000);
        std::cout << ToUserFriendly(times) << "it: " << ToUserFriendly(elapsedNs / 1000000) << "ms (" << ToUserFriendly(perSecond) << "it/s)" << std::endl;
    }

    Tests() = delete;
};
