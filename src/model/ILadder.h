#ifndef SRC_MODEL_ILADDER_H_
#define SRC_MODEL_ILADDER_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include "model/IRenderable.h"

namespace model {

class ILadder : public virtual IRenderable {
 public:
    ILadder() = default;
    ~ILadder() override = default;
    [[nodiscard]] virtual float getClimbingSpeed() const = 0;
    virtual void setClimbingSpeed(float value) = 0;
};

}  // namespace model

#endif  // SRC_MODEL_ILADDER_H_
