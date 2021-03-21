# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.12)
set(CMAKE_CXX_STANDARD 20)

project ("ChessDotCpp")

# Include sub-projects.
add_subdirectory ("ChessDotCpp")
