/*
 * SubscriberInformationTests.cpp
 *
 *  Created on: 17Jun.,2017
 *      Author: tom
 */
#include <iostream>
#include <gtest/gtest.h>
#include <InMemoryBus/Subscribtions/MessageToSubscribers/UnknownMessageToSubscribersEntityEntity.h>
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"

namespace InMemoryBusTests {
using namespace InMemoryBus::Subscribtions::MessageToSubscribers;

TEST(UnknownMessageToSubscribersEntityTest, constructor_sets_message_type) {
  // Arrange
  std::string expected("Unknown");

  // Act
  UnknownMessageToSubscribersEntity sut { };

  // Assert
  EXPECT_EQ(0, expected.compare(sut.get_message_type()));
}

TEST(UnknownMessageToSubscribersEntityTest, constructor_sets_subscriber) {
  using namespace InMemoryBus;

  // Arrange
  // Act
  UnknownMessageToSubscribersEntity sut { };

  // Assert
  EXPECT_EQ(0, sut.get_repository()->size());
}

}
