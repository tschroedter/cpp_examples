#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IDirection.h"
#include "Heading.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            class MockIDirection
                :public IDirection
            {
            public:
                // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
                MOCK_CONST_METHOD0(get_heading, ::PacMan::Logic::Heading());
                MOCK_METHOD1(set_heading, void(::PacMan::Logic::Heading));
                // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
            };
        }
    }
}
