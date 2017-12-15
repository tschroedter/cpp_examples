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
#include "../Common/MessageBusSynchronization.h"
#include "../Common/IMessagesQueue.h"
#include "../Exceptions/ArgumentInvalidException.h"

namespace InMemoryBus {
namespace Notifiers {

MessageBusNotifierFactory::MessageBusNotifierFactory(MessageBusSynchronization_SPtr synchronization, IMessagesQueue_SPtr messages, ISubscibersNotifierFactory_SPtr factory)
: m_synchronization(synchronization),
  m_messages(messages),
  m_factory(factory) {
  if (m_synchronization == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create MessageBusNotifierFactory because 'synchronization' is null!",
                                               "synchronization");
  }

  if (m_messages == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create MessageBusNotifierFactory because 'messages' is null!",
                                               "messages");
  }

  if (m_factory == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create MessageBusNotifierFactory because 'factory' is null!",
                                               "factory");
  }

}

IMessageBusNotifier_SPtr MessageBusNotifierFactory::create() {

  ISubscibersNotifier_SPtr subscriber_notifier = m_factory->create();

  IMessageBusNotifier_SPtr notifier =
      std::make_shared<MessageBusNotifier>(m_synchronization,
                                           m_messages,
                                           subscriber_notifier);  // TODO use container to create notifiers

  return notifier;
}

}
}
