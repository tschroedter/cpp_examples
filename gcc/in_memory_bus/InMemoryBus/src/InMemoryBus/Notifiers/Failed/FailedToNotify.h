/*
 * FailedToNotify.h
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFY_H_
#define INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFY_H_

#include "IFailedToNotify.h"
#include "../../BaseMessage.h"
#include "../../Subscribtions/Subscribers/ISubscriberInformationEntity.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class FailedToNotify : public IFailedToNotify {
 public:
  FailedToNotify(ISubscriberInformationEntity_SPtr information, BaseMessage_SPtr message);
  virtual ~FailedToNotify() = default;

  ISubscriberInformationEntity_SPtr get_information();
  BaseMessage_SPtr get_message();

 private:
  ISubscriberInformationEntity_SPtr m_information = nullptr;
  BaseMessage_SPtr m_message = nullptr;
};

}
}
}

#endif /* INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFY_H_ */
