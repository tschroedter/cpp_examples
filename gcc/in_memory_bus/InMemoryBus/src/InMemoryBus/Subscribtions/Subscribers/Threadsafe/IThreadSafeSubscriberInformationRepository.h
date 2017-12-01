/*
 * IThreadSafeSubscriberInformationRepository.h
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_THREADSAFE_ITHREADSAFESUBSCRIBERINFORMATIONREPOSITORY_H_
#define INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_THREADSAFE_ITHREADSAFESUBSCRIBERINFORMATIONREPOSITORY_H_

#include "../ISubscriberInformationEntityRepository.h"

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
namespace ThreadSafe {
class IThreadSafeSubscriberInformationRepository : public ISubscriberInformationRepository {
 public:
  virtual ~IThreadSafeSubscriberInformationRepository() = default;
};
}
}
}
}

typedef std::shared_ptr<InMemoryBus::Subscribtions::Subscribers::ThreadSafe::IThreadSafeSubscriberInformationRepository> IThreadSafeSubscriberInformationRepository_SPtr;

#endif /* INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_THREADSAFE_ITHREADSAFESUBSCRIBERINFORMATIONREPOSITORY_H_ */
