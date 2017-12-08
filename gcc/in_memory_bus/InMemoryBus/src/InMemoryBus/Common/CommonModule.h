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

namespace InMemoryBus {
namespace Common {

namespace di = boost::di;

auto common_module = []
{
  return (di::make_injector(
          di::bind<ILogger>.to<Logger>()
      ));
};

}
}

#endif /* INMEMORYBUS_COMMON_COMMONMODULE_H_ */
