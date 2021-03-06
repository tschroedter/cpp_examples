/*
 * FailedSubscriberFunctionCaller.cpp
 *
 *  Created on: 12 Dec. 2017
 *      Author: tom
 */

#include <string>
#include "FailedSubscriberFunctionCaller.h"
#include "../../Subscribtions/Subscribers/ISubscriberInformationEntity.h"
#include "../../Common/BaseMessage.h"
#include "../../Common/Interfaces/ILogger.h"
#include "../../Common/Exceptions/ArgumentInvalidExceptions.h"

using namespace std;
using namespace Common::Exceptions;

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

FailedSubscriberFunctionCaller::FailedSubscriberFunctionCaller(ILogger_SPtr logger)  // Todo testing
    : m_logger(logger) {
  if (m_logger == nullptr) {
    throw ArgumentInvalidException("Can't create FailedSubscriberFunctionCaller because 'logger' is null!",
                                               "logger");
  }
}

void FailedSubscriberFunctionCaller::call_subscriber_function(const ISubscriberInformationEntity_SPtr& info,
                                                              BaseMessage_SPtr& message) {
  bool success = try_call_subscriber_function(info, message);

  if (!success) {
    string text = "Failed to execute SubscriberFunction for message '" + message->getType()
        + "' and SubscriberId '" + info->get_subscriber_id() + "'! - PROCESSING ABORTED!";

    m_logger->error(text);
  }
}

}
}
}
