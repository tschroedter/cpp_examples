/*
 * ComponentOther.cpp
 *
 *  Created on: 22 Aug. 2017
 *      Author: tom
 */

#include "ComponentOtherA.h"

#include <iostream>
#include "InMemoryBus/IBus.h"
#include "OtherMessage.h"

#define NO_OF_MESSAGES_TO_SEND 100

using namespace std;

namespace InMemoryBusExample {
ComponentOtherA::ComponentOtherA(IBus_SPtr bus)
    : InMemoryBus::Common::BusNode(bus, "ComponentOtherA", "OtherMessage") {
}

void ComponentOtherA::update() {
  for (int i = m_start; i <= m_stop; i++) {
    auto message = make_shared<OtherMessage>();
    message->counter = i;

    send(message);

    cout << "[ComponentOtherA::update] OtherMessage with Counter: " << i << " send!" << endl;
  }
}

void ComponentOtherA::set_range(int start, int stop) {
  m_start = start;
  m_stop = stop;
}

}
