#ifndef SRC_VIEW_MODEL_SCENE
#define SRC_VIEW_MODEL_SCENE

#include <imgui.h>

#include "model/Scene.h"
#include "view_model/IEditable.h"

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
            auto editable_object =
                dynamic_cast<view_model::IEditable*>(it->get());
            if (editable_object != nullptr) {
                if (editable_object->renderSelectableItem(selected_ == i)) {
                    selected_ = i;
                }
            } else {
                if (ImGui::Selectable("Unknown", selected_ == i)) {
                    selected_ = i;
                }
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
