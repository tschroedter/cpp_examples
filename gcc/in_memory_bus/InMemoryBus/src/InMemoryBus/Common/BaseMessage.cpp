/*
 * BaseMessage.cpp
 *
 *  Created on: 23Jun.,2017
 *      Author: tom
 */

#include "BaseMessage.h"
#include <string>

namespace InMemoryBus {
namespace Common {

using namespace std;

BaseMessage::BaseMessage(const string messageType) {
  this->m_messageType = messageType;

}

string BaseMessage::getType() const {
  return (this->m_messageType);
}

}
}
