/*
 * SubscribersModule.h
 *
 *  Created on: 28 Nov. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERSMODULE_H_
#define INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERSMODULE_H_

#include <string>
#include "boost/di.hpp"
#include "../Common/IFactory.h"
#include "../Common/SubscriberFunction.h"
#include "SubscribtionManager.h"
#include "ISubscribtionManager.h"
#include "Subscribers/SubscriberInformationRepository.h"
#include "Subscribers/ISubscriberInformationEntity.h"
#include "Subscribers/ISubscriberInformationRepository.h"
#include "Subscribers/SubscriberInformationEntityFactory.h"
#include "Subscribers/ISubscriberInformationEntityFactory.h"
#include "Subscribers/UnknownSubscriberInformationEntityEntity.h"
#include "Subscribers/Threadsafe/ThreadSafeSubscriberInformationRepository.h"
#include "Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"

namespace di = boost::di;
using namespace std;

namespace InMemoryBus {
namespace Subscribtions {
auto subscribtions_module =
    []
    {
      return
      (di::make_injector
          (
              di::bind<Subscribers::ThreadSafe::IThreadSafeSubscriberInformationRepository>.to<Subscribers::ThreadSafe::ThreadSafeSubscriberInformationRepository>(),
              di::bind<Subscribers::ISubscriberInformationRepository>.to<Subscribers::SubscriberInformationRepository>(),
              di::bind<Subscribers::UnknownSubscriberInformationEntity>.to<Subscribers::UnknownSubscriberInformationEntity>().in(di::singleton),
              di::bind<ISubscribtionManager>.to<SubscribtionManager>(),
              di::bind<Subscribers::ISubscriberInformationEntity>.to<Subscribers::SubscriberInformationEntity>(),
              di::bind<Subscribers::ISubscriberInformationEntityFactory>.to<Subscribers::SubscriberInformationEntityFactory>(),

              di::bind<ifactory
              <Subscribers::ISubscriberInformationEntity>>()
              .to(factory<Subscribers::SubscriberInformationEntity> {}),

              di::bind<ifactory
              <Subscribers::ISubscriberInformationEntity, std::string>>()
              .to(factory<Subscribers::SubscriberInformationEntity> {}),

              di::bind<ifactory
              <Subscribers::ISubscriberInformationEntity, std::string, std::string>>()
              .to(factory<Subscribers::SubscriberInformationEntity> {}),

              di::bind<ifactory
              <Subscribers::ISubscriberInformationEntity,
              string,
              string,
              InMemoryBus::Common::SubscriberFunction>>()
              .to(factory<Subscribers::SubscriberInformationEntity> {})
          )
      );
    };
}
}

/*
 *   example(const ifactory<interface>& f1, const ifactory<interface, int, double>& f2, const ifactory<interface, double>& f3) {
 assert(dynamic_cast<implementation*>(f1.create().get()));
 assert(dynamic_cast<implementation_with_args*>(f2.create(42, 87.0).get()));
 assert(dynamic_cast<implementation_with_injected_args*>(f3.create(87.0).get()));
 */

#endif /* INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERSMODULE_H_ */
