#include "model/Player.h"

namespace model {

IIcon const& Player::getIcon() const { return renderableImpl_.getIcon(); }

void Player::setIcon(std::unique_ptr<IIcon> icon) {
    return renderableImpl_.setIcon(std::move(icon));
}

glm::vec2 Player::getPosition() const { return renderableImpl_.getPosition(); }

void Player::setPosition(glm::vec2 position) {
    return renderableImpl_.setPosition(position);
}

}  // namespace model