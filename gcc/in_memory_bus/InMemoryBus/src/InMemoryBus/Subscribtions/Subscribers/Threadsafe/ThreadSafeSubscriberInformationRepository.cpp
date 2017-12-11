/*
 * ThreadSafeSubscriberInformationRepository.cpp
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#include "ThreadSafeSubscriberInformationRepository.h"
#include "../ISubscriberInformationEntity.h"
#include "../../../Exceptions/ArgumentInvalidException.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
namespace ThreadSafe {
ThreadSafeSubscriberInformationRepository::ThreadSafeSubscriberInformationRepository(
    ISubscriberInformationRepository_SPtr repository)
    : m_repository(repository) {
  if (m_repository == nullptr) {
    throw Exceptions::ArgumentInvalidException(
        "Can't create ThreadSafeSubscriberInformationRepository because 'repository' is null!", "repository");
  }
}

ISubscriberInformationEntityVector_SPtr ThreadSafeSubscriberInformationRepository::get_all_subscribers() {
  std::lock_guard<std::recursive_mutex> lock (m_mutex);

  auto all = m_repository->get_all_subscribers();

  return (all);
}

ISubscriberInformationEntity_SPtr ThreadSafeSubscriberInformationRepository::find_subscriber_by_id(
    const string& subscriber_id) {
  std::lock_guard<std::recursive_mutex> lock (m_mutex);

  auto information = m_repository->find_subscriber_by_id(subscriber_id);

  return (information);
}

void ThreadSafeSubscriberInformationRepository::remove(const ISubscriberInformationEntity_SPtr information) {
  std::lock_guard<std::recursive_mutex> lock (m_mutex);

  m_repository->remove(information);
}

void ThreadSafeSubscriberInformationRepository::add(const ISubscriberInformationEntity_SPtr information) {
  std::lock_guard<std::recursive_mutex> lock (m_mutex);

  m_repository->add(information);
}

size_t ThreadSafeSubscriberInformationRepository::size() {
  std::lock_guard<std::recursive_mutex> lock (m_mutex);

  auto size = m_repository->size();

  return (size);
}
}
}
}
}
