/*
 * SubscribtionManager.h
 *
 *  Created on: 30 Oct. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBTIONMANAGER_H_
#define INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBTIONMANAGER_H_

#include <string>
#include "../Common/SubscriberFunction.h"
#include "ISubscribtionManager.h"
#include "Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"
#include "MessageToSubscribers/IMessageToSubscribersEntity.h"
#include "MessageToSubscribers/MessageToSubscribersRepository.h"
#include "Subscribers/SubscriberInformationEntity.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
class SubscribtionManager : public ISubscribtionManager {
 public:
  SubscribtionManager(IMessageToSubscribersRepository_SPtr repository);
  ~SubscribtionManager() = default;

  void remove_subscription(string subscriber_id, string message_type) override;
  void add_subscription(string subscriber_id, string message_type, SubscriberFunction messageReceiver) override;
  IThreadSafeSubscriberInformationRepository_SPtr get_repository_for_message_type(const string& message_type) override;

 private:
  IMessageToSubscribersRepository_SPtr m_repository = nullptr;

  IMessageToSubscribersEntity_SPtr create_entity(string message_type);
};
}
}

#endif /* INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBTIONMANAGER_H_ */
