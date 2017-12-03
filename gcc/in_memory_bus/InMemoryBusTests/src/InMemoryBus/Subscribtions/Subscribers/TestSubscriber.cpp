/*
 * TestSubscriber.cpp
 *
 *  Created on: 16Jun.,2017
 *      Author: tom
 */

#include "../Subscribers/TestSubscriber.h"

#include <string>
#include "InMemoryBus/BaseMessage.h"
#include "InMemoryBus/Typedefs.h"
#include "../Subscribers/Message.h"

namespace InMemoryBusTests {

TestSubscriber::TestSubscriber() {
  m_received_message = m_no_message_received;
}

TestSubscriber::~TestSubscriber() {
}

InMemoryBus::SubscriberFunction TestSubscriber::getNotifyFunc() {
  auto messageListener = [=](BaseMessage_SPtr base_message) -> void
  {
    Message_SPtr message = dynamic_pointer_cast<Message>(base_message);

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
