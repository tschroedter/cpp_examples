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
#include "../Exceptions/ArgumentInvalidException.h"
#include "../Subscribtions/Subscribers/SubscriberInformationEntity.h"
#include "../Subscribtions/Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"
#include "../Typedefs.h"
#include "../BaseMessage.h"
#include "../MessageBusSynchronization.h"
#include "../IMessagesQueue.h"
#include "../Subscribtions/ISubscribtionManager.h"

namespace InMemoryBus {
namespace Notifiers {
MessageBusNotifier::MessageBusNotifier(MessageBusSynchronization_SPtr synchronization, IMessagesQueue_SPtr messages,
                                       ISubscibersNotifier_SPtr notifier)
    : m_synchronization(synchronization),
      m_messages(messages),
      m_notifier(notifier) {
  if (m_synchronization == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create MessageBusNotifier because 'synchronization' is null!",
                                               "synchronization");
  }

  if (m_messages == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create MessageBusNotifier because 'messages' is null!",
                                               "messages");
  }

  if (m_notifier == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create MessageBusNotifier because 'notifier' is null!",
                                               "notifier");
  }
}

void MessageBusNotifier::process_next_message() {
  if (m_messages->size() == 0) {
    return;
  }

  BaseMessage_SPtr message = m_messages->dequeue();

  m_notifier->notify_all_subscribers_for_message(message);
}

void MessageBusNotifier::notify() {
  while (!m_synchronization->is_stop_requested.load()) {
    std::unique_lock<std::mutex> lock(m_synchronization->mutex);

    m_synchronization->messages_available.wait(
        lock, std::bind(&MessageBusSynchronization::is_messages_avalable, m_synchronization));

    process_next_message();
  }
}
}
}
