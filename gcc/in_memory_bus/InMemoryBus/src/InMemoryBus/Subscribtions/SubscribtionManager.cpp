/*
 * SubscribtionManager.cpp
 *
 *  Created on: 30 Oct. 2017
 *      Author: tom
 */
// TODO MySkills VET course
#include <memory>
#include "../Typedefs.h"
#include "SubscribtionManager.h"
#include "../Exceptions/ArgumentInvalidException.h"
#include "MessageToSubscribers/MessageToSubscribersEntity.h"
#include "MessageToSubscribers/IMessageToSubscribersRepository.h"
#include "MessageToSubscribers/IMessageToSubscribersEntity.h"
#include "Subscribers/ISubscriberInformationEntityRepository.h"
#include "Subscribers/SubscriberInformationEntity.h"
#include "Subscribers/SubscriberInformationRepository.h"
#include "Subscribers/Threadsafe/ThreadSafeSubscriberInformationRepository.h"
#include "Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
SubscribtionManager::SubscribtionManager(IMessageToSubscribersRepository_SPtr repository)
    : m_repository(repository) {
  if (m_repository == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create SubscribtionManager because 'm_repository' is null!",
                                               "m_repository");
  }
}

void SubscribtionManager::remove_subscription(string subscriber_id, string message_type) {
  auto entity = get_repository_for_message_type(message_type);

  auto information = entity->find_subscriber_by_id(subscriber_id);

  entity->remove(information);
}

IMessageToSubscribersEntity_SPtr SubscribtionManager::create_entity(string message_type) {
  // TODO use BOOST.DI factory
  auto sp_vector = make_shared<ISubscriberInformationEntityVector>();
  auto repo = make_shared<Subscribers::SubscriberInformationRepository>(sp_vector);
  auto thread_safe_repo = make_shared<Subscribers::ThreadSafe::ThreadSafeSubscriberInformationRepository>(repo);

  auto entity = make_shared<Subscribtions::MessageToSubscribers::MessageToSubscribersEntity>(message_type,
                                                                                             thread_safe_repo);

  return (entity);
}

void SubscribtionManager::add_subscription(string subscriber_id, string message_type,
                                           SubscriberFunction messageReceiver) {
  ISubscriberInformationEntity_SPtr information = make_shared<Subscribers::SubscriberInformationEntity>(
      subscriber_id, message_type, messageReceiver);

  IMessageToSubscribersEntity_SPtr entity = m_repository->find_subscriber_by_message_type(message_type);

  string entity_message_type = entity->get_message_type();

  if (entity_message_type.compare("Unknown") == 0) {   // TODO magic number
    entity = create_entity(message_type);

    m_repository->add(entity);
  }

  entity->get_repository()->add(information);
}

IThreadSafeSubscriberInformationRepository_SPtr SubscribtionManager::get_repository_for_message_type(
    const string& message_type) {
  auto entity = m_repository->find_subscriber_by_message_type(message_type);

  return (entity->get_repository());
}
}
}
