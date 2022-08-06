#ifndef SRC_MODEL_IPLAYER_H_
#define SRC_MODEL_IPLAYER_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include "model/IRenderable.h"

namespace model {

class IPlayer : public virtual IRenderable {
 public:
    IPlayer() = default;
    ~IPlayer() override = default;
};

}  // namespace model

#endif  // SRC_MODEL_IPLAYER_H_
