/*
 * SubscriberFunctionCallerTests.cpp
 *
 *  Created on: 7 Dec. 2017
 *      Author: tom
 */

#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Common.h"
#include "../Mocks/MockIFailedToNotifyManager.h"
#include "InMemoryBus/Common/SubscriberFunction.h"
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "InMemoryBus/Notifiers/SubscriberFunctionCaller.h"
#include "InMemoryBus/Notifiers/Failed/IFailedToNotifyManager.h"
#include "InMemoryBus/Subscribtions/Subscribers/SubscriberInformationEntity.h"
#include "InMemoryBus/Subscribtions/Subscribers/ISubscriberInformationEntity.h"
#include "../Common/TestMessage.h"
#include "../Common/TestSubscriber.h"

namespace InMemoryBusTests {

using namespace InMemoryBus::Notifiers;

TEST(SubscriberFunctionCallerTests, constructor_throws_for_manager_is_nullptr) {
  try {
    // Arrange
    IFailedToNotifyManager_SPtr manager = nullptr;

    // Act
    SubscriberFunctionCaller sut { manager };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'manager' is invalid! Can't create SubscriberFunctionCaller because 'manager' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(SubscriberFunctionCallerTests, execute_subscriber_function_calls_function) {
  // Arrange
  BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();

  TestSubscriber subscriber { };

  ISubscriberInformationEntity_SPtr information = std::make_shared<
      InMemoryBus::Subscribtions::Subscribers::SubscriberInformationEntity>("one", message->getType(),
                                                                            subscriber.getNotifyFunc());

  IFailedToNotifyManager_SPtr manager = std::make_shared<MockIFailedToNotifyManager>();

  SubscriberFunctionCaller sut { manager };

  // Act
  sut.execute_subscriber_function(information, message);

  // Assert
  EXPECT_TRUE(subscriber.wasCalledOnNotify());
}

TEST(SubscriberFunctionCallerTests, try_call_subscriber_function_returns_true_for_function_called) {
  // Arrange
  BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();

  TestSubscriber subscriber { };

  ISubscriberInformationEntity_SPtr information = std::make_shared<
      InMemoryBus::Subscribtions::Subscribers::SubscriberInformationEntity>("one", message->getType(),
                                                                            subscriber.getNotifyFunc());

  IFailedToNotifyManager_SPtr manager = std::make_shared<MockIFailedToNotifyManager>();

  SubscriberFunctionCaller sut { manager };

  // Act
  auto actual = sut.try_call_subscriber_function(information, message);

  // Assert
  EXPECT_TRUE(actual);
}

TEST(SubscriberFunctionCallerTests, try_call_subscriber_function_calls_function) {
  // Arrange
  BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();

  TestSubscriber subscriber { };

  ISubscriberInformationEntity_SPtr information = std::make_shared<
      InMemoryBus::Subscribtions::Subscribers::SubscriberInformationEntity>("one", message->getType(),
                                                                            subscriber.getNotifyFunc());

  IFailedToNotifyManager_SPtr manager = std::make_shared<MockIFailedToNotifyManager>();

  SubscriberFunctionCaller sut { manager };

  // Act
  sut.try_call_subscriber_function(information, message);

  // Assert
  EXPECT_TRUE(subscriber.wasCalledOnNotify());
}

TEST(SubscriberFunctionCallerTests, try_call_subscriber_function_returns_false_for_function_not_called) {
  // Arrange
  BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();

  TestSubscriber subscriber { };

  ISubscriberInformationEntity_SPtr information = std::make_shared<
      InMemoryBus::Subscribtions::Subscribers::SubscriberInformationEntity>("one", message->getType(),
                                                                            subscriber.getNotifyFunc());

  IFailedToNotifyManager_SPtr manager = std::make_shared<MockIFailedToNotifyManager>();

  SubscriberFunctionCaller sut { manager };

  information->try_lock();  // make it not call the function

  // Act
  auto actual = sut.try_call_subscriber_function(information, message);

  // Assert
  EXPECT_FALSE(actual);
}

TEST(SubscriberFunctionCallerTests, call_subscriber_function_calls_function) {
  // Arrange
  BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();

  TestSubscriber subscriber { };

  ISubscriberInformationEntity_SPtr information = std::make_shared<
      InMemoryBus::Subscribtions::Subscribers::SubscriberInformationEntity>("one", message->getType(),
                                                                            subscriber.getNotifyFunc());

  IFailedToNotifyManager_SPtr manager = std::make_shared<MockIFailedToNotifyManager>();

  SubscriberFunctionCaller sut { manager };

  // Act
  sut.call_subscriber_function(information, message);

  // Assert
  EXPECT_TRUE(subscriber.wasCalledOnNotify());
}

TEST(SubscriberFunctionCallerTests, call_subscriber_function_does_not_call_manager) {
  // Arrange
  BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();

  TestSubscriber subscriber { };

  ISubscriberInformationEntity_SPtr information = std::make_shared<
      InMemoryBus::Subscribtions::Subscribers::SubscriberInformationEntity>("one", message->getType(),
                                                                            subscriber.getNotifyFunc());

  MockIFailedToNotifyManager* p_mock_manager = new MockIFailedToNotifyManager();
  IFailedToNotifyManager_SPtr manager { p_mock_manager };

  SubscriberFunctionCaller sut { manager };

  EXPECT_CALL(*p_mock_manager, handle_failed_notification(information, message)).Times(0);

  // Act
  sut.call_subscriber_function(information, message);

  // Assert
}

TEST(SubscriberFunctionCallerTests, call_subscriber_function_calls_manager_for_failes_function_call) {
  // Arrange
  BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();

  TestSubscriber subscriber { };

  ISubscriberInformationEntity_SPtr information = std::make_shared<
      InMemoryBus::Subscribtions::Subscribers::SubscriberInformationEntity>("one", message->getType(),
                                                                            subscriber.getNotifyFunc());

  MockIFailedToNotifyManager* p_mock_manager = new MockIFailedToNotifyManager();
  IFailedToNotifyManager_SPtr manager { p_mock_manager };

  SubscriberFunctionCaller sut { manager };

  EXPECT_CALL(*p_mock_manager, handle_failed_notification(information, message)).Times(1);

  information->try_lock();  // make it not call the function

  // Act
  sut.call_subscriber_function(information, message);

  // Assert
}

}
