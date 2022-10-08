#ifndef TICTACTOE_GRID_H_
#define TICTACTOE_GRID_H_

#include <array>
#include <string>

#include "player.h"

namespace tictactoe {

// In fact, the game can work with any size (> 2).
const int kGridSize{3};
// Sometimes you need to know the square size.
const int kGridSquareSize{kGridSize * kGridSize};

// A fixed-size grid class.
class Grid {
 public:
  // Print a grid with cell numbers (if the cell is empty).
  // Otherwise, if the cell is not empty, then print its contents.
  //
  // For example:
  // 0 | 1 | 2
  // 3 | x | 5
  // 6 | 7 | 8
  auto Print() const -> void;

  // Getting the row or column by cell number.
  auto GetRow(int cell_num) const -> int { return cell_num / kGridSize; }
  auto GetColumn(int cell_num) const -> int { return cell_num % kGridSize; }

  auto GetCellState(int row, int col) const -> player_label_t {
    return grid_[row][col].player_label;
  }
  auto SetCellState(int row, int col, player_label_t cell_state) -> void {
    grid_[row][col].player_label = cell_state;
  }

  // Overloaded encapsulation for working with the cell number.
  auto GetCellState(int cell_num) const -> player_label_t {
    return GetCellState(GetRow(cell_num), GetColumn(cell_num));
  }
  auto SetCellState(int cell_num, player_label_t cell_state) -> void {
    SetCellState(GetRow(cell_num), GetColumn(cell_num), cell_state);
  }

  // Convert cell state to a string (e.g. PlayerLabel::kMarkX -> "x").
  auto ToString(player_label_t cell_state) const -> std::string;

  // Filling the grid array with an empty cell state.
  auto Reset() -> void { grid_.fill({std::nullopt}); }

 private:
  struct CellState { player_label_t player_label; };
  std::array<std::array<CellState, kGridSize>, kGridSize> grid_;
};

}  // namespace tictactoe

#endif  // TICTACTOE_GRID_H_