/*
 * InMemoryBusExampleModule.h
 *
 *  Created on: 2 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUSEXAMPLEMODULE_H_
#define INMEMORYBUSEXAMPLEMODULE_H_

#include <string>
#include <iostream>
#include "boost/di.hpp"
#include "InMemoryBus/Common/SubscriberFunction.h"
#include "InMemoryBus/InMemoryBusModule.h"

namespace InMemoryBusExample {

auto inmemorybusexample_module = []
{
  return (di::make_injector(
          InMemoryBus::inmemorybus_module()));
};

}

#endif /* INMEMORYBUSEXAMPLEMODULE_H_ */
