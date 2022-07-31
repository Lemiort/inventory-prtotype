#include "gtest/gtest.h"
#include "view_model/MockEditable.h"
#include "view_model/Scene.h"

using view_model::MockEditable;
using view_model::Scene;

class SceneTest : public ::testing::Test {
protected:
    SceneTest() = default;

    ~SceneTest() override = default;

    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(SceneTest, AddGetRemoveObjects) {
    // Arrange
    Scene scene;
    auto editable = std::make_unique<MockEditable>();

    // Act
    scene.addObject(std::move(editable));
    auto const& objects = scene.getObjects();
    ASSERT_NE(objects.size(), 0);
    auto const& first_object = **objects.cbegin();
    scene.removeObject(first_object);
    ASSERT_EQ(objects.size(), 0);
}