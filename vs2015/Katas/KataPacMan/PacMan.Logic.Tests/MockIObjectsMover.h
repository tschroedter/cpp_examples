#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IObjectsMover.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            class MockIObjectsMover // todo common test lib
                :public IObjectsMover
            {
            public:
                // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
                MOCK_METHOD0(calculate, void());
                MOCK_CONST_METHOD1(print_moves, std::ostream&(std::ostream &out));
                MOCK_CONST_METHOD0(move_objects, void());
                MOCK_METHOD1(
                    initialize,
                    void(const PacMan::Logic::IPlayingField_Ptr& playing_field));
                MOCK_CONST_METHOD0(
                    get_status,
                    PacMan::Logic::ValidationStatus());
                // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
            };
        };
    };
};
