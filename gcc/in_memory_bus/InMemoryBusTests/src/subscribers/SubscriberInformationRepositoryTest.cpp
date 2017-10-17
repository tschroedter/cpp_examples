#include <memory>
#include <iostream>
#include <gtest/gtest.h>
#include <subscribers/SubscriberInformation.h>
#include <subscribers/SubscriberInformationRepository.h>
#include "Typedefs.h"
#include "../Message.h"

namespace InMemoryBusTests
{
    using namespace InMemoryBus;

    // InMemoryBus::SubscriberFunction DOES_NOT_MATTER = 0;

    void doNothingSubscriberFunction(InMemoryBus::BaseMessage* p_base_message)
    {
    }

    TEST(SubscriberInformationRepositoryTest, add_adds_information_to_vector)
    {
        // Arrange
        auto sp_info = std::make_shared<SubscriberInformation>("id", "type",
                doNothingSubscriberFunction);
        auto sp_vector = std::make_shared<SubscriberInformationVector>();

        Messages messages;

        SubscriberInformationRepository sut
        { sp_vector };

        // Act
        sut.add(sp_info);

        // Assert
        EXPECT_EQ(1, sp_vector->size());
    }

    TEST(SubscriberInformationRepositoryTest, add_adds_informations_to_vector)
    {
        // Arrange
        using namespace InMemoryBus;

        auto sp_info_one = std::make_shared<SubscriberInformation>("id1",
                "type", doNothingSubscriberFunction);
        auto sp_info_two = std::make_shared<SubscriberInformation>("id2",
                "type", doNothingSubscriberFunction);
        auto sp_vector = std::make_shared<SubscriberInformationVector>();

        Messages messages;

        SubscriberInformationRepository sut
        { sp_vector };

        // Act
        sut.add(sp_info_one);
        sut.add(sp_info_two);

        // Assert
        EXPECT_EQ(2, sp_vector->size());
    }

    TEST(SubscriberInformationRepositoryTest, remove_removes_information_from_vector)
    {
        // Arrange
        using namespace InMemoryBus;

        auto sp_info = std::make_shared<SubscriberInformation>("id", "type",
                doNothingSubscriberFunction);
        auto sp_vector = std::make_shared<SubscriberInformationVector>();

        Messages messages;

        SubscriberInformationRepository sut
        { sp_vector };

        sut.add(sp_info);

        // Act
        sut.remove(sp_info);

        // Assert
        EXPECT_EQ(0, sp_vector->size());
    }

    TEST(SubscriberInformationRepositoryTest, remove_removes_specific_information_from_vector)
    {
        // Arrange
        using namespace InMemoryBus;

        auto sp_info_one = std::make_shared<SubscriberInformation>("id1",
                "type", doNothingSubscriberFunction);
        auto sp_info_two = std::make_shared<SubscriberInformation>("id2",
                "type", doNothingSubscriberFunction);
        auto sp_vector = std::make_shared<SubscriberInformationVector>();

        Messages messages;

        SubscriberInformationRepository sut
        { sp_vector };

        sut.add(sp_info_one);
        sut.add(sp_info_two);

        // Act
        sut.remove(sp_info_one);

        // Assert
        EXPECT_EQ(1, sp_vector->size());
    }

    TEST(SubscriberInformationRepositoryTest, findBySubscriberId_returns_information)
    {
        // Arrange
        using namespace InMemoryBus;

        auto sp_info = std::make_shared<SubscriberInformation>("id", "type",
                doNothingSubscriberFunction);
        auto sp_vector = std::make_shared<SubscriberInformationVector>();

        Messages messages;

        SubscriberInformationRepository sut
        { sp_vector };

        sut.add(sp_info);

        // Act
        auto actual = sut.findBySubscriberId(sp_info->subscriber_id);

        // Assert
        EXPECT_TRUE(sp_info == actual);
    }

    TEST(SubscriberInformationRepositoryTest, findBySubscriberId_returns_Unknown_For_Unknown_subscriber_id)
    {
        // Arrange
        using namespace InMemoryBus;

        auto sp_info = std::make_shared<SubscriberInformation>("id", "type",
                doNothingSubscriberFunction);
        auto sp_vector = std::make_shared<SubscriberInformationVector>();

        Messages messages;

        SubscriberInformationRepository sut
        { sp_vector };

        sut.add(sp_info);

        // Act
        auto actual = sut.findBySubscriberId("unknown subscriber_id");

        // Assert
        EXPECT_TRUE(actual->subscriber_id.compare("Unknown") == 0);
    }

    TEST(SubscriberInformationRepositoryTest, getAll_returns_all_informations)
    {
        // Arrange
        using namespace InMemoryBus;

        auto sp_info_one = std::make_shared<SubscriberInformation>("id1",
                "type", doNothingSubscriberFunction);
        auto sp_info_two = std::make_shared<SubscriberInformation>("id2",
                "type", doNothingSubscriberFunction);
        auto sp_vector = std::make_shared<SubscriberInformationVector>();

        Messages messages;

        SubscriberInformationRepository sut
        { sp_vector };

        sut.add(sp_info_one);
        sut.add(sp_info_two);

        // Act
        auto actual = sut.getAll();

        // Assert
        EXPECT_EQ(2, actual->size());
        EXPECT_TRUE(sp_info_one == (*actual)[0]);
        EXPECT_TRUE(sp_info_two == (*actual)[1]);
    }

    TEST(SubscriberInformationRepositoryTest, getAll_returns_all_informations_indepently_from_add_or_remove)
    {
        // Arrange
        using namespace InMemoryBus;

        auto sp_info_one = std::make_shared<SubscriberInformation>("id1",
                "type", doNothingSubscriberFunction);
        auto sp_info_two = std::make_shared<SubscriberInformation>("id2",
                "type", doNothingSubscriberFunction);
        auto sp_vector = std::make_shared<SubscriberInformationVector>();

        Messages messages;

        SubscriberInformationRepository sut
        { sp_vector };

        sut.add(sp_info_one);
        sut.add(sp_info_two);
        auto actual = sut.getAll();
        EXPECT_EQ(2, actual->size());

        // Act
        sut.remove(sp_info_one);

        // Assert
        EXPECT_EQ(2, actual->size());
        EXPECT_EQ(1, sp_vector->size());
    }
}
