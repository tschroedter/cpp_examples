/*
 * MockISubscriberInformationEntity.h
 *
 *  Created on: 9 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_MOCKS_MOCKISUBSCRIBERINFORMATIONENTITY_H_
#define SRC_INMEMORYBUS_MOCKS_MOCKISUBSCRIBERINFORMATIONENTITY_H_

#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "InMemoryBus/Common/SubscriberFunction.h"
#include "InMemoryBus/Subscribtions/Subscribers/ISubscriberInformationEntity.h"

using namespace std;

namespace InMemoryBusTests {

class MockISubscriberInformationEntity : public InMemoryBus::Subscribtions::Subscribers::ISubscriberInformationEntity {
 public:
  MOCK_CONST_METHOD0(get_subscriber_id, std::string());
  MOCK_CONST_METHOD0(get_message_type, std::string());
  MOCK_CONST_METHOD0(get_subscriber_function, InMemoryBus::Common::SubscriberFunction());
  MOCK_METHOD0(try_lock, bool());
  MOCK_METHOD0(unlock, void());
};

}

#endif /* SRC_INMEMORYBUS_MOCKS_MOCKISUBSCRIBERINFORMATIONENTITY_H_ */
