/*
 * FailedSubscriberFunctionCaller.h
 *
 *  Created on: 12 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDSUBSCRIBERFUNCTIONCALLER_H_
#define SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDSUBSCRIBERFUNCTIONCALLER_H_

#include "Common/Interfaces/ILogger.h"
#include "../../Subscribtions/Subscribers/ISubscriberInformationEntity.h"
#include "../../Common/BaseMessage.h"
#include "IFailedSubscriberFunctionCaller.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class FailedSubscriberFunctionCaller : public IFailedSubscriberFunctionCaller {
 public:
  FailedSubscriberFunctionCaller(ILogger_SPtr logger);
  virtual ~FailedSubscriberFunctionCaller() = default;

  void call_subscriber_function(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message) override;

 private:
  ILogger_SPtr m_logger = nullptr;
};

}
}
}

#endif /* SRC_INMEMORYBUS_NOTIFIERS_FAILED_FAILEDSUBSCRIBERFUNCTIONCALLER_H_ */
