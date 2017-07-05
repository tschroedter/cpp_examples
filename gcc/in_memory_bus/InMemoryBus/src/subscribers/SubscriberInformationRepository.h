/*
 * SubscriptionsRepository.h
 *
 *  Created on: 3Jul.,2017
 *      Author: tom
 */

#ifndef SUBSCRIBERS_SUBSCRIBERINFORMATIONREPOSITORY_H_
#define SUBSCRIBERS_SUBSCRIBERINFORMATIONREPOSITORY_H_

#include <string>
#include <memory>
#include "SubscriberInformation.h"
#include "UnknownSubscriberInformation.h"

namespace InMemoryBus
{

    class SubscriberInformationRepository
    {
        public:
            SubscriberInformationRepository(SubscriberInformationVector_SPtr subscribers);
            virtual ~SubscriberInformationRepository();

            SubscriberInformationVector_SPtr getAll();
            SubscriberInformation_SPtr findBySubscriberId(const std::string subscriber_id);
            void remove(const SubscriberInformation_SPtr information);
            void add(const SubscriberInformation_SPtr information);

        private:
            SubscriberInformationVector_SPtr m_informations;
            int findIndexBySubscriberId(const std::string& subscriber_id);
            SubscriberInformation_SPtr m_unknown;
    };

} /* namespace InMemoryBus */

#endif /* SUBSCRIBERS_SUBSCRIBERINFORMATIONREPOSITORY_H_ */
