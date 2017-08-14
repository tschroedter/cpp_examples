#include "stdafx.h"
#include <gtest/gtest.h>
#include "MonsterHeadingCalculator.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            void test_calculate_sets_heading (
                Row monster_row,
                Column monster_column,
                Row pacman_row,
                Column pacman_column,
                Heading expected )
            {
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
                test_calculate_sets_heading(
                                            Row{0},
                                            Column{0},
                                            Row{1},
                                            Column{1},
                                            Heading_Down);
            }

            TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_0_1_and_pac_man_1_1)
            {
                test_calculate_sets_heading(
                                            Row{0},
                                            Column{1},
                                            Row{1},
                                            Column{1},
                                            Heading_Down);
            }

            TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_0_2_and_pac_man_1_1)
            {
                test_calculate_sets_heading(
                                            Row{0},
                                            Column{2},
                                            Row{1},
                                            Column{1},
                                            Heading_Down);
            }

            TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_1_0_and_pac_man_1_1)
            {
                test_calculate_sets_heading(
                                            Row{1},
                                            Column{0},
                                            Row{1},
                                            Column{1},
                                            Heading_Right);
            }

            TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_1_1_and_pac_man_1_1)
            {
                test_calculate_sets_heading(
                                            Row{1},
                                            Column{1},
                                            Row{1},
                                            Column{1},
                                            Heading_Unknown);
            }

            TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_1_2_and_pac_man_1_1)
            {
                test_calculate_sets_heading(
                                            Row{1},
                                            Column{2},
                                            Row{1},
                                            Column{1},
                                            Heading_Left);
            }

            TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_2_0_and_pac_man_1_1)
            {
                using namespace Logic;

                test_calculate_sets_heading(
                                            Row{2},
                                            Column{0},
                                            Row{1},
                                            Column{1},
                                            Heading_Up);
            }

            TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_2_1_and_pac_man_1_1)
            {
                test_calculate_sets_heading(
                                            Row{2},
                                            Column{1},
                                            Row{1},
                                            Column{1},
                                            Heading_Up);
            }

            TEST(MonsterHeadingCalculator, calculate_sets_heading_for_monster_2_2_and_pac_man_1_1)
            {
                test_calculate_sets_heading(
                                            Row{2},
                                            Column{2},
                                            Row{1},
                                            Column{1},
                                            Heading_Up);
            }
        };
    };
};
