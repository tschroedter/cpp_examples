/*
 * SubscibersNotifierFactory.cpp
 *
 *  Created on: 16 Dec. 2017
 *      Author: tom
 */

#include <memory>
#include "SubscibersNotifierFactory.h"
#include "SubscibersNotifier.h"
#include "ISubscibersNotifier.h"
#include "SubscriberFunctionCaller.h"
#include "ISubscriberFunctionCaller.h"
#include "../Exceptions/ArgumentInvalidException.h"

namespace InMemoryBus {
namespace Notifiers {

SubscibersNotifierFactory::SubscibersNotifierFactory(ILogger_SPtr logger, ISubscribtionManager_SPtr manager, IFailedToNotifyManager_SPtr failed_manager)
: m_logger(logger),
  m_manager(manager),
  m_failed_manager(failed_manager) {
  if (m_logger == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create SubscibersNotifierFactory because 'logger' is null!",
                                               "logger");
  }

  if (m_manager == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create SubscibersNotifierFactory because 'manager' is null!",
                                               "manager");
  }

  if (m_failed_manager == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create SubscibersNotifierFactory because 'failed_manager' is null!",
                                               "failed_manager");
  }

}

ISubscibersNotifier_SPtr SubscibersNotifierFactory::create() {
  ISubscriberFunctionCaller_SPtr caller = std::make_shared<SubscriberFunctionCaller>(m_failed_manager);

  ISubscibersNotifier_SPtr notifier = std::make_shared<SubscibersNotifier>(m_logger, m_manager, caller);

  return notifier;
}

}
}
