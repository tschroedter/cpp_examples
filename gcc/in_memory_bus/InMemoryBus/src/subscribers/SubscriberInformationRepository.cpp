/*
 * NewSubscriberInformationRepository.cpp
 *
 *  Created on: 29 Aug. 2017
 *      Author: tom
 */

#include <vector>
#include "uuid/uuid.h"
#include "SubscriberInformationRepository.h"

namespace InMemoryBus
{
    SubscriberInformationRepository::SubscriberInformationRepository(
            SubscriberInformationVector_SPtr informations)
    {
        m_informations =
                std::make_shared<BaseRepository<SubscriberInformation>>(
                        informations);

        m_unknown = std::make_shared<UnknownSubscriberInformation>();
    }

    SubscriberInformationRepository::~SubscriberInformationRepository()
    {
    }

    void SubscriberInformationRepository::add(
            const SubscriberInformation_SPtr entity)
    {
        m_informations->add(entity);
    }

    void SubscriberInformationRepository::remove(
            const SubscriberInformation_SPtr entity)
    {
        m_informations->remove(entity);
    }

    SubscriberInformationVector_SPtr SubscriberInformationRepository::getAll()
    {
        return (m_informations->getAll());
    }

    SubscriberInformation_SPtr SubscriberInformationRepository::findBySubscriberId(
            const std::string& subscriber_id)
    {
        auto all = m_informations->getAll();

        for (auto iter = all->begin(); iter != all->end(); iter++)
        {
            SubscriberInformation_SPtr info = (*iter);

            std::string id = info->subscriber_id;

            if (id.compare(subscriber_id) == 0)
            {
                return (info);
            }
        }

        return (m_unknown);
    }

    size_t SubscriberInformationRepository::size()
    {
        return m_informations->size();
    }
} /* namespace InMemoryBus */
