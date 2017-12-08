/*
 * SubscibersNotifierTests.cpp
 *
 *  Created on: 6 Dec. 2017
 *      Author: tom
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Common.h"
#include "../Mocks/MockISubscribtionManager.h"
#include "../Mocks/MockIThreadSafeSubscriberInformationRepository.h"
#include "../Mocks/MockISubscriberFunctionCaller.h"
#include "../Common/TestSubscriber.h"
#include "InMemoryBus/Common/SubscriberFunction.h"
#include "InMemoryBus/Common/BaseMessage.h"
#include "InMemoryBus/Exceptions/ArgumentInvalidException.h"
#include "InMemoryBus/Notifiers/SubscibersNotifier.h"
#include "InMemoryBus/Subscribtions/Subscribers/SubscriberInformationEntity.h"
#include "../Common/TestMessage.h"

namespace InMemoryBusTests {

using namespace InMemoryBus::Notifiers;

TEST(SubscibersNotifierTests, constructor_throws_for_manager_is_nullptr) {
  try {
    // Arrange
    ISubscribtionManager_SPtr manager = nullptr;
    ISubscriberFunctionCaller_SPtr caller = std::make_shared<MockISubscriberFunctionCaller>();

    // Act
    SubscibersNotifier sut { manager, caller };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'manager' is invalid! Can't create SubscibersNotifier because 'manager' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(SubscibersNotifierTests, constructor_throws_for_failed_manager_is_nullptr) {
  try {
    // Arrange
    ISubscribtionManager_SPtr manager = std::make_shared<MockISubscribtionManager>();
    ISubscriberFunctionCaller_SPtr caller = nullptr;

    // Act
    SubscibersNotifier sut { manager, caller };

    // Assert
    FAIL()<<"Expected ArgumentInvalidException";
  }
  catch(InMemoryBus::Exceptions::ArgumentInvalidException const & ex)
  {
    auto actual = ex.get_message();
    auto expected = std::string("Parameter 'caller' is invalid! Can't create SubscibersNotifier because 'caller' is null!");

    InMemoryBusTest::expect_std_strings_are_equal(expected, actual);
  }
}

TEST(SubscibersNotifierTests, notify_all_subscribers_for_message_ignores_message_is_null) {
  try {
    // Arrange
    BaseMessage_SPtr message = nullptr;
    ISubscribtionManager_SPtr manager = std::make_shared<MockISubscribtionManager>();
    ISubscriberFunctionCaller_SPtr caller = std::make_shared<MockISubscriberFunctionCaller>();

    SubscibersNotifier sut { manager, caller };

    // Act
    sut.notify_all_subscribers_for_message(message);
  } catch (InMemoryBus::Exceptions::ArgumentInvalidException const & ex) {
    // Assert
    FAIL()<<"message is null should be ignored!";
  }
}

TEST(SubscibersNotifierTests, notify_all_subscribers_for_message_ignores_repository_is_null) {
  try {
    // Arrange
    BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();
    IThreadSafeSubscriberInformationRepository_SPtr repository = nullptr;
    MockISubscribtionManager* p_mock_manager = new MockISubscribtionManager();
    ISubscribtionManager_SPtr manager { p_mock_manager };
    ISubscriberFunctionCaller_SPtr caller = std::make_shared<MockISubscriberFunctionCaller>();

    SubscibersNotifier sut { manager, caller };

    EXPECT_CALL(*p_mock_manager, get_repository_for_message_type(message->getType())).Times(1).WillOnce(
        testing::Return(repository));

    // Act
    sut.notify_all_subscribers_for_message(message);
  } catch (InMemoryBus::Exceptions::ArgumentInvalidException const & ex) {
    // Assert
    FAIL()<<"repository is null should be ignored!";
  }
}

TEST(SubscibersNotifierTests, notify_all_subscribers_for_message_ignores_entities_is_null) {
  try {
    // Arrange
    BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();
    ISubscriberInformationEntityVector_SPtr vector = std::make_shared<ISubscriberInformationEntityVector>();
    MockIThreadSafeSubscriberInformationRepository* p_mock_repository =
        new MockIThreadSafeSubscriberInformationRepository();
    IThreadSafeSubscriberInformationRepository_SPtr repository { p_mock_repository };
    ISubscriberInformationEntityVector_SPtr entities = nullptr;
    MockISubscribtionManager* p_mock_manager = new MockISubscribtionManager();
    ISubscribtionManager_SPtr manager { p_mock_manager };
    ISubscriberFunctionCaller_SPtr caller = std::make_shared<MockISubscriberFunctionCaller>();

    SubscibersNotifier sut { manager, caller };

    EXPECT_CALL(*p_mock_manager, get_repository_for_message_type(message->getType())).Times(1).WillOnce(
        testing::Return(repository));
    EXPECT_CALL(*p_mock_repository, get_all_subscribers()).Times(1).WillOnce(testing::Return(vector));

    // Act
    sut.notify_all_subscribers_for_message(message);
  } catch (InMemoryBus::Exceptions::ArgumentInvalidException const & ex) {
    // Assert
    FAIL()<<"entites is null should be ignored!";
  }
}

TEST(SubscibersNotifierTests, notify_all_subscribers_for_message_entities_calls_subscriber_functions) {
  // Arrange
  BaseMessage_SPtr message = std::make_shared<InMemoryBusTests::TestMessage>();

  TestSubscriber subscriber_one { };
  TestSubscriber subscriber_two { };

  ISubscriberInformationEntity_SPtr information_one = std::make_shared<
      InMemoryBus::Subscribtions::Subscribers::SubscriberInformationEntity>("one", message->getType(),
                                                                            subscriber_one.getNotifyFunc());

  ISubscriberInformationEntity_SPtr information_two = std::make_shared<
      InMemoryBus::Subscribtions::Subscribers::SubscriberInformationEntity>("two", message->getType(),
                                                                            subscriber_two.getNotifyFunc());

  MockIThreadSafeSubscriberInformationRepository* p_mock_repository =
      new MockIThreadSafeSubscriberInformationRepository();
  IThreadSafeSubscriberInformationRepository_SPtr repository { p_mock_repository };
  ISubscriberInformationEntityVector* p_vector = new ISubscriberInformationEntityVector();
  ISubscriberInformationEntityVector_SPtr vector { p_vector };
  MockISubscribtionManager* p_mock_manager = new MockISubscribtionManager();
  ISubscribtionManager_SPtr manager { p_mock_manager };
  MockISubscriberFunctionCaller* p_mock_caller = new MockISubscriberFunctionCaller();
  ISubscriberFunctionCaller_SPtr caller { p_mock_caller };

  SubscibersNotifier sut { manager, caller };

  EXPECT_CALL(*p_mock_manager, get_repository_for_message_type(message->getType())).Times(1).WillOnce(
      testing::Return(repository));
  EXPECT_CALL(*p_mock_repository, get_all_subscribers()).Times(1).WillOnce(testing::Return(vector));

  EXPECT_CALL(*p_mock_caller, call_subscriber_function(information_one, message)).Times(1);
  EXPECT_CALL(*p_mock_caller, call_subscriber_function(information_two, message)).Times(1);

  vector->push_back(information_one);
  vector->push_back(information_two);

  // Act
  sut.notify_all_subscribers_for_message(message);

  // Assert
}

}

