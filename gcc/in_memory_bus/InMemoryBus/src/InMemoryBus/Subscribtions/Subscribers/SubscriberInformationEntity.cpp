/*
 * NewSubscriberInformation.cpp
 *
 *  Created on: 17Jun.,2017
 *      Author: tom
 */

#include <mutex>
#include "SubscriberInformationEntity.h"
#include "../../Exceptions/ArgumentInvalidException.h"

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
// todo use ApsectC++
SubscriberInformationEntity::SubscriberInformationEntity(const std::string subscriber_id,
                                                         const std::string message_type,
                                                         const SubscriberFunction subscriber_function)
    : m_subscriber_id(subscriber_id),
      m_message_type(message_type),
      m_subscriber_function(subscriber_function) {
  if (subscriber_id.empty()) {
    throw Exceptions::ArgumentInvalidException(
        "Can't create SubscriberInformationEntity because 'subscriber_id' is empty!", "subscriber_id");
  }

  if (message_type.empty()) {
    throw Exceptions::ArgumentInvalidException(
        "Can't create SubscriberInformationEntity because 'message_type' is empty!", "message_type");
  }

  if (subscriber_function == nullptr) {
    throw Exceptions::ArgumentInvalidException(
        "Can't create SubscriberInformationEntity because 'subscriber_function' is null!", "subscriber_function");
  }
}

bool operator<(const SubscriberInformationEntity& one, const SubscriberInformationEntity& two) {
  return (one.get_subscriber_id() < two.get_subscriber_id());
}

string SubscriberInformationEntity::get_subscriber_id() const {
  return (m_subscriber_id);
}

string SubscriberInformationEntity::get_message_type() const {
  return (m_message_type);
}
SubscriberFunction SubscriberInformationEntity::get_subscriber_function() const {
  return (m_subscriber_function);
}

bool SubscriberInformationEntity::try_lock() {
  return (m_mutex.try_lock());
}

void SubscriberInformationEntity::unlock() {
  m_mutex.unlock();
}

}
}
}
