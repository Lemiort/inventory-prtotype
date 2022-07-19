#ifndef SRC_VIEW_MODEL_SCENE
#define SRC_VIEW_MODEL_SCENE

#include <imgui.h>

#include "model/Scene.h"

namespace view_model {

class Scene : public model::Scene {
public:
    Scene() = default;
    ~Scene() override = default;

    void renderSelectableList() {
        ImGui::BeginChild("left pane", ImVec2(650, 0), true);

        const auto& objects = getObjects();
        auto it = objects.cbegin();
        for (size_t i = 0; i < objects.size(); i++, it++) {
            // FIXME: Good candidate to use
            // ImGuiSelectableFlags_SelectOnNav
            std::stringstream ss;
            model::IRenderable* const object = it->get();
            if (dynamic_cast<model::Player*>(object) != nullptr) {
                ss << "Player " << i;
            } else if (dynamic_cast<model::Ladder*>(object) != nullptr) {
                ss << "Ladder " << i;
            } else if (dynamic_cast<model::Wall*>(object) != nullptr) {
                ss << "Wall " << i;
            } else {
                ss << "Unknown " << i;
            }
            if (ImGui::Selectable(ss.str().c_str(), selected_ == i)) {
                selected_ = i;
            }
        }
        ImGui::EndChild();
    }

    size_t getSelectedIndex() const { return selected_; }

private:
    size_t selected_{0};
};

}  // namespace view_model

#endif /* SRC_VIEW_MODEL_SCENE */
