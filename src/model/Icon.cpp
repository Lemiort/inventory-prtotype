#include "model/Icon.h"

namespace model {

std::filesystem::path Icon::getFilePath() const { return path_; }

void Icon::setFilePath(std::filesystem::path path) { path_ = path; }

}  // namespace model