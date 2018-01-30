/*
 * IMessageBusNotifierFactory.h
 *
 *  Created on: 15 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_NOTIFIERS_FACTORIES_IMESSAGEBUSNOTIFIERFACTORY_H_
#define SRC_INMEMORYBUS_NOTIFIERS_FACTORIES_IMESSAGEBUSNOTIFIERFACTORY_H_

#include <memory>
#include "../IMessageBusNotifier.h"
#include "../ISubscibersNotifier.h"
#include "../../Common/MessageBusSynchronization.h"
#include "../../Common/IMessagesQueue.h"

using namespace std;

namespace InMemoryBus {
namespace Notifiers {
namespace Factories {

class IMessageBusNotifierFactory {
 public:
  virtual ~IMessageBusNotifierFactory() = default;

  virtual IMessageBusNotifier_SPtr create() = 0;
};

}
}
}

typedef shared_ptr<InMemoryBus::Notifiers::Factories::IMessageBusNotifierFactory> IMessageBusNotifierFactory_SPtr;

#endif /* SRC_INMEMORYBUS_NOTIFIERS_FACTORIES_IMESSAGEBUSNOTIFIERFACTORY_H_ */
