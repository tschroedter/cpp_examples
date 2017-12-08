/*
 * MessageBusTests.cpp
 *
 *  Created on: 13Jun.,2017
 *      Author: tom
 */

#include <iostream>
#include <gtest/gtest.h>
#include "InMemoryBus/Typedefs.h"
#include "InMemoryBus/MessageBus.h"
#include "Subscribtions/Subscribers/TestSubscriber.h"
#include "Mocks/MockISubscribtionManager.h"
#include "Mocks/MockIMessageBusPublisher.h"

namespace InMemoryBusTests {
TEST(MessageBusTest, subscribe_calls_manager_add_subscription) {
  // Arrange
  InMemoryBusTests::TestSubscriber subscriber;

  IMessageBusPublisher_SPtr publisher = std::make_shared<MockIMessageBusPublisher>();

  MockISubscribtionManager* p_mock_manager = new MockISubscribtionManager { };
  ISubscribtionManager_SPtr manager(p_mock_manager);

  InMemoryBus::MessageBus sut { publisher, manager };

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

  InMemoryBus::MessageBus sut { publisher, manager };

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
