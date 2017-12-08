/*
 * MockIMessagesQueue.h
 *
 *  Created on: 4 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_MOCKIMESSAGESQUEUE_H_
#define INMEMORYBUS_MOCKIMESSAGESQUEUE_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "InMemoryBus/Common/IMessagesQueue.h"
#include "InMemoryBus/Common/BaseMessage.h"

using namespace std;

namespace InMemoryBusTests {

class MockIMessagesQueue : public InMemoryBus::Common::IMessagesQueue {
 public:
  MOCK_METHOD0(dequeue, BaseMessage_SPtr());
  MOCK_METHOD1(enqueue, void(BaseMessage_SPtr message));
  MOCK_CONST_METHOD0(size, size_t());
};

}

#endif /* INMEMORYBUS_MOCKIMESSAGESQUEUE_H_ */
