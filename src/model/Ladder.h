#ifndef SRC_MODEL_LADDER
#define SRC_MODEL_LADDER

#include "model/ILadder.h"
#include "model/Renderable.h"

namespace model {

class Ladder : public ILadder, public Renderable {
public:
    Ladder() = default;
    ~Ladder() override = default;
    [[nodiscard]] float getClimbingSpeed() const override { return 0.0F; }
    void setClimbingSpeed(float value) override {}

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

#endif /* SRC_MODEL_LADDER */
