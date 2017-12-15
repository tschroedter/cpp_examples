/*
 * MessageBusNotifierFactory.h
 *
 *  Created on: 15 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_MESSAGEBUSNOTIFIERFACTORY_H_
#define INMEMORYBUS_NOTIFIERS_MESSAGEBUSNOTIFIERFACTORY_H_

#include <memory>
#include "IMessageBusNotifier.h"
#include "IMessageBusNotifierFactory.h"
#include "ISubscibersNotifier.h"
#include "../Subscribtions/SubscribtionManager.h"
#include "../Common/MessageBusSynchronization.h"
#include "../Common/IMessagesQueue.h"
#include "../Common/ILogger.h"
#include "../Common/IFactory.h"

namespace InMemoryBus {
namespace Notifiers {

class MessageBusNotifierFactory : public IMessageBusNotifierFactory{
 public:
  MessageBusNotifierFactory(const ifactory<IMessageBusNotifier>& factory);
  virtual ~MessageBusNotifierFactory() = default;

  IMessageBusNotifier_SPtr create() override;

 private:
  const ifactory<IMessageBusNotifier>& m_factory;
};

}
}

#endif /* INMEMORYBUS_NOTIFIERS_MESSAGEBUSNOTIFIERFACTORY_H_ */
