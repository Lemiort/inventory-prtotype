#include "view_model/Ladder.h"

#include <imgui.h>

namespace view_model {

Ladder::Ladder() {
    view_model::Renderable::setName(
        "Ladder " + std::to_string(view_model::Renderable::getId()));
    setIcon(std::make_unique<model::Icon>("../textures/ladder.png"));
}

void Ladder::renderEditWindow() {
    ImGui::BeginChild("item view",
                      ImVec2(0,
                             -ImGui::GetFrameHeightWithSpacing()));  // Leave
                                                                     // room for
                                                                     // 1 line
                                                                     // below us
    view_model::Renderable::renderEditWindow();

    float climbing_speed = getClimbingSpeed();
    if (ImGui::InputFloat("Climbing speed", &climbing_speed)) {
        setClimbingSpeed(climbing_speed);
    }
    ImGui::EndChild();
}

}  // namespace view_model
