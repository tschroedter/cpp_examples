#include <memory>
#include <iostream>
#include <gtest/gtest.h>
#include <messages/MessageToSubscribers.h>
#include <messages/MessageToSubscribersRepository.h>
#include "../MockISubscriberInformationRepository.h"

namespace InMemoryBusTests
{
    using namespace InMemoryBus;

    // InMemoryBus::SubscriberFunction DOES_NOT_MATTER = 0;

    TEST(MessageToSubscribersRepositoryTests, add_adds_item_to_vector_once)
    {
        // Arrange
        MockISubscriberInformationRepository* p_repo =
                new MockISubscriberInformationRepository
                { };
        ISubscriberInformationRepository_SPtr repo(p_repo);
        MessageToSubscribers_SPtr sp_one =
                std::make_shared<MessageToSubscribers>("type", repo);

        MessageToSubscribersVector* p_vector = new MessageToSubscribersVector();
        MessageToSubscribersVector_SPtr sp_vector
        { p_vector };

        MessageToSubscribersRepository sut
        { sp_vector };

        // Act
        sut.add(sp_one);

        // Assert
        EXPECT_EQ(1, sp_vector->size());
    }

    TEST(MessageToSubscribersRepositoryTests, add_adds_item_to_vector_multiple)
    {
        // Arrange
        using namespace InMemoryBus;

        MockISubscriberInformationRepository* p_repo =
                new MockISubscriberInformationRepository
                { };
        ISubscriberInformationRepository_SPtr repo(p_repo);
        MessageToSubscribers_SPtr sp_one =
                std::make_shared<MessageToSubscribers>("one", repo);
        MessageToSubscribers_SPtr sp_two =
                std::make_shared<MessageToSubscribers>("two", repo);

        MessageToSubscribersVector* p_vector = new MessageToSubscribersVector();
        MessageToSubscribersVector_SPtr sp_vector
        { p_vector };

        MessageToSubscribersRepository sut
        { sp_vector };

        // Act
        sut.add(sp_one);
        sut.add(sp_two);

        // Assert
        EXPECT_EQ(2, sp_vector->size());
    }

    TEST(MessageToSubscribersRepositoryTests, remove_removes_item_from_vector)
    {
        // Arrange
        using namespace InMemoryBus;

        MockISubscriberInformationRepository* p_repo =
                new MockISubscriberInformationRepository
                { };
        ISubscriberInformationRepository_SPtr repo(p_repo);
        MessageToSubscribers_SPtr sp_one =
                std::make_shared<MessageToSubscribers>("type", repo);

        MessageToSubscribersVector* p_vector = new MessageToSubscribersVector();
        MessageToSubscribersVector_SPtr sp_vector
        { p_vector };

        MessageToSubscribersRepository sut
        { sp_vector };

        sut.add(sp_one);

        // Act
        sut.remove(sp_one);

        // Assert
        EXPECT_EQ(0, sp_vector->size());
    }

    TEST(MessageToSubscribersRepositoryTests, remove_removes_selected_item_from_vector)
    {
        // Arrange
        using namespace InMemoryBus;

        MockISubscriberInformationRepository* p_repo =
                new MockISubscriberInformationRepository
                { };
        ISubscriberInformationRepository_SPtr repo(p_repo);
        MessageToSubscribers_SPtr sp_one =
                std::make_shared<MessageToSubscribers>("one", repo);
        MessageToSubscribers_SPtr sp_two =
                std::make_shared<MessageToSubscribers>("two", repo);

        MessageToSubscribersVector* p_vector = new MessageToSubscribersVector();
        MessageToSubscribersVector_SPtr sp_vector
        { p_vector };

        MessageToSubscribersRepository sut
        { sp_vector };

        sut.add(sp_one);
        sut.add(sp_two);

        // Act
        sut.remove(sp_one);

        // Assert
        EXPECT_EQ(1, sp_vector->size());
    }

    TEST(MessageToSubscribersRepositoryTests, findBySubscriberId_returns_item)
    {
        // Arrange
        using namespace InMemoryBus;

        MockISubscriberInformationRepository* p_repo =
                new MockISubscriberInformationRepository
                { };
        ISubscriberInformationRepository_SPtr repo(p_repo);
        MessageToSubscribers_SPtr sp_one =
                std::make_shared<MessageToSubscribers>("type", repo);

        MessageToSubscribersVector* p_vector = new MessageToSubscribersVector();
        MessageToSubscribersVector_SPtr sp_vector
        { p_vector };

        MessageToSubscribersRepository sut
        { sp_vector };

        sut.add(sp_one);

        // Act
        auto actual = sut.findByMessageType(sp_one->get_message_type());

        // Assert
        EXPECT_TRUE(sp_one == actual);
    }

    TEST(MessageToSubscribersRepositoryTests, findBySubscriberId_returns_Unknown_For_Unknown_subscriber_id)
    {
        // Arrange
        using namespace InMemoryBus;

        MessageToSubscribersVector* p_vector = new MessageToSubscribersVector();
        MessageToSubscribersVector_SPtr sp_vector
        { p_vector };

        MessageToSubscribersRepository sut
        { sp_vector };

        // Act
        auto actual = sut.findByMessageType("unknown subscriber_id");

        // Assert
        EXPECT_TRUE(actual->get_message_type().compare("Unknown") == 0); // todo use function
    }

    TEST(MessageToSubscribersRepositoryTests, getAll_returns_all_informations)
    {
        // Arrange
        using namespace InMemoryBus;

        MockISubscriberInformationRepository* p_repo =
                new MockISubscriberInformationRepository
                { };
        ISubscriberInformationRepository_SPtr repo(p_repo);
        MessageToSubscribers_SPtr sp_one =
                std::make_shared<MessageToSubscribers>("one", repo);
        MessageToSubscribers_SPtr sp_two =
                std::make_shared<MessageToSubscribers>("two", repo);

        MessageToSubscribersVector* p_vector = new MessageToSubscribersVector();
        MessageToSubscribersVector_SPtr sp_vector
        { p_vector };

        MessageToSubscribersRepository sut
        { sp_vector };

        sut.add(sp_one);
        sut.add(sp_two);

        // Act
        auto actual = sut.getAll();

        // Assert
        EXPECT_EQ(2, actual->size());
        EXPECT_TRUE(sp_one == (*actual)[0]);
        EXPECT_TRUE(sp_two == (*actual)[1]);
    }

    TEST(MessageToSubscribersRepositoryTests, getAll_returns_all_informations_indepently_from_add_or_remove)
    {
        // Arrange
        using namespace InMemoryBus;

        MockISubscriberInformationRepository* p_repo =
                new MockISubscriberInformationRepository
                { };
        ISubscriberInformationRepository_SPtr repo(p_repo);
        MessageToSubscribers_SPtr sp_one =
                std::make_shared<MessageToSubscribers>("one", repo);
        MessageToSubscribers_SPtr sp_two =
                std::make_shared<MessageToSubscribers>("two", repo);

        MessageToSubscribersVector* p_vector = new MessageToSubscribersVector();
        MessageToSubscribersVector_SPtr sp_vector
        { p_vector };

        MessageToSubscribersRepository sut
        { sp_vector };

        sut.add(sp_one);
        sut.add(sp_two);
        auto actual = sut.getAll();
        EXPECT_EQ(2, actual->size());

        // Act
        sut.remove(sp_one);

        // Assert
        EXPECT_EQ(2, actual->size());
        EXPECT_EQ(1, sp_vector->size());
    }
}
