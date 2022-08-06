#ifndef SRC_MODEL_PLAYER_H_
#define SRC_MODEL_PLAYER_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include "model/IPlayer.h"
#include "model/Renderable.h"

namespace model {

class Player : public IPlayer, public virtual Renderable {
 public:
    Player() = default;
    ~Player() override = default;
};

}  // namespace model

#endif  // SRC_MODEL_PLAYER_H_
