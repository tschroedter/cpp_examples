/*
 * SubscriberFunctionCaller.h
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_NOTIFIERS_SUBSCRIBERFUNCTIONCALLER_H_
#define SRC_INMEMORYBUS_NOTIFIERS_SUBSCRIBERFUNCTIONCALLER_H_

#include "BaseSubscriberFunctionCaller.h"
#include "Failed/IFailedToNotifyManager.h"
#include "../Subscribtions/Subscribers/ISubscriberInformationEntity.h"
#include "../Common/BaseMessage.h"

namespace InMemoryBus {
namespace Notifiers {

class SubscriberFunctionCaller : public BaseSubscriberFunctionCaller {
 public:
  SubscriberFunctionCaller(IFailedToNotifyManager_SPtr failed_manager);
  virtual ~SubscriberFunctionCaller() = default;

  void call_subscriber_function(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message) override;

 private:
  IFailedToNotifyManager_SPtr m_manager = nullptr;
};

}
}

#endif /* SRC_INMEMORYBUS_NOTIFIERS_SUBSCRIBERFUNCTIONCALLER_H_ */
