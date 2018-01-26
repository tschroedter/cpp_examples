/*
 * FailedToNotify.cpp
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#include "FailedToNotify.h"
#include "Common/Exceptions/ArgumentInvalidExceptions.h"
#include "../../Common/BaseMessage.h"
#include "../../Subscribtions/Subscribers/ISubscriberInformationEntity.h"

using namespace Common::Exceptions;

namespace InMemoryBus {
namespace Notifiers {
namespace Failed {

FailedToNotify::FailedToNotify(ISubscriberInformationEntity_SPtr information, BaseMessage_SPtr message)  // Todo testing
    : m_information(information),
      m_message(message),
      m_number_of_tries(0) {
  if (m_information == nullptr) {
    throw ArgumentInvalidException(
        "Can't create FailedToNotify because 'information' is null!", "information");
  }

  if (m_message == nullptr) {
    throw ArgumentInvalidException("Can't create FailedToNotify because 'message' is null!",
                                                            "message");
  }
}

ISubscriberInformationEntity_SPtr FailedToNotify::get_information() {
  return (m_information);
}

BaseMessage_SPtr FailedToNotify::get_message() {
  return (m_message);
}
int FailedToNotify::get_number_of_tries() const {
  return (m_number_of_tries);
}

void FailedToNotify::increase_number_of_tries() {
  m_number_of_tries++;
}

}
}
}
