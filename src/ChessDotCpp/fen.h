#pragma once

#include <string>

#include "board.h"

class Fens
{
public:
	static void Parse(Board& board, Fen fen);
	static Fen Serialize(const Board& board);
};
