/*
 * NewSubscriberInformationRepository.cpp
 *
 *  Created on: 29 Aug. 2017
 *      Author: tom
 */

#include <vector>
#include "uuid/uuid.h"
#include "../../Common/Exceptions/ArgumentInvalidExceptions.h"
#include "SubscriberInformationRepository.h"
#include "ISubscriberInformationEntity.h"

using namespace std;
using namespace Common::Exceptions;

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
SubscriberInformationRepository::SubscriberInformationRepository(ISubscriberInformationEntityVector_SPtr informations) {
  if (informations == nullptr) {
    throw ArgumentInvalidException(
        "Can't create SubscriberInformationRepository because 'informations' is null!", "informations");
  }

  m_informations = make_shared<InMemoryBus::Common::BaseRepository<ISubscriberInformationEntity>>(informations);

  m_unknown = make_shared<UnknownSubscriberInformationEntity>();
}

void SubscriberInformationRepository::add(const ISubscriberInformationEntity_SPtr entity) {
  m_informations->add(entity);
}

void SubscriberInformationRepository::remove(const ISubscriberInformationEntity_SPtr entity) {
  m_informations->remove(entity);
}

ISubscriberInformationEntityVector_SPtr SubscriberInformationRepository::get_all_subscribers() {
  return (m_informations->get_all());
}

ISubscriberInformationEntity_SPtr SubscriberInformationRepository::find_subscriber_by_id(const string& subscriber_id) {
  auto all = m_informations->get_all();

  for (auto iter = all->begin(); iter != all->end(); iter++) {
    ISubscriberInformationEntity_SPtr info = (*iter);

    string id = info->get_subscriber_id();

    if (id.compare(subscriber_id) == 0) {
      return (info);
    }
  }

  return (m_unknown);
}

size_t SubscriberInformationRepository::size() {
  return (m_informations->size());
}
}
}
}
