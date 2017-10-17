/*
 * NewSubscriberInformation.cpp
 *
 *  Created on: 17Jun.,2017
 *      Author: tom
 */

#include "SubscriberInformation.h"

#include "../exceptions/ArgumentInvalidException.h"

namespace InMemoryBus
{
    // todo use ApsectC++
    SubscriberInformation::SubscriberInformation(const std::string subscriber_id,
            const std::string message_type,
            const SubscriberFunction subscriber_function) :
            subscriber_id(subscriber_id), message_type(message_type), subscriber_function(
                    subscriber_function)
    {
        if (subscriber_id.empty())
        {
            throw ArgumentInvalidException("Can't create SubscriberInformation because 'subscriber_id' is empty!", "subscriber_id");
        }

        if (message_type.empty())
        {
            throw ArgumentInvalidException("Can't create SubscriberInformation because 'message_type' is empty!", "message_type");
        }

        if (subscriber_function == nullptr)
        {
            throw ArgumentInvalidException("Can't create SubscriberInformation because 'subscriber_function' is null!", "subscriberFunction");
        }
    }

    SubscriberInformation::~SubscriberInformation()
    {
    }

    bool operator<(const SubscriberInformation& one,
            const SubscriberInformation& two)
    {
        return (one.subscriber_id < two.subscriber_id);
    }

} /* namespace InMemoryBus */
