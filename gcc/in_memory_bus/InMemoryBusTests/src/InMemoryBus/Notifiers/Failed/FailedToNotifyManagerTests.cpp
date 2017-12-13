/*
 * FailedToNotifyManagerTests.cpp
 *
 *  Created on: 12 Dec. 2017
 *      Author: tom
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "InMemoryBus/Common/BaseMessage.h"
#include "InMemoryBus/Common/MessageBusSynchronization.h"
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "InMemoryBus/Notifiers/Failed/FailedToNotifyManager.h"
#include "InMemoryBus/Notifiers/Failed/IFailedToNotify.h"
#include "InMemoryBus/Notifiers/Failed/ThreadSafe/IThreadSafeFailedToNotifyQueue.h"
#include "InMemoryBus/Common/ILogger.h"
#include "../../Mocks/MockILogger.h"
#include "../../Mocks/MockIFailedToNotifyQueue.h"
#include "../../Mocks/MockIThreadSafeFailedToNotifyQueue.h"
#include "../../Mocks/MockISubscriberInformationEntity.h"
#include "../../Mocks/MockIFailedSubscriberFunctionCaller.h"
#include "../../Common.h"
#include "../../Common/TestMessage.h"

namespace InMemoryBusTests {

using namespace InMemoryBus::Notifiers::Failed;

TEST(FailedToNotifyManagerTests, constructor_throws_for_logger_is_nullptr) {
  try {
    // Arrange
    ILogger_SPtr logger = nullptr;
    MessageBusSynchronization_SPtr synchronization = std::make_shared<InMemoryBus::Common::MessageBusSynchronization>();
    IThreadSafeFailedToNotifyQueue_SPtr queue = std::make_shared<MockIThreadSafeFailedToNotifyQueue>();
    IFailedSubscriberFunctionCaller_SPtr caller = std::make_shared<MockIFailedSubscriberFunctionCaller>();

    // Act
    FailedToNotifyManager sut { logger, synchronization, queue, caller };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'logger' is invalid! Can't create FailedToNotifyManager because 'logger' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(FailedToNotifyManagerTests, constructor_throws_for_synchronization_is_nullptr) {
  try {
    // Arrange
    ILogger_SPtr logger = std::make_shared<MockILogger>();
    MessageBusSynchronization_SPtr synchronization = nullptr;
    IThreadSafeFailedToNotifyQueue_SPtr queue = std::make_shared<MockIThreadSafeFailedToNotifyQueue>();
    IFailedSubscriberFunctionCaller_SPtr caller = std::make_shared<MockIFailedSubscriberFunctionCaller>();

    // Act
    FailedToNotifyManager sut { logger, synchronization, queue, caller };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'synchronization' is invalid! Can't create FailedToNotifyManager because 'synchronization' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(FailedToNotifyManagerTests, constructor_throws_for_caller_is_nullptr) {
  try {
    // Arrange
    ILogger_SPtr logger = std::make_shared<MockILogger>();
    MessageBusSynchronization_SPtr synchronization = std::make_shared<InMemoryBus::Common::MessageBusSynchronization>();
    IThreadSafeFailedToNotifyQueue_SPtr queue = std::make_shared<MockIThreadSafeFailedToNotifyQueue>();
    IFailedSubscriberFunctionCaller_SPtr caller = nullptr;

    // Act
    FailedToNotifyManager sut { logger, synchronization, queue, caller };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'caller' is invalid! Can't create FailedToNotifyManager because 'caller' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(FailedToNotifyManagerTests, constructor_throws_for_queue_is_nullptr) {
  try {
    // Arrange
    ILogger_SPtr logger = std::make_shared<MockILogger>();
    MessageBusSynchronization_SPtr synchronization = std::make_shared<InMemoryBus::Common::MessageBusSynchronization>();
    IThreadSafeFailedToNotifyQueue_SPtr queue = nullptr;
    IFailedSubscriberFunctionCaller_SPtr caller = std::make_shared<MockIFailedSubscriberFunctionCaller>();

    // Act
    FailedToNotifyManager sut { logger, synchronization, queue, caller };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'queue' is invalid! Can't create FailedToNotifyManager because 'queue' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(FailedToNotifyManagerTests, handle_failed_notification_calls_enqueue) {
  /* TODO more testing
  // Arrange
  BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();
  MockISubscriberInformationEntity* p_mock_entity = new MockISubscriberInformationEntity();
  ISubscriberInformationEntity_SPtr entity = std::make_shared<MockISubscriberInformationEntity>();

  MockILogger* p_mock_logger = new MockILogger();
  ILogger_SPtr logger { p_mock_logger };

  MockIThreadSafeFailedToNotifyQueue* p_mock_queue = new MockIThreadSafeFailedToNotifyQueue();
  IThreadSafeFailedToNotifyQueue_SPtr queue { p_mock_queue };

  IFailedSubscriberFunctionCaller_SPtr caller = std::make_shared<MockIFailedSubscriberFunctionCaller>();

  EXPECT_CALL(*p_mock_logger, set_prefix("FailedToNotifyManager")).Times(1);
  EXPECT_CALL(*p_mock_queue, enqueue(testing::A<IFailedToNotify_SPtr>())).Times(1);
  EXPECT_CALL(*p_mock_logger, warn(testing::A<std::string>())).Times(1);
  EXPECT_CALL(*p_mock_entity, get_subscriber_id()).Times(1).WillOnce(testing::Return(std::string("id")));

  FailedToNotifyManager sut { logger, queue, caller };

  // Act
  sut.handle_failed_notification(entity, message);

  // Assert
   */
}

}
