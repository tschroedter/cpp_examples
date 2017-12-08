/*
 * TestMessageBusNotifier.h
 *
 *  Created on: 5 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_TESTMESSAGEBUSNOTIFIER_H_
#define INMEMORYBUS_NOTIFIERS_TESTMESSAGEBUSNOTIFIER_H_

#include "InMemoryBus/Notifiers/MessageBusNotifier.h"
#include "InMemoryBus/Notifiers/ISubscibersNotifier.h"
#include "InMemoryBus/Common/MessageBusSynchronization.h"
#include "InMemoryBus/Common/IMessagesQueue.h"

namespace InMemoryBusTests {

class TestMessageBusNotifier : public InMemoryBus::Notifiers::MessageBusNotifier {
 public:
  TestMessageBusNotifier(MessageBusSynchronization_SPtr synchronization, IMessagesQueue_SPtr messages,
                         ISubscibersNotifier_SPtr);
  virtual ~TestMessageBusNotifier() = default;

  void operator()() {
    notify();
  }

  void notify() override;

  void notify_all_subscribers_for_message(BaseMessage_SPtr message);
  void process_next_message();

};

}

#endif /* INMEMORYBUS_NOTIFIERS_TESTMESSAGEBUSNOTIFIER_H_ */
