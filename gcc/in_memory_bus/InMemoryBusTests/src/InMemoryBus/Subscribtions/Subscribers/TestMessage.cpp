/*
 * Message.cpp
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#include "TestMessage.h"

#include <string>
#include "InMemoryBus/BaseMessage.h"

namespace InMemoryBusTests {
TestMessage::TestMessage(const std::string event)
    : InMemoryBus::BaseMessage("TestMessage") {
  m_MessageEvent = event;
}

TestMessage::~TestMessage() {
}

std::string TestMessage::getEvent() {
  return (m_MessageEvent);
}
}
