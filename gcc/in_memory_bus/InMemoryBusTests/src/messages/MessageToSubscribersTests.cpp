/*
 * MessageToSubscribersTests.cpp
 *
 *  Created on: 26 Oct. 2017
 *      Author: tom
 */

#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "subscribers/SubscriberInformation.h"
#include "subscribers/SubscriberInformationRepository.h"
#include "MessageBus.h"
#include "exceptions/ArgumentInvalidException.h"
#include "messages/MessageToSubscribers.h"
#include "exceptions/ArgumentInvalidException.h"
#include "../MockISubscriberInformationRepository.h"

namespace InMemoryBusTests
{

    void expect_std_strings_are_equal(const std::string & expected,
            const std::string & actual);

    TEST(MessageToSubscribersTest, constructor_sets_message_type)
    {
        using namespace InMemoryBus;

        // Arrange
        std::string expected("message_type");

        MockISubscriberInformationRepository* p_repo = new MockISubscriberInformationRepository{};
        ISubscriberInformationRepository_SPtr subscribers(p_repo);

        // Act
        MessageToSubscribers sut
        { expected, subscribers };

        // Assert
        EXPECT_EQ(0, expected.compare(sut.get_message_type()));
    }

    TEST(MessageToSubscribersTest, constructor_sets_subscribers)
    {
        using namespace InMemoryBus;

        // Arrange
        std::string expected("message_type");

        MockISubscriberInformationRepository* p_repo = new MockISubscriberInformationRepository{};
        ISubscriberInformationRepository_SPtr subscribers(p_repo);

        // Act
        MessageToSubscribers sut
        { expected, subscribers };

        // Assert
        EXPECT_EQ(subscribers, sut.get_subscribers());
    }

    TEST(MessageToSubscribersTest, operatorLess_returns_false_for_b_less_a)
    {
        using namespace InMemoryBus;

        // Arrange
        MockISubscriberInformationRepository* p_repo = new MockISubscriberInformationRepository{};
        ISubscriberInformationRepository_SPtr subscribers(p_repo);
        MessageToSubscribers a
        { "a", subscribers };
        MessageToSubscribers b
        { "b", subscribers };

        // Act
        // Assert
        EXPECT_FALSE(b < a);
    }

    TEST(MessageToSubscribersTest, operatorLess_returns_false_for_a_less_a)
    {
        using namespace InMemoryBus;

        // Arrange
        MockISubscriberInformationRepository* p_repo = new MockISubscriberInformationRepository{};
        ISubscriberInformationRepository_SPtr subscribers(p_repo);
        MessageToSubscribers a
        { "a", subscribers };
        MessageToSubscribers b
        { "b", subscribers };

        // Act
        // Assert
        EXPECT_FALSE(a < a);
    }

    TEST(MessageToSubscribersTest, operatorLess_returns_true_for_a_less_b)
    {
        using namespace InMemoryBus;

        // Arrange
        MockISubscriberInformationRepository* p_repo = new MockISubscriberInformationRepository{};
        ISubscriberInformationRepository_SPtr subscribers(p_repo);
        MessageToSubscribers a
        { "a", subscribers };
        MessageToSubscribers b
        { "b", subscribers };

        // Act
        // Assert
        EXPECT_TRUE(a < b);
    }

    TEST(MessageToSubscribersTest, constructor_throws_for_message_type_is_empty)
    {
        using namespace InMemoryBus;

        try
        {
            MockISubscriberInformationRepository* p_repo = new MockISubscriberInformationRepository{};
            ISubscriberInformationRepository_SPtr subscribers(p_repo);
            MessageToSubscribers a
            { "", subscribers };

            FAIL()<< "Expected ArgumentInvalidException";
        }
        catch(ArgumentInvalidException const & ex)
        {
            auto actual = ex.get_message();
            auto expected = std::string("Parameter 'message_type' is invalid! Can't create MessageToSubscribers because 'message_type' is empty!");

            expect_std_strings_are_equal(expected, actual);
        }
    }

    TEST(MessageToSubscribersTest, constructor_throws_for_subscribers_is_null)
    {
        using namespace InMemoryBus;

        try
        {
            MessageToSubscribers sut
            { "type", nullptr };

            FAIL()<<"Expected ArgumentInvalidException";
        }
        catch(ArgumentInvalidException const & ex)
        {
            auto actual = ex.get_message();
            auto expected = std::string("Parameter 'subscribers' is invalid! Can't create MessageToSubscribers because 'subscribers' is null!");

            expect_std_strings_are_equal(expected, actual);
        }
    }

} /* namespace InMemoryBus */
