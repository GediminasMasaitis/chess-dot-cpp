#pragma once
#include <iostream>

#include "board.h"
#include "common.h"
#include "fen.h"
#include "magics.h"
#include "see.h"
#include "likeliness.h"
#include "movegen.h"
#include "tablebases.h"
#include "zobrist.h"
#include "fathom/tbprobe.h"

class Tests
{
public:
    static void TestUci()
    {
        Tablebases::Init();
        //std::vector<Fen> moveses =
        //{
        //    "e2e4 c7c5 g1f3 d7d6 d2d4 c5d4 d1d4 b8c6 f1b5 c8d7 d4d3 g7g6 e1g1 g8f6 b1c3 f8g7 c1f4 e8g8 a2a3 a7a6 b5c4 e7e5 f4e3 b7b5 c4b3 c6a5 d3d6 a5b3 c2b3 d7e6 d6b4 d8b8 e3g5 a6a5 b4b5 b8b5 c3b5 a8b8 b5c7 e6b3 g5f6 g7f6 a1c1 a5a4 c7a6 b8b5 c1c7 g6g5 a6c5 g5g4 f3d2 f6d8 c7c6 d8g5 d2b3 a4b3 f1d1 g5e7 c5d7 f8d8 c6c3 g8g7 c3c7 b5b6 g1f1 b6d6 d1d6 e7d6 c7b7 h7h5 a3a4 d8a8 d7b6 a8a6 b6c4 d6c5 c4e5 a6a4 b7f7 g7g8 f7f5 c5e7 f5h5 a4e4 h5f5 e4a4 f1e2 e7f8 e5d3 a4a7 f5g5 a7g7 g5g7 g8g7 e2d2 f8d6 d2c3 d6h2 g2g3 g7f6 c3b3 f6e6 b3a4 e6d5 b2b4 d5e4 b4b5 e4d5 b5b6 d5c6 a4a5 c6b7 d3c5 b7c6 b6b7 c6c7 a5a6 h2g1 a6a7 g1f2 b7b8Q c7c6 b8e8 c6c5 e8f8 c5c4 f8f2 c4d3 f2f5 d3c4 f5g4 c4c3 g4f3 c3c4 f3e4 c4c3 e4f3", // 69
        //    "e2e4 c7c5 g1f3 d7d6 d2d4 c5d4 d1d4 b8c6 f1b5 c8d7 d4d3 g7g6 e1g1 g8f6 b1c3 f8g7 c1f4 e8g8 a2a3 a7a6 b5c4 e7e5 f4e3 b7b5 c4b3 c6a5 d3d6 a5b3 c2b3 d7e6 d6b4 d8b8 e3g5 a6a5 b4b5 b8b5 c3b5 a8b8 b5c7 e6b3 g5f6 g7f6 a1c1 a5a4 c7a6 b8b5 c1c7 g6g5 a6c5 g5g4 f3d2 f6d8 c7c6 d8g5 d2b3 a4b3 f1d1 g5e7 c5d7 f8d8 c6c3 g8g7 c3c7 b5b6 g1f1 b6d6 d1d6 e7d6 c7b7 h7h5 a3a4 d8a8 d7b6 a8a6 b6c4 d6c5 c4e5 a6a4 b7f7 g7g8 f7f5 c5e7 f5h5 a4e4 h5f5 e4a4 f1e2 e7f8 e5d3 a4a7 f5g5 a7g7 g5g7 g8g7 e2d2 f8d6 d2c3 d6h2 g2g3 g7f6 c3b3 f6e6 b3a4 e6d5 b2b4 d5e4 b4b5 e4d5 b5b6 d5c6 a4a5 c6b7 d3c5 b7c6 b6b7 c6c7 a5a6 h2g1 a6a7 g1f2 b7b8Q c7c6 b8e8 c6c5 e8f8 c5c4 f8f2 c4d3 f2f5 d3c4 f5g4 c4c3 g4f3 c3c4 f3e4 c4c3 e4f3 c3c4",
        //    "e2e4 c7c5 g1f3 d7d6 d2d4 c5d4 d1d4 b8c6 f1b5 c8d7 d4d3 g7g6 e1g1 g8f6 b1c3 f8g7 c1f4 e8g8 a2a3 a7a6 b5c4 e7e5 f4e3 b7b5 c4b3 c6a5 d3d6 a5b3 c2b3 d7e6 d6b4 d8b8 e3g5 a6a5 b4b5 b8b5 c3b5 a8b8 b5c7 e6b3 g5f6 g7f6 a1c1 a5a4 c7a6 b8b5 c1c7 g6g5 a6c5 g5g4 f3d2 f6d8 c7c6 d8g5 d2b3 a4b3 f1d1 g5e7 c5d7 f8d8 c6c3 g8g7 c3c7 b5b6 g1f1 b6d6 d1d6 e7d6 c7b7 h7h5 a3a4 d8a8 d7b6 a8a6 b6c4 d6c5 c4e5 a6a4 b7f7 g7g8 f7f5 c5e7 f5h5 a4e4 h5f5 e4a4 f1e2 e7f8 e5d3 a4a7 f5g5 a7g7 g5g7 g8g7 e2d2 f8d6 d2c3 d6h2 g2g3 g7f6 c3b3 f6e6 b3a4 e6d5 b2b4 d5e4 b4b5 e4d5 b5b6 d5c6 a4a5 c6b7 d3c5 b7c6 b6b7 c6c7 a5a6 h2g1 a6a7 g1f2 b7b8Q c7c6 b8e8 c6c5 e8f8 c5c4 f8f2 c4d3 f2f5 d3c4 f5g4 c4c3 g4f3 c3c4 f3e4 c4c3 e4f3 c3c4 f3e4", // 70
        //    "e2e4 c7c5 g1f3 d7d6 d2d4 c5d4 d1d4 b8c6 f1b5 c8d7 d4d3 g7g6 e1g1 g8f6 b1c3 f8g7 c1f4 e8g8 a2a3 a7a6 b5c4 e7e5 f4e3 b7b5 c4b3 c6a5 d3d6 a5b3 c2b3 d7e6 d6b4 d8b8 e3g5 a6a5 b4b5 b8b5 c3b5 a8b8 b5c7 e6b3 g5f6 g7f6 a1c1 a5a4 c7a6 b8b5 c1c7 g6g5 a6c5 g5g4 f3d2 f6d8 c7c6 d8g5 d2b3 a4b3 f1d1 g5e7 c5d7 f8d8 c6c3 g8g7 c3c7 b5b6 g1f1 b6d6 d1d6 e7d6 c7b7 h7h5 a3a4 d8a8 d7b6 a8a6 b6c4 d6c5 c4e5 a6a4 b7f7 g7g8 f7f5 c5e7 f5h5 a4e4 h5f5 e4a4 f1e2 e7f8 e5d3 a4a7 f5g5 a7g7 g5g7 g8g7 e2d2 f8d6 d2c3 d6h2 g2g3 g7f6 c3b3 f6e6 b3a4 e6d5 b2b4 d5e4 b4b5 e4d5 b5b6 d5c6 a4a5 c6b7 d3c5 b7c6 b6b7 c6c7 a5a6 h2g1 a6a7 g1f2 b7b8Q c7c6 b8e8 c6c5 e8f8 c5c4 f8f2 c4d3 f2f5 d3c4 f5g4 c4c3 g4f3 c3c4 f3e4 c4c3 e4f3 c3c4 f3e4 c4c3",
        //};

        std::vector<Fen> moveses =
        {
            "f2f4 d7d5 g1f3 g8f6 b2b3 g7g6 c1b2 f8g7 e2e3 e8g8 f1e2 c7c5 e1g1 b8c6 f3e5 d8d6 e5c6 d6c6 e2f3 c8f5 d2d3 h7h6 d1d2 g6g5 f4g5 h6g5 c2c4 c6d7 c4d5 g5g4 f3e2 d7d5 e3e4 f6e4 d3e4 d5d2 b1d2 g7b2 e4f5 b2d4 g1h1 d4a1 f1a1 a8d8 d2e4 d8d4 e4c5 b7b6 c5d3 f8c8 h1g1 d4e4 e2f1 c8c2 a2a3 g8g7 d3b4 c2d2 a1c1 e4f4 b4c6 g7f6 c1e1 f4f5 c6e7 f5a5 a3a4 a5c5 f1c4 d2d7 e7g8 f6g7 e1e8 d7d2 g8e7 c5e5 c4f1 f7f6 e8g8 g7f7 g8g4 e5e7 f1c4 f7e8 g1f1 e8d8 g4f4 e7h7 h2h3 d8e7 f4f2 d2f2 f1f2 e7d6 f2f3 d6e5 f3e2 f6f5 e2f3 a7a5 f3e3 f5f4 e3f3 h7d7 h3h4 d7h7 g2g3 f4g3 f3g3 e5e4 c4e2 h7g7 e2g4 e4d4 g3f4 g7e7 g4f3 e7h7 f4g3 h7d7 f3e2 d4e3 e2g4 d7d3 h4h5 e3e4 g3h4 d3b3 h5h6 b3d3 h6h7 d3d8 h4g5 e4e5 g5g6 d8e8 g4d7 e8d8 d7f5 d8a8 f5g4 a8b8 g4h5 e5e6 g6g7 b8b7 g7g6 b7b8 h5e2 e6e5 e2c4 b8h8 g6g7 h8h7 g7h7 e5f5 c4e2 f5f6 h7h6 f6f5 e2d3 f5e5 h6g5 e5d4 d3f1 d4e5 g5g6 e5e6 f1c4 e6d6 g6f5 d6c5 c4f1 c5d6 f1b5 d6d5 f5f6 d5d6 f6f5 d6d5 f5f6 d5d6 b5d3 d6d5 f6e7 d5c6"
        };
    	
        std::queue<std::string> commands = std::queue<std::string>();
        commands.push("uci");
        commands.push("ucinewgame");

        for (const auto& moves : moveses)
        {
            commands.push("position startpos moves " + moves);
            commands.push("isready");
            //commands.push("go wtime 60000 winc 600 btime 60000 binc 600");
            //commands.push("go infinite depth 10");
            commands.push("go wtime 70 btime 107 winc 50 binc 50");
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

    static void TestRepetitions()
    {
        Fen fen = "3k4/6p1/2r5/8/8/8/1R4P1/3K4 w - - 0 1";
        Board board{};
        Fens::Parse(board, fen);

        board.DoMove("b2b3");
        board.DoMove("c6c5");
        board.DoMove("g2g3");
        board.DoMove("g7g6");
        board.DoMove("b3b2");
        board.DoMove("c5c6");
    	
        //const ZobristKey key = ZobristKeys.CalculateKey(board);
        auto callback = [&](SearchCallbackData& data) { };
        auto search = Search(callback);

        auto isRepetition = search.IsRepetitionOr50Move(board);
    	
        std::cout << std::hex << isRepetition << std::endl;
    }

    static void TestTablebases()
    {
        //Fen fen = "3k4/8/2r5/8/8/8/1R4P1/3K4 w - - 0 1";
        Fen fen = "3k4/8/2r5/8/8/8/1R3Q2/3K4 w - - 0 1";
        //Fen fen = "8/8/5k2/8/8/8/1P6/RK3q2 w - - 0 1";
        Board board{};
        Fens::Parse(board, fen);

        MoveArray engineMoves = MoveArray();
        MoveCount engineMoveCount = 0;
        MoveGenerator::GetAllPossibleMoves(board, engineMoves, engineMoveCount);
    	

        Tablebases::Init();
        auto result = Tablebases::Probe(board);

        //TbRootMoves moves;
    	
        //auto result = tb_probe_root
        //(
        //    board.BitBoard[Colors::White],
        //    board.BitBoard[Colors::Black],
        //    board.BitBoard[Pieces::WhiteKing] | board.BitBoard[Pieces::BlackKing],
        //    board.BitBoard[Pieces::WhiteQueen] | board.BitBoard[Pieces::BlackQueen],
        //    board.BitBoard[Pieces::WhiteRook] | board.BitBoard[Pieces::BlackRook],
        //    board.BitBoard[Pieces::WhiteBishop] | board.BitBoard[Pieces::BlackBishop],
        //    board.BitBoard[Pieces::WhiteKnight] | board.BitBoard[Pieces::BlackKnight],
        //    board.BitBoard[Pieces::WhitePawn] | board.BitBoard[Pieces::BlackPawn],
        //    0, 0, 0, board.WhiteToMove, false, false, &moves
        //);

        std::cout << static_cast<int16_t>(result) << std::endl;
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
