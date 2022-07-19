#ifndef SRC_MODEL_WALL
#define SRC_MODEL_WALL

#include "model/IWall.h"
#include "model/Renderable.h"

namespace model {

class Wall : public IWall, public Renderable {
public:
    Wall() = default;
    ~Wall() override = default;

    IWall::Type getType() const override;

    void setType(IWall::Type type) override;

    IIcon const& getIcon() const override;

    void setIcon(std::unique_ptr<IIcon> icon) override;

    glm::vec2 getPosition() const override;

    void setPosition(glm::vec2 position) override;
};

}  // namespace model

#endif /* SRC_MODEL_WALL */
