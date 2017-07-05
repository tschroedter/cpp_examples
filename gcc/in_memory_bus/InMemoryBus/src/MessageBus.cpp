/*
 * MessageBus.cpp
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#include <functional>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include "MessageBus.h"
#include "subscribers/SubscriberInformation.h"
#include "Typedefs.h"

namespace InMemoryBus
{

    MessageBus::MessageBus(Subscribers* subscribers, Messages* messages)
    {
        m_subsribers = subscribers;
        m_messages = messages;
    }

    MessageBus::~MessageBus()
    {
    }

    void MessageBus::subscribe(
            std::string subscriber_id,
            SubscriberFunction messageReceiver)
    {
        SubscriberInformation_Ptr info =
                new SubscriberInformation(
                        subscriber_id,
                        messageReceiver);

        m_subsribers->push_back(info);
    }

    void MessageBus::unsubscribe(
            std::string subscriber_id)
    {
        int indexToBeRemoved = -1;
        int currentIndex = 0;

        for (auto iter = m_subsribers->begin(); iter != m_subsribers->end(); iter++)
        {
            SubscriberInformation_Ptr info = (*iter);
            std::string id = info->subscriber_id;

            if (id.compare(subscriber_id) == 0)
            {
                indexToBeRemoved = currentIndex;
                break;
            }

            currentIndex++;
        }

        if (indexToBeRemoved > -1)
        {
            SubscriberInformation_Ptr toBeFreed = m_subsribers->at(indexToBeRemoved);
            m_subsribers->erase(m_subsribers->begin() + indexToBeRemoved);
            delete toBeFreed;
        }
    }

    void MessageBus::publish(BaseMessage* p_message)
    {
        m_messages->push(p_message);
    }

    void MessageBus::notify()
    {
        while (!m_messages->empty())
        {
            for (auto iter = m_subsribers->begin(); iter != m_subsribers->end(); iter++)
            {
                SubscriberInformation_Ptr info = (*iter);
                SubscriberFunction func = info->function;

                auto p_message = m_messages->front();

                func(p_message);
            }

            m_messages->pop();
        }
    }
} /* namespace InMemoryBus */
