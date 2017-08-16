#include "stdafx.h"
#include <gtest/gtest.h>
#include "BaseException.h"

namespace PacMan
{
    namespace Common
    {
        namespace Tests
        {
            TEST(BaseException, get_error_returns_string)
            {
                // Arrange
                // Act
                BaseException sut{"Message"};

                // Assert
                EXPECT_EQ("Message", sut.get_error());
            }
        };
    };
};
