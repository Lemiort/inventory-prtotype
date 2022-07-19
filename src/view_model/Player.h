#ifndef SRC_VIEW_MODEL_PLAYER
#define SRC_VIEW_MODEL_PLAYER

#include <imgui.h>

#include "model/Player.h"
#include "view_model/IEditable.h"

namespace view_model {
class Player : public model::Player, public view_model::IEditable {
public:
    Player() = default;
    ~Player() override = default;

    bool renderSelectableItem(bool is_selected) override {
        return ImGui::Selectable("Player", is_selected);
    }
    void renderEditWindow() override {}
};
}  // namespace view_model

#endif /* SRC_VIEW_MODEL_PLAYER */
