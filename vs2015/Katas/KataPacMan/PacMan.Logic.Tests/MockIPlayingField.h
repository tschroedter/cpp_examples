#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IPlayingField.h"
#include "IPlayingFieldObject.h"

class MockIPlayingField
        :public PacMan::Logic::IPlayingField
{
public:
    // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
    MOCK_METHOD2(
        initialize, void(
            const size_t rows,
            const size_t columns));
    MOCK_CONST_METHOD0(
        get_rows, size_t());
    MOCK_CONST_METHOD0(
        get_columns, size_t());
    MOCK_METHOD2(
        get_object_at, PacMan::Logic::IPlayingFieldObject_Ptr(
            const size_t rows,
            const size_t columns));
    MOCK_METHOD2(
        get_object_type_at, PacMan::Logic::PlayingFieldObjectType(
            const size_t rows,
            const size_t columns));
    MOCK_METHOD3(
        put_object_at, void(
            const PacMan::Logic::IPlayingFieldObject_Ptr,
            const size_t rows,
            const size_t columns));
    MOCK_METHOD4(
        move_object_from_to, void(
            const size_t from_row,
            const size_t from_column,
            const size_t to_row,
            const size_t to_column));
    // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
};
