/*
 * NotifierThreadPoolTests.cpp
 *
 *  Created on: 6 Dec. 2017
 *      Author: tom
 */
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Common.h"
#include "../Mocks/MockILogger.h"
#include "../Mocks/MockIMessagesQueue.h"
#include "../Mocks/MockISubscibersNotifier.h"
#include "../Mocks/MockIMessageBusPublisher.h"
#include "InMemoryBus/Common/MessageBusSynchronization.h"
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "InMemoryBus/Notifiers/NotifierThreadPool.h"

namespace InMemoryBusTests {

using namespace InMemoryBus::Notifiers;

TEST(NotifierThreadPoolTests, constructor_throws_for_logger_is_nullptr) {
  try {
    // Arrange
    ILogger_SPtr logger = nullptr;
    MessageBusSynchronization_SPtr synchronization = std::make_shared<InMemoryBus::Common::MessageBusSynchronization>();
    IMessageBusPublisher_SPtr publisher = std::make_shared<MockIMessageBusPublisher>();
    IMessagesQueue_SPtr messages = std::make_shared<MockIMessagesQueue>();
    ISubscibersNotifier_SPtr notifier = std::make_shared<MockISubscibersNotifier>();

    // Act
    NotifierThreadPool sut { logger, synchronization, publisher, messages, notifier };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'logger' is invalid! Can't create NotifierThreadPool because 'logger' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(NotifierThreadPoolTests, constructor_throws_for_synchronization_is_nullptr) {
  try {
    // Arrange
    ILogger_SPtr logger = std::make_shared<MockILogger>();
    MessageBusSynchronization_SPtr synchronization = nullptr;
    IMessageBusPublisher_SPtr publisher = std::make_shared<MockIMessageBusPublisher>();
    IMessagesQueue_SPtr messages = std::make_shared<MockIMessagesQueue>();
    ISubscibersNotifier_SPtr notifier = std::make_shared<MockISubscibersNotifier>();

    // Act
    NotifierThreadPool sut { logger, synchronization, publisher, messages, notifier };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'synchronization' is invalid! Can't create NotifierThreadPool because 'synchronization' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(NotifierThreadPoolTests, constructor_throws_for_publisher_is_nullptr) {
  try {
    // Arrange
    ILogger_SPtr logger = std::make_shared<MockILogger>();
    MessageBusSynchronization_SPtr synchronization = std::make_shared<InMemoryBus::Common::MessageBusSynchronization>();
    IMessageBusPublisher_SPtr publisher = nullptr;
    IMessagesQueue_SPtr messages = std::make_shared<MockIMessagesQueue>();
    ISubscibersNotifier_SPtr notifier = std::make_shared<MockISubscibersNotifier>();

    // Act
    NotifierThreadPool sut { logger, synchronization, publisher, messages, notifier };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'publisher' is invalid! Can't create NotifierThreadPool because 'publisher' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(NotifierThreadPoolTests, constructor_throws_for_messages_is_nullptr) {
  try {
    // Arrange
    ILogger_SPtr logger = std::make_shared<MockILogger>();
    MessageBusSynchronization_SPtr synchronization = std::make_shared<InMemoryBus::Common::MessageBusSynchronization>();
    IMessageBusPublisher_SPtr publisher = std::make_shared<MockIMessageBusPublisher>();
    IMessagesQueue_SPtr messages = nullptr;
    ISubscibersNotifier_SPtr notifier = std::make_shared<MockISubscibersNotifier>();

    // Act
    NotifierThreadPool sut { logger, synchronization, publisher, messages, notifier };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'messages' is invalid! Can't create NotifierThreadPool because 'messages' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(NotifierThreadPoolTests, constructor_throws_for_notifier_is_nullptr) {
  try {
    // Arrange
    ILogger_SPtr logger = std::make_shared<MockILogger>();
    MessageBusSynchronization_SPtr synchronization = std::make_shared<InMemoryBus::Common::MessageBusSynchronization>();
    IMessageBusPublisher_SPtr publisher = std::make_shared<MockIMessageBusPublisher>();
    IMessagesQueue_SPtr messages = std::make_shared<MockIMessagesQueue>();
    ISubscibersNotifier_SPtr notifier = nullptr;

    // Act
    NotifierThreadPool sut { logger, synchronization, publisher, messages, notifier };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'notifier' is invalid! Can't create NotifierThreadPool because 'notifier' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

}
