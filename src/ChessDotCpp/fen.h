#pragma once

#include <string>

#include "board.h"

class Fen
{
	//static Piece TryParsePiece(char ch);
public:
	static void Parse(Board& board, std::string fen);
};
