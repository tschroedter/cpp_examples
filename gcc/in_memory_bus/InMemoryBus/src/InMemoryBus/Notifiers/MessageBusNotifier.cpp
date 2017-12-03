/*
 * MessageBusNotifier.cpp
 *
 *  Created on: 26 Nov. 2017
 *      Author: tom
 */

#include "../Notifiers/MessageBusNotifier.h"

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
                                       ISubscribtionManager_SPtr manager)
    : m_synchronization(synchronization),
      m_messages(messages),
      m_manager(manager) {
  if (m_synchronization == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create MessageBusNotifier because 'm_synchronization' is null!",
                                               "m_synchronization");
  }

  if (m_messages == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create MessageBusNotifier because 'm_messages' is null!",
                                               "m_messages");
  }

  if (m_manager == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create MessageBusNotifier because 'm_manager' is null!",
                                               "m_manager");
  }
}

void MessageBusNotifier::notify_all_subscribers_for_message(BaseMessage_SPtr message) {
  if (message == nullptr) {
    return;
  }

  auto repository = m_manager->get_repository_for_message_type(message->getType());

  ISubscriberInformationEntityVector_SPtr infos = repository->get_all_subscribers();

  for (auto iter = infos->begin(); iter != infos->end(); iter++) {
    ISubscriberInformationEntity_SPtr info = (*iter);
    auto message_type = message->getType();
    if (message_type.compare(info->get_message_type()) != 0) {
      continue;
    }
    SubscriberFunction func = info->get_subscriber_function();
    func(message);
  }
}

void MessageBusNotifier::process_next_message() {
  if (m_messages->size() == 0) {
    return;
  }

  BaseMessage_SPtr message = m_messages->dequeue();

  notify_all_subscribers_for_message(message);
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
