/*
 * IFailedToNotify.h
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDTONOTIFY_H_
#define INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDTONOTIFY_H_

#include <memory>
#include "../../BaseMessage.h"
#include "../../Subscribtions/Subscribers/ISubscriberInformationEntity.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class IFailedToNotify {
 public:
  virtual ~IFailedToNotify() = default;

  virtual ISubscriberInformationEntity_SPtr get_information() = 0;
  virtual BaseMessage_SPtr get_message() = 0;
};

}
}
}

typedef std::shared_ptr<InMemoryBus::Notifiers::Failed::IFailedToNotify> IFailedToNotify_SPtr;

#endif /* INMEMORYBUS_NOTIFIERS_FAILED_IFAILEDTONOTIFY_H_ */
