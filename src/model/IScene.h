#ifndef SRC_MODEL_ISCENE
#define SRC_MODEL_ISCENE

#include <memory>
#include <set>

#include "model/IRenderable.h"

namespace model {

class IScene {
public:
    IScene() = default;
    virtual ~IScene() = default;

    virtual std::set<std::unique_ptr<IRenderable>> const& getObjects()
        const = 0;
    virtual void AddObject(std::unique_ptr<IRenderable> object) = 0;
    virtual void RemoveObject(IRenderable const& object) = 0;
};

}  // namespace model

#endif /* SRC_MODEL_ISCENE */
