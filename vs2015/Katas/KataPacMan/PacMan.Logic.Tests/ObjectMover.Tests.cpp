#include "stdafx.h"
#include <gtest/gtest.h>
#include "ObjectMover.h"
#include "MockIPlayingField.h"
#include "../PacMan.View.Tests/MockIPlayingFieldObject.h"
#include "MockIObjectMoveCalculator.h"

PacMan::Logic::IObjectMoveCalculator_Ptr create_calculator()
{
    using namespace PacMan::Logic;

    MockIObjectMoveCalculator* mock_object = new MockIObjectMoveCalculator{};

    IObjectMoveCalculator_Ptr object{ mock_object };

    return object;
}

PacMan::Logic::IPlayingFieldObject_Ptr create_object(
    PacMan::Logic::Heading heading)
{
    using namespace PacMan::Logic;

    MockIPlayingFieldObject* mock_object = new MockIPlayingFieldObject{};

    EXPECT_CALL(*mock_object,
        get_type())
        .WillRepeatedly(testing::Return(PlayingFieldObjectType_PacMan));

    EXPECT_CALL(*mock_object,
        is_moving())
        .WillRepeatedly(testing::Return(true));

    EXPECT_CALL(*mock_object,
        get_heading())
        .WillRepeatedly(testing::Return(heading));

    IPlayingFieldObject_Ptr object{ mock_object };

    return object;
}

PacMan::Logic::IPlayingField_Ptr create_playing_field(
    PacMan::Logic::IPlayingFieldObject_Ptr object,
    const size_t expectedCalledTimes,
    const size_t expectedRow,
    const size_t expectedColumn)
{
    using namespace PacMan::Logic;

    MockIPlayingField* mock_playing_field = new MockIPlayingField{};

    EXPECT_CALL(*mock_playing_field,
        get_object_at(size_t(1), size_t(1)))
        .WillRepeatedly(testing::Return(object));

    EXPECT_CALL(*mock_playing_field,
        get_rows())
        .WillRepeatedly(testing::Return(size_t(3)));
    EXPECT_CALL(*mock_playing_field,
        get_columns())
        .WillRepeatedly(testing::Return(size_t(3)));
    EXPECT_CALL(*mock_playing_field,
        move_object_from_to(
            size_t(1),
            size_t(1),
            expectedRow,
            expectedColumn))
        .Times(expectedCalledTimes);

    IPlayingField_Ptr playing_field{ mock_playing_field };

    return playing_field;
}

void TEST_move_object_from_to_n_times_with_start_position_1_1(
    const PacMan::Logic::Heading heading,
    const size_t times,
    const size_t expectedCalledTimes,
    const size_t expectedRow,
    const size_t expectedColumn)
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
    IPlayingFieldObject_Ptr object = create_object(heading);
    IPlayingField_Ptr playing_field =
        create_playing_field(
            object,
            expectedCalledTimes,
            expectedRow,
            expectedColumn);

    IObjectMoveCalculator_Ptr calculator = create_calculator();

    ObjectMover sut{ calculator };

    sut.initialize(playing_field);

    // Act
    for (int i = 0; i < times; i++)
    {
        sut.move_object(size_t(1), size_t(1));
    }

    // Assert
}

void TEST_move_object_from_to_with_start_position_1_1(
    const PacMan::Logic::Heading heading,
    const size_t expectedRow,
    const size_t expectedColumn)
{
    using namespace PacMan::Logic;

    TEST_move_object_from_to_n_times_with_start_position_1_1(
        heading,
        size_t(1),
        size_t(1),
        expectedRow,
        expectedColumn);

}

TEST(ObjectMover, move_object_calls_playing_field_for_heading_left)
{
    using namespace PacMan::Logic;

    // todo testing ==> this is just a dummy test
    TEST_move_object_from_to_with_start_position_1_1(Heading_Left,
                                                size_t(1),
                                                size_t(0));
}

