/*
 * ComponentA.h
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#ifndef COMPONENTA_H_
#define COMPONENTA_H_

#include "BusNode.h"
#include "MessageBus.h"
#include "BaseMessage.h"

namespace InMemoryBusExample
{

    class ComponentA: public InMemoryBus::BusNode
    {
        public:
            ComponentA(InMemoryBus::MessageBus* messageBus);
            virtual ~ComponentA();

        protected:
            void onNotify(InMemoryBus::BaseMessage* p_base_message) override;
    };

} /* namespace InMemoryBus */

#endif /* COMPONENTA_H_ */
