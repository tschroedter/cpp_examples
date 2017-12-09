/*
 * SubscribersModule.h
 *
 *  Created on: 28 Nov. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERSMODULE_H_
#define INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERSMODULE_H_

#include <boost/di.hpp>
#include "SubscribtionManager.h"
#include "ISubscribtionManager.h"
#include "Subscribers/SubscriberInformationRepository.h"
#include "Subscribers/ISubscriberInformationEntity.h"
#include "Subscribers/ISubscriberInformationRepository.h"
#include "Subscribers/SubscriberInformationEntity.h"
#include "Subscribers/UnknownSubscriberInformationEntityEntity.h"
#include "Subscribers/Threadsafe/ThreadSafeSubscriberInformationRepository.h"
#include "Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"

namespace di = boost::di;

namespace InMemoryBus {
namespace Subscribtions {
auto subscribtions_module =
    []
    {
      return (di::make_injector(
              di::bind<Subscribers::ISubscriberInformationEntity>.to<Subscribers::SubscriberInformationEntity>(),
              di::bind<Subscribers::ThreadSafe::IThreadSafeSubscriberInformationRepository>.to<Subscribers::ThreadSafe::ThreadSafeSubscriberInformationRepository>(),
              di::bind<Subscribers::ISubscriberInformationRepository>.to<Subscribers::SubscriberInformationRepository>(),
              di::bind<Subscribers::UnknownSubscriberInformationEntity>.to<Subscribers::UnknownSubscriberInformationEntity>().in(di::singleton),
              di::bind<ISubscribtionManager>.to<SubscribtionManager>()
          ));
    };
}
}

#endif /* INMEMORYBUS_SUBSCRIBTIONS_SUBSCRIBERSMODULE_H_ */
