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
#include "evaluation.h"
#include "tune.h"
#include "uci.h"


void UciStdOut(const std::string& str)
{
    std::cout << str << std::endl;
}

std::string UciStdIn()
{
    std::string line;
    std::getline(std::cin, line);
    return line;
}

void Run()
{
    auto uci = Uci(&std::cin, &std::cout);
    uci.Run();
}

void Test()
{
    //ofstream magics;
    //magics.open("C:/Temp/magics.txt");
    //for(auto value : MagicsData.Table)
    //{
    //	magics << "0x" << std::hex << value << ",\n";
    //}
    //magics.close();

    Fen fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    //Fen fen = "r4rk1/p2n1ppp/3qp3/6B1/N5P1/3P1b2/PPP1BbP1/R2Q1R1K b - - 0 14";

    //PerftRunner::Run(fen, 7);


    Board board = Board();
    Fens::Parse(board, fen);

    SearchParameters search_parameters = SearchParameters();
    search_parameters.MaxDepth = Constants::MaxDepth;
    search_parameters.Infinite = true;

    //Search::Run(board, search_parameters, Uci::OnCallback);

    //EachColor<Bitboard> pins;
    //PinDetector::GetPinnedToKings(board, pins);
    //Score score;

    //Bench::PrintWithTiming([&]()
    //{
    //        auto rng = PRNG();
    //        auto num = 0;
    //        for (auto i = 0; i < 2000000000; i++)
    //        {
    //            if (rng.rand64() < 4611686018427387904ULL) [[likely]]
    //            {
    //                num++;
    //            }
    //        }
    //        cout << num << std::endl;
    //}, 1);
}

int main()
{
    Run();
    return 0;
}
