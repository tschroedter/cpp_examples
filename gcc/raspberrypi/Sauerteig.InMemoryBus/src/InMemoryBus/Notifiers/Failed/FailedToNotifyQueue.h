/*
 * FailedToNotifyHandler.h
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFYQUEUE_H_
#define SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFYQUEUE_H_

#include <queue>
#include "IFailedToNotify.h"
#include "IFailedToNotifyQueue.h"

using namespace std;

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class FailedToNotifyQueue : public IFailedToNotifyQueue {
 public:
  FailedToNotifyQueue() = default;
  virtual ~FailedToNotifyQueue() = default;

  void enqueue(IFailedToNotify_SPtr failed) override;
  IFailedToNotify_SPtr dequeue() override;
  size_t size() override;

 private:
  queue<IFailedToNotify_SPtr> m_queue;
};

}
}
}

#endif /* SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFYQUEUE_H_ */
