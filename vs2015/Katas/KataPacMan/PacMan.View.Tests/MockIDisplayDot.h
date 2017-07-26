#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IDisplayDot.h"

class MockIDisplayDot
    :public PacMan::View::IDisplayDot
{
public:
    // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
    MOCK_CONST_METHOD0(get_type, PacMan::View::DisplayObjectType());
    MOCK_CONST_METHOD0(to_string, std::string());
    MOCK_METHOD1(initialize, void(const PacMan::Logic::IPlayingFieldObject_Ptr object));
    // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
};
