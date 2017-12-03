/*
 * NewUnknownSubscriberInformation.cpp
 *
 *  Created on: 29 Aug. 2017
 *      Author: tom
 */

#include "../../BaseMessage.h"
#include "UnknownSubscriberInformationEntityEntity.h"

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
UnknownSubscriberInformationEntity::UnknownSubscriberInformationEntity()
    : SubscriberInformationEntity("Unknown", "Unknown", getNotifyFunc()) {
}

UnknownSubscriberInformationEntity::~UnknownSubscriberInformationEntity() {
}

InMemoryBus::SubscriberFunction UnknownSubscriberInformationEntity::getNotifyFunc() {
  auto messageListener = [=](BaseMessage_SPtr message) -> void
  {
    this->onNotify(message);
  };
  return (messageListener);
}

void UnknownSubscriberInformationEntity::onNotify(BaseMessage_SPtr message) {
}
}
}
}
