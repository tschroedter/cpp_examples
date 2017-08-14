#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IDirection.h"
#include "Heading.h"

using namespace ::PacMan::Logic;

class MockIDirection // todo common test lib
    :public IDirection
{
public:
    // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
    MOCK_CONST_METHOD0(get_heading, ::PacMan::Logic::Heading());
    MOCK_METHOD1(set_heading, void(::PacMan::Logic::Heading));
    // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
};
