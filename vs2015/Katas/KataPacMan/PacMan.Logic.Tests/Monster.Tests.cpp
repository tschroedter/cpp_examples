#include "stdafx.h"
#include <gtest/gtest.h>
#include "MockILocation.h"
#include "IDirection.h"
#include "ILocation.h"
#include "MockIDirection.h"
#include "Monster.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            TEST(Monster, is_moveable_returns_true)
            {
                // Arrange
                MockILocation* mock_location = new MockILocation{};
                ILocation_Ptr location(mock_location);
                IDirection_Ptr direction = std::make_shared<MockIDirection>();

                Monster sut
                {
                    location,
                    direction
                };

                // Act
                // Assert
                EXPECT_TRUE(sut.is_moveable());
            }

            TEST(Monster, constructor_sets_type)
            {
                // Arrange
                MockILocation* mock_location = new MockILocation{};
                ILocation_Ptr location(mock_location);
                IDirection_Ptr direction = std::make_shared<MockIDirection>();

                Monster sut
                {
                    location,
                    direction
                };

                // Act
                PlayingFieldObjectType actual = sut.get_type();

                // Assert
                EXPECT_EQ(PlayingFieldObjectType_Monster, actual);
            }

            TEST(Monster, tick_calls_tick)
            {
                // Arrange
                MockILocation* mock_location = new MockILocation{};
                ILocation_Ptr location(mock_location);
                MockIDirection* mock_direction = new MockIDirection{};
                IDirection_Ptr direction(mock_direction);

                Monster sut
                {
                    location,
                    direction
                };

                // Act
                // Assert
                EXPECT_NO_THROW(sut.tick());
            }

            TEST(Monster, set_heading_sets_heading)
            {
                // Arrange
                MockILocation* mock_location = new MockILocation{};
                ILocation_Ptr location(mock_location);
                MockIDirection* mock_direction = new MockIDirection{};
                IDirection_Ptr direction(mock_direction);

                Monster sut
                {
                    location,
                    direction
                };

                EXPECT_CALL(*mock_direction,
                    set_heading(Heading_Right))
                                               .Times(1);

                // Act
                sut.set_heading(Heading_Right);

                // Assert
            }

            void test_is_moveable_for_heading (
                Heading heading,
                bool expected )
            {
                // Arrange
                MockILocation* mock_location = new MockILocation{};
                ILocation_Ptr location(mock_location);
                MockIDirection* mock_direction = new MockIDirection{};
                IDirection_Ptr direction(mock_direction);

                Monster sut
                {
                    location,
                    direction
                };

                EXPECT_CALL(*mock_direction,
                    get_heading())
                                  .Times(1)
                                  .WillOnce(testing::Return(heading));

                // Act
                bool actual = sut.is_moving();

                // Assert
                EXPECT_EQ(expected, actual);
            }

            TEST(Monster, is_moving_returns_false_for_Heading_Unknown)
            {
                test_is_moveable_for_heading(Heading_Unknown, false);
            }

            TEST(Monster, is_moving_returns_false_for_Heading_Max)
            {
                test_is_moveable_for_heading(Heading_Max, false);
            }

            TEST(Monster, is_moving_returns_false_for_Heading_Left)
            {
                test_is_moveable_for_heading(Heading_Left, true);
            }

            TEST(Monster, is_moving_returns_false_for_Heading_Right)
            {
                test_is_moveable_for_heading(Heading_Right, true);
            }

            TEST(Monster, is_moving_returns_false_for_Heading_Up)
            {
                test_is_moveable_for_heading(Heading_Up, true);
            }

            TEST(Monster, is_moving_returns_false_for_Heading_Down)
            {
                test_is_moveable_for_heading(Heading_Down, true);
            }
        };
    };
};
