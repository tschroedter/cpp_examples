/*
 * ComponentB.cpp
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#include <iostream>
#include "ComponentB.h"
#include "MessageBus.h"
#include "BaseMessage.h"
#include "Message.h"

namespace InMemoryBusExample
{

    ComponentB::ComponentB(InMemoryBus::MessageBus* messageBus) :
            InMemoryBus::BusNode("ComponentB", messageBus)
    {
    }
    ComponentB::~ComponentB()
    {
    }

    void ComponentB::update()
    {
        Message* p_greeting = new Message("Hello"); // todo memory leak
        send(p_greeting);
    }

    void ComponentB::onNotify(InMemoryBus::BaseMessage* p_base_message)
    {
        auto p_message = dynamic_cast<Message*>(p_base_message);

        std::cout << "[ComponentB] I received: " << p_message->getEvent()
                << std::endl;
    }

} /* namespace InMemoryBus */
