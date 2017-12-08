/*
 * ComponentB.cpp
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#include <iostream>
#include "ComponentB.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BaseMessage.h"
#include "Message.h"

using namespace std;

namespace InMemoryBusExample {

ComponentB::ComponentB(IBus_SPtr bus)
    : InMemoryBus::Common::BusNode(bus, "ComponentB", "Message") {
}

void ComponentB::update() {
  auto greeting = make_shared<Message>("Hello");

  send(greeting);

  cout << "[ComponentB::update] I sending: " << greeting->getEvent() << endl;
}

void ComponentB::onNotify(BaseMessage_SPtr p_base_message) {
  Message_SPtr message = dynamic_pointer_cast<Message>(p_base_message);

  cout << "[ComponentB::onNotify] I received: " << message->getEvent() << endl;
}

} /* namespace InMemoryBus */
