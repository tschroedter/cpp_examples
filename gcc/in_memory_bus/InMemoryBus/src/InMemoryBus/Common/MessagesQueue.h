/*
 * NewMessagesQueue.h
 *
 *  Created on: 28 Nov. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_COMMON_MESSAGESQUEUE_H_
#define INMEMORYBUS_COMMON_MESSAGESQUEUE_H_

#include <queue>
#include "concurrentqueue.h"
#include "BaseMessage.h"
#include "IMessagesQueue.h"

namespace InMemoryBus {
namespace Common {

class MessagesQueue : public IMessagesQueue {
 public:
  MessagesQueue() = default;
  virtual ~MessagesQueue() = default;

  BaseMessage_SPtr dequeue() override;
  void enqueue(BaseMessage_SPtr message) override;
  size_t size() const override;

 private:
  moodycamel::ConcurrentQueue<BaseMessage_SPtr> m_queue;
};

}
}

#endif /* INMEMORYBUS_MESSAGESQUEUE_H_ */
