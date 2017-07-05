/*
 * TestSubscriber.cpp
 *
 *  Created on: 16Jun.,2017
 *      Author: tom
 */

#include <string>
#include "BaseMessage.h"
#include "Message.h"
#include "Typedefs.h"
#include "TestSubscriber.h"

namespace InMemoryBusTests
{

    TestSubscriber::TestSubscriber()
    {
        m_received_message = &m_no_message_received;
    }

    TestSubscriber::~TestSubscriber()
    {
    }

    InMemoryBus::SubscriberFunction TestSubscriber::getNotifyFunc()
    {
        auto messageListener = [=](InMemoryBus::BaseMessage* p_message) -> void
        {
            this->onNotify(dynamic_cast<Message*>(p_message));
        };
        return (messageListener);
    }

    void TestSubscriber::onNotify(Message* p_message)
    {
        m_received_message = p_message;
    }

    bool TestSubscriber::wasCalledOnNotify()
    {
        if (m_received_message->getEvent() != "No Message Received")
        {
            return (true);
        }

        return (false);
    }

} /* namespace InMemoryBus */
