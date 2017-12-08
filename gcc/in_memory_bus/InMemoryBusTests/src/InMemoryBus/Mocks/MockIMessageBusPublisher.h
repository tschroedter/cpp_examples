/*
 * MockIMessageBusPublisher.h
 *
 *  Created on: 4 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_MOCKIMESSAGEBUSPUBLISHER_H_
#define INMEMORYBUS_MOCKIMESSAGEBUSPUBLISHER_H_

#include <gtest/gtest.h>
#include "InMemoryBus/BaseMessage.h"
#include "InMemoryBus/Publishers/IMessageBusPublisher.h"

using namespace std;

namespace InMemoryBusTests {

class MockIMessageBusPublisher : public InMemoryBus::Publishers::IMessageBusPublisher {
 public:
  MOCK_METHOD1(publish, void(BaseMessage_SPtr message));
};
}

#endif /* INMEMORYBUS_MOCKIMESSAGEBUSPUBLISHER_H_ */
