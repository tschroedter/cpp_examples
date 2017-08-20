#include "stdafx.h"
#include <gtest/gtest.h>
#include "MockIObjectMoveCalculator.h"
#include "MockIPlayingFieldObject.h"
#include "MockIPlayingField.h"
#include "MoveObjectInformation.h"
#include "ToRowAnToColumnCalculator.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            void test_ToRowAnToColumnCalculator (
                const Row from_row,
                const Column from_column,
                const Row to_row,
                const Column to_column,
                const PlayingFieldObjectType type,
                const Row expected_row,
                const Column expected_column )
            {
                // Arrange
                Heading heading = Heading_Right;

                MockIObjectMoveCalculator* mock_calculator = new MockIObjectMoveCalculator{};
                IObjectMoveCalculator_Ptr calculator(mock_calculator);

                mock_calculator->to_row = to_row;
                mock_calculator->to_column = to_column;

                EXPECT_CALL(
                    *mock_calculator,
                    calculate(
                        from_row,
                        from_column,
                        heading))
                                 .Times(1);

                MockIPlayingField* mock_playing_field = new MockIPlayingField{};
                IPlayingField_Ptr playing_field(mock_playing_field);

                EXPECT_CALL(
                    *mock_playing_field,
                    get_object_type_at(
                        testing::_,
                        testing::_))
                                    .WillRepeatedly(testing::Return(type));

                ToRowAnToColumnCalculator sut
                {
                    calculator
                };

                sut.initialize(playing_field);

                sut.from_row = from_row;
                sut.from_column = from_column;
                sut.heading = heading;

                // Act
                sut.caclulate();

                // Assert
                EXPECT_EQ(expected_row, sut.to_row);
                EXPECT_EQ(expected_column, sut.to_column);
            }

            TEST(ToRowAnToColumnCalculator, calculate_sets_to_row_and_to_column_for_target_is_wall)
            {
                test_ToRowAnToColumnCalculator(
                                               Row{1},
                                               Column{2},
                                               Row{3},
                                               Column{4},
                                               PlayingFieldObjectType_Wall,
                                               Row{1},
                                               Column{2});
            }

            TEST(ToRowAnToColumnCalculator, calculate_sets_to_row_and_to_column_for_target_is_not_wall)
            {
                test_ToRowAnToColumnCalculator(
                                               Row{1},
                                               Column{2},
                                               Row{3},
                                               Column{4},
                                               PlayingFieldObjectType_Dot,
                                               Row{3},
                                               Column{4});
            }
        };
    };
};
