/*
 * NeedFactory.cpp
 *
 *  Created on: 10 Dec. 2017
 *      Author: tom
 */

#include <iostream>
#include "NeedFactory.h"
#include <memory>
#include <boost/di.hpp>
#include "InMemoryBus/Common/IFactory.h"
#include "InMemoryBus/Subscribtions/Subscribers/SubscriberInformationEntity.h"
#include "InMemoryBus/Subscribtions/Subscribers/ISubscriberInformationEntity.h"

namespace InMemoryBusTests {

NeedFactory::NeedFactory(const ifactory<InMemoryBus::Subscribtions::Subscribers::ISubscriberInformationEntity, string, string,
                         InMemoryBus::Common::SubscriberFunction>& factory)
: m_factory(factory) {
  auto test = dynamic_cast<InMemoryBus::Subscribtions::Subscribers::ISubscriberInformationEntity*>
              (m_factory.create("id", "type", do_nothing).get());

  cout << test << endl;

  /*
  ISubscriberInformationEntity_SPtr test = dynamic_cast<InMemoryBus::Subscribtions::Subscribers::ISubscriberInformationEntity*>
              (m_factory.create("id", "type", do_nothing).get());

  test->get_id();
  */
}

void NeedFactory::do_nothing(BaseMessage_SPtr base_message) {
}

} /* namespace InMemoryBusTests */
