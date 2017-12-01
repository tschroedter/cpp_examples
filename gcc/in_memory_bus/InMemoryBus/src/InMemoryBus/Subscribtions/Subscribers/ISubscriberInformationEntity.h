/*
 * ISubscriberInformation.h
 *
 *  Created on: 1 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_ISUBSCRIBERINFORMATIONENTITY_H_
#define INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_ISUBSCRIBERINFORMATIONENTITY_H_

#include "../../Typedefs.h"
#include "../../BaseEntity.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
class ISubscriberInformationEntity : public BaseEntity {
 public:
  virtual ~ISubscriberInformationEntity() = default;

  virtual string get_subscriber_id() const = 0;
  virtual string get_message_type() const = 0;
  virtual SubscriberFunction get_subscriber_function() const = 0;
};
}
}
}

typedef std::shared_ptr<InMemoryBus::Subscribtions::Subscribers::ISubscriberInformationEntity> ISubscriberInformationEntity_SPtr;
typedef std::vector<ISubscriberInformationEntity_SPtr> ISubscriberInformationEntityVector;
typedef std::shared_ptr<ISubscriberInformationEntityVector> ISubscriberInformationEntityVector_SPtr;

#endif /* INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_ISUBSCRIBERINFORMATIONENTITY_H_ */
