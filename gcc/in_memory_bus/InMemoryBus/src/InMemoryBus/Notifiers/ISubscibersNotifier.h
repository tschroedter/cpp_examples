/*
 * ISubscibersNotifier.h
 *
 *  Created on: 5 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_NOTIFIERS_ISUBSCIBERSNOTIFIER_H_
#define SRC_INMEMORYBUS_NOTIFIERS_ISUBSCIBERSNOTIFIER_H_

#include <memory>
#include "../Common/BaseMessage.h"
#include "../Subscribtions/Subscribers/SubscriberInformationEntity.h"

namespace InMemoryBus {
namespace Notifiers {
class ISubscibersNotifier {
 public:
  virtual ~ISubscibersNotifier() = default;

  virtual void notify_all_subscribers_for_message(BaseMessage_SPtr message) = 0;
};
}
}

typedef std::shared_ptr<InMemoryBus::Notifiers::ISubscibersNotifier> ISubscibersNotifier_SPtr;

#endif /* SRC_INMEMORYBUS_NOTIFIERS_ISUBSCIBERSNOTIFIER_H_ */
