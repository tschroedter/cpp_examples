#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IDot.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            class MockIDot
                :public IDot
            {
            public:
                // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
                MOCK_CONST_METHOD0(get_type, PacMan::Logic::PlayingFieldObjectType());
                MOCK_CONST_METHOD0(get_location, PacMan::Logic::ILocation_Ptr());
                MOCK_CONST_METHOD0(get_heading, PacMan::Logic::Heading());
                MOCK_METHOD1(set_heading, void(PacMan::Logic::Heading));
                MOCK_CONST_METHOD0(is_moving, bool());
                MOCK_METHOD0(tick, void());
                // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
            };
        };
    };
};
