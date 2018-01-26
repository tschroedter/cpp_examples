/*
 * IVector.h
 *
 *  Created on: 14Jun.,2017
 *      Author: tom
 */

#ifndef SRC_INMEMORYBUS_COMMON_SUBSCRIBERFUNCTION_H_
#define SRC_INMEMORYBUS_COMMON_SUBSCRIBERFUNCTION_H_

#include <memory>
#include <functional>
#include "BaseMessage.h"

namespace InMemoryBus {
namespace Common {

typedef std::function<void(BaseMessage_SPtr)> SubscriberFunction;   // Todo maybe move typedef out of namespace

}
}

#endif /* SRC_INMEMORYBUS_COMMON_SUBSCRIBERFUNCTION_H_ */
