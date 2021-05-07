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
			"r3r1kb/p2bp2p/1q1p1npB/5NQ1/2p1P1P1/2N2P2/PPP5/2KR3R b - - 0 1"
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
