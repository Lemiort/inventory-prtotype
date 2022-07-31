#ifndef SRC_VIEW_MODEL_PLAYER
#define SRC_VIEW_MODEL_PLAYER

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

#endif /* SRC_VIEW_MODEL_PLAYER */
