/*
 * IVector.h
 *
 *  Created on: 14Jun.,2017
 *      Author: tom
 */

#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

#include <memory>
#include <functional>
#include "BaseMessage.h"

namespace InMemoryBus {

typedef std::function<void(BaseMessage_SPtr)> SubscriberFunction;

} /* namespace InMemoryBus */

#endif /* TYPEDEFS_H_ */
