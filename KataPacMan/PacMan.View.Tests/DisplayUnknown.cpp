#include "stdafx.h"
#include <gtest/gtest.h>
#include "DisplayUnknown.h"

TEST(DisplayUnknown, to_string_returns_string)
{
    using namespace PacMan::View;

    // Arrange
    DisplayUnknown sut {};

    // Act
    auto actual = sut.to_string();

    // Assert
    EXPECT_EQ("? ", actual);
}
