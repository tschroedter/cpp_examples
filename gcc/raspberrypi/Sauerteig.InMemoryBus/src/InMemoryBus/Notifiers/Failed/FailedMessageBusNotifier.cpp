/*
 * FailedMessageBusNotifier.cpp
 *
 *  Created on: 12 Dec. 2017
 *      Author: tom
 */

#include <thread>
#include <chrono>
#include "Common/Interfaces/ILogger.h"
#include "Common/Interfaces/IThreadInformationProvider.h"
#include "FailedMessageBusNotifier.h"
#include "ThreadSafe/IThreadSafeFailedToNotifyQueue.h"
#include "../ISubscriberFunctionCaller.h"
#include "../../Exceptions/ArgumentInvalidException.h"
#include "../../Common/MessageBusSynchronization.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

#define MAX_NUMBER_OF_RETRIES 3

FailedMessageBusNotifier::FailedMessageBusNotifier(ILogger_SPtr logger, IThreadInformationProvider_SPtr provider,
                                                   MessageBusSynchronization_SPtr synchronization,
                                                   IThreadSafeFailedToNotifyQueue_SPtr queue,
                                                   ISubscriberFunctionCaller_SPtr caller)  // Todo testing
    : m_logger(logger),
      m_provider(provider),
      m_synchronization(synchronization),
      m_messages(queue),
      m_caller(caller) {
  if (m_logger == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create FailedMessageBusNotifier because 'logger' is null!",
                                               "logger");
  }

  if (m_provider == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create FailedMessageBusNotifier because 'provider' is null!",
                                               "provider");
  }

  if (m_synchronization == nullptr) {
    throw Exceptions::ArgumentInvalidException(
        "Can't create FailedMessageBusNotifier because 'synchronization' is null!", "synchronization");
  }

  if (m_messages == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create FailedMessageBusNotifier because 'messages' is null!",
                                               "messages");
  }

  if (m_caller == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create FailedMessageBusNotifier because 'caller' is null!",
                                               "caller");
  }

  m_logger->set_prefix("FailedMessageBusNotifier");
}

void FailedMessageBusNotifier::handle_failed_message(IFailedToNotify_SPtr failed) {
  ISubscriberInformationEntity_SPtr information = failed->get_information();
  BaseMessage_SPtr message = failed->get_message();

  bool result = m_caller->try_call_subscriber_function(information, message);

  if (!result) {
    failed->increase_number_of_tries();

    int tries = failed->get_number_of_tries();

    if (tries < MAX_NUMBER_OF_RETRIES) {
      m_messages->enqueue(failed);
    } else {
      std::string text = "Failed to execute SubscriberFunction for message '" + failed->get_message()->getType()
          + "' and SubscriberId '" + failed->get_information()->get_subscriber_id()
          + "'! - Giving up! Message deleted!";
      m_logger->error(text);
    }
  }
}

void FailedMessageBusNotifier::proccess_failed_messages() {
  size_t size = m_messages->size();

  for (size_t i = 0; i < size; i++) {
    auto failed = m_messages->dequeue();
    handle_failed_message(failed);
  }
}

void FailedMessageBusNotifier::trigger_reprocessing_if_queue_is_not_empty() {
  if (m_messages->size() > 0) {
    m_synchronization->is_messages_avalable_failed_messages_processor = true;
    m_synchronization->messages_available_failed_messages_processor.notify_one();
  } else {
    m_synchronization->is_messages_avalable_failed_messages_processor = false;
  }
}

void FailedMessageBusNotifier::notify() {
  while (!m_synchronization->is_stop_requested_failed_messages_processor.load()) {
    std::unique_lock<std::mutex> lock(m_synchronization->mutex_failed_messages_processor);

    m_synchronization->messages_available_failed_messages_processor.wait(
        lock,
        std::bind(&Common::MessageBusSynchronization::is_messages_avalable_failed_messages_processor,
                  m_synchronization));

    proccess_failed_messages();

    trigger_reprocessing_if_queue_is_not_empty();
  }
}

}
}
}
