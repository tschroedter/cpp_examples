/*
 * MessageBusNotifier.h
 *
 *  Created on: 26 Nov. 2017
 *      Author: tom
 */

#ifndef INMEMORY_NOTIFIERS_MESSAGEBUSNOTIFIER_H_
#define INMEMORY_NOTIFIERS_MESSAGEBUSNOTIFIER_H_

#include "IMessageBusNotifier.h"
#include "../MessageBusSynchronization.h"
#include "../IMessagesQueue.h"
#include "../Subscribtions/ISubscribtionManager.h"
#include "../BaseMessage.h"

namespace InMemoryBus {
namespace Notifiers {
class MessageBusNotifier : public IMessageBusNotifier {
 public:
  MessageBusNotifier(MessageBusSynchronization_SPtr synchronization, IMessagesQueue_SPtr messages,
                     ISubscribtionManager_SPtr manager);
  virtual ~MessageBusNotifier() = default;

  void operator()() {
    notify();
  }

  void notify();

 private:
  MessageBusSynchronization_SPtr m_synchronization = nullptr;
  IMessagesQueue_SPtr m_messages = nullptr;
  ISubscribtionManager_SPtr m_manager = nullptr;

  void process_next_message();
  void notify_all_subscribers_for_message(BaseMessage* p_message);
};
}
}

#endif /* INMEMORY_NOTIFIERS_MESSAGEBUSNOTIFIER_H_ */
