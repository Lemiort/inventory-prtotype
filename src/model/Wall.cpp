#include "model/Wall.h"

namespace model {

IWall::Type Wall::getType() const { return type_; }

void Wall::setType(IWall::Type type) { type_ = type; }

}  // namespace model