/*
 * FailedToNotifyManager.cpp
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#include <memory>
#include "FailedToNotifyManager.h"
#include "ThreadSafe/IThreadSafeFailedToNotifyQueue.h"
#include "../../Exceptions/ArgumentInvalidException.h"
#include "FailedToNotify.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

// TODO testing, process failed messages
FailedToNotifyManager::FailedToNotifyManager(IThreadSafeFailedToNotifyQueue_SPtr queue)
    : m_queue(queue) {
  if (m_queue == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create FailedToNotifyManager because 'queue' is null!", "queue");
  }
}

void FailedToNotifyManager::handle_failed_notification(const ISubscriberInformationEntity_SPtr& info,
                                                       BaseMessage_SPtr& message) {

  auto failed = make_shared<Failed::FailedToNotify>(info, message);

  m_queue->enqueue(failed);

  cout << "[FailedToNotifyManager::enqueue] Failed to execute SubscriberFunction for message '"
       << failed->get_message()->getType() << "' and SubscriberId '" << failed->get_information()->get_subscriber_id()
       << "'!" << endl;

  // TODO have separate thread trying to deliver failed messages
}

}
}
}
