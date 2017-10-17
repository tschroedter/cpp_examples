/*
 * OtherMessage.cpp
 *
 *  Created on: 22 Aug. 2017
 *      Author: tom
 */

#include "OtherMessage.h"

namespace InMemoryBusExample
{

    OtherMessage::OtherMessage() :
            InMemoryBus::BaseMessage("OtherMessage")
    {
    }

    OtherMessage::~OtherMessage()
    {
    }

} /* namespace InMemoryBus */
