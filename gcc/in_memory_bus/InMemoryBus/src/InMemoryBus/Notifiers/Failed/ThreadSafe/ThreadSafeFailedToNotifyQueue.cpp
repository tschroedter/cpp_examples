/*
 * FailedToNotifyQueue.cpp
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#include "ThreadSafeFailedToNotifyQueue.h"
#include "../../../Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../IFailedToNotifyQueue.h"

using namespace std;
using namespace Common::Exceptions;

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {
namespace ThreadSafe {

ThreadSafeFailedToNotifyQueue::ThreadSafeFailedToNotifyQueue(IFailedToNotifyQueue_SPtr queue)
    : m_queue(queue) {
  if (m_queue == nullptr) {
    throw ArgumentInvalidException("Can't create ThreadSafeFailedToNotifyQueue because 'queue' is null!",
                                               "queue");
  }
}

void ThreadSafeFailedToNotifyQueue::enqueue(IFailedToNotify_SPtr failed) {
  lock_guard<recursive_mutex> lock(m_mutex);

  m_queue->enqueue(failed);

}

IFailedToNotify_SPtr ThreadSafeFailedToNotifyQueue::dequeue() {
  lock_guard<recursive_mutex> lock(m_mutex);

  auto entity = m_queue->dequeue();

  return (entity);
}

size_t ThreadSafeFailedToNotifyQueue::size() {
  lock_guard<recursive_mutex> lock(m_mutex);

  auto size = m_queue->size();

  return (size);
}

}
}
}
}
