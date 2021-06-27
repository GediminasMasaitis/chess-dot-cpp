#pragma once

#include "common.h"
#include "game.h"
#include "options.h"

class Bench
{
public:
	static void Run(ThreadId threads)
	{
		ThreadId originalThreads = Options::Threads;
		Options::Threads = threads;
		std::vector<Fen> fens =
		{
			"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1",
			"r3r1kb/p2bp2p/1q1p1npB/5NQ1/2p1P1P1/2N2P2/PPP5/2KR3R b - - 0 1",
			//"r1r3k1/4bpp1/p6p/1p1q1P2/P2p4/1P1Q4/3B1PPP/R3R1K1 b - -",
			//"8/1R4pk/5p1p/r1b4P/1p3B2/5KP1/4N3/8 w - -",
			//"8/7p/5p2/4k3/r3n2K/6P1/2R4P/8 b - -",
			//"6k1/2R5/r1N1K2p/7P/3p1P2/2b5/8/8 w - -",
			//"3rr1k1/ppnq1pbp/2p3p1/P3pbB1/1PN1B2P/2PP2P1/2Q2P2/2R1R1K1 b - -",
			//"8/8/3k4/8/p7/4RK2/8/r7 b - -",
			//"5rk1/5pbp/p2r1qp1/Qpp5/8/P1P1PB1P/1P3PP1/1R3RK1 w - -",
		};

		std::queue<std::string> commands = std::queue<std::string>();
		commands.push("uci");
		
		for (const auto& fen : fens)
		{
			commands.push("ucinewgame");
			commands.push("position fen " + fen);
			commands.push("isready");
			commands.push("go wtime 60000 winc 600 btime 60000 binc 600");
		}
		commands.push("quit");
		Game::RunCommands(commands);
		Options::Threads = originalThreads;
	}
};
