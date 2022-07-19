#ifndef TESTS_MODEL_MOCKRENDERABLE
#define TESTS_MODEL_MOCKRENDERABLE

#include "gmock/gmock.h"
#include "model/IRenderable.h"

namespace model {

class MockRenderable : public IRenderable {
public:
    MOCK_METHOD(IIcon const&, getIcon, (), (const, override));
    MOCK_METHOD(void, setIcon, (std::unique_ptr<IIcon>), (override));
    MOCK_METHOD(glm::vec2, getPosition, (), (const, override));
    MOCK_METHOD(void, setPosition, (glm::vec2), (override));
};

}  // namespace model

#endif /* TESTS_MODEL_MOCKRENDERABLE */
