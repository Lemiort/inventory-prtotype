#ifndef SRC_VIEW_MODEL_SCENE
#define SRC_VIEW_MODEL_SCENE

#include <memory>
#include <set>

#include "view_model/IEditable.h"

namespace view_model {

class Scene {
public:
    Scene() = default;
    virtual ~Scene() = default;

    void renderSelectableList();

    size_t getSelectedIndex() const;

    void renderEditWindow(size_t index);

    std::set<std::unique_ptr<IEditable>> const& getObjects() const;
    void addObject(std::unique_ptr<IEditable> object);
    void removeObject(IEditable const& object);

private:
    std::set<std::unique_ptr<IEditable>> objects_;
    size_t selected_{0};
};

}  // namespace view_model

#endif /* SRC_VIEW_MODEL_SCENE */
