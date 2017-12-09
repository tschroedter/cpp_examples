/*
 * SubscribtionManagerTests.cpp
 *
 *  Created on: 8 Dec. 2017
 *      Author: tom
 */

#include <iostream>
#include <gtest/gtest.h>
#include "../Common.h"
#include "../Common/TestSubscriber.h"
#include "../Mocks/MockIMessageToSubscribersRepository.h"
#include "../Mocks/MockIThreadSafeSubscriberInformationRepository.h"
#include "../Mocks/MockIMessageToSubscribersEntity.h"
#include "../Mocks/MockISubscriberInformationEntity.h"
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "InMemoryBus/Subscribtions/SubscribtionManager.h"
#include "InMemoryBus/Subscribtions/Subscribers/UnknownSubscriberInformationEntityEntity.h"

namespace InMemoryBusTests {

using namespace InMemoryBus::Subscribtions;

TEST(SubscribtionManagerTests, constructor_throws_for_repository_is_null) {
  try {
    // Arrange
    IMessageToSubscribersRepository_SPtr repository = nullptr;
    IUnknownSubscriberInformationEntity_SPtr unknown =
        std::make_shared<Subscribers::UnknownSubscriberInformationEntity>();

    // Act
    SubscribtionManager sut { repository, unknown };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'repository' is invalid! Can't create SubscribtionManager because 'repository' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(SubscribtionManagerTests, constructor_throws_for_unknown_is_null) {
  try {
    // Arrange
    IMessageToSubscribersRepository_SPtr repository = std::make_shared<MockIMessageToSubscribersRepository>();
    IUnknownSubscriberInformationEntity_SPtr unknown = nullptr;

    // Act
    SubscribtionManager sut { repository, unknown };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'unknown' is invalid! Can't create SubscribtionManager because 'unknown' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(SubscribtionManagerTests, remove_subscription_) {
  // Arrange
  ISubscriberInformationEntity_SPtr information = std::make_shared<MockISubscriberInformationEntity>();
  MockIMessageToSubscribersEntity* p_mock_entity = new MockIMessageToSubscribersEntity();
  IMessageToSubscribersEntity_SPtr entity { p_mock_entity };
  MockIThreadSafeSubscriberInformationRepository* p_mock_subscribers =
      new MockIThreadSafeSubscriberInformationRepository();
  IThreadSafeSubscriberInformationRepository_SPtr subscribers { p_mock_subscribers };
  MockIMessageToSubscribersRepository* p_mock_repository = new MockIMessageToSubscribersRepository();
  IMessageToSubscribersRepository_SPtr repository { p_mock_repository };
  IUnknownSubscriberInformationEntity_SPtr unknown =
      std::make_shared<Subscribers::UnknownSubscriberInformationEntity>();

  SubscribtionManager sut { repository, unknown };

  EXPECT_CALL(*p_mock_repository,
      find_subscriber_by_message_type("type")).Times(1).WillOnce(testing::Return(entity));
  EXPECT_CALL(*p_mock_entity,
      get_repository()).Times(1).WillOnce(testing::Return(subscribers));
  EXPECT_CALL(*p_mock_subscribers,
      find_subscriber_by_id("id")).Times(1).WillOnce(testing::Return(information));
  EXPECT_CALL(*p_mock_subscribers,
      remove(information)).Times(1);

  // Act
  sut.remove_subscription("id", "type");

  // Assert
}

TEST(SubscribtionManagerTests, add_subscription_adds_to_existing_subscription) {
  // Arrange
  TestSubscriber subscriber { };

  ISubscriberInformationEntity_SPtr information = std::make_shared<MockISubscriberInformationEntity>();
  MockIMessageToSubscribersEntity* p_mock_entity = new MockIMessageToSubscribersEntity();
  IMessageToSubscribersEntity_SPtr entity { p_mock_entity };
  MockIThreadSafeSubscriberInformationRepository* p_mock_subscribers =
      new MockIThreadSafeSubscriberInformationRepository();
  IThreadSafeSubscriberInformationRepository_SPtr subscribers { p_mock_subscribers };
  MockIMessageToSubscribersRepository* p_mock_repository = new MockIMessageToSubscribersRepository();
  IMessageToSubscribersRepository_SPtr repository { p_mock_repository };
  IUnknownSubscriberInformationEntity_SPtr unknown =
      std::make_shared<Subscribers::UnknownSubscriberInformationEntity>();

  SubscribtionManager sut { repository, unknown };

  EXPECT_CALL(*p_mock_repository,
      find_subscriber_by_message_type("type")).Times(1).WillOnce(testing::Return(entity));
  EXPECT_CALL(*p_mock_entity,
      get_repository()).Times(1).WillOnce(testing::Return(subscribers));
  EXPECT_CALL(*p_mock_entity,
      get_message_type()).Times(1).WillOnce(testing::Return("type"));
  EXPECT_CALL(*p_mock_subscribers,
      add(::testing::A<ISubscriberInformationEntity_SPtr>())).Times(1);  // TODO test for id, type, function

  // Act
  sut.add_subscription("id", "type", subscriber.getNotifyFunc());

  // Assert
}

TEST(SubscribtionManagerTests, get_repository_for_message_type_returns_repository) {
  // Arrange
  TestSubscriber subscriber { };

  MockIMessageToSubscribersEntity* p_mock_entity = new MockIMessageToSubscribersEntity();
  IMessageToSubscribersEntity_SPtr entity { p_mock_entity };
  IThreadSafeSubscriberInformationRepository_SPtr subscribers = std::make_shared<
      MockIThreadSafeSubscriberInformationRepository>();
  MockIMessageToSubscribersRepository* p_mock_repository = new MockIMessageToSubscribersRepository();
  IMessageToSubscribersRepository_SPtr repository { p_mock_repository };
  IUnknownSubscriberInformationEntity_SPtr unknown =
      std::make_shared<Subscribers::UnknownSubscriberInformationEntity>();

  SubscribtionManager sut { repository, unknown };

  EXPECT_CALL(*p_mock_repository,
      find_subscriber_by_message_type("type")).Times(1).WillOnce(testing::Return(entity));

  EXPECT_CALL(*p_mock_entity,
      get_repository()).Times(1).WillOnce(testing::Return(subscribers));

  // Act
  auto actual = sut.get_repository_for_message_type("type");

  // Assert
  EXPECT_EQ(subscribers, actual);
}

}
