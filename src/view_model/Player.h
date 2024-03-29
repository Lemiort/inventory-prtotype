#ifndef SRC_VIEW_MODEL_PLAYER_H_
#define SRC_VIEW_MODEL_PLAYER_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include "model/Player.h"
#include "view_model/Renderable.h"

namespace view_model {
class Player : public model::Player, public virtual view_model::Renderable {
 public:
    Player();
    ~Player() override = default;

    void renderEditWindow() override;
};
}  // namespace view_model

#endif  // SRC_VIEW_MODEL_PLAYER_H_
