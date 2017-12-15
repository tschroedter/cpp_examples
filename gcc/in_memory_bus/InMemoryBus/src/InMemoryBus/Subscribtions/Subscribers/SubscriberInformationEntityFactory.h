/*
 * SubscriberInformationEntityFactory.h
 *
 *  Created on: 15 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_SUBSCRIBERINFORMATIONENTITYFACTORY_H_
#define INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_SUBSCRIBERINFORMATIONENTITYFACTORY_H_

#include <string>
#include "ISubscriberInformationEntity.h"
#include "ISubscriberInformationEntityFactory.h"
#include "../../Common/SubscriberFunction.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {

class SubscriberInformationEntityFactory : public ISubscriberInformationEntityFactory {
 public:
  SubscriberInformationEntityFactory() = default;
  virtual ~SubscriberInformationEntityFactory() = default;

  ISubscriberInformationEntity_SPtr create(const string subscriber_id, const string message_type,
                                           const InMemoryBus::Common::SubscriberFunction subscriber_function) override;
};

}
}
}

#endif /* INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_SUBSCRIBERINFORMATIONENTITYFACTORY_H_ */
