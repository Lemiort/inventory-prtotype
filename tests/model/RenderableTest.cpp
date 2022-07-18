#include "gtest/gtest.h"
#include "model/MockIcon.h"
#include "model/Renderable.h"

using model::MockIcon;
using model::Renderable;

class RenderableTest : public ::testing::Test {
protected:
    RenderableTest() = default;

    ~RenderableTest() override = default;

    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(RenderableTest, IconGetterSetterTest) {
    // Arrange
    Renderable renderable;
    MockIcon icon;

    // Act
    renderable.setIcon(icon);

    // Assert
    EXPECT_EQ(renderable.getIcon().getFilePath(), icon.getFilePath());
}

TEST_F(RenderableTest, PositionGetterSetterTest) {
    // Arrange
    Renderable renderable;
    glm::vec2 position{1.0F, 2.0F};

    // Act
    renderable.setPosition(position);

    // Assert
    EXPECT_EQ(renderable.getPosition(), position);
}