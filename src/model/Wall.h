#ifndef SRC_MODEL_WALL
#define SRC_MODEL_WALL

#include "model/IWall.h"
#include "model/Renderable.h"

namespace model {

class Wall : public IWall, public Renderable {
public:
    Wall() = default;
    ~Wall() override = default;

    [[nodiscard]] IWall::Type getType() const override {
        return IWall::Type::kUnbreakable;
    }
    void setType(IWall::Type type) override {}

    [[nodiscard]] IIcon const& getIcon() const override {
        return Renderable::getIcon();
    }
    void setIcon(IIcon const& icon) override {
        return Renderable::setIcon(icon);
    }
    [[nodiscard]] glm::vec2 getPosition() const override {
        return Renderable::getPosition();
    }
    void setPosition(glm::vec2 position) override {
        return Renderable::setPosition(position);
    }
};

}  // namespace model

#endif /* SRC_MODEL_WALL */
