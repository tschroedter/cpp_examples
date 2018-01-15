/*
 * ISubscriberInformationEntityFactory.h
 *
 *  Created on: 15 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_FACTORIES_ISUBSCRIBERINFORMATIONENTITYFACTORY_H_
#define INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_FACTORIES_ISUBSCRIBERINFORMATIONENTITYFACTORY_H_

#include <string>
#include "../ISubscriberInformationEntity.h"
#include "../../../Common/SubscriberFunction.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
namespace Factories {

class ISubscriberInformationEntityFactory {
 public:
  ISubscriberInformationEntityFactory() = default;
  virtual ~ISubscriberInformationEntityFactory() = default;

  virtual ISubscriberInformationEntity_SPtr create(
      const string subscriber_id, const string message_type,
      const InMemoryBus::Common::SubscriberFunction subscriber_function) = 0;
};

}
}
}
}

typedef std::shared_ptr<InMemoryBus::Subscribtions::Subscribers::Factories::ISubscriberInformationEntityFactory> ISubscriberInformationEntityFactory_SPtr;

#endif /* INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_FACTORIES_ISUBSCRIBERINFORMATIONENTITYFACTORY_H_ */
