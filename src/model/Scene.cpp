#include "model/Scene.h"

#include <algorithm>

namespace model {

std::set<std::unique_ptr<IRenderable>> const& Scene::getObjects() const {
    return objects_;
}

void Scene::AddObject(std::unique_ptr<IRenderable> object) {
    objects_.insert(std::move(object));
}

void Scene::RemoveObject(IRenderable const& object) {
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

}  // namespace model