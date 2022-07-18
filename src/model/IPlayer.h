#ifndef SRC_MODEL_PLAYER
#define SRC_MODEL_PLAYER

#include "model/IRenderable.h"

namespace model {

class IPlayer : public IRenderable {
public:
    IPlayer() = default;
    virtual ~IPlayer() = default;
};

}  // namespace model

#endif /* SRC_MODEL_PLAYER */
