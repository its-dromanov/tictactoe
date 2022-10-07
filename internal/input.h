#ifndef TICTACTOE_INTERNAL_INPUT_H_
#define TICTACTOE_INTERNAL_INPUT_H_

#include <memory>

#include "grid.h"

namespace tictactoe {

class Input {
 public:
  template <class T>
  auto GetSingleUserInput(const std::string& msg) const -> T;

  auto GetCellNumber(const std::unique_ptr<tictactoe::Grid>& grid,
                     const std::string& player_label) const -> int;
  auto GetFirstPlayer() const -> player_label_t;
  auto GetAnswerAboutReplay() const -> bool;
};

}  // namespace tictactoe

#endif  // TICTACTOE_INTERNAL_INPUT_H_