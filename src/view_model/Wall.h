#ifndef SRC_VIEW_MODEL_WALL
#define SRC_VIEW_MODEL_WALL

#include "model/Wall.h"
#include "view_model/Renderable.h"

namespace view_model {
class Wall : public model::Wall, public virtual view_model::IEditable {
public:
    Wall();
    ~Wall() override = default;

    bool renderSelectableItem(bool is_selected) override;
    void renderEditWindow() override;
    bool getIsMarkedToDelete() const override;

private:
    Renderable renderable_impl_;
};
}  // namespace view_model

#endif /* SRC_VIEW_MODEL_WALL */
