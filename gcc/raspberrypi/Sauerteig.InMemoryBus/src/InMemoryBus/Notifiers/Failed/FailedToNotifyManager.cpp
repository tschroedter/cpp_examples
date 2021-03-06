/*
 * FailedToNotifyManager.cpp
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#include <memory>
#include <string>
#include "Common/Interfaces/ILogger.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../../Common/MessageBusSynchronization.h"
#include "FailedToNotifyManager.h"
#include "FailedMessageBusNotifier.h"
#include "ThreadSafe/IThreadSafeFailedToNotifyQueue.h"
#include "IFailedSubscriberFunctionCaller.h"
#include "FailedToNotify.h"

using namespace std;
using namespace Common::Exceptions;

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

FailedToNotifyManager::FailedToNotifyManager(ILogger_SPtr logger, MessageBusSynchronization_SPtr synchronization,
                                             IThreadSafeFailedToNotifyQueue_SPtr messages,
                                             IFailedSubscriberFunctionCaller_SPtr caller)
    : m_logger(logger),
      m_synchronization(synchronization),
      m_messages(messages),
      m_caller(caller) {
  if (m_logger == nullptr) {
    throw ArgumentInvalidException("Can't create FailedToNotifyManager because 'logger' is null!",
                                               "logger");
  }

  if (m_synchronization == nullptr) {
    throw ArgumentInvalidException("Can't create FailedToNotifyManager because 'synchronization' is null!",
                                               "synchronization");  // Todo testing
  }

  if (m_messages == nullptr) {
    throw ArgumentInvalidException("Can't create FailedToNotifyManager because 'queue' is null!", "queue");
  }

  if (m_caller == nullptr) {
    throw ArgumentInvalidException("Can't create FailedToNotifyManager because 'caller' is null!",
                                               "caller");
  }

  m_logger->set_prefix("FailedToNotifyManager");
}

void FailedToNotifyManager::handle_failed_notification(const ISubscriberInformationEntity_SPtr& info,
                                                       BaseMessage_SPtr& message) {

  auto failed = make_shared<Failed::FailedToNotify>(info, message);

  m_messages->enqueue(failed);

  m_synchronization->is_messages_avalable_failed_messages_processor = true;
  m_synchronization->messages_available_failed_messages_processor.notify_one();

  string text = "Failed to execute SubscriberFunction for message '" + message->getType() + "' and SubscriberId '"
      + info->get_subscriber_id() + "'! - Enqueued for retry!";

  m_logger->warn(text);
}

}
}
}
