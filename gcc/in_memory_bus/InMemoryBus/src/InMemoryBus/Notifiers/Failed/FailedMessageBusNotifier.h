/*
 * FailedMessageBusNotifier.h
 *
 *  Created on: 12 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDMESSAGEBUSNOTIFIER_H_
#define SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDMESSAGEBUSNOTIFIER_H_

#include "IFailedToNotifyQueue.h"
#include "IFailedMessageBusNotifier.h"
#include "../ISubscriberFunctionCaller.h"
#include "../../Common/ILogger.h"
#include "../../Common/MessageBusSynchronization.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class FailedMessageBusNotifier : IFailedMessageBusNotifier {
 public:
  FailedMessageBusNotifier(ILogger_SPtr logger,
                           MessageBusSynchronization_SPtr synchronization,
                           IFailedToNotifyQueue_SPtr queue,
                           ISubscriberFunctionCaller_SPtr caller);
  virtual ~FailedMessageBusNotifier() = default;

  void operator()() override {
      notify();
  }

  void notify() override;

 private:
  ILogger_SPtr m_logger = nullptr;
  MessageBusSynchronization_SPtr m_synchronization = nullptr;
  IFailedToNotifyQueue_SPtr m_messages = nullptr;
  ISubscriberFunctionCaller_SPtr m_caller = nullptr;

  void handle_failed_message(IFailedToNotify_SPtr failed);
};

}
}
}

#endif /* SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDMESSAGEBUSNOTIFIER_H_ */
