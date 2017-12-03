/*
 * UnknownMessageToSubscribers.h
 *
 *  Created on: 30 Oct. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBERS_UNKNOWNMESSAGETOSUBSCRIBERSENTITYENTITY_H_
#define INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBERS_UNKNOWNMESSAGETOSUBSCRIBERSENTITYENTITY_H_

#include "MessageToSubscribersEntity.h"
#include "../Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
namespace MessageToSubscribers {
class UnknownMessageToSubscribersEntity : public MessageToSubscribersEntity {
 public:
  UnknownMessageToSubscribersEntity();
  virtual ~UnknownMessageToSubscribersEntity() = default;

  string get_message_type() const override;
  IThreadSafeSubscriberInformationRepository_SPtr get_repository() const override;
};
}
}
}

#endif /* INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBERS_UNKNOWNMESSAGETOSUBSCRIBERSENTITYENTITY_H_ */
