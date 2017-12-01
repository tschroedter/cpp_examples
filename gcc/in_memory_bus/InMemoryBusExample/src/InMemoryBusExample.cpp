//============================================================================
// Name        : InMemoryBusExample.cpp
// Author      : Thomas Schroedter
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <string.h>
#include <boost/di.hpp>

#include "ComponentA.h"
#include "ComponentB.h"
#include "InMemoryBusExampleModule.h"
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "InMemoryBus/MessageBusSynchronization.h"
#include "InMemoryBus/IMessagesQueue.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Notifiers/INotifierThreadPool.h"
#include "InMemoryBus/InMemoryBusModule.h"
#include "InMemoryBus/Subscribtions/ISubscribtionManager.h"
#include "InMemoryBus/Subscribtions/MessageToSubscribers/IMessageToSubscribersRepository.h"

#include "ComponentOtherA.h"
#include "ComponentOtherB.h"

using namespace std;

void test(InMemoryBus::BaseMessage * message) {
}

void MemoryLeakTest() {
  //}
  // Memory leak test
  auto sp_vector = std::make_shared<ISubscriberInformationEntityVector>();
  InMemoryBus::Subscribtions::Subscribers::SubscriberInformationRepository repo { sp_vector };
  InMemoryBus::SubscriberFunction does_not_matter = test;
  for (int i = 0; i < 10000; i++) {
    std::string id = std::to_string(i);
    auto info = std::make_shared<InMemoryBus::Subscribtions::Subscribers::SubscriberInformationEntity>(id, "type",
                                                                                                       does_not_matter);
    repo.add(info);
    std::cout << "Added " << id << " to repository...\n";
    repo.remove(info);
    std::cout << "...removed " << id << " from repository!\n";
  }
}

int main() {
  try {
    cout << "InMemoryBusExample" << endl;

    auto injector = InMemoryBusExample::inmemorybusexample_module();
    auto bus = injector.create<IBus_SPtr>();
    auto notifier_pool = injector.create<INotifierThreadPool_SPtr>();
    notifier_pool->initialize(10);

    auto synchronization = injector.create<MessageBusSynchronization_SPtr>();

    ComponentA_UPtr compA = injector.create<ComponentA_UPtr>();
    ComponentB_UPtr compB = injector.create<ComponentB_UPtr>();
    ComponentOtherB_UPtr otherA = injector.create<ComponentOtherB_UPtr>();
    ComponentOtherA_UPtr otherB = injector.create<ComponentOtherA_UPtr>();

    // This is supposed to act like a game loop.
    // for (int ctr = 0; ctr < 5; ctr++)
    {
      compA->update();
      compB->update();
      otherA->update();
      otherB->update();
    }

    // MemoryLeakTest();

    std::this_thread::sleep_for(std::chrono::seconds(1));  // give threads time to process

    notifier_pool->stop();
  } catch (const InMemoryBus::Exceptions::ArgumentInvalidException & ex) {
    std::cout << "ArgumentInvalidException: " << ex.what();
  } catch (const std::exception & ex) {
    std::cout << "Exception: " << ex.what();
  } catch (...) {
    std::cout << "Default Exception!";
  }

  return (0);
}
