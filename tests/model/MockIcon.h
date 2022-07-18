#ifndef TESTS_MODEL_MOCKICON
#define TESTS_MODEL_MOCKICON

#include "gmock/gmock.h"
#include "model/IIcon.h"

namespace model {

class MockIcon : public IIcon {
public:
    MOCK_METHOD(std::filesystem::path, getFilePath, (), (const, override));
    MOCK_METHOD(void, setFilePath, (std::filesystem::path), (override));
};

}  // namespace model

#endif /* TESTS_MODEL_MOCKICON */
