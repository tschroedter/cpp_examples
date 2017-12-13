/*
 * FailedMessageBusNotifier.h
 *
 *  Created on: 12 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDMESSAGEBUSNOTIFIER_H_
#define SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDMESSAGEBUSNOTIFIER_H_

#include "ThreadSafe/IThreadSafeFailedToNotifyQueue.h"
#include "IFailedMessageBusNotifier.h"
#include "../ISubscriberFunctionCaller.h"
#include "../../Common/ILogger.h"
#include "../../Common/MessageBusSynchronization.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class FailedMessageBusNotifier : public IFailedMessageBusNotifier {
 public:
  FailedMessageBusNotifier(ILogger_SPtr logger,
                           MessageBusSynchronization_SPtr synchronization,
                           IThreadSafeFailedToNotifyQueue_SPtr queue,
                           ISubscriberFunctionCaller_SPtr caller);
  virtual ~FailedMessageBusNotifier() = default;

  void operator()() override {
      notify();
  }

  void notify() override;

 private:
  ILogger_SPtr m_logger = nullptr;
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
