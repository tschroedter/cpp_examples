/*
 * MessageBusPublisher.h
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORY_PUBLISHERS_MESSAGEBUSPUBLISHER_H_
#define SRC_INMEMORY_PUBLISHERS_MESSAGEBUSPUBLISHER_H_

#include "../Common/MessageBusSynchronization.h"
#include "../Common/BaseMessage.h"
#include "../Common/IMessagesQueue.h"
#include "../Common/SubscriberFunction.h"
#include "IMessageBusPublisher.h"

namespace InMemoryBus {
namespace Publishers {
class MessageBusPublisher : public IMessageBusPublisher {
 public:
  MessageBusPublisher(MessageBusSynchronization_SPtr synchronization, IMessagesQueue_SPtr messages);
  virtual ~MessageBusPublisher() = default;

  void publish(BaseMessage_SPtr message);

 private:
  MessageBusSynchronization_SPtr m_synchronization = nullptr;
  IMessagesQueue_SPtr m_messages = nullptr;
};
}
}

#endif /* SRC_INMEMORY_PUBLISHERS_MESSAGEBUSPUBLISHER_H_ */
