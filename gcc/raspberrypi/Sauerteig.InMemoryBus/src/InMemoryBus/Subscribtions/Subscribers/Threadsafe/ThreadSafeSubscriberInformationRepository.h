/*
 * ThreadSafeSubscriberInformationRepository.h
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_THREADSAFE_THREADSAFESUBSCRIBERINFORMATIONREPOSITORY_H_
#define INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_THREADSAFE_THREADSAFESUBSCRIBERINFORMATIONREPOSITORY_H_

#include <mutex>
#include "IThreadSafeSubscriberInformationRepository.h"
#include "../ISubscriberInformationEntity.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
namespace ThreadSafe {
class ThreadSafeSubscriberInformationRepository : public IThreadSafeSubscriberInformationRepository {
 public:
  ThreadSafeSubscriberInformationRepository(ISubscriberInformationRepository_SPtr repository);
  virtual ~ThreadSafeSubscriberInformationRepository() = default;

  ISubscriberInformationEntityVector_SPtr get_all_subscribers() override;
  ISubscriberInformationEntity_SPtr find_subscriber_by_id(const string& subscriber_id) override;
  void remove(const ISubscriberInformationEntity_SPtr information) override;
  void add(const ISubscriberInformationEntity_SPtr information) override;
  size_t size() override;

 private:
  ISubscriberInformationRepository_SPtr m_repository = nullptr;

  recursive_mutex m_mutex;  // TODO allow multiple readers but only 1 writer
};
}
}
}
}

#endif /* INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_THREADSAFE_THREADSAFESUBSCRIBERINFORMATIONREPOSITORY_H_ */
