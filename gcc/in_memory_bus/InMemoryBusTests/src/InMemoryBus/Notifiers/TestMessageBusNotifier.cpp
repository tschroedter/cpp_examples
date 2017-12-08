/*
 * TestMessageBusNotifier.cpp
 *
 *  Created on: 5 Dec. 2017
 *      Author: tom
 */

#include "TestMessageBusNotifier.h"
#include "InMemoryBus/Notifiers/MessageBusNotifier.h"
#include "InMemoryBus/Notifiers/ISubscibersNotifier.h"
#include "InMemoryBus/MessageBusSynchronization.h"
#include "InMemoryBus/IMessagesQueue.h"

namespace InMemoryBusTests {

TestMessageBusNotifier::TestMessageBusNotifier(MessageBusSynchronization_SPtr synchronization,
                                               IMessagesQueue_SPtr messages, ISubscibersNotifier_SPtr notifier)
    : InMemoryBus::Notifiers::MessageBusNotifier(synchronization, messages, notifier) {
}

void TestMessageBusNotifier::notify() {
  InMemoryBus::Notifiers::MessageBusNotifier::notify();
}

void TestMessageBusNotifier::process_next_message() {
  InMemoryBus::Notifiers::MessageBusNotifier::process_next_message();
}

}
