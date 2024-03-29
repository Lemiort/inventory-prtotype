/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include "view_model/Wall.h"

#include <imgui.h>

#include <memory>

namespace view_model {

Wall::Wall() {
    view_model::Renderable::setName(
        "Wall " + std::to_string(view_model::Renderable::getId()));
    setIcon(std::make_unique<model::Icon>("../textures/wall.png"));
}

void Wall::renderEditWindow() {
    ImGui::BeginChild("item view",
                      ImVec2(0,
                             -ImGui::GetFrameHeightWithSpacing()));  // Leave
                                                                     // room for
                                                                     // 1 line
                                                                     // below us
    view_model::Renderable::renderEditWindow();

    // render wall type
    const char* items[] = {"Brekable", "Unbreakable"};

    // convert wall type to combo
    int item_current_idx = 0;  // Here we store our selection data as an index.
    auto current_wall_type = getType();
    switch (current_wall_type) {
        case model::IWall::Type::kBreakable:
            item_current_idx = 0;
            break;
        case model::IWall::Type::kUnbreakable:
            item_current_idx = 1;
            break;
        default:
            item_current_idx = 0;
            break;
    }

    const char* combo_preview_value =
        items[item_current_idx];  // Pass in the preview value visible before
                                  // opening the combo (it could be anything)

    if (ImGui::BeginCombo("Wall type", combo_preview_value,
                          ImGuiComboFlags_::ImGuiComboFlags_None)) {
        for (int n = 0; n < IM_ARRAYSIZE(items); n++) {
            const bool is_selected = (item_current_idx == n);
            if (ImGui::Selectable(items[n], is_selected)) {
                item_current_idx = n;
                // save value of combo
                switch (item_current_idx) {
                    case 0:
                        setType(model::IWall::Type::kBreakable);
                        break;
                    case 1:
                        setType(model::IWall::Type::kUnbreakable);
                        break;
                    default:
                        setType(model::IWall::Type::kBreakable);
                        break;
                }
            }

            // Set the initial focus when opening the combo (scrolling +
            // keyboard navigation focus)
            if (is_selected) {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }

    ImGui::EndChild();
}

}  // namespace view_model
