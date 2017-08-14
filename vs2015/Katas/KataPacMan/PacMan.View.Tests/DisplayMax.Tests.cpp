#include "stdafx.h"
#include <gtest/gtest.h>
#include "DisplayMax.h"

namespace PacMan
{
    namespace View
    {
        namespace Tests
        {
            TEST(DisplayMax, to_string_returns_string)
            {
                using namespace View;

                // Arrange
                DisplayMax sut{};

                // Act
                auto actual = sut.to_string();

                // Assert
                EXPECT_EQ("MA", actual);
            }
        };
    };
};