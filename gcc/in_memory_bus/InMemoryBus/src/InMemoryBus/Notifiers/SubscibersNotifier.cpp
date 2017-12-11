/*
 * SubscibersNotifier.cpp
 *
 *  Created on: 5 Dec. 2017
 *      Author: tom
 */

#include <thread>
#include <chrono>
#include "SubscibersNotifier.h"
#include "ISubscriberFunctionCaller.h"
#include "../Common/BaseMessage.h"
#include "../Common/ILogger.h"
#include "../Exceptions/ArgumentInvalidException.h"
#include "../Subscribtions/ISubscribtionManager.h"
#include "../Subscribtions/Subscribers/SubscriberInformationEntity.h"

namespace InMemoryBus {
namespace Notifiers {

SubscibersNotifier::SubscibersNotifier(ILogger_SPtr logger, ISubscribtionManager_SPtr manager, ISubscriberFunctionCaller_SPtr caller)
    : m_logger(logger),
      m_manager(manager),
      m_caller(caller) {
  if (m_logger == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create SubscibersNotifier because 'logger' is null!", "logger");
  }

  if (m_manager == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create SubscibersNotifier because 'manager' is null!", "manager");
  }

  if (m_caller == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create SubscibersNotifier because 'caller' is null!", "caller");
  }

  m_logger->set_prefix("SubscibersNotifier");
}

void SubscibersNotifier::notify_all_subscribers_for_message(BaseMessage_SPtr message) {
  check_before_notifying(message);
}

void SubscibersNotifier::check_before_notifying(BaseMessage_SPtr message) {
  if (message == nullptr) {
    m_logger->debug("[MessageBusNotifier::check_before_notify_all_subscribers_for_message] 'message' is null!");

    return;
  }

  IThreadSafeSubscriberInformationRepository_SPtr repository = m_manager->get_repository_for_message_type(
      message->getType());

  if (repository == nullptr) {
    m_logger->debug("check_before_notify_all_subscribers_for_message(...) 'repository' is null!");

    return;
  }

  ISubscriberInformationEntityVector_SPtr entities = repository->get_all_subscribers();

  if (entities == nullptr) {
    m_logger->debug("check_before_notify_all_subscribers_for_message(...) 'entities' is null!");

    return;
  }

  call_all_subscriber_functions(entities, message);
}

void SubscibersNotifier::call_all_subscriber_functions(const ISubscriberInformationEntityVector_SPtr& infos,
                                                       BaseMessage_SPtr message) {
  for (auto iter = infos->begin(); iter != infos->end(); iter++) {
    ISubscriberInformationEntity_SPtr info = (*iter);
    auto message_type = message->getType();
    if (message_type.compare(info->get_message_type()) != 0) {
      continue;
    }

    m_caller->call_subscriber_function(info, message);
  }
}

}
}
