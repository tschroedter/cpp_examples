/*
 * NewUnknownSubscriberInformation.cpp
 *
 *  Created on: 29 Aug. 2017
 *      Author: tom
 */

#include "UnknownSubscriberInformationEntity.h"

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
UnknownSubscriberInformation::UnknownSubscriberInformation()
    : SubscriberInformationEntity("Unknown", "Unknown", getNotifyFunc()) {
}

UnknownSubscriberInformation::~UnknownSubscriberInformation() {
}

InMemoryBus::SubscriberFunction UnknownSubscriberInformation::getNotifyFunc() {
  auto messageListener = [=](InMemoryBus::BaseMessage* p_message) -> void
  {
    this->onNotify(p_message);
  };
  return (messageListener);
}

void UnknownSubscriberInformation::onNotify(BaseMessage* p_message) {
}
}
}
}
