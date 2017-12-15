/*
 * MessageBusNotifierFactory.cpp
 *
 *  Created on: 15 Dec. 2017
 *      Author: tom
 */

#include <memory>
#include "MessageBusNotifierFactory.h"
#include "MessageBusNotifier.h"
#include "IMessageBusNotifier.h"
#include "../Common/IFactory.h"
#include "../Exceptions/ArgumentInvalidException.h"

namespace InMemoryBus {
namespace Notifiers {

MessageBusNotifierFactory::MessageBusNotifierFactory(const ifactory<IMessageBusNotifier>& factory)
    : m_factory(factory) {
}

IMessageBusNotifier_SPtr MessageBusNotifierFactory::create() {
  IMessageBusNotifier_SPtr instance = m_factory.create();

  return instance;
}

}
}
