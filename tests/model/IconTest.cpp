#include "gtest/gtest.h"
#include "model/Icon.h"

using model::Icon;

class IconTest : public ::testing::Test {
protected:
    IconTest() = default;

    ~IconTest() override = default;

    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(IconTest, GetterSetterTest) {
    // Arrange
    Icon icon;
    std::filesystem::path path{"C:/Windows/icon.ico"};

    // Act
    icon.setFilePath(path);

    // Assert
    EXPECT_EQ(icon.getFilePath(), path);
}