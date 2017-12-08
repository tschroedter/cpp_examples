/*
 * NewUnknownSubscriberInformation.h
 *
 *  Created on: 29 Aug. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_UNKNOWNSUBSCRIBERINFORMATIONENTITYENTITY_H_
#define INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_UNKNOWNSUBSCRIBERINFORMATIONENTITYENTITY_H_

#include "../../Common/BaseMessage.h"
#include "SubscriberInformationEntity.h"

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
class UnknownSubscriberInformationEntity : public SubscriberInformationEntity {
 public:
  UnknownSubscriberInformationEntity();
  virtual ~UnknownSubscriberInformationEntity();

  SubscriberFunction getNotifyFunc();

 private:
  void onNotify(BaseMessage_SPtr message);
};
}
}
}

#endif /* INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_UNKNOWNSUBSCRIBERINFORMATIONENTITYENTITY_H_ */
