# CMakeList.txt : CMake project for ChessDotCpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Add source to this project's executable.
add_executable (ChessDotCpp "ChessDotCpp.cpp" "board.cpp" "fen.cpp" "perft.cpp" "movegen.cpp" "magics.cpp" "move.cpp" "attacks.cpp" "search.cpp" "uci.cpp" "moveorder.cpp" "tablebases.cpp" "evaluationClassical2.cpp" "movepick.cpp" "searchhash.cpp" "evaluationNnueBase.cpp" "external/fathom/src/tbprobe.cpp")

set_source_files_properties("external/fathom/src/tbprobe.cpp" PROPERTIES LANGUAGE CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /openmp")

# add_definitions(-D__cplusplus)
# TODO: Add tests and install targets if needed.
