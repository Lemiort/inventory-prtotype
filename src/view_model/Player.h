#ifndef SRC_VIEW_MODEL_PLAYER
#define SRC_VIEW_MODEL_PLAYER

#include "model/Player.h"
#include "view_model/Renderable.h"

namespace view_model {
class Player : public model::Player, public virtual view_model::IEditable {
public:
    Player();
    ~Player() override = default;

    bool renderSelectableItem(bool is_selected) override;
    void renderEditWindow() override;
    bool getIsMarkedToDelete() const override;

private:
    Renderable renderable_impl_;
};
}  // namespace view_model

#endif /* SRC_VIEW_MODEL_PLAYER */
