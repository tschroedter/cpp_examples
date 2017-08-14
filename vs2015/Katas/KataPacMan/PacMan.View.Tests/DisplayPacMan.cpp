#include "stdafx.h"
#include <gtest/gtest.h>
#include "DisplayPacMan.h"
#include "../PacMan.Logic.Tests/MockIDirection.h"
#include "../PacMan.Logic.Tests/MockIPlayingFieldObject.h"

TEST(DisplayPacMan, to_string_returns_string_for_Heading_Unknown)
{
    using namespace PacMan::View;

    // Arrange
    MockIPlayingFieldObject* mock_object = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object(mock_object);

    DisplayPacMan sut{};
    sut.initialize(object);

    EXPECT_CALL(*mock_object,
        get_heading())
                      .Times(1)
                      .WillOnce(testing::Return(Heading_Unknown));

    // Act
    auto actual = sut.to_string();

    // Assert
    EXPECT_EQ("UN", actual);
}

TEST(DisplayPacMan, to_string_returns_string_for_Heading_Up)
{
    using namespace PacMan::View;

    // Arrange
    MockIPlayingFieldObject* mock_object = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object(mock_object);

    DisplayPacMan sut{};
    sut.initialize(object);

    EXPECT_CALL(*mock_object,
        get_heading())
                      .Times(1)
                      .WillOnce(testing::Return(Heading_Up));

    // Act
    auto actual = sut.to_string();

    // Assert
    EXPECT_EQ("\\/", actual);
}

TEST(DisplayPacMan, to_string_returns_string_for_Heading_Down)
{
    using namespace PacMan::View;

    // Arrange
    MockIPlayingFieldObject* mock_object = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object(mock_object);

    DisplayPacMan sut{};
    sut.initialize(object);

    EXPECT_CALL(*mock_object,
        get_heading())
                      .Times(1)
                      .WillOnce(testing::Return(Heading_Down));

    // Act
    auto actual = sut.to_string();

    // Assert
    EXPECT_EQ("/\\", actual);
}

TEST(DisplayPacMan, to_string_returns_string_for_Heading_Left)
{
    using namespace PacMan::View;

    // Arrange
    MockIPlayingFieldObject* mock_object = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object(mock_object);

    DisplayPacMan sut{};
    sut.initialize(object);

    EXPECT_CALL(*mock_object,
        get_heading())
                      .Times(1)
                      .WillOnce(testing::Return(Heading_Left));

    // Act
    auto actual = sut.to_string();

    // Assert
    EXPECT_EQ(" >", actual);
}

TEST(DisplayPacMan, to_string_returns_string_for_Heading_Right)
{
    using namespace PacMan::View;

    // Arrange
    MockIPlayingFieldObject* mock_object = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object(mock_object);

    DisplayPacMan sut{};
    sut.initialize(object);

    EXPECT_CALL(*mock_object,
        get_heading())
                      .Times(1)
                      .WillOnce(testing::Return(Heading_Right));

    // Act
    auto actual = sut.to_string();

    // Assert
    EXPECT_EQ("< ", actual);
}

TEST(DisplayPacMan, to_string_returns_string_for_Heading_Max)
{
    using namespace PacMan::View;

    // Arrange
    MockIPlayingFieldObject* mock_object = new MockIPlayingFieldObject{};
    IPlayingFieldObject_Ptr object(mock_object);

    DisplayPacMan sut{};
    sut.initialize(object);

    EXPECT_CALL(*mock_object,
        get_heading())
                      .Times(1)
                      .WillOnce(testing::Return(Heading_Max));

    // Act
    auto actual = sut.to_string();

    // Assert
    EXPECT_EQ("MA", actual);
}
