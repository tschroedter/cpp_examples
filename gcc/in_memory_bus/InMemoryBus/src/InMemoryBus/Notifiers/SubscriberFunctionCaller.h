/*
 * SubscriberFunctionCaller.h
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_SUBSCRIBERFUNCTIONCALLER_H_
#define INMEMORYBUS_NOTIFIERS_SUBSCRIBERFUNCTIONCALLER_H_

#include "ISubscriberFunctionCaller.h"
#include "Failed/IFailedToNotifyManager.h"
#include "../Subscribtions/Subscribers/ISubscriberInformationEntity.h"
#include "../Common/BaseMessage.h"

namespace InMemoryBus {
namespace Notifiers {

class SubscriberFunctionCaller : public ISubscriberFunctionCaller {
 public:
  SubscriberFunctionCaller(IFailedToNotifyManager_SPtr failed_manager);
  virtual ~SubscriberFunctionCaller() = default;

  void execute_subscriber_function(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message) override;
  bool try_call_subscriber_function(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr message) override;
  void call_subscriber_function(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message) override;

 private:
  IFailedToNotifyManager_SPtr m_manager = nullptr;
};

}
}

#endif /* INMEMORYBUS_NOTIFIERS_SUBSCRIBERFUNCTIONCALLER_H_ */
