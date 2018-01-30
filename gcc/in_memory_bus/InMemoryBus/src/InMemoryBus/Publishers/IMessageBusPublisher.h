/*
 * IMessageBusPublisher.h
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORY_PUBLISHERS_IMESSAGEBUSPUBLISHER_H_
#define SRC_INMEMORY_PUBLISHERS_IMESSAGEBUSPUBLISHER_H_

#include <memory>
#include "../Common/BaseMessage.h"

namespace InMemoryBus {
namespace Publishers {
class IMessageBusPublisher {
 public:
  virtual ~IMessageBusPublisher() = default;

  virtual void publish(BaseMessage_SPtr message) = 0;
};
}
}

typedef std::shared_ptr<InMemoryBus::Publishers::IMessageBusPublisher> IMessageBusPublisher_SPtr;

#endif /* SRC_INMEMORY_PUBLISHERS_IMESSAGEBUSPUBLISHER_H_ */
