/*
 * MockISubscibersNotifier.h
 *
 *  Created on: 6 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_MOCKISUBSCIBERSNOTIFIER_H_
#define INMEMORYBUS_MOCKISUBSCIBERSNOTIFIER_H_

#include <gmock/gmock.h>
#include "InMemoryBus/BaseMessage.h"
#include "InMemoryBus/Notifiers/ISubscibersNotifier.h"

namespace InMemoryBusTests {

class MockISubscibersNotifier : public InMemoryBus::Notifiers::ISubscibersNotifier {
 public:
  MOCK_METHOD1(notify_all_subscribers_for_message, void(BaseMessage_SPtr message));};

}

#endif /* INMEMORYBUS_MOCKISUBSCIBERSNOTIFIER_H_ */
