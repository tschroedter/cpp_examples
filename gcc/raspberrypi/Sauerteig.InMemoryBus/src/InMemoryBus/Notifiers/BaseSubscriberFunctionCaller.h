/*
 * BaseSubscriberFunctionCaller.h
 *
 *  Created on: 12 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_NOTIFIERS_BASESUBSCRIBERFUNCTIONCALLER_H_
#define SRC_INMEMORYBUS_NOTIFIERS_BASESUBSCRIBERFUNCTIONCALLER_H_

#include "ISubscriberFunctionCaller.h"
#include "../Subscribtions/Subscribers/ISubscriberInformationEntity.h"
#include "../Common/BaseMessage.h"

namespace InMemoryBus {
namespace Notifiers {

class BaseSubscriberFunctionCaller : public ISubscriberFunctionCaller {
 public:
  BaseSubscriberFunctionCaller() = default;
  virtual ~BaseSubscriberFunctionCaller() = default;

  virtual void execute_subscriber_function(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message);
  virtual bool try_call_subscriber_function(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr message);
  virtual void call_subscriber_function(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message) = 0;

 protected:
  int m_number_of_retries = 10;
};

}
}

#endif /* SRC_INMEMORYBUS_NOTIFIERS_BASESUBSCRIBERFUNCTIONCALLER_H_ */
