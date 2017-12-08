/*
 * ArgumentInvalidExceptionTests.cpp
 *
 *  Created on: 17 Oct. 2017
 *      Author: tom
 */

#include <iostream>
#include <gtest/gtest.h>
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "../Common.h"

namespace InMemoryBusTests {
namespace Exceptions {

using namespace InMemoryBus::Exceptions;

TEST(ArgumentInvalidExceptionTest, what_returns_string_for_given_parameter_name) {
  // Arrange
  std::string expected = "Parameter 'parameter_name' is invalid!";

  // Act
  ArgumentInvalidException sut { "parameter_name" };

  // Assert
  std::string actual(sut.what());

  InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
}

TEST(ArgumentInvalidExceptionTest, what_returns_string_for_given_message_and_parameter_name) {
  // Arrange
  std::string expected = "Parameter 'parameter_name' is invalid! message";

  // Act
  ArgumentInvalidException sut { "message", "parameter_name" };

  // Assert
  std::string actual(sut.what());

  InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
}

TEST(ArgumentInvalidExceptionTest, get_message_string_for_given_parameter_name) {
  // Arrange
  std::string expected = "Parameter 'parameter_name' is invalid!";

  // Act
  ArgumentInvalidException sut { "parameter_name" };

  // Assert
  std::string actual(sut.get_message());

  InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
}

TEST(ArgumentInvalidExceptionTest, get_message_string_for_given_message_and_parameter_name) {
  // Arrange
  std::string expected = "Parameter 'parameter_name' is invalid! message";

  // Act
  ArgumentInvalidException sut { "message", "parameter_name" };

  // Assert
  std::string actual(sut.get_message());

  InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
}

}
}

