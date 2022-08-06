#ifndef SRC_MODEL_IWALL_H_
#define SRC_MODEL_IWALL_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include "model/IRenderable.h"

namespace model {

class IWall : public virtual IRenderable {
 public:
    enum class Type : uint8_t { kBreakable = 0U, kUnbreakable = 1U };
    IWall() = default;
    ~IWall() override = default;
    [[nodiscard]] virtual IWall::Type getType() const = 0;
    virtual void setType(IWall::Type type) = 0;
};

}  // namespace model

#endif  // SRC_MODEL_IWALL_H_
