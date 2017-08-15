#include "stdafx.h"
#include <gtest/gtest.h>
#include "ObjectsMoverCalculator.h"
#include "MockIObjectMoveCalculator.h"
#include "MockIPlayingFieldObject.h"
#include "MockIPlayingField.h"
#include "MockIMovingObjectsRepository.h"
#include "MoveObjectInformation.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            std::function<std::shared_ptr<IMoveObjectInformation>  ()> create_factory ()
            {
                return []
                {
                    using namespace Logic;

                    MoveObjectInformation* p_info = new MoveObjectInformation{};

                    IMoveObjectInformation_Ptr info{p_info};

                    return info;
                };
            }

            Hypodermic::FactoryWrapper<IMoveObjectInformation> wrapper
            {
                create_factory()
            };

            TEST(ObjectsMoverCalculator, initialize_call_calculator_initialize)
            {
                // Arrange
                MockIPlayingField* mock_playing_field = new MockIPlayingField{};
                IPlayingField_Ptr playing_field(mock_playing_field);

                MockIMovingObjectsRepository* mock_repository = new MockIMovingObjectsRepository{};
                IMovingObjectsRepository_Ptr repository(mock_repository);

                MockIObjectMoveCalculator* mock_calculator = new MockIObjectMoveCalculator{};
                IObjectMoveCalculator_Ptr calculator(mock_calculator);

                EXPECT_CALL(
                    *mock_calculator,
                    initialize(playing_field))
                                              .Times(1);

                ObjectsMoverCalculator sut
                {
                    wrapper,
                    calculator
                };

                // Act
                sut.initialize(playing_field,
                               repository);

                // Assert
            }

            TEST(ObjectsMoverCalculator, create_info_returns_new_info_instance)
            {
                // Arrange
                Row from_row(1);
                Column from_column(2);
                Row to_row(3);
                Column to_column(4);
                PlayingFieldObjectType type = PlayingFieldObjectType_PacMan;

                MockIPlayingFieldObject* mock_object = new MockIPlayingFieldObject{};
                IPlayingFieldObject_Ptr object(mock_object);

                EXPECT_CALL(*mock_object,
                    get_heading())
                                  .WillRepeatedly(testing::Return(Heading_Left));

                EXPECT_CALL(*mock_object,
                    get_type())
                               .WillRepeatedly(testing::Return(type));

                MockIObjectMoveCalculator* mock_calculator = new MockIObjectMoveCalculator{};
                IObjectMoveCalculator_Ptr calculator(mock_calculator);

                mock_calculator->to_row = to_row;
                mock_calculator->to_column = to_column;

                ObjectsMoverCalculator sut
                {
                    wrapper,
                    calculator
                };

                // Act
                auto actual = sut.create_info(from_row,
                                              from_column,
                                              object);

                // Assert
                EXPECT_EQ(from_row, actual->from_row);
                EXPECT_EQ(from_column, actual->from_column);
                EXPECT_EQ(to_row, actual->to_row);
                EXPECT_EQ(to_column, actual->to_column);
                EXPECT_EQ(type, actual->playing_field_object_type);
            }

            void test_calculate_for_is_moving (
                bool is_moving,
                int expected_number_of_calls )
            {
                // Arrange
                Row to_row(3);
                Column to_column(4);
                PlayingFieldObjectType type = PlayingFieldObjectType_PacMan;

                MockIPlayingFieldObject* mock_object = new MockIPlayingFieldObject{};
                IPlayingFieldObject_Ptr object(mock_object);

                EXPECT_CALL(*mock_object,
                    get_heading())
                                  .WillRepeatedly(testing::Return(Heading_Left));

                EXPECT_CALL(*mock_object,
                    get_type())
                               .WillRepeatedly(testing::Return(type));

                EXPECT_CALL(*mock_object,
                    is_moving())
                                .WillRepeatedly(testing::Return(is_moving));

                MockIObjectMoveCalculator* mock_calculator = new MockIObjectMoveCalculator{};
                IObjectMoveCalculator_Ptr calculator(mock_calculator);

                mock_calculator->to_row = to_row;
                mock_calculator->to_column = to_column;

                MockIPlayingField* mock_playing_field = new MockIPlayingField{};
                IPlayingField_Ptr playing_field(mock_playing_field);

                EXPECT_CALL(
                    *mock_playing_field,
                    get_rows())
                               .WillRepeatedly(testing::Return(Row(3)));
                EXPECT_CALL(
                    *mock_playing_field,
                    get_columns())
                                  .WillRepeatedly(testing::Return(Column(3)));
                EXPECT_CALL(
                    *mock_playing_field,
                    get_object_at(
                        testing::_,
                        testing::_))
                                    .WillRepeatedly(testing::Return(object));

                MockIMovingObjectsRepository* mock_repository = new MockIMovingObjectsRepository{};
                IMovingObjectsRepository_Ptr repository(mock_repository);

                EXPECT_CALL(
                    *mock_repository,
                    add(testing::A<IMoveObjectInformation_Ptr>()))
                                                                  .Times(expected_number_of_calls);

                ObjectsMoverCalculator sut
                {
                    wrapper,
                    calculator
                };

                sut.initialize(playing_field,
                               repository);
                // Act
                sut.calculate();

                // Assert
            }

            TEST(ObjectsMoverCalculator, calculate_calls_repository_add_for_object_is_moving_true)
            {
                test_calculate_for_is_moving(true, 9);
            }

            TEST(ObjectsMoverCalculator, calculate_calls_repository_add_for_object_is_moving_false)
            {
                test_calculate_for_is_moving(false, 0);
            }

            TEST(ObjectsMoverCalculator, calculate_calls_repository_clear)
            {
                // Arrange
                MockIPlayingFieldObject* mock_object = new MockIPlayingFieldObject{};
                IPlayingFieldObject_Ptr object(mock_object);

                MockIObjectMoveCalculator* mock_calculator = new MockIObjectMoveCalculator{};
                IObjectMoveCalculator_Ptr calculator(mock_calculator);

                MockIPlayingField* mock_playing_field = new MockIPlayingField{};
                IPlayingField_Ptr playing_field(mock_playing_field);

                MockIMovingObjectsRepository* mock_repository = new MockIMovingObjectsRepository{};
                IMovingObjectsRepository_Ptr repository(mock_repository);

                EXPECT_CALL(
                    *mock_repository,
                    clear())
                            .Times(1);

                ObjectsMoverCalculator sut
                {
                    wrapper,
                    calculator
                };

                sut.initialize(playing_field,
                               repository);

                // Act
                sut.calculate();

                // Assert
            }
        };
    };
};
