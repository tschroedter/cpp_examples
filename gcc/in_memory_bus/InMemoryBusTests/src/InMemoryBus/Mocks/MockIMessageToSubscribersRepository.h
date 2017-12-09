/*
 * MockIMessageToSubscribersRepository.h
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_MOCKS_MOCKIMESSAGETOSUBSCRIBERSREPOSITORY_H_
#define SRC_INMEMORYBUS_MOCKS_MOCKIMESSAGETOSUBSCRIBERSREPOSITORY_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "InMemoryBus/Subscribtions/MessageToSubscribers/IMessageToSubscribersRepository.h"
#include "InMemoryBus/Subscribtions/MessageToSubscribers/IMessageToSubscribersEntity.h"

namespace InMemoryBusTests {

using namespace std;

class MockIMessageToSubscribersRepository : public InMemoryBus::Subscribtions::MessageToSubscribers::IMessageToSubscribersRepository {
 public:
  MOCK_CONST_METHOD0(get_all_subscribers, IMessageToSubscribersEntityVector_SPtr());
  MOCK_METHOD1(find_subscriber_by_message_type, IMessageToSubscribersEntity_SPtr(const std::string& message_type));
  MOCK_METHOD1(remove, void(const IMessageToSubscribersEntity_SPtr information));
  MOCK_METHOD1(add, void(const IMessageToSubscribersEntity_SPtr information));
  MOCK_CONST_METHOD0(size, size_t());
};

}

#endif /* SRC_INMEMORYBUS_MOCKS_MOCKIMESSAGETOSUBSCRIBERSREPOSITORY_H_ */
