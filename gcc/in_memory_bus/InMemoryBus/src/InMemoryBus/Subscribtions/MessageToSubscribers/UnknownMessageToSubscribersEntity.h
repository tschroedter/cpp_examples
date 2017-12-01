/*
 * UnknownMessageToSubscribers.h
 *
 *  Created on: 30 Oct. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBERS_UNKNOWNMESSAGETOSUBSCRIBERSENTITY_H_
#define INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBERS_UNKNOWNMESSAGETOSUBSCRIBERSENTITY_H_

#include "MessageToSubscribersEntity.h"
#include "../Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
namespace MessageToSubscribers {
class UnknownMessageToSubscribers : public MessageToSubscribersEntity {
 public:
  UnknownMessageToSubscribers();
  virtual ~UnknownMessageToSubscribers() = default;

  string get_message_type() const override;
  IThreadSafeSubscriberInformationRepository_SPtr get_repository() const override;
};
}
}
}

#endif /* INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBERS_UNKNOWNMESSAGETOSUBSCRIBERSENTITY_H_ */
