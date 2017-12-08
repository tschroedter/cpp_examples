/*
 * FailedToNotify.h
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFY_H_
#define INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFY_H_

#include "IFailedToNotify.h"
#include "../../Common/BaseMessage.h"
#include "../../Subscribtions/Subscribers/ISubscriberInformationEntity.h"

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

class FailedToNotify : public IFailedToNotify {
 public:
  FailedToNotify(ISubscriberInformationEntity_SPtr information, BaseMessage_SPtr message);
  virtual ~FailedToNotify() = default;

  ISubscriberInformationEntity_SPtr get_information() override;
  BaseMessage_SPtr get_message() override;

  int get_number_of_tries() const override;
  void increase_number_of_tries() override;

 private:
  ISubscriberInformationEntity_SPtr m_information = nullptr;
  BaseMessage_SPtr m_message = nullptr;
  int m_number_of_tries = 0;
};

}
}
}

#endif /* INMEMORYBUS_NOTIFIERS_FAILED_FAILEDTONOTIFY_H_ */
