/*
 * MessageBus.cpp
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#include <thread>
#include <functional>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include "MessageBus.h"
#include "Exceptions/ArgumentInvalidException.h"
#include "Subscribtions/ISubscribtionManager.h"
#include "Subscribtions/Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"
#include "Common/SubscriberFunction.h"
#include "Publishers/MessageBusPublisher.h"
#include "Notifiers/MessageBusNotifier.h"
#include "Subscribtions/Subscribers/SubscriberInformationEntity.h"

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

void MessageBus::subscribe(std::string subscriber_id, std::string message_type,
                           Common::SubscriberFunction messageReceiver) {
  m_manager->add_subscription(subscriber_id, message_type, messageReceiver);
}

void MessageBus::unsubscribe(std::string subscriber_id, std::string message_type) {
  m_manager->remove_subscription(subscriber_id, message_type);
}

void MessageBus::publish(BaseMessage_SPtr message) {
  m_publisher->publish(message);
}

}