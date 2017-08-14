#include "stdafx.h"
#include <gtest/gtest.h>
#include "MockILocation.h"
#include "MockIDirection.h"
#include "MockIPlayingField.h"
#include "ILocator.h"
#include "MonstersHeadingUpdater.h"
#include "MockILocator.h"
#include "MockIMonsterHeadingCalculator.h"
#include "../PacMan.View.Tests/MockIPlayingFieldObject.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            TEST(MonstersHeadingUpdater, initialize_calls_locator_initialize)
            {
                // Arrange
                MockIPlayingField* mock_playing_field = new MockIPlayingField{};
                IPlayingField_Ptr playing_field(mock_playing_field);

                MockILocator* mock_locator =
                    new MockILocator{};
                ILocator_Ptr locator(mock_locator);

                MockIMonsterHeadingCalculator* mock_calculator =
                    new MockIMonsterHeadingCalculator{};
                IMonsterHeadingCalculator_Ptr calculator(mock_calculator);

                MonstersHeadingUpdater sut
                {
                    locator,
                    calculator
                };

                EXPECT_CALL(*mock_locator,
                    initialize(
                        playing_field))
                                       .Times(1);

                // Act
                sut.initialize(playing_field);

                // Assert
            }

            ILocatorInformation_Ptr create_information (
                IPlayingFieldObject_Ptr object,
                Row row,
                Column column )
            {
                ILocatorInformation* p_monster_info = new ILocatorInformation{};
                ILocatorInformation_Ptr monster_info{p_monster_info};

                monster_info->row = row;
                monster_info->column = column;
                monster_info->object = object;

                return monster_info;
            }

            TEST(MonstersHeadingUpdater, update_sets_heading_of_monsters)
            {
                // Arrange
                MockIPlayingField* mock_playing_field = new MockIPlayingField{};
                IPlayingField_Ptr playing_field(mock_playing_field);

                MockILocator* mock_locator =
                    new MockILocator{};
                ILocator_Ptr locator(mock_locator);

                MockIMonsterHeadingCalculator* mock_calculator =
                    new MockIMonsterHeadingCalculator{};
                IMonsterHeadingCalculator_Ptr calculator(mock_calculator);

                MockIPlayingFieldObject* mock_monster_one = new MockIPlayingFieldObject();
                IPlayingFieldObject_Ptr monster_one{mock_monster_one};

                LocatorInformationVector* p_monsters = new LocatorInformationVector{};
                LocatorInformationVector_Ptr monsters{p_monsters};

                ILocatorInformation_Ptr monster_info_one =
                    create_information(
                                       monster_one,
                                       Row(1),
                                       Column(1));

                monsters->push_back(monster_info_one);

                MockIPlayingFieldObject* mock_monster_two = new MockIPlayingFieldObject();
                IPlayingFieldObject_Ptr monster_two{mock_monster_two};

                ILocatorInformation_Ptr monster_info_two =
                    create_information(
                                       monster_two,
                                       Row(1),
                                       Column(2));

                monsters->push_back(monster_info_two);

                MockIPlayingFieldObject* mock_pacman = new MockIPlayingFieldObject();

                IPlayingFieldObject_Ptr pacman{mock_pacman};

                LocatorInformationVector* p_pacmans = new LocatorInformationVector{};
                LocatorInformationVector_Ptr pacmans{p_pacmans};

                ILocatorInformation_Ptr pacman_info =
                    create_information(
                                       monster_one,
                                       Row(2),
                                       Column(2));

                pacmans->push_back(pacman_info);

                MonstersHeadingUpdater sut
                {
                    locator,
                    calculator
                };

                sut.initialize(playing_field);

                EXPECT_CALL(*mock_locator,
                    get_all_of_type(PlayingFieldObjectType_PacMan))
                                                                   .WillRepeatedly(testing::Return(pacmans));

                EXPECT_CALL(*mock_locator,
                    get_all_of_type(PlayingFieldObjectType_Monster))
                                                                    .WillRepeatedly(testing::Return(monsters));

                EXPECT_CALL(*mock_calculator,
                    get_heading())
                                  .WillRepeatedly(testing::Return(Heading_Down));

                EXPECT_CALL(*mock_monster_one,
                    set_heading(Heading_Down))
                                              .Times(1);

                EXPECT_CALL(*mock_monster_two,
                    set_heading(Heading_Down))
                                              .Times(1);

                // Act
                sut.update();

                // Assert
            }
        };
    };
};
