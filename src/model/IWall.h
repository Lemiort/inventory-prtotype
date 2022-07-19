#ifndef SRC_MODEL_IWALL
#define SRC_MODEL_IWALL

#include "model/IRenderable.h"

namespace model {

class IWall : public IRenderable {
public:
    enum class Type : uint8_t { kBreakable = 0, kUnbreakable };
    IWall() = default;
    ~IWall() override = default;
    [[nodiscard]] virtual IWall::Type getType() const = 0;
    virtual void setType(IWall::Type type) = 0;
};

}  // namespace model

#endif /* SRC_MODEL_IWALL */
