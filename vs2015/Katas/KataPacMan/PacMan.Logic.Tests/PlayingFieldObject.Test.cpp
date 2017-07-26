#include "stdafx.h"
#include <gtest/gtest.h>
#include <memory>
#include "PlayingFieldObject.h"
#include "PlayingFieldObjectType.h"
#include "MockIDirection.h"
#include "MockILocation.h"

class TestPlayingFieldObject
    : public PacMan::Logic::PlayingFieldObject
{
public:
    TestPlayingFieldObject (
        PacMan::Logic::ILocation_Ptr location,
        PacMan::Logic::IDirection_Ptr direction )
        : PlayingFieldObject(
                             PacMan::Logic::PlayingFieldObjectType_Unknown,
                             location,
                             direction)
    {
    }

    bool was_tick_called = false;

    void tick () override
    {
        was_tick_called = true;
    }
};

TEST(PlayingFieldObject, constructor_sets_heading)
{
    using namespace PacMan::Logic;

    // Arrange
    ILocation_Ptr location = std::make_shared<MockILocation>();
    MockIDirection* mock_direction = new MockIDirection{};
    IDirection_Ptr direction(mock_direction);

    TestPlayingFieldObject sut
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

TEST(PlayingFieldObject, constructor_sets_type)
{
    using namespace PacMan::Logic;

    // Arrange
    ILocation_Ptr location = std::make_shared<MockILocation>();
    IDirection_Ptr direction = std::make_shared<MockIDirection>();

    TestPlayingFieldObject sut
    {
        location,
        direction
    };

    // Act
    PlayingFieldObjectType actual = sut.get_type();

    // Assert
    EXPECT_EQ(PlayingFieldObjectType_Unknown, actual);
}

TEST(PlayingFieldObject, tick_calls_tick)
{
    using namespace PacMan::Logic;

    // Arrange
    ILocation_Ptr location = std::make_shared<MockILocation>();
    IDirection_Ptr direction = std::make_shared<MockIDirection>();

    TestPlayingFieldObject sut
    {
        location,
        direction
    };

    // Act
    sut.tick();

    // Assert
    EXPECT_EQ(true, sut.was_tick_called);
}

TEST(PlayingFieldObject, set_heading_calls_direction)
{
    using namespace PacMan::Logic;

    // Arrange
    ILocation_Ptr location = std::make_shared<MockILocation>();
    MockIDirection* mock_direction = new MockIDirection{};
    IDirection_Ptr direction(mock_direction);

    TestPlayingFieldObject sut
    {
        location,
        direction
    };

    EXPECT_CALL(*mock_direction,
        set_heading(Heading_Left))
                                  .Times(1);

    // Act
    sut.set_heading(Heading_Left);

    // Assert
}
