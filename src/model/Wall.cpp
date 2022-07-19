#include "model/Wall.h"

namespace model {

IWall::Type Wall::getType() const { return IWall::Type::kUnbreakable; }

void Wall::setType(IWall::Type type) {}

IIcon const& Wall::getIcon() const { return Renderable::getIcon(); }

void Wall::setIcon(std::unique_ptr<IIcon> icon) {
    return Renderable::setIcon(std::move(icon));
}

glm::vec2 Wall::getPosition() const { return Renderable::getPosition(); }

void Wall::setPosition(glm::vec2 position) {
    return Renderable::setPosition(position);
}

}  // namespace model