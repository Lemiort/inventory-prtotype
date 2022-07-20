#include "model/Wall.h"

namespace model {

IWall::Type Wall::getType() const { return type_; }

void Wall::setType(IWall::Type type) { type_ = type; }

IIcon const& Wall::getIcon() const { return renderableImpl_.getIcon(); }

void Wall::setIcon(std::unique_ptr<IIcon> icon) {
    renderableImpl_.setIcon(std::move(icon));
}

glm::vec2 Wall::getPosition() const { return renderableImpl_.getPosition(); }

void Wall::setPosition(glm::vec2 position) {
    renderableImpl_.setPosition(position);
}

}  // namespace model