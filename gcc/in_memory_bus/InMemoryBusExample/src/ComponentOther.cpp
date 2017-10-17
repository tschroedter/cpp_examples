/*
 * ComponentOther.cpp
 *
 *  Created on: 22 Aug. 2017
 *      Author: tom
 */

#include <iostream>
#include "ComponentOther.h"
#include "OtherMessage.h"

namespace InMemoryBusExample
{
    ComponentOther::ComponentOther(InMemoryBus::MessageBus* messageBus) :
            InMemoryBus::BusNode("ComponentOtherA", "OtherMessage", messageBus)
    {
    }

    ComponentOther::~ComponentOther()
    {
    }

    void ComponentOther::update()
    {
        OtherMessage* message = new OtherMessage();

        for (int i = 0; i < 10; i++)
        {
            std::cout << "[ComponentOther] Sending OtherMessage...\n";

            send(message);
        }
    }
} /* namespace InMemoryBus */
