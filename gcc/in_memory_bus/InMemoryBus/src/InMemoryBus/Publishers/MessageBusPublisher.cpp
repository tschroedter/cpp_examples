/*
 * MessageBusPublisher.cpp
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */
#include <mutex>
#include "MessageBusPublisher.h"
#include "../Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../Common/MessageBusSynchronization.h"
#include "../Common/BaseMessage.h"
#include "../Common/IMessagesQueue.h"
#include "../Common/SubscriberFunction.h"

using namespace Common::Exceptions;

namespace InMemoryBus {
namespace Publishers {
MessageBusPublisher::MessageBusPublisher(MessageBusSynchronization_SPtr synchronization, IMessagesQueue_SPtr messages)
    : m_synchronization(synchronization),
      m_messages(messages) {
  if (m_synchronization == nullptr) {
    throw ArgumentInvalidException("Can't create MessageBusPublisher because 'synchronization' is null!",
                                               "synchronization");
  }

  if (m_messages == nullptr) {
    throw ArgumentInvalidException("Can't create MessageBusPublisher because 'messages' is null!",
                                               "messages");
  }
}

void MessageBusPublisher::publish(BaseMessage_SPtr message) {
  std::lock_guard<std::mutex> guard(m_synchronization->mutex_thread_pool);

  m_messages->enqueue(message);

  m_synchronization->is_messages_avalable_for_thread_pool = true;

  m_synchronization->messages_available.notify_one();
}
}
}
