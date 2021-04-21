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
#include "bench.h";

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
    
    //Fen fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    Fen fen = "r4rk1/p2n1ppp/3qp3/6B1/N5P1/3P1b2/PPP1BbP1/R2Q1R1K b - - 0 14";
    
    //PerftRunner::Run(fen, 7);
    Board board = Board();
    Fens::Parse(board, fen);

    EachColor<Bitboard> pins;
    PinDetector::GetPinnedToKings(board, pins);
    Score score;
    Bench::PrintWithTiming([&]()
    {
        score = Evaluation::Evaluate(board, pins);
    }, 100000000);
    cout << score << std::endl;
    //Search::Run(board);
    
    
    return 0;
}
