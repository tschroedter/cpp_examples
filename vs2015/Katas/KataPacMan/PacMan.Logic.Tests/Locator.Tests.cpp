#include "stdafx.h"
#include <gtest/gtest.h>
#include "MockIDirection.h"
#include "ILocator.h"
#include "LocatorInformation.h"
#include "Locator.h"
#include "MockIPlayingField.h"
#include "MockIPlayingFieldObject.h"

namespace PacMan
{
    namespace Logic
    {
        namespace Tests
        {
            using namespace Logic;

            TEST(Locator, get_all_returns_all_items)
            {
                // Arrange
                MockIPlayingFieldObject* mock_object_one = new MockIPlayingFieldObject{};
                IPlayingFieldObject_Ptr object_one(mock_object_one);

                MockIPlayingFieldObject* mock_object_two = new MockIPlayingFieldObject{};
                IPlayingFieldObject_Ptr object_two(mock_object_two);

                MockIPlayingField* mock_playing_field = new MockIPlayingField{};
                IPlayingField_Ptr playing_field(mock_playing_field);

                LocatorInformationVector* p_vector = new LocatorInformationVector{};
                LocatorInformationVector_Ptr vector(p_vector);

                Locator sut{};

                sut.initialize(playing_field);

                EXPECT_CALL(*mock_playing_field,
                    get_rows())
                               .WillRepeatedly(testing::Return(Row{1}));

                EXPECT_CALL(*mock_playing_field,
                    get_columns())
                                  .WillRepeatedly(testing::Return(Column{2}));

                EXPECT_CALL(*mock_playing_field,
                    get_object_at(Row{ 0 }, Column{ 0 }))
                                                         .WillRepeatedly(testing::Return(object_one));

                EXPECT_CALL(*mock_playing_field,
                    get_object_at(Row{ 0 }, Column{ 1 }))
                                                         .WillRepeatedly(testing::Return(object_two));

                // Act
                auto all = sut.get_all();

                // Assert
                EXPECT_EQ(2, all->size());
                EXPECT_EQ(object_one, (*all)[0]->object);
                EXPECT_EQ(Row(0), (*all)[0]->row);
                EXPECT_EQ(Column(0), (*all)[0]->column);
                EXPECT_EQ(object_two, (*all)[1]->object);
                EXPECT_EQ(Row(0), (*all)[1]->row);
                EXPECT_EQ(Column(1), (*all)[1]->column);
            }

            TEST(Locator, get_all_of_type_returns_all_items_of_type)
            {
                // Arrange
                MockIPlayingFieldObject* mock_object_one = new MockIPlayingFieldObject{};
                IPlayingFieldObject_Ptr object_one(mock_object_one);

                MockIPlayingFieldObject* mock_object_two = new MockIPlayingFieldObject{};
                IPlayingFieldObject_Ptr object_two(mock_object_two);

                MockIPlayingField* mock_playing_field = new MockIPlayingField{};
                IPlayingField_Ptr playing_field(mock_playing_field);

                LocatorInformationVector* p_vector = new LocatorInformationVector{};
                LocatorInformationVector_Ptr vector(p_vector);

                Locator sut{};

                sut.initialize(playing_field);

                EXPECT_CALL(*mock_object_one,
                    get_type())
                               .WillRepeatedly(testing::Return(PlayingFieldObjectType_PacMan));

                EXPECT_CALL(*mock_object_two,
                    get_type())
                               .WillRepeatedly(testing::Return(PlayingFieldObjectType_Monster));

                EXPECT_CALL(*mock_playing_field,
                    get_rows())
                               .WillRepeatedly(testing::Return(Row{1}));

                EXPECT_CALL(*mock_playing_field,
                    get_columns())
                                  .WillRepeatedly(testing::Return(Column{2}));

                EXPECT_CALL(*mock_playing_field,
                    get_object_at(Row{ 0 }, Column{ 0 }))
                                                         .WillRepeatedly(testing::Return(object_one));

                EXPECT_CALL(*mock_playing_field,
                    get_object_at(Row{ 0 }, Column{ 1 }))
                                                         .WillRepeatedly(testing::Return(object_two));

                // Act
                auto all = sut.get_all_of_type(PlayingFieldObjectType_Monster);

                // Assert
                EXPECT_EQ(1, all->size());
                EXPECT_EQ(object_two, (*all)[0]->object);
                EXPECT_EQ(Row(0), (*all)[0]->row);
                EXPECT_EQ(Column(1), (*all)[0]->column);
            }
        };
    };
};
