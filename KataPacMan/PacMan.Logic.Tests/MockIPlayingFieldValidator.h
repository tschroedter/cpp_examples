#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-generated-function-mockers.h>
#include "IPlayingFieldValidator.h"
#include "IPlayingFieldObject.h"

class MockIPlayingFieldValidator
        :public PacMan::Logic::IPlayingFieldValidator
{
public:
    // ReSharper disable CppOverridingFunctionWithoutOverrideSpecifier
    MOCK_METHOD2(initialize,
        void(const size_t rows, const size_t columns));
    MOCK_CONST_METHOD0(get_rows, size_t());
    MOCK_CONST_METHOD0(get_columns, size_t());
    MOCK_CONST_METHOD1(validate_object, void(const PacMan::Logic::IPlayingFieldObject_Ptr));
    MOCK_CONST_METHOD1(validate_row, void(const size_t row));
    MOCK_CONST_METHOD1(validate_column, void(const size_t column));
    MOCK_CONST_METHOD2(validate_rows_and_columns,
        void(const size_t row, const size_t column));
    // ReSharper restore CppOverridingFunctionWithoutOverrideSpecifier
};
