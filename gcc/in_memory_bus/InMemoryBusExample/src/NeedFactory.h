/*
 * NeedFactory.h
 *
 *  Created on: 10 Dec. 2017
 *      Author: tom
 */

#ifndef SRC_NEEDFACTORY_H_
#define SRC_NEEDFACTORY_H_

#include <memory>
#include <boost/di.hpp>
#include "InMemoryBus/Common/SubscriberFunction.h"
#include "InMemoryBus/Common/IFactory.h"
#include "InMemoryBus/Subscribtions/Subscribers/SubscriberInformationEntity.h"
#include "InMemoryBus/Subscribtions/Subscribers/ISubscriberInformationEntity.h"

namespace InMemoryBusTests {

class NeedFactory {
 public:
  NeedFactory(
      const ifactory<InMemoryBus::Subscribtions::Subscribers::ISubscriberInformationEntity, string, string,
          InMemoryBus::Common::SubscriberFunction>& factory);
  virtual ~NeedFactory() = default;

 private:
  const ifactory<InMemoryBus::Subscribtions::Subscribers::ISubscriberInformationEntity, string, string,
      InMemoryBus::Common::SubscriberFunction>& m_factory;

  static void do_nothing(BaseMessage_SPtr base_message);
};

} /* namespace InMemoryBusTests */

#endif /* SRC_NEEDFACTORY_H_ */
