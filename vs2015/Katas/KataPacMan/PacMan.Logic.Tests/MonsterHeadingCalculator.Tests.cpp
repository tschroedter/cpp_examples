#include "stdafx.h"
#include <gtest/gtest.h>
#include "MonsterHeadingCalculator.h"

void test_calculate_sets_heading (
    size_t monster_row,
    size_t monster_column,
    size_t pacman_row,
    size_t pacman_column,
    PacMan::Logic::Heading expected )
{
    using namespace PacMan::Logic;

    // Arrange
    MonsterHeadingCalculator sut{};

    sut.monster_row = monster_row;
    sut.monster_column = monster_column;
    sut.pacman_row = pacman_row;
    sut.pacman_column = pacman_column;

    // Act
    sut.calculate();

    // Assert
    Heading actual = sut.get_heading();

    EXPECT_EQ(expected, actual);
}

TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_0_0_and_pac_man_1_1)
{
    using namespace PacMan::Logic;

    test_calculate_sets_heading(
                                size_t{0},
                                size_t{0},
                                size_t{1},
                                size_t{1},
                                Heading_Down);
}

TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_0_1_and_pac_man_1_1)
{
    using namespace PacMan::Logic;

    test_calculate_sets_heading(
                                size_t{0},
                                size_t{1},
                                size_t{1},
                                size_t{1},
                                Heading_Down);
}

TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_0_2_and_pac_man_1_1)
{
    using namespace PacMan::Logic;

    test_calculate_sets_heading(
                                size_t{0},
                                size_t{2},
                                size_t{1},
                                size_t{1},
                                Heading_Down);
}

TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_1_0_and_pac_man_1_1)
{
    using namespace PacMan::Logic;

    test_calculate_sets_heading(
                                size_t{1},
                                size_t{0},
                                size_t{1},
                                size_t{1},
                                Heading_Right);
}

TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_1_1_and_pac_man_1_1)
{
    using namespace PacMan::Logic;

    test_calculate_sets_heading(
                                size_t{1},
                                size_t{1},
                                size_t{1},
                                size_t{1},
                                Heading_Unknown);
}

TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_1_2_and_pac_man_1_1)
{
    using namespace PacMan::Logic;

    test_calculate_sets_heading(
                                size_t{1},
                                size_t{2},
                                size_t{1},
                                size_t{1},
                                Heading_Left);
}

TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_2_0_and_pac_man_1_1)
{
    using namespace PacMan::Logic;

    test_calculate_sets_heading(
                                size_t{2},
                                size_t{0},
                                size_t{1},
                                size_t{1},
                                Heading_Up);
}

TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_2_1_and_pac_man_1_1)
{
    using namespace PacMan::Logic;

    test_calculate_sets_heading(
                                size_t{2},
                                size_t{1},
                                size_t{1},
                                size_t{1},
                                Heading_Up);
}

TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_2_2_and_pac_man_1_1)
{
    using namespace PacMan::Logic;

    test_calculate_sets_heading(
                                size_t{2},
                                size_t{2},
                                size_t{1},
                                size_t{1},
                                Heading_Up);
}
