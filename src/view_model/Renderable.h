#ifndef SRC_VIEW_MODEL_RENDERABLE
#define SRC_VIEW_MODEL_RENDERABLE

#include "model/Renderable.h"
#include "view_model/IEditable.h"

namespace view_model {

class Renderable : public model::Renderable, public view_model::IEditable {
public:
    Renderable();
    ~Renderable() override = default;

    bool renderSelectableItem(bool is_selected) override;
    void renderEditWindow() override;
    int getId() const;
    void setName(std::string name);

private:
    std::string name_;
    int object_id_;
    static int objects_count_;
};

}  // namespace view_model

#endif /* SRC_VIEW_MODEL_RENDERABLE */
