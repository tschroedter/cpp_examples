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
        "Can't create ThreadSafeSubscriberInformationRepository because 'm_repository' is null!", "m_repository");
  }
}

ISubscriberInformationEntityVector_SPtr ThreadSafeSubscriberInformationRepository::get_all_subscribers() {
  m_mutex.lock();

  auto all = m_repository->get_all_subscribers();

  m_mutex.unlock();

  return (all);
}

ISubscriberInformationEntity_SPtr ThreadSafeSubscriberInformationRepository::find_subscriber_by_id(
    const string& subscriber_id) {
  m_mutex.lock();

  auto information = m_repository->find_subscriber_by_id(subscriber_id);

  m_mutex.unlock();

  return (information);
}

void ThreadSafeSubscriberInformationRepository::remove(const ISubscriberInformationEntity_SPtr information) {
  m_mutex.lock();

  m_repository->remove(information);

  m_mutex.unlock();
}

void ThreadSafeSubscriberInformationRepository::add(const ISubscriberInformationEntity_SPtr information) {
  m_mutex.lock();

  m_repository->add(information);

  m_mutex.unlock();
}

size_t ThreadSafeSubscriberInformationRepository::size() {
  m_mutex.lock();

  auto size = m_repository->size();

  m_mutex.unlock();

  return (size);
}
}
}
}
}
