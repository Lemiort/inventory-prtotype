#include "view_model/Ladder.h"

#include <imgui.h>

namespace view_model {

Ladder::Ladder() {
    renderable_impl_.setName("Ladder " +
                             std::to_string(renderable_impl_.getId()));
}

bool Ladder::renderSelectableItem(bool is_selected) {
    return renderable_impl_.renderSelectableItem(is_selected);
}
void Ladder::renderEditWindow() {
    ImGui::BeginChild("item view",
                      ImVec2(0,
                             -ImGui::GetFrameHeightWithSpacing()));  // Leave
                                                                     // room for
                                                                     // 1 line
                                                                     // below us
    renderable_impl_.renderEditWindow();

    float climbing_speed = getClimbingSpeed();
    if (ImGui::InputFloat("Climbing speed", &climbing_speed)) {
        setClimbingSpeed(climbing_speed);
    }
    ImGui::EndChild();
}

bool Ladder::getIsMarkedToDelete() const {
    return renderable_impl_.getIsMarkedToDelete();
}

}  // namespace view_model
