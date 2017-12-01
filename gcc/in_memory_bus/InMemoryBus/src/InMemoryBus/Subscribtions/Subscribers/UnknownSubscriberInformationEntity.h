/*
 * NewUnknownSubscriberInformation.h
 *
 *  Created on: 29 Aug. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_UNKNOWNSUBSCRIBERINFORMATIONENTITY_H_
#define INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_UNKNOWNSUBSCRIBERINFORMATIONENTITY_H_

#include "../../BaseMessage.h"
#include "SubscriberInformationEntity.h"

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
class UnknownSubscriberInformation : public SubscriberInformationEntity {
 public:
  UnknownSubscriberInformation();
  virtual ~UnknownSubscriberInformation();

  InMemoryBus::SubscriberFunction getNotifyFunc();

 private:
  void onNotify(BaseMessage* p_message);
};
}
}
}

#endif /* INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_UNKNOWNSUBSCRIBERINFORMATIONENTITY_H_ */
