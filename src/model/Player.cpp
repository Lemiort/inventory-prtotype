#include "model/Player.h"

namespace model {

IIcon const& Player::getIcon() const { return Renderable::getIcon(); }

void Player::setIcon(std::unique_ptr<IIcon> icon) {
    return Renderable::setIcon(std::move(icon));
}

glm::vec2 Player::getPosition() const { return Renderable::getPosition(); }

void Player::setPosition(glm::vec2 position) {
    return Renderable::setPosition(position);
}

}  // namespace model