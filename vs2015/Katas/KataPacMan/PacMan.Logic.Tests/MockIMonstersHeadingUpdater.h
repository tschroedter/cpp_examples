#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IMonstersHeadingUpdater.h"

using namespace PacMan::Logic;

class MockIMonstersHeadingUpdater // todo common test lib
    :public IMonstersHeadingUpdater
{
public:
    // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
    MOCK_METHOD1(
        initialize,
        void(const IPlayingField_Ptr& playing_field));
    MOCK_CONST_METHOD0(
        update,
        void());
    // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
};
