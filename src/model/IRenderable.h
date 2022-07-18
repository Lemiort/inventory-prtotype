#ifndef SRC_MODEL_IRENDERABLE
#define SRC_MODEL_IRENDERABLE

#include <glm/vec2.hpp>

#include "model/IIcon.h"


namespace model {

class IRenderable {
public:
    IRenderable() = default;
    virtual ~IRenderable() = default;
    virtual IIcon getIcon() const = 0;
    virtual void setIcon(IIcon) = 0;
    virtual glm::vec2 getPosition() const = 0;
    virtual void setPosition(glm::vec2 position) = 0;
};

}  // namespace model

#endif /* SRC_MODEL_IRENDERABLE */
