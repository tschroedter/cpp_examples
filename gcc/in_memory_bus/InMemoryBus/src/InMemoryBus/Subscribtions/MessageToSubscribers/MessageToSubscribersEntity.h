/*
 * MessageToSubscribersInformation.h
 *
 *  Created on: 14 Oct. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_MESSAGETOSUBSCRIBERSENTITY_H_
#define SRC_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_MESSAGETOSUBSCRIBERSENTITY_H_

#include <string>
#include "IMessageToSubscribersEntity.h"
#include "../../Common/BaseEntity.h"
#include "../Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
namespace MessageToSubscribers {
class MessageToSubscribersEntity : public IMessageToSubscribersEntity {
 public:
  MessageToSubscribersEntity(const string message_type, IThreadSafeSubscriberInformationRepository_SPtr subscribers);
  virtual ~MessageToSubscribersEntity() = default;

  string get_message_type() const override;
  IThreadSafeSubscriberInformationRepository_SPtr get_repository() const override;

  friend bool operator<(const MessageToSubscribersEntity& one, const MessageToSubscribersEntity& two);

 protected:
  MessageToSubscribersEntity() = default;
  string m_message_type;
  IThreadSafeSubscriberInformationRepository_SPtr m_subscribers = nullptr;
};
}
}
}

#endif /* SRC_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_MESSAGETOSUBSCRIBERSENTITY_H_ */
