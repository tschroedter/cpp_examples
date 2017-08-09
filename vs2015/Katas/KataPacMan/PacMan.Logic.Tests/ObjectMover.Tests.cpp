#include "stdafx.h"
#include <gtest/gtest.h>
#include "ObjectMover.h"
#include "MockIPlayingField.h"
#include "../PacMan.View.Tests/MockIPlayingFieldObject.h"
#include "MockIObjectMoveCalculator.h"
#include "ObjectsMover.h"

TEST(ObjectMover, initialize_calls_calculator_initialize)
{
    using namespace PacMan::Logic;

    // Arrange
    MockIPlayingField* mock_playing_field = new MockIPlayingField{};
    IPlayingField_Ptr playing_field(mock_playing_field);

    MockIObjectMoveCalculator* mock_calculator =
        new MockIObjectMoveCalculator{};
    IObjectMoveCalculator_Ptr calculator(mock_calculator);

    ObjectMover sut
    {
        calculator
    };

    EXPECT_CALL(*mock_calculator,
        initialize(
            playing_field))
                           .Times(1);

    // Act
    sut.initialize(playing_field);

    // Assert
}

TEST(ObjectMover, move_object_does_not_calls_calculator_calculate_for_is_moveable_is_false)
{
    using namespace PacMan::Logic;

    // Arrange
    size_t row(1);
    size_t column(2);
    Heading heading = Heading_Left;

    MockIPlayingFieldObject* mock_object = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object(mock_object);

    MockIPlayingField* mock_playing_field = new MockIPlayingField{};
    IPlayingField_Ptr playing_field(mock_playing_field);

    MockIObjectMoveCalculator* mock_calculator =
        new MockIObjectMoveCalculator{};
    IObjectMoveCalculator_Ptr calculator(mock_calculator);

    ObjectMover sut
    {
        calculator
    };

    sut.initialize(playing_field);

    EXPECT_CALL(*mock_playing_field,
        get_object_at(row, column))
                                   .WillRepeatedly(testing::Return(object));

    EXPECT_CALL(*mock_object,
        is_moveable())
                      .WillRepeatedly(testing::Return(false));

    EXPECT_CALL(*mock_object,
        is_moving())
                    .WillRepeatedly(testing::Return(true));

    EXPECT_CALL(*mock_object,
        get_type())
                   .WillRepeatedly(testing::Return(PlayingFieldObjectType_Unknown));

    EXPECT_CALL(*mock_calculator,
        calculate(
            row,
            column,
            heading))
                     .Times(0);

    // Act
    sut.move_object(row, column);

    // Assert
}

TEST(ObjectMover, move_object_does_not_calls_calculator_calculate_for_is_moving_is_false)
{
    using namespace PacMan::Logic;

    // Arrange
    size_t row(1);
    size_t column(2);
    Heading heading = Heading_Left;

    MockIPlayingFieldObject* mock_object = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object(mock_object);

    MockIPlayingField* mock_playing_field = new MockIPlayingField{};
    IPlayingField_Ptr playing_field(mock_playing_field);

    MockIObjectMoveCalculator* mock_calculator =
        new MockIObjectMoveCalculator{};
    IObjectMoveCalculator_Ptr calculator(mock_calculator);

    ObjectMover sut
    {
        calculator
    };

    sut.initialize(playing_field);

    EXPECT_CALL(*mock_playing_field,
        get_object_at(row, column))
                                   .WillRepeatedly(testing::Return(object));

    EXPECT_CALL(*mock_object,
        is_moveable())
                      .WillRepeatedly(testing::Return(true));

    EXPECT_CALL(*mock_object,
        is_moving())
                    .WillRepeatedly(testing::Return(false));

    EXPECT_CALL(*mock_object,
        get_type())
                   .WillRepeatedly(testing::Return(PlayingFieldObjectType_Unknown));

    EXPECT_CALL(*mock_calculator,
        calculate(
            row,
            column,
            heading))
                     .Times(0);

    // Act
    sut.move_object(row, column);

    // Assert
}

TEST(ObjectMover, move_object_calls_calculator_calculate)
{
    using namespace PacMan::Logic;

    // Arrange
    size_t row(1);
    size_t column(2);
    Heading heading = Heading_Left;

    MockIPlayingFieldObject* mock_object = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object(mock_object);

    MockIPlayingField* mock_playing_field = new MockIPlayingField{};
    IPlayingField_Ptr playing_field(mock_playing_field);

    MockIObjectMoveCalculator* mock_calculator =
        new MockIObjectMoveCalculator{};
    IObjectMoveCalculator_Ptr calculator(mock_calculator);

    ObjectMover sut
    {
        calculator
    };

    sut.initialize(playing_field);

    EXPECT_CALL(*mock_playing_field,
        get_object_at(row, column))
                                   .WillRepeatedly(testing::Return(object));

    EXPECT_CALL(*mock_object,
        is_moveable())
                      .WillRepeatedly(testing::Return(true));

    EXPECT_CALL(*mock_object,
        is_moving())
                    .WillRepeatedly(testing::Return(true));

    EXPECT_CALL(*mock_object,
        get_type())
                   .WillRepeatedly(testing::Return(PlayingFieldObjectType_Unknown));

    EXPECT_CALL(*mock_object,
        get_heading())
                      .WillRepeatedly(testing::Return(heading));

    EXPECT_CALL(*mock_calculator,
        calculate(
            row,
            column,
            heading))
                     .Times(1);

    // Act
    sut.move_object(row, column);

    // Assert
}

TEST(ObjectMover, move_object_calls_playing_field_move_object_from_to)
{
    using namespace PacMan::Logic;

    // Arrange
    size_t from_row(1);
    size_t from_column(2);
    Heading heading = Heading_Left;
    size_t to_row(3);
    size_t to_column(4);

    MockIPlayingFieldObject* mock_object = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object(mock_object);

    MockIPlayingField* mock_playing_field = new MockIPlayingField{};
    IPlayingField_Ptr playing_field(mock_playing_field);

    MockIObjectMoveCalculator* mock_calculator =
        new MockIObjectMoveCalculator{};
    IObjectMoveCalculator_Ptr calculator(mock_calculator);

    ObjectMover sut
    {
        calculator
    };

    sut.initialize(playing_field);

    EXPECT_CALL(*mock_playing_field,
        get_object_at(from_row, from_column))
                                             .WillRepeatedly(testing::Return(object));

    EXPECT_CALL(*mock_object,
        is_moveable())
                      .WillRepeatedly(testing::Return(true));

    EXPECT_CALL(*mock_object,
        is_moving())
                    .WillRepeatedly(testing::Return(true));

    EXPECT_CALL(*mock_object,
        get_type())
                   .WillRepeatedly(testing::Return(PlayingFieldObjectType_Unknown));

    EXPECT_CALL(*mock_object,
        get_heading())
                      .WillRepeatedly(testing::Return(heading));

    EXPECT_CALL(*mock_calculator,
        calculate(
            from_row,
            from_column,
            heading))
                     .Times(1);

    mock_calculator->to_row = to_row;
    mock_calculator->to_column = to_column;

    EXPECT_CALL(*mock_playing_field,
        move_object_from_to(
            from_row,
            from_column,
            to_row,
            to_column))
                       .Times(1);
    // Act
    sut.move_object(from_row, from_column);

    // Assert
}
