/*
 * ComponentB.cpp
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#include <iostream>
#include "ComponentB.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/BaseMessage.h"
#include "Message.h"

using namespace std;

namespace InMemoryBusExample {

ComponentB::ComponentB(IBus_SPtr bus)
    : InMemoryBus::BusNode(bus, "ComponentB", "Message") {
}
ComponentB::~ComponentB() {
  cout << "[ComponentB::~ComponentB] Destroyed!" << endl;
}

void ComponentB::update() {
  Message* p_greeting = new Message("Hello");  // todo memory leak
  send(p_greeting);

  cout << "[ComponentB::update] I sending: " << p_greeting->getEvent() << endl;
}

void ComponentB::onNotify(InMemoryBus::BaseMessage* p_base_message) {
  auto p_message = dynamic_cast<Message*>(p_base_message);

  cout << "[ComponentB::onNotify] I received: " << p_message->getEvent() << endl;
}

} /* namespace InMemoryBus */
