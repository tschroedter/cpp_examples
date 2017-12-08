/*
 * MockISubscribtionManager.h
 *
 *  Created on: 3 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_MOCKISUBSCRIBTIONMANAGER_H_
#define INMEMORYBUS_MOCKISUBSCRIBTIONMANAGER_H_

#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "InMemoryBus/Common/SubscriberFunction.h"
#include "InMemoryBus/Subscribtions/ISubscribtionManager.h"

using namespace std;

namespace InMemoryBusTests {

class MockISubscribtionManager : public InMemoryBus::Subscribtions::ISubscribtionManager {
 public:
  MOCK_METHOD2(remove_subscription, void(string subscriber_id, string message_type));
  MOCK_METHOD3(add_subscription, void(string subscriber_id, string message_type, InMemoryBus::SubscriberFunction messageReceiver));
  MOCK_METHOD1(get_repository_for_message_type, IThreadSafeSubscriberInformationRepository_SPtr(const string& message_typ));
};

}

#endif /* INMEMORYBUS_MOCKISUBSCRIBTIONMANAGER_H_ */
