/*
 * FailedToNotifyManager.h
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFYMANAGER_H_
#define INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFYMANAGER_H_

#include <thread>
#include "IFailedToNotifyManager.h"
#include "ThreadSafe/IThreadSafeFailedToNotifyQueue.h"
#include "../../Common/ILogger.h"
#include "../../Common/MessageBusSynchronization.h"
#include "IFailedSubscriberFunctionCaller.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class FailedToNotifyManager : public IFailedToNotifyManager {
 public:
  FailedToNotifyManager(ILogger_SPtr logger,
                        MessageBusSynchronization_SPtr synchronization,
                        IThreadSafeFailedToNotifyQueue_SPtr messages,
                        IFailedSubscriberFunctionCaller_SPtr caller);
  virtual ~FailedToNotifyManager();

  void handle_failed_notification(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message) override;

 private:
  ILogger_SPtr m_logger = nullptr;
  MessageBusSynchronization_SPtr m_synchronization = nullptr;
  IThreadSafeFailedToNotifyQueue_SPtr m_messages = nullptr;
  IFailedSubscriberFunctionCaller_SPtr m_caller = nullptr;

  std::thread m_thread;
};

}
}
}

#endif /* INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFYMANAGER_H_ */
