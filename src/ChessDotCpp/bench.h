#pragma once

#include "common.h"

#include <chrono>
#include <functional>
#include <iostream>

class Bench
{
public:
	static size_t RunWithTiming(const std::function<void()>& function, const size_t times)
	{
		const auto start = std::chrono::high_resolution_clock::now();
		for(size_t i = 0; i < times; i++)
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
};
