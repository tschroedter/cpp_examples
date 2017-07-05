/*
 * Message.h
 *
 *  Created on: 9Jun.,2017
 *      Author: tom
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>
#include "BaseMessage.h"

namespace InMemoryBusExample
{

    class Message: public InMemoryBus::BaseMessage
    {
        public:
            Message(const std::string event = "Unknown");
            virtual ~Message();
            std::string getEvent();
        private:
            std::string m_MessageEvent;
    };

} /* namespace InMemoryBus */

#endif /* MESSAGE_H_ */
