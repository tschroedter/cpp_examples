/*
 * InMemoryBusExampleModule.h
 *
 *  Created on: 2 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUSEXAMPLEMODULE_H_
#define INMEMORYBUSEXAMPLEMODULE_H_

#include "InMemoryBus/InMemoryBusModule.h"
#include "InMemoryBus/Common/IFactory.h"
#include "InMemoryBus/Subscribtions/Subscribers/SubscriberInformationEntity.h"
#include "InMemoryBus/Subscribtions/Subscribers/ISubscriberInformationEntity.h"

namespace InMemoryBusExample {

struct interface {
  virtual ~interface() noexcept = default;
  virtual void dummy1() = 0;
};
//->

struct implementation : interface {
  void dummy1() override {}
};

struct implementation_with_args : interface {
  implementation_with_args(int i, double d) {
    assert(42 == i);
    assert(87.0 == d);
  }
  void dummy1() override {}
};

/*<<example `example` class>>*/
class example {
 public:
  example(const ifactory<interface>& f1, const ifactory<interface, int, double>& f2) {
    assert(dynamic_cast<implementation*>(f1.create().get()));
    assert(dynamic_cast<implementation_with_args*>(f2.create(42, 87.0).get()));
  }
};

void mydo_nothing_subscriber_function(BaseMessage_SPtr base_message) {
}

class myexample {
 public:
  myexample(const ifactory<InMemoryBus::Subscribtions::Subscribers::ISubscriberInformationEntity>& factory) {
    assert(dynamic_cast<InMemoryBus::Subscribtions::Subscribers::SubscriberInformationEntity*>(factory.create().get()));
  }
};


auto inmemorybusexample_module = []
{
  return (di::make_injector(
        di::bind<interface>().to<implementation>(),
        di::bind<ifactory<interface>>().to(factory<implementation>{}),
        di::bind<ifactory<interface, int, double>>().to(factory<implementation_with_args>{}),
        InMemoryBus::inmemorybus_module()));
};

}

#endif /* INMEMORYBUSEXAMPLEMODULE_H_ */
