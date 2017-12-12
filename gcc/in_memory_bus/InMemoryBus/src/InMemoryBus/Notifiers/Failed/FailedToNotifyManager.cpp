/*
 * FailedToNotifyManager.cpp
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#include <memory>
#include <string>
#include <thread>
#include "FailedToNotifyManager.h"
#include "FailedMessageBusNotifier.h"
#include "ThreadSafe/IThreadSafeFailedToNotifyQueue.h"
#include "../../Exceptions/ArgumentInvalidException.h"
#include "../../Common/ILogger.h"
#include "../../Common/MessageBusSynchronization.h"
#include "IFailedSubscriberFunctionCaller.h"
#include "FailedToNotify.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

FailedToNotifyManager::FailedToNotifyManager(
    ILogger_SPtr logger,
    MessageBusSynchronization_SPtr synchronization,
    IThreadSafeFailedToNotifyQueue_SPtr messages,
    IFailedSubscriberFunctionCaller_SPtr caller)
    : m_logger(logger),
      m_synchronization(synchronization),
      m_messages(messages),
      m_caller(caller) {
  if (m_logger == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create FailedToNotifyManager because 'logger' is null!",
                                               "logger");
  }

  if (m_messages == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create FailedToNotifyManager because 'synchronization' is null!", "synchronization");
  }

  if (m_messages == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create FailedToNotifyManager because 'queue' is null!", "queue");
  }

  if (m_caller == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create FailedToNotifyManager because 'caller' is null!", "caller");
  }

  m_logger->set_prefix("FailedToNotifyManager");

  auto notifier = std::make_shared<FailedMessageBusNotifier>(m_logger, m_synchronization, m_messages, m_caller);  // TODO use container to create notifiers

  m_thread = std::thread([notifier]() {(*notifier)();});
}

FailedToNotifyManager::~FailedToNotifyManager() {
  m_thread.join();
}

void FailedToNotifyManager::handle_failed_notification(const ISubscriberInformationEntity_SPtr& info,
                                                       BaseMessage_SPtr& message) {

  auto failed = make_shared<Failed::FailedToNotify>(info, message);

  m_messages->enqueue(failed);

  std::string text = "[FailedToNotifyManager::enqueue] Failed to execute SubscriberFunction for message '"
      + failed->get_message()->getType() + "' and SubscriberId '" + failed->get_information()->get_subscriber_id()
      + "'! - Enqueued for retry!";

  m_logger->warn(text);
}

}
}
}
