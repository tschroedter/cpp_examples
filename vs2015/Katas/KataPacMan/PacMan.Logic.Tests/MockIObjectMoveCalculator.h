#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IObjectMoveCalculator.h"
#include "Heading.h"

using namespace PacMan::Logic;

class MockIObjectMoveCalculator // todo common test lib
    :public IObjectMoveCalculator
{
public:
    // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
    MOCK_METHOD3(
        calculate,
        void(
            const PacMan::Logic::Row from_row,
            const PacMan::Logic::Column from_column,
            const PacMan::Logic::Heading heading));
    MOCK_METHOD1(
        initialize,
        void(
            const PacMan::Logic::IPlayingField_Ptr& playing_field));
    // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
};
