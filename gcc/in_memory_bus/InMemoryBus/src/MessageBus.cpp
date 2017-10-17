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
#include "subscribers/SubscriberInformationRepository.h"
#include "Typedefs.h"

namespace InMemoryBus
{

    MessageBus::MessageBus(SubscriberInformationRepository_SPtr subscribers,
            Messages* messages)
    {
        m_subscribers = subscribers;
        m_messages = messages;
    }

    MessageBus::~MessageBus()
    {
    }

    void MessageBus::subscribe(std::string subscriber_id,
            std::string message_type, SubscriberFunction messageReceiver)
    {
        SubscriberInformation_SPtr info =
                std::make_shared<SubscriberInformation>(subscriber_id,
                        message_type, messageReceiver);

        m_subscribers->add(info);
    }

    void MessageBus::unsubscribe(std::string subscriber_id,
            std::string message_type)
    {
        SubscriberInformation_SPtr info = m_subscribers->findBySubscriberId(
                subscriber_id);

        if (info == nullptr)
        {
            return;
        }

        if (message_type.compare(info->message_type) != 0)
        {
            return; // todo testing
        }

        m_subscribers->remove(info);
    }

    void MessageBus::publish(BaseMessage* p_message)
    {
        m_messages->push(p_message);
    }

    void MessageBus::notify()
    {
        // todo notify only subscribers to message, one repository for all or repo per message type
        SubscriberInformationVector_SPtr infos = m_subscribers->getAll();

        while (!m_messages->empty())
        {
            for (auto iter = infos->begin(); iter != infos->end(); iter++)
            {
                auto p_message = m_messages->front();
                SubscriberInformation_SPtr info = (*iter);

                auto message_type = p_message->getType();

                if (message_type.compare(info->message_type) != 0)
                {
                    continue;
                }

                SubscriberFunction func = info->subscriber_function;

                func(p_message);
            }

            m_messages->pop();
        }
    }
} /* namespace InMemoryBus */
