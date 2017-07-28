#include "stdafx.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "IDirection.h"
#include "MockIDirection.h"
#include "IObjectMoveCalculator.h"
#include "ObjectMoveCalculator.h"
#include "IMovingObjectsRepository.h"
#include "MovingObjectsRepository.h"
#include "ObjectsMover.h"
#include "MockIPlayingField.h"
#include "MockIMovingObjectsRepository.h"
#include "MockIObjectsMoverCalculator.h"

TEST(ObjectsMover, initialize_calls_calculator_initialize)
{
    using namespace PacMan::Logic;

    // Arrange
    MockIPlayingField* mock_playing_field = new MockIPlayingField{};
    IPlayingField_Ptr playing_field(mock_playing_field);

    MockIObjectsMoverCalculator* mock_calculator =
        new MockIObjectsMoverCalculator{};
    IObjectsMoverCalculator_Ptr calculator(mock_calculator);

    MockIMovingObjectsRepository* mock_repository =
        new MockIMovingObjectsRepository{};
    IMovingObjectsRepository_Ptr repository(mock_repository);

    IDirection_Ptr direction = std::make_shared<MockIDirection>();

    ObjectsMover sut
    {
        calculator,
        repository
    };

    EXPECT_CALL(*mock_calculator,
        initialize(
            playing_field,
            repository))
                        .Times(1);

    // Act
    sut.initialize(playing_field);

    // Assert
}

TEST(ObjectsMover, calculate_call_calculator_calculate)
{
    using namespace PacMan::Logic;

    // Arrange
    MockIPlayingField* mock_playing_field = new MockIPlayingField{};
    IPlayingField_Ptr playing_field(mock_playing_field);

    MockIObjectsMoverCalculator* mock_calculator =
        new MockIObjectsMoverCalculator{};
    IObjectsMoverCalculator_Ptr calculator(mock_calculator);

    MockIMovingObjectsRepository* mock_repository =
        new MockIMovingObjectsRepository{};
    IMovingObjectsRepository_Ptr repository(mock_repository);

    ObjectsMover sut
    {
        calculator,
        repository
    };

    sut.initialize(playing_field);

    EXPECT_CALL(*mock_calculator,
        calculate())
                    .Times(1);

    // Act
    sut.calculate();

    // Assert
}

TEST(ObjectsMover, print_moves_call_repositories_print_moves)
{
    using namespace PacMan::Logic;

    // Arrange
    MockIPlayingField* mock_playing_field = new MockIPlayingField{};
    IPlayingField_Ptr playing_field(mock_playing_field);

    MockIObjectsMoverCalculator* mock_calculator =
        new MockIObjectsMoverCalculator{};
    IObjectsMoverCalculator_Ptr calculator(mock_calculator);

    MockIMovingObjectsRepository* mock_repository =
        new MockIMovingObjectsRepository{};
    IMovingObjectsRepository_Ptr repository(mock_repository);

    ObjectsMover sut
    {
        calculator,
        repository
    };

    sut.initialize(playing_field);
    
    std::stringstream stream;

    EXPECT_CALL(*mock_repository,
        print_moves(testing::A<std::ostream&>()))
        .Times(1)
        .WillOnce(testing::ReturnRef(stream));

    // Act
    sut.print_moves(std::cout);

    // Assert
}
