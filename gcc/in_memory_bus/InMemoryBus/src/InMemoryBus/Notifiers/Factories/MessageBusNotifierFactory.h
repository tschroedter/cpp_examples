/*
 * MessageBusNotifierFactory.h
 *
 *  Created on: 15 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_NOTIFIERS_FACTORIES_MESSAGEBUSNOTIFIERFACTORY_H_
#define SRC_INMEMORYBUS_NOTIFIERS_FACTORIES_MESSAGEBUSNOTIFIERFACTORY_H_

#include <memory>
#include "IMessageBusNotifierFactory.h"
#include "ISubscibersNotifierFactory.h"
#include "../IMessageBusNotifier.h"
#include "../ISubscibersNotifier.h"
#include "../../Common/Interfaces/ILogger.h"
#include "../../Common/Interfaces/IThreadInformationProvider.h"
#include "../../Common/MessageBusSynchronization.h"
#include "../../Common/IMessagesQueue.h"
#include "../../Subscribtions/SubscribtionManager.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Factories {

class MessageBusNotifierFactory : public IMessageBusNotifierFactory {
 public:
  MessageBusNotifierFactory(ILogger_SPtr logger,
                            IThreadInformationProvider_SPtr provider,
                            MessageBusSynchronization_SPtr synchronization,
                            IMessagesQueue_SPtr messages,
                            ISubscibersNotifierFactory_SPtr factory);
  virtual ~MessageBusNotifierFactory() = default;

  IMessageBusNotifier_SPtr create() override;

 private:
  ILogger_SPtr m_logger = nullptr;
  IThreadInformationProvider_SPtr m_provider = nullptr;
  MessageBusSynchronization_SPtr m_synchronization = nullptr;
  IMessagesQueue_SPtr m_messages = nullptr;
  ISubscibersNotifierFactory_SPtr m_factory = nullptr;
};

}
}
}

#endif /* SRC_INMEMORYBUS_NOTIFIERS_FACTORIES_MESSAGEBUSNOTIFIERFACTORY_H_ */
