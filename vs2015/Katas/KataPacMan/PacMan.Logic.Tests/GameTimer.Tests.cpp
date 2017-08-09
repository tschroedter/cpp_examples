#include "stdafx.h"
#include "GameTimer.h"
#include <iostream>
#include <gtest/gtest.h>
#include "MockIPlayingField.h"
#include "../PacMan.View.Tests/MockIPlayingFieldObject.h"
#include "MockIObjectMover.h"
#include "MockIObjectsMover.h"

TEST(GameTimer, tick_calls_tick_on_all_objects)
{
    using namespace PacMan::Logic;

    // Arrange
    MockIPlayingFieldObject* mock_object_0_0 = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object_0_0(mock_object_0_0);

    MockIPlayingFieldObject* mock_object_0_1 = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object_0_1(mock_object_0_1);

    MockIPlayingFieldObject* mock_object_1_0 = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object_1_0(mock_object_1_0);

    MockIPlayingFieldObject* mock_object_1_1 = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object_1_1(mock_object_1_1);

    MockIPlayingField* mock_playing_field = new MockIPlayingField{};
    IPlayingField_Ptr playing_field(mock_playing_field);

    MockIObjectsMover* mock_objects_mover = new MockIObjectsMover{};
    IObjectsMover_Ptr objects_mover(mock_objects_mover);

    GameTimer sut{objects_mover};
    sut.initialize(playing_field);

    EXPECT_CALL(*mock_playing_field,
        get_rows())
                   .Times(1)
                   .WillOnce(testing::Return(size_t(2)));

    EXPECT_CALL(*mock_playing_field,
        get_columns())
                      .Times(1)
                      .WillOnce(testing::Return(size_t(2)));

    EXPECT_CALL(*mock_playing_field,
        get_object_at(size_t(0), size_t(0)))
                                            .Times(1)
                                            .WillOnce(testing::Return(object_0_0));

    EXPECT_CALL(*mock_playing_field,
        get_object_at(size_t(0), size_t(1)))
                                            .Times(1)
                                            .WillOnce(testing::Return(object_0_1));

    EXPECT_CALL(*mock_playing_field,
        get_object_at(size_t(1), size_t(0)))
                                            .Times(1)
                                            .WillOnce(testing::Return(object_1_0));

    EXPECT_CALL(*mock_playing_field,
        get_object_at(size_t(1), size_t(1)))
                                            .Times(1)
                                            .WillOnce(testing::Return(object_1_1));

    EXPECT_CALL(*mock_object_0_0,
        tick())
               .Times(1);

    EXPECT_CALL(*mock_object_0_1,
        tick())
               .Times(1);

    EXPECT_CALL(*mock_object_1_0,
        tick())
               .Times(1);

    EXPECT_CALL(*mock_object_1_1,
        tick())
               .Times(1);

    // Act
    // Assert
    sut.tick();
}

TEST(GameTimer, initialize_calls_object_movers_initialize)
{
    using namespace PacMan::Logic;

    // Arrange
    MockIPlayingField* mock_playing_field = new MockIPlayingField{};
    IPlayingField_Ptr playing_field(mock_playing_field);

    MockIObjectsMover* mock_objects_mover = new MockIObjectsMover{};
    IObjectsMover_Ptr objects_mover(mock_objects_mover);

    GameTimer sut{objects_mover};
    sut.initialize(playing_field);

    EXPECT_CALL(*mock_objects_mover,
        initialize(playing_field))
                                  .Times(1);

    // Act
    sut.initialize(playing_field);

    // Assert
}

TEST(GameTimer, get_status_calls_get_status)
{
    using namespace PacMan::Logic;

    // Arrange
    MockIPlayingField* mock_playing_field = new MockIPlayingField{};
    IPlayingField_Ptr playing_field(mock_playing_field);

    MockIObjectsMover* mock_objects_mover = new MockIObjectsMover{};
    IObjectsMover_Ptr objects_mover(mock_objects_mover);

    GameTimer sut{objects_mover};
    sut.initialize(playing_field);

    EXPECT_CALL(*mock_objects_mover,
        get_status())
                     .WillRepeatedly(testing::Return(ValidationStatus_PacMan_ALive));

    // Act
    auto actual = sut.get_status();

    // Assert
    EXPECT_EQ(ValidationStatus_PacMan_ALive,
        actual);
}

TEST(GameTimer, tick_calls_move_objects_calculate_print_moves_move_objects)
{
    using namespace PacMan::Logic;

    // Arrange
    MockIPlayingField* mock_playing_field = new MockIPlayingField{};
    IPlayingField_Ptr playing_field(mock_playing_field);

    MockIObjectsMover* mock_objects_mover = new MockIObjectsMover{};
    IObjectsMover_Ptr objects_mover(mock_objects_mover);

    GameTimer sut{objects_mover};
    sut.initialize(playing_field);

    EXPECT_CALL(*mock_playing_field,
        get_rows())
                   .WillRepeatedly(testing::Return(0));

    EXPECT_CALL(*mock_playing_field,
        get_columns())
                      .WillRepeatedly(testing::Return(0));

    EXPECT_CALL(*mock_objects_mover,
        calculate())
                    .Times(1);

    std::stringstream stream;

    EXPECT_CALL(*mock_objects_mover,
        print_moves(testing::A<std::ostream&>()))
                                                 .Times(1)
                                                 .WillOnce(testing::ReturnRef(stream));

    EXPECT_CALL(*mock_objects_mover,
        move_objects())
                       .Times(1);

    // Act
    sut.tick();

    // Assert
}
