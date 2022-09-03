#pragma once
#include <iostream>

#include "board.h"
#include "common.h"
#include "fen.h"
#include "magics.h"
#include "see.h"
#include "movegen.h"
#include "tablebases.h"
#include "zobrist.h"
#include "evaluation.h"
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
            "c2c4 c7c5 g1f3 g8f6 g2g3 b7b6 f1g2 c8b7 b1c3 e7e6 e1g1 f8e7 d2d4 c5d4 d1d4 d7d6 f1d1 a7a6 d4d3 e8g8 c1g5 b8d7 d3c2 d8c7 b2b3 h7h6 g5f4 g7g5 f4e3 f6g4 e3c1 f7f5 h2h3 g4e5 f3e5 d7e5 g2b7 c7b7 f2f4 e5g6 e2e4 g5f4 c1f4 g6f4 g3f4 f5e4 c3e4 a8d8 d1f1 d6d5 c4d5 e6d5 e4g3 e7c5 g1h2 g8h8 a1e1 d5d4 e1e6 d4d3 c2c3 c5d4 e6h6 h8g7 c3c6 b7c6 h6c6 d3d2 f1d1 d4e3 f4f5 e3f4 h2g2 f4g3 g2g3 f8f5 c6b6 a6a5 b6c6 f5e5 c6c7 g7f6 c7c2 e5g5 g3h2 g5d5 h3h4 f6g6 h2g3 g6h5 g3f4 d8d6 c2c4 d6d7 f4e3 d5d3 e3f2 d3d6 c4e4 d7c7 f2e2 c7c2 e4e5 h5h4 a2a4 h4g4 e5a5 g4f4 a5b5 c2a2 b5b4 f4e5 b4b8 a2c2 b3b4 d6d4 a4a5 e5e6 a5a6 c2a2 b4b5 d4h4 e2e3 h4h2 b8e8 e6d7 e8g8 a2a3 e3d4 d7e6 d4c5 a3a2 c5b4 e6f7 g8g3 h2h4 b4b3 h4a4 d1f1 f7e6 g3e3 e6d5 e3d3 d5e5 d3d2 a4a3 b3b4 a3a4 b4c3 a4a3 c3b4 a3a4 b4c3 a4a3"
        };
        
        std::queue<std::string> commands = std::queue<std::string>();
        commands.push("uci");
        commands.push("ucinewgame");

        for (const auto& moves : moveses)
        {
            commands.push("position startpos moves " + moves);
            commands.push("isready");
            commands.push("go wtime 60000 winc 600 btime 60000 binc 600");
            //commands.push("go infinite depth 3");
            //commands.push("go wtime 70 btime 107 winc 50 binc 50");
        }
        commands.push("quit");
        Game::RunCommands(commands);
    }

    static void TestUciFen()
    {
        std::queue<std::string> commands = std::queue<std::string>();
        commands.push("uci");
        commands.push("ucinewgame");
        //commands.push("position fen 8/1p3p1p/p4P1k/P4P1p/6pP/6Pq/5P2/6K1 b - - moves h3g3 f2g3");
        commands.push("position fen 8/1p3p1p/p4P1k/P4P1p/6pP/6Pq/5P2/6K1 b - - moves");
        commands.push("go infinite");
        commands.push("quit");
        Game::RunCommands(commands);
    }

    static void TestEval()
    {
        //TestEvalClass::Init();
        EvaluationNnueBase::Init();

        //Fen fen = "rnbqkb1r/pppppppp/8/8/8/8/PPPPPPPP/RNBQK1NR w KQkq - 0 1";
        //Fen fen = "3k4/4b3/8/8/P4RB1/4P3/6KP/1R6 b - - 2 40";

        //Fen fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
        Fen fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNB1KBNR w KQkq - 0 1";

        Board board{};
        Fens::Parse(board, fen);

        EachColor<Bitboard> pins;
        PinDetector::GetPinnedToKings(board, pins);
        const auto score = CallEval(board, pins);
        std::cout << score << std::endl;
    }

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
        auto search = Search(nullptr);

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
