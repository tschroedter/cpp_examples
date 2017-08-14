#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IMonsterHeadingCalculator.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            class MockIMonsterHeadingCalculator // todo common test lib
                :public IMonsterHeadingCalculator
            {
            public:
                // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
                MOCK_METHOD0(
                    calculate,
                    void());
                MOCK_CONST_METHOD0(
                    get_heading,
                    PacMan::Logic::Heading());
                // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
            };
        };
    };
};
