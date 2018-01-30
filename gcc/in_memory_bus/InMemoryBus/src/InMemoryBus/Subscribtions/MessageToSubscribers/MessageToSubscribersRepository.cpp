/*
 * MessageToSubscribersRepository.cpp
 *
 *  Created on: 30 Oct. 2017
 *      Author: tom
 */

#include "../../Common/Exceptions/ArgumentInvalidExceptions.h"
#include "MessageToSubscribersRepository.h"
#include "IMessageToSubscribersEntity.h"
#include "UnknownMessageToSubscribersEntityEntity.h"

using namespace std;
using namespace Common::Exceptions;

namespace InMemoryBus {
namespace Subscribtions {
namespace MessageToSubscribers {

MessageToSubscribersRepository::MessageToSubscribersRepository(IMessageToSubscribersEntityVector_SPtr subscribers) {
  if (subscribers == nullptr) {
    throw ArgumentInvalidException(
        "Can't create MessageToSubscribersRepository because 'subscribers' is null!", "subscribers");
  }

  m_subscribers = make_shared<InMemoryBus::Common::BaseRepository<IMessageToSubscribersEntity>>(subscribers);

  m_unknown = make_shared<UnknownMessageToSubscribersEntity>();
}

IMessageToSubscribersEntityVector_SPtr MessageToSubscribersRepository::get_all_subscribers() const {
  return (m_subscribers->get_all());
}

IMessageToSubscribersEntity_SPtr MessageToSubscribersRepository::find_subscriber_by_message_type(
    const string& message_type) {
  auto all = m_subscribers->get_all();

  for (auto iter = all->begin(); iter != all->end(); iter++) {
    IMessageToSubscribersEntity_SPtr entity = (*iter);

    string type = entity->get_message_type();

    if (type.compare(message_type) == 0) {
      return (entity);
    }
  }

  return (m_unknown);
}

void MessageToSubscribersRepository::remove(const IMessageToSubscribersEntity_SPtr entity) {
  m_subscribers->remove(entity);
}

void MessageToSubscribersRepository::add(const IMessageToSubscribersEntity_SPtr entity) {
  m_subscribers->add(entity);
}

size_t MessageToSubscribersRepository::size() const {
  return (m_subscribers->size());
}
}
}
}
