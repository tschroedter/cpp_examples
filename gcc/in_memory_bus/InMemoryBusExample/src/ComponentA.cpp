/*
 * ComponentA.cpp
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#include <iostream>
#include "ComponentA.h"
#include "BusNode.h"
#include "BaseMessage.h"
#include "Message.h"

namespace InMemoryBusExample
{

    ComponentA::ComponentA(InMemoryBus::MessageBus* messageBus) :
            InMemoryBus::BusNode("ComponentA", "Message", messageBus)
    {
    }

    ComponentA::~ComponentA()
    {
    }

    void ComponentA::onNotify(InMemoryBus::BaseMessage* p_base_message)
    {
        auto p_message = dynamic_cast<Message*>(p_base_message);

        std::cout << "[ComponentA] I received: " << p_message->getEvent()
                << std::endl;
    }
} /* namespace InMemoryBus */
