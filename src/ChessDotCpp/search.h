#pragma once
#include "board.h"
#include "evaluation.h"

class PlyData
{
};
using PlyDataArray = std::array<PlyData, Constants::MaxDepth>;

class ThreadData
{
public:
	PlyDataArray Plies;
};
using ThreadVector = std::vector<ThreadData>;

class GlobalData
{
public:
	
};

class SearchStats
{
public:
	
};

class SearchData
{
public:
	ThreadVector Thread;
	GlobalData Global;
	SearchStats Stats;
	
	SearchData()
	{
		Thread = ThreadVector(1);
		Global = GlobalData();
		Stats = SearchStats();
	}
};

class Search
{
public:
	static void Run(Board& board)
	{
		SearchData data = SearchData();
	}

	static void IterativeDeepen(Board& board, SearchData& data)
	{
		Score score = AlphaBeta(board, data, 1, 0, -Constants::Inf, Constants::Inf);
		for (Ply depth = 2; depth < Constants::MaxDepth; depth++)
		{
			score = Aspiration(board, data, depth, score);
		}
	}

	static Score Aspiration(Board& board, SearchData& data, const Ply depth, const Score previous)
	{
		AlphaBeta(board, data, depth, 0, -Constants::Inf, Constants::Inf);
		return 0;
	}
	
	static Score AlphaBeta(Board& board, SearchData& data, Ply depth, Ply ply, Score alpha, Score beta)
	{
		Score staticScore = Evaluation::Evaluate(board);
		if(depth <= 0)
		{
			return staticScore;
		}
		
		MoveArray moves;
		return 0;
	}
	
	Search() = delete;
};
