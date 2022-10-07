#include "grid.h"

#include <iostream>

namespace tictactoe {

auto Grid::Print() const -> void {
  int cell_num{0};
  for (int row = 0; row < kGridSize; ++row) {
    for (int col = 0; col < kGridSize; ++col) {
      auto cell_state{GetCellState(row, col)};
      if (cell_state) {
        if (col != kGridSize - 1) {
          std::cout << ToString(cell_state) << " | ";
        } else {
          std::cout << ToString(cell_state);
        }
      } else {
        if (col != kGridSize - 1) {
          std::cout << cell_num << " | ";
        } else {
          std::cout << cell_num;
        }
      }

      ++cell_num;
    }

    std::cout << "\n";
  }
}

auto Grid::ToString(player_label_t cell_state) const -> std::string {
  if (cell_state == PlayerLabel::kMarkX) {
    return "x";
  } else if (cell_state == PlayerLabel::kMarkO) {
    return "o";
  } else {
    return " ";
  }
}

}  // namespace tictactoe