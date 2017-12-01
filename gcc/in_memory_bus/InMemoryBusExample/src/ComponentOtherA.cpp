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

using namespace std;

namespace InMemoryBusExample {
ComponentOtherA::ComponentOtherA(IBus_SPtr bus)
    : InMemoryBus::BusNode(bus, "ComponentOtherA", "OtherMessage") {
}

ComponentOtherA::~ComponentOtherA() {
  cout << "[ComponentOtherA::~ComponentOtherA] Destroyed!" << endl;
}

void ComponentOtherA::update() {
  OtherMessage* message = new OtherMessage();

  for (int i = 0; i < 3; i++) {
    cout << "[ComponentOtherA::update] Sending OtherMessage..." << endl;

    send(message);
  }
}
} /* namespace InMemoryBus */
