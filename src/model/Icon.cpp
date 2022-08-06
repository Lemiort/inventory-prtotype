/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include "model/Icon.h"

#include <utility>

namespace model {

Icon::Icon(std::filesystem::path path) : path_{std::move(path)} {}

std::filesystem::path Icon::getFilePath() const { return path_; }

void Icon::setFilePath(std::filesystem::path path) { path_ = path; }

}  // namespace model
