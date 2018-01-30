/*
 * BusNode.cpp
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#include <functional>
#include <algorithm>
#include <iostream>
#include "BusNode.h"
#include "BaseMessage.h"
#include "../IBus.h"

using namespace std;

namespace InMemoryBus {
namespace Common {

BusNode::BusNode(IBus_SPtr bus, string subscriber_id, string message_type)
    : m_bus(bus),
      m_subscriber_id(subscriber_id),
      m_message_type(message_type) {
  m_bus->subscribe(subscriber_id, message_type, this->get_notify_function());
}

BusNode::~BusNode() {
  m_bus->unsubscribe(m_subscriber_id, m_message_type);
}

void BusNode::update() {
}

std::function<void(BaseMessage_SPtr)> BusNode::get_notify_function() {
  auto messageListener = [=](BaseMessage_SPtr message) -> void
  {
    this->onNotify(message);
  };
  return (messageListener);
}

void BusNode::send(BaseMessage_SPtr message) {
  m_bus->publish(message);
}

void BusNode::onNotify(BaseMessage_SPtr message) {
}

}
}
