/*
 * FailedToNotifyHandler.cpp
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#include "FailedToNotifyQueue.h"
#include "IFailedToNotify.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

void FailedToNotifyQueue::enqueue(IFailedToNotify_SPtr failed) {
  m_queue.push(failed);
}

IFailedToNotify_SPtr FailedToNotifyQueue::dequeue() {
  auto front = m_queue.front();

  m_queue.pop();

  return (front);
}

size_t FailedToNotifyQueue::size() {
  return (m_queue.size());
}

}
}
}
