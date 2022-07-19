#include "model/Ladder.h"

namespace model {

float Ladder::getClimbingSpeed() const { return climbingSpeed_; }

void Ladder::setClimbingSpeed(float value) { climbingSpeed_ = value; }

IIcon const& Ladder::getIcon() const { return Renderable::getIcon(); }

void Ladder::setIcon(std::unique_ptr<IIcon> icon) {
    return Renderable::setIcon(std::move(icon));
}

glm::vec2 Ladder::getPosition() const { return Renderable::getPosition(); }

void Ladder::setPosition(glm::vec2 position) {
    return Renderable::setPosition(position);
}

}  // namespace model