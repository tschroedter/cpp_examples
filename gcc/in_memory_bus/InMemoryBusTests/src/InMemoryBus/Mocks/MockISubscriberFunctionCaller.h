/*
 * MockISubscriberFunctionCaller.h
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_MOCKS_MOCKISUBSCRIBERFUNCTIONCALLER_H_
#define INMEMORYBUS_MOCKS_MOCKISUBSCRIBERFUNCTIONCALLER_H_

#include <string>
#include <gtest/gtest.h>
#include "InMemoryBus/Notifiers/ISubscriberFunctionCaller.h"

namespace InMemoryBusTests {

class MockISubscriberFunctionCaller : public InMemoryBus::Notifiers::ISubscriberFunctionCaller {
 public:
  MOCK_METHOD2(execute_subscriber_function, void(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message));
  MOCK_METHOD2(try_call_all_subscriber_function, bool(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr message));
  MOCK_METHOD2(call_all_subscriber_function, void(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message));
};

}

#endif /* INMEMORYBUS_MOCKS_MOCKISUBSCRIBERFUNCTIONCALLER_H_ */
