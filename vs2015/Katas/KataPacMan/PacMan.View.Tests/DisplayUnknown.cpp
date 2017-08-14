#include "stdafx.h"
#include <gtest/gtest.h>
#include "DisplayUnknown.h"

namespace PacMan
{
    namespace View
    {
        namespace Tests
        {
            TEST(DisplayUnknown, to_string_returns_string)
            {
                using namespace View;

                // Arrange
                DisplayUnknown sut{};

                // Act
                auto actual = sut.to_string();

                // Assert
                EXPECT_EQ("? ", actual);
            }
        };
    };
};
