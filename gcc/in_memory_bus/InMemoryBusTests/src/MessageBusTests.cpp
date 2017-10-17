/*
 * MessageBusTests.cpp
 *
 *  Created on: 13Jun.,2017
 *      Author: tom
 */

#include <iostream>
#include <gtest/gtest.h>
#include <subscribers/SubscriberInformationRepository.h>
#include "MessageBus.h"
#include "Message.h"
#include "Typedefs.h"
#include "TestSubscriber.h"

namespace InMemoryBusTests
{
    InMemoryBus::SubscriberInformationRepository_SPtr MessageBusTest_create_subscribers_repository()
    {
        InMemoryBus::SubscriberInformationVector_SPtr informations =
                std::make_shared<InMemoryBus::SubscriberInformationVector>();

        InMemoryBus::SubscriberInformationRepository_SPtr subscribers =
                std::make_shared<InMemoryBus::SubscriberInformationRepository>(
                        informations);

        return subscribers;
    }

    TEST(MessageBusTest, subscribe_adds_to_subscribers)
    {
        // Arrange
        InMemoryBusTests::TestSubscriber subscriber;

        using namespace InMemoryBus;

        SubscriberInformationRepository_SPtr subscribers =
                MessageBusTest_create_subscribers_repository();

        Messages messages;
        MessageBus sut
        { subscribers, &messages };

        // Act
        sut.subscribe("id", "type", subscriber.getNotifyFunc());

        // Assert
        EXPECT_EQ(1, subscribers->size());
    }

    TEST(MessageBusTest, unsubscribe_removes_from_subscribers)
    {
        // Arrange
        InMemoryBusTests::TestSubscriber subscriber;

        using namespace InMemoryBus;

        SubscriberInformationRepository_SPtr subscribers =
                MessageBusTest_create_subscribers_repository();
        Messages messages;
        MessageBus sut
        { subscribers, &messages };

        sut.subscribe("id", "type", subscriber.getNotifyFunc());
        EXPECT_EQ(1, subscribers->size());

        // Act
        sut.unsubscribe("id", "type");

        // Assert
        EXPECT_EQ(0, subscribers->size());
    }

    TEST(MessageBusTest, publish_adds_message_to_queue)
    {
        // Arrange
        InMemoryBusTests::TestSubscriber subscriber;
        InMemoryBusTests::Message message
        { "Test" };

        using namespace InMemoryBus;

        SubscriberInformationRepository_SPtr subscribers =
                MessageBusTest_create_subscribers_repository();
        Messages messages;
        MessageBus sut
        { subscribers, &messages };

        sut.subscribe("id", "type", subscriber.getNotifyFunc());

        // Act
        sut.publish(&message);

        // Assert
        EXPECT_EQ(1, messages.size());
    }

    TEST(MessageBusTest, notify_calls_subscribers_onNotify)
    {
        // Arrange
        InMemoryBusTests::TestSubscriber subscriberOne;
        InMemoryBusTests::TestSubscriber subscriberTwo;
        InMemoryBusTests::Message message
        { "Test" };

        using namespace InMemoryBus;

        SubscriberInformationRepository_SPtr subscribers =
                MessageBusTest_create_subscribers_repository();
        Messages messages;
        MessageBus sut
        { subscribers, &messages };

        sut.subscribe("idOne", message.getType(),
                subscriberOne.getNotifyFunc());
        sut.subscribe("idTwo", message.getType(),
                subscriberTwo.getNotifyFunc());

        sut.publish(&message);

        // Act
        sut.notify();

        // Assert
        EXPECT_TRUE(subscriberOne.wasCalledOnNotify());
        EXPECT_TRUE(subscriberTwo.wasCalledOnNotify());
    }

} /* namespace InMemoryBus */
