/*
 * NewMessagesQueue.cpp
 *
 *  Created on: 28 Nov. 2017
 *      Author: tom
 */

#include "MessagesQueue.h"
#include "BaseMessage.h"

namespace InMemoryBus {
namespace Common {

BaseMessage_SPtr MessagesQueue::dequeue() {
  BaseMessage_SPtr message = nullptr;

  m_queue.try_dequeue(message);

  return (message);
}

void MessagesQueue::enqueue(BaseMessage_SPtr message) {
  m_queue.enqueue(message);
}

size_t MessagesQueue::size() const {
  return (m_queue.size_approx());
}

}
}
