#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "ILogger.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Common;

            class MockILogger
                :public ILogger
            {
            public:
                // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
                MOCK_CONST_METHOD1(debug, void(const std::string message));
                MOCK_CONST_METHOD1(error, void(const std::string message));
                MOCK_CONST_METHOD1(info, void(const std::string message));
                MOCK_CONST_METHOD1(warning, void(const std::string message));
                // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
            };
        };
    };
};
