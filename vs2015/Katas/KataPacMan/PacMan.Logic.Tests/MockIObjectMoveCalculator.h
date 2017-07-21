#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IObjectMoveCalculator.h"
#include "Heading.h"

class MockIObjectMoveCalculator // todo common test lib
    :public PacMan::Logic::IObjectMoveCalculator
{
public:
    // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
    MOCK_METHOD3(
        calculate,
        void(
            const size_t from_row,
            const size_t from_column,
            const PacMan::Logic::Heading heading));
    MOCK_METHOD1(
        initialize,
        void(
            const PacMan::Logic::IPlayingField_Ptr& playing_field));
    // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
};
