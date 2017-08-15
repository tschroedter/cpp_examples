#include "stdafx.h"
#include "GameTimer.h"
#include <iostream>
#include <gtest/gtest.h>
#include "MockIPlayingField.h"
#include "MockIObjectMover.h"
#include "MockIObjectsMover.h"
#include "ObjectsTicker.h"
#include "MockIPlayingFieldObject.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            TEST(ObjectsTicker, tick_calls_tick_on_all_objects)
            {
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

                ObjectsTicker sut{};
                sut.initialize(playing_field);

                EXPECT_CALL(*mock_playing_field,
                    get_rows())
                               .Times(1)
                               .WillOnce(testing::Return(Row(2)));

                EXPECT_CALL(*mock_playing_field,
                    get_columns())
                                  .Times(1)
                                  .WillOnce(testing::Return(Column(2)));

                EXPECT_CALL(*mock_playing_field,
                    get_object_at(Row(0), Column(0)))
                                                     .Times(1)
                                                     .WillOnce(testing::Return(object_0_0));

                EXPECT_CALL(*mock_playing_field,
                    get_object_at(Row(0), Column(1)))
                                                     .Times(1)
                                                     .WillOnce(testing::Return(object_0_1));

                EXPECT_CALL(*mock_playing_field,
                    get_object_at(Row(1), Column(0)))
                                                     .Times(1)
                                                     .WillOnce(testing::Return(object_1_0));

                EXPECT_CALL(*mock_playing_field,
                    get_object_at(Row(1), Column(1)))
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
        };
    };
};
