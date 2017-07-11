#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IObjectMover.h"

class MockIObjectMover // todo common test lib
    :public PacMan::Logic::IObjectMover
{
public:
    // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
    MOCK_METHOD2(
        move_object,
        void(const size_t row, const size_t column));
    MOCK_METHOD1(
        initialize,
        void(const PacMan::Logic::IPlayingField_Ptr& playing_field));
    // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
};
