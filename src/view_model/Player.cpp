#include "view_model/Player.h"

#include <imgui.h>

namespace view_model {

Player::Player() {
    renderable_impl_.setName("Player " +
                             std::to_string(renderable_impl_.getId()));
}

bool Player::renderSelectableItem(bool is_selected) {
    return renderable_impl_.renderSelectableItem(is_selected);
}
void Player::renderEditWindow() {
    ImGui::BeginChild("item view",
                      ImVec2(0,
                             -ImGui::GetFrameHeightWithSpacing()));  // Leave
                                                                     // room for
                                                                     // 1 line
                                                                     // below us
    renderable_impl_.renderEditWindow();
    ImGui::EndChild();
}

bool Player::getIsMarkedToDelete() const {
    return renderable_impl_.getIsMarkedToDelete();
}

}  // namespace view_model
