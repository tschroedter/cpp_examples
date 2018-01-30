/*
 * ISubscriberInformationRepository.h
 *
 *  Created on: 27 Oct. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_IMESSAGETOSUBSCRIBERSREPOSITORY_H_
#define SRC_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_IMESSAGETOSUBSCRIBERSREPOSITORY_H_

#include "MessageToSubscribersEntity.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
namespace MessageToSubscribers {
class IMessageToSubscribersRepository {
 public:
  virtual ~IMessageToSubscribersRepository() = default;

  virtual IMessageToSubscribersEntityVector_SPtr get_all_subscribers() const = 0;
  virtual IMessageToSubscribersEntity_SPtr find_subscriber_by_message_type(const string& message_type) = 0;
  virtual void remove(const IMessageToSubscribersEntity_SPtr information) = 0;
  virtual void add(const IMessageToSubscribersEntity_SPtr information) = 0;
  virtual size_t size() const = 0;
};
}
}
}

typedef shared_ptr<InMemoryBus::Subscribtions::MessageToSubscribers::IMessageToSubscribersRepository> IMessageToSubscribersRepository_SPtr;

#endif /* SRC_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_IMESSAGETOSUBSCRIBERSREPOSITORY_H_ */
