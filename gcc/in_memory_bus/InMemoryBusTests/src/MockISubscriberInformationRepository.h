/*
 * SubscriberInformationRepositoryMock.h
 *
 *  Created on: 26 Oct. 2017
 *      Author: tom
 */

#ifndef MESSAGES_MOCKSUBSCRIBERINFORMATIONREPOSITORY_H_
#define MESSAGES_MOCKSUBSCRIBERINFORMATIONREPOSITORY_H_

#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "subscribers/ISubscriberInformationRepository.h"

namespace InMemoryBus
{

    class MockISubscriberInformationRepository
    : public ISubscriberInformationRepository
    {
        public:
            MOCK_METHOD0(getAll, InMemoryBus::SubscriberInformationVector_SPtr());
            MOCK_METHOD1(findBySubscriberId, InMemoryBus::SubscriberInformation_SPtr(const std::string& subscriber_id));
            MOCK_METHOD1(remove, void(const InMemoryBus::SubscriberInformation_SPtr information));
            MOCK_METHOD1(add, void(const InMemoryBus::SubscriberInformation_SPtr information));
            MOCK_METHOD0(size, size_t());
    };
    

} /* namespace InMemoryBus */

#endif /* MESSAGES_MOCKSUBSCRIBERINFORMATIONREPOSITORY_H_ */
