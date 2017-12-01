/*
 * NewMessagesQueue.cpp
 *
 *  Created on: 28 Nov. 2017
 *      Author: tom
 */

#include "MessagesQueue.h"
#include "BaseMessage.h"

namespace InMemoryBus {

BaseMessage* MessagesQueue::front() {
  BaseMessage* message = m_queue.front();

  return (message);
}

void MessagesQueue::pop()

{
  m_queue.pop();
}

void MessagesQueue::push(BaseMessage* message) {
  m_queue.push(message);
}

size_t MessagesQueue::size() const {
  return (m_queue.size());
}

} /* namespace InMemoryBus */
