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
#include <InMemoryBus/Subscribtions/Subscribers/ISubscriberInformationRepository.h>

namespace InMemoryBusTests {

class MockISubscriberInformationRepository :
    public InMemoryBus::Subscribtions::Subscribers::ISubscriberInformationRepository {
 public:
  MOCK_METHOD0(get_all_subscribers, ISubscriberInformationEntityVector_SPtr());
  MOCK_METHOD1(find_subscriber_by_id, ISubscriberInformationEntity_SPtr(const std::string& subscriber_id));
  MOCK_METHOD1(remove, void(const ISubscriberInformationEntity_SPtr information));
  MOCK_METHOD1(add, void(const ISubscriberInformationEntity_SPtr information));
  MOCK_METHOD0(size, size_t());
};

}

#endif /* MESSAGES_MOCKSUBSCRIBERINFORMATIONREPOSITORY_H_ */
