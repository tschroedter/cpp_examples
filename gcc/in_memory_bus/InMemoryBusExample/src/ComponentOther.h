/*
 * ComponentOther.h
 *
 *  Created on: 22 Aug. 2017
 *      Author: tom
 */

#ifndef COMPONENTOTHER_H_
#define COMPONENTOTHER_H_

#include "BusNode.h"
#include "MessageBus.h"

namespace InMemoryBusExample
{
    class ComponentOther: public InMemoryBus::BusNode
    {
        public:
            ComponentOther(InMemoryBus::MessageBus* messageBus);
            ~ComponentOther();

            void update();
    };

} /* namespace InMemoryBus */

#endif /* COMPONENTOTHER_H_ */
