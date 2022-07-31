#include "model/Ladder.h"

namespace model {

float Ladder::getClimbingSpeed() const { return climbingSpeed_; }

void Ladder::setClimbingSpeed(float value) { climbingSpeed_ = value; }

}  // namespace model