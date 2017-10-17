/*
 * OtherMessage.h
 *
 *  Created on: 22 Aug. 2017
 *      Author: tom
 */

#ifndef OTHERMESSAGE_H_
#define OTHERMESSAGE_H_

#include <BaseMessage.h>

namespace InMemoryBusExample
{
    class OtherMessage: public InMemoryBus::BaseMessage
    {
        public:
            OtherMessage();
            ~OtherMessage();
    };

} /* namespace InMemoryBus */

#endif /* OTHERMESSAGE_H_ */
