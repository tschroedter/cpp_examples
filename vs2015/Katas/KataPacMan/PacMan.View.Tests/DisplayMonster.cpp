#include "stdafx.h"
#include <gtest/gtest.h>
#include "DisplayMonster.h"

TEST(DisplayMonster, to_string_returns_string)
{
    using namespace PacMan::View;

    // Arrange
    DisplayMonster sut{};

    // Act
    auto actual = sut.to_string();

    // Assert
    EXPECT_EQ("M ", actual);
}
