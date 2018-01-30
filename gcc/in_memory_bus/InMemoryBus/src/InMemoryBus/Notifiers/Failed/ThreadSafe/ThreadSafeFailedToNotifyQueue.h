/*
 * FailedToNotifyQueue.h
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_NOTIFIERS_FAILED_THREADSAFE_THREADSAFEFAILEDTONOTIFYQUEUE_H_
#define SRC_INMEMORYBUS_NOTIFIERS_FAILED_THREADSAFE_THREADSAFEFAILEDTONOTIFYQUEUE_H_

#include <mutex>
#include "IThreadSafeFailedToNotifyQueue.h"
#include "../IFailedToNotifyQueue.h"

using namespace std;

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
  recursive_mutex m_mutex;
};

}
}
}
}

#endif /* SRC_INMEMORYBUS_NOTIFIERS_FAILED_THREADSAFE_THREADSAFEFAILEDTONOTIFYQUEUE_H_ */
