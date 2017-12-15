/*
 * Installer.h
 *
 *  Created on: 27 Nov. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUSMODULE_H_
#define INMEMORYBUSMODULE_H_

#include <boost/di.hpp>
#include "Common/CommonModule.h"
#include "Subscribtions/MessageToSubscribers/MessageToSubscribersModule.h"
#include "Notifiers/NotifiersModule.h"
#include "Publishers/PublishersModule.h"
#include "Subscribtions/SubscribtionsModule.h"
#include "Subscribtions/MessageToSubscribers/MessageToSubscribersModule.h"
#include "IBus.h"
#include "MessageBus.h"

namespace di = boost::di;

namespace InMemoryBus {
auto inmemorybus_module = []
{
  return (di::make_injector(
          InMemoryBus::Common::common_module(),
          InMemoryBus::Subscribtions::MessageToSubscribers::message_to_subscribers_module(),
          InMemoryBus::Notifiers::notifiers_module(),
          InMemoryBus::Publishers::publishers_module(),
          InMemoryBus::Subscribtions::subscribtions_module(),
          di::bind<InMemoryBus::IBus>.to<InMemoryBus::MessageBus>()
      ));
};
}

#endif /* INMEMORYBUSMODULE_H_ */
