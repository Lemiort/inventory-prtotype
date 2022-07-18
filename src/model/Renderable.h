#ifndef SRC_MODEL_RENDERABLE
#define SRC_MODEL_RENDERABLE

#include "model/IRenderable.h"
#include "model/Icon.h"

namespace model {

class Renderable : public IRenderable {
public:
    Renderable() = default;
    ~Renderable() override = default;
    [[nodiscard]] IIcon const& getIcon() const override { return Icon{}; }
    void setIcon(IIcon const&) override {}
    [[nodiscard]] glm::vec2 getPosition() const override {
        return {0.0F, 0.1F};
    }
    void setPosition(glm::vec2 position) override {}
};

}  // namespace model

#endif /* SRC_MODEL_RENDERABLE */
