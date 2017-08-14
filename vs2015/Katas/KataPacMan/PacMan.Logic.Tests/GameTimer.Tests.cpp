#include "stdafx.h"
#include "GameTimer.h"
#include <gtest/gtest.h>
#include "MockIPlayingField.h"
#include "../PacMan.View.Tests/MockIPlayingFieldObject.h"
#include "MockIObjectMover.h"
#include "MockIObjectsMover.h"
#include "../PacMan.View.Tests/MockIObjectsTicker.h"
#include "MockIMonstersHeadingUpdater.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            TEST(GameTimer, initialize_calls_monster_updater_initialize)
            {
                // Arrange
                MockIPlayingField* mock_playing_field = new MockIPlayingField{};
                IPlayingField_Ptr playing_field(mock_playing_field);

                MockIObjectsMover* mock_objects_mover = new MockIObjectsMover{};
                IObjectsMover_Ptr objects_mover(mock_objects_mover);

                MockIObjectsTicker* mock_objects_ticker = new MockIObjectsTicker{};
                IObjectsTicker_Ptr objects_ticker(mock_objects_ticker);

                MockIMonstersHeadingUpdater* mock_monster_updater = new MockIMonstersHeadingUpdater{};
                IMonstersHeadingUpdater_Ptr monster_updater(mock_monster_updater);

                GameTimer sut{
                    monster_updater,
                    objects_mover,
                    objects_ticker
                };

                EXPECT_CALL(*mock_monster_updater,
                    initialize(playing_field))
                                              .Times(1);

                // Act
                sut.initialize(playing_field);

                // Assert
            }

            TEST(GameTimer, initialize_calls_objects_movers_initialize)
            {
                using namespace Logic;

                // Arrange
                MockIPlayingField* mock_playing_field = new MockIPlayingField{};
                IPlayingField_Ptr playing_field(mock_playing_field);

                MockIObjectsMover* mock_objects_mover = new MockIObjectsMover{};
                IObjectsMover_Ptr objects_mover(mock_objects_mover);

                MockIObjectsTicker* mock_objects_ticker = new MockIObjectsTicker{};
                IObjectsTicker_Ptr objects_ticker(mock_objects_ticker);

                MockIMonstersHeadingUpdater* mock_monster_updater = new MockIMonstersHeadingUpdater{};
                IMonstersHeadingUpdater_Ptr monster_updater(mock_monster_updater);

                GameTimer sut{
                    monster_updater,
                    objects_mover,
                    objects_ticker
                };

                EXPECT_CALL(*mock_objects_mover,
                    initialize(playing_field))
                                              .Times(1);

                // Act
                sut.initialize(playing_field);

                // Assert
            }

            TEST(GameTimer, initialize_calls_objects_ticker_initialize)
            {
                // Arrange
                MockIPlayingField* mock_playing_field = new MockIPlayingField{};
                IPlayingField_Ptr playing_field(mock_playing_field);

                MockIObjectsMover* mock_objects_mover = new MockIObjectsMover{};
                IObjectsMover_Ptr objects_mover(mock_objects_mover);

                MockIObjectsTicker* mock_objects_ticker = new MockIObjectsTicker{};
                IObjectsTicker_Ptr objects_ticker(mock_objects_ticker);

                MockIMonstersHeadingUpdater* mock_monster_updater = new MockIMonstersHeadingUpdater{};
                IMonstersHeadingUpdater_Ptr monster_updater(mock_monster_updater);

                GameTimer sut{
                    monster_updater,
                    objects_mover,
                    objects_ticker
                };

                EXPECT_CALL(*mock_objects_ticker,
                    initialize(playing_field))
                                              .Times(1);

                // Act
                sut.initialize(playing_field);

                // Assert
            }

            TEST(GameTimer, get_status_calls_get_status)
            {
                // Arrange
                MockIPlayingField* mock_playing_field = new MockIPlayingField{};
                IPlayingField_Ptr playing_field(mock_playing_field);

                MockIObjectsMover* mock_objects_mover = new MockIObjectsMover{};
                IObjectsMover_Ptr objects_mover(mock_objects_mover);

                MockIObjectsTicker* mock_objects_ticker = new MockIObjectsTicker{};
                IObjectsTicker_Ptr objects_ticker(mock_objects_ticker);

                MockIMonstersHeadingUpdater* mock_monster_updater = new MockIMonstersHeadingUpdater{};
                IMonstersHeadingUpdater_Ptr monster_updater(mock_monster_updater);

                GameTimer sut{
                    monster_updater,
                    objects_mover,
                    objects_ticker
                };

                sut.initialize(playing_field);

                EXPECT_CALL(*mock_objects_mover,
                    get_status())
                                 .WillRepeatedly(testing::Return(ValidationStatus_PacMan_ALive));

                // Act
                auto actual = sut.get_status();

                // Assert
                EXPECT_EQ(ValidationStatus_PacMan_ALive,
                    actual);
            }

            TEST(GameTimer, tick_calls_tick)
            {
                // Arrange
                MockIPlayingField* mock_playing_field = new MockIPlayingField{};
                IPlayingField_Ptr playing_field(mock_playing_field);

                MockIObjectsMover* mock_objects_mover = new MockIObjectsMover{};
                IObjectsMover_Ptr objects_mover(mock_objects_mover);

                MockIObjectsTicker* mock_objects_ticker = new MockIObjectsTicker{};
                IObjectsTicker_Ptr objects_ticker(mock_objects_ticker);

                MockIMonstersHeadingUpdater* mock_monster_updater = new MockIMonstersHeadingUpdater{};
                IMonstersHeadingUpdater_Ptr monster_updater(mock_monster_updater);

                GameTimer sut{
                    monster_updater,
                    objects_mover,
                    objects_ticker
                };

                sut.initialize(playing_field);

                std::stringstream stream;

                EXPECT_CALL(*mock_objects_mover,
                    print_moves(testing::A<std::ostream&>()))
                                                             .Times(1)
                                                             .WillOnce(testing::ReturnRef(stream));

                EXPECT_CALL(*mock_objects_ticker,
                    tick())
                           .Times(1);

                // Act
                sut.tick();

                // Assert
            }

            TEST(GameTimer, tick_calls_move_objects_calculate_print_moves_move_objects)
            {
                // Arrange
                MockIPlayingField* mock_playing_field = new MockIPlayingField{};
                IPlayingField_Ptr playing_field(mock_playing_field);

                MockIObjectsMover* mock_objects_mover = new MockIObjectsMover{};
                IObjectsMover_Ptr objects_mover(mock_objects_mover);

                MockIObjectsTicker* mock_objects_ticker = new MockIObjectsTicker{};
                IObjectsTicker_Ptr objects_ticker(mock_objects_ticker);

                MockIMonstersHeadingUpdater* mock_monster_updater = new MockIMonstersHeadingUpdater{};
                IMonstersHeadingUpdater_Ptr monster_updater(mock_monster_updater);

                GameTimer sut{
                    monster_updater,
                    objects_mover,
                    objects_ticker
                };

                sut.initialize(playing_field);

                EXPECT_CALL(*mock_playing_field,
                    get_rows())
                               .WillRepeatedly(testing::Return(0));

                EXPECT_CALL(*mock_playing_field,
                    get_columns())
                                  .WillRepeatedly(testing::Return(0));

                EXPECT_CALL(*mock_monster_updater,
                    update())
                             .Times(1);

                EXPECT_CALL(*mock_objects_mover,
                    calculate())
                                .Times(1);

                std::stringstream stream;

                EXPECT_CALL(*mock_objects_mover,
                    print_moves(testing::A<std::ostream&>()))
                                                             .Times(1)
                                                             .WillOnce(testing::ReturnRef(stream));

                EXPECT_CALL(*mock_objects_mover,
                    move_objects())
                                   .Times(1);

                // Act
                sut.tick();

                // Assert
            }
        };
    };
};
