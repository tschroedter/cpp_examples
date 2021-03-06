#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IPlayingFieldObject.h"

namespace PacMan
{
    namespace View
    {
        namespace Tests
        {
            using namespace Logic;

            class MockIPlayingFieldObject // todo common test lib
                :public IPlayingFieldObject
            {
            public:
                // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
                MOCK_CONST_METHOD0(get_type, PacMan::Logic::PlayingFieldObjectType());
                MOCK_CONST_METHOD0(get_heading, PacMan::Logic::Heading());
                MOCK_METHOD1(set_heading, void(PacMan::Logic::Heading));
                MOCK_CONST_METHOD0(is_moving, bool());
                MOCK_METHOD0(tick, void());
                MOCK_CONST_METHOD0(is_moveable, bool());
                // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
            };
        };
    };
};
