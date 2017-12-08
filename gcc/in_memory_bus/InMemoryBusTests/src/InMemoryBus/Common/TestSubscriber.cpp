/*
 * TestSubscriber.cpp
 *
 *  Created on: 16Jun.,2017
 *      Author: tom
 */

#include "../Common/TestSubscriber.h"

#include <string>
#include "InMemoryBus/Common/BaseMessage.h"
#include "InMemoryBus/Common/SubscriberFunction.h"
#include "TestMessage.h"

namespace InMemoryBusTests {

TestSubscriber::TestSubscriber() {
  m_received_message = m_no_message_received;
}

TestSubscriber::~TestSubscriber() {
}

InMemoryBus::SubscriberFunction TestSubscriber::getNotifyFunc() {
  auto messageListener = [=](BaseMessage_SPtr base_message) -> void
  {
    Message_SPtr message = dynamic_pointer_cast<TestMessage>(base_message);

    this->onNotify(message);
  };
  return (messageListener);
}

void TestSubscriber::onNotify(Message_SPtr message) {
  m_received_message = message;
}

bool TestSubscriber::wasCalledOnNotify() {
  if (m_received_message->getEvent() != "No Message Received") {
    return (true);
  }

  return (false);
}

} /* namespace InMemoryBus */
