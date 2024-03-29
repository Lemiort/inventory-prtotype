#ifndef SRC_VIEW_MODEL_WALL_H_
#define SRC_VIEW_MODEL_WALL_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

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

#endif  // SRC_VIEW_MODEL_WALL_H_
