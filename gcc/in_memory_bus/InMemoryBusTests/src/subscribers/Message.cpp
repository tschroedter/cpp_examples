/*
 * Message.cpp
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#include <string>
#include "InMemoryBus/BaseMessage.h"
#include "Message.h"

namespace InMemoryBusTests
{
    Message::Message(const std::string event) :
            InMemoryBus::BaseMessage("Message")
    {
        m_MessageEvent = event;
    }

    Message::~Message()
    {
    }

    std::string Message::getEvent()
    {
        return (m_MessageEvent);
    }
} /* namespace InMemoryBus */
