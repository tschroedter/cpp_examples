/*
 * ISubscriberInformationRepository.h
 *
 *  Created on: 27 Oct. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_ISUBSCRIBERINFORMATIONREPOSITORY_H_
#define INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_ISUBSCRIBERINFORMATIONREPOSITORY_H_

#include "ISubscriberInformationEntity.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
class ISubscriberInformationRepository {
 public:
  virtual ~ISubscriberInformationRepository() = default;

  virtual ISubscriberInformationEntityVector_SPtr get_all_subscribers() = 0;
  virtual ISubscriberInformationEntity_SPtr find_subscriber_by_id(const string& subscriber_id) = 0;
  virtual void remove(const ISubscriberInformationEntity_SPtr information) = 0;
  virtual void add(const ISubscriberInformationEntity_SPtr information) = 0;
  virtual size_t size() = 0;
};
}
}
}

typedef shared_ptr<InMemoryBus::Subscribtions::Subscribers::ISubscriberInformationRepository> ISubscriberInformationRepository_SPtr;

#endif /* INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_ISUBSCRIBERINFORMATIONREPOSITORY_H_ */
