
#include "view_model/Scene.h"

#include <imgui.h>

namespace view_model {

void Scene::renderSelectableList() {
    ImGui::BeginChild("left pane", ImVec2(650, 0), true);

    const auto& objects = getObjects();
    auto it = objects.cbegin();
    for (size_t i = 0; i < objects.size(); i++, it++) {
        auto editable_object = dynamic_cast<view_model::IEditable*>(it->get());
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

size_t Scene::getSelectedIndex() const { return selected_; }

void Scene::renderEditWindow(size_t index) {
    const auto& objects = getObjects();
    auto it = objects.cbegin();
    std::advance(it, index);
    bool is_marked_to_delete{false};
    if (it != objects.cend()) {
        auto* editable_object = dynamic_cast<view_model::IEditable*>(it->get());
        if (editable_object != nullptr) {
            editable_object->renderEditWindow();
            is_marked_to_delete = editable_object->getIsMarkedToDelete();
        }
    }
    if (is_marked_to_delete) {
        removeObject(**it);
    }
}

}  // namespace view_model
