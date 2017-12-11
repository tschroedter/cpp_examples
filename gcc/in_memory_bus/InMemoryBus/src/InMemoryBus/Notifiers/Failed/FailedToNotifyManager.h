/*
 * FailedToNotifyManager.h
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFYMANAGER_H_
#define INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFYMANAGER_H_

#include "IFailedToNotifyManager.h"
#include "ThreadSafe/IThreadSafeFailedToNotifyQueue.h"
#include "../../Common/ILogger.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class FailedToNotifyManager : public IFailedToNotifyManager {
 public:
  FailedToNotifyManager(ILogger_SPtr logger, IThreadSafeFailedToNotifyQueue_SPtr queue);
  virtual ~FailedToNotifyManager() = default;

  void handle_failed_notification(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message) override;

 private:
  ILogger_SPtr m_logger = nullptr;
  IThreadSafeFailedToNotifyQueue_SPtr m_queue = nullptr;
};

}
}
}

#endif /* INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFYMANAGER_H_ */
