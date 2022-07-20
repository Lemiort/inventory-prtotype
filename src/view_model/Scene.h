#ifndef SRC_VIEW_MODEL_SCENE
#define SRC_VIEW_MODEL_SCENE

#include "model/Scene.h"
#include "view_model/IEditable.h"

namespace view_model {

class Scene : public model::Scene {
public:
    Scene() = default;
    ~Scene() override = default;

    void renderSelectableList();

    size_t getSelectedIndex() const;

    void renderEditWindow(size_t index);

private:
    size_t selected_{0};
};

}  // namespace view_model

#endif /* SRC_VIEW_MODEL_SCENE */
