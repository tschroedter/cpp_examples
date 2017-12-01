/*
 * BaseMessage.cpp
 *
 *  Created on: 23Jun.,2017
 *      Author: tom
 */

#include "BaseMessage.h"
#include <string>

namespace InMemoryBus {

BaseMessage::BaseMessage(const std::string messageType) {
  this->m_messageType = messageType;

}

std::string BaseMessage::getType() const {
  return (this->m_messageType);
}
;
} /* namespace InMemoryBus */
