#include "stdafx.h"
#include "GameTimer.h"
#include <gtest/gtest.h>
#include "MockIPlayingField.h"
#include "../PacMan.View.Tests/MockIPlayingFieldObject.h"
#include "MockIObjectMover.h"

TEST(GameTimer, tick_calls_tick_on_all_objects)
{
    using namespace PacMan::Logic;

    // Arrange
    MockIPlayingFieldObject* mock_object_0_0 = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object_0_0 ( mock_object_0_0 );

    MockIPlayingFieldObject* mock_object_0_1 = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object_0_1 ( mock_object_0_1 );

    MockIPlayingFieldObject* mock_object_1_0 = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object_1_0 ( mock_object_1_0 );

    MockIPlayingFieldObject* mock_object_1_1 = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object_1_1 ( mock_object_1_1 );

    MockIObjectMover* mock_object_mover = new MockIObjectMover{};
    IObjectMover_Ptr object_mover(mock_object_mover);

    MockIPlayingField* mock_playing_field = new MockIPlayingField{};
    IPlayingField_Ptr playing_field ( mock_playing_field );

    GameTimer sut {};
    sut.initialize ( playing_field, object_mover);

    EXPECT_CALL(*mock_playing_field,
        get_rows())
                   .Times ( 1 )
                   .WillOnce ( testing::Return ( size_t ( 2 ) ) );

    EXPECT_CALL(*mock_playing_field,
        get_columns())
                      .Times ( 1 )
                      .WillOnce ( testing::Return ( size_t ( 2 ) ) );

    EXPECT_CALL(*mock_playing_field,
        get_object_at(size_t(0), size_t(0)))
                                            .Times ( 1 )
                                            .WillOnce ( testing::Return ( object_0_0 ) );

    EXPECT_CALL(*mock_playing_field,
        get_object_at(size_t(0), size_t(1)))
                                            .Times ( 1 )
                                            .WillOnce ( testing::Return ( object_0_1 ) );

    EXPECT_CALL(*mock_playing_field,
        get_object_at(size_t(1), size_t(0)))
                                            .Times ( 1 )
                                            .WillOnce ( testing::Return ( object_1_0 ) );

    EXPECT_CALL(*mock_playing_field,
        get_object_at(size_t(1), size_t(1)))
                                            .Times ( 1 )
                                            .WillOnce ( testing::Return ( object_1_1 ) );

    EXPECT_CALL(*mock_object_0_0,
        tick())
               .Times ( 1 );

    EXPECT_CALL(*mock_object_0_1,
        tick())
               .Times ( 1 );

    EXPECT_CALL(*mock_object_1_0,
        tick())
               .Times ( 1 );

    EXPECT_CALL(*mock_object_1_1,
        tick())
               .Times ( 1 );

    // Act
    // Assert
    sut.tick();
}
