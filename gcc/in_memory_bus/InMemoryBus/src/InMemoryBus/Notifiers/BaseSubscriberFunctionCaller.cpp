/*
 * BaseSubscriberFunctionCaller.cpp
 *
 *  Created on: 12 Dec. 2017
 *      Author: tom
 */

#include <thread>
#include "BaseSubscriberFunctionCaller.h"
#include "../Subscribtions/Subscribers/ISubscriberInformationEntity.h"
#include "../Common/BaseMessage.h"

namespace InMemoryBus {
namespace Notifiers {

void BaseSubscriberFunctionCaller::execute_subscriber_function(const ISubscriberInformationEntity_SPtr& info,
                                                               BaseMessage_SPtr& message) {
  InMemoryBus::Common::SubscriberFunction func = info->get_subscriber_function();
  func(message);
}

bool BaseSubscriberFunctionCaller::try_call_subscriber_function(const ISubscriberInformationEntity_SPtr& info,
                                                                BaseMessage_SPtr message) {
  int counter = 0;
  bool success = false;

  while (counter++ <= m_number_of_retries) {
    bool is_locked = info->try_lock();

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

}
}
