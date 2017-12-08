/*
 * SubscriberInformationTests.cpp
 *
 *  Created on: 17Jun.,2017
 *      Author: tom
 */
#include <iostream>
#include <gtest/gtest.h>
#include "InMemoryBus/Typedefs.h"
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "InMemoryBus/Subscribtions/Subscribers/SubscriberInformationEntity.h"
#include "../Subscribers/TestSubscriber.h"
#include "../../Common.h"
#include "TestMessage.h"

namespace InMemoryBusTests {

using namespace InMemoryBus::Subscribtions::Subscribers;

TEST(SubscriberInformationEntityTest, constructor_sets_subscriber_id) {
  // Arrange
  std::string expected("id");
  InMemoryBusTests::TestSubscriber subscriber { };

  // Act
  SubscriberInformationEntity sut { "id", "message_type", subscriber.getNotifyFunc() };

  // Assert
  EXPECT_EQ(0, expected.compare(sut.get_subscriber_id()));
}

TEST(SubscriberInformationEntityTest, constructor_sets_message_type) {
  using namespace InMemoryBus;

  // Arrange
  std::string expected("message_type");
  InMemoryBusTests::TestSubscriber subscriber { };

  // Act
  SubscriberInformationEntity sut { "id", "message_type", subscriber.getNotifyFunc() };

  // Assert
  EXPECT_EQ(0, expected.compare(sut.get_message_type()));
}

TEST(SubscriberInformationEntityTest, constructor_sets_subscriber_function) {
  using namespace InMemoryBus;

  // Arrange
  Message_SPtr message = std::make_shared<TestMessage>("Hello");
  InMemoryBusTests::TestSubscriber subscriber { };

  // Act
  SubscriberInformationEntity sut { "id", "message_type", subscriber.getNotifyFunc() };
  SubscriberFunction subscriber_function = sut.get_subscriber_function();
  subscriber_function(message);

  // Assert
  EXPECT_TRUE(subscriber.wasCalledOnNotify());
}

TEST(SubscriberInformationEntityTest, operatorLess_returns_false_for_b_less_a) {
  using namespace InMemoryBus;

  // Arrange
  InMemoryBusTests::TestSubscriber subscriber { };
  SubscriberInformationEntity a { "a", "message_type", subscriber.getNotifyFunc() };
  SubscriberInformationEntity b { "b", "message_type", subscriber.getNotifyFunc() };

  // Act
  // Assert
  EXPECT_FALSE(b < a);
}

TEST(SubscriberInformationEntityTest, operatorLess_returns_false_for_a_less_a) {
  using namespace InMemoryBus;

  // Arrange
  InMemoryBusTests::TestSubscriber subscriber { };
  SubscriberInformationEntity a { "a", "message_type", subscriber.getNotifyFunc() };

  // Act
  // Assert
  EXPECT_FALSE(a < a);
}

TEST(SubscriberInformationEntityTest, operatorLess_returns_true_for_a_less_b) {
  using namespace InMemoryBus;

  // Arrange
  InMemoryBusTests::TestSubscriber subscriber { };
  SubscriberInformationEntity a { "a", "message_type", subscriber.getNotifyFunc() };
  SubscriberInformationEntity b { "b", "message_type", subscriber.getNotifyFunc() };

  // Act
  // Assert
  EXPECT_TRUE(a < b);
}

TEST(SubscriberInformationEntityTest, constructor_throws_for_subscriber_id_is_empty) {
  using namespace InMemoryBus;

  try {
    InMemoryBusTests::TestSubscriber subscriber { };

    SubscriberInformationEntity a { "", "message_type", subscriber.getNotifyFunc() };

    FAIL()<< "Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'subscriber_id' is invalid! Can't create SubscriberInformationEntity because 'subscriber_id' is empty!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(SubscriberInformationEntityTest, constructor_throws_for_message_type_is_empty) {
  using namespace InMemoryBus;

  try {
    InMemoryBusTests::TestSubscriber subscriber { };

    SubscriberInformationEntity a { "id", "", subscriber.getNotifyFunc() };

    FAIL()<< "Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'message_type' is invalid! Can't create SubscriberInformationEntity because 'message_type' is empty!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(SubscriberInformationEntityTest, constructor_throws_for_subscriber_function_is_null) {
  using namespace InMemoryBus;

  try {
    SubscriberInformationEntity a { "id", "type", nullptr };

    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'subscriber_function' is invalid! Can't create SubscriberInformationEntity because 'subscriber_function' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(SubscriberInformationEntityTest, try_lock_returns_true_for_locking_ok) {
  // Arrange
  InMemoryBusTests::TestSubscriber subscriber { };

  SubscriberInformationEntity sut { "id", "message_type", subscriber.getNotifyFunc() };

  // Act
  bool actual = sut.try_lock();

  // Assert
  EXPECT_TRUE(actual);
}

TEST(SubscriberInformationEntityTest, try_lock_returns_false_for_locking_not_ok) {
  // Arrange
  InMemoryBusTests::TestSubscriber subscriber { };

  SubscriberInformationEntity sut { "id", "message_type", subscriber.getNotifyFunc() };

  sut.try_lock();

  // Act
  bool actual = sut.try_lock();

  // Assert
  EXPECT_FALSE(actual);
}

TEST(SubscriberInformationEntityTest, unlock_free_lock) {
  // Arrange
  InMemoryBusTests::TestSubscriber subscriber { };

  SubscriberInformationEntity sut { "id", "message_type", subscriber.getNotifyFunc() };

  sut.try_lock();

  // Act
  sut.unlock();

  // Assert
  bool actual = sut.try_lock();

  EXPECT_TRUE(actual);
}

}
