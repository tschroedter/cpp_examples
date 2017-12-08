/*
 * ThreadSafeFailedToNotifyQueueTests.cpp
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../Mocks/MockIFailedToNotify.h"
#include "../../Mocks/MockIFailedToNotifyQueue.h"
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "InMemoryBus/Notifiers/Failed/FailedToNotify.h"
#include "InMemoryBus/Notifiers/Failed/IFailedToNotifyQueue.h"
#include "InMemoryBus/Notifiers/Failed/ThreadSafe/ThreadSafeFailedToNotifyQueue.h"
#include "../../Common.h"

namespace InMemoryBusTests {

using namespace InMemoryBus::Notifiers::Failed::ThreadSafe;

TEST(ThreadSafeFailedToNotifyQueueTests, constructor_throws_for_queue_is_nullptr) {
  try {
    // Arrange
    IFailedToNotifyQueue_SPtr queue = nullptr;

    // Act
    ThreadSafeFailedToNotifyQueue sut { queue };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'queue' is invalid! Can't create ThreadSafeFailedToNotifyQueue because 'queue' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(ThreadSafeFailedToNotifyQueueTests, enqueue_calls_queue) {
  // Arrange
  IFailedToNotify_SPtr failed = std::make_shared<MockIFailedToNotify>();
  MockIFailedToNotifyQueue* p_mock_queue = new MockIFailedToNotifyQueue();
  IFailedToNotifyQueue_SPtr queue { p_mock_queue };

  ThreadSafeFailedToNotifyQueue sut { queue };

  EXPECT_CALL(*p_mock_queue, enqueue(failed)).Times(1);

  // Act
  sut.enqueue(failed);

  // Assert
}

TEST(ThreadSafeFailedToNotifyQueueTests, dequeue_calls_queue) {
  // Arrange
  IFailedToNotify_SPtr failed = std::make_shared<MockIFailedToNotify>();
  MockIFailedToNotifyQueue* p_mock_queue = new MockIFailedToNotifyQueue();
  IFailedToNotifyQueue_SPtr queue { p_mock_queue };

  ThreadSafeFailedToNotifyQueue sut { queue };

  EXPECT_CALL(*p_mock_queue, dequeue()).Times(1).WillOnce(testing::Return(failed));

  // Act
  auto actual = sut.dequeue();

  // Assert
  EXPECT_EQ(failed, actual);
}

TEST(ThreadSafeFailedToNotifyQueueTests, size_calls_queue) {
  // Arrange
  IFailedToNotify_SPtr failed = std::make_shared<MockIFailedToNotify>();
  MockIFailedToNotifyQueue* p_mock_queue = new MockIFailedToNotifyQueue();
  IFailedToNotifyQueue_SPtr queue { p_mock_queue };

  ThreadSafeFailedToNotifyQueue sut { queue };

  EXPECT_CALL(*p_mock_queue, size()).Times(1).WillOnce(testing::Return((size_t) 1));

  // Act
  int actual = sut.size();

  // Assert
  EXPECT_EQ(1, actual);
}

}
