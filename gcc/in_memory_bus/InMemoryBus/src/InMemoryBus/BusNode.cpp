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
#include "IBus.h"
#include "BaseMessage.h"

namespace InMemoryBus {

BusNode::BusNode(IBus_SPtr bus, std::string subscriber_id, std::string message_type)
    : m_bus(bus),
      m_subscriber_id(subscriber_id),
      m_message_type(message_type) {
  m_bus->subscribe(subscriber_id, message_type, this->getNotifyFunc());
}

BusNode::~BusNode() {
  m_bus->unsubscribe(m_subscriber_id, m_message_type);
}

void BusNode::update() {
}

std::function<void(BaseMessage*)> BusNode::getNotifyFunc() {
  auto messageListener = [=](BaseMessage* p_message) -> void
  {
    this->onNotify(p_message);
  };
  return (messageListener);
}

void BusNode::send(BaseMessage* p_message) {
  m_bus->publish(p_message);
}

void BusNode::onNotify(BaseMessage* message) {
}

}
