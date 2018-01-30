/*
 * CommonModule.h
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_COMMON_COMMONMODULE_H_
#define INMEMORYBUS_COMMON_COMMONMODULE_H_

#include <boost/di.hpp>
#include "Logger.h"
#include "ILogger.h"
#include "MessageBusSynchronization.h"
#include "MessagesQueue.h"
#include "IMessagesQueue.h"
#include "ThreadInformationProvider.h"
#include "Interfaces/IThreadInformationProvider.h"

namespace InMemoryBus {
namespace Common {

namespace di = boost::di;

auto common_module = []
{
  return (di::make_injector(
          di::bind<ILogger>.to<Logger>(),
          di::bind<Interfaces::IThreadInformationProvider>.to<ThreadInformationProvider>(),
          di::bind<InMemoryBus::Common::IMessagesQueue>.to<InMemoryBus::Common::MessagesQueue>().in(di::singleton),
          di::bind<InMemoryBus::Common::MessageBusSynchronization>().in(di::singleton)
      ));
};

}
}

#endif /* INMEMORYBUS_COMMON_COMMONMODULE_H_ */
