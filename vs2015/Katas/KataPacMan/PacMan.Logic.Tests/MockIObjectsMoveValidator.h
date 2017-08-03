#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IObjectsMoveValidator.h"

class MockIObjectsMoveValidator // todo common test lib
    :public IObjectsMoveValidator
{
public:
    // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
    MOCK_METHOD0(
        validate_moves,
        void());
    MOCK_METHOD1(
        initialize,
        void(const PacMan::Logic::IMovingObjectsRepository_Ptr& playing_field));
    MOCK_CONST_METHOD0(
        get_status,
        ValidationStatus());
    // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
};
