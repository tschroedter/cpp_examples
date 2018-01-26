/*
 * INewMessagesQueue.h
 *
 *  Created on: 28 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_COMMON_IMESSAGESQUEUE_H_
#define SRC_INMEMORYBUS_COMMON_IMESSAGESQUEUE_H_

#include <memory>
#include "BaseMessage.h"

namespace InMemoryBus {
namespace Common {

class IMessagesQueue {
 public:
  virtual ~IMessagesQueue() = default;

  virtual BaseMessage_SPtr dequeue() = 0;
  virtual void enqueue(BaseMessage_SPtr message) = 0;
  virtual size_t size() const = 0;
};

}
}

typedef std::shared_ptr<InMemoryBus::Common::IMessagesQueue> IMessagesQueue_SPtr;

#endif /* SRC_INMEMORYBUS_COMMON_IMESSAGESQUEUE_H_ */
