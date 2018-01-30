/*
 * MessageToSubscribersInformation.cpp
 *
 *  Created on: 14 Oct. 2017
 *      Author: tom
 */

#include <string>
#include "../../Common/Exceptions/ArgumentInvalidExceptions.h"
#include "MessageToSubscribersEntity.h"
#include "IMessageToSubscribersEntity.h"

#include "../Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"

using namespace std;
using namespace Common::Exceptions;

namespace InMemoryBus {
namespace Subscribtions {
namespace MessageToSubscribers {
MessageToSubscribersEntity::MessageToSubscribersEntity(const string message_type,
                                                       IThreadSafeSubscriberInformationRepository_SPtr subscribers)
    : m_message_type(message_type),
      m_subscribers(subscribers) {
  if (message_type.empty()) {
    throw ArgumentInvalidException("Can't create MessageToSubscribers because 'message_type' is empty!",
                                               "message_type");
  }

  if (subscribers == nullptr) {
    throw ArgumentInvalidException("Can't create MessageToSubscribers because 'subscribers' is null!",
                                               "subscribers");
  }
}

bool operator<(const MessageToSubscribersEntity& one, const MessageToSubscribersEntity& two) {
  return (one.get_message_type() < two.get_message_type());
}

string MessageToSubscribersEntity::get_message_type() const {
  return (m_message_type);
}

IThreadSafeSubscriberInformationRepository_SPtr MessageToSubscribersEntity::get_repository() const {
  return (m_subscribers);
}
}
}
}
