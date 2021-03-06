/*
 * NewUnknownSubscriberInformation.h
 *
 *  Created on: 29 Aug. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_UNKNOWNSUBSCRIBERINFORMATIONENTITYENTITY_H_
#define SRC_INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_UNKNOWNSUBSCRIBERINFORMATIONENTITYENTITY_H_

#include <memory>
#include <string>
#include "../../Common/BaseMessage.h"
#include "SubscriberInformationEntity.h"

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
class UnknownSubscriberInformationEntity : public SubscriberInformationEntity {
 public:
  UnknownSubscriberInformationEntity();
  virtual ~UnknownSubscriberInformationEntity();

  InMemoryBus::Common::SubscriberFunction getNotifyFunc();

 private:
  void onNotify(BaseMessage_SPtr message);
};
}
}
}

typedef std::shared_ptr<InMemoryBus::Subscribtions::Subscribers::UnknownSubscriberInformationEntity> IUnknownSubscriberInformationEntity_SPtr;

#endif /* SRC_INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_UNKNOWNSUBSCRIBERINFORMATIONENTITYENTITY_H_ */
