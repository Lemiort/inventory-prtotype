#include <memory>

#include "gtest/gtest.h"
#include "model/Player.h"

using model::IPlayer;
using model::Player;

class PlayerTest : public ::testing::Test {
protected:
    PlayerTest() = default;

    ~PlayerTest() override = default;

    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(PlayerTest, CtorDtorTest) {
    // Arrange
    std::unique_ptr<IPlayer> player;

    // Act
    player = std::make_unique<Player>();

    // Assert
    ASSERT_NO_THROW(player.reset());
}