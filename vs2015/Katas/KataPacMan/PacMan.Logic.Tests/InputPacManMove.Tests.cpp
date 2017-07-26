#include "stdafx.h"
#include <gtest/gtest.h>
#include "InputMoveForPacMan.h"

void test_get_heading_for_given_char_and_expected_heading (
    const char input,
    const PacMan::Logic::Heading heading )
{
    using namespace PacMan::Logic;

    // Arrange
    std::stringstream out;
    std::stringstream in;

    in << input << '\n';

    InputPacManMove sut
    {
        out,
        in
    };

    sut.initialize();

    // Act
    Heading actual = sut.get_heading();

    // Assert
    EXPECT_EQ(heading, actual);
}

TEST(InputPacManMove, get_heading_returns_Heading_Up_for_w)
{
    using namespace PacMan::Logic;

    test_get_heading_for_given_char_and_expected_heading('w', Heading_Up);
}

TEST(InputPacManMove, get_heading_returns_Heading_Down_for_s)
{
    using namespace PacMan::Logic;

    test_get_heading_for_given_char_and_expected_heading('s', Heading_Down);
}

TEST(InputPacManMove, get_heading_returns_Heading_Left_for_a)
{
    using namespace PacMan::Logic;

    test_get_heading_for_given_char_and_expected_heading('a', Heading_Left);
}

TEST(InputPacManMove, get_heading_returns_Heading_Right_for_d)
{
    using namespace PacMan::Logic;

    test_get_heading_for_given_char_and_expected_heading('d', Heading_Right);
}
