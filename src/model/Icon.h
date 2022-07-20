#ifndef SRC_MODEL_ICON
#define SRC_MODEL_ICON

#include "model/IIcon.h"

namespace model {

class Icon : public IIcon {
public:
    explicit Icon(std::filesystem::path path = "./icon.ico");
    ~Icon() override = default;
    [[nodiscard]] std::filesystem::path getFilePath() const override;
    void setFilePath(std::filesystem::path path) override;

private:
    std::filesystem::path path_;
};

}  // namespace model

#endif /* SRC_MODEL_ICON */
