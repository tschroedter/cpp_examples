#include "stdafx.h"
#include <gtest/gtest.h>
#include "DisplayDot.h"

TEST(DisplayDot, to_string_returns_string)
{
    using namespace PacMan::View;

    // Arrange
    DisplayDot sut{};

    // Act
    auto actual = sut.to_string();

    // Assert
    EXPECT_EQ(". ", actual);
}
