#include "gtest/gtest.h"
#include "model/Ladder.h"

using model::Ladder;

class LadderTest : public ::testing::Test {
protected:
    LadderTest() = default;

    ~LadderTest() override = default;

    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(LadderTest, GetterSetterTest) {
    // Arrange
    Ladder ladder;
    constexpr float kClimbingSpeed = 100.0F;

    // Act
    ladder.setClimbingSpeed(kClimbingSpeed);

    // Assert
    EXPECT_EQ(ladder.getClimbingSpeed(), kClimbingSpeed);
}