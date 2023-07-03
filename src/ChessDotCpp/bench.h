#pragma once

#include "common.h"
#include "game.h"
#include "options.h"
#include "search.h"

class Bench
{
public:
	static void Run()
	{
		// Positions that I initially generated for 4ku
		// Should work fine for this as well.
		const std::array<std::pair<Fen, int>, 25> bench_positions = { {
			{"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 16},         // Phase 24
			{"r1n2rk1/1pq2pp1/4bn1p/N1bpp3/4P3/3QBP2/PPP1B1PP/2KR3R w - - 0 1", 16},  // Phase 23
			{"r1bq1rk1/pp2p1bp/2p3p1/1P3p2/2QPn3/6P1/PB1NPPBP/R4RK1 b - - 0 1", 16},  // Phase 22
			{"r3r1k1/ppqn1p2/4bppp/8/2PB4/1P1B2b1/P1Q2PPP/R3R1K1 w - - 0 1", 14},     // Phase 21
			{"r4rk1/pp3ppp/2nppq2/8/2BPb3/4P3/PP1N1PPP/R2Q1RK1 b - - 0 1", 16},       // Phase 20
			{"r2q2k1/1p1r4/p4b2/2Bn2p1/4Q3/6PP/PP3P2/R2R2K1 w - - 0 1", 13},          // Phase 19
			{"2bq1rk1/1pn2ppp/3p4/p2Np3/4P1P1/PN2BP2/1PP3QP/2K1b2R w - - 0 1", 17},   // Phase 18
			{"2rr3k/1p3pp1/1Q2b2p/pP2p3/P1B1P3/3P2R1/5P1P/2q3NK w - - 0 1", 18},      // Phase 17
			{"4k2r/3nbp1p/pqp1p3/3p2p1/3P1B2/4PPN1/PP2QP1P/2R3K1 b k - 0 1", 16},     // Phase 16
			{"6k1/5p2/p3p1p1/2qnQ3/6P1/1r5P/1P2R2K/5R2 w - - 0 1", 15},               // Phase 15
			{"q1b2rk1/2R1Qp1p/p5p1/1p6/1P1Np2P/P3P1P1/5P2/6K1 b - - 0 1", 17},        // Phase 14
			{"6k1/3q2b1/1nNp4/3Pp1pp/4Pp2/5P2/6PP/2RQ2K1 w - - 0 1", 17},             // Phase 13
			{"1r3rk1/p4p2/2p1bp1p/3Pb3/8/1P1BN3/P4PPP/4RRK1 b - - 0 1", 16},          // Phase 12
			{"5b2/5k1p/4bpp1/2p5/4Pq2/3PN2P/2P2PP1/Q5K1 w - - 0 1", 14},              // Phase 11
			{"3k4/2p5/p2qn3/1p1pNQ2/1P6/P6P/6P1/5K2 b - - 0 1", 14},                  // Phase 10
			{"r1b3k1/2p2ppp/1b6/p3N3/5B2/2P5/PP4PP/R2n1K2 b - - 0 1", 16},            // Phase 9
			{"2k5/1pp2Q1p/8/8/5P2/3q4/P5K1/8 b - - 0 1", 18},                         // Phase 8
			{"8/1R4b1/3k4/3npp1p/3p3P/r2P1NP1/4PP2/6K1 w - - 0 1", 16},               // Phase 7
			{"8/2p2p2/2Bb1kp1/R6p/P6P/r5P1/4PPK1/8 b - - 0 1", 16},                   // Phase 6
			{"8/5b2/pr4p1/4k2p/8/P1K3P1/7P/5R2 w - - 0 1", 17},                       // Phase 5
			{"8/7R/8/4p1k1/1r6/3K4/8/8 b - - 0 1", 15},                               // Phase 4
			{"8/8/5kp1/5p1p/4pP1P/6P1/4K3/2R3b1 b - - 0 1", 24},                      // Phase 3
			{"8/8/3bB3/7p/8/pK4kP/8/8 w - - 0 1", 26},                                // Phase 2
			{"8/5k2/P6P/5b2/P7/3p4/3K4/8 b - - 0 1", 20},                             // Phase 1
			{"8/8/p1Pk2pp/3p1p2/p4P2/6P1/5K1P/8 w - - 0 1", 16}                       // Phase 0
		} };

		auto target_depth = 0;
		int64_t total_nodes = 0;
		int phase = 0;
		auto search = Search([&phase, &total_nodes, &target_depth](SearchCallbackData& data)
		{
			if(data.Depth != target_depth)
			{
				return;
            }

			const ThreadState& mainThreadState = data.State.Thread[0];
			std::stringstream builder = std::stringstream();

			builder << "info";
			builder << "phase " << (phase - 1);
			builder << " depth " << std::to_string(data.Depth);
			builder << " seldepth " << std::to_string(data.State.Thread[0].SelectiveDepth);

			builder << " multipv " << static_cast<uint32_t>(data.MultiPv + 1);
			if (data._Score > Constants::MateThreshold)
			{
				const Score mateInPlies = static_cast<Score>(Constants::Mate - data._Score);
				const Score mateInMoves = static_cast<Score>((mateInPlies + 1) / 2);
				builder << " score mate " << std::to_string(mateInMoves);
			}
			else if (data._Score < -Constants::MateThreshold)
			{
				const Score mateInPlies = static_cast<Score>(Constants::Mate + data._Score);
				const Score mateInMoves = static_cast<Score>((mateInPlies + 1) / 2);
				builder << " score mate -" << std::to_string(mateInMoves);
			}
			else
			{
				builder << " score cp " << std::to_string(data._Score);
			}

			total_nodes += mainThreadState.Stats.Nodes;
			builder << " nodes " << std::to_string(mainThreadState.Stats.Nodes);
			auto elapsed = mainThreadState.Stats.Elapsed;
			if (elapsed == 0)
			{
				elapsed = 1;
			}

			Stat nodes = 0;
			for (auto i = 0; i < Options::Threads; i++)
			{
				nodes += data.State.Thread[i].Stats.Nodes;
			}

			auto nps = (nodes * 1000) / elapsed;

			builder << " nps " << nps;
			builder << " time " << elapsed;

			builder << " pv";
			const auto& principalVariation = mainThreadState.SavedPrincipalVariations[data.MultiPv];
			for (MoveCount ply = 0; ply < principalVariation.Length; ply++)
			{
				const auto& entry = principalVariation.Moves[ply];
				builder << " " << entry.ToPositionString();
			}
			builder << std::endl;
			std::cout << builder.str();
		});

		const auto start = std::chrono::high_resolution_clock::now();
		//for(auto& pair : bench_positions)
		for(auto index = 0; index < bench_positions.size(); index++)
		{
			auto& pair = bench_positions[index];
			Board board;
			Fens::Parse(board, pair.first);

			SearchParameters parameters;
			parameters.Infinite = true;
			parameters.UciThread = true;
			parameters.MaxDepth = pair.second;

			phase = 25 - index;
			target_depth = pair.second;
			SearchResults results;
			search.State.NewGame();
			search.Run(board, parameters, results);
		}
		const auto end = std::chrono::high_resolution_clock::now();
		const auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

		std::stringstream final_builder = std::stringstream();
		final_builder << "Bench: ";
		final_builder << elapsed_ms << " ms ";
		final_builder << total_nodes << " nodes ";
		final_builder << total_nodes * 1000 / std::max(elapsed_ms, static_cast<int64_t>(1)) << " nps\n";
		std::cout << final_builder.str();
	}
};
