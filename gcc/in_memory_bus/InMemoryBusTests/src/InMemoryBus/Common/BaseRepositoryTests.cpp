/*
 * SubscriberInformationRepositoryTests.cpp
 *
 *  Created on: 3Jul.,2017
 *      Author: tom
 */

#include <memory>
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "InMemoryBus/Common/BaseRepository.h"
#include "TestBaseEntity.h"

namespace InMemoryBusTests {
using namespace InMemoryBus::Common;

TEST(BaseRepository, add_adds_entity_to_vector) {
  // Arrange
  auto sp_entity = std::make_shared<TestBaseEntity>();
  auto sp_vector = std::make_shared<std::vector<std::shared_ptr<TestBaseEntity>>>();

  BaseRepository<TestBaseEntity> sut { sp_vector };

  // Act
  sut.add(sp_entity);

  // Assert
  EXPECT_EQ(1, sp_vector->size());
}

TEST(BaseRepository, add_adds_entities_to_vector) {
  // Arrange
  auto sp_entity_one = std::make_shared<TestBaseEntity>();
  auto sp_entity_two = std::make_shared<TestBaseEntity>();
  auto sp_vector = std::make_shared<std::vector<std::shared_ptr<TestBaseEntity>>>();

  BaseRepository<TestBaseEntity> sut { sp_vector };

  // Act
  sut.add(sp_entity_one);
  sut.add(sp_entity_two);

  // Assert
  EXPECT_EQ(2, sp_vector->size());
}

TEST(BaseRepository, remove_removes_entity_from_vector) {
  // Arrange
  auto sp_entity = std::make_shared<TestBaseEntity>();
  auto sp_vector = std::make_shared<std::vector<std::shared_ptr<TestBaseEntity>>>();

  BaseRepository<TestBaseEntity> sut { sp_vector };

  sut.add(sp_entity);

  // Act
  sut.remove(sp_entity);

  // Assert
  EXPECT_EQ(0, sp_vector->size());
}

TEST(BaseRepository, remove_removes_specific_entities_from_vector) {
  // Arrange
  auto sp_entity_one = std::make_shared<TestBaseEntity>();
  auto sp_entity_two = std::make_shared<TestBaseEntity>();
  auto sp_vector = std::make_shared<std::vector<std::shared_ptr<TestBaseEntity>>>();

  BaseRepository<TestBaseEntity> sut { sp_vector };

  sut.add(sp_entity_one);
  sut.add(sp_entity_two);

  // Act
  sut.remove(sp_entity_one);

  // Assert
  EXPECT_EQ(1, sp_vector->size());
}

TEST(BaseRepository, findBySubscriberId_returns_information) {
  // Arrange
  auto sp_entity = std::make_shared<TestBaseEntity>();
  auto sp_vector = std::make_shared<std::vector<std::shared_ptr<TestBaseEntity>>>();

  BaseRepository<TestBaseEntity> sut { sp_vector };

  sut.add(sp_entity);

  uuid_t id;
  sp_entity->get_id(id);

  // Act
  auto actual = sut.find_by_id(id);

  // Assert
  EXPECT_TRUE(sp_entity == actual);
}

TEST(BaseRepository, findBySubscriberId_returns_Unknown_For_Unknown_subscriber_id) {
  // Arrange
  auto sp_vector = std::make_shared<std::vector<std::shared_ptr<TestBaseEntity>>>();

  BaseRepository<TestBaseEntity> sut { sp_vector };

  uuid_t unknown_id;
  uuid_parse("00000000-0000-0000-0000-000000000000", unknown_id);

  // Act
  auto actual = sut.find_by_id(unknown_id);

  // Assert
  EXPECT_TRUE(actual == nullptr);
}

TEST(BaseRepository, get_all_returns_all_informations) {
  // Arrange
  auto sp_entity_one = std::make_shared<TestBaseEntity>();
  auto sp_entity_two = std::make_shared<TestBaseEntity>();
  auto sp_vector = std::make_shared<std::vector<std::shared_ptr<TestBaseEntity>>>();

  BaseRepository<TestBaseEntity> sut { sp_vector };

  sut.add(sp_entity_one);
  sut.add(sp_entity_two);

  // Act
  auto actual = sut.get_all();

  // Assert
  EXPECT_EQ(2, actual->size());
  EXPECT_TRUE(sp_entity_one == (*actual)[0]);
  EXPECT_TRUE(sp_entity_two == (*actual)[1]);
}

TEST(BaseRepository, get_all_returns_all_informations_indepently_from_add_or_remove) {
  // Arrange
  auto sp_entity_one = std::make_shared<TestBaseEntity>();
  auto sp_entity_two = std::make_shared<TestBaseEntity>();
  auto sp_vector = std::make_shared<std::vector<std::shared_ptr<TestBaseEntity>>>();

  BaseRepository<TestBaseEntity> sut { sp_vector };

  sut.add(sp_entity_one);
  sut.add(sp_entity_two);

  auto actual = sut.get_all();
  EXPECT_EQ(2, actual->size());

  // Act
  sut.remove(sp_entity_one);

  // Assert
  EXPECT_EQ(2, actual->size());
  EXPECT_EQ(1, sp_vector->size());
}
}
/* namespace InMemoryBusTests */
