/*
 * IBus.h
 *
 *  Created on: 14Jun.,2017
 *      Author: tom
 */

#ifndef SRC_IBUS_H_
#define SRC_IBUS_H_

#include <memory>
#include <functional>
#include "Common/BaseMessage.h"
#include "Common/SubscriberFunction.h"

using namespace std;

namespace InMemoryBus {

class IBus {
 public:
  virtual ~IBus() = default;
  virtual void subscribe(string subscriber_id, string message_type,
                         Common::SubscriberFunction messageReceiver) = 0;
  virtual void unsubscribe(string subscriber_id, string message_type) = 0;
  virtual void publish(BaseMessage_SPtr message) = 0;
};

}

typedef shared_ptr<InMemoryBus::IBus> IBus_SPtr;

#endif /* SRC_IBUS_H_ */
