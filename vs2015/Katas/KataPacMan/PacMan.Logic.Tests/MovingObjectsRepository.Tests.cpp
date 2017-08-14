#include "stdafx.h"
#include <gtest/gtest.h>
#include "MockIDirection.h"
#include "MovingObjectsRepository.h"
#include "MoveObjectInformation.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            IMoveObjectInformation_Ptr create_move_object_information (
                PlayingFieldObjectType type )
            {
                MoveObjectInformation* p_object = new MoveObjectInformation();
                IMoveObjectInformation_Ptr object{p_object};
                object->playing_field_object_type = type;

                return object;
            }

            TEST(MovingObjectsRepository, add_adds_item_to_vector)
            {
                // Arrange
                IMoveObjectInformation_Ptr object =
                    create_move_object_information(PlayingFieldObjectType_Monster);

                MovingObjectsInformationVector* p_vector = new MovingObjectsInformationVector{};
                MovingObjectsInformationVector_Ptr vector(p_vector);

                MovingObjectsRepository sut
                {
                    vector
                };

                // Act
                sut.add(object);

                // Assert
                EXPECT_EQ(1, vector->size());
            }

            TEST(MovingObjectsRepository, add_adds_multiple_items_to_vector)
            {
                // Arrange
                IMoveObjectInformation_Ptr object_one =
                    create_move_object_information(PlayingFieldObjectType_Monster);
                IMoveObjectInformation_Ptr object_two =
                    create_move_object_information(PlayingFieldObjectType_Monster);

                MovingObjectsInformationVector* p_vector = new MovingObjectsInformationVector{};
                MovingObjectsInformationVector_Ptr vector(p_vector);

                MovingObjectsRepository sut
                {
                    vector
                };

                // Act
                sut.add(object_one);
                sut.add(object_two);

                // Assert
                EXPECT_EQ(2, vector->size());
            }

            TEST(MovingObjectsRepository, get_all_returns_all_items)
            {
                // Arrange
                IMoveObjectInformation_Ptr object_one =
                    create_move_object_information(PlayingFieldObjectType_Monster);
                IMoveObjectInformation_Ptr object_two =
                    create_move_object_information(PlayingFieldObjectType_Monster);

                MovingObjectsInformationVector* p_vector = new MovingObjectsInformationVector{};
                MovingObjectsInformationVector_Ptr vector(p_vector);

                MovingObjectsRepository sut
                {
                    vector
                };

                sut.add(object_one);
                sut.add(object_two);

                // Act
                auto all = sut.get_all();

                // Assert
                EXPECT_EQ(2, all->size());
                EXPECT_EQ(object_one, (*all)[0]);
                EXPECT_EQ(object_two, (*all)[1]);
            }

            TEST(MovingObjectsRepository, get_all_of_type_returns_items_with_given_type)
            {
                // Arrange
                IMoveObjectInformation_Ptr object_one =
                    create_move_object_information(PlayingFieldObjectType_Monster);

                IMoveObjectInformation_Ptr object_two =
                    create_move_object_information(PlayingFieldObjectType_Monster);

                IMoveObjectInformation_Ptr object_three =
                    create_move_object_information(PlayingFieldObjectType_PacMan);

                MovingObjectsInformationVector* p_vector = new MovingObjectsInformationVector{};
                MovingObjectsInformationVector_Ptr vector(p_vector);

                MovingObjectsRepository sut
                {
                    vector
                };

                sut.add(object_one);
                sut.add(object_two);
                sut.add(object_three);

                // Act
                auto all = sut.get_all_of_type(PlayingFieldObjectType_Monster);

                // Assert
                EXPECT_EQ(2, all->size());
                EXPECT_EQ(object_one, (*all)[0]);
                EXPECT_EQ(object_two, (*all)[1]);
            }

            TEST(MovingObjectsRepository, clear_removes_all_items)
            {
                // Arrange
                IMoveObjectInformation_Ptr object_one =
                    create_move_object_information(PlayingFieldObjectType_Monster);
                IMoveObjectInformation_Ptr object_two =
                    create_move_object_information(PlayingFieldObjectType_Monster);

                MovingObjectsInformationVector* p_vector = new MovingObjectsInformationVector{};
                MovingObjectsInformationVector_Ptr vector(p_vector);

                MovingObjectsRepository sut
                {
                    vector
                };

                sut.add(object_one);
                sut.add(object_two);

                // Act
                sut.clear();

                // Assert
                EXPECT_EQ(0, vector->size());
            }
        };
    };
};
