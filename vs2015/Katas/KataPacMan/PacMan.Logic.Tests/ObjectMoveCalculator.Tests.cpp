#include "stdafx.h"
#include <gtest/gtest.h>
#include "ObjectMoveCalculator.h"
#include "MockIPlayingField.h"
#include "../PacMan.View.Tests/MockIPlayingFieldObject.h"

using namespace PacMan::Logic;

IPlayingField_Ptr create_playing_field_for_ObjectMoveCalculator (
    const size_t expectedCalledTimes,
    const Row expectedRow,
    const Column expectedColumn )
{
    using namespace PacMan::Logic;

    MockIPlayingField* mock_playing_field = new MockIPlayingField{};

    EXPECT_CALL(*mock_playing_field,
        get_rows())
                   .WillRepeatedly(testing::Return(Row(4)));
    EXPECT_CALL(*mock_playing_field,
        get_columns())
                      .WillRepeatedly(testing::Return(Column(4)));

    IPlayingField_Ptr playing_field{mock_playing_field};

    return playing_field;
}

void TEST_move_object_from_to_n_times_with_start_position_1_1_for_ObjectMoveCalculator (
    const Heading heading,
    const size_t times,
    const size_t expectedCalledTimes,
    const Row expectedRow,
    const Column expectedColumn )
{
    using namespace PacMan::Logic;

    std::cout
        << "heading: "
        << heading
        << " times: "
        << times
        << " expectedRow: "
        << expectedRow
        << " expectedColumn: "
        << expectedColumn << "\n";

    // Arrange
    IPlayingField_Ptr playing_field =
        create_playing_field_for_ObjectMoveCalculator(expectedCalledTimes,
                                                      expectedRow,
                                                      expectedColumn);

    ObjectMoveCalculator sut{};

    sut.initialize(playing_field);

    // Act
    // Assert
    for (int i = 0; i < times; i++)
    {
        sut.calculate(Row(1),
                      Column(1),
                      heading);

        EXPECT_EQ(expectedRow, sut.to_row);
        EXPECT_EQ(expectedColumn, sut.to_column);
    }
}

void TEST_move_object_from_to_with_start_position_1_1_for_ObjectMoveCalculator (
    const Heading heading,
    const Row expectedRow,
    const Column expectedColumn )
{
    using namespace PacMan::Logic;

    TEST_move_object_from_to_n_times_with_start_position_1_1_for_ObjectMoveCalculator(
                                                                                      heading,
                                                                                      size_t(1),
                                                                                      size_t(1),
                                                                                      expectedRow,
                                                                                      expectedColumn);
}

TEST(ObjectMoveCalculator, move_object_calls_playing_field_for_heading_left)
{
    TEST_move_object_from_to_with_start_position_1_1_for_ObjectMoveCalculator(Heading_Left,
                                                                              Row(1),
                                                                              Column(0));
}

TEST(ObjectMoveCalculator, move_object_calls_playing_field_for_heading_right)
{
    TEST_move_object_from_to_with_start_position_1_1_for_ObjectMoveCalculator(Heading_Right,
                                                                              Column(1),
                                                                              size_t(2));
}

TEST(ObjectMoveCalculator, move_object_calls_playing_field_for_heading_up)
{
    TEST_move_object_from_to_with_start_position_1_1_for_ObjectMoveCalculator(Heading_Up,
                                                                              Row(0),
                                                                              Column(1));
}

TEST(ObjectMoveCalculator, move_object_calls_playing_field_for_heading_down)
{
    TEST_move_object_from_to_with_start_position_1_1_for_ObjectMoveCalculator(Heading_Down,
                                                                              Row(2),
                                                                              Column(1));
}

TEST(ObjectMoveCalculator, move_object_calls_playing_field_for_heading_left_multiple_times)
{
    TEST_move_object_from_to_n_times_with_start_position_1_1_for_ObjectMoveCalculator(
                                                                                      Heading_Left,
                                                                                      size_t(2),
                                                                                      size_t(2),
                                                                                      Row(1),
                                                                                      Column(0));
}

TEST(ObjectMoveCalculator, move_object_calls_playing_field_for_heading_right_multiple_times)
{
    TEST_move_object_from_to_n_times_with_start_position_1_1_for_ObjectMoveCalculator(
                                                                                      Heading_Right,
                                                                                      size_t(2),
                                                                                      size_t(2),
                                                                                      Row(1),
                                                                                      Column(2));
}

TEST(ObjectMoveCalculator, move_object_calls_playing_field_for_heading_up_multiple_times)
{
    TEST_move_object_from_to_n_times_with_start_position_1_1_for_ObjectMoveCalculator(
                                                                                      Heading_Up,
                                                                                      size_t(2),
                                                                                      size_t(2),
                                                                                      Row(0),
                                                                                      Column(1));
}

TEST(ObjectMoveCalculator, move_object_calls_playing_field_for_heading_down_multiple_times)
{
    TEST_move_object_from_to_n_times_with_start_position_1_1_for_ObjectMoveCalculator(
                                                                                      Heading_Down,
                                                                                      size_t(2),
                                                                                      size_t(2),
                                                                                      Row(2),
                                                                                      Column(1));
}
