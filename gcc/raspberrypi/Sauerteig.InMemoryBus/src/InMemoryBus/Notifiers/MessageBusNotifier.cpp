/*
 * MessageBusNotifier.cpp
 *
 *  Created on: 26 Nov. 2017
 *      Author: tom
 */

#include "../Notifiers/MessageBusNotifier.h"

#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <chrono>
#include <string>
#include <functional>
#include <condition_variable>
#include "Common/Interfaces/ILogger.h"
#include "Common/Interfaces/IThreadInformationProvider.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../Subscribtions/Subscribers/SubscriberInformationEntity.h"
#include "../Subscribtions/Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"
#include "../Common/SubscriberFunction.h"
#include "../Common/BaseMessage.h"
#include "../Common/MessageBusSynchronization.h"
#include "../Common/IMessagesQueue.h"
#include "../Subscribtions/ISubscribtionManager.h"

using namespace std;
using namespace Common::Exceptions;

namespace InMemoryBus {
namespace Notifiers {
MessageBusNotifier::MessageBusNotifier(ILogger_SPtr logger,
                                       IThreadInformationProvider_SPtr provider,
                                       MessageBusSynchronization_SPtr synchronization,
                                       IMessagesQueue_SPtr messages,
                                       ISubscibersNotifier_SPtr notifier)
    : m_logger(logger),
      m_provider(provider),
      m_synchronization(synchronization),
      m_messages(messages),
      m_notifier(notifier) {
  if (m_logger == nullptr) {
    throw ArgumentInvalidException("Can't create MessageBusNotifier because 'logger' is null!",
                                               "logger");
  }

  if (m_provider == nullptr) {
    throw ArgumentInvalidException("Can't create MessageBusNotifier because 'provider' is null!",
                                               "provider");
  }

  if (m_synchronization == nullptr) {
    throw ArgumentInvalidException("Can't create MessageBusNotifier because 'synchronization' is null!",
                                               "synchronization");
  }

  if (m_messages == nullptr) {
    throw ArgumentInvalidException("Can't create MessageBusNotifier because 'messages' is null!",
                                               "messages");
  }

  if (m_notifier == nullptr) {
    throw ArgumentInvalidException("Can't create MessageBusNotifier because 'notifier' is null!",
                                               "notifier");
  }

  m_logger->set_prefix("MessageBusNotifier");
}

void MessageBusNotifier::process_next_message() {
  if (m_messages->size() == 0) {
    m_synchronization->is_messages_avalable_for_thread_pool = false;
    return;
  }

  BaseMessage_SPtr message = m_messages->dequeue();

  m_notifier->notify_all_subscribers_for_message(message);
}

void MessageBusNotifier::notify() {
  while (!m_synchronization->is_stop_requested_for_thread_pool.load()) {
    unique_lock<mutex> lock(m_synchronization->mutex_thread_pool);

    m_synchronization->messages_available.wait(
        lock, bind(&Common::MessageBusSynchronization::is_messages_avalable_for_thread_pool, m_synchronization));

    process_next_message();
  }
}
}
}
