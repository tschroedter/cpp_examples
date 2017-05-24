#include "stdafx.h"
#include <gtest/gtest.h>
#include "DisplayMax.h"

TEST(DisplayMax, to_string_returns_string)
{
    using namespace PacMan::View;

    // Arrange
    DisplayMax sut {};

    // Act
    auto actual = sut.to_string();

    // Assert
    EXPECT_EQ("MA", actual);
}
