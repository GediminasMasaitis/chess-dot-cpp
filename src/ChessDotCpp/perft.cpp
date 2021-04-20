#include "perft.h"

#include "movegen.h"
#include "fen.h"

#include <iostream>
#include <chrono>
#include <algorithm>

size_t GetNodesInner(Board& board, Move parentMove, Ply depth, MoveStack& moveStack)
{
	if (depth == 0)
	{
		return 1;
	}

	auto possibleMoves = moveStack[depth];
	size_t possibleMoveCount = 0;
	MoveGenerator::GetAllPossibleMoves(board, possibleMoves, possibleMoveCount);
	if (depth == 1)
	{
		//std::cout << parentMove.ToPositionString() << ": " << Fens::Serialize(board) << " " << possibleMoveCount << std::endl;
		//std::sort(possibleMoves.begin(), possibleMoves.begin() + possibleMoveCount, [](const Move& lhs, const Move& rhs) {return lhs.ToPositionString() < rhs.ToPositionString(); });
		//for (auto i = 0; i < possibleMoveCount; i++)
		//{
		//	auto& move = possibleMoves[i];
		//	std::cout << move.ToPositionString() << std::endl;
		//}
		return possibleMoveCount;
	}

	size_t nodes = 0;
	for (size_t i = 0; i < possibleMoveCount; i++)
	{
		auto& move = possibleMoves[i];
		board.DoMove(move);
		const size_t childNodes = GetNodesInner(board, move, depth - 1, moveStack);
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
	size_t possibleMoveCount = 0;
	MoveGenerator::GetAllPossibleMoves(board, possibleMoves, possibleMoveCount);
	size_t totalNodes = 0;
	for (size_t i = 0; i < possibleMoveCount; i++)
	{
		auto& move = possibleMoves[i];
		//auto boardStr1 = Fens::Serialize(board);
		board.DoMove(move);
		const size_t nodes = GetNodesInner(board, move, depth - 1, moveStack);
		board.UndoMove();
		//auto boardStr2 = Fens::Serialize(board);
		//assert(boardStr1 == boardStr2);
		totalNodes += nodes;
		const auto moveStr = move.ToPositionString();
		const auto moveAndNodes = MoveAndNodes(moveStr, nodes, move);
		movesAndNodes[moveAndNodeCount++] = moveAndNodes;
	}
	return totalNodes;
}

void RunIteration(Fen fen, Ply depth)
{
	auto board = Board();
	Fens::Parse(board, fen);
	//board.DoMove("a2a4");
	
	/*board.UndoMove();
	board.DoMove("b2b4");*/
	
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
}

void IterativeDeepen(Fen fen, Ply depth)
{
	for (Ply i = 1; i <= depth; i++)
	{
		RunIteration(fen, i);
		/*var result = RunComparison(fen, i);
		if (!result.Correct)
		{
			RunFaultyLineSearch(fen, i, result);
			break;
		}*/
	}
}

void PerftRunner::Run(Fen fen, Ply depth)
{
	assert(depth > 0);

	std::cout << "Running perft up to depth " << depth << " for position " << fen << std::endl;
	IterativeDeepen(fen, depth);
}


