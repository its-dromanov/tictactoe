cmake_minimum_required(VERSION 3.23)
project(tictactoe)

set(CMAKE_CXX_STANDARD 23)

add_executable(tictactoe tictactoe.cpp tictactoe.h internal/game.cpp internal/game.h internal/grid.cpp internal/grid.h internal/player.h internal/input.cpp internal/input.h)
