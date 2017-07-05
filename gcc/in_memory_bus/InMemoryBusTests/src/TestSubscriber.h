/*
 * TestSubscriber.h
 *
 *  Created on: 16Jun.,2017
 *      Author: tom
 */

#ifndef TESTSUBSCRIBER_H_
#define TESTSUBSCRIBER_H_

#include "Message.h"
#include "subscribers/SubscriberInformation.h"
#include "Typedefs.h"

namespace InMemoryBusTests
{

    class TestSubscriber
    {
        public:
            TestSubscriber();
            virtual ~TestSubscriber();

            InMemoryBus::SubscriberFunction getNotifyFunc();
            void onNotify(Message* p_message);

            bool wasCalledOnNotify();
            Message* m_received_message;

        private:
            Message m_no_message_received
            { "No Message Received" };
    };

} /* namespace InMemoryBus */

#endif /* TESTSUBSCRIBER_H_ */
