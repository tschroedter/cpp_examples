/*
 * IThreadSafeFailedToNotifyQueue.h
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_NOTIFIERS_FAILED_THREADSAFE_ITHREADSAFEFAILEDTONOTIFYQUEUE_H_
#define SRC_INMEMORYBUS_NOTIFIERS_FAILED_THREADSAFE_ITHREADSAFEFAILEDTONOTIFYQUEUE_H_

#include <memory>
#include "../IFailedToNotifyQueue.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {
namespace ThreadSafe {

class IThreadSafeFailedToNotifyQueue : public IFailedToNotifyQueue {
 public:
  virtual ~IThreadSafeFailedToNotifyQueue() = default;
};

}
}
}
}

typedef std::shared_ptr<InMemoryBus::Notifiers::Failed::ThreadSafe::IThreadSafeFailedToNotifyQueue> IThreadSafeFailedToNotifyQueue_SPtr;

#endif /* SRC_INMEMORYBUS_NOTIFIERS_FAILED_THREADSAFE_ITHREADSAFEFAILEDTONOTIFYQUEUE_H_ */
