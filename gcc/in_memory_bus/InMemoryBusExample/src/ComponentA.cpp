/*
 * ComponentA.cpp
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#include <iostream>
#include "ComponentA.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/BusNode.h"
#include "InMemoryBus/BaseMessage.h"
#include "Message.h"

using namespace std;

namespace InMemoryBusExample {

ComponentA::ComponentA(IBus_SPtr bus)
    : InMemoryBus::BusNode(bus, "ComponentA", "Message") {
}

ComponentA::~ComponentA() {
  cout << "[ComponentA::~ComponentA] Destroyed!" << endl;
}

void ComponentA::onNotify(InMemoryBus::BaseMessage* p_base_message) {
  auto p_message = dynamic_cast<Message*>(p_base_message);

  cout << "[ComponentA::onNotify] I received: " << p_message->getEvent() << endl;
}

}
