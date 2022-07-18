#ifndef SRC_MODEL_PLAYER
#define SRC_MODEL_PLAYER

#include "model/IPlayer.h"
#include "model/Renderable.h"

namespace model {

class Player : public IPlayer, public Renderable {
public:
    Player() = default;
    ~Player() override = default;

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

#endif /* SRC_MODEL_PLAYER */
