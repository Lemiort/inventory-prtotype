#ifndef SRC_MODEL_ISCENE
#define SRC_MODEL_ISCENE

#include <set>

#include "model/IRenderable.h"

namespace model {

class IScene {
public:
    IScene() = default;
    virtual ~IScene() = default;

    const std::set<IRenderable>& getObjects() const = 0;
    void AddObject(IRenderable object) = 0;
    void RemoveObject(IRenderable& object) = 0;
};

}  // namespace model

#endif /* SRC_MODEL_ISCENE */
