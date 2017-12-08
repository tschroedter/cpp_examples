/*
 * MockIThreadSafeSubscriberInformationRepository.h
 *
 *  Created on: 4 Dec. 2017
 *      Author: tom
 */

#ifndef INMEMORYBUS_MOCKITHREADSAFESUBSCRIBERINFORMATIONREPOSITORY_H_
#define INMEMORYBUS_MOCKITHREADSAFESUBSCRIBERINFORMATIONREPOSITORY_H_

#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "InMemoryBus/Subscribtions/Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"

namespace InMemoryBusTests {

class MockIThreadSafeSubscriberInformationRepository :
    public InMemoryBus::Subscribtions::Subscribers::ThreadSafe::IThreadSafeSubscriberInformationRepository {
 public:
  MOCK_METHOD0(get_all_subscribers, ISubscriberInformationEntityVector_SPtr());
  MOCK_METHOD1(find_subscriber_by_id, ISubscriberInformationEntity_SPtr(const std::string& subscriber_id));
  MOCK_METHOD1(remove, void(const ISubscriberInformationEntity_SPtr information));
  MOCK_METHOD1(add, void(const ISubscriberInformationEntity_SPtr information));
  MOCK_METHOD0(size, size_t());
};

}

#endif /* INMEMORYBUS_MOCKITHREADSAFESUBSCRIBERINFORMATIONREPOSITORY_H_ */
