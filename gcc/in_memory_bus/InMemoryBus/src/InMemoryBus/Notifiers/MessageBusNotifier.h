/*
 * MessageBusNotifier.h
 *
 *  Created on: 26 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORY_NOTIFIERS_MESSAGEBUSNOTIFIER_H_
#define SRC_INMEMORY_NOTIFIERS_MESSAGEBUSNOTIFIER_H_

#include "IMessageBusNotifier.h"
#include "ISubscibersNotifier.h"
#include "../Common/MessageBusSynchronization.h"
#include "../Common/IMessagesQueue.h"
#include "../Common/Interfaces/ILogger.h"
#include "../Common/Interfaces/IThreadInformationProvider.h"
#include "../Common/BaseMessage.h"
#include "../Subscribtions/ISubscribtionManager.h"

using namespace std;

namespace InMemoryBus {
namespace Notifiers {
class MessageBusNotifier : public IMessageBusNotifier {
 public:
  MessageBusNotifier(ILogger_SPtr logger,
                     IThreadInformationProvider_SPtr provider,
                     MessageBusSynchronization_SPtr synchronization,
                     IMessagesQueue_SPtr messages,
                     ISubscibersNotifier_SPtr notifier);
  virtual ~MessageBusNotifier() = default;

  void operator()() {
    string pid = m_provider->get_thread_process_id_as_string();
    m_logger->info("MessageBusNotifier PID: " + pid);

    notify();
  }

  void notify() override;

 protected:
  void process_next_message();

 private:
  ILogger_SPtr m_logger = nullptr;
  IThreadInformationProvider_SPtr m_provider = nullptr;
  MessageBusSynchronization_SPtr m_synchronization = nullptr;
  IMessagesQueue_SPtr m_messages = nullptr;
  ISubscibersNotifier_SPtr m_notifier = nullptr;

  void notify_all_subscribers_for_message(const ISubscriberInformationEntityVector_SPtr& infos,
                                          BaseMessage_SPtr message);
};
}
}

#endif /* SRC_INMEMORY_NOTIFIERS_MESSAGEBUSNOTIFIER_H_ */
