#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IObjectsMoverCalculator.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            class MockIObjectsMoverCalculator
                :public IObjectsMoverCalculator
            {
            public:
                // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
                MOCK_METHOD2(
                    initialize,
                    void(const IPlayingField_Ptr playing_field,
                        const IMovingObjectsRepository_Ptr repository));
                MOCK_CONST_METHOD0(
                    calculate,
                    void());
                // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
            };
        };
    };
};
