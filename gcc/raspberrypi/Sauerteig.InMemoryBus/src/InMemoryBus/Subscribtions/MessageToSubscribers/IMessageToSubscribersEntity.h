/*
 * IMessageToSubscribers.h
 *
 *  Created on: 30 Oct. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_IMESSAGETOSUBSCRIBERSENTITY_H_
#define SRC_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_IMESSAGETOSUBSCRIBERSENTITY_H_

#include "../Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"
#include "../../Common/BaseEntity.h"

namespace InMemoryBus {
namespace Subscribtions {
namespace MessageToSubscribers {
class IMessageToSubscribersEntity : public InMemoryBus::Common::BaseEntity {
 public:
  virtual ~IMessageToSubscribersEntity() = default;

  virtual std::string get_message_type() const = 0;
  virtual IThreadSafeSubscriberInformationRepository_SPtr get_repository() const = 0;
};
}
}
}

typedef std::shared_ptr<InMemoryBus::Subscribtions::MessageToSubscribers::IMessageToSubscribersEntity> IMessageToSubscribersEntity_SPtr;
typedef std::vector<IMessageToSubscribersEntity_SPtr> IMessageToSubscribersEntityVector;
typedef std::shared_ptr<IMessageToSubscribersEntityVector> IMessageToSubscribersEntityVector_SPtr;

#endif /* SRC_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_IMESSAGETOSUBSCRIBERSENTITY_H_ */
