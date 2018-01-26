/*
 * ISubscriberInformation.h
 *
 *  Created on: 1 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_ISUBSCRIBERINFORMATIONENTITY_H_
#define INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_ISUBSCRIBERINFORMATIONENTITY_H_

#include <memory>
#include <vector>
#include <mutex>
#include "../../Common/SubscriberFunction.h"
#include "../../Common/BaseEntity.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
class ISubscriberInformationEntity : public InMemoryBus::Common::BaseEntity {
 public:
  virtual ~ISubscriberInformationEntity() = default;

  virtual string get_subscriber_id() const = 0;
  virtual string get_message_type() const = 0;
  virtual InMemoryBus::Common::SubscriberFunction get_subscriber_function() const = 0;
  virtual bool try_lock() = 0;
  virtual void unlock() =0;
};
}
}
}

typedef shared_ptr<InMemoryBus::Subscribtions::Subscribers::ISubscriberInformationEntity> ISubscriberInformationEntity_SPtr;
typedef vector<ISubscriberInformationEntity_SPtr> ISubscriberInformationEntityVector;
typedef shared_ptr<ISubscriberInformationEntityVector> ISubscriberInformationEntityVector_SPtr;

#endif /* INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_ISUBSCRIBERINFORMATIONENTITY_H_ */
