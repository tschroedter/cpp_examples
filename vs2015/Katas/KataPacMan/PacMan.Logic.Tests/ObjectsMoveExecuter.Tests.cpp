#include "stdafx.h"
#include <gtest/gtest.h>
#include "ObjectMover.h"
#include "MockIPlayingField.h"
#include "../PacMan.View.Tests/MockIPlayingFieldObject.h"
#include "MockIObjectMoveCalculator.h"
#include "ObjectsMover.h"
#include "ObjectsMoveExecuter.h"
#include "MockIMovingObjectsRepository.h"
#include "MoveObjectInformation.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            IMoveObjectInformation_Ptr create_information (
                PlayingFieldObjectType type,
                Row from_row,
                Column from_column,
                Row to_row,
                Column to_column )
            {
                auto p_info = new MoveObjectInformation{};
                IMoveObjectInformation_Ptr info{p_info};

                info->from_row = from_row;
                info->from_column = from_column;
                info->to_row = to_row;
                info->to_column = to_column;
                info->playing_field_object_type = type;

                return info;
            }

            TEST(ObjectsMoveExecuter, move_objects_moves_pacman)
            {
                // Arrange
                MockIPlayingField* mock_playing_field = new MockIPlayingField{};
                IPlayingField_Ptr playing_field(mock_playing_field);

                MockIObjectMoveCalculator* mock_calculator =
                    new MockIObjectMoveCalculator{};
                IObjectMoveCalculator_Ptr calculator(mock_calculator);

                MockIMovingObjectsRepository* mock_repository =
                    new MockIMovingObjectsRepository{};
                IMovingObjectsRepository_Ptr repository(mock_repository);

                MovingObjectsInformationVector* p_monsters = new MovingObjectsInformationVector{};
                MovingObjectsInformationVector_Ptr monsters{p_monsters};

                MovingObjectsInformationVector* p_pacmans = new MovingObjectsInformationVector{};
                MovingObjectsInformationVector_Ptr pacmans{p_pacmans};

                IMoveObjectInformation_Ptr pacman_info_one =
                    create_information(
                                       PlayingFieldObjectType_PacMan,
                                       Row(0),
                                       Column(1),
                                       Row(2),
                                       Column(3));
                pacmans->push_back(pacman_info_one);

                IMoveObjectInformation_Ptr pacman_info_two =
                    create_information(
                                       PlayingFieldObjectType_PacMan,
                                       Row(4),
                                       Column(5),
                                       Row(6),
                                       Column(7));
                pacmans->push_back(pacman_info_two);

                ObjectsMoveExecuter sut{};

                EXPECT_CALL(*mock_repository,
                    get_all_of_type(PlayingFieldObjectType_PacMan))
                                                                   .WillRepeatedly(testing::Return(pacmans));

                EXPECT_CALL(*mock_repository,
                    get_all_of_type(PlayingFieldObjectType_Monster))
                                                                    .WillRepeatedly(testing::Return(monsters));

                EXPECT_CALL(*mock_playing_field,
                    move_object_from_to(
                        Row(0),
                    Column(1),
                    Row(2),
                    Column(3)))
                               .Times(1);

                EXPECT_CALL(*mock_playing_field,
                    move_object_from_to(
                        Row(4),
                    Column(5),
                    Row(6),
                    Column(7)))
                               .Times(1);
                sut.initialize(
                               playing_field,
                               repository);

                // Act
                sut.move_objects();

                // Assert
            }

            TEST(ObjectsMoveExecuter, move_objects_moves_monsters)
            {
                // Arrange
                MockIPlayingField* mock_playing_field = new MockIPlayingField{};
                IPlayingField_Ptr playing_field(mock_playing_field);

                MockIObjectMoveCalculator* mock_calculator =
                    new MockIObjectMoveCalculator{};
                IObjectMoveCalculator_Ptr calculator(mock_calculator);

                MockIMovingObjectsRepository* mock_repository =
                    new MockIMovingObjectsRepository{};
                IMovingObjectsRepository_Ptr repository(mock_repository);

                MovingObjectsInformationVector* p_monsters = new MovingObjectsInformationVector{};
                MovingObjectsInformationVector_Ptr monsters{p_monsters};

                IMoveObjectInformation_Ptr pacman_info_one =
                    create_information(
                                       PlayingFieldObjectType_Monster,
                                       Row(0),
                                       Column(1),
                                       Row(2),
                                       Column(3));
                monsters->push_back(pacman_info_one);

                IMoveObjectInformation_Ptr pacman_info_two =
                    create_information(
                                       PlayingFieldObjectType_Monster,
                                       Row(4),
                                       Column(5),
                                       Row(6),
                                       Column(7));
                monsters->push_back(pacman_info_two);

                MovingObjectsInformationVector* p_pacmans = new MovingObjectsInformationVector{};
                MovingObjectsInformationVector_Ptr pacmans{p_pacmans};

                ObjectsMoveExecuter sut{};

                EXPECT_CALL(*mock_repository,
                    get_all_of_type(PlayingFieldObjectType_PacMan))
                                                                   .WillRepeatedly(testing::Return(pacmans));

                EXPECT_CALL(*mock_repository,
                    get_all_of_type(PlayingFieldObjectType_Monster))
                                                                    .WillRepeatedly(testing::Return(monsters));

                EXPECT_CALL(*mock_playing_field,
                    move_object_from_to(
                        Row(0),
                    Column(1),
                    Row(2),
                    Column(3)))
                               .Times(1);

                EXPECT_CALL(*mock_playing_field,
                    move_object_from_to(
                        Row(4),
                    Column(5),
                    Row(6),
                    Column(7)))
                               .Times(1);

                sut.initialize(
                               playing_field,
                               repository);

                // Act
                sut.move_objects();

                // Assert
            }
        };
    };
};
