/*
 * MockIMessageToSubscribersEntityFactory.h
 *
 *  Created on: 15 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_MOCKS_MOCKIMESSAGETOSUBSCRIBERSENTITYFACTORY_H_
#define INMEMORYBUS_MOCKS_MOCKIMESSAGETOSUBSCRIBERSENTITYFACTORY_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "InMemoryBus/Subscribtions/MessageToSubscribers/IMessageToSubscribersEntity.h"
#include "InMemoryBus/Subscribtions/MessageToSubscribers/IMessageToSubscribersEntityFactory.h"

namespace InMemoryBusTests {
class MockIMessageToSubscribersEntityFactory :
    public InMemoryBus::Subscribtions::MessageToSubscribers::IMessageToSubscribersEntityFactory {
 public:
  virtual ~MockIMessageToSubscribersEntityFactory() = default;

  MOCK_METHOD1(create, IMessageToSubscribersEntity_SPtr(const std::string));};
}

#endif /* INMEMORYBUS_MOCKS_MOCKIMESSAGETOSUBSCRIBERSENTITYFACTORY_H_ */
