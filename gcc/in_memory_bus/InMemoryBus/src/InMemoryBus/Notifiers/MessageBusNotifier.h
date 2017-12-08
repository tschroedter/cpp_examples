/*
 * MessageBusNotifier.h
 *
 *  Created on: 26 Nov. 2017
 *      Author: tom
 */

#ifndef INMEMORY_NOTIFIERS_MESSAGEBUSNOTIFIER_H_
#define INMEMORY_NOTIFIERS_MESSAGEBUSNOTIFIER_H_

#include "IMessageBusNotifier.h"
#include "ISubscibersNotifier.h"
#include "../MessageBusSynchronization.h"
#include "../IMessagesQueue.h"
#include "../Subscribtions/ISubscribtionManager.h"
#include "../BaseMessage.h"

namespace InMemoryBus {
namespace Notifiers {
class MessageBusNotifier : public IMessageBusNotifier {
 public:
  MessageBusNotifier(MessageBusSynchronization_SPtr synchronization, IMessagesQueue_SPtr messages,
                     ISubscibersNotifier_SPtr notifier);
  virtual ~MessageBusNotifier() = default;

  void operator()() {
    notify();
  }

  void notify() override;

 protected:
  void process_next_message();

 private:
  MessageBusSynchronization_SPtr m_synchronization = nullptr;
  IMessagesQueue_SPtr m_messages = nullptr;
  ISubscibersNotifier_SPtr m_notifier = nullptr;

  void notify_all_subscribers_for_message(const ISubscriberInformationEntityVector_SPtr& infos,
                                          BaseMessage_SPtr message);
};
}
}

#endif /* INMEMORY_NOTIFIERS_MESSAGEBUSNOTIFIER_H_ */
