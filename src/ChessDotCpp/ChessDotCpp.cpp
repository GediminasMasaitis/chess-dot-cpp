#include "ChessDotCpp.h"

#include "bench.h"
#include "tests.h"
#include "uci.h"
#include "evaluation.h"
#include "nnuetrain.h"

void Run(int argc, char** argv)
{
    EvaluationNnue::Init();
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
    //std::cout << sizeof(TranspositionTableEntry) << std::endl;
    //Game::RunTestCommands();

    //Tests::TestSee();
    //Tests::TestMagics();
    //Tests::TestZobrist();
    //Tests::TestUci();
    //Tests::TestSfen();
    Tests::TestFenSerialize();
    
    //PerftSuite::Run();
}

void Train()
{
    NnueTrainer::Run();
}

int main(int argc, char** argv)
{
    //Test();
    Train();
    //Run(argc, argv);
    return 0;
}
