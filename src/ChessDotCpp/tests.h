#pragma once
#include <iostream>

#include "board.h"
#include "common.h"
#include "fen.h"
#include "magics.h"
#include "see.h"

class Tests
{
public:
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
