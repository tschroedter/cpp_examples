/*
 * MessageBusPublisherTests.cpp
 *
 *  Created on: 6 Dec. 2017
 *      Author: tom
 */
#include <memory>
#include <thread>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Common.h"
#include "../Mocks/MockIMessagesQueue.h"
#include "TestNotifier.h"
#include "InMemoryBus/Common/MessageBusSynchronization.h"
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "InMemoryBus/Publishers/MessageBusPublisher.h"
#include "../Common/TestMessage.h"

namespace InMemoryBusTests {

using namespace InMemoryBus::Publishers;

TEST(MessageBusPublisherTests, constructor_throws_for_synchronization_is_nullptr) {
  try {
    // Arrange
    MessageBusSynchronization_SPtr synchronization = nullptr;
    IMessagesQueue_SPtr messages = std::make_shared<MockIMessagesQueue>();

    // Act
    MessageBusPublisher sut { synchronization, messages };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'synchronization' is invalid! Can't create MessageBusPublisher because 'synchronization' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(MessageBusPublisherTests, constructor_throws_for_messages_is_nullptr) {
  try {
    // Arrange
    MessageBusSynchronization_SPtr synchronization = std::make_shared<InMemoryBus::Common::MessageBusSynchronization>();
    IMessagesQueue_SPtr messages = nullptr;

    // Act
    MessageBusPublisher sut { synchronization, messages };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'messages' is invalid! Can't create MessageBusPublisher because 'messages' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(MessageBusPublisherTests, publish_calls_enqueue) {
  // Arrange
  BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();
  MessageBusSynchronization_SPtr synchronization = std::make_shared<InMemoryBus::Common::MessageBusSynchronization>();
  MockIMessagesQueue* p_mock_messages = new MockIMessagesQueue();
  IMessagesQueue_SPtr messages { p_mock_messages };

  MessageBusPublisher sut { synchronization, messages };

  EXPECT_CALL(*p_mock_messages, enqueue(message)).Times(1);

  // Act
  sut.publish(message);

  // Assert
}

TEST(MessageBusPublisherTests, publish_sets_is_messages_avalable_to_true) {
  // Arrange
  BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();
  MessageBusSynchronization_SPtr synchronization = std::make_shared<InMemoryBus::Common::MessageBusSynchronization>();
  MockIMessagesQueue* p_mock_messages = new MockIMessagesQueue();
  IMessagesQueue_SPtr messages{p_mock_messages};

  MessageBusPublisher sut { synchronization, messages };

  EXPECT_CALL(*p_mock_messages, enqueue(message)).Times(1);

  // Act
  sut.publish(message);

  // Assert
  EXPECT_TRUE(synchronization->is_messages_avalable);
}

TEST(MessageBusPublisherTests, publish_notifies_one) {
  // Arrange
  BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();
  MessageBusSynchronization_SPtr synchronization = std::make_shared<InMemoryBus::Common::MessageBusSynchronization>();
  MockIMessagesQueue* p_mock_queue = new MockIMessagesQueue();
  IMessagesQueue_SPtr messages { p_mock_queue };

  MessageBusPublisher sut { synchronization, messages };

  auto notifier = std::make_shared<TestNotifier>(synchronization, 1000);
  auto notifier_thread = std::thread([notifier]() {(*notifier)();});

  EXPECT_CALL(*p_mock_queue, enqueue(message)).Times(1);

  // Act
  sut.publish(message);
  notifier_thread.join();  // TODO maybe use extra timeout

  // Assert
  EXPECT_TRUE(notifier->was_called_notify);
}

}
