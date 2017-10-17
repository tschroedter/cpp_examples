/*
 * NewSubscriberInformation.h
 *
 *  Created on: 29 Aug. 2017
 *      Author: tom
 */

#ifndef SUBSCRIBERS_SUBSCRIBERINFORMATIONREPOSITORY_H_
#define SUBSCRIBERS_SUBSCRIBERINFORMATIONREPOSITORY_H_

#include "SubscriberInformationRepository.h"

#include <string>
#include <memory>
#include "../BaseRepository.h"
#include "SubscriberInformation.h"
#include "UnknownSubscriberInformation.h"

namespace InMemoryBus
{

    class SubscriberInformationRepository
    {
        public:
            SubscriberInformationRepository(
                    SubscriberInformationVector_SPtr informations);
            ~SubscriberInformationRepository();

            SubscriberInformationVector_SPtr getAll();
            SubscriberInformation_SPtr findBySubscriberId(
                    const std::string& subscriber_id);
            void remove(const SubscriberInformation_SPtr information);
            void add(const SubscriberInformation_SPtr information);
            size_t size(); // todo testing

        private:
            std::shared_ptr<BaseRepository<SubscriberInformation>> m_informations;
            std::shared_ptr<UnknownSubscriberInformation> m_unknown;
    };

    typedef std::shared_ptr<SubscriberInformationRepository> SubscriberInformationRepository_SPtr;

} /* namespace InMemoryBus */

#endif /* SUBSCRIBERS_SUBSCRIBERINFORMATIONREPOSITORY_H_ */
