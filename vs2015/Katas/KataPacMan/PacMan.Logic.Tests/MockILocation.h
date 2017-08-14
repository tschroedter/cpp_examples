#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "ILocation.h"
#include "RowAndColumn.h"

using namespace PacMan::Logic;

class MockILocation
    :public ILocation
{
public:
    // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
    MOCK_CONST_METHOD0(get_row, Row());
    MOCK_CONST_METHOD0(get_column,Column());
    // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
};
