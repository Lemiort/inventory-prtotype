#ifndef SRC_VIEW_MODEL_LADDER_H_
#define SRC_VIEW_MODEL_LADDER_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include "model/Ladder.h"
#include "view_model/Renderable.h"

namespace view_model {
class Ladder : public model::Ladder, public virtual view_model::Renderable {
 public:
    Ladder();
    ~Ladder() override = default;
    void renderEditWindow() override;
};
}  // namespace view_model

#endif  // SRC_VIEW_MODEL_LADDER_H_
