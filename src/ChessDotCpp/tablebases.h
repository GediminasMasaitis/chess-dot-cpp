#pragma once

#include "board.h"

class Tablebases
{
public:
	static void Init();
	static bool CanProbe(const Board& board);
	static GameOutcome Probe(const Board& board);
	static bool ProbeRoot(const Board& board, Move& tbMove);
};
