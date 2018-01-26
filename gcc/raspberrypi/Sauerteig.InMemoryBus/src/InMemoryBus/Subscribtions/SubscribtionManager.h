/*
 * SubscribtionManager.h
 *
 *  Created on: 30 Oct. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBTIONMANAGER_H_
#define SRC_INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBTIONMANAGER_H_

#include <string>
#include "../Common/SubscriberFunction.h"
#include "ISubscribtionManager.h"
#include "Subscribers/SubscriberInformationEntity.h"
#include "Subscribers/UnknownSubscriberInformationEntityEntity.h"
#include "Subscribers/Factories/ISubscriberInformationEntityFactory.h"
#include "Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"
#include "MessageToSubscribers/IMessageToSubscribersEntity.h"
#include "MessageToSubscribers/MessageToSubscribersRepository.h"
#include "MessageToSubscribers/IMessageToSubscribersEntityFactory.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
class SubscribtionManager : public ISubscribtionManager {
 public:
  SubscribtionManager(IMessageToSubscribersRepository_SPtr repository,
                      ISubscriberInformationEntityFactory_SPtr information_factory,
                      IMessageToSubscribersEntityFactory_SPtr message_factory,
                      IUnknownSubscriberInformationEntity_SPtr unknown);
  ~SubscribtionManager() = default;

  void remove_subscription(string subscriber_id, string message_type) override;
  void add_subscription(string subscriber_id, string message_type,
                        InMemoryBus::Common::SubscriberFunction messageReceiver) override;
  IThreadSafeSubscriberInformationRepository_SPtr get_repository_for_message_type(const string& message_type) override;

 private:
  IMessageToSubscribersRepository_SPtr m_repository = nullptr;
  ISubscriberInformationEntityFactory_SPtr m_information_factory = nullptr;
  IMessageToSubscribersEntityFactory_SPtr m_message_factory = nullptr;
  IUnknownSubscriberInformationEntity_SPtr m_unknown = nullptr;

  IMessageToSubscribersEntity_SPtr create_entity(string message_type);
};
}
}

#endif /* SRC_INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBTIONMANAGER_H_ */
