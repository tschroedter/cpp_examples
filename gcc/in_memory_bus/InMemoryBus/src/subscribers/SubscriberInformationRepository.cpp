/*
 * SubscriptionsRepository.cpp
 *
 *  Created on: 3Jul.,2017
 *      Author: tom
 */

#include <string>
#include <memory>
#include "SubscriberInformation.h"
#include "SubscriberInformationRepository.h"

namespace InMemoryBus
{

    SubscriberInformationRepository::SubscriberInformationRepository(
            SubscriberInformationVector_SPtr informations)
    {
        m_informations = informations;

        m_unknown = std::make_shared<UnknownSubscriberInformation>();
    }

    SubscriberInformationRepository::~SubscriberInformationRepository()
    {
    }

    SubscriberInformationVector_SPtr SubscriberInformationRepository::getAll()
    {
        SubscriberInformationVector* p_vector = new SubscriberInformationVector();

        for (auto iter = m_informations->begin(); iter != m_informations->end();
                iter++)
        {
            SubscriberInformation_SPtr info = (*iter);

            p_vector->push_back(info);
        }

        auto all = std::shared_ptr<SubscriberInformationVector>(p_vector);

        return (all);
    }

    int SubscriberInformationRepository::findIndexBySubscriberId(
            const std::string& subscriber_id)
    {
        int indexToFind = -1;
        int currentIndex = 0;

        for (auto iter = m_informations->begin(); iter != m_informations->end();
                iter++)
        {
            SubscriberInformation_SPtr info = (*iter);
            std::string id = info->subscriber_id;
            if (id.compare(subscriber_id) == 0)
            {
                indexToFind = currentIndex;
                break;
            }
            currentIndex++;
        }

        return (indexToFind);
    }

    SubscriberInformation_SPtr SubscriberInformationRepository::findBySubscriberId(
            const std::string subscriber_id)
    {
        int indexToFind = findIndexBySubscriberId(subscriber_id);

        if (indexToFind > -1)
        {
            return (m_informations->at(indexToFind));
        }

        return (m_unknown);
    }

    void SubscriberInformationRepository::remove(
            const SubscriberInformation_SPtr information)
    {
        int index = this->findIndexBySubscriberId(information->subscriber_id);

        if (index >= 0)
        {
            m_informations->erase(m_informations->begin() + index);
        }
    }

    void SubscriberInformationRepository::add(
            const SubscriberInformation_SPtr information)
    {
        m_informations->push_back(information);
    }

} /* namespace InMemoryBus */
