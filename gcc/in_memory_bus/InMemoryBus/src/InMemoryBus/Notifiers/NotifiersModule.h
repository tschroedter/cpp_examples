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
#include "MessageBusNotifierFactory.h"
#include "IMessageBusNotifierFactory.h"
#include "NotifierThreadPool.h"
#include "INotifierThreadPool.h"
#include "SubscibersNotifier.h"
#include "ISubscibersNotifier.h"
#include "SubscriberFunctionCaller.h"
#include "ISubscriberFunctionCaller.h"
#include "MessageBusNotifierFactory.h"
#include "IMessageBusNotifierFactory.h"
#include "SubscibersNotifierFactory.h"
#include "ISubscibersNotifierFactory.h"
#include "Failed/FailedToNotify.h"
#include "Failed/IFailedToNotify.h"
#include "Failed/FailedToNotifyQueue.h"
#include "Failed/IFailedToNotifyQueue.h"
#include "Failed/FailedToNotifyManager.h"
#include "Failed/IFailedToNotifyManager.h"
#include "Failed/ThreadSafe/ThreadSafeFailedToNotifyQueue.h"
#include "Failed/ThreadSafe/IThreadSafeFailedToNotifyQueue.h"
#include "Failed/FailedMessageBusNotifier.h"
#include "Failed/IFailedMessageBusNotifier.h"
#include "Failed/FailedSubscriberFunctionCaller.h"
#include "Failed/IFailedSubscriberFunctionCaller.h"
#include "Failed/FailedMessageQueueProcessor.h"
#include "Failed/IFailedMessageQueueProcessor.h"
#include "../Common/IFactory.h"

namespace di = boost::di;

namespace InMemoryBus {
namespace Notifiers {
auto notifiers_module =
    []
    {
      return (di::make_injector(
              di::bind<IMessageBusNotifierFactory>.to<MessageBusNotifierFactory>(),
              di::bind<ISubscibersNotifierFactory>.to<SubscibersNotifierFactory>(),
              di::bind<IMessageBusNotifier>.to<MessageBusNotifier>(),
              di::bind<INotifierThreadPool>.to<NotifierThreadPool>(),
              di::bind<ISubscibersNotifier>.to<SubscibersNotifier>(),
              di::bind<ISubscriberFunctionCaller>.to<SubscriberFunctionCaller>(),
              di::bind<Failed::IFailedMessageBusNotifier>.to<Failed::FailedMessageBusNotifier>(),
              di::bind<Failed::IFailedSubscriberFunctionCaller>.to<Failed::FailedSubscriberFunctionCaller>(),
              di::bind<Failed::IFailedToNotify>.to<Failed::FailedToNotify>(),
              di::bind<Failed::IFailedToNotifyQueue>.to<Failed::FailedToNotifyQueue>(),
              di::bind<Failed::IFailedToNotifyManager>.to<Failed::FailedToNotifyManager>(),
              di::bind<Failed::IFailedMessageQueueProcessor>.to<Failed::FailedMessageQueueProcessor>(),
              di::bind<Failed::ThreadSafe::IThreadSafeFailedToNotifyQueue>.to<Failed::ThreadSafe::ThreadSafeFailedToNotifyQueue>().in(di::singleton),

              di::bind<ifactory
              <IMessageBusNotifier>>()
              .to(factory<MessageBusNotifier> {})
          ));
    };
}
}

#endif /* INMEMORY_NOTIFIERS_NOTIFIERSMODULE_H_ */
