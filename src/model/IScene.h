#ifndef SRC_MODEL_ISCENE_H_
#define SRC_MODEL_ISCENE_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

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
    virtual void addObject(std::unique_ptr<IRenderable> object) = 0;
    virtual void removeObject(IRenderable const& object) = 0;
};

}  // namespace model

#endif  // SRC_MODEL_ISCENE_H_
