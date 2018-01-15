/*
 * MessageBusPublisher.cpp
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */
#include <mutex>
#include "MessageBusPublisher.h"
#include "../Common/MessageBusSynchronization.h"
#include "../Common/BaseMessage.h"
#include "../Common/IMessagesQueue.h"
#include "../Common/SubscriberFunction.h"
#include "../Exceptions/ArgumentInvalidException.h"

namespace InMemoryBus {
namespace Publishers {
MessageBusPublisher::MessageBusPublisher(MessageBusSynchronization_SPtr synchronization, IMessagesQueue_SPtr messages)
    : m_synchronization(synchronization),
      m_messages(messages) {
  if (m_synchronization == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create MessageBusPublisher because 'synchronization' is null!",
                                               "synchronization");
  }

  if (m_messages == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create MessageBusPublisher because 'messages' is null!",
                                               "messages");
  }
}

void MessageBusPublisher::publish(BaseMessage_SPtr message) {
  std::lock_guard<std::mutex> guard(m_synchronization->mutex);

  m_messages->enqueue(message);

  m_synchronization->is_messages_avalable_for_thread_pool = true;

  m_synchronization->messages_available.notify_one();
}
}
}
