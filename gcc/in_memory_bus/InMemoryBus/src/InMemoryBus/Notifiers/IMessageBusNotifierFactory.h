/*
 * IMessageBusNotifierFactory.h
 *
 *  Created on: 15 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_IMESSAGEBUSNOTIFIERFACTORY_H_
#define INMEMORYBUS_NOTIFIERS_IMESSAGEBUSNOTIFIERFACTORY_H_

#include <memory>
#include "IMessageBusNotifier.h"
#include "../Common/MessageBusSynchronization.h"
#include "../Common/IMessagesQueue.h"
#include "ISubscibersNotifier.h"
namespace InMemoryBus {
namespace Notifiers {

class IMessageBusNotifierFactory {
 public:
  virtual ~IMessageBusNotifierFactory() = default;

  virtual IMessageBusNotifier_SPtr create() = 0;
};

}
}

typedef std::shared_ptr<InMemoryBus::Notifiers::IMessageBusNotifierFactory> IMessageBusNotifierFactory_SPtr;

#endif /* INMEMORYBUS_NOTIFIERS_IMESSAGEBUSNOTIFIERFACTORY_H_ */