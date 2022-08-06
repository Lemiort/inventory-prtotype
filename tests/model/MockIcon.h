#ifndef TESTS_MODEL_MOCKICON_H_
#define TESTS_MODEL_MOCKICON_H_

/*!
 * @copyright Copyright (c) 2022 Lemiort
 */

#include "gmock/gmock.h"
#include "model/IIcon.h"

namespace model {

class MockIcon : public IIcon {
 public:
    MOCK_METHOD(std::filesystem::path, getFilePath, (), (const, override));
    MOCK_METHOD(void, setFilePath, (std::filesystem::path), (override));
};

}  // namespace model

#endif  // TESTS_MODEL_MOCKICON_H_
