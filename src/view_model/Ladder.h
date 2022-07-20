#ifndef SRC_VIEW_MODEL_LADDER
#define SRC_VIEW_MODEL_LADDER

#include "model/Ladder.h"
#include "view_model/Renderable.h"

namespace view_model {
class Ladder : public model::Ladder, public view_model::IEditable {
public:
    Ladder();
    ~Ladder() override = default;

    bool renderSelectableItem(bool is_selected) override;
    void renderEditWindow() override;

private:
    Renderable renderable_impl_;
};
}  // namespace view_model

#endif /* SRC_VIEW_MODEL_LADDER */
