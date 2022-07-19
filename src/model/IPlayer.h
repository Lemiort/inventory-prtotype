#ifndef SRC_MODEL_IPLAYER
#define SRC_MODEL_IPLAYER

#include "model/IRenderable.h"

namespace model {

class IPlayer : public IRenderable {
public:
    IPlayer() = default;
    ~IPlayer() override = default;
};

}  // namespace model

#endif /* SRC_MODEL_IPLAYER */
