/*
 * ComponentB.h
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#ifndef COMPONENTB_H_
#define COMPONENTB_H_

#include "BusNode.h"
#include "MessageBus.h"
#include "BaseMessage.h"

namespace InMemoryBusExample
{

    class ComponentB: public InMemoryBus::BusNode
    {
        public:
            ComponentB(InMemoryBus::MessageBus* messageBus);
            virtual ~ComponentB();

            void update();

        private:
            void onNotify(InMemoryBus::BaseMessage* p_base_message) override;
    };

} /* namespace InMemoryBus */

#endif /* COMPONENTB_H_ */
