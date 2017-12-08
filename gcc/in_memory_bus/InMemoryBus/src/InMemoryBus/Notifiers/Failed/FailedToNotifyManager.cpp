/*
 * FailedToNotifyManager.cpp
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#include "FailedToNotifyManager.h"
#include "IFailedToNotifyQueue.h"
#include "../../Exceptions/ArgumentInvalidException.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

// TODO singelton? lockin required?
FailedToNotifyManager::FailedToNotifyManager(IFailedToNotifyQueue_SPtr queue)
    : m_queue(queue) {
  if (m_queue == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create FailedToNotifyManager because 'queue' is null!", "queue");
  }
}

void FailedToNotifyManager::enqueue(IFailedToNotify_SPtr failed) {
  m_queue->enqueue(failed);

  cout << "[FailedToNotifyManager::enqueue] Failed to execute SubscriberFunction for message '"
       << failed->get_message()->getType() << "' and SubscriberId '" << failed->get_information()->get_subscriber_id()
       << "'!" << endl;

  //auto failed = std::make_shared<FailedToNotify>(info, message);
  //cout << "Created FTN: " << failed->get_message()->getType() << endl;
  // TODO store message and retry => store in new class info + message ==> have separate thread trying to deliver failed messages
}

}
}
}
