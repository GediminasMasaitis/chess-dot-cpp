// ChessDotCpp.cpp : Defines the entry point for the application.
//

#include "ChessDotCpp.h"
#include "fen.h"
#include "movegen.h"
#include "perft.h"

using namespace std;

int main()
{
	Fen fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
	//auto board = std::make_unique<Board>();
	//auto board = Board();
	//Fens::Parse(board, fen);

	

	//auto move = Move(9, 17, ChessPiece::WhitePawn);
	//board.DoMove(move);
	//board.UndoMove();

	//auto moves = MoveArray();
	//size_t moveCount = 0;
	//MoveGenerator::GetAllPossibleMoves(board, moves, moveCount);

	PerftRunner::Run(fen, 6);
	
	//cout << nodes << endl;
	return 0;
}
