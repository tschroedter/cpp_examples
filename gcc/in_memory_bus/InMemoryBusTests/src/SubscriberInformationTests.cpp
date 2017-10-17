/*
 * SubscriberInformationTests.cpp
 *
 *  Created on: 17Jun.,2017
 *      Author: tom
 */
#include <iostream>
#include <gtest/gtest.h>
#include "subscribers/SubscriberInformation.h"
#include "MessageBus.h"
#include "Message.h"
#include "Typedefs.h"
#include "TestSubscriber.h"
#include "exceptions/ArgumentInvalidException.h"

namespace InMemoryBusTests
{
    void expect_std_strings_are_equal(const std::string & expected,
            const std::string & actual)
    {
        std::cout << "Actual  : " << actual << "\n";
        std::cout << "Expected: " << expected << "\n";

        EXPECT_EQ(0, expected.compare(actual));
    }

    TEST(SubscriberInformationTest, constructor_sets_subscriber_id)
    {
        using namespace InMemoryBus;

        // Arrange
        std::string expected("id");
        InMemoryBusTests::TestSubscriber subscriber
        { };

        // Act
        SubscriberInformation sut
        { "id", "message_type", subscriber.getNotifyFunc() };

        // Assert
        EXPECT_EQ(0, expected.compare(sut.subscriber_id));
    }

    TEST(SubscriberInformationTest, constructor_sets_message_type)
    {
        using namespace InMemoryBus;

        // Arrange
        std::string expected("message_type");
        InMemoryBusTests::TestSubscriber subscriber
        { };

        // Act
        SubscriberInformation sut
        { "id", "message_type", subscriber.getNotifyFunc() };

        // Assert
        EXPECT_EQ(0, expected.compare(sut.message_type));
    }

    TEST(SubscriberInformationTest, constructor_sets_subscriber_function)
    {
        using namespace InMemoryBus;

        // Arrange
        Message* p_message = new Message
        { "Hello" };
        InMemoryBusTests::TestSubscriber subscriber
        { };

        // Act
        SubscriberInformation sut
        { "id", "message_type", subscriber.getNotifyFunc() };
        sut.subscriber_function(p_message);

        // Assert
        EXPECT_TRUE(subscriber.wasCalledOnNotify());
    }

    TEST(SubscriberInformationTest, operatorLess_returns_false_for_b_less_a)
    {
        using namespace InMemoryBus;

        // Arrange
        InMemoryBusTests::TestSubscriber subscriber
        { };
        SubscriberInformation a
        { "a", "message_type", subscriber.getNotifyFunc() };
        SubscriberInformation b
        { "b", "message_type", subscriber.getNotifyFunc() };

        // Act
        // Assert
        EXPECT_FALSE(b < a);
    }

    TEST(SubscriberInformationTest, operatorLess_returns_false_for_a_less_a)
    {
        using namespace InMemoryBus;

        // Arrange
        InMemoryBusTests::TestSubscriber subscriber
        { };
        SubscriberInformation a
        { "a", "message_type", subscriber.getNotifyFunc() };

        // Act
        // Assert
        EXPECT_FALSE(a < a);
    }

    TEST(SubscriberInformationTest, operatorLess_returns_true_for_a_less_b)
    {
        using namespace InMemoryBus;

        // Arrange
        InMemoryBusTests::TestSubscriber subscriber
        { };
        SubscriberInformation a
        { "a", "message_type", subscriber.getNotifyFunc() };
        SubscriberInformation b
        { "b", "message_type", subscriber.getNotifyFunc() };

        // Act
        // Assert
        EXPECT_TRUE(a < b);
    }

    TEST(SubscriberInformationTest, constructor_throws_for_subscriber_id_is_empty)
    {
        using namespace InMemoryBus;

        try
        {
            InMemoryBusTests::TestSubscriber subscriber
            { };

            SubscriberInformation a
            { "", "message_type", subscriber.getNotifyFunc() };

            FAIL()<< "Expected ArgumentInvalidException";
        }
        catch(ArgumentInvalidException const & ex)
        {
            auto actual = ex.get_message();
            auto expected = std::string("Parameter 'subscriber_id' is invalid! Can't create SubscriberInformation because 'subscriber_id' is empty!");

            expect_std_strings_are_equal(expected, actual);
        }
    }

    TEST(SubscriberInformationTest, constructor_throws_for_message_type_is_empty)
    {
        using namespace InMemoryBus;

        try
        {
            InMemoryBusTests::TestSubscriber subscriber
            { };

            SubscriberInformation a
            { "id", "", subscriber.getNotifyFunc() };

            FAIL()<< "Expected ArgumentInvalidException";
        }
        catch(ArgumentInvalidException const & ex)
        {
            auto actual = ex.get_message();
            auto expected = std::string("Parameter 'message_type' is invalid! Can't create SubscriberInformation because 'message_type' is empty!");

            expect_std_strings_are_equal(expected, actual);
        }
    }

    TEST(SubscriberInformationTest, constructor_throws_for_subscriber_function_is_null)
    {
        using namespace InMemoryBus;

        try
        {
            SubscriberInformation a
            { "id", "type", nullptr };

            FAIL()<<"Expected ArgumentInvalidException";
    }
    catch(ArgumentInvalidException const & ex)
    {
        auto actual = ex.get_message();
        auto expected = std::string("Parameter 'subscriberFunction' is invalid! Can't create SubscriberInformation because 'subscriber_function' is null!");

        expect_std_strings_are_equal(expected, actual);
    }
}

}
/* namespace InMemoryBus */
