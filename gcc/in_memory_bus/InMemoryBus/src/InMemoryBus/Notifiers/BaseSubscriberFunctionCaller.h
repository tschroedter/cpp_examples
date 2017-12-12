/*
 * BaseSubscriberFunctionCaller.h
 *
 *  Created on: 12 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_BASESUBSCRIBERFUNCTIONCALLER_H_
#define INMEMORYBUS_NOTIFIERS_BASESUBSCRIBERFUNCTIONCALLER_H_

#include "../Subscribtions/Subscribers/ISubscriberInformationEntity.h"
#include "../Common/BaseMessage.h"
#include "ISubscriberFunctionCaller.h"

namespace InMemoryBus {
namespace Notifiers {

class BaseSubscriberFunctionCaller : public ISubscriberFunctionCaller {
 public:
  BaseSubscriberFunctionCaller() = default;
  virtual ~BaseSubscriberFunctionCaller() = default;

  void execute_subscriber_function(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message);
  bool try_call_subscriber_function(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr message);
  virtual void call_subscriber_function(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message) = 0;

 protected:
  int m_number_of_retries = 10;
};

}
}

#endif /* INMEMORYBUS_NOTIFIERS_BASESUBSCRIBERFUNCTIONCALLER_H_ */
