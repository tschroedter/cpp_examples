/*
 * MessageBusNotifierTests.cpp
 *
 *  Created on: 4 Dec. 2017
 *      Author: tom
 */

#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "InMemoryBus/Notifiers/MessageBusNotifier.h"
#include "InMemoryBus/Common/MessageBusSynchronization.h"
#include "InMemoryBus/Publishers/MessageBusPublisher.h"
#include "TestMessageBusNotifier.h"
#include "../Common.h"
#include "../Mocks/MockIMessagesQueue.h"
#include "../Mocks/MockISubscibersNotifier.h"
#include "../Common/TestMessage.h"

namespace InMemoryBusTests {

using namespace InMemoryBus::Notifiers;

TEST(MessageBusNotifierTests, constructor_throws_for_synchronization_is_nullptr) {
  try {
    // Arrange
    IMessagesQueue_SPtr messages = std::make_shared<MockIMessagesQueue>();
    ISubscibersNotifier_SPtr notifier = std::make_shared<MockISubscibersNotifier>();

    // Act
    MessageBusNotifier sut { nullptr, messages, notifier };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'synchronization' is invalid! Can't create MessageBusNotifier because 'synchronization' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(MessageBusNotifierTests, constructor_throws_for_messages_is_nullptr) {
  try {
    // Arrange
    MessageBusSynchronization_SPtr synchronization = std::make_shared<InMemoryBus::Common::MessageBusSynchronization>();  // TODO missing an interface here?
    ISubscibersNotifier_SPtr notifier = std::make_shared<MockISubscibersNotifier>();

    // Act
    MessageBusNotifier sut { synchronization, nullptr, notifier };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'messages' is invalid! Can't create MessageBusNotifier because 'messages' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(MessageBusNotifierTests, process_next_message_does_not_calls_dequeue_for_size_is_zero) {
  // Arrange
  Message_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();

  MessageBusSynchronization_SPtr synchronization = std::make_shared<InMemoryBus::Common::MessageBusSynchronization>();
  MockIMessagesQueue* p_mock_messages = new MockIMessagesQueue();
  IMessagesQueue_SPtr messages { p_mock_messages };
  ISubscibersNotifier_SPtr notifier = std::make_shared<MockISubscibersNotifier>();

  TestMessageBusNotifier sut { synchronization, messages, notifier };

  EXPECT_CALL(*p_mock_messages, size()).Times(1).WillOnce(testing::Return((size_t) 0));
  EXPECT_CALL(*p_mock_messages, dequeue()).Times(0);

  // Act
  sut.process_next_message();

  // Assert
}

TEST(MessageBusNotifierTests, process_next_message_calls_dequeue) {
  // Arrange
  BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();

  MessageBusSynchronization_SPtr synchronization = std::make_shared<InMemoryBus::Common::MessageBusSynchronization>();
  MockIMessagesQueue* p_mock_messages = new MockIMessagesQueue();
  IMessagesQueue_SPtr messages { p_mock_messages };
  MockISubscibersNotifier* p_mock_notifier = new MockISubscibersNotifier();
  ISubscibersNotifier_SPtr notifier { p_mock_notifier };

  TestMessageBusNotifier sut { synchronization, messages, notifier };

  EXPECT_CALL(*p_mock_messages, size()).Times(1).WillOnce(testing::Return((size_t) 1));
  EXPECT_CALL(*p_mock_messages, dequeue()).Times(1).WillOnce(testing::Return(message));
  EXPECT_CALL(*p_mock_notifier, notify_all_subscribers_for_message(message)).Times(1);

  // Act
  sut.process_next_message();

  // Assert
}

TEST(MessageBusNotifierTests, process_next_message_calls_notifier) {
  // Arrange
  BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();
  MessageBusSynchronization_SPtr synchronization = std::make_shared<InMemoryBus::Common::MessageBusSynchronization>();
  MockIMessagesQueue* p_mock_messages = new MockIMessagesQueue();
  IMessagesQueue_SPtr messages { p_mock_messages };
  MockISubscibersNotifier* p_mock_notifier = new MockISubscibersNotifier();
  ISubscibersNotifier_SPtr notifier { p_mock_notifier };

  TestMessageBusNotifier sut { synchronization, messages, notifier };

  EXPECT_CALL(*p_mock_messages, size()).Times(1).WillOnce(testing::Return((size_t) 1));
  EXPECT_CALL(*p_mock_messages, dequeue()).Times(1).WillOnce(testing::Return(message));
  EXPECT_CALL(*p_mock_notifier, notify_all_subscribers_for_message(message)).Times(1);

  // Act
  sut.process_next_message();

  // Assert
}

TEST(MessageBusNotifierTests, notify_calls_process_next_message) {
  // Arrange
  BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();
  MessageBusSynchronization_SPtr synchronization = std::make_shared<InMemoryBus::Common::MessageBusSynchronization>();
  MockIMessagesQueue* p_mock_messages = new MockIMessagesQueue();
  IMessagesQueue_SPtr messages { p_mock_messages };
  MockISubscibersNotifier* p_mock_notifier = new MockISubscibersNotifier();
  ISubscibersNotifier_SPtr notifier { p_mock_notifier };

  TestMessageBusNotifier sut { synchronization, messages, notifier };

  EXPECT_CALL(*p_mock_messages, size()).WillOnce(testing::Return((size_t) 1)).WillRepeatedly(
      testing::Return((size_t) 0));
  EXPECT_CALL(*p_mock_messages, dequeue()).Times(1).WillOnce(testing::Return(message));
  EXPECT_CALL(*p_mock_notifier, notify_all_subscribers_for_message(message)).Times(1);

  // Act
  synchronization->is_messages_avalable_for_thread_pool = true;
  synchronization->messages_available.notify_one();
  std::thread notifer = std::thread(&TestMessageBusNotifier::notify, sut);

  // Assert
  std::this_thread::sleep_for(std::chrono::milliseconds(100));  // not nice, but we have to wait for the thread to process
  synchronization->is_stop_requested_for_thread_pool.store(true);
  synchronization->is_messages_avalable_for_thread_pool = true;
  synchronization->messages_available.notify_one();
  notifer.join();
}

}

