#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IPlayingFieldValidator.h"
#include "IPlayingFieldObject.h"

using namespace PacMan::Logic;

class MockIPlayingFieldValidator
    :public IPlayingFieldValidator
{
public:
    // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
    MOCK_METHOD2(initialize,
        void(
            const PacMan::Logic::Row rows,
            const PacMan::Logic::Column columns));
    MOCK_CONST_METHOD0(get_rows, PacMan::Logic::Row());
    MOCK_CONST_METHOD0(get_columns, PacMan::Logic::Column());
    MOCK_CONST_METHOD1(validate_object, void(const PacMan::Logic::IPlayingFieldObject_Ptr));
    MOCK_CONST_METHOD1(validate_row, void(const PacMan::Logic::Row row));
    MOCK_CONST_METHOD1(validate_column, void(const PacMan::Logic::Column column));
    MOCK_CONST_METHOD2(validate_rows_and_columns,
        void(
            const PacMan::Logic::Row row,
            const PacMan::Logic::Column column));
    // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
};
