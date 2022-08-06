#ifndef SRC_MODEL_RENDERABLE_H_
#define SRC_MODEL_RENDERABLE_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include <memory>

#include "model/IRenderable.h"
#include "model/Icon.h"

namespace model {

class Renderable : public virtual IRenderable {
 public:
    Renderable();
    ~Renderable() override = default;
    IIcon const& getIcon() const override;
    void setIcon(std::unique_ptr<IIcon> icon) override;
    glm::vec2 getPosition() const override;
    void setPosition(glm::vec2 position) override;

 private:
    glm::vec2 position_{0.0F, 0.0F};
    std::unique_ptr<IIcon> icon_;
};

}  // namespace model

#endif  // SRC_MODEL_RENDERABLE_H_
