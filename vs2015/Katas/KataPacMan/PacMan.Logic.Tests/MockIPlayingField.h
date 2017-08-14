#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IPlayingField.h"
#include "IPlayingFieldObject.h"

using namespace PacMan::Logic;

class MockIPlayingField
    :public IPlayingField
{
public:
    // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
    MOCK_METHOD2(
        initialize, void(
            const PacMan::Logic::Row rows,
            const PacMan::Logic::Column columns));
    MOCK_CONST_METHOD0(
        get_rows, PacMan::Logic::Row());
    MOCK_CONST_METHOD0(
        get_columns, PacMan::Logic::Column());
    MOCK_METHOD2(
        get_object_at, PacMan::Logic::IPlayingFieldObject_Ptr(
            const PacMan::Logic::Row rows,
            const PacMan::Logic::Column columns));
    MOCK_METHOD2(
        get_object_type_at, PacMan::Logic::PlayingFieldObjectType(
            const PacMan::Logic::Row rows,
            const PacMan::Logic::Column columns));
    MOCK_METHOD3(
        put_object_at, void(
            const PacMan::Logic::IPlayingFieldObject_Ptr,
            const PacMan::Logic::Row rows,
            const PacMan::Logic::Column columns));
    MOCK_METHOD4(
        move_object_from_to, void(
            const PacMan::Logic::Row from_row,
            const PacMan::Logic::Column from_column,
            const PacMan::Logic::Row to_row,
            const PacMan::Logic::Column to_column));
    // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
};
