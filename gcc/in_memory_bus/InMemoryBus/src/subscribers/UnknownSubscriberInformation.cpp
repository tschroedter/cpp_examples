/*
 * UnknownSubscriberInformation.cpp
 *
 *  Created on: 4Jul.,2017
 *      Author: tom
 */

#include "UnknownSubscriberInformation.h"

namespace InMemoryBus
{

    UnknownSubscriberInformation::UnknownSubscriberInformation() :
            SubscriberInformation("Unknown", getNotifyFunc())
    {
    }

    UnknownSubscriberInformation::~UnknownSubscriberInformation()
    {
    }

    InMemoryBus::SubscriberFunction UnknownSubscriberInformation::getNotifyFunc()
    {
        auto messageListener = [=](InMemoryBus::BaseMessage* p_message) -> void
        {
            this->onNotify(p_message);
        };
        return (messageListener);
    }

    void UnknownSubscriberInformation::onNotify(BaseMessage* p_message)
    {
        // todo log that instance did nothing
    }
} /* namespace InMemoryBus */
