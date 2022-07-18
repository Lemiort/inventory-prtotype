#include "gtest/gtest.h"
#include "model/MockRenderable.h"
#include "model/Scene.h"

using model::MockRenderable;
using model::Scene;

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
    auto renderable = std::make_unique<MockRenderable>();

    // Act
    scene.AddObject(std::move(renderable));
    auto const& objects = scene.getObjects();
    ASSERT_NE(objects.size(), 0);
    auto const& first_object = **objects.cbegin();
    scene.RemoveObject(first_object);
    ASSERT_EQ(objects.size(), 0);
}