#ifndef TICTACTOE_INPUT_H_
#define TICTACTOE_INPUT_H_

#include <memory>

#include "grid.h"

namespace tictactoe {

// A user input class.
// Here you can get the necessary things from the user with certain conditions.
class Input {
 public:
  // Getting a single value from a user of a certain type.
  template <class T>
  auto GetSingleInput(const std::string& msg) const -> T;

  auto GetCellNumber(const std::unique_ptr<Grid>& grid,
                     const std::string& player_label) const -> int;
  auto GetFirstPlayer() const -> player_label_t;
  auto GetAnswerAboutReplay() const -> bool;
};

}  // namespace tictactoe

#endif  // TICTACTOE_INPUT_H_