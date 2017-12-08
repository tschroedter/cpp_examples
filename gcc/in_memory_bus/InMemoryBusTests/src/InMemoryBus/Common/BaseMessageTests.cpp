/*
 * BaseMessageTests.cpp
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#include <iostream>
#include <gtest/gtest.h>
#include "TestBaseEntity.h"
#include "uuid/uuid.h"

#include "InMemoryBus/Common/BaseMessage.h"
#include "../Common.h"
#include "TestMessage.h"

namespace InMemoryBusTests {

using namespace InMemoryBus::Common;

TEST(BaseMessageTests, get_type_returns_type) {
  // Arrange
  BaseMessage sut { "type" };

  // Act
  auto actual = sut.getType();

  // Assert
  InMemoryBusTest::expect_std_strings_are_equal("type", actual);
}

TEST(BaseMessageTests, get_type_returns_type_for_sub_class) {
  // Arrange
  TestMessage sut { };

  // Act
  auto actual = sut.getType();

  // Assert
  InMemoryBusTest::expect_std_strings_are_equal("TestMessage", actual);
}

}
