#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IObjectMover.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            class MockIObjectMover // todo common test lib
                :public IObjectMover
            {
            public:
                // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
                MOCK_METHOD2(
                    move_object,
                    void(
                        const PacMan::Logic::Row row,
                        const PacMan::Logic::Column column));
                MOCK_METHOD1(
                    initialize,
                    void(
                        const PacMan::Logic::IPlayingField_Ptr& playing_field));
                // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
            };
        };
    };
};
