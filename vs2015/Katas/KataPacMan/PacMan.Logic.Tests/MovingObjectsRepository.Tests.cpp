#include "stdafx.h"
#include <gtest/gtest.h>
#include "MockIDirection.h"
#include "MovingObjectsRepository.h"
#include "MoveObjectInformation.h"
#include <strstream>

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            IMoveObjectInformation_Ptr create_move_object_information (
                PlayingFieldObjectType type,
                Row from_row,
                Column from_column,
                Row to_row,
                Column to_column )
            {
                MoveObjectInformation* p_object = new MoveObjectInformation();
                p_object->from_row = from_row;
                p_object->from_column = from_column;
                p_object->to_row = to_row;
                p_object->to_column = to_column;

                IMoveObjectInformation_Ptr object{p_object};
                object->playing_field_object_type = type;

                return object;
            }

            IMoveObjectInformation_Ptr create_move_object_information (
                PlayingFieldObjectType type )
            {
                auto info =
                    create_move_object_information(
                                                   type,
                                                   Row(0),
                                                   Column(1),
                                                   Row(2),
                                                   Column(3));
                return info;
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

            TEST(MovingObjectsRepository, print_moves_returns_moves)
            {
                // Arrange
                IMoveObjectInformation_Ptr object_one =
                    create_move_object_information(
                                                   PlayingFieldObjectType_Monster,
                                                   Row(0),
                                                   Column(1),
                                                   Row(2),
                                                   Column(3));
                IMoveObjectInformation_Ptr object_two =
                    create_move_object_information(
                                                   PlayingFieldObjectType_PacMan,
                                                   Row(4),
                                                   Column(5),
                                                   Row(6),
                                                   Column(7));

                MovingObjectsInformationVector* p_vector = new MovingObjectsInformationVector{};
                MovingObjectsInformationVector_Ptr vector(p_vector);

                MovingObjectsRepository sut
                {
                    vector
                };

                sut.add(object_one);
                sut.add(object_two);

                std::stringstream out;

                // Act
                sut.print_moves(out);

                // Assert
                std::string actual = out.str();
                std::string expected = "[0] (0 , 1) --> (2, 3) Type: 4\n[1] (4 , 5) --> (6, 7) Type: 3\n";

                EXPECT_EQ(expected, actual);
            }
        };
    };
};
