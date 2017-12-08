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
#include "SubscibersNotifier.h"
#include "ISubscibersNotifier.h"
#include "SubscriberFunctionCaller.h"
#include "ISubscriberFunctionCaller.h"
#include "Failed/FailedToNotify.h"
#include "Failed/IFailedToNotify.h"
#include "Failed/FailedToNotifyQueue.h"
#include "Failed/IFailedToNotifyQueue.h"
#include "Failed/FailedToNotifyManager.h"
#include "Failed/IFailedToNotifyManager.h"

namespace di = boost::di;

namespace InMemoryBus {
namespace Notifiers {
auto notifiers_module = []
{
  return (di::make_injector(
          di::bind<IMessageBusNotifier>.to<MessageBusNotifier>(),
          di::bind<INotifierThreadPool>.to<NotifierThreadPool>(),
          di::bind<ISubscibersNotifier>.to<SubscibersNotifier>(),
          di::bind<ISubscriberFunctionCaller>.to<SubscriberFunctionCaller>(),
          di::bind<Failed::IFailedToNotify>.to<Failed::FailedToNotify>(),
          di::bind<Failed::IFailedToNotifyQueue>.to<Failed::FailedToNotifyQueue>(),
          di::bind<Failed::IFailedToNotifyManager>.to<Failed::FailedToNotifyManager>().in(di::singleton)
      ));
};
}
}

#endif /* INMEMORY_NOTIFIERS_NOTIFIERSMODULE_H_ */
