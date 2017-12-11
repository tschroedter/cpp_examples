/*
 * MockIMessageToSubscribersEntity.h
 *
 *  Created on: 9 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_MOCKS_MOCKIMESSAGETOSUBSCRIBERSENTITY_H_
#define SRC_INMEMORYBUS_MOCKS_MOCKIMESSAGETOSUBSCRIBERSENTITY_H_

#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "InMemoryBus/Subscribtions/MessageToSubscribers/IMessageToSubscribersEntity.h"
#include "InMemoryBus/Subscribtions/Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"

using namespace std;

namespace InMemoryBusTests {

class MockIMessageToSubscribersEntity :
    public InMemoryBus::Subscribtions::MessageToSubscribers::IMessageToSubscribersEntity {
 public:
  MOCK_CONST_METHOD0(get_message_type, std::string());
  MOCK_CONST_METHOD0(get_repository, IThreadSafeSubscriberInformationRepository_SPtr());
};

}

#endif /* SRC_INMEMORYBUS_MOCKS_MOCKIMESSAGETOSUBSCRIBERSENTITY_H_ */
