#include "stdafx.h"
#include <gtest/gtest.h>
#include <memory>
#include "PacMan.h"
#include "MockILocation.h"
#include "IDirection.h"
#include "MockIDirection.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            void is_moving_test_for_heading (
                Heading heading,
                bool expected )
            {
                // Arrange
                ILocation_Ptr location = std::make_shared<MockILocation>();
                MockIDirection* mock_direction = new MockIDirection{};
                IDirection_Ptr direction(mock_direction);

                PacMan sut
                {
                    location,
                    direction
                };

                EXPECT_CALL(*mock_direction,
                    get_heading())
                                  .Times(1)
                                  .WillOnce(testing::Return(heading));

                // Act
                // Assert
                EXPECT_EQ(
                    expected,
                    sut.is_moving());
            }

            TEST(PacMan, is_moving_returns_false_for_heading_unknown)
            {
                is_moving_test_for_heading(Heading_Unknown, false);
            }

            TEST(PacMan, is_moving_returns_false_for_heading_max)
            {
                is_moving_test_for_heading(Heading_Max, false);
            }

            TEST(PacMan, is_moving_returns_true_for_heading_left)
            {
                is_moving_test_for_heading(Heading_Left, true);
            }

            TEST(PacMan, is_moving_returns_true_for_heading_right)
            {
                is_moving_test_for_heading(Heading_Right, true);
            }

            TEST(PacMan, is_moving_returns_true_for_heading_up)
            {
                is_moving_test_for_heading(Heading_Up, true);
            }

            TEST(PacMan, is_moving_returns_true_for_heading_down)
            {
                is_moving_test_for_heading(Heading_Down, true);
            }

            TEST(PacMan, constructor_sets_heading)
            {
                // Arrange
                ILocation_Ptr location = std::make_shared<MockILocation>();
                MockIDirection* mock_direction = new MockIDirection{};
                IDirection_Ptr direction(mock_direction);

                PacMan sut
                {
                    location,
                    direction
                };

                EXPECT_CALL(*mock_direction,
                    get_heading())
                                  .Times(1)
                                  .WillOnce(testing::Return(Heading_Down));

                // Act
                Heading actual = sut.get_heading();

                // Assert
                EXPECT_EQ(Heading_Down, actual);
            }

            TEST(PacMan, constructor_sets_type)
            {
                // Arrange
                ILocation_Ptr location = std::make_shared<MockILocation>();
                IDirection_Ptr direction = std::make_shared<MockIDirection>();

                PacMan sut
                {
                    location,
                    direction
                };

                // Act
                PlayingFieldObjectType actual = sut.get_type();

                // Assert
                EXPECT_EQ(PlayingFieldObjectType_PacMan, actual);
            }

            TEST(PacMan, tick_calls_tick)
            {
                // Arrange
                ILocation_Ptr location = std::make_shared<MockILocation>();
                IDirection_Ptr direction = std::make_shared<MockIDirection>();

                PacMan sut
                {
                    location,
                    direction
                };

                // Act
                // Assert
                EXPECT_NO_THROW(sut.tick());
            }

            TEST(PacMan, set_heading_sets_heading)
            {
                // Arrange
                ILocation_Ptr location = std::make_shared<MockILocation>();
                MockIDirection* mock_direction = new MockIDirection{};
                IDirection_Ptr direction(mock_direction);

                PacMan sut
                {
                    location,
                    direction
                };

                EXPECT_CALL(*mock_direction,
                    set_heading(Heading_Down))
                                              .Times(1);

                // Act
                sut.set_heading(Heading_Down);

                // Assert
            }

            TEST(PacMan, is_moveable_returns_true)
            {
                // Arrange
                ILocation_Ptr location = std::make_shared<MockILocation>();
                MockIDirection* mock_direction = new MockIDirection{};
                IDirection_Ptr direction(mock_direction);

                PacMan sut
                {
                    location,
                    direction
                };

                // Act
                bool actual = sut.is_moveable();

                // Assert
                EXPECT_EQ(true, actual);
            }
        };
    };
};
