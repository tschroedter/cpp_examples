/*
 * TestNotifier.h
 *
 *  Created on: 6 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_PUBLISHERS_TESTNOTIFIER_H_
#define INMEMORYBUS_PUBLISHERS_TESTNOTIFIER_H_

#include "InMemoryBus/MessageBusSynchronization.h"

namespace InMemoryBusTests {

using namespace InMemoryBus;

class TestNotifier {
 public:
  TestNotifier(MessageBusSynchronization_SPtr synchronization, int time_out_in_ms);
  virtual ~TestNotifier() = default;

  void operator()() {
    notify();
  }

  void notify();

  bool was_called_notify = false;

 private:
  MessageBusSynchronization_SPtr m_synchronization = nullptr;
  int m_time_out_in_ms = 1000;
};

}

#endif /* INMEMORYBUS_PUBLISHERS_TESTNOTIFIER_H_ */
