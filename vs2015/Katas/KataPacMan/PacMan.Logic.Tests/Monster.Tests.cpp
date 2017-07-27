#include "stdafx.h"
#include <gtest/gtest.h>
#include "MockILocation.h"
#include "IDirection.h"
#include "ILocation.h"
#include "MockIDirection.h"
#include "Monster.h"

TEST(Monster, is_moveable_returns_true)
{
    using namespace PacMan::Logic;

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
    using namespace PacMan::Logic;

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
    using namespace PacMan::Logic;

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
    using namespace PacMan::Logic;

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
    PacMan::Logic::Heading heading,
    bool expected )
{
    using namespace PacMan::Logic;

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
    using namespace PacMan::Logic;

    test_is_moveable_for_heading(Heading_Unknown, false);
}

TEST(Monster, is_moving_returns_false_for_Heading_Max)
{
    using namespace PacMan::Logic;

    test_is_moveable_for_heading(Heading_Max, false);
}

TEST(Monster, is_moving_returns_false_for_Heading_Left)
{
    using namespace PacMan::Logic;

    test_is_moveable_for_heading(Heading_Left, true);
}

TEST(Monster, is_moving_returns_false_for_Heading_Right)
{
    using namespace PacMan::Logic;

    test_is_moveable_for_heading(Heading_Right, true);
}

TEST(Monster, is_moving_returns_false_for_Heading_Up)
{
    using namespace PacMan::Logic;

    test_is_moveable_for_heading(Heading_Up, true);
}

TEST(Monster, is_moving_returns_false_for_Heading_Down)
{
    using namespace PacMan::Logic;

    test_is_moveable_for_heading(Heading_Down, true);
}
