/*
 * ThreadSafeSubscriberInformationRepositoryTests.cpp
 *
 *  Created on: 6 Dec. 2017
 *      Author: tom
 */

#include <memory>
#include <iostream>
#include <gtest/gtest.h>
#include "../../../Common.h"
#include "../../../Mocks/MockISubscriberInformationRepository.h"
#include "InMemoryBus/Common/BaseMessage.h"
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "InMemoryBus/Subscribtions/Subscribers/Threadsafe/ThreadSafeSubscriberInformationRepository.h"
#include "InMemoryBus/Subscribtions/Subscribers/SubscriberInformationEntity.h"
#include "InMemoryBus/Subscribtions/Subscribers/ISubscriberInformationRepository.h"

namespace InMemoryBusTests {

using namespace InMemoryBus::Subscribtions::Subscribers::ThreadSafe;

TEST(ThreadSafeSubscriberInformationRepositoryTests, constructor_throws_for_repository_is_nullptr) {
  try {
    // Arrange
    ISubscriberInformationRepository_SPtr repository = nullptr;

    // Act
    ThreadSafeSubscriberInformationRepository sut { repository };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'repository' is invalid! Can't create ThreadSafeSubscriberInformationRepository because 'repository' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(ThreadSafeSubscriberInformationRepositoryTests, get_all_subscribers_calls_repository) {
  // Arrange
  ISubscriberInformationEntityVector_SPtr vector = std::make_shared<ISubscriberInformationEntityVector>();
  MockISubscriberInformationRepository* p_mock_repository = new MockISubscriberInformationRepository();
  ISubscriberInformationRepository_SPtr repository { p_mock_repository };

  ThreadSafeSubscriberInformationRepository sut { repository };

  EXPECT_CALL(*p_mock_repository, get_all_subscribers()).Times(1).WillOnce(testing::Return(vector));

  // Act
  auto actual = sut.get_all_subscribers();

  // Assert
  EXPECT_EQ(vector, actual);
}

TEST(ThreadSafeSubscriberInformationRepositoryTests, find_subscriber_by_id_calls_repository) {
  // Arrange
  ISubscriberInformationEntity_SPtr entity { };
  MockISubscriberInformationRepository* p_mock_repository = new MockISubscriberInformationRepository();
  ISubscriberInformationRepository_SPtr repository { p_mock_repository };

  ThreadSafeSubscriberInformationRepository sut { repository };

  EXPECT_CALL(*p_mock_repository, find_subscriber_by_id("id")).Times(1).WillOnce(testing::Return(entity));

  // Act
  auto actual = sut.find_subscriber_by_id("id");

  // Assert
  EXPECT_EQ(entity, actual);
}

TEST(ThreadSafeSubscriberInformationRepositoryTests, remove_calls_repository) {
  // Arrange
  ISubscriberInformationEntity_SPtr entity { };
  MockISubscriberInformationRepository* p_mock_repository = new MockISubscriberInformationRepository();
  ISubscriberInformationRepository_SPtr repository { p_mock_repository };

  ThreadSafeSubscriberInformationRepository sut { repository };

  EXPECT_CALL(*p_mock_repository, remove(entity)).Times(1);

  // Act
  sut.remove(entity);

  // Assert
}

TEST(ThreadSafeSubscriberInformationRepositoryTests, add_calls_repository) {
  // Arrange
  ISubscriberInformationEntity_SPtr entity { };
  MockISubscriberInformationRepository* p_mock_repository = new MockISubscriberInformationRepository();
  ISubscriberInformationRepository_SPtr repository { p_mock_repository };

  ThreadSafeSubscriberInformationRepository sut { repository };

  EXPECT_CALL(*p_mock_repository, add(entity)).Times(1);

  // Act
  sut.add(entity);

  // Assert
}

TEST(ThreadSafeSubscriberInformationRepositoryTests, size_calls_repository) {
  // Arrange
  ISubscriberInformationEntity_SPtr entity { };
  MockISubscriberInformationRepository* p_mock_repository = new MockISubscriberInformationRepository();
  ISubscriberInformationRepository_SPtr repository { p_mock_repository };

  ThreadSafeSubscriberInformationRepository sut { repository };

  EXPECT_CALL(*p_mock_repository, size()).Times(1).WillOnce(testing::Return((size_t) 1));

  // Act
  auto actual = sut.size();

  // Assert
  EXPECT_EQ(1, actual);
}

}
