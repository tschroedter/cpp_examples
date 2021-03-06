/*
 * FailedMessageQueueProcessor.cpp
 *
 *  Created on: 12 Dec. 2017
 *      Author: tom
 */

#include <thread>
#include <chrono>
#include "FailedMessageQueueProcessor.h"
#include "IFailedMessageBusNotifier.h"
#include "../../Common/MessageBusSynchronization.h"
#include "../../Common/General.h"
#include "../../Common/Interfaces/ILogger.h"
#include "../../Common/Exceptions/ArgumentInvalidExceptions.h"

using namespace std;
using namespace Common::Exceptions;

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

FailedMessageQueueProcessor::FailedMessageQueueProcessor(ILogger_SPtr logger,
                                                         MessageBusSynchronization_SPtr synchronization,
                                                         IFailedMessageBusNotifier_SPtr notifier)
    : m_logger(logger),
      m_synchronization(synchronization),
      m_notifier(notifier) {
  if (m_logger == nullptr) {
    throw ArgumentInvalidException("Can't create FailedMessageQueueProcessor because 'logger' is null!",
                                               "logger");
  }

  if (m_synchronization == nullptr) {
    throw ArgumentInvalidException(
        "Can't create FailedMessageQueueProcessor because 'synchronization' is null!", "synchronization");
  }

  if (m_notifier == nullptr) {
    throw ArgumentInvalidException("Can't create FailedMessageQueueProcessor because 'notifier' is null!",
                                               "notifier");
  }

  m_synchronization->is_stop_requested_failed_messages_processor.store(false);

  m_logger->set_prefix("FailedMessageQueueProcessor");
}

void FailedMessageQueueProcessor::initialize() {
  m_thread = thread([this]() {(*this->m_notifier)();});

  string id = InMemoryBus::Common::thread_id_to_string(m_thread.get_id());

  m_logger->info(string("Failed notifier thread " + id + " created!"));
}

void FailedMessageQueueProcessor::stop() {
  m_synchronization->is_stop_requested_failed_messages_processor.store(true);
  m_synchronization->is_messages_avalable_failed_messages_processor = true;
  m_synchronization->messages_available_failed_messages_processor.notify_one();

  string id = InMemoryBus::Common::thread_id_to_string(m_thread.get_id());

  m_logger->info(string("Trying to join with failed notifier thread " + id + " ..."));

  if (m_thread.joinable()) {
    m_thread.join();
  }

  m_logger->info(string("...  failed notifier thread " + id + " joined!"));
}

}
}
}
