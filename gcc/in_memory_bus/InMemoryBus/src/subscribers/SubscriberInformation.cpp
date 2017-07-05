/*
 * SubscriberInformation.cpp
 *
 *  Created on: 17Jun.,2017
 *      Author: tom
 */

#include "SubscriberInformation.h"

namespace InMemoryBus
{

    SubscriberInformation::SubscriberInformation(
            const std::string id,
            const SubscriberFunction subscriberFunction)
    : subscriber_id(id), function(subscriberFunction)
    {
    }

    SubscriberInformation::~SubscriberInformation()
    {
    }

    bool operator<(
            const SubscriberInformation& one,
            const SubscriberInformation& two)
    {
            return (one.subscriber_id < two.subscriber_id);
    }

} /* namespace InMemoryBus */
