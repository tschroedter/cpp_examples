/*
 * MockIFailedSubscriberFunctionCaller.h
 *
 *  Created on: 13 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_MOCKS_MOCKIFAILEDSUBSCRIBERFUNCTIONCALLER_H_
#define INMEMORYBUS_MOCKS_MOCKIFAILEDSUBSCRIBERFUNCTIONCALLER_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "InMemoryBus/Notifiers/Failed/IFailedSubscriberFunctionCaller.h"
#include "InMemoryBus/Common/BaseMessage.h"
#include "InMemoryBus/Subscribtions/Subscribers/ISubscriberInformationEntity.h"

namespace InMemoryBusTests {
class MockIFailedSubscriberFunctionCaller : public InMemoryBus::Notifiers::Failed::IFailedSubscriberFunctionCaller {
 public:
  MOCK_METHOD2(execute_subscriber_function, void(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message));
  MOCK_METHOD2(try_call_subscriber_function, bool(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message));
  MOCK_METHOD2(call_subscriber_function, void(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message));
};
}

#endif /* INMEMORYBUS_MOCKS_MOCKIFAILEDSUBSCRIBERFUNCTIONCALLER_H_ */
