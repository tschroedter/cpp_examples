/*
 * MockIFailedToNotify.h
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_MOCKS_MOCKIFAILEDTONOTIFY_H_
#define INMEMORYBUS_MOCKS_MOCKIFAILEDTONOTIFY_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "InMemoryBus/Notifiers/Failed/IFailedToNotify.h"

namespace InMemoryBusTests {
class MockIFailedToNotify : public InMemoryBus::Notifiers::Failed::IFailedToNotify {
 public:
  MOCK_METHOD0(get_information, ISubscriberInformationEntity_SPtr());
  MOCK_METHOD0(get_message, BaseMessage_SPtr());
  MOCK_CONST_METHOD0(get_number_of_tries, int());
  MOCK_METHOD0(increase_number_of_tries, void());
};
}

#endif /* INMEMORYBUS_MOCKS_MOCKIFAILEDTONOTIFY_H_ */
