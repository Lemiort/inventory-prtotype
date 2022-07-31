#ifndef SRC_VIEW_MODEL_RENDERABLE
#define SRC_VIEW_MODEL_RENDERABLE

#include "model/Renderable.h"
#include "view_model/IEditable.h"

namespace view_model {

class Renderable : public virtual model::Renderable,
                   public virtual view_model::IEditable {
public:
    Renderable();
    ~Renderable() override;

    bool renderSelectableItem(bool is_selected) override;
    void renderEditWindow() override;
    bool getIsMarkedToDelete() const override;

    int getId() const;
    void setName(std::string name);

private:
    std::string name_;
    int object_id_;
    static int objects_count_;
    bool is_marked_to_delete_{false};

    struct OpenGlTexture;
    std::unique_ptr<OpenGlTexture> texture_{nullptr};
    void createTextureFromPath(std::filesystem::path path);
    bool first_render_{true};
};

}  // namespace view_model

#endif /* SRC_VIEW_MODEL_RENDERABLE */
