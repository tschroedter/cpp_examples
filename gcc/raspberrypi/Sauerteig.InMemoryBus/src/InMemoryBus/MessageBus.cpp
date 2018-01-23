/*
 * MessageBus.cpp
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#include "MessageBus.h"
#include "Common/SubscriberFunction.h"
#include "Common/BaseMessage.h"
#include "Exceptions/ArgumentInvalidException.h"
#include "Subscribtions/ISubscribtionManager.h"

using namespace std;

namespace InMemoryBus {

MessageBus::MessageBus(IMessageBusPublisher_SPtr publisher, ISubscribtionManager_SPtr manager)
    : m_publisher(publisher),
      m_manager(manager) {
  if (m_publisher == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create MessageBus because 'publisher' is null!", "publisher");
  }

  if (m_manager == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create MessageBus because 'manager' is null!", "manager");
  }
}

void MessageBus::subscribe(string subscriber_id, string message_type,
                           Common::SubscriberFunction messageReceiver) {
  m_manager->add_subscription(subscriber_id, message_type, messageReceiver);
}

void MessageBus::unsubscribe(string subscriber_id, string message_type) {
  m_manager->remove_subscription(subscriber_id, message_type);
}

void MessageBus::publish(BaseMessage_SPtr message) {
  m_publisher->publish(message);
}

}
