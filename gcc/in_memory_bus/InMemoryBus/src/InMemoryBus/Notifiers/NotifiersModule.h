/*
 * NotifiersModule.h
 *
 *  Created on: 29 Nov. 2017
 *      Author: tom
 */

#ifndef INMEMORY_NOTIFIERS_NOTIFIERSMODULE_H_
#define INMEMORY_NOTIFIERS_NOTIFIERSMODULE_H_

#include <boost/di.hpp>
#include "MessageBusNotifier.h"
#include "IMessageBusNotifier.h"
#include "NotifierThreadPool.h"
#include "INotifierThreadPool.h"

namespace di = boost::di;

namespace InMemoryBus {
namespace Notifiers {
auto notifiers_module = []
{
  return (di::make_injector(
          di::bind<IMessageBusNotifier>.to<MessageBusNotifier>(),
          di::bind<INotifierThreadPool>.to<NotifierThreadPool>()
      ));
};
}
}

#endif /* INMEMORY_NOTIFIERS_NOTIFIERSMODULE_H_ */
