/*
 * BusNode.h
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#ifndef BUSNODE_H_
#define BUSNODE_H_

#include "MessageBus.h"

namespace InMemoryBus
{

    class BusNode
    {
        public:
            BusNode(std::string subscriber_id, std::string message_type,
                    MessageBus *messageBus);
            virtual ~BusNode();

            virtual void update();

        protected:
            MessageBus *messageBus;

            std::function<void(BaseMessage*)> getNotifyFunc();
            void send(BaseMessage* p_message);
            virtual void onNotify(BaseMessage* p_message);
    };
} /* namespace InMemoryBus */

#endif /* BUSNODE_H_ */
