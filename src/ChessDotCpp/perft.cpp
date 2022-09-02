#include "perft.h"

#include "movegen.h"
#include "fen.h"

#include <iostream>
#include <chrono>
#include <algorithm>

size_t GetNodesInner(Board& board, Ply depth, MoveStack& moveStack)
{
	if (depth == 0)
	{
		return 1;
	}

	auto possibleMoves = moveStack[depth];
	MoveCount possibleMoveCount = 0;
	MoveGenerator::GetAllPossibleMoves(board, possibleMoves, possibleMoveCount);
	if (depth == 1)
	{
		return possibleMoveCount;
	}

	size_t nodes = 0;
	for (MoveCount i = 0; i < possibleMoveCount; i++)
	{
		auto& move = possibleMoves[i];
		board.DoMove(move);
		const size_t childNodes = GetNodesInner(board, depth - 1, moveStack);
		board.UndoMove();
		nodes += childNodes;
	}
	return nodes;
}

size_t InternalPerftClient::GetMovesAndNodes(Board& board, Ply depth, MoveStack& moveStack, MoveAndNodeArray& movesAndNodes, size_t& moveAndNodeCount)
{
	assert(depth > 0);
	moveAndNodeCount = 0;
	auto possibleMoves = moveStack[depth];
	MoveCount possibleMoveCount = 0;
	MoveGenerator::GetAllPossibleMoves(board, possibleMoves, possibleMoveCount);
	size_t totalNodes = 0;
	for (MoveCount i = 0; i < possibleMoveCount; i++)
	{
		auto& move = possibleMoves[i];
		board.DoMove(move);
		const size_t nodes = GetNodesInner(board, depth - 1, moveStack);
		board.UndoMove();
		totalNodes += nodes;
		const auto moveStr = move.ToPositionString();
		const auto moveAndNodes = MoveAndNodes(moveStr, nodes, move);
		movesAndNodes[moveAndNodeCount++] = moveAndNodes;
	}
	return totalNodes;
}

size_t RunIteration(Fen fen, Ply depth)
{
	auto board = Board();
	Fens::Parse(board, fen);
    auto moveStack = MoveStack();
	MoveAndNodeArray movesAndNodes;
	size_t moveAndNodeCount = 0;
	auto start = std::chrono::high_resolution_clock::now();
	size_t nodes = InternalPerftClient::GetMovesAndNodes(board, depth, moveStack, movesAndNodes, moveAndNodeCount);
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = end - start;
	const auto elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
	const auto elapsedNs = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
	const auto nps = static_cast<uint64_t>(static_cast<double>(nodes * 1000000000) / static_cast<double>(elapsedNs));

	std::cout << "Depth: " << std::to_string(depth) << ", Perft nodes: " << nodes << ", " << elapsedMs << "ms (" << ToUserFriendly(nps) << "N/s)" << std::endl;
	std::sort(movesAndNodes.begin(), movesAndNodes.begin() + moveAndNodeCount, [](const MoveAndNodes& lhs, const MoveAndNodes& rhs) {return lhs.MovePos < rhs.MovePos; });
	for(size_t i = 0; i < moveAndNodeCount; i++)
	{
		auto& moveAndNodes = movesAndNodes[i];
		std::cout << moveAndNodes.MovePos << ": " << moveAndNodes.Nodes << std::endl;
	}
	return nodes;
}

size_t IterativeDeepen(Fen fen, Ply depth)
{
	size_t count = 0;
	for (Ply i = 1; i <= depth; i++)
	{
		count = RunIteration(fen, i);
		/*var result = RunComparison(fen, i);
		if (!result.Correct)
		{
			RunFaultyLineSearch(fen, i, result);
			break;
		}*/
	}
	return count;
}

size_t PerftRunner::Run(Fen fen, Ply depth)
{
	assert(depth > 0);

	std::cout << "Running perft up to depth " << depth << " for position " << fen << std::endl;

	
	return IterativeDeepen(fen, depth);
}

class PerftSuiteEntry
{
public:
	Fen fen;
	Ply depth;
	size_t expected;
};



