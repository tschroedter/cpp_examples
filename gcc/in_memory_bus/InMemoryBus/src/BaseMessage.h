/*
 * BaseMessage.h
 *
 *  Created on: 23Jun.,2017
 *      Author: tom
 */

#ifndef BASEMESSAGE_H_
#define BASEMESSAGE_H_

#include <string>

namespace InMemoryBus
{

    class BaseMessage
    {
        private:
            std::string m_messageType;

        public:
            BaseMessage(const std::string messageType);
            virtual ~BaseMessage() = default;
            virtual std::string getType() const;
    };

} /* namespace InMemoryBus */

#endif /* BASEMESSAGE_H_ */
