/*
 * IFailedToNotifiyManager.h
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDTONOTIFYMANAGER_H_
#define INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDTONOTIFYMANAGER_H_

#include <memory>
#include "IFailedToNotify.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class IFailedToNotifyManager {
 public:
  virtual ~IFailedToNotifyManager() = default;

  virtual void handle_failed_notification(const ISubscriberInformationEntity_SPtr& info, BaseMessage_SPtr& message) = 0;
};

}
}
}

typedef std::shared_ptr<InMemoryBus::Notifiers::Failed::IFailedToNotifyManager> IFailedToNotifyManager_SPtr;

#endif /* INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDTONOTIFYMANAGER_H_ */
