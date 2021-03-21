# CMakeList.txt : CMake project for ChessDotCpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.12)

# Add source to this project's executable.
add_executable (ChessDotCpp "ChessDotCpp.cpp" "ChessDotCpp.h" "board.h" "board.cpp" "types.h" "constants.h" "zobrist.h" "move.h" "common.h" "fen.h" "fen.cpp" "perft.h" "perft.cpp" "movegen.h" "movegen.cpp" "magics.h" "magics.cpp" "move.cpp")

set(CMAKE_CXX_STANDARD 20)

# TODO: Add tests and install targets if needed.
