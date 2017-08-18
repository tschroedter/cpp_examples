#include "stdafx.h"
#include <gtest/gtest.h>
#include "Wall.h"
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

            TEST(Wall, constructor_sets_heading)
            {
                // Arrange
                ILocation_Ptr location = std::make_shared<MockILocation>();
                MockIDirection* mock_direction = new MockIDirection{};
                IDirection_Ptr direction(mock_direction);

                Wall sut
                {
                    location,
                    direction
                };

                EXPECT_CALL(*mock_direction,
                    get_heading())
                    .Times(1)
                    .WillOnce(testing::Return(Heading_Unknown));

                // Act
                Heading actual = sut.get_heading();

                // Assert
                EXPECT_EQ(Heading_Unknown, actual);
            }

            TEST(Wall, is_moving_returns_false)
            {
                // Arrange
                ILocation_Ptr location = std::make_shared<MockILocation>();
                IDirection_Ptr direction = std::make_shared<MockIDirection>();

                Wall sut
                {
                    location,
                    direction
                };

                // Act
                // Assert
                EXPECT_FALSE(sut.is_moving());
            }

            TEST(Wall, constructor_sets_type)
            {
                // Arrange
                ILocation_Ptr location = std::make_shared<MockILocation>();
                IDirection_Ptr direction = std::make_shared<MockIDirection>();

                Wall sut
                {
                    location,
                    direction
                };

                // Act
                PlayingFieldObjectType actual = sut.get_type();

                // Assert
                EXPECT_EQ(PlayingFieldObjectType_Wall, actual);
            }

            TEST(Wall, tick_calls_tick)
            {
                // Arrange
                ILocation_Ptr location = std::make_shared<MockILocation>();
                IDirection_Ptr direction = std::make_shared<MockIDirection>();

                Wall sut
                {
                    location,
                    direction
                };

                // Act
                // Assert
                EXPECT_NO_THROW(sut.tick());
            }

            TEST(Wall, set_heading_does_not_set_heading)
            {
                // Arrange
                ILocation_Ptr location = std::make_shared<MockILocation>();
                MockIDirection* mock_direction = new MockIDirection{};
                IDirection_Ptr direction(mock_direction);

                Wall sut
                {
                    location,
                    direction
                };

                EXPECT_CALL(*mock_direction,
                    set_heading(Heading_Right))
                    .Times(0);

                // Act
                sut.set_heading(Heading_Right);

                // Assert
            }

            TEST(Wall, is_moveable_returns_false)
            {
                // Arrange
                ILocation_Ptr location = std::make_shared<MockILocation>();
                MockIDirection* mock_direction = new MockIDirection{};
                IDirection_Ptr direction(mock_direction);

                Wall sut
                {
                    location,
                    direction
                };

                // Act
                // Assert
                EXPECT_FALSE(sut.is_moveable());
            }
        };
    };
};
