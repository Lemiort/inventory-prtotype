#ifndef SRC_MODEL_PLAYER
#define SRC_MODEL_PLAYER

#include "model/IPlayer.h"
#include "model/Renderable.h"

namespace model {

class Player : public IPlayer, public virtual Renderable {
public:
    Player() = default;
    ~Player() override = default;
};

}  // namespace model

#endif /* SRC_MODEL_PLAYER */
