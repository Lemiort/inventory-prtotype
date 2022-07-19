#ifndef SRC_MODEL_PLAYER
#define SRC_MODEL_PLAYER

#include "model/IPlayer.h"
#include "model/Renderable.h"

namespace model {

class Player : public IPlayer, public Renderable {
public:
    Player() = default;
    ~Player() override = default;

    IIcon const& getIcon() const override;
    void setIcon(std::unique_ptr<IIcon> icon) override;
    glm::vec2 getPosition() const override;
    void setPosition(glm::vec2 position) override;
};

}  // namespace model

#endif /* SRC_MODEL_PLAYER */
