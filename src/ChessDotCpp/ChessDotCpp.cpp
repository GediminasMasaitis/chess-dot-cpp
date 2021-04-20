// ChessDotCpp.cpp : Defines the entry point for the application.
//

#include "ChessDotCpp.h"
#include "fen.h"
#include "movegen.h"
#include "perft.h"
#include "magics.h"
#include "iostream"
#include "fstream"
#include "random.h"
#include "search.h"

using namespace std;

int main()
{
	
	//ofstream magics;
	//magics.open("C:/Temp/magics.txt");
	//for(auto value : MagicsData.Table)
	//{
	//	magics << "0x" << std::hex << value << ",\n";
	//}
	//magics.close();
	
	Fen fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
	//Fen fen = "r1bqkbnr/pppppppp/n7/3P4/8/1N6/PPP1PPPP/R1BQKBNR b KQkq - 0 1";

	PerftRunner::Run(fen, 7);
	//Board board;
	//Fens::Parse(board, fen);
	//Search::Run(board);
	
	//cout << nodes << endl;
	return 0;
}
