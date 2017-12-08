/*
 * ComponentA.cpp
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#include <iostream>
#include "ComponentA.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Common/BusNode.h"
#include "InMemoryBus/Common/BaseMessage.h"
#include "Message.h"

using namespace std;

namespace InMemoryBusExample {

ComponentA::ComponentA(IBus_SPtr bus)
    : InMemoryBus::Common::BusNode(bus, "ComponentA", "Message") {
}

void ComponentA::onNotify(BaseMessage_SPtr p_base_message) {
  Message_SPtr message = dynamic_pointer_cast<Message>(p_base_message);

  cout << "[ComponentA::onNotify] I received: " << message->getEvent() << endl;
}

}
