/*
 * TestNotifier.cpp
 *
 *  Created on: 6 Dec. 2017
 *      Author: tom
 */

#include <mutex>
#include <chrono>
#include <functional>
#include <condition_variable>
#include "TestNotifier.h"
#include "InMemoryBus/MessageBusSynchronization.h"

namespace InMemoryBusTests {

using namespace InMemoryBus;

TestNotifier::TestNotifier(MessageBusSynchronization_SPtr synchronization, int time_out_in_ms)
    : m_synchronization(synchronization),
      m_time_out_in_ms(time_out_in_ms) {
}

void TestNotifier::notify() {
  std::unique_lock<std::mutex> lock(m_synchronization->mutex);

  bool completed = m_synchronization->messages_available.wait_for(
      lock, std::chrono::milliseconds(m_time_out_in_ms),
      std::bind(&MessageBusSynchronization::is_messages_avalable, m_synchronization));

  if (completed) {
    was_called_notify = true;
  }
}

}

