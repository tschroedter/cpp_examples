/*
 * MessageToSubscribersModule.h
 *
 *  Created on: 30 Nov. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_MESSAGETOSUBSCRIBERSMODULE_H_
#define INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_MESSAGETOSUBSCRIBERSMODULE_H_

#include <boost/di.hpp>
#include "MessageToSubscribersEntity.h"
#include "IMessageToSubscribersEntity.h"
#include "MessageToSubscribersRepository.h"
#include "IMessageToSubscribersRepository.h"

namespace di = boost::di;

namespace InMemoryBus {
namespace Subscribtions {
namespace MessageToSubscribers {
auto message_to_subscribers_module = []
{
  return (di::make_injector(
          di::bind<IMessageToSubscribersEntity>.to<MessageToSubscribersEntity>(),
          di::bind<MessageToSubscribersRepository>.in(di::singleton),
          di::bind<IMessageToSubscribersRepository>.to<MessageToSubscribersRepository>().in(di::singleton)
      ));
};
}
}
}

#endif /* INMEMORYBUS_SUBSCRIBTIONS_MESSAGETOSUBSCRIBTIONS_MESSAGETOSUBSCRIBERSMODULE_H_ */
