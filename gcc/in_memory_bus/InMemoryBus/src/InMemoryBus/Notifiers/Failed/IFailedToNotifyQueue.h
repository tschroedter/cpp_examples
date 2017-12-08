/*
 * IFailedToNotifyHandler.h
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDTONOTIFYQUEUE_H_
#define INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDTONOTIFYQUEUE_H_

#include <memory>
#include "IFailedToNotify.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class IFailedToNotifyQueue {
 public:
  virtual ~IFailedToNotifyQueue() = default;

  virtual void enqueue(IFailedToNotify_SPtr failed) = 0;
  virtual IFailedToNotify_SPtr dequeue() = 0;
  virtual size_t size() = 0;
};

}
}
}

typedef std::shared_ptr<InMemoryBus::Notifiers::Failed::IFailedToNotifyQueue> IFailedToNotifyQueue_SPtr;

#endif /* INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDTONOTIFYQUEUE_H_ */
