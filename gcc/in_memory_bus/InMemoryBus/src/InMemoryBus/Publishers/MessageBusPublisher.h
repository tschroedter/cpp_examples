/*
 * MessageBusPublisher.h
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#ifndef INMEMORY_PUBLISHERS_MESSAGEBUSPUBLISHER_H_
#define INMEMORY_PUBLISHERS_MESSAGEBUSPUBLISHER_H_

#include "../MessageBusSynchronization.h"
#include "../BaseMessage.h"
#include "../IMessagesQueue.h"
#include "../Typedefs.h"
#include "IMessageBusPublisher.h"

namespace InMemoryBus {
namespace Publishers {
class MessageBusPublisher : public IMessageBusPublisher {
 public:
  MessageBusPublisher(MessageBusSynchronization_SPtr synchronization, IMessagesQueue_SPtr messages);
  virtual ~MessageBusPublisher() = default;

  void publish(BaseMessage* p_message);

 private:
  MessageBusSynchronization_SPtr m_synchronization = nullptr;
  IMessagesQueue_SPtr m_messages = nullptr;
};
}
}

#endif /* INMEMORY_PUBLISHERS_MESSAGEBUSPUBLISHER_H_ */
