#include "stdafx.h"
#include <gtest/gtest.h>
#include "DisplayMonster.h"

namespace PacMan
{
    namespace View
    {
        namespace Tests
        {
            TEST(DisplayMonster, to_string_returns_string)
            {
                using namespace View;

                // Arrange
                DisplayMonster sut{};

                // Act
                auto actual = sut.to_string();

                // Assert
                EXPECT_EQ("M ", actual);
            }
        };
    };
};
