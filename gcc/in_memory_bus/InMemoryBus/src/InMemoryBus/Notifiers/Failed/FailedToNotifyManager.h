/*
 * FailedToNotifyManager.h
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFYMANAGER_H_
#define INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFYMANAGER_H_

#include "IFailedToNotifyManager.h"
#include "IFailedToNotifyQueue.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class FailedToNotifyManager : public IFailedToNotifyManager {
 public:
  FailedToNotifyManager(IFailedToNotifyQueue_SPtr queue);
  virtual ~FailedToNotifyManager() = default;

  void enqueue(IFailedToNotify_SPtr failed) override;

 private:
  IFailedToNotifyQueue_SPtr m_queue = nullptr;
};

}
}
}

#endif /* INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFYMANAGER_H_ */
