#include "stdafx.h"
#include <gtest/gtest.h>
#include "Dot.h"
#include "MockILocation.h"
#include "IDirection.h"
#include "MockIDirection.h"

TEST(Dot, constructor_sets_heading)
{
    using namespace PacMan::Logic;

    // Arrange
    ILocation_Ptr location = std::make_shared<MockILocation>();
    MockIDirection* mock_direction = new MockIDirection{};
    IDirection_Ptr direction(mock_direction);

    Dot sut
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

TEST(Dot, is_moving_returns_false)
{
    using namespace PacMan::Logic;

    // Arrange
    ILocation_Ptr location = std::make_shared<MockILocation>();
    IDirection_Ptr direction = std::make_shared<MockIDirection>();

    Dot sut
    {
        location,
        direction
    };

    // Act
    // Assert
    EXPECT_FALSE(sut.is_moving());
}

TEST(Dot, constructor_sets_type)
{
    using namespace PacMan::Logic;

    // Arrange
    ILocation_Ptr location = std::make_shared<MockILocation>();
    IDirection_Ptr direction = std::make_shared<MockIDirection>();

    Dot sut
    {
        location,
        direction
    };

    // Act
    PlayingFieldObjectType actual = sut.get_type();

    // Assert
    EXPECT_EQ(PlayingFieldObjectType_Dot, actual);
}

TEST(Dot, tick_calls_tick)
{
    using namespace PacMan::Logic;

    // Arrange
    ILocation_Ptr location = std::make_shared<MockILocation>();
    IDirection_Ptr direction = std::make_shared<MockIDirection>();

    Dot sut
    {
        location,
        direction
    };

    // Act
    // Assert
    EXPECT_NO_THROW (sut.tick());
}
