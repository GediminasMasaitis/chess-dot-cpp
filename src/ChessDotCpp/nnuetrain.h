#pragma once
#include <string>

#include "searchstate.h"

//class TrainingSearchResults
//{
//public:
//	Score _Score;
//	HistoryPly HistoryPly;
//};

enum class ResultFormats : uint8_t
{
	Plain
};

class TrainingParameters
{
public:
	std::string InputPath;
	std::string OutputPath;
	std::string OffsetPath;
	ResultFormats ResultFormat;
	SearchParameters SearchParams;
};

class NnueTrainer
{
public:
	static void Run(const TrainingParameters& parameters);
};
