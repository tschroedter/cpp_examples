/*
 * MessageBusNotifierFactory.h
 *
 *  Created on: 15 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_FACTORIES_MESSAGEBUSNOTIFIERFACTORY_H_
#define INMEMORYBUS_NOTIFIERS_FACTORIES_MESSAGEBUSNOTIFIERFACTORY_H_

#include <memory>
#include "IMessageBusNotifierFactory.h"
#include "ISubscibersNotifierFactory.h"
#include "../IMessageBusNotifier.h"
#include "../ISubscibersNotifier.h"
#include "../../Subscribtions/SubscribtionManager.h"
#include "../../Common/MessageBusSynchronization.h"
#include "../../Common/IMessagesQueue.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Factories {

class MessageBusNotifierFactory : public IMessageBusNotifierFactory {
 public:
  MessageBusNotifierFactory(MessageBusSynchronization_SPtr synchronization, IMessagesQueue_SPtr messages,
                            ISubscibersNotifierFactory_SPtr factory);
  virtual ~MessageBusNotifierFactory() = default;

  IMessageBusNotifier_SPtr create() override;

 private:
  MessageBusSynchronization_SPtr m_synchronization = nullptr;
  IMessagesQueue_SPtr m_messages = nullptr;
  ISubscibersNotifierFactory_SPtr m_factory = nullptr;
};

}
}
}

#endif /* INMEMORYBUS_NOTIFIERS_FACTORIES_MESSAGEBUSNOTIFIERFACTORY_H_ */
