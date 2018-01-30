/*
 * IThreadSafeSubscriberInformationRepository.h
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_THREADSAFE_ITHREADSAFESUBSCRIBERINFORMATIONREPOSITORY_H_
#define SRC_INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_THREADSAFE_ITHREADSAFESUBSCRIBERINFORMATIONREPOSITORY_H_

#include "../ISubscriberInformationRepository.h"

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

#endif /* SRC_INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_THREADSAFE_ITHREADSAFESUBSCRIBERINFORMATIONREPOSITORY_H_ */
