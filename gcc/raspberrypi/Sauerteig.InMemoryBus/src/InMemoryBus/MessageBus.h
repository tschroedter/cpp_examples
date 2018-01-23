/*
 * MessageBus.h
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#ifndef MESSAGEBUS_H_
#define MESSAGEBUS_H_

#include "IBus.h"
#include "Common/SubscriberFunction.h"
#include "Publishers/MessageBusPublisher.h"
#include "Subscribtions/ISubscribtionManager.h"

using namespace std;

namespace InMemoryBus {

class MessageBus : public IBus {
 public:
  MessageBus(IMessageBusPublisher_SPtr publisher, ISubscribtionManager_SPtr manager);
  virtual ~MessageBus() = default;

  void subscribe(string subscriber_id, string message_type, Common::SubscriberFunction messageReceiver);
  void unsubscribe(string subscriber_id, string message_type);
  void publish(BaseMessage_SPtr message);
  void notify();

 private:
  IMessageBusPublisher_SPtr m_publisher = nullptr;
  ISubscribtionManager_SPtr m_manager = nullptr;
};

}

#endif /* MESSAGEBUS_H_ */
