cmake_minimum_required(VERSION 3.17)
project(battleship)

set(CMAKE_CXX_STANDARD 14)

add_executable(battleship main.cpp src/CBateau.cpp src/CBateau.h src/testCBateau.cpp src/BiblioStd.h)