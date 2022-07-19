#ifndef SRC_VEW_MODEL_SCENE
#define SRC_VEW_MODEL_SCENE

#include <imgui.h>

#include "model/Scene.h"

namespace view_model {

class Scene : public model::Scene {
public:
    Scene() = default;
    ~Scene() override = default;

    void renderSelectableList() {
        ImGui::BeginChild("left pane", ImVec2(650, 0), true);

        for (size_t i = 0; i < getObjects().size(); i++) {
            // FIXME: Good candidate to use
            // ImGuiSelectableFlags_SelectOnNav
            std::stringstream ss;
            ss << "MyObject " << i;
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

#endif /* SRC_VEW_MODEL_SCENE */
