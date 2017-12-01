/*
 * INewMessagesQueue.h
 *
 *  Created on: 28 Nov. 2017
 *      Author: tom
 */

#ifndef IMESSAGESQUEUE_H_
#define IMESSAGESQUEUE_H_

#include <memory>
#include "BaseMessage.h"

namespace InMemoryBus {

class IMessagesQueue {
 public:
  virtual ~IMessagesQueue() = default;

  virtual BaseMessage* front() = 0;
  virtual void pop() = 0;
  virtual void push(BaseMessage* message) = 0;
  virtual size_t size() const = 0;
};

} /* namespace InMemoryBus */

typedef std::shared_ptr<InMemoryBus::IMessagesQueue> IMessagesQueue_SPtr;

#endif /* IMESSAGESQUEUE_H_ */
