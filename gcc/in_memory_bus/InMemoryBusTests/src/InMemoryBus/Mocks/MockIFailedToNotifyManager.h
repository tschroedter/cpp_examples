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
#include "InMemoryBus/Notifiers/Failed/IFailedToNotify.h"

namespace InMemoryBusTests {
class MockIFailedToNotifyManager : public InMemoryBus::Notifiers::Failed::IFailedToNotifyManager {
 public:
  MOCK_METHOD1(enqueue, void(IFailedToNotify_SPtr failed));
};
}

#endif /* INMEMORYBUS_MOCKS_MOCKIFAILEDTONOTIFYMANAGER_H_ */
