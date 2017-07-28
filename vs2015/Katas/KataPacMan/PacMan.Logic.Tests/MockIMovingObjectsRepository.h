#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IMovingObjectsRepository.h"

class MockIMovingObjectsRepository
    :public PacMan::Logic::IMovingObjectsRepository
{
public:
    // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
    MOCK_METHOD1(
        add,
        void(const PacMan::Logic::IMoveObjectInformation_Ptr information));
    MOCK_METHOD0(
        clear,
        void());
    MOCK_CONST_METHOD0(
        get_all,
        PacMan::Logic::MovingObjectsInformationVector_Ptr());
    MOCK_CONST_METHOD1(
        get_all_of_type,
        PacMan::Logic::MovingObjectsInformationVector_Ptr(PacMan::Logic::PlayingFieldObjectType type));
    MOCK_CONST_METHOD1(
        print_moves,
        std::ostream&(std::ostream& out));
    // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
};
