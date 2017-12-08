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
#include "InMemoryBus/Common/BusNode.h"
#include "InMemoryBus/Common/BaseMessage.h"
#include "OtherMessage.h"

using namespace std;

namespace InMemoryBusExample {

ComponentOtherB::ComponentOtherB(IBus_SPtr bus)
    : InMemoryBus::Common::BusNode(bus, "ComponentOtherB", "OtherMessage") {
}

void ComponentOtherB::onNotify(BaseMessage_SPtr p_base_message) {
  OtherMessage_SPtr message = dynamic_pointer_cast<OtherMessage>(p_base_message);
  int counter = message->counter;

  if (m_bitset.test(counter) == true) {
    cout << "[ComponentOtherB::onNotify] ERROR - Already received message for Counter " << counter << "!" << endl;

    return;
  }

  m_bitset.set(counter);
}

bool ComponentOtherB::get_status() {
  bool all_true = true;
  for (size_t i = 0; i < m_bitset.size(); i++) {
    bool test = m_bitset.test(i);

    all_true = all_true && test;

    if (!test) {
      cout << "[ComponentOtherB::onNotify] Didn't receive message for counter " << i << "!" << endl;
    }
  }

  return (all_true);
}
} /* namespace InMemoryBus */
