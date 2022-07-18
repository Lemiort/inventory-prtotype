#ifndef SRC_MODEL_IICON
#define SRC_MODEL_IICON

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

#endif /* SRC_MODEL_IICON */
