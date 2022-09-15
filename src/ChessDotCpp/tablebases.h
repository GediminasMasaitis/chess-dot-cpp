#pragma once

#include "board.h"

class Tablebases
{
public:
	static inline bool Initialized = false;

	static void Init(const std::string& path);
	static bool CanProbe(const Board& board);
	static GameOutcome Probe(const Board& board);
	static bool ProbeRoot(const Board& board, Move& tbMove);
};
