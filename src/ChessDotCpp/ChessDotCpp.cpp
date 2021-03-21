// ChessDotCpp.cpp : Defines the entry point for the application.
//

#include "ChessDotCpp.h"
#include "fen.h"
#include "movegen.h"
#include "perft.h"

using namespace std;

int main()
{
	//auto board = std::make_unique<Board>();
	auto board = Board();
	Fen::Parse(board, "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

	

	//auto move = Move(9, 17, ChessPiece::WhitePawn);
	//board.DoMove(move);
	//board.UndoMove();

	auto moves = MoveArray();
	size_t moveCount = 0;
	MoveGenerator::GetAllPossibleMoves(board, moves, moveCount);

	auto movesAndNodes = MoveAndNodeArray();
	size_t moveAndNodeCount = 0;
	auto nodes = InternalPerftClient::GetMovesAndNodes(board, 5, movesAndNodes, moveAndNodeCount);
	
	cout << nodes << endl;
	return 0;
}
