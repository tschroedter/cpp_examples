#include <memory>
#include <iostream>
#include <gtest/gtest.h>
#include "../../Common.h"
#include "InMemoryBus/Subscribtions/MessageToSubscribers/IMessageToSubscribersEntity.h"
#include "InMemoryBus/Subscribtions/MessageToSubscribers/MessageToSubscribersEntity.h"
#include "InMemoryBus/Subscribtions/MessageToSubscribers/MessageToSubscribersRepository.h"
#include "InMemoryBus/Subscribtions/Subscribers/Threadsafe/IThreadSafeSubscriberInformationRepository.h"
#include "../../Mocks/MockIThreadSafeSubscriberInformationRepository.h"

namespace InMemoryBusTests {
using namespace InMemoryBus::Subscribtions::MessageToSubscribers;

TEST(MessageToSubscribersRepositoryTests, add_adds_item_to_vector_once) {
  // Arrange
  MockIThreadSafeSubscriberInformationRepository* p_repo = new MockIThreadSafeSubscriberInformationRepository { };
  IThreadSafeSubscriberInformationRepository_SPtr repo(p_repo);
  IMessageToSubscribersEntity_SPtr entity = std::make_shared<MessageToSubscribersEntity>("type", repo);

  IMessageToSubscribersEntityVector* p_vector = new IMessageToSubscribersEntityVector();
  IMessageToSubscribersEntityVector_SPtr sp_vector { p_vector };

  MessageToSubscribersRepository sut { sp_vector };

  // Act
  sut.add(entity);

  // Assert
  EXPECT_EQ(1, sp_vector->size());
}

TEST(MessageToSubscribersRepositoryTests, add_adds_item_to_vector_multiple) {
  // Arrange
  MockIThreadSafeSubscriberInformationRepository* p_repo = new MockIThreadSafeSubscriberInformationRepository { };
  IThreadSafeSubscriberInformationRepository_SPtr repo(p_repo);
  IMessageToSubscribersEntity_SPtr sp_one = std::make_shared<MessageToSubscribersEntity>("one", repo);
  IMessageToSubscribersEntity_SPtr sp_two = std::make_shared<MessageToSubscribersEntity>("two", repo);

  IMessageToSubscribersEntityVector* p_vector = new IMessageToSubscribersEntityVector();
  IMessageToSubscribersEntityVector_SPtr sp_vector { p_vector };

  MessageToSubscribersRepository sut { sp_vector };

  // Act
  sut.add(sp_one);
  sut.add(sp_two);

  // Assert
  EXPECT_EQ(2, sp_vector->size());
}

TEST(MessageToSubscribersRepositoryTests, remove_removes_item_from_vector) {
  // Arrange
  MockIThreadSafeSubscriberInformationRepository* p_repo = new MockIThreadSafeSubscriberInformationRepository { };
  IThreadSafeSubscriberInformationRepository_SPtr repo(p_repo);
  IMessageToSubscribersEntity_SPtr sp_one = std::make_shared<MessageToSubscribersEntity>("type", repo);

  IMessageToSubscribersEntityVector* p_vector = new IMessageToSubscribersEntityVector();
  IMessageToSubscribersEntityVector_SPtr sp_vector { p_vector };

  MessageToSubscribersRepository sut { sp_vector };

  sut.add(sp_one);

  // Act
  sut.remove(sp_one);

  // Assert
  EXPECT_EQ(0, sp_vector->size());
}

TEST(MessageToSubscribersRepositoryTests, remove_removes_selected_item_from_vector) {
  // Arrange
  MockIThreadSafeSubscriberInformationRepository* p_repo = new MockIThreadSafeSubscriberInformationRepository { };
  IThreadSafeSubscriberInformationRepository_SPtr repo(p_repo);
  IMessageToSubscribersEntity_SPtr sp_one = std::make_shared<MessageToSubscribersEntity>("one", repo);
  IMessageToSubscribersEntity_SPtr sp_two = std::make_shared<MessageToSubscribersEntity>("two", repo);

  IMessageToSubscribersEntityVector* p_vector = new IMessageToSubscribersEntityVector();
  IMessageToSubscribersEntityVector_SPtr sp_vector { p_vector };

  MessageToSubscribersRepository sut { sp_vector };

  sut.add(sp_one);
  sut.add(sp_two);

  // Act
  sut.remove(sp_one);

  // Assert
  EXPECT_EQ(1, sp_vector->size());
}

TEST(MessageToSubscribersRepositoryTests, findBySubscriberId_returns_item) {
  // Arrange
  MockIThreadSafeSubscriberInformationRepository* p_repo = new MockIThreadSafeSubscriberInformationRepository { };
  IThreadSafeSubscriberInformationRepository_SPtr repo(p_repo);
  IMessageToSubscribersEntity_SPtr sp_one = std::make_shared<MessageToSubscribersEntity>("type", repo);

  IMessageToSubscribersEntityVector* p_vector = new IMessageToSubscribersEntityVector();
  IMessageToSubscribersEntityVector_SPtr sp_vector { p_vector };

  MessageToSubscribersRepository sut { sp_vector };

  sut.add(sp_one);

  // Act
  auto actual = sut.find_subscriber_by_message_type(sp_one->get_message_type());

  // Assert
  EXPECT_TRUE(sp_one == actual);
}

TEST(MessageToSubscribersRepositoryTests, findBySubscriberId_returns_Unknown_For_Unknown_subscriber_id) {
  // Arrange
  IMessageToSubscribersEntityVector* p_vector = new IMessageToSubscribersEntityVector();
  IMessageToSubscribersEntityVector_SPtr sp_vector { p_vector };

  MessageToSubscribersRepository sut { sp_vector };

  // Act
  auto subscriber = sut.find_subscriber_by_message_type("unknown subscriber_id");

  // Assert
  std::string actual = subscriber->get_message_type();
  InMemoryBusTest::expect_std_strings_are_equal("Unknown", actual);
}

TEST(MessageToSubscribersRepositoryTests, get_all_returns_all_informations) {
  // Arrange
  MockIThreadSafeSubscriberInformationRepository* p_repo = new MockIThreadSafeSubscriberInformationRepository { };
  IThreadSafeSubscriberInformationRepository_SPtr repo(p_repo);
  IMessageToSubscribersEntity_SPtr sp_one = std::make_shared<MessageToSubscribersEntity>("one", repo);
  IMessageToSubscribersEntity_SPtr sp_two = std::make_shared<MessageToSubscribersEntity>("two", repo);

  IMessageToSubscribersEntityVector* p_vector = new IMessageToSubscribersEntityVector();
  IMessageToSubscribersEntityVector_SPtr sp_vector { p_vector };

  MessageToSubscribersRepository sut { sp_vector };

  sut.add(sp_one);
  sut.add(sp_two);

  // Act
  auto actual = sut.get_all_subscribers();

  // Assert
  EXPECT_EQ(2, actual->size());
  EXPECT_TRUE(sp_one == (*actual)[0]);
  EXPECT_TRUE(sp_two == (*actual)[1]);
}

TEST(MessageToSubscribersRepositoryTests, get_all_returns_all_informations_indepently_from_add_or_remove) {
  // Arrange
  MockIThreadSafeSubscriberInformationRepository* p_repo = new MockIThreadSafeSubscriberInformationRepository { };
  IThreadSafeSubscriberInformationRepository_SPtr repo(p_repo);
  IMessageToSubscribersEntity_SPtr sp_one = std::make_shared<MessageToSubscribersEntity>("one", repo);
  IMessageToSubscribersEntity_SPtr sp_two = std::make_shared<MessageToSubscribersEntity>("two", repo);

  IMessageToSubscribersEntityVector* p_vector = new IMessageToSubscribersEntityVector();
  IMessageToSubscribersEntityVector_SPtr sp_vector { p_vector };

  MessageToSubscribersRepository sut { sp_vector };

  sut.add(sp_one);
  sut.add(sp_two);
  auto actual = sut.get_all_subscribers();
  EXPECT_EQ(2, actual->size());

  // Act
  sut.remove(sp_one);

  // Assert
  EXPECT_EQ(2, actual->size());
  EXPECT_EQ(1, sp_vector->size());
}

}
