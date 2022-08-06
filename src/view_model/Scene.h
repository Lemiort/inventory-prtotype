#ifndef SRC_VIEW_MODEL_SCENE_H_
#define SRC_VIEW_MODEL_SCENE_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include <list>
#include <memory>

#include "view_model/IEditable.h"

namespace view_model {

class Scene {
 public:
    Scene() = default;
    virtual ~Scene() = default;

    void renderSelectableList();

    size_t getSelectedIndex() const;

    void renderEditWindow(size_t index);

    std::list<std::unique_ptr<IEditable>> const& getObjects() const;
    void addObject(std::unique_ptr<IEditable> object);
    void removeObject(IEditable const& object);

 private:
    std::list<std::unique_ptr<IEditable>> objects_;
    size_t selected_{0};
};

}  // namespace view_model

#endif  // SRC_VIEW_MODEL_SCENE_H_
