#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IObjectsTicker.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            class MockIObjectsTicker
                :public IObjectsTicker
            {
            public:
                // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
                MOCK_METHOD1(
                    initialize,
                    void(const PacMan::Logic::IPlayingField_Ptr& playing_field));
                MOCK_CONST_METHOD0(
                    tick,
                    void());
                // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
            };
        };
    };
};
