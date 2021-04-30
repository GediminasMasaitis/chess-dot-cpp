#include "ChessDotCpp.h"

#include "bench.h"
#include "tests.h"
#include "uci.h"

void Run(int argc, char** argv)
{
	if(argc > 1)
	{
        std::string param1 = argv[1];
		if(param1 == "bench")
		{
            Bench::Run();
			return;
		}
	}
	
    auto uci = UciStd();
    uci.Run();
}

void Test()
{
    //Game::RunTestCommands();

    Tests::TestSee();
    
    //PerftSuite::Run();
    
    //ofstream magics;
    //magics.open("C:/Temp/magics.txt");
    //for(auto value : MagicsData.Table)
    //{
    //	magics << "0x" << std::hex << value << ",\n";
    //}
    //magics.close();

    //Fen fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    //Fen fen = "rnbqkbnr/pppppppp/8/8/1P6/8/P1PPPPPP/RNBQKBNR b KQkq - 0 1";
    ////Fen fen = "r4rk1/p2n1ppp/3qp3/6B1/N5P1/3P1b2/PPP1BbP1/R2Q1R1K b - - 0 14";

    ////PerftRunner::Run(fen, 7);


    //Board board = Board();
    //Fens::Parse(board, fen);

    //EachColor<Bitboard> pins;
    //PinDetector::GetPinnedToKings(board, pins);
    //Score eval1 = Evaluation::Evaluate(board, pins);
    //
    //auto key = board.Key;
    //board.FlipColors();

    //PinDetector::GetPinnedToKings(board, pins);
    //Score eval2 = Evaluation::Evaluate(board, pins);   
    //auto key2 = board.Key;
    //auto fen2 = Fens::Serialize(board);

    //board.FlipColors();
    //auto key3 = board.Key;
    //auto fen3 = Fens::Serialize(board);
    //PinDetector::GetPinnedToKings(board, pins);
    //Score eval3 = Evaluation::Evaluate(board, pins);

    //SearchParameters search_parameters = SearchParameters();
    //search_parameters.MaxDepth = Constants::MaxDepth;
    //search_parameters.Infinite = true;

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

int main(int argc, char** argv)
{
    Run(argc, argv);
    //Test();
    //Game::RunTestCommands();
    return 0;
}
