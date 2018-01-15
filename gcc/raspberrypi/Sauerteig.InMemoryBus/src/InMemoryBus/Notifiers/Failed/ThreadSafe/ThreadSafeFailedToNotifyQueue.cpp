/*
 * FailedToNotifyQueue.cpp
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#include "ThreadSafeFailedToNotifyQueue.h"
#include "../IFailedToNotifyQueue.h"
#include "../../../Exceptions/ArgumentInvalidException.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {
namespace ThreadSafe {

ThreadSafeFailedToNotifyQueue::ThreadSafeFailedToNotifyQueue(IFailedToNotifyQueue_SPtr queue)
    : m_queue(queue) {
  if (m_queue == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create ThreadSafeFailedToNotifyQueue because 'queue' is null!",
                                               "queue");
  }
}

void ThreadSafeFailedToNotifyQueue::enqueue(IFailedToNotify_SPtr failed) {
  std::lock_guard<std::recursive_mutex> lock(m_mutex);

  m_queue->enqueue(failed);

}

IFailedToNotify_SPtr ThreadSafeFailedToNotifyQueue::dequeue() {
  std::lock_guard<std::recursive_mutex> lock(m_mutex);

  auto entity = m_queue->dequeue();

  return (entity);
}

size_t ThreadSafeFailedToNotifyQueue::size() {
  std::lock_guard<std::recursive_mutex> lock(m_mutex);

  auto size = m_queue->size();

  return (size);
}

}
}
}
}
