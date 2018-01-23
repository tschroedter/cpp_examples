/*
 * FailedMessageBusNotifier.h
 *
 *  Created on: 12 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDMESSAGEBUSNOTIFIER_H_
#define SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDMESSAGEBUSNOTIFIER_H_

#include "Common/Interfaces/ILogger.h"
#include "Common/Interfaces/IThreadInformationProvider.h"
#include "ThreadSafe/IThreadSafeFailedToNotifyQueue.h"
#include "IFailedMessageBusNotifier.h"
#include "../ISubscriberFunctionCaller.h"
#include "../../Common/MessageBusSynchronization.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class FailedMessageBusNotifier : public IFailedMessageBusNotifier {
 public:
  FailedMessageBusNotifier(ILogger_SPtr logger,
                           IThreadInformationProvider_SPtr provider,
                           MessageBusSynchronization_SPtr synchronization,
                           IThreadSafeFailedToNotifyQueue_SPtr queue,
                           ISubscriberFunctionCaller_SPtr caller);
  virtual ~FailedMessageBusNotifier() = default;

  void operator()() override {
    std::string pid = m_provider->get_thread_process_id_as_string();
    m_logger->info("FailedMessageBusNotifier PID: " + pid);

    notify();
  }

  void notify() override;

 private:
  ILogger_SPtr m_logger = nullptr;
  IThreadInformationProvider_SPtr m_provider = nullptr;
  MessageBusSynchronization_SPtr m_synchronization = nullptr;
  IThreadSafeFailedToNotifyQueue_SPtr m_messages = nullptr;
  ISubscriberFunctionCaller_SPtr m_caller = nullptr;

  void handle_failed_message(IFailedToNotify_SPtr failed);
  void proccess_failed_messages();
  void trigger_reprocessing_if_queue_is_not_empty();
};

}
}
}

#endif /* SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDMESSAGEBUSNOTIFIER_H_ */
