/*
 * NewUnknownSubscriberInformation.h
 *
 *  Created on: 29 Aug. 2017
 *      Author: tom
 */

#ifndef SUBSCRIBERS_UNKNOWNSUBSCRIBERINFORMATION_H_
#define SUBSCRIBERS_UNKNOWNSUBSCRIBERINFORMATION_H_

#include "../BaseMessage.h"
#include "SubscriberInformation.h"

namespace InMemoryBus
{

    class UnknownSubscriberInformation: public SubscriberInformation
    {
        public:
            UnknownSubscriberInformation();
            virtual ~UnknownSubscriberInformation();

            InMemoryBus::SubscriberFunction getNotifyFunc();

        private:
            void onNotify(BaseMessage* p_message);

    };
/* namespace InMemoryBus */
}
#endif /* SUBSCRIBERS_UNKNOWNSUBSCRIBERINFORMATION_H_ */
