/*
 * ISubscribtionManager.h
 *
 *  Created on: 30 Oct. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_ISUBSCRIBTIONMANAGER_H_
#define INMEMORYBUS_SUBSCRIBTIONS_ISUBSCRIBTIONMANAGER_H_

#include "Subscribers/SubscriberInformationEntity.h"
#include "Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
class ISubscribtionManager {
 public:
  virtual ~ISubscribtionManager() = default;

  virtual void remove_subscription(string subscriber_id, string message_type) = 0;
  virtual void add_subscription(string subscriber_id, string message_type,
                                InMemoryBus::Common::SubscriberFunction messageReceiver) = 0;
  virtual IThreadSafeSubscriberInformationRepository_SPtr get_repository_for_message_type(
      const string& message_type) = 0;
};
}
}

typedef std::shared_ptr<InMemoryBus::Subscribtions::ISubscribtionManager> ISubscribtionManager_SPtr;

#endif /* INMEMORYBUS_SUBSCRIBTIONS_ISUBSCRIBTIONMANAGER_H_ */
