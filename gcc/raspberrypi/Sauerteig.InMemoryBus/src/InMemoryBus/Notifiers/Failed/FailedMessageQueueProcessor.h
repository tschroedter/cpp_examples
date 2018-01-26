/*
 * FailedMessageQueueProcessor.h
 *
 *  Created on: 12 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDMESSAGEQUEUEPROCESSOR_H_
#define SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDMESSAGEQUEUEPROCESSOR_H_

#include <thread>
#include "Common/Interfaces/ILogger.h"
#include "../../Common/MessageBusSynchronization.h"
#include "FailedMessageBusNotifier.h"
#include "IFailedMessageQueueProcessor.h"

using namespace std;

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class FailedMessageQueueProcessor : public IFailedMessageQueueProcessor {  // ToDo testing
 public:
  FailedMessageQueueProcessor(ILogger_SPtr logger, MessageBusSynchronization_SPtr synchronization,
                              IFailedMessageBusNotifier_SPtr notifier);
  virtual ~FailedMessageQueueProcessor() = default;

  void initialize() override;
  void stop() override;

 private:
  ILogger_SPtr m_logger = nullptr;
  MessageBusSynchronization_SPtr m_synchronization = nullptr;
  IFailedMessageBusNotifier_SPtr m_notifier = nullptr;

  thread m_thread;
};

}
}
}

#endif /* SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDMESSAGEQUEUEPROCESSOR_H_ */
