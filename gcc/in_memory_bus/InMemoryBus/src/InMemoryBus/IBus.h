/*
 * IBus.h
 *
 *  Created on: 14Jun.,2017
 *      Author: tom
 */

#ifndef IBUS_H_
#define IBUS_H_

#include <memory>
#include <functional>
#include "Common/BaseMessage.h"
#include "Common/SubscriberFunction.h"

namespace InMemoryBus {

class IBus {
 public:
  virtual ~IBus() = default;
  virtual void subscribe(std::string subscriber_id, std::string message_type, SubscriberFunction messageReceiver) = 0;
  virtual void unsubscribe(std::string subscriber_id, std::string message_type) = 0;
  virtual void publish(BaseMessage_SPtr message) = 0;
};

}

typedef std::shared_ptr<InMemoryBus::IBus> IBus_SPtr;

#endif
