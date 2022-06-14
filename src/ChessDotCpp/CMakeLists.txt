# CMakeList.txt : CMake project for ChessDotCpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.12)

# Add source to this project's executable.
add_executable (ChessDotCpp "ChessDotCpp.cpp" "ChessDotCpp.h" "board.h" "board.cpp" "types.h" "constants.h" "zobrist.h" "move.h" "common.h" "fen.h" "fen.cpp" "perft.h" "perft.cpp" "movegen.h" "movegen.cpp" "magics.h" "magics.cpp" "move.cpp"   "bits.h" "PerftExternal.cpp" "random.h" "search.h" "evaluationClassical.h" "error.h" "evaluationClassical.cpp" "attacks.h" "attacks.cpp" "bench.h" "search.cpp" "tune.h" "uci.h" "uci.cpp" "stopper.h" "moveorder.h" "searchstate.h" "moveorder.cpp" "debug.h" "searchhash.h" "game.h" "see.h" "tests.h" "options.h" "polyglot.h" "evaluationNnue.h" "evaluationNnue.cpp" "nncpuprobe/misc.cpp" "nncpuprobe/misc.h" "nncpuprobe/nncpu.cpp" "nncpuprobe/nncpu.h" "nncpuprobe/simd.h" "nncpuprobe/nncupucommon.h" "evaluation.h"  "trainnnue.h" "trainnnue.cpp" "abdada.h"  "likeliness.h" "fathom/stdendian.h" "fathom/tbchess.h" "fathom/tbconfig.h" "fathom/tbprobe.cpp" "fathom/tbprobe.h" "tablebases.h" "tablebases.cpp" "trainbase.h" "trainbase.cpp" "trainclassical.h" "trainclassical.cpp" "pgn.h" "evaluationClassical2.h" "naiveBayes.h" "texel.h" "eval4ku.h" "evaluationClassical2.h" "evaluationClassical2.cpp" "threadpool_old.h" "threadpool.h" "datagen.h" "evaluationNnue2.h" "evaluationNnueBase.h" "simd.h")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /openmp")
# add_definitions(-D__cplusplus)
# TODO: Add tests and install targets if needed.
