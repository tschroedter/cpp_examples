/*
 * SubscriberInformationEntityFactory.h
 *
 *  Created on: 15 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_FACTORIES_SUBSCRIBERINFORMATIONENTITYFACTORY_H_
#define INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_FACTORIES_SUBSCRIBERINFORMATIONENTITYFACTORY_H_

#include <string>
#include "ISubscriberInformationEntityFactory.h"
#include "../ISubscriberInformationEntity.h"
#include "../../../Common/SubscriberFunction.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
namespace Factories {

class SubscriberInformationEntityFactory : public ISubscriberInformationEntityFactory {
 public:
  SubscriberInformationEntityFactory() = default;
  virtual ~SubscriberInformationEntityFactory() = default;

  ISubscriberInformationEntity_SPtr create(const string subscriber_id, const string message_type,
                                           const InMemoryBus::Common::SubscriberFunction subscriber_function) override;  // TODO BOOST.DI Factory not working yet
};

}
}
}
}

#endif /* INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_FACTORIES_SUBSCRIBERINFORMATIONENTITYFACTORY_H_ */
