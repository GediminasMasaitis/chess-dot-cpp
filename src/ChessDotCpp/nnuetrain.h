#pragma once
#include <string>

#include "searchstate.h"

//class TrainingSearchResults
//{
//public:
//	Score _Score;
//	HistoryPly HistoryPly;
//};

enum class OutputFormats : uint8_t
{
	Plain
};


enum class InputFormats : uint8_t
{
	Epd,
	Plain
};

class TrainingParameters
{
public:
	InputFormats InputFormat;
	std::string InputPath;
	
	OutputFormats OutputFormat;
	std::string OutputPath;
	
	std::string OffsetPath;
	
	SearchParameters SearchParams;
};

class NnueTrainer
{
public:
	static void Run(const TrainingParameters& parameters);
};
