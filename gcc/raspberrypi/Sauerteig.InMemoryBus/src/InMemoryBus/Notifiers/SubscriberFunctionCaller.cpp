/*
 * SubscriberFunctionCaller.cpp
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#include "SubscriberFunctionCaller.h"
#include "Failed/IFailedToNotifyManager.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../Common/BaseMessage.h"

using namespace Common::Exceptions;

namespace InMemoryBus {
namespace Notifiers {

SubscriberFunctionCaller::SubscriberFunctionCaller(IFailedToNotifyManager_SPtr manager)
    : m_manager(manager) {
  if (m_manager == nullptr) {
    throw ArgumentInvalidException("Can't create SubscriberFunctionCaller because 'manager' is null!",
                                               "manager");
  }
}

void SubscriberFunctionCaller::call_subscriber_function(const ISubscriberInformationEntity_SPtr& info,
                                                        BaseMessage_SPtr& message) {
  bool success = try_call_subscriber_function(info, message);

  if (!success) {
    m_manager->handle_failed_notification(info, message);
  }
}

}
}
