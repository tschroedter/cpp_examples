#include "stdafx.h"
#include "GameTimer.h"
#include <gtest/gtest.h>
#include "ObjectsMoveValidator.h"
#include "MockIMovingObjectsRepository.h"
#include "MoveObjectInformation.h"

using namespace PacMan::Logic;

TEST(ObjectsMoveValidator, initialize_sets_repository)
{
    // Arrange
    MockIMovingObjectsRepository* mock_repository =
        new MockIMovingObjectsRepository{};
    IMovingObjectsRepository_Ptr repository(mock_repository);


    ObjectsMoveValidator sut{};

    // Act
    sut.initialize(repository);

    // Assert
    EXPECT_EQ(ValidationStatus_Unknown, sut.get_status());
}

TEST(ObjectsMoveValidator, get_status_returns_status)
{
    // Arrange
    MockIMovingObjectsRepository* mock_repository =
        new MockIMovingObjectsRepository{};
    IMovingObjectsRepository_Ptr repository(mock_repository);

    ObjectsMoveValidator sut{};

    // Act
    sut.initialize(repository);

    // Assert
}

IMoveObjectInformation_Ptr create_move (
    PlayingFieldObjectType type,
    Row to_row,
    Column to_column )
{
    auto p_information = new MoveObjectInformation{};
    IMoveObjectInformation_Ptr move{p_information};
    move->playing_field_object_type = type;
    move->to_row = to_row;
    move->to_column = to_column;

    return move;
}

TEST(ObjectsMoveValidator, calculate_status_depending_on_move_returns_ValidationStatus_PacMan_Death_for_monster_and_pacman_move_to_same_field)
{
    // Arrange
    IMoveObjectInformation_Ptr move =
        create_move(PlayingFieldObjectType_PacMan,
                    Row(1),
                    Column(2));

    IMoveObjectInformation_Ptr other_one =
        create_move(PlayingFieldObjectType_Dot,
                    Row(0),
                    Column(0));

    IMoveObjectInformation_Ptr other_two =
        create_move(PlayingFieldObjectType_Monster,
                    Row(1),
                    Column(2));

    auto p_other_moves = new MovingObjectsInformationVector();
    MovingObjectsInformationVector_Ptr other_moves{p_other_moves};

    other_moves->push_back(move);
    other_moves->push_back(other_one);
    other_moves->push_back(other_two);

    MockIMovingObjectsRepository* mock_repository =
        new MockIMovingObjectsRepository{};
    IMovingObjectsRepository_Ptr repository(mock_repository);

    EXPECT_CALL(*mock_repository,
        get_all())
                  .WillRepeatedly(testing::Return(other_moves));

    ObjectsMoveValidator sut{};
    sut.initialize(repository);

    // Act
    sut.validate_moves();

    // Assert
    EXPECT_EQ(ValidationStatus_PacMan_Death, sut.get_status());
}

TEST(ObjectsMoveValidator, calculate_status_depending_on_move_returns_ValidationStatus_PacMan_ALive_for_monster_and_pacman_move_to_different_fields)
{
    // Arrange
    IMoveObjectInformation_Ptr move =
        create_move(PlayingFieldObjectType_PacMan,
                    Row(1),
                    Column(2));

    IMoveObjectInformation_Ptr other_one =
        create_move(PlayingFieldObjectType_Dot,
                    Row(0),
                    Column(0));

    IMoveObjectInformation_Ptr other_two =
        create_move(PlayingFieldObjectType_Monster,
                    Row(1),
                    Column(0));

    auto p_other_moves = new MovingObjectsInformationVector();
    MovingObjectsInformationVector_Ptr other_moves{p_other_moves};

    other_moves->push_back(move);
    other_moves->push_back(other_one);
    other_moves->push_back(other_two);

    MockIMovingObjectsRepository* mock_repository =
        new MockIMovingObjectsRepository{};
    IMovingObjectsRepository_Ptr repository(mock_repository);

    EXPECT_CALL(*mock_repository,
        get_all())
                  .WillRepeatedly(testing::Return(other_moves));

    ObjectsMoveValidator sut{};
    sut.initialize(repository);

    // Act
    sut.validate_moves();

    // Assert
    EXPECT_EQ(ValidationStatus_PacMan_ALive, sut.get_status());
}

TEST(ObjectsMoveValidator, calculate_status_depending_on_move_returns_ValidationStatus_PacMan_ALive_for_dot_and_pacman_move_to_same_field)
{
    // Arrange
    IMoveObjectInformation_Ptr move =
        create_move(PlayingFieldObjectType_PacMan,
                    Row(1),
                    Column(2));

    IMoveObjectInformation_Ptr other_one =
        create_move(PlayingFieldObjectType_Dot,
                    Row(1),
                    Column(2));

    auto p_other_moves = new MovingObjectsInformationVector();
    MovingObjectsInformationVector_Ptr other_moves{p_other_moves};

    other_moves->push_back(move);
    other_moves->push_back(other_one);

    MockIMovingObjectsRepository* mock_repository =
        new MockIMovingObjectsRepository{};
    IMovingObjectsRepository_Ptr repository(mock_repository);

    EXPECT_CALL(*mock_repository,
        get_all())
                  .WillRepeatedly(testing::Return(other_moves));

    ObjectsMoveValidator sut{};
    sut.initialize(repository);

    // Act
    sut.validate_moves();

    // Assert
    EXPECT_EQ(ValidationStatus_PacMan_ALive, sut.get_status());
}
