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
  m_messageType = messageType;
}

string BaseMessage::getType() const {
  return (m_messageType);
}

MessageIdType BaseMessage::get_id() const {
  return m_id;
}

void BaseMessage::create_new_id() {
    next_id++;
    m_id = next_id.load();
}

}
}
