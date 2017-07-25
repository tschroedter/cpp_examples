#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IObjectsMover.h"

class MockIObjectsMover // todo common test lib
    :public PacMan::Logic::IObjectsMover
{
public:
    // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
    MOCK_METHOD0(calculate, void());
    MOCK_CONST_METHOD0(print_moves, void());
    MOCK_CONST_METHOD0(move_objects, void());
    MOCK_METHOD1(
        initialize,
        void(const PacMan::Logic::IPlayingField_Ptr& playing_field));
    // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
};
