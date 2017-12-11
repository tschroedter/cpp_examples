/*
 * FailedToNotifyManagerTests.cpp
 *
 *  Created on: 12 Dec. 2017
 *      Author: tom
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "InMemoryBus/Common/BaseMessage.h"
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "InMemoryBus/Notifiers/Failed/FailedToNotifyManager.h"
#include "InMemoryBus/Notifiers/Failed/IFailedToNotify.h"
#include "InMemoryBus/Notifiers/Failed/ThreadSafe/IThreadSafeFailedToNotifyQueue.h"
#include "InMemoryBus/Common/ILogger.h"
#include "../../Mocks/MockILogger.h"
#include "../../Mocks/MockIFailedToNotifyQueue.h"
#include "../../Mocks/MockIThreadSafeFailedToNotifyQueue.h"
#include "../../Mocks/MockISubscriberInformationEntity.h"
#include "../../Common.h"
#include "../../Common/TestMessage.h"

namespace InMemoryBusTests {

using namespace InMemoryBus::Notifiers::Failed;

TEST(FailedToNotifyManagerTests, constructor_throws_for_logger_is_nullptr) {
  try {
    // Arrange
    ILogger_SPtr logger = nullptr;
    IThreadSafeFailedToNotifyQueue_SPtr queue = std::make_shared<MockIThreadSafeFailedToNotifyQueue>();

    // Act
    FailedToNotifyManager sut { logger, queue };

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

TEST(FailedToNotifyManagerTests, constructor_throws_for_queue_is_nullptr) {
  try {
    // Arrange
    ILogger_SPtr logger = std::make_shared<MockILogger>();
    IThreadSafeFailedToNotifyQueue_SPtr queue = nullptr;

    // Act
    FailedToNotifyManager sut { logger, queue };

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
  // Arrange
  BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();
  ISubscriberInformationEntity_SPtr entity = std::make_shared<MockISubscriberInformationEntity>();

  MockILogger* p_mock_logger = new MockILogger();
  ILogger_SPtr logger { p_mock_logger };

  MockIThreadSafeFailedToNotifyQueue* p_mock_queue = new MockIThreadSafeFailedToNotifyQueue();
  IThreadSafeFailedToNotifyQueue_SPtr queue { p_mock_queue };

  FailedToNotifyManager sut { logger, queue };

  EXPECT_CALL(*p_mock_queue, enqueue(testing::A<IFailedToNotify_SPtr>())).Times(1);
  EXPECT_CALL(*p_mock_logger, error(testing::A<std::string>())).Times(1);

  // Act
  sut.handle_failed_notification(entity, message);

  // Assert
}

}
