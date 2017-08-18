#include "stdafx.h"
#include <gtest/gtest.h>
#include "MockILocation.h"
#include "ObjectToDisplayFieldObject.h"
#include "MockIDisplayUnknown.h"
#include "MockIDisplayDot.h"
#include "MockIDisplayMonster.h"
#include "MockIDisplayMax.h"
#include "MockIPlayingFieldObject.h"
#include "DisplayObjectType.h"
#include "MockIDisplayPacMan.h"
#include "MockIDisplayWall.h"

namespace PacMan
{
    namespace View
    {
        namespace Tests
        {
            std::function<IDisplayUnknown_Ptr  ()> create_factory_unknown ()
            {
                return []
                {
                    auto p_mock = new MockIDisplayUnknown{};

                    EXPECT_CALL(*p_mock,
                        get_type())
                                   .WillRepeatedly(testing::Return(DisplayObjectType_Unknown));

                    IDisplayUnknown_Ptr display(p_mock);

                    return display;
                };
            }

            Hypodermic::FactoryWrapper<IDisplayUnknown> wrapper_unknown{create_factory_unknown()};

            std::function<IDisplayDot_Ptr  ()> create_factory_dot ()
            {
                return []
                {
                    auto p_mock = new MockIDisplayDot{};

                    EXPECT_CALL(*p_mock,
                        get_type())
                                   .WillRepeatedly(testing::Return(DisplayObjectType_Dot));

                    IDisplayDot_Ptr display(p_mock);

                    return display;
                };
            }

            Hypodermic::FactoryWrapper<IDisplayDot> wrapper_dot{create_factory_dot()};

            std::function<IDisplayWall_Ptr ()> create_factory_wall ()
            {
                return []
                {
                    auto p_mock = new MockIDisplayWall{};

                    EXPECT_CALL(*p_mock,
                        get_type())
                                   .WillRepeatedly(testing::Return(DisplayObjectType_Wall));

                    IDisplayWall_Ptr display(p_mock);

                    return display;
                };
            }

            Hypodermic::FactoryWrapper<IDisplayWall> wrapper_wall{create_factory_wall()};

            std::function<IDisplayPacMan_Ptr  ()> create_factory_pac_man ()
            {
                return []
                {
                    auto p_mock = new MockIDisplayPacMan{};

                    EXPECT_CALL(*p_mock,
                        get_type())
                                   .WillRepeatedly(testing::Return(DisplayObjectType_PacMan));

                    IDisplayPacMan_Ptr display(p_mock);

                    return display;
                };
            }

            Hypodermic::FactoryWrapper<IDisplayPacMan> wrapper_pac_man{create_factory_pac_man()};

            std::function<IDisplayMonster_Ptr  ()> create_factory_monster ()
            {
                return []
                {
                    auto p_mock = new MockIDisplayMonster{};

                    EXPECT_CALL(*p_mock,
                        get_type())
                                   .WillRepeatedly(testing::Return(DisplayObjectType_Monster));

                    IDisplayMonster_Ptr display(p_mock);

                    return display;
                };
            }

            Hypodermic::FactoryWrapper<IDisplayMonster> wrapper_monster{create_factory_monster()};

            std::function<IDisplayMax_Ptr  ()> create_factory_max ()
            {
                return []
                {
                    auto p_mock = new MockIDisplayMax{};

                    EXPECT_CALL(*p_mock,
                        get_type())
                                   .WillRepeatedly(testing::Return(DisplayObjectType_Max));

                    IDisplayMax_Ptr display(p_mock);

                    return display;
                };
            }

            Hypodermic::FactoryWrapper<IDisplayMax> wrapper_max{create_factory_max()};

            void test_get_object (
                PlayingFieldObjectType type,
                DisplayObjectType displayType )
            {
                using namespace View;

                // Arrange
                MockIPlayingFieldObject* mock_object = new MockIPlayingFieldObject();
                IPlayingFieldObject_Ptr object(mock_object);

                ObjectToDisplayFieldObject sut
                {
                    wrapper_unknown,
                    wrapper_dot,
                    wrapper_wall,
                    wrapper_pac_man,
                    wrapper_monster,
                    wrapper_max
                };

                sut.initialize();

                EXPECT_CALL(*mock_object,
                    get_type())
                               .Times(1)
                               .WillOnce(testing::Return(type));

                // Act
                IDisplayPlayingFieldObject_Ptr actual = sut.get_object_for(object);

                // Assert
                EXPECT_EQ(displayType, actual->get_type());
            }

            TEST(ObjectToDisplayFieldObject, get_object_for_returns_display_object_for_unknown)
            {
                using namespace View;

                test_get_object(
                                PlayingFieldObjectType_Unknown,
                                DisplayObjectType_Unknown);
            }

            TEST(ObjectToDisplayFieldObject, get_object_for_returns_display_object_for_dot)
            {
                using namespace View;

                test_get_object(
                                PlayingFieldObjectType_Dot,
                                DisplayObjectType_Dot);
            }

            TEST(ObjectToDisplayFieldObject, get_object_for_returns_display_object_for_pacman)
            {
                using namespace View;

                test_get_object(
                                PlayingFieldObjectType_PacMan,
                                DisplayObjectType_PacMan);
            }

            TEST(ObjectToDisplayFieldObject, get_object_for_returns_display_object_for_monster)
            {
                using namespace View;

                test_get_object(
                                PlayingFieldObjectType_Monster,
                                DisplayObjectType_Monster);
            }

            TEST(ObjectToDisplayFieldObject, get_object_for_returns_display_object_for_max)
            {
                using namespace View;

                test_get_object(
                                PlayingFieldObjectType_Max,
                                DisplayObjectType_Max);
            }
        };
    };
};
