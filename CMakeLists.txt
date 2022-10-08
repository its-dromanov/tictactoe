cmake_minimum_required(VERSION 3.23)
project(tictactoe)

set(CMAKE_CXX_STANDARD 23)

add_executable(tictactoe tictactoe/tictactoe.cpp tictactoe/tictactoe.h tictactoe/game.cpp tictactoe/game.h tictactoe/grid.cpp tictactoe/grid.h tictactoe/player.h tictactoe/input.cpp tictactoe/input.h)
