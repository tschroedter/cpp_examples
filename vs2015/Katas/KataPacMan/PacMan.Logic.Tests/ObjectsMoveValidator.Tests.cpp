#include "stdafx.h"
#include "GameTimer.h"
#include <gtest/gtest.h>
#include "ObjectsMoveValidator.h"
#include "MockIMovingObjectsRepository.h"
#include "MoveObjectInformation.h"

TEST(ObjectsMoveValidator, initialize_sets_repository)
{
    using namespace PacMan::Logic;

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
    using namespace PacMan::Logic;

    // Arrange
    MockIMovingObjectsRepository* mock_repository =
        new MockIMovingObjectsRepository{};
    IMovingObjectsRepository_Ptr repository(mock_repository);

    ObjectsMoveValidator sut{};

    // Act
    sut.initialize(repository);

    // Assert
}

PacMan::Logic::IMoveObjectInformation_Ptr create_move (
    PacMan::Logic::PlayingFieldObjectType type,
    size_t to_row,
    size_t to_column )
{
    using namespace PacMan::Logic;

    auto p_information = new MoveObjectInformation{};
    IMoveObjectInformation_Ptr move{p_information};
    move->playing_field_object_type = type;
    move->to_row = to_row;
    move->to_column = to_column;

    return move;
}

TEST(ObjectsMoveValidator, calculate_status_depending_on_move_returns_ValidationStatus_PacMan_Death_for_monster_and_pacman_move_to_same_field)
{
    using namespace PacMan::Logic;

    // Arrange
    IMoveObjectInformation_Ptr move =
        create_move(PlayingFieldObjectType_PacMan,
                    size_t(1),
                    size_t(2));

    IMoveObjectInformation_Ptr other_one =
        create_move(PlayingFieldObjectType_Dot,
                    size_t(0),
                    size_t(0));

    IMoveObjectInformation_Ptr other_two =
        create_move(PlayingFieldObjectType_Monster,
                    size_t(1),
                    size_t(2));

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
    using namespace PacMan::Logic;

    // Arrange
    IMoveObjectInformation_Ptr move =
        create_move(PlayingFieldObjectType_PacMan,
                    size_t(1),
                    size_t(2));

    IMoveObjectInformation_Ptr other_one =
        create_move(PlayingFieldObjectType_Dot,
                    size_t(0),
                    size_t(0));

    IMoveObjectInformation_Ptr other_two =
        create_move(PlayingFieldObjectType_Monster,
                    size_t(1),
                    size_t(0));

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
    using namespace PacMan::Logic;

    // Arrange
    IMoveObjectInformation_Ptr move =
        create_move(PlayingFieldObjectType_PacMan,
                    size_t(1),
                    size_t(2));

    IMoveObjectInformation_Ptr other_one =
        create_move(PlayingFieldObjectType_Dot,
                    size_t(1),
                    size_t(2));

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
