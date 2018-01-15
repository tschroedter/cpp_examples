/*
 * MessageToSubscribersEntityFactory.cpp
 *
 *  Created on: 15 Dec. 2017
 *      Author: tom
 */

#include <string>
#include <memory>
#include "MessageToSubscribersEntity.h"
#include "MessageToSubscribersEntityFactory.h"
#include "IMessageToSubscribersEntity.h"
#include "../Subscribers/ISubscriberInformationEntity.h"
#include "../Subscribers/SubscriberInformationRepository.h"
#include "../Subscribers/Threadsafe/ThreadSafeSubscriberInformationRepository.h"

namespace InMemoryBus {
namespace Subscribtions {
namespace MessageToSubscribers {

using namespace std;

IMessageToSubscribersEntity_SPtr MessageToSubscribersEntityFactory::create(const string message_type) {
  auto sp_vector = make_shared<ISubscriberInformationEntityVector>();
  auto repo = make_shared<Subscribers::SubscriberInformationRepository>(sp_vector);
  auto thread_safe_repo = make_shared<Subscribers::ThreadSafe::ThreadSafeSubscriberInformationRepository>(repo);

  auto entity = make_shared<Subscribtions::MessageToSubscribers::MessageToSubscribersEntity>(message_type,
                                                                                             thread_safe_repo);

  return entity;
}

}
}
}
