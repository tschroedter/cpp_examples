#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "ILocator.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            class MockILocator // todo common test lib
                :public ILocator
            {
            public:
                // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
                MOCK_METHOD0(
                    get_all,
                    PacMan::Logic::LocatorInformationVector_Ptr());
                MOCK_METHOD1(
                    get_all_of_type,
                    PacMan::Logic::LocatorInformationVector_Ptr(PlayingFieldObjectType type));
                MOCK_METHOD1(
                    initialize,
                    void(const PacMan::Logic::IPlayingField_Ptr& playing_field));
                // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
            };
        };
    };
};
