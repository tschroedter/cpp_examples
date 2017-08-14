#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IDot.h"

using namespace PacMan::Logic;

class MockILocation
    :public ILocation
{
public:
    // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
    MOCK_CONST_METHOD0(get_row, PacMan::Logic::Row());
    MOCK_CONST_METHOD0(get_column, PacMan::Logic::Column());
    // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
};
