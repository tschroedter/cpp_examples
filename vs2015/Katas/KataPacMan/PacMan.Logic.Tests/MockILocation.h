#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>

class MockILocation
    :public PacMan::Logic::ILocation
{
public:
    // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
    MOCK_CONST_METHOD0(get_row, size_t());
    MOCK_CONST_METHOD0(get_column,size_t());
    // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
};
