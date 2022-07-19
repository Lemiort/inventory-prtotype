#include "model/Renderable.h"

namespace model {

IIcon const& Renderable::getIcon() const { return *icon_; }

void Renderable::setIcon(std::unique_ptr<IIcon> icon) {
    icon_ = std::move(icon);
}

glm::vec2 Renderable::getPosition() const { return position_; }

void Renderable::setPosition(glm::vec2 position) { position_ = position; }

}  // namespace model