#ifndef SRC_MODEL_ICON_H_
#define SRC_MODEL_ICON_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include "model/IIcon.h"

namespace model {

class Icon : public IIcon {
 public:
    explicit Icon(
        std::filesystem::path path = "../textures/thiscatdoesnotexist.jpg");
    ~Icon() override = default;
    [[nodiscard]] std::filesystem::path getFilePath() const override;
    void setFilePath(std::filesystem::path path) override;

 private:
    std::filesystem::path path_;
};

}  // namespace model

#endif  // SRC_MODEL_ICON_H_
