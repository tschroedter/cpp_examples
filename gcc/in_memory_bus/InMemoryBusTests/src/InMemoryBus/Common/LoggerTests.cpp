/*
 * LoggerTests.cpp
 *
 *  Created on: 14 Dec. 2017
 *      Author: tom
 */

#include <iostream>
#include <sstream>
#include <gtest/gtest.h>
#include "InMemoryBus/Common/Logger.h"
#include "../Common.h"

namespace InMemoryBusTests {

using namespace InMemoryBus::Common;

void test(LogLevel function, LogLevel level, std::string expected) {
  // Arrange
  stringstream ss { };

  Logger sut { ss };

  sut.set_log_level(level);

  // Act
  auto enum_value = function.getEnum();

  switch (enum_value) {
    case LogLevel::ERROR: {
      sut.error("test");
      break;
    }
    case LogLevel::WARN: {
      sut.warn("test");
      break;
    }
    case LogLevel::INFO: {
      sut.info("test");
      break;
    }
    case LogLevel::DEBUG: {
      sut.debug("test");
      break;
    }
    default:
      break;
  }

  // Assert
  auto actual = ss.str();

  if (expected.size() > 0) {
    InMemoryBusTest::expect_std_strings_contains(actual, expected);
  } else {
    EXPECT_EQ((size_t )0, actual.size());
  }
}

TEST(LoggerTests, error_writes_string_for_loglevel_error) {
  test(LogLevel::ERROR, LogLevel::ERROR, "test");
}

TEST(LoggerTests, error_writes_string_for_loglevel_warn) {
  test(LogLevel::ERROR, LogLevel::WARN, "test");
}

TEST(LoggerTests, error_writes_string_for_loglevel_info) {
  test(LogLevel::ERROR, LogLevel::INFO, "test");
}

TEST(LoggerTests, error_writes_string_for_loglevel_debug) {
  test(LogLevel::ERROR, LogLevel::DEBUG, "test");
}

TEST(LoggerTests, warn_does_not_write_string_for_loglevel_error) {
  test(LogLevel::WARN, LogLevel::ERROR, "");
}

TEST(LoggerTests, warn_writes_string_for_loglevel_warn) {
  test(LogLevel::WARN, LogLevel::WARN, "test");
}

TEST(LoggerTests, warn_writes_string_for_loglevel_info) {
  test(LogLevel::WARN, LogLevel::INFO, "test");
}

TEST(LoggerTests, warn_writes_string_for_loglevel_debug) {
  test(LogLevel::WARN, LogLevel::DEBUG, "test");
}

TEST(LoggerTests, info_does_not_write_string_for_loglevel_error) {
  test(LogLevel::INFO, LogLevel::ERROR, "");
}

TEST(LoggerTests, info_does_not_write_string_for_loglevel_warn) {
  test(LogLevel::INFO, LogLevel::WARN, "");
}

TEST(LoggerTests, info_writes_string_for_loglevel_info) {
  test(LogLevel::INFO, LogLevel::INFO, "test");
}

TEST(LoggerTests, info_writes_string_for_loglevel_debug) {
  test(LogLevel::INFO, LogLevel::DEBUG, "test");
}

TEST(LoggerTests, debug_does_not_write_string_for_loglevel_error) {
  test(LogLevel::DEBUG, LogLevel::ERROR, "");
}

TEST(LoggerTests, debug_does_not_write_string_for_loglevel_warn) {
  test(LogLevel::DEBUG, LogLevel::WARN, "");
}

TEST(LoggerTests, debug_does_not_write_string_for_loglevel_info) {
  test(LogLevel::DEBUG, LogLevel::INFO, "");
}

TEST(LoggerTests, debug_writes_string_for_loglevel_debug) {
  test(LogLevel::DEBUG, LogLevel::DEBUG, "test");
}

}
