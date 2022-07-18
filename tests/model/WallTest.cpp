#include "gtest/gtest.h"
#include "model/Wall.h"

using model::Wall;

class WallTest : public ::testing::Test {
protected:
    WallTest() = default;

    ~WallTest() override = default;

    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(WallTest, GetterSetterTest) {
    // Arrange
    Wall wall;
    constexpr auto kWallType = model::IWall::Type::kUnbreakable;

    // Act
    wall.setType(kWallType);

    // Assert
    EXPECT_EQ(wall.getType(), kWallType);
}