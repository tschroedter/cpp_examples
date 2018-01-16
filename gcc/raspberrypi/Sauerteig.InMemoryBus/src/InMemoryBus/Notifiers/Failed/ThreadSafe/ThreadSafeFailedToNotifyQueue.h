/*
 * FailedToNotifyQueue.h
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_FAILED_THREADSAFE_THREADSAFEFAILEDTONOTIFYQUEUE_H_
#define INMEMORYBUS_NOTIFIERS_FAILED_THREADSAFE_THREADSAFEFAILEDTONOTIFYQUEUE_H_

#include <mutex>
#include "IThreadSafeFailedToNotifyQueue.h"
#include "../IFailedToNotifyQueue.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {
namespace ThreadSafe {

class ThreadSafeFailedToNotifyQueue : public IThreadSafeFailedToNotifyQueue {
 public:
  ThreadSafeFailedToNotifyQueue(IFailedToNotifyQueue_SPtr queue);
  virtual ~ThreadSafeFailedToNotifyQueue() = default;

  void enqueue(IFailedToNotify_SPtr failed) override;
  IFailedToNotify_SPtr dequeue() override;
  size_t size() override;

 private:
  IFailedToNotifyQueue_SPtr m_queue = nullptr;
  std::recursive_mutex m_mutex;
};

}
}
}
}

#endif /* INMEMORYBUS_NOTIFIERS_FAILED_THREADSAFE_THREADSAFEFAILEDTONOTIFYQUEUE_H_ */