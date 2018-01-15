/*
 * SubscibersNotifier.h
 *
 *  Created on: 5 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_SUBSCIBERSNOTIFIER_H_
#define INMEMORYBUS_NOTIFIERS_SUBSCIBERSNOTIFIER_H_

#include "Common/Interfaces/ILogger.h"
#include "ISubscibersNotifier.h"
#include "ISubscriberFunctionCaller.h"
#include "../Common/BaseMessage.h"
#include "../Subscribtions/ISubscribtionManager.h"
#include "../Subscribtions/Subscribers/SubscriberInformationEntity.h"

namespace InMemoryBus {
namespace Notifiers {

class SubscibersNotifier : public ISubscibersNotifier {
 public:
  SubscibersNotifier(ILogger_SPtr logger, ISubscribtionManager_SPtr manager, ISubscriberFunctionCaller_SPtr caller);
  virtual ~SubscibersNotifier() = default;

  void notify_all_subscribers_for_message(BaseMessage_SPtr message) override;

 private:
  ILogger_SPtr m_logger = nullptr;
  ISubscribtionManager_SPtr m_manager = nullptr;
  ISubscriberFunctionCaller_SPtr m_caller = nullptr;

  void check_before_notifying(BaseMessage_SPtr message);
  void call_all_subscriber_functions(const ISubscriberInformationEntityVector_SPtr& infos, BaseMessage_SPtr message);
  void call_all_subscriber_function(ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message);
  bool try_call_all_subscriber_function(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr message);
  void execute_subscriber_function(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message);
};

}
}

#endif /* INMEMORYBUS_NOTIFIERS_SUBSCIBERSNOTIFIER_H_ */
