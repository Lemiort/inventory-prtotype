#ifndef SRC_MODEL_WALL_H_
#define SRC_MODEL_WALL_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include "model/IWall.h"
#include "model/Renderable.h"

namespace model {

class Wall : public IWall, public virtual Renderable {
 public:
    Wall() = default;
    ~Wall() override = default;

    IWall::Type getType() const override;
    void setType(IWall::Type type) override;

 private:
    IWall::Type type_{IWall::Type::kBreakable};
};

}  // namespace model

#endif  // SRC_MODEL_WALL_H_
