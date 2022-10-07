// Super-powerful code that was definitely worth a separate file.
// Perhaps it should be rewritten...

#ifndef TICTACTOE_INTERNAL_PLAYER_H_
#define TICTACTOE_INTERNAL_PLAYER_H_

#include <optional>

namespace tictactoe {

enum class PlayerLabel { kMarkX, kMarkO };

using player_label_t = std::optional<PlayerLabel>;

}  // namespace tictactoe

#endif  // TICTACTOE_INTERNAL_PLAYER_H_