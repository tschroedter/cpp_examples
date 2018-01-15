/*
 * ISubscriberFunctionCaller.h
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_ISUBSCRIBERFUNCTIONCALLER_H_
#define INMEMORYBUS_NOTIFIERS_ISUBSCRIBERFUNCTIONCALLER_H_

#include <memory>
#include "../Common/BaseMessage.h"
#include "../Subscribtions/Subscribers/SubscriberInformationEntity.h"

namespace InMemoryBus {
namespace Notifiers {
class ISubscriberFunctionCaller {
 public:
  virtual ~ISubscriberFunctionCaller() = default;

  virtual void execute_subscriber_function(const ISubscriberInformationEntity_SPtr& info,
                                           BaseMessage_SPtr& message) = 0;
  virtual bool try_call_subscriber_function(const ISubscriberInformationEntity_SPtr& info,
                                            BaseMessage_SPtr message) = 0;
  virtual void call_subscriber_function(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message) = 0;
};
}
}

typedef std::shared_ptr<InMemoryBus::Notifiers::ISubscriberFunctionCaller> ISubscriberFunctionCaller_SPtr;

#endif /* INMEMORYBUS_NOTIFIERS_ISUBSCRIBERFUNCTIONCALLER_H_ */
