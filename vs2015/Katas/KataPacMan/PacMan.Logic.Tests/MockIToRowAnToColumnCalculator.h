#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IToRowAnToColumnCalculator.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            class MockIToRowAnToColumnCalculator
                :public IToRowAnToColumnCalculator
            {
            public:
                // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
                MOCK_METHOD1(initialize, void(const IPlayingField_Ptr playing_field));
                MOCK_METHOD0(caclulate, void());
                // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
            };
        };
    };
};
