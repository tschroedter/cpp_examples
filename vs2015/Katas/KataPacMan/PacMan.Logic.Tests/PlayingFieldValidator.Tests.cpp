#include "stdafx.h"
#include <gtest/gtest.h>
#include "PlayingFieldException.h"
#include "PlayingFieldValidator.h"
#include "MockIPlayingFieldObject.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            IPlayingFieldValidator_Ptr create_sut ()
            {
                IPlayingFieldValidator_Ptr sut = std::make_shared<PlayingFieldValidator>();
                sut->initialize(Row(1), Column(2));

                return sut;
            }

            TEST(PlayingFieldValidator, constructor_sets_rows)
            {
                // Arrange
                Row expected{1};

                IPlayingFieldValidator_Ptr sut = create_sut();

                // Act
                Row actual = sut->get_rows();

                // Assert
                EXPECT_EQ(expected, actual);
            }

            TEST(PlayingFieldValidator, constructor_sets_columns)
            {
                // Arrange
                Column expected{2};

                IPlayingFieldValidator_Ptr sut = create_sut();

                // Act
                Column actual = sut->get_columns();

                // Assert
                EXPECT_EQ(expected, actual);
            }

            TEST(PlayingFieldValidator, validate_rows_and_columns_throws_for_row_is_invalid)
            {
                // Arrange
                Row row_invalid(100);
                Column column_valid(0);

                IPlayingFieldValidator_Ptr sut = create_sut();

                // Act
                // Assert
                EXPECT_THROW(
                    sut->validate_rows_and_columns(
                        row_invalid,
                        column_valid),
                    PacMan::Logic::PlayingFieldException);
            }

            TEST(PlayingFieldValidator, validate_rows_and_columns_throws_for_column_is_invalid)
            {
                // Arrange
                Row row_valid(0);
                Column column_invalid(100);

                IPlayingFieldValidator_Ptr sut = create_sut();

                // Act
                // Assert
                EXPECT_THROW(
                    sut->validate_rows_and_columns(
                        row_valid,
                        column_invalid),
                    PacMan::Logic::PlayingFieldException);
            }

            TEST(PlayingFieldValidator, validate_rows_and_columns_does_not_throws_for_valid_row_and_column)
            {
                // Arrange
                Row row_valid(1);
                Column column_valid(1);

                IPlayingFieldValidator_Ptr sut = create_sut();

                // Act
                // Assert
                EXPECT_NO_THROW(
                    sut->validate_rows_and_columns(
                        row_valid,
                        column_valid),
                    PacMan::Logic::PlayingFieldException);
            }

            TEST(PlayingFieldValidator, validate_column_throws_for_nullptr)
            {
                // Arrange
                IPlayingFieldValidator_Ptr sut = create_sut();

                // Act
                // Assert
                EXPECT_THROW(
                    sut->validate_object(nullptr),
                    PacMan::Logic::PlayingFieldException);
            }

            TEST(PlayingFieldValidator, validate_column_does_not_throws_for_object)
            {
                // Arrange
                IPlayingFieldObject_Ptr object = std::make_shared<MockIPlayingFieldObject>();

                IPlayingFieldValidator_Ptr sut = create_sut();

                // Act
                // Assert
                EXPECT_NO_THROW(
                    sut->validate_object(object),
                    PacMan::Logic::PlayingFieldException);
            }
        };
    };
};
