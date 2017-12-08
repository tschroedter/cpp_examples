/*
 * FailedToNotifyTests.cpp
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "InMemoryBus/BaseMessage.h"
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "InMemoryBus/Notifiers/Failed/FailedToNotify.h"
#include "InMemoryBus/Subscribtions/Subscribers/SubscriberInformationEntity.h"
#include "InMemoryBus/Subscribtions/Subscribers/ISubscriberInformationEntity.h"
#include "../Common.h"
#include "../Subscribtions/Subscribers/TestSubscriber.h"
#include "../Subscribtions/Subscribers/TestMessage.h"

namespace InMemoryBusTests {

using namespace InMemoryBus::Notifiers::Failed;

TEST(FailedToNotify, constructor_throws_for_information_is_nullptr) {
  try {
    // Arrange
    ISubscriberInformationEntity_SPtr information = nullptr;
    BaseMessage_SPtr message = std::make_shared<TestMessage>();

    // Act
    FailedToNotify sut { information, message };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'information' is invalid! Can't create FailedToNotify because 'information' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(FailedToNotify, constructor_throws_for_message_is_nullptr) {
  try {
    // Arrange
    TestSubscriber subscriber;

    ISubscriberInformationEntity_SPtr information = std::make_shared<
        InMemoryBus::Subscribtions::Subscribers::SubscriberInformationEntity>("id", "type", subscriber.getNotifyFunc());

    BaseMessage_SPtr message = nullptr;

    // Act
    FailedToNotify sut { information, message };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'message' is invalid! Can't create FailedToNotify because 'message' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(FailedToNotify, get_information_returns_information) {
  // Arrange
  TestSubscriber subscriber;

  ISubscriberInformationEntity_SPtr information = std::make_shared<
      InMemoryBus::Subscribtions::Subscribers::SubscriberInformationEntity>("id", "type", subscriber.getNotifyFunc());

  BaseMessage_SPtr message = std::make_shared<TestMessage>();

  FailedToNotify sut { information, message };

  // Act
  auto actual = sut.get_information();

  // Assert
  EXPECT_EQ(information, actual);
}

TEST(FailedToNotify, get_message_returns_message) {
  // Arrange
  TestSubscriber subscriber;

  ISubscriberInformationEntity_SPtr information = std::make_shared<
      InMemoryBus::Subscribtions::Subscribers::SubscriberInformationEntity>("id", "type", subscriber.getNotifyFunc());

  BaseMessage_SPtr message = std::make_shared<TestMessage>();

  FailedToNotify sut { information, message };

  // Act
  auto actual = sut.get_message();

  // Assert
  EXPECT_EQ(message, actual);
}

}
