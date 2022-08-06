#ifndef SRC_MODEL_IICON_H_
#define SRC_MODEL_IICON_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include <filesystem>

namespace model {

class IIcon {
 public:
    IIcon() = default;
    virtual ~IIcon() = default;
    [[nodiscard]] virtual std::filesystem::path getFilePath() const = 0;
    virtual void setFilePath(std::filesystem::path path) = 0;
};

}  // namespace model

#endif  // SRC_MODEL_IICON_H_
