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
  m_mutex.lock();

  m_queue->enqueue(failed);

  m_mutex.unlock();
}

IFailedToNotify_SPtr ThreadSafeFailedToNotifyQueue::dequeue() {
  m_mutex.lock();

  auto entity = m_queue->dequeue();

  m_mutex.unlock();

  return (entity);
}

size_t ThreadSafeFailedToNotifyQueue::size() {
  m_mutex.lock();

  auto size = m_queue->size();

  m_mutex.unlock();

  return (size);
}

}
}
}
}
