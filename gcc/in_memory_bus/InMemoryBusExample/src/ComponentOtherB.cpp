/*
 * ComponentOtherB.cpp
 *
 *  Created on: 4 Oct. 2017
 *      Author: tom
 */

#include "ComponentOtherB.h"

#include <iostream>
#include "ComponentA.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/BusNode.h"
#include "InMemoryBus/BaseMessage.h"
#include "OtherMessage.h"

using namespace std;

namespace InMemoryBusExample {

ComponentOtherB::ComponentOtherB(IBus_SPtr bus)
    : InMemoryBus::BusNode(bus, "ComponentOtherB", "OtherMessage") {
}

ComponentOtherB::~ComponentOtherB() {
  cout << "[ComponentOtherB::~ComponentOtherB] Destroyed!" << endl;
}

void ComponentOtherB::onNotify(InMemoryBus::BaseMessage* p_base_message) {
  auto p_message = dynamic_cast<OtherMessage*>(p_base_message);

  cout << "[ComponentOtherB::onNotify] I received: " << p_message->getType() << endl;
}
} /* namespace InMemoryBus */
