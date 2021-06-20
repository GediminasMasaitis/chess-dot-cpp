#pragma once

#include "board.h"

enum class TablebaseResult : int8_t
{
	Unknown,
	Win,
	Draw,
	Loss
};

class Tablebases
{
public:
	static void Init();
	static bool CanProbe(const Board& board);
	static TablebaseResult Probe(const Board& board);
	static bool ProbeRoot(const Board& board, Move& tbMove);
};
