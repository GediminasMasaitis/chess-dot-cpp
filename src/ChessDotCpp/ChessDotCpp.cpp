#include "ChessDotCpp.h"

#include "bench.h"
#include "tests.h"
#include "uci.h"
#include "evaluation.h"
#include "perft.h"
#include "tablebases.h"


void Run(int argc, char** argv)
{
    EvaluationNnue::Init();
    Tablebases::Init();
    Eval2::InitEvalMasks();
    if(argc > 1)
    {
        std::string param1 = argv[1];
        if(param1 == "bench")
        {
            Bench::Run(1);
            return;
        }
    }
    
    auto uci = UciStd();
    uci.Run();
}

void Test()
{
    //std::cout << sizeof(UndoMove) << std::endl;
    //Game::RunTestCommands();

    //Tests::TestSee();
    //Tests::TestMagics();
    //Tests::TestZobrist();
    //Tests::TestRepetitions();
    //Tests::TestUci();
    Tests::TestEval();
    //Tests::TestTablebases();
    
    //Tests::TestSfen();
    //Tests::TestFenSerialize();
    //Tests::TestPgnParse();
    
    //PerftRunner::Run(Uci::StartingFen, 6);
}


int main(int argc, char** argv)
{
    //std::cout << sizeof(BoardBase) << std::endl;
    //Test();
    //Train();
    Run(argc, argv);
    return 0;
}
