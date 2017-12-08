/*
 * MockIThreadSafeFailedToNotifyQueue.h
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_MOCKS_MOCKITHREADSAFEFAILEDTONOTIFYQUEUE_H_
#define INMEMORYBUS_MOCKS_MOCKITHREADSAFEFAILEDTONOTIFYQUEUE_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "InMemoryBus/Notifiers/Failed/ThreadSafe/IThreadSafeFailedToNotifyQueue.h"
#include "InMemoryBus/Notifiers/Failed/IFailedToNotify.h"

namespace InMemoryBusTests {

class MockIThreadSafeFailedToNotifyQueue :
    public InMemoryBus::Notifiers::Failed::ThreadSafe::IThreadSafeFailedToNotifyQueue {
 public:
  MOCK_METHOD1(enqueue, void(IFailedToNotify_SPtr failed));
  MOCK_METHOD0(dequeue, IFailedToNotify_SPtr());
  MOCK_METHOD0(size, size_t());
};

}

#endif /* INMEMORYBUS_MOCKS_MOCKITHREADSAFEFAILEDTONOTIFYQUEUE_H_ */
