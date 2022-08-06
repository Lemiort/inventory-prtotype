#ifndef SRC_MODEL_LADDER_H_
#define SRC_MODEL_LADDER_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include "model/ILadder.h"
#include "model/Renderable.h"

namespace model {

class Ladder : public ILadder, public virtual Renderable {
 public:
    Ladder() = default;
    ~Ladder() override = default;
    float getClimbingSpeed() const override;
    void setClimbingSpeed(float value) override;

 private:
    float climbingSpeed_{0.0F};
};

}  // namespace model

#endif  // SRC_MODEL_LADDER_H_
