#include "input.h"

#include <iostream>
#include <sstream>

namespace tictactoe {

template <class T>
auto Input::GetSingleUserInput(const std::string& msg) const -> T {
  std::string str;
  T res;
  while (std::cout << msg && std::getline(std::cin, str)) {
    std::istringstream iss(str);
    if (iss >> res) { return res; }
  }
}

auto Input::GetCellNumber(const std::unique_ptr<tictactoe::Grid>& grid,
                          const std::string& player_label) const -> int {
  while (true) {
    auto cell_num = GetSingleUserInput<int>("[" + player_label +
        "] Enter the cell number: ");
    if (cell_num >= 0 && cell_num < kGridSquareSize &&
        !grid->GetCellState(cell_num)) {
      return cell_num;
    } else if (cell_num >= 0 && cell_num < kGridSquareSize &&
        grid->GetCellState(cell_num)) {
      std::cout << "There is already the mark in this cell.\n";
    } else {
      std::cout << "The cell number must be in the range 0-\n"
                << kGridSquareSize - 1 << ".\n";
    }
  }
}

auto Input::GetFirstPlayer() const -> player_label_t {
  while (true) {
    auto player_mark = GetSingleUserInput<char>(
        "Enter the mark of the player who will move first (x/o): ");
    if (player_mark == 'x') {
      return PlayerLabel::kMarkX;
    } else if (player_mark == 'o') {
      return PlayerLabel::kMarkO;
    } else {
      std::cout << "The player's mark must be \"x\" or \"o\".\n";
    }
  }
}

auto Input::GetAnswerAboutReplay() const -> bool {
  while (true) {
    auto answer = GetSingleUserInput<char>(
        "Do you want to play again? (y/n): ");
    if (answer == 'y') {
      return true;
    } else if (answer == 'n') {
      return false;
    } else {
      std::cout << "The answer must be \"y\" or \"n\".\n";
    }
  }
}

}  // namespace tictactoe