#include "model/Ladder.h"

namespace model {

float Ladder::getClimbingSpeed() const { return climbingSpeed_; }

void Ladder::setClimbingSpeed(float value) { climbingSpeed_ = value; }

IIcon const& Ladder::getIcon() const { return renderableImpl_.getIcon(); }

void Ladder::setIcon(std::unique_ptr<IIcon> icon) {
    renderableImpl_.setIcon(std::move(icon));
}

glm::vec2 Ladder::getPosition() const { return renderableImpl_.getPosition(); }

void Ladder::setPosition(glm::vec2 position) {
    renderableImpl_.setPosition(position);
}

}  // namespace model