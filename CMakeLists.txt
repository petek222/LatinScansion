cmake_minimum_required(VERSION 3.13)
project(LatinScansion)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -pedantic-errors")


add_executable(LatinScansion LatinScansion.h LatinScansion.cpp LatinScansionDriver.cpp)