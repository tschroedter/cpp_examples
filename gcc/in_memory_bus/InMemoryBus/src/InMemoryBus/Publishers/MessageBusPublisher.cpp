/*
 * MessageBusPublisher.cpp
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */
#include <mutex>
#include "MessageBusPublisher.h"
#include "../MessageBusSynchronization.h"
#include "../BaseMessage.h"
#include "../Typedefs.h"
#include "../IMessagesQueue.h"
#include "../Exceptions/ArgumentInvalidException.h"

namespace InMemoryBus {
namespace Publishers {
MessageBusPublisher::MessageBusPublisher(MessageBusSynchronization_SPtr synchronization, IMessagesQueue_SPtr messages)
    : m_synchronization(synchronization),
      m_messages(messages) {
  if (m_synchronization == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create MessageBusPublisher because 'm_synchronization' is null!",
                                               "m_synchronization");
  }

  if (m_messages == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create MessageBusPublisher because 'm_messages' is null!",
                                               "m_messages");
  }
}

void MessageBusPublisher::publish(BaseMessage* p_message) {  // TODO use typedef shared_ptr
  std::lock_guard<std::mutex> guard(m_synchronization->mutex);

  m_messages->push(p_message);

  m_synchronization->is_messages_avalable = true;

  m_synchronization->messages_available.notify_one();
}
}
}
