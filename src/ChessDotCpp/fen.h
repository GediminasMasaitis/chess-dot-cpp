#pragma once

#include <string>

#include "board.h"

class Fens
{
public:
	template<class TBoard>
	static void Parse(TBoard& board, Fen fen);

	template<class TBoard>
	static Fen Serialize(const TBoard& board);
};
