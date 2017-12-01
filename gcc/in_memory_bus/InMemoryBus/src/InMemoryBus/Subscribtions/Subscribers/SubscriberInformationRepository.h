/*
 * NewSubscriberInformation.h
 *
 *  Created on: 29 Aug. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_SUBSCRIBERINFORMATIONREPOSITORY_H_
#define INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_SUBSCRIBERINFORMATIONREPOSITORY_H_

#include "SubscriberInformationRepository.h"

#include <string>
#include <memory>
#include "../../BaseRepository.h"
#include "ISubscriberInformationEntity.h"
#include "ISubscriberInformationEntityRepository.h"
#include "UnknownSubscriberInformationEntity.h"

using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
namespace Subscribers {
class SubscriberInformationRepository : public ISubscriberInformationRepository {
 public:
  SubscriberInformationRepository(ISubscriberInformationEntityVector_SPtr informations);
  virtual ~SubscriberInformationRepository() = default;

  ISubscriberInformationEntityVector_SPtr get_all_subscribers() override;
  ISubscriberInformationEntity_SPtr find_subscriber_by_id(const string& subscriber_id) override;
  void remove(const ISubscriberInformationEntity_SPtr information) override;
  void add(const ISubscriberInformationEntity_SPtr information) override;
  size_t size() override;

 private:
  shared_ptr<BaseRepository<ISubscriberInformationEntity>> m_informations = nullptr;
  shared_ptr<UnknownSubscriberInformation> m_unknown = nullptr;
};
}
}
}

#endif /* INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERS_SUBSCRIBERINFORMATIONREPOSITORY_H_ */
