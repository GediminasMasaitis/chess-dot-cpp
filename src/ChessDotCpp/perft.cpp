#include "perft.h"

#include "movegen.h"

using MoveStack = std::array<MoveArray, 7>;

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

size_t InternalPerftClient::GetMovesAndNodes(Board& board, Ply depth, MoveAndNodeArray& movesAndNodes, size_t& moveAndNodeCount)
{
	if (depth == 0)
	{
		throw std::exception("Invalid depth");
	}

	auto moveStack = MoveStack();
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


