/*
 * ArgumentInvalidExceptionTests.cpp
 *
 *  Created on: 17 Oct. 2017
 *      Author: tom
 */

#include <iostream>
#include <gtest/gtest.h>
#include "exceptions/ArgumentInvalidException.h"

namespace InMemoryBus
{
    void expect_std_strings_are_equal(const std::string & expected,
            const std::string & actual)
    {
        std::cout << "Actual  : " << actual << "\n";
        std::cout << "Expected: " << expected << "\n";

        EXPECT_EQ(0, expected.compare(actual));
    }

    TEST(ArgumentInvalidExceptionTest, what_returns_string_for_given_parameter_name)
    {
        using namespace InMemoryBus;

        // Arrange
        std::string expected = "Parameter 'parameter_name' is invalid!";

        // Act
        ArgumentInvalidException sut
        { "parameter_name" };

        // Assert
        std::string actual(sut.what());

        expect_std_strings_are_equal(expected, actual);
    }

    TEST(ArgumentInvalidExceptionTest, what_returns_string_for_given_message_and_parameter_name)
    {
        using namespace InMemoryBus;

        // Arrange
        std::string expected = "Parameter 'parameter_name' is invalid! message";

        // Act
        ArgumentInvalidException sut
        { "message", "parameter_name" };

        // Assert
        std::string actual(sut.what());

        expect_std_strings_are_equal(expected, actual);
    }

} /* namespace InMemoryBus */
