//============================================================================
// Name        : InMemoryBusExample.cpp
// Author      : Thomas Schroedter
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <boost/di.hpp>

#include "NeedFactory.h"
#include "ComponentA.h"
#include "ComponentB.h"
#include "ComponentOtherA.h"
#include "ComponentOtherB.h"
#include "InMemoryBusExampleModule.h"
#include "InMemoryBus/Common/SubscriberFunction.h"
#include "InMemoryBus/Common/BaseMessage.h"
#include "InMemoryBus/Common/MessageBusSynchronization.h"
#include "InMemoryBus/Common/IMessagesQueue.h"
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "InMemoryBus/IBus.h"
#include "InMemoryBus/Notifiers/INotifierThreadPool.h"
#include "InMemoryBus/InMemoryBusModule.h"
#include "InMemoryBus/Subscribtions/ISubscribtionManager.h"
#include "InMemoryBus/Subscribtions/MessageToSubscribers/IMessageToSubscribersRepository.h"

using namespace std;

void test(BaseMessage_SPtr message) {
}

void MemoryLeakTest() {
  //}
  // Memory leak test
  auto sp_vector = std::make_shared<ISubscriberInformationEntityVector>();
  InMemoryBus::Subscribtions::Subscribers::SubscriberInformationRepository repo { sp_vector };
  InMemoryBus::Common::SubscriberFunction does_not_matter = test;
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

#define NUMBER_OF_MESSAGES 100

int main() {
  try {
    cout << "InMemoryBusExample" << endl;

    auto injector = InMemoryBusExample::inmemorybusexample_module();

    // TODO Factory not working yet auto test = injector.create<shared_ptr<InMemoryBusTests::NeedFactory>>();

    auto notifier_pool = injector.create<INotifierThreadPool_SPtr>();
    notifier_pool->initialize(16);

    auto synchronization = injector.create<MessageBusSynchronization_SPtr>();

    ComponentA_UPtr compA = injector.create<ComponentA_UPtr>();
    ComponentB_UPtr compB = injector.create<ComponentB_UPtr>();

    auto coa_uptrs = std::vector<ComponentOtherA_UPtr>();

    for (int i = 0; i < NUMBER_OF_MESSAGES; i++) {
      coa_uptrs.push_back(injector.create<ComponentOtherA_UPtr>());
      coa_uptrs[i]->set_range(i, i);
    }

    auto cob_uptrs = std::vector<ComponentOtherB_UPtr>();

    for (int i = 0; i < NUMBER_OF_MESSAGES; i++) {
      cob_uptrs.push_back(injector.create<ComponentOtherB_UPtr>());
    }

    compA->update();
    compB->update();

    for (size_t i = 0; i < coa_uptrs.size(); i++) {
      coa_uptrs[i]->update();
    }

    // MemoryLeakTest();

    std::this_thread::sleep_for(std::chrono::seconds(2));  // give threads time to process

    for (size_t i = 0; i < cob_uptrs.size(); i++) {
      bool is_good = cob_uptrs[i]->get_status();

      if (is_good) {
        cout << i << ": All Good!" << endl;
      } else {
        cout << i << ": ERROR NOT GOOD!" << endl;
      }
    }

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
