/*
 * ComponentOtherB.cpp
 *
 *  Created on: 4 Oct. 2017
 *      Author: tom
 */

#include <iostream>
#include "ComponentA.h"
#include "BusNode.h"
#include "BaseMessage.h"
#include "OtherMessage.h"
#include "ComponentOtherA.h"

namespace InMemoryBusExample
{

    ComponentOtherA::ComponentOtherA(InMemoryBus::MessageBus* messageBus) :
            InMemoryBus::BusNode("ComponentOtherA", "OtherMessage", messageBus)
    {
    }

    ComponentOtherA::~ComponentOtherA()
    {
    }

    void ComponentOtherA::onNotify(InMemoryBus::BaseMessage* p_base_message)
    {
        auto p_message = dynamic_cast<OtherMessage*>(p_base_message);

        std::cout << "[ComponentOtherA] I received: " << p_message->getType()
                << std::endl;
    }
} /* namespace InMemoryBus */
