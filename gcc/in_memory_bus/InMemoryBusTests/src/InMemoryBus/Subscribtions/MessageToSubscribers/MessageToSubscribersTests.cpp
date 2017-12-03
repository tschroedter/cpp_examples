/*
 * MessageToSubscribersTests.cpp
 *
 *  Created on: 26 Oct. 2017
 *      Author: tom
 */

#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "InMemoryBus/Subscribtions/Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"
#include "InMemoryBus/MessageBus.h"
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "InMemoryBus/Subscribtions/MessageToSubscribers/MessageToSubscribersEntity.h"
#include "../../MockIThreadSafeSubscriberInformationRepository.h"

namespace InMemoryBusTests {
using namespace InMemoryBus::Subscribtions::MessageToSubscribers;

void expect_std_strings_are_equal(const std::string & expected, const std::string & actual);

TEST(MessageToSubscribersTest, constructor_sets_message_type) {
  // Arrange
  std::string expected("message_type");

  MockIThreadSafeSubscriberInformationRepository* p_repo = new MockIThreadSafeSubscriberInformationRepository { };
  IThreadSafeSubscriberInformationRepository_SPtr subscribers(p_repo);

  // Act
  MessageToSubscribersEntity sut { expected, subscribers };

  // Assert
  EXPECT_EQ(0, expected.compare(sut.get_message_type()));
}

TEST(MessageToSubscribersTest, constructor_sets_subscribers) {
  // Arrange
  std::string expected("message_type");

  MockIThreadSafeSubscriberInformationRepository* p_repository = new MockIThreadSafeSubscriberInformationRepository { };
  IThreadSafeSubscriberInformationRepository_SPtr repository(p_repository);

  // Act
  MessageToSubscribersEntity sut { expected, repository };

  // Assert
  EXPECT_EQ(repository, sut.get_repository());
}

TEST(MessageToSubscribersTest, operatorLess_returns_false_for_b_less_a) {
  using namespace InMemoryBus;

  // Arrange
  MockIThreadSafeSubscriberInformationRepository* p_repo = new MockIThreadSafeSubscriberInformationRepository { };
  IThreadSafeSubscriberInformationRepository_SPtr subscribers(p_repo);
  MessageToSubscribersEntity a { "a", subscribers };
  MessageToSubscribersEntity b { "b", subscribers };

  // Act
  // Assert
  EXPECT_FALSE(b < a);
}

TEST(MessageToSubscribersTest, operatorLess_returns_false_for_a_less_a) {
  // Arrange
  MockIThreadSafeSubscriberInformationRepository* p_repo = new MockIThreadSafeSubscriberInformationRepository { };
  IThreadSafeSubscriberInformationRepository_SPtr subscribers(p_repo);
  MessageToSubscribersEntity a { "a", subscribers };
  MessageToSubscribersEntity b { "b", subscribers };

  // Act
  // Assert
  EXPECT_FALSE(a < a);
}

TEST(MessageToSubscribersTest, operatorLess_returns_true_for_a_less_b) {
  // Arrange
  MockIThreadSafeSubscriberInformationRepository* p_repo = new MockIThreadSafeSubscriberInformationRepository { };
  IThreadSafeSubscriberInformationRepository_SPtr subscribers(p_repo);
  MessageToSubscribersEntity a { "a", subscribers };
  MessageToSubscribersEntity b { "b", subscribers };

  // Act
  // Assert
  EXPECT_TRUE(a < b);
}

TEST(MessageToSubscribersTest, constructor_throws_for_message_type_is_empty) {
  try {
    MockIThreadSafeSubscriberInformationRepository* p_repo = new MockIThreadSafeSubscriberInformationRepository { };
    IThreadSafeSubscriberInformationRepository_SPtr subscribers(p_repo);
    MessageToSubscribersEntity a { "", subscribers };

    FAIL()<< "Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'message_type' is invalid! Can't create MessageToSubscribers because 'message_type' is empty!");

    expect_std_strings_are_equal(expected, actual);
  }
}

TEST(MessageToSubscribersTest, constructor_throws_for_subscribers_is_null) {
  try {
    MessageToSubscribersEntity sut { "type", nullptr };

    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'subscribers' is invalid! Can't create MessageToSubscribers because 'subscribers' is null!");

    expect_std_strings_are_equal(expected, actual);
  }
}

}
/* namespace InMemoryBus */
