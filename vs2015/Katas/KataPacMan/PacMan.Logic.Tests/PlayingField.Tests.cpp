#include "stdafx.h"
#include <gtest/gtest.h>
#include "PlayingField.h"
#include "MockIPlayingFieldValidator.h"
#include "Hypodermic/FactoryWrapper.h"
#include "MockIDot.h"
#include "Dot.h"
#include "MockIDirection.h"
#include "MockILocation.h"

using namespace PacMan::Logic;

std::function<std::shared_ptr<IDot>  ()> create_factory ()
{
    return []
    {
        using namespace PacMan::Logic;

        ILocation_Ptr location = std::make_shared<MockILocation>();
        IDirection_Ptr direction = std::make_shared<MockIDirection>();

        return std::make_shared<Dot>(location,
                                     direction);
    };
}

Hypodermic::FactoryWrapper<IDot> wrapper{create_factory()};

std::unique_ptr<PlayingField> create_sut_using_mock ()
{
    MockIPlayingFieldValidator* mock_validator = new MockIPlayingFieldValidator{};
    IPlayingFieldValidator_Ptr validator(mock_validator);
    auto sut = std::make_unique<PlayingField>(
                                              wrapper,
                                              validator);

    sut->initialize(
                    Row(3),
                    Column(4));

    return sut;
}

TEST(PlayingField, initialize_calls_validator)
{
    // Arrange
    Row rows(1);
    Column columns(2);

    MockIPlayingFieldValidator* mock_validator = new MockIPlayingFieldValidator{};
    IPlayingFieldValidator_Ptr validator(mock_validator);
    auto sut = std::make_unique<PlayingField>(
                                              wrapper,
                                              validator);

    EXPECT_CALL(*mock_validator,
        initialize(rows, columns))
                                  .Times(1);

    // Act
    sut->initialize(rows, columns);

    // Assert
}

TEST(PlayingField, constructor_sets_rows)
{
    // Arrange
    Row expected{3};

    auto sut = create_sut_using_mock();

    // Act
    Row actual = sut->get_rows();

    // Assert
    EXPECT_EQ(expected, actual);
}

TEST(PlayingField, constructor_sets_columns)
{
    // Arrange
    Column expected{4};

    auto sut = create_sut_using_mock();

    // Act
    Column actual = sut->get_columns();

    // Assert
    EXPECT_EQ(expected, actual);
}

TEST(PlayingField, constructor_populates_field_with_dots)
{
    // Arrange
    auto sut = create_sut_using_mock();

    // Act
    for (Row row = 0; row < sut->get_rows(); row++)
    {
        for (Column column = 0; column < sut->get_columns(); column++)
        {
            std::cout << "["
                << std::to_string(row)
                << ","
                << std::to_string(column)
                << "] ";

            auto actual = sut->get_object_type_at(row, column);

            // Assert
            EXPECT_EQ(PlayingFieldObjectType_Dot, actual);

            std::cout << "Passed!\n";
        }
    }
}

TEST(PlayingField, get_object_type_at_returns_type)
{
    // Arrange
    Row row(0);
    Column column(0);
    auto sut = create_sut_using_mock();

    // Act
    char actual = sut->get_object_type_at(row, column);

    // Assert
    EXPECT_EQ(PlayingFieldObjectType_Dot, actual);
}

TEST(PlayingField, put_object_at_puts_object_at_given_row_column)
{
    // Arrange
    IPlayingFieldObject_Ptr expected{};
    Row row(0);
    Column column(1);

    auto sut = create_sut_using_mock();

    // Act
    sut->put_object_at(expected, row, column);

    // Assert
    auto actual = sut->get_object_at(row, column);

    EXPECT_EQ(expected, actual);
}

TEST(PlayingField, move_object_from_to_moves_object)
{
    // Arrange
    IPlayingFieldObject_Ptr expected{};
    auto sut = create_sut_using_mock();
    sut->put_object_at(expected, 0, 0);

    // Act
    sut->move_object_from_to(0, 0, 1, 1);

    // Assert
    auto actual = sut->get_object_at(1, 1);

    EXPECT_EQ(expected, actual);
}

TEST(PlayingField, move_object_from_to_fills_empty_spot_with_dot)
{
    // Arrange
    IPlayingFieldObject_Ptr expected{};
    auto sut = create_sut_using_mock();
    sut->put_object_at(expected, 0, 0);

    // Act
    sut->move_object_from_to(0, 0, 1, 1);

    // Assert
    auto actual = sut->get_object_at(0, 0);

    EXPECT_EQ(PlayingFieldObjectType::PlayingFieldObjectType_Dot, actual->get_type());
}
