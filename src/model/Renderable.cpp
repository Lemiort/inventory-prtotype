/*!
 * @copyright Copyright (c) 2022 Lemiort
 */
#include "model/Renderable.h"

#include <utility>

#include "model/Icon.h"

namespace model {

Renderable::Renderable() : icon_{std::make_unique<Icon>()} {}

IIcon const& Renderable::getIcon() const { return *icon_; }

void Renderable::setIcon(std::unique_ptr<IIcon> icon) {
    icon_ = std::move(icon);
}

glm::vec2 Renderable::getPosition() const { return position_; }

void Renderable::setPosition(glm::vec2 position) { position_ = position; }

}  // namespace model
