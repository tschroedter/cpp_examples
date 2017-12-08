/*
 * MockIFailedToNotifyManager.h
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_MOCKS_MOCKIFAILEDTONOTIFYMANAGER_H_
#define INMEMORYBUS_MOCKS_MOCKIFAILEDTONOTIFYMANAGER_H_

#include <gtest/gtest.h>
#include "InMemoryBus/Notifiers/Failed/IFailedToNotifyManager.h"
#include "InMemoryBus/Common/BaseMessage.h"
#include "InMemoryBus/Subscribtions/Subscribers/ISubscriberInformationEntity.h"

namespace InMemoryBusTests {
class MockIFailedToNotifyManager : public InMemoryBus::Notifiers::Failed::IFailedToNotifyManager {
 public:
  MOCK_METHOD2(handle_failed_notification, void(const ISubscriberInformationEntity_SPtr& info,
          BaseMessage_SPtr& message));
};
}

#endif /* INMEMORYBUS_MOCKS_MOCKIFAILEDTONOTIFYMANAGER_H_ */
