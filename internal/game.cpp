#include "game.h"

#include <iostream>

namespace tictactoe {

auto Game::ProcessPlayerMove(const std::unique_ptr<Input>& input,
                             std::unique_ptr<Grid>& grid) -> bool {
  int cell_num = input->GetCellNumber(grid, grid->ToString(curr_player_));

  grid->SetCellState(cell_num, curr_player_);

  // Count the number of marks in different directions.
  int horiz{0}, vert{0}, l_diag{0}, r_diag{0};
  int rev_i{kGridSize - 1};  // For counting on the right diagonal (reverse index).
  for (int i = 0; i < kGridSize; ++i) {
    // Horizontally.
    if (grid->GetCellState(grid->GetRow(cell_num), i) == curr_player_) {
      ++horiz;
    }
    // Vertically.
    if (grid->GetCellState(i, grid->GetColumn(cell_num)) == curr_player_) {
      ++vert;
    }
    // Left diagonal.
    if (grid->GetCellState(i, i) == curr_player_) {
      ++l_diag;
    }
    // Right diagonal.
    if (grid->GetCellState(rev_i, i) == curr_player_) {
      ++r_diag;
    }
    --rev_i;
  }

  // Checking the victory of the current player in any direction.
  return (horiz == kGridSize || vert == kGridSize ||
          l_diag == kGridSize || r_diag == kGridSize);
}

auto Game::Run(const std::unique_ptr<Input>& input,
               std::unique_ptr<Grid>& grid) -> void {
  std::cout << "Welcome to the tic-tac-toe game!\n\n";

  do {
    curr_player_ = input->GetFirstPlayer();
    std::cout << "Game on!\n";
    grid->Print();

    while (!ProcessPlayerMove(input, grid)) {
      grid->Print();
      PassMoveToNextPlayer();
    }

    std::cout << "The end! The " << grid->ToString(curr_player_)
              << "-player has won!\n";
    grid->Reset();
  } while (input->GetAnswerAboutReplay());

  std::cout << "\nThanks for playing!\n";
}

}  // namespace tictactoe