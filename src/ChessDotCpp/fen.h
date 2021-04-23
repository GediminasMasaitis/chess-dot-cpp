#pragma once

#include <string>

#include "board.h"

class Fens
{
	//static Piece TryParsePiece(char ch);
public:
	static void Parse(Board& board, Fen fen);
	static Fen Serialize(const Board& board);

	static void Flip(Board& board, Board& target);
};
