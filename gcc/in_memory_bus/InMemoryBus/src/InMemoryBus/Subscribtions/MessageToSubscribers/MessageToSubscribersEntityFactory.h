/*
 * MessageToSubscribersEntityFactory.h
 *
 *  Created on: 15 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBERS_MESSAGETOSUBSCRIBERSENTITYFACTORY_H_
#define SRC_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBERS_MESSAGETOSUBSCRIBERSENTITYFACTORY_H_

#include <string>
#include "IMessageToSubscribersEntityFactory.h"
#include "IMessageToSubscribersEntity.h"

namespace InMemoryBus {
namespace Subscribtions {
namespace MessageToSubscribers {

class MessageToSubscribersEntityFactory : public IMessageToSubscribersEntityFactory {
 public:
  MessageToSubscribersEntityFactory() = default;
  virtual ~MessageToSubscribersEntityFactory() = default;

  IMessageToSubscribersEntity_SPtr create(const std::string message_type) override;

};

}
}
}

#endif /* SRC_INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBERS_MESSAGETOSUBSCRIBERSENTITYFACTORY_H_ */
