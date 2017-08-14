#include "stdafx.h"
#include <gtest/gtest.h>
#include "DisplayDot.h"

namespace PacMan
{
    namespace View
    {
        namespace Tests
        {
            TEST(DisplayDot, to_string_returns_string)
            {
                using namespace View;

                // Arrange
                DisplayDot sut{};

                // Act
                auto actual = sut.to_string();

                // Assert
                EXPECT_EQ(". ", actual);
            }
        };
    };
};