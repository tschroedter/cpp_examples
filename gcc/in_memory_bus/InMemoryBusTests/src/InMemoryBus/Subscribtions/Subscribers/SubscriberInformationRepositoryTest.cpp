#include <memory>
#include <iostream>
#include <gtest/gtest.h>
#include "InMemoryBus/Common/BaseMessage.h"
#include "InMemoryBus/Subscribtions/Subscribers/SubscriberInformationEntity.h"
#include "InMemoryBus/Subscribtions/Subscribers/SubscriberInformationRepository.h"

namespace InMemoryBusTests {
using namespace InMemoryBus::Subscribtions::Subscribers;

void doNothingSubscriberFunction(BaseMessage_SPtr base_message) { // TODO rename
}

TEST(SubscriberInformationRepositoryTest, add_adds_information_to_vector) {
  // Arrange
  auto p_info = new SubscriberInformationEntity("id", "type", doNothingSubscriberFunction);
  ISubscriberInformationEntity_SPtr info(p_info);

  auto entities = std::make_shared<ISubscriberInformationEntityVector>();

  SubscriberInformationRepository sut { entities };

  // Act
  sut.add(info);

  // Assert
  EXPECT_EQ(1, entities->size());
}

TEST(SubscriberInformationRepositoryTest, add_adds_informations_to_vector) {
  // Arrange
  auto p_info_one = new SubscriberInformationEntity("id1", "type", doNothingSubscriberFunction);
  ISubscriberInformationEntity_SPtr info_one(p_info_one);

  auto p_info_two = new SubscriberInformationEntity("id1", "type", doNothingSubscriberFunction);
  ISubscriberInformationEntity_SPtr info_two(p_info_two);

  auto entities = std::make_shared<ISubscriberInformationEntityVector>();

  SubscriberInformationRepository sut { entities };

  // Act
  sut.add(info_one);
  sut.add(info_two);

  // Assert
  EXPECT_EQ(2, entities->size());
}

TEST(SubscriberInformationRepositoryTest, remove_removes_information_from_vector) {
  // Arrange
  using namespace InMemoryBus;

  auto p_info = new SubscriberInformationEntity("id", "type", doNothingSubscriberFunction);
  ISubscriberInformationEntity_SPtr info(p_info);

  auto entities = std::make_shared<ISubscriberInformationEntityVector>();

  SubscriberInformationRepository sut { entities };

  sut.add(info);

  // Act
  sut.remove(info);

  // Assert
  EXPECT_EQ(0, entities->size());
}

TEST(SubscriberInformationRepositoryTest, remove_removes_specific_information_from_vector) {
  // Arrange
  using namespace InMemoryBus;

  auto p_info_one = new SubscriberInformationEntity("id1", "type", doNothingSubscriberFunction);
  ISubscriberInformationEntity_SPtr info_one(p_info_one);

  auto p_info_two = new SubscriberInformationEntity("id1", "type", doNothingSubscriberFunction);
  ISubscriberInformationEntity_SPtr info_two(p_info_two);

  auto entities = std::make_shared<ISubscriberInformationEntityVector>();

  SubscriberInformationRepository sut { entities };

  sut.add(info_one);
  sut.add(info_two);

  // Act
  sut.remove(info_one);

  // Assert
  EXPECT_EQ(1, entities->size());
}

TEST(SubscriberInformationRepositoryTest, find_subscriber_by_id_returns_information) {
  // Arrange
  using namespace InMemoryBus;

  auto p_info = new SubscriberInformationEntity("id", "type", doNothingSubscriberFunction);
  ISubscriberInformationEntity_SPtr info(p_info);

  auto entities = std::make_shared<ISubscriberInformationEntityVector>();

  SubscriberInformationRepository sut { entities };

  sut.add(info);

  // Act
  auto actual = sut.find_subscriber_by_id(info->get_subscriber_id());

  // Assert
  EXPECT_TRUE(info == actual);
}

TEST(SubscriberInformationRepositoryTest, find_subscriber_by_id_returns_Unknown_For_Unknown_subscriber_id) {
  // Arrange
  using namespace InMemoryBus;

  auto p_info = new SubscriberInformationEntity("id", "type", doNothingSubscriberFunction);
  ISubscriberInformationEntity_SPtr info(p_info);

  auto entities = std::make_shared<ISubscriberInformationEntityVector>();

  SubscriberInformationRepository sut { entities };

  sut.add(info);

  // Act
  auto actual = sut.find_subscriber_by_id("unknown subscriber_id");

  // Assert
  EXPECT_TRUE(actual->get_subscriber_id().compare("Unknown") == 0);
}

TEST(SubscriberInformationRepositoryTest, get_all_subscribers_returns_all_informations) {
  // Arrange
  auto p_info_one = new SubscriberInformationEntity("id1", "type", doNothingSubscriberFunction);
  ISubscriberInformationEntity_SPtr info_one(p_info_one);

  auto p_info_two = new SubscriberInformationEntity("id1", "type", doNothingSubscriberFunction);
  ISubscriberInformationEntity_SPtr info_two(p_info_two);

  auto entities = std::make_shared<ISubscriberInformationEntityVector>();

  SubscriberInformationRepository sut { entities };

  sut.add(info_one);
  sut.add(info_two);

  // Act
  auto actual = sut.get_all_subscribers();

  // Assert
  EXPECT_EQ(2, actual->size());
  EXPECT_TRUE(info_one == (*actual)[0]);
  EXPECT_TRUE(info_two == (*actual)[1]);
}

TEST(SubscriberInformationRepositoryTest, get_all_subscribers_returns_all_informations_indepently_from_add_or_remove) {
  // Arrange
  auto p_info_one = new SubscriberInformationEntity("id1", "type", doNothingSubscriberFunction);
  ISubscriberInformationEntity_SPtr info_one(p_info_one);

  auto p_info_two = new SubscriberInformationEntity("id1", "type", doNothingSubscriberFunction);
  ISubscriberInformationEntity_SPtr info_two(p_info_two);

  auto entities = std::make_shared<ISubscriberInformationEntityVector>();

  SubscriberInformationRepository sut { entities };

  sut.add(info_one);
  sut.add(info_two);
  auto actual = sut.get_all_subscribers();
  EXPECT_EQ(2, actual->size());

  // Act
  sut.remove(info_one);

  // Assert
  EXPECT_EQ(2, actual->size());
  EXPECT_EQ(1, entities->size());
}
}
