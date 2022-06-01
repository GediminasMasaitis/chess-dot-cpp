#include "ChessDotCpp.h"

#include "bench.h"
#include "tests.h"
#include "uci.h"
#include "evaluation.h"
#include "perft.h"
#include "tablebases.h"
#include "texel.h"
#include "evaluationClassical2.h"

void Run(int argc, char** argv)
{
    EvaluationNnue::Init();
    Tablebases::Init();
    Eval2::InitEvalMasks();
    EvaluationClassical2::Init();
    if(argc > 1)
    {
        std::string param1 = argv[1];
        if(param1 == "bench")
        {
            Bench::Run(1);
            return;
        }
        else if (param1 == "tune")
        {
            Texel::Run();
        }
    }
    
    auto uci = UciStd();
    uci.Run();
}

void Test()
{
    //std::cout << sizeof(UndoMove) << std::endl;
    //Game::RunTestCommands();
    Game::RunCuteChessOutput();

    //Tests::TestSee();
    //Tests::TestMagics();
    //Tests::TestZobrist();
    //Tests::TestRepetitions();
    //Tests::TestUci();
    //Tests::TestEval();
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
