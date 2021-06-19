#pragma once

#include "types.h"

#include <string>
#include <iostream>
#include <unordered_map>

struct LikelinessEntry
{
	size_t trues = 0;
	size_t falses = 0;
};

class Likeliness
{
	inline static std::unordered_map<std::string, LikelinessEntry> entries{};

	static LikelinessEntry& GetOrCreate(const std::string& location)
	{

		return entries[location];
	}

public:
	static void Add(const std::string& location, bool result)
	{
		if (entries.find(location) == entries.end())
		{
			entries[location] = LikelinessEntry();
		}

		if (result)
		{
			entries[location].trues++;
		}
		else
		{
			entries[location].falses++;
		}
	}

	static void PrintStats()
	{
		for (const auto& entry : entries)
		{
			const size_t sum = entry.second.trues + entry.second.falses;
			const double percent = 100 * static_cast<double>(entry.second.trues) / sum;
			std::cout << entry.first << "   " << entry.second.trues << ":" << entry.second.falses << "; " << percent << "% true" << std::endl;
		}
	}

	Likeliness() = delete;
};

inline static size_t is_likely_true = 0;
inline static size_t is_likely_false = 0;
#define S1(x) #x
#define S2(x) S1(x)
#define LOCATION __FILE__ ":" S2(__LINE__)
#define CONCAT_(x,y) x##y
#define CONCAT(x,y) CONCAT_(x,y)
#define UNIQUENAME CONCAT(likely_,__LINE__)
#define IFLIEKLY(x) const bool UNIQUENAME = (x); Likeliness::Add(LOCATION, UNIQUENAME); if(UNIQUENAME)
