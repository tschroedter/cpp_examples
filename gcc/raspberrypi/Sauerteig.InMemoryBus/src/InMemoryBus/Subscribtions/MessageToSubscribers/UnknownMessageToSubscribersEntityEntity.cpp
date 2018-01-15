/*
 * UnknownMessageToSubscribers.cpp
 *
 *  Created on: 30 Oct. 2017
 *      Author: tom
 */

#include "UnknownMessageToSubscribersEntityEntity.h"

#include "MessageToSubscribersEntity.h"
#include "../Subscribers/ISubscriberInformationEntity.h"
#include "../Subscribers/SubscriberInformationRepository.h"
#include "../Subscribers/Threadsafe/ThreadSafeSubscriberInformationRepository.h"
#include "../Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
namespace MessageToSubscribers {
UnknownMessageToSubscribersEntity::UnknownMessageToSubscribersEntity()
    : MessageToSubscribersEntity() {
  auto sp_vector = make_shared<ISubscriberInformationEntityVector>();
  auto repo = make_shared<Subscribers::SubscriberInformationRepository>(sp_vector);
  auto thread_safe_repo = make_shared<Subscribers::ThreadSafe::ThreadSafeSubscriberInformationRepository>(repo);
  m_subscribers = thread_safe_repo;
  m_message_type = "Unknown";
}

string UnknownMessageToSubscribersEntity::get_message_type() const {
  return (m_message_type);
}

IThreadSafeSubscriberInformationRepository_SPtr UnknownMessageToSubscribersEntity::get_repository() const {
  return (m_subscribers);
}
}
}
}
