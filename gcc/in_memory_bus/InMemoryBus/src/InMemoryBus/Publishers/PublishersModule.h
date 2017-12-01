/*
 * PublishersModule.h
 *
 *  Created on: 29 Nov. 2017
 *      Author: tom
 */

#ifndef INMEMORY_PUBLISHERS_PUBLISHERSMODULE_H_
#define INMEMORY_PUBLISHERS_PUBLISHERSMODULE_H_

#include <boost/di.hpp>
#include "MessageBusPublisher.h"
#include "IMessageBusPublisher.h"

namespace di = boost::di;

namespace InMemoryBus {
namespace Publishers {
auto publishers_module = []
{
  return (di::make_injector(
          di::bind<IMessageBusPublisher>.to<MessageBusPublisher>().in(di::unique)
      ));
};
}
}

#endif /* INMEMORY_PUBLISHERS_PUBLISHERSMODULE_H_ */
