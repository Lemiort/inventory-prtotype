
#include "view_model/Scene.h"

#include <imgui.h>

namespace view_model {

std::set<std::unique_ptr<IEditable>> const& Scene::getObjects() const {
    return objects_;
}

void Scene::addObject(std::unique_ptr<IEditable> object) {
    objects_.insert(std::move(object));
}

void Scene::removeObject(IEditable const& object) {
    auto object_iterator = std::find_if(objects_.cbegin(), objects_.cend(),
                                        [&](auto const& iterator) -> bool {
                                            // compare address of object in
                                            // iterator and address of reference
                                            return (&(*iterator) == &(object));
                                        });
    if (object_iterator != objects_.end()) {
        objects_.erase(*object_iterator);
    }
}

void Scene::renderSelectableList() {
    ImGui::BeginChild("left pane", ImVec2(650, 0), true);

    const auto& objects = getObjects();
    auto it = objects.cbegin();
    for (size_t i = 0; i < objects.size(); i++, it++) {
        if ((*it)->renderSelectableItem(selected_ == i)) {
            selected_ = i;
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
        (*it)->renderEditWindow();
        is_marked_to_delete = (*it)->getIsMarkedToDelete();
    }
    if (is_marked_to_delete) {
        removeObject(**it);
    }
}

}  // namespace view_model
