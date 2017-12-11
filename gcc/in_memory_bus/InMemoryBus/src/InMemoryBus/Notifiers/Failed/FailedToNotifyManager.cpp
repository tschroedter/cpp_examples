/*
 * FailedToNotifyManager.cpp
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#include <memory>
#include <string>
#include "FailedToNotifyManager.h"
#include "ThreadSafe/IThreadSafeFailedToNotifyQueue.h"
#include "../../Exceptions/ArgumentInvalidException.h"
#include "../../Common/ILogger.h"
#include "FailedToNotify.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

// TODO testing, process failed messages
FailedToNotifyManager::FailedToNotifyManager(ILogger_SPtr logger, IThreadSafeFailedToNotifyQueue_SPtr queue)
    : m_logger(logger),
      m_queue(queue) {
  if (m_logger == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create FailedToNotifyManager because 'logger' is null!", "logger");
  }

  if (m_queue == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create FailedToNotifyManager because 'queue' is null!", "queue");
  }

  m_logger->set_prefix("FailedToNotifyManager");
}

void FailedToNotifyManager::handle_failed_notification(const ISubscriberInformationEntity_SPtr& info,
                                                       BaseMessage_SPtr& message) {

  auto failed = make_shared<Failed::FailedToNotify>(info, message);

  m_queue->enqueue(failed);

  std::string text =
      "[FailedToNotifyManager::enqueue] Failed to execute SubscriberFunction for message '"
       + failed->get_message()->getType()
       + "' and SubscriberId '"
       + failed->get_information()->get_subscriber_id()
       + "'!";

  m_logger->error(text);

  // TODO have separate thread trying to deliver failed messages
}

}
}
}
