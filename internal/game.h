#ifndef TICTACTOE_INTERNAL_GAME_H_
#define TICTACTOE_INTERNAL_GAME_H_

#include <memory>

#include "input.h"
#include "grid.h"

namespace tictactoe {

class Game {
 public:
  // Starting the main game cycle.
  auto Run(const std::unique_ptr<Input>& input,
           std::unique_ptr<Grid>& grid) -> void;

 private:
  // Processing the player's move includes:
  // 1. Getting the cell number via input.
  // 2. Entering the player's label into the grid by the number.
  // 3. Processing and return the result of the move.
  auto ProcessPlayerMove(const std::unique_ptr<Input>& input,
                         std::unique_ptr<Grid>& grid) -> bool;

  // Swap the current player.
  auto PassMoveToNextPlayer() -> void {
    curr_player_ = (curr_player_ == PlayerLabel::kMarkX) ?
        PlayerLabel::kMarkO : PlayerLabel::kMarkX;
  }

  player_label_t curr_player_;
};

}  // namespace tictactoe

#endif  // TICTACTOE_INTERNAL_GAME_H_