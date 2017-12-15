/*
 * IMessageToSubscribersEntityFactory.h
 *
 *  Created on: 15 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBERS_IMESSAGETOSUBSCRIBERSENTITYFACTORY_H_
#define INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBERS_IMESSAGETOSUBSCRIBERSENTITYFACTORY_H_

#include <memory>
#include <string>
#include "IMessageToSubscribersEntity.h"

namespace InMemoryBus {
namespace Subscribtions {
namespace MessageToSubscribers {
class IMessageToSubscribersEntityFactory {
 public:
  virtual ~IMessageToSubscribersEntityFactory() = default;

  virtual IMessageToSubscribersEntity_SPtr create(const std::string message_type) = 0;
};
}
}
}

typedef std::shared_ptr<InMemoryBus::Subscribtions::MessageToSubscribers::IMessageToSubscribersEntityFactory> IMessageToSubscribersEntityFactory_SPtr;

#endif /* INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBERS_IMESSAGETOSUBSCRIBERSENTITYFACTORY_H_ */
