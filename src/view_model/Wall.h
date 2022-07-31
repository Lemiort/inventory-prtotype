#ifndef SRC_VIEW_MODEL_WALL
#define SRC_VIEW_MODEL_WALL

#include "model/Wall.h"
#include "view_model/Renderable.h"

namespace view_model {
class Wall : public model::Wall, public virtual view_model::Renderable {
public:
    Wall();
    ~Wall() override = default;

    void renderEditWindow() override;
};
}  // namespace view_model

#endif /* SRC_VIEW_MODEL_WALL */
