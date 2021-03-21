#include "perft.h"

#include "movegen.h"
#include "fen.h"

#include <iostream>
#include <chrono>

size_t GetNodesInner(Board& board, Ply depth, MoveStack& moveStack)
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
		return possibleMoveCount;
	}

	size_t nodes = 0;
	for (auto i = 0; i < possibleMoveCount; i++)
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
	size_t possibleMoveCount = 0;
	MoveGenerator::GetAllPossibleMoves(board, possibleMoves, possibleMoveCount);
	size_t totalNodes = 0;
	for (auto i = 0; i < possibleMoveCount; i++)
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

void RunIteration(Fen fen, Ply depth)
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
	auto elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed);

	std::cout << "Depth: " << depth << ", Perft nodes: " << nodes << ", " << elapsedMs << " ms" << std::endl;
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


