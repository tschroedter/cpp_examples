/*
 * SubscriberInformationTests.cpp
 *
 *  Created on: 17Jun.,2017
 *      Author: tom
 */
#include <iostream>
#include <gtest/gtest.h>
#include "MessageBus.h"
#include "Message.h"
#include "Typedefs.h"
#include "TestSubscriber.h"
#include "subscribers/SubscriberInformation.h"
#include "TestSubscriber.h"

namespace InMemoryBusTests
{

    TEST(SubscriberInformationTest, constructor_sets_subscriber_id)
    {
        using namespace InMemoryBus;

        // Arrange
        std::string expected("id");
        InMemoryBusTests::TestSubscriber subscriber
        { };

        // Act
        SubscriberInformation sut
        { "id", subscriber.getNotifyFunc() };

        // Assert
        EXPECT_EQ(0, expected.compare(sut.subscriber_id));
    }

    TEST(SubscriberInformationTest, constructor_sets_function)
    {
        using namespace InMemoryBus;

        // Arrange
        Message* p_message = new Message
        { "Hello" };
        InMemoryBusTests::TestSubscriber subscriber
        { };

        // Act
        SubscriberInformation sut
        { "id", subscriber.getNotifyFunc() };
        sut.function(p_message);

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
        { "a", subscriber.getNotifyFunc() };
        SubscriberInformation b
        { "b", subscriber.getNotifyFunc() };

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
        { "a", subscriber.getNotifyFunc() };

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
        { "a", subscriber.getNotifyFunc() };
        SubscriberInformation b
        { "b", subscriber.getNotifyFunc() };

        // Act
        // Assert
        EXPECT_TRUE(a < b);
    }

} /* namespace InMemoryBus */
