/*
 * SubscriberFunctionCaller.cpp
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#include <thread>
#include "SubscriberFunctionCaller.h"
#include "Failed/FailedToNotify.h"
#include "Failed/IFailedToNotifyManager.h"
#include "../Subscribtions/Subscribers/ISubscriberInformationEntity.h"
#include "../BaseMessage.h"
#include "../Exceptions/ArgumentInvalidException.h"

namespace InMemoryBus {
namespace Notifiers {

#define NUMBER_OF_RETRIES 3

SubscriberFunctionCaller::SubscriberFunctionCaller(IFailedToNotifyManager_SPtr manager)
    : m_manager(manager) {
  if (m_manager == nullptr) {
    throw Exceptions::ArgumentInvalidException("Can't create SubscriberFunctionCaller because 'manager' is null!",
                                               "manager");
  }
}
void SubscriberFunctionCaller::execute_subscriber_function(const ISubscriberInformationEntity_SPtr& info,
                                                           BaseMessage_SPtr& message) {
  SubscriberFunction func = info->get_subscriber_function();
  func(message);
}

bool SubscriberFunctionCaller::try_call_all_subscriber_function(const ISubscriberInformationEntity_SPtr& info,
                                                                BaseMessage_SPtr message) {
  int counter = 0;
  bool success = false;

  while (counter++ <= NUMBER_OF_RETRIES) {  // TODO testing
    bool is_locked = info->try_lock();  // TODO MockISubscriberInformationEntity to check we lock and unlock mutex

    if (is_locked) {
      execute_subscriber_function(info, message);
      success = true;
      info->unlock();
      break;
    } else {
      std::this_thread::yield();
    }
  }

  return (success);
}

void SubscriberFunctionCaller::call_all_subscriber_function(const ISubscriberInformationEntity_SPtr& info,
                                                            BaseMessage_SPtr& message) {
  bool success = try_call_all_subscriber_function(info, message);

  if (!success) {
    auto failed = make_shared<Failed::FailedToNotify>(info, message);
    m_manager->enqueue(failed);
  }
}

}
}
