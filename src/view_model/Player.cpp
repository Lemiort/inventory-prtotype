#include "view_model/Player.h"

#include <imgui.h>

namespace view_model {

Player::Player() {
    view_model::Renderable::setName(
        "Player " + std::to_string(view_model::Renderable::getId()));
}

void Player::renderEditWindow() {
    ImGui::BeginChild("item view",
                      ImVec2(0,
                             -ImGui::GetFrameHeightWithSpacing()));  // Leave
                                                                     // room for
                                                                     // 1 line
                                                                     // below us
    view_model::Renderable::renderEditWindow();
    ImGui::EndChild();
}

}  // namespace view_model
