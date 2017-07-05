/*
 * UnknownSubscriberInformation.h
 *
 *  Created on: 4Jul.,2017
 *      Author: tom
 */

#ifndef UNKNOWNSUBSCRIBERINFORMATION_H_
#define UNKNOWNSUBSCRIBERINFORMATION_H_

#include "../BaseMessage.h"
#include "SubscriberInformation.h"

namespace InMemoryBus
{

    class UnknownSubscriberInformation  // todo testing
        : public SubscriberInformation
    {
        public:
            UnknownSubscriberInformation();
            virtual ~UnknownSubscriberInformation();

            InMemoryBus::SubscriberFunction getNotifyFunc();

        private:
            void onNotify(BaseMessage* p_message);
    };

} /* namespace InMemoryBus */

#endif /* UNKNOWNSUBSCRIBERINFORMATION_H_ */
