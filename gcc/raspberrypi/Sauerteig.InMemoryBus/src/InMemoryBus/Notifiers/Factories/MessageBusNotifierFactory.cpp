/*
 * MessageBusNotifierFactory.cpp
 *
 *  Created on: 15 Dec. 2017
 *      Author: tom
 */

#include <memory>
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "MessageBusNotifierFactory.h"
#include "IMessageBusNotifierFactory.h"
#include "ISubscibersNotifierFactory.h"
#include "../MessageBusNotifier.h"
#include "../IMessageBusNotifier.h"
#include "../SubscibersNotifier.h"
#include "../ISubscibersNotifier.h"
#include "../../Subscribtions/SubscribtionManager.h"
#include "../../Common/MessageBusSynchronization.h"
#include "../../Common/IMessagesQueue.h"

using namespace Common::Exceptions;

namespace InMemoryBus {
namespace Notifiers {
namespace Factories {

MessageBusNotifierFactory::MessageBusNotifierFactory(
        ILogger_SPtr logger,
        IThreadInformationProvider_SPtr provider,
        MessageBusSynchronization_SPtr synchronization,
        IMessagesQueue_SPtr messages,
        ISubscibersNotifierFactory_SPtr factory)
    : m_logger(logger),
      m_provider(provider),
      m_synchronization(synchronization),
      m_messages(messages),
      m_factory(factory) {
  if (m_logger == nullptr) {
    throw ArgumentInvalidException("Can't create MessageBusNotifierFactory because 'logger' is null!",
                                               "logger");
  }

  if (m_provider == nullptr) {
    throw ArgumentInvalidException("Can't create MessageBusNotifierFactory because 'provider' is null!",
                                               "provider");
  }

  if (m_synchronization == nullptr) {
    throw ArgumentInvalidException(
        "Can't create MessageBusNotifierFactory because 'synchronization' is null!", "synchronization");
  }

  if (m_messages == nullptr) {
    throw ArgumentInvalidException("Can't create MessageBusNotifierFactory because 'messages' is null!",
                                               "messages");
  }

  if (m_factory == nullptr) {
    throw ArgumentInvalidException("Can't create MessageBusNotifierFactory because 'factory' is null!",
                                               "factory");
  }

}

IMessageBusNotifier_SPtr MessageBusNotifierFactory::create() {

  ISubscibersNotifier_SPtr subscriber_notifier = m_factory->create();

  IMessageBusNotifier_SPtr notifier =
          std::make_shared<InMemoryBus::Notifiers::MessageBusNotifier>(
                                            m_logger,
                                            m_provider,
                                            m_synchronization,
                                            m_messages,
                                            subscriber_notifier);  // TODO use container to create notifiers

  return notifier;
}

}
}
}
