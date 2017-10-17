/*
 * MessageBus.h
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#ifndef MESSAGEBUS_H_
#define MESSAGEBUS_H_

#include <functional>
#include <queue>
#include <vector>
#include <map>
#include "IBus.h"
#include "subscribers/SubscriberInformation.h"
#include "subscribers/SubscriberInformationRepository.h"
#include "Typedefs.h"

namespace InMemoryBus
{
    // TODO use newsubrepo!!!
    // typedef std::map<std::string, Subscribers*> MessagesToSubscribers;

    class MessageBus: public IBus
    {
        public:
            MessageBus(SubscriberInformationRepository_SPtr subscribers,
                    Messages* messages);
            virtual ~MessageBus();
            void subscribe(std::string subscriber_id, std::string message_type,
                    SubscriberFunction messageReceiver);
            void unsubscribe(std::string subscriber_id,
                    std::string message_type);
            void publish(BaseMessage* p_message);
            void notify();

        private:
            SubscriberInformationRepository_SPtr m_subscribers;
            Messages* m_messages;
            // MessagesToSubscribers m_messages_to_subscribers; // todo create mapping message to subscribers
    };

} /* namespace InMemoryBus */

#endif /* MESSAGEBUS_H_ */
