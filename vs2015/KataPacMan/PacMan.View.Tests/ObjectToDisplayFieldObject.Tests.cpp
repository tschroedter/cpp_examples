#include "stdafx.h"
#include <gtest/gtest.h>
#include "MockILocation.h"
#include "ObjectToDisplayFieldObject.h"
#include "MockIDisplayUnknown.h"
#include "MockIDisplayDot.h"
#include "MockIDisplayMonster.h"
#include "MockIDisplayMax.h"
#include "../PacMan.Logic.Tests/MockIPlayingFieldObject.h"
#include "DisplayObjectType.h"
#include "MockIDisplayPacMan.h"

std::function<std::shared_ptr<PacMan::View::IDisplayUnknown> ()> create_factory_unknown ()
{
    return []
            {
                return std::make_shared<MockIDisplayUnknown>();
            };
}

Hypodermic::FactoryWrapper<PacMan::View::IDisplayUnknown> wrapper_unknown { create_factory_unknown() };

std::function<std::shared_ptr<PacMan::View::IDisplayDot> ()> create_factory_dot ()
{
    return []
            {
                return std::make_shared<MockIDisplayDot>();
            };
}

Hypodermic::FactoryWrapper<PacMan::View::IDisplayDot> wrapper_dot { create_factory_dot() };

std::function<std::shared_ptr<PacMan::View::IDisplayPacMan> ()> create_factory_pac_man ()
{
    return []
            {
                return std::make_shared<MockIDisplayPacMan>();
            };
}

Hypodermic::FactoryWrapper<PacMan::View::IDisplayPacMan> wrapper_pac_man { create_factory_pac_man() };

std::function<std::shared_ptr<PacMan::View::IDisplayMonster> ()> create_factory_monster ()
{
    return []
            {
                return std::make_shared<MockIDisplayMonster>();
            };
}

Hypodermic::FactoryWrapper<PacMan::View::IDisplayMonster> wrapper_monster { create_factory_monster() };

std::function<std::shared_ptr<PacMan::View::IDisplayMax> ()> create_factory_max ()
{
    return []
            {
                return std::make_shared<MockIDisplayMax>();
            };
}

Hypodermic::FactoryWrapper<PacMan::View::IDisplayMax> wrapper_max { create_factory_max() };

TEST(ObjectToDisplayFieldObject, get_object_for_returns_display_object_for_dot)
{
    using namespace PacMan::View;

    // Arrange
    MockIPlayingFieldObject* mock_object = new MockIPlayingFieldObject();
    PacMan::Logic::IPlayingFieldObject_Ptr object ( mock_object );

    ObjectToDisplayFieldObject sut
    {
        wrapper_unknown,
        wrapper_dot,
        wrapper_pac_man,
        wrapper_monster,
        wrapper_max
    };

    EXPECT_CALL(*mock_object,
        get_type())
                   .Times ( 1 )
                   .WillOnce ( testing::Return ( PacMan::Logic::PlayingFieldObjectType_Dot ) );

    // Act
    IDisplayPlayingFieldObject_Ptr actual = sut.get_object_for ( object );

    // Assert
    EXPECT_EQ(PacMan::View::DisplayObjectType_Dot, actual->get_type());
}