void PerftSuite::Run()
{
	auto entries = std::vector<PerftSuiteEntry>
	{
		PerftSuiteEntry{ "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 6, 119060324 },
		PerftSuiteEntry{ "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1", 5, 193690690 },
		PerftSuiteEntry{ "4k3/8/8/8/8/8/8/4K2R w K - 0 1", 6, 764643 },
		PerftSuiteEntry{ "4k3/8/8/8/8/8/8/R3K3 w Q - 0 1", 6, 846648 },
		PerftSuiteEntry{ "4k2r/8/8/8/8/8/8/4K3 w k - 0 1", 6, 899442 },
		PerftSuiteEntry{ "r3k3/8/8/8/8/8/8/4K3 w q - 0 1", 6, 1001523 },
		PerftSuiteEntry{ "4k3/8/8/8/8/8/8/R3K2R w KQ - 0 1", 6, 2788982 },
		PerftSuiteEntry{ "r3k2r/8/8/8/8/8/8/4K3 w kq - 0 1", 6, 3517770 },
		PerftSuiteEntry{ "8/8/8/8/8/8/6k1/4K2R w K - 0 1", 6, 185867 },
		PerftSuiteEntry{ "8/8/8/8/8/8/1k6/R3K3 w Q - 0 1", 6, 413018 },
		PerftSuiteEntry{ "4k2r/6K1/8/8/8/8/8/8 w k - 0 1", 6, 179869 },
		PerftSuiteEntry{ "r3k3/1K6/8/8/8/8/8/8 w q - 0 1", 6, 367724 },
		PerftSuiteEntry{ "r3k2r/8/8/8/8/8/8/R3K2R w KQkq - 0 1", 6, 179862938 },
		PerftSuiteEntry{ "r3k2r/8/8/8/8/8/8/1R2K2R w Kkq - 0 1", 6, 195629489 },
		PerftSuiteEntry{ "r3k2r/8/8/8/8/8/8/2R1K2R w Kkq - 0 1", 6, 184411439 },
		PerftSuiteEntry{ "r3k2r/8/8/8/8/8/8/R3K1R1 w Qkq - 0 1", 6, 189224276 },
		PerftSuiteEntry{ "1r2k2r/8/8/8/8/8/8/R3K2R w KQk - 0 1", 6, 198328929 },
		PerftSuiteEntry{ "2r1k2r/8/8/8/8/8/8/R3K2R w KQk - 0 1", 6, 185959088 },
		PerftSuiteEntry{ "r3k1r1/8/8/8/8/8/8/R3K2R w KQq - 0 1", 6, 190755813 },
		PerftSuiteEntry{ "4k3/8/8/8/8/8/8/4K2R b K - 0 1", 6, 899442 },
		PerftSuiteEntry{ "4k3/8/8/8/8/8/8/R3K3 b Q - 0 1", 6, 1001523 },
		PerftSuiteEntry{ "4k2r/8/8/8/8/8/8/4K3 b k - 0 1", 6, 764643 },
		PerftSuiteEntry{ "r3k3/8/8/8/8/8/8/4K3 b q - 0 1", 6, 846648 },
		PerftSuiteEntry{ "4k3/8/8/8/8/8/8/R3K2R b KQ - 0 1", 6, 3517770 },
		PerftSuiteEntry{ "r3k2r/8/8/8/8/8/8/4K3 b kq - 0 1", 6, 2788982 },
		PerftSuiteEntry{ "8/8/8/8/8/8/6k1/4K2R b K - 0 1", 6, 179869 },
		PerftSuiteEntry{ "8/8/8/8/8/8/1k6/R3K3 b Q - 0 1", 6, 367724 },
		PerftSuiteEntry{ "4k2r/6K1/8/8/8/8/8/8 b k - 0 1", 6, 185867 },
		PerftSuiteEntry{ "r3k3/1K6/8/8/8/8/8/8 b q - 0 1", 6, 413018 },
		PerftSuiteEntry{ "r3k2r/8/8/8/8/8/8/R3K2R b KQkq - 0 1", 6, 179862938 },
		PerftSuiteEntry{ "r3k2r/8/8/8/8/8/8/1R2K2R b Kkq - 0 1", 6, 198328929 },
		PerftSuiteEntry{ "r3k2r/8/8/8/8/8/8/2R1K2R b Kkq - 0 1", 6, 185959088 },
		PerftSuiteEntry{ "r3k2r/8/8/8/8/8/8/R3K1R1 b Qkq - 0 1", 6, 190755813 },
		PerftSuiteEntry{ "1r2k2r/8/8/8/8/8/8/R3K2R b KQk - 0 1", 6, 195629489 },
		PerftSuiteEntry{ "2r1k2r/8/8/8/8/8/8/R3K2R b KQk - 0 1", 6, 184411439 },
		PerftSuiteEntry{ "r3k1r1/8/8/8/8/8/8/R3K2R b KQq - 0 1", 6, 189224276 },
		PerftSuiteEntry{ "8/1n4N1/2k5/8/8/5K2/1N4n1/8 w - - 0 1", 6, 8107539 },
		PerftSuiteEntry{ "8/1k6/8/5N2/8/4n3/8/2K5 w - - 0 1", 6, 2594412 },
		PerftSuiteEntry{ "8/8/4k3/3Nn3/3nN3/4K3/8/8 w - - 0 1", 6, 19870403 },
		PerftSuiteEntry{ "K7/8/2n5/1n6/8/8/8/k6N w - - 0 1", 6, 588695 },
		PerftSuiteEntry{ "k7/8/2N5/1N6/8/8/8/K6n w - - 0 1", 6, 688780 },
		PerftSuiteEntry{ "8/1n4N1/2k5/8/8/5K2/1N4n1/8 b - - 0 1", 6, 8503277 },
		PerftSuiteEntry{ "8/1k6/8/5N2/8/4n3/8/2K5 b - - 0 1", 6, 3147566 },
		PerftSuiteEntry{ "8/8/3K4/3Nn3/3nN3/4k3/8/8 b - - 0 1", 6, 4405103 },
		PerftSuiteEntry{ "K7/8/2n5/1n6/8/8/8/k6N b - - 0 1", 6, 688780 },
		PerftSuiteEntry{ "k7/8/2N5/1N6/8/8/8/K6n b - - 0 1", 6, 588695 },
		PerftSuiteEntry{ "B6b/8/8/8/2K5/4k3/8/b6B w - - 0 1", 6, 22823890 },
		PerftSuiteEntry{ "8/8/1B6/7b/7k/8/2B1b3/7K w - - 0 1", 6, 28861171 },
		PerftSuiteEntry{ "k7/B7/1B6/1B6/8/8/8/K6b w - - 0 1", 6, 7881673 },
		PerftSuiteEntry{ "K7/b7/1b6/1b6/8/8/8/k6B w - - 0 1", 6, 7382896 },
		PerftSuiteEntry{ "B6b/8/8/8/2K5/5k2/8/b6B b - - 0 1", 6, 9250746 },
		PerftSuiteEntry{ "8/8/1B6/7b/7k/8/2B1b3/7K b - - 0 1", 6, 29027891 },
		PerftSuiteEntry{ "k7/B7/1B6/1B6/8/8/8/K6b b - - 0 1", 6, 7382896 },
		PerftSuiteEntry{ "K7/b7/1b6/1b6/8/8/8/k6B b - - 0 1", 6, 7881673 },
		PerftSuiteEntry{ "7k/RR6/8/8/8/8/rr6/7K w - - 0 1", 6, 44956585 },
		PerftSuiteEntry{ "R6r/8/8/2K5/5k2/8/8/r6R w - - 0 1", 6, 525169084 },
		PerftSuiteEntry{ "7k/RR6/8/8/8/8/rr6/7K b - - 0 1", 6, 44956585 },
		PerftSuiteEntry{ "R6r/8/8/2K5/5k2/8/8/r6R b - - 0 1", 6, 524966748 },
		PerftSuiteEntry{ "6kq/8/8/8/8/8/8/7K w - - 0 1", 6, 391507 },
		PerftSuiteEntry{ "6KQ/8/8/8/8/8/8/7k b - - 0 1", 6, 391507 },
		PerftSuiteEntry{ "K7/8/8/3Q4/4q3/8/8/7k w - - 0 1", 6, 3370175 },
		PerftSuiteEntry{ "6qk/8/8/8/8/8/8/7K b - - 0 1", 6, 419369 },
		PerftSuiteEntry{ "6KQ/8/8/8/8/8/8/7k b - - 0 1", 6, 391507 },
		PerftSuiteEntry{ "K7/8/8/3Q4/4q3/8/8/7k b - - 0 1", 6, 3370175 },
		PerftSuiteEntry{ "8/8/8/8/8/K7/P7/k7 w - - 0 1", 6, 6249 },
		PerftSuiteEntry{ "8/8/8/8/8/7K/7P/7k w - - 0 1", 6, 6249 },
		PerftSuiteEntry{ "K7/p7/k7/8/8/8/8/8 w - - 0 1", 6, 2343 },
		PerftSuiteEntry{ "7K/7p/7k/8/8/8/8/8 w - - 0 1", 6, 2343 },
		PerftSuiteEntry{ "8/2k1p3/3pP3/3P2K1/8/8/8/8 w - - 0 1", 6, 34834 },
		PerftSuiteEntry{ "8/8/8/8/8/K7/P7/k7 b - - 0 1", 6, 2343 },
		PerftSuiteEntry{ "8/8/8/8/8/7K/7P/7k b - - 0 1", 6, 2343 },
		PerftSuiteEntry{ "K7/p7/k7/8/8/8/8/8 b - - 0 1", 6, 6249 },
		PerftSuiteEntry{ "7K/7p/7k/8/8/8/8/8 b - - 0 1", 6, 6249 },
		PerftSuiteEntry{ "8/2k1p3/3pP3/3P2K1/8/8/8/8 b - - 0 1", 6, 34822 },
		PerftSuiteEntry{ "8/8/8/8/8/4k3/4P3/4K3 w - - 0 1", 6, 11848 },
		PerftSuiteEntry{ "4k3/4p3/4K3/8/8/8/8/8 b - - 0 1", 6, 11848 },
		PerftSuiteEntry{ "8/8/7k/7p/7P/7K/8/8 w - - 0 1", 6, 10724 },
		PerftSuiteEntry{ "8/8/k7/p7/P7/K7/8/8 w - - 0 1", 6, 10724 },
		PerftSuiteEntry{ "8/8/3k4/3p4/3P4/3K4/8/8 w - - 0 1", 6, 53138 },
		PerftSuiteEntry{ "8/3k4/3p4/8/3P4/3K4/8/8 w - - 0 1", 6, 157093 },
		PerftSuiteEntry{ "8/8/3k4/3p4/8/3P4/3K4/8 w - - 0 1", 6, 158065 },
		PerftSuiteEntry{ "k7/8/3p4/8/3P4/8/8/7K w - - 0 1", 6, 20960 },
		PerftSuiteEntry{ "8/8/7k/7p/7P/7K/8/8 b - - 0 1", 6, 10724 },
		PerftSuiteEntry{ "8/8/k7/p7/P7/K7/8/8 b - - 0 1", 6, 10724 },
		PerftSuiteEntry{ "8/8/3k4/3p4/3P4/3K4/8/8 b - - 0 1", 6, 53138 },
		PerftSuiteEntry{ "8/3k4/3p4/8/3P4/3K4/8/8 b - - 0 1", 6, 158065 },
		PerftSuiteEntry{ "8/8/3k4/3p4/8/3P4/3K4/8 b - - 0 1", 6, 157093 },
		PerftSuiteEntry{ "k7/8/3p4/8/3P4/8/8/7K b - - 0 1", 6, 21104 },
		PerftSuiteEntry{ "7k/3p4/8/8/3P4/8/8/K7 w - - 0 1", 6, 32191 },
		PerftSuiteEntry{ "7k/8/8/3p4/8/8/3P4/K7 w - - 0 1", 6, 30980 },
		PerftSuiteEntry{ "k7/8/8/7p/6P1/8/8/K7 w - - 0 1", 6, 41874 },
		PerftSuiteEntry{ "k7/8/7p/8/8/6P1/8/K7 w - - 0 1", 6, 29679 },
		PerftSuiteEntry{ "k7/8/8/6p1/7P/8/8/K7 w - - 0 1", 6, 41874 },
		PerftSuiteEntry{ "k7/8/6p1/8/8/7P/8/K7 w - - 0 1", 6, 29679 },
		PerftSuiteEntry{ "k7/8/8/3p4/4p3/8/8/7K w - - 0 1", 6, 22886 },
		PerftSuiteEntry{ "k7/8/3p4/8/8/4P3/8/7K w - - 0 1", 6, 28662 },
		PerftSuiteEntry{ "7k/3p4/8/8/3P4/8/8/K7 b - - 0 1", 6, 32167 },
		PerftSuiteEntry{ "7k/8/8/3p4/8/8/3P4/K7 b - - 0 1", 6, 30749 },
		PerftSuiteEntry{ "k7/8/8/7p/6P1/8/8/K7 b - - 0 1", 6, 41874 },
		PerftSuiteEntry{ "k7/8/7p/8/8/6P1/8/K7 b - - 0 1", 6, 29679 },
		PerftSuiteEntry{ "k7/8/8/6p1/7P/8/8/K7 b - - 0 1", 6, 41874 },
		PerftSuiteEntry{ "k7/8/6p1/8/8/7P/8/K7 b - - 0 1", 6, 29679 },
		PerftSuiteEntry{ "k7/8/8/3p4/4p3/8/8/7K b - - 0 1", 6, 22579 },
		PerftSuiteEntry{ "k7/8/3p4/8/8/4P3/8/7K b - - 0 1", 6, 28662 },
		PerftSuiteEntry{ "7k/8/8/p7/1P6/8/8/7K w - - 0 1", 6, 41874 },
		PerftSuiteEntry{ "7k/8/p7/8/8/1P6/8/7K w - - 0 1", 6, 29679 },
		PerftSuiteEntry{ "7k/8/8/1p6/P7/8/8/7K w - - 0 1", 6, 41874 },
		PerftSuiteEntry{ "7k/8/1p6/8/8/P7/8/7K w - - 0 1", 6, 29679 },
		PerftSuiteEntry{ "k7/7p/8/8/8/8/6P1/K7 w - - 0 1", 6, 55338 },
		PerftSuiteEntry{ "k7/6p1/8/8/8/8/7P/K7 w - - 0 1", 6, 55338 },
		PerftSuiteEntry{ "3k4/3pp3/8/8/8/8/3PP3/3K4 w - - 0 1", 6, 199002 },
		PerftSuiteEntry{ "7k/8/8/p7/1P6/8/8/7K b - - 0 1", 6, 41874 },
		PerftSuiteEntry{ "7k/8/p7/8/8/1P6/8/7K b - - 0 1", 6, 29679 },
		PerftSuiteEntry{ "7k/8/8/1p6/P7/8/8/7K b - - 0 1", 6, 41874 },
		PerftSuiteEntry{ "7k/8/1p6/8/8/P7/8/7K b - - 0 1", 6, 29679 },
		PerftSuiteEntry{ "k7/7p/8/8/8/8/6P1/K7 b - - 0 1", 6, 55338 },
		PerftSuiteEntry{ "k7/6p1/8/8/8/8/7P/K7 b - - 0 1", 6, 55338 },
		PerftSuiteEntry{ "3k4/3pp3/8/8/8/8/3PP3/3K4 b - - 0 1", 6, 199002 },
		PerftSuiteEntry{ "8/Pk6/8/8/8/8/6Kp/8 w - - 0 1", 6, 1030499 },
		PerftSuiteEntry{ "n1n5/1Pk5/8/8/8/8/5Kp1/5N1N w - - 0 1", 6, 37665329 },
		PerftSuiteEntry{ "8/PPPk4/8/8/8/8/4Kppp/8 w - - 0 1", 6, 28859283 },
		PerftSuiteEntry{ "n1n5/PPPk4/8/8/8/8/4Kppp/5N1N w - - 0 1", 6, 71179139 },
		PerftSuiteEntry{ "8/Pk6/8/8/8/8/6Kp/8 b - - 0 1", 6, 1030499 },
		PerftSuiteEntry{ "n1n5/1Pk5/8/8/8/8/5Kp1/5N1N b - - 0 1", 6, 37665329 },
		PerftSuiteEntry{ "8/PPPk4/8/8/8/8/4Kppp/8 b - - 0 1", 6, 28859283 },
		PerftSuiteEntry{ "n1n5/PPPk4/8/8/8/8/4Kppp/5N1N b - - 0 1", 6, 71179139 }
	};

	for (size_t i = 0; i < entries.size(); i++)
	{
		const auto& entry = entries[i];
		const size_t nodes = PerftRunner::Run(entry.fen, entry.depth);
		if(nodes != entry.expected)
		{
			std::cout << "Error! Expected " << entry.expected << " but found " << nodes << std::endl;
			break;
		}
	}
}


