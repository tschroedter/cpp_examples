/*
 * MessageBusTests.cpp
 *
 *  Created on: 13Jun.,2017
 *      Author: tom
 */

#include <iostream>
#include <gtest/gtest.h>
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "InMemoryBus/Common/SubscriberFunction.h"
#include "InMemoryBus/MessageBus.h"
#include "Common.h"
#include "Common/TestSubscriber.h"
#include "Mocks/MockISubscribtionManager.h"
#include "Mocks/MockIMessageBusPublisher.h"

namespace InMemoryBusTests {

using namespace InMemoryBus;

TEST(MessageBusTest, constructor_throws_for_publisher_is_null) {
  try {
    // Arrange
    IMessageBusPublisher_SPtr publisher = nullptr;
    ISubscribtionManager_SPtr manager = std::make_shared<MockISubscribtionManager>();

    // Act
    MessageBus sut { publisher, manager };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'publisher' is invalid! Can't create MessageBus because 'publisher' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(MessageBusTest, constructor_throws_for_manager_is_null) {
  try {
    // Arrange
    IMessageBusPublisher_SPtr publisher = std::make_shared<MockIMessageBusPublisher>();
    ISubscribtionManager_SPtr manager = nullptr;

    // Act
    MessageBus sut { publisher, manager };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'manager' is invalid! Can't create MessageBus because 'manager' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(MessageBusTest, subscribe_calls_manager_add_subscription) {
  // Arrange
  InMemoryBusTests::TestSubscriber subscriber;

  IMessageBusPublisher_SPtr publisher = std::make_shared<MockIMessageBusPublisher>();

  MockISubscribtionManager* p_mock_manager = new MockISubscribtionManager { };
  ISubscribtionManager_SPtr manager(p_mock_manager);

  MessageBus sut { publisher, manager };

  EXPECT_CALL(*p_mock_manager,
      add_subscription("id", "type", testing::A<InMemoryBus::SubscriberFunction>())).Times(1);

  // Act
  sut.subscribe("id", "type", subscriber.getNotifyFunc());

  // Assert
}

TEST(MessageBusTest, unsubscribe_calls_manager_) {
  // Arrange
  InMemoryBusTests::TestSubscriber subscriber;

  IMessageBusPublisher_SPtr publisher = std::make_shared<MockIMessageBusPublisher>();

  MockISubscribtionManager* p_mock_manager = new MockISubscribtionManager { };
  ISubscribtionManager_SPtr manager(p_mock_manager);

  MessageBus sut { publisher, manager };

  EXPECT_CALL(*p_mock_manager, remove_subscription("id", "type")).Times(1);

  // Act
  sut.unsubscribe("id", "type");

  // Assert
}

TEST(MessageBusTest, publish_adds_message_to_queue) {
  // Arrange
  BaseMessage_SPtr message = make_shared<InMemoryBusTests::TestMessage>("Test");

  MockIMessageBusPublisher* p_publisher = new MockIMessageBusPublisher { };
  IMessageBusPublisher_SPtr publisher(p_publisher);
  ISubscribtionManager_SPtr manager = std::make_shared<MockISubscribtionManager>();

  InMemoryBus::MessageBus sut { publisher, manager };

  EXPECT_CALL(*p_publisher, publish(message)).Times(1);

  // Act
  sut.publish(message);

  // Assert
}

}
