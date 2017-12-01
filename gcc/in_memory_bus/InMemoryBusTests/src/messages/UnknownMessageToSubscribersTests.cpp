/*
 * SubscriberInformationTests.cpp
 *
 *  Created on: 17Jun.,2017
 *      Author: tom
 */
#include <iostream>
#include <gtest/gtest.h>
#include "messages/UnknownMessageToSubscribers.h"
#include "exceptions/ArgumentInvalidException.h"

namespace InMemoryBusTests
{
    TEST(UnknownMessageToSubscribersTest, constructor_sets_message_type)
    {
        using namespace InMemoryBus;

        // Arrange
        std::string expected("Unknown");

        // Act
        UnknownMessageToSubscribers sut
        { };

        // Assert
        EXPECT_EQ(0, expected.compare(sut.get_message_type()));
    }

    TEST(UnknownMessageToSubscribersTest, constructor_sets_subscriber)
    {
        using namespace InMemoryBus;

        // Arrange
        // Act
        UnknownMessageToSubscribers sut
        { };

        // Assert
        EXPECT_EQ(0, sut.get_subscribers()->size());
    }

}
/* namespace InMemoryBus */
