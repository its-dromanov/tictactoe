#include "tictactoe.h"

#include <memory>

#include "input.h"
#include "grid.h"
#include "game.h"

namespace tictactoe {

auto TicTacToeMain(int argc, char **argv) -> int {
  auto input = std::make_unique<Input>();
  auto grid = std::make_unique<Grid>();
  auto game = std::make_unique<Game>();

  game->Run(input, grid);

  return 0;
}

}  // namespace tictactoe

auto main(int argc, char **argv) -> int {
  return tictactoe::TicTacToeMain(argc, argv);
}