/*
 * IVector.h
 *
 *  Created on: 14Jun.,2017
 *      Author: tom
 */

#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

#include <queue>
#include <functional>
#include <vector>
#include "BaseMessage.h"

namespace InMemoryBus
{

    typedef std::queue<BaseMessage*> Messages;
    typedef std::function<void(BaseMessage*)> SubscriberFunction;

} /* namespace InMemoryBus */

#endif /* TYPEDEFS_H_ */
