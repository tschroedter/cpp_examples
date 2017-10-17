/*
 * ComponentOtherB.h
 *
 *  Created on: 4 Oct. 2017
 *      Author: tom
 */

#ifndef COMPONENTOTHERA_H_
#define COMPONENTOTHERA_H_

#include "BusNode.h"
#include "MessageBus.h"
#include "BaseMessage.h"

namespace InMemoryBusExample
{

    class ComponentOtherA: public InMemoryBus::BusNode
    {
        public:
            ComponentOtherA(InMemoryBus::MessageBus* messageBus);
            virtual ~ComponentOtherA();

        protected:
            void onNotify(InMemoryBus::BaseMessage* p_base_message) override;
    };

} /* namespace InMemoryBus */

#endif /* COMPONENTOTHERA_H_ */
